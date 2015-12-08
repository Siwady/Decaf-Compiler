
#include "ast.h"
#include <algorithm>
#include <sstream>

using namespace std;

const char *temps[] = {"$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", "$t8", "$t9"};
#define TEMP_COUNT (sizeof(temps)/sizeof(temps[0]))       

int Label,ChLabel,StrLabel;
map<string, int> tempMap;
map<string, VValue> sTable;
map<string, Method*> mTable;
map<string,string> StringConstants; //String Constants.
map<char,string> CharConstants;     //Char Constants.

string forAssignCode;
VValue returnValue;
VValue st={st.type = INT,st.u.ivalue = 0, st.isArray=false,st.ArraySize=0};

string MethodName;
list<VValue> ActualVariables;

string newTemp() {
    int i;

    for (i = 0; i < TEMP_COUNT; i++) {
        if (tempMap.find(temps[i]) == tempMap.end()) {
            tempMap[temps[i]] = 1;

            return string(temps[i]);
        }
    }

    return string("");
}

string newLabel() {
    string s = "Label";
    stringstream sstm;
    sstm << s << Label++;
    return sstm.str();
}
string newString() {
    string s = "Str";
    stringstream sstm;
    sstm << s << StrLabel++;
    return sstm.str();
}
string newChar() {
    string s = "Ch";
    stringstream sstm;
    sstm << s << ChLabel++;
    return sstm.str();
}

void releaseTemp(string temp) {
    tempMap.erase(temp);
}

string getStringFromType(MethodType type){
    switch (type) {
        case M_VOID:
            return "void";
            break;
        case M_INT:
            return "int";
            break;
        case M_BOOLEAN:
            return "bool";
            break;
    }
    return "";
}
string getStringFromType(VarType type){
    switch (type) {
        case INT:
            return "int";
            break;
        case BOOLEAN:
            return "bool";
            break;
        case STRINGS :
            return "string";
            break;
        case CHARACTER:
            return "char";
            break;
    }
    return "";
}

string GetIdentation(int i)
{
    string s="";
    for(int j=0;j<i;j++)
    {
        s+="    ";
    }
    return s;
}

string Program::generateCode() {

    stringstream ss;
    ss<<"#class "<<id<<"{"<<endl;
    DeclList::iterator it=this->Variables->begin();
    while(it!=this->Variables->end()){
        Declaration *d=*it;
        ss<<d->generateCode(1);
        it++;
    }
    ss<<GetIdentation(1)<<"jal main \n"<<
        GetIdentation(1)<<"j EndClass\n";

    MethodList::iterator it2=this->Methods->begin();
    while(it2!=this->Methods->end()){
        Method *m =*it2;
        //if(m->id.find(string("main"))!=string::npos){
            ss<<m->generateCode(1)<<endl;
        //}
        it2++;
    }
    ss<<"#}\n"<<
    "EndClass:\n"
     << "# Exit\n"
     << "li $v0, 10\n"
     << "syscall\n";;
    return ss.str();
}

//-------------  GENERATE CODE  EXPRESIONS----------------------------------------------

string AddExpr::generateCode(string& place, int i){
    string place1, place2;
    string code1 = expr1->generateCode(place1,i);
    string code2 = expr2->generateCode(place2,i);
    stringstream ss;
    
    releaseTemp(place1);
    releaseTemp(place2);
    place = newTemp();
    
    ss << code1 << endl <<
          code2 << endl <<
          GetIdentation(i)<<"add " << place << ", " << place1 << ", " << place2;
    this->type=INT;
    return ss.str();
}

string SubExpr::generateCode(string &place, int i)
{
    string place1, place2;
    string code1 = expr1->generateCode(place1,i);
    string code2 = expr2->generateCode(place2,i);
    stringstream ss;
    
    releaseTemp(place1);
    releaseTemp(place2);
    place = newTemp();
    
    ss << code1 << endl <<
    code2 << endl <<
    GetIdentation(i)<<"sub " << place << ", " << place1 << ", " << place2;
    this->type=INT;
    return ss.str();
}

string MultExpr::generateCode(string &place, int i)
{
    string place1, place2;
    string code1 = expr1->generateCode(place1,i);
    string code2 = expr2->generateCode(place2,i);
    stringstream ss;

    releaseTemp(place1);
    releaseTemp(place2);
    place = newTemp();

    ss << code1 << endl <<
    code2 << endl <<
    GetIdentation(i)<<"mult " << place1 << ", " << place2 << endl <<
    GetIdentation(i)<<"mflo " << place;

    this->type=INT;
    return ss.str();
}

string DivExpr::generateCode(string &place, int i)
{
    string place1, place2;
    string code1 = expr1->generateCode(place1,i);
    string code2 = expr2->generateCode(place2,i);
    stringstream ss;

    releaseTemp(place1);
    releaseTemp(place2);
    place = newTemp();

    ss << code1 << endl <<
    code2 << endl <<
    GetIdentation(i)<<"div " << place1 << ", " << place2 << endl <<
    GetIdentation(i)<<"mflo " << place;

    this->type=INT;
    return ss.str();
}

string LessThanExpr::generateCode(string &place, int i)
{
    string place1, place2;
    string code1 = expr1->generateCode(place1,i);
    string code2 = expr2->generateCode(place2,i);
    stringstream ss;
    
    releaseTemp(place1);
    releaseTemp(place2);
    place = newTemp();
    
    ss << code1 << endl <<
    code2 << endl <<
    GetIdentation(i)<<"slt " << place << ", " << place1 << ", " << place2;
    this->type=BOOLEAN;
    return ss.str();
}
string GreaterThanExpr::generateCode(string &place, int i)
{
    string place1, place2;
    string code1 = expr1->generateCode(place1,i);
    string code2 = expr2->generateCode(place2,i);
    stringstream ss;
    
    releaseTemp(place1);
    releaseTemp(place2);
    place = newTemp();
    
    ss << code1 << endl <<
    code2 << endl <<
    GetIdentation(i)<<"slt " << place << ", " << place2 << ", " << place1;
    this->type=BOOLEAN;
    return ss.str();
}

string LessThanEqualExpr::generateCode(string &place, int i)
{
    string place1, place2;
    string code1 = expr1->generateCode(place1,i);
    string code2 = expr2->generateCode(place2,i);
    stringstream ss;
    
    releaseTemp(place1);
    releaseTemp(place2);
    place = newTemp();
    
    ss << code1 << endl <<
    code2 << endl <<
    GetIdentation(i)<<"slt "  << place << ", " << place2 << ", " << place1 <<"\n"<<
    GetIdentation(i)<<"nor "  << place << ", " << place  << ", " << place  << "\n"<<
    GetIdentation(i)<<"addi " << place << ", " << place  << ", 2";
    this->type=BOOLEAN;
    return ss.str();
}

string GreaterThanEqualExpr::generateCode(string &place, int i)
{
    string place1, place2;
    string code1 = expr1->generateCode(place1,i);
    string code2 = expr2->generateCode(place2,i);
    stringstream ss;
    
    releaseTemp(place1);
    releaseTemp(place2);
    place = newTemp();
    
    ss << code1 << endl <<
    code2   << endl <<
    GetIdentation(i)<<"slt "  << place << ", " << place1 << ", " << place2 <<"\n"<<
    GetIdentation(i)<<"nor "  << place << ", " << place  << ", " << place  <<"\n"<<
    GetIdentation(i)<<"addi " << place << ", " << place  << ", 2";
    this->type=BOOLEAN;
    return ss.str();
}
string EqualExpr::generateCode(string &place, int i)
{
    string place1, place2, true_l,end_l;
    string code1 = expr1->generateCode(place1,i);
    string code2 = expr2->generateCode(place2,i);
    stringstream ss;
    true_l=newLabel();
    end_l=newLabel();
    
    releaseTemp(place1);
    releaseTemp(place2);
    place = newTemp();
    
    ss << code1 << endl <<
    code2 << endl <<
    GetIdentation(i)<<"beq "<< place1 << ", " << place2 << ", " <<true_l<<"\n"<<
    GetIdentation(i)<<"li " << place  << ", " << "0\n"  <<
    GetIdentation(i)<<"j "  << end_l  << "\n" <<
    GetIdentation(i)<<true_l<< ":\n"  <<
    GetIdentation(i)<<"li " << place  << ", " << "1\n"  <<
    GetIdentation(i)<<end_l << ":\n";
    this->type=BOOLEAN;
    return ss.str();
}

string NotEqualExpr::generateCode(string &place, int i)
{
    string place1, place2, true_l,end_l;
    string code1 = expr1->generateCode(place1,i);
    string code2 = expr2->generateCode(place2,i);
    stringstream ss;
    true_l=newLabel();
    end_l=newLabel();
    
    releaseTemp(place1);
    releaseTemp(place2);
    place = newTemp();
    
    ss << code1 << endl <<
    code2 << endl <<
    GetIdentation(i)<<"beq "<< place1 << ", " << place2 << ", " <<true_l<<"\n"<<
    GetIdentation(i)<<"li " << place  << ", " << "1\n"  <<
    GetIdentation(i)<<"j "  << end_l  << "\n" <<
    GetIdentation(i)<<true_l<< ":\n"  <<
    GetIdentation(i)<<"li " << place  << ", " << "0\n"  <<
    GetIdentation(i)<<end_l << ":\n";
    this->type=BOOLEAN;
    return ss.str();
}

string IntExpr::generateCode(string &place, int i)
{
    stringstream ss;
    
    place = newTemp();
    
    ss << GetIdentation(i)<<"li " << place << ", " << value.IntValue();
    this->type=INT;
    return ss.str();
}
string BoolExpr::generateCode(string &place, int i)
{
    stringstream ss;
    
    place = newTemp();
    
    ss <<GetIdentation(i)<< "li " << place << ", " << value.BoolValue();
    this->type=BOOLEAN;
    return ss.str();
}

string ArrayExpr::generateCode(string &place, int i)
{
    string place1=newTemp();
    string place2=newTemp();
    string place3=newTemp();
    string place4=newTemp();
    if (sTable.find(id) == sTable.end()) {
        /*if (mTable.find(MethodName) != mTable.end()) {
            if (mTable[MethodName]->LTable.find(id) != mTable[MethodName]->LTable.end()) {
                return mTable[MethodName]->LTable[id];
            }
        }*/
        printf("Variable %s is not declared\n", id.c_str());
        exit(0);
    }
    string code=this->dim->generateCode(place1,i);
    stringstream ss;
    place = newTemp();
    ss <<
    GetIdentation(i)<<"la " << place3 << ", " << id << endl <<
    code<<
    GetIdentation(i)<<"add " <<place2<<", "<< place1 << ", " << place1 << endl <<
    GetIdentation(i)<<"add " <<place2<<", "<< place2 << ", " << place2 << endl <<
    GetIdentation(i)<<"add " <<place4<<", "<< place2 << ", " << place3 << endl <<
    GetIdentation(i)<<"lw " << place << ", " << "0("<< place4 << ")" << endl;

    releaseTemp(place1);
    releaseTemp(place2);
    releaseTemp(place3);
    releaseTemp(place4);
    this->type=sTable[id].type;
    return ss.str();
}

string IdExpr::generateCode(string &place, int i)
{
    if (sTable.find(id) == sTable.end()) {
        /*if (mTable.find(MethodName) != mTable.end()) {
            if (mTable[MethodName]->LTable.find(id) != mTable[MethodName]->LTable.end()) {
                return mTable[MethodName]->LTable[id];
            }
        }*/
        printf("Variable %s is not declared\n", id.c_str());
        exit(0);
    }
	stringstream ss;

	place = newTemp();
        
    ss <<
    GetIdentation(i)<<"la " << place << ", " << id << endl <<
    GetIdentation(i)<<"lw " << place << ", " << "0("<< place << ")" << endl;
    this->type=sTable[id].type;
	return ss.str();
		
}

string NegativeExpr::generateCode(string& place, int i){
    stringstream ss;

    place = newTemp();

   // ss << GetIdentation(i)<<"la " << place << ", -" << this->expr-IntValue();
    this->type=INT;
    return ss.str();
}

string CharExpr::generateCode(string& place, int i){
    stringstream ss;
    this->type=CHARACTER;

    place = newTemp();
    string lab=newChar();
    CharConstants[this->value.CharValue()]=lab;
    ss << "lb " <<place<<", "<<lab<<endl;
    return ss.str();
}

string StrExpr::generateCode(string& place, int i){
    stringstream ss;
    this->type=STRINGS;
    place = newTemp();
    string lab=newString();
    StringConstants[this->val]=lab;
    ss << "la " <<place<<", "<<lab<<endl;
    return ss.str();

}

string MethodExpr::generateCode(string& place, int i){
    stringstream ss;

    return ss.str();
}
string ShiftLeftExpr::generateCode(string& place, int i){
    string place1, place2;
    string code1 = expr1->generateCode(place1,i);
    string code2 = expr2->generateCode(place2,i);
    stringstream ss;

    releaseTemp(place1);
    releaseTemp(place2);
    place = newTemp();

    ss << code1 << endl <<
    code2 << endl <<
    GetIdentation(i)<<"sllv " << place << ", " << place1 << ", " << place2;
    this->type=INT;
    return ss.str();
}

string ShiftRightExpr::generateCode(string& place, int i){
    string place1, place2;
    string code1 = expr1->generateCode(place1,i);
    string code2 = expr2->generateCode(place2,i);
    stringstream ss;

    releaseTemp(place1);
    releaseTemp(place2);
    place = newTemp();

    ss << code1 << endl <<
    code2 << endl <<
    GetIdentation(i)<<"srlv " << place << ", " << place1 << ", " << place2;
    this->type=INT;
    return ss.str();
}

string RotExpr::generateCode(string& place, int i){
    stringstream ss;
    this->type=INT;
    return ss.str();
}

string AndExpr::generateCode(string& place, int i){
    string place1, place2;
    string code1 = expr1->generateCode(place1,i);
    string code2 = expr2->generateCode(place2,i);
    stringstream ss;

    releaseTemp(place1);
    releaseTemp(place2);
    place = newTemp();

    ss << code1 << endl <<
    code2 << endl <<
    GetIdentation(i)<<"and " << place << ", " << place1 << ", " << place2;
    this->type=BOOLEAN;
    return ss.str();
}

string OrExpr::generateCode(string &place, int i)
{
    string place1, place2;
    string code1 = expr1->generateCode(place1,i);
    string code2 = expr2->generateCode(place2,i);
    stringstream ss;

    releaseTemp(place1);
    releaseTemp(place2);
    place = newTemp();

    ss << code1 << endl <<
    code2 << endl <<
    GetIdentation(i)<<"or " << place << ", " << place1 << ", " << place2;
    this->type=BOOLEAN;
    return ss.str();
}

string ModExpr::generateCode(string &place, int i)
{
    string place1, place2;
    string code1 = expr1->generateCode(place1,i);
    string code2 = expr2->generateCode(place2,i);
    stringstream ss;

    releaseTemp(place1);
    releaseTemp(place2);
    place = newTemp();

    ss << code1 << endl <<
    code2 << endl <<
    GetIdentation(i)<<"div " << place1 << ", " << place2 << endl <<
    GetIdentation(i)<<"mfhi " << place;
    this->type=INT;
    return ss.str();
}

string NotExpr::generateCode(string &place, int i)
{
    stringstream ss;
    this->type=BOOLEAN;
    return ss.str();
}


//------------------------------------GENERATE CODE  STATEMENT---------------------------------------------


string PrintStatement::generateCode(string label1, string label2, int i)
{
    string place1;
    ExprList::iterator it=expr.begin();
    string code;
    stringstream ss;
    ss<<GetIdentation(i)<<"#print ";
    while(it!=expr.end()){
        Expr *e=*it;
        if(it==expr.begin()){
            ss<<e->toString();
        }else{
            ss<<","<<e->toString();
        }
        it++;
        if(it==expr.end()){
            ss<<";\n";
        }
    }
    it=expr.begin();
    while(it!=expr.end()){
        Expr *e=*it;
        code = e->generateCode(place1,i+1);
        releaseTemp(place1);
        ss <<code << endl ;
        switch (e->type) {
        case INT:
            ss<<GetIdentation(i+1)<<"move $a0, " << place1 << endl<<
            GetIdentation(i+1)<< "li $v0, 1" << endl<<
            GetIdentation(i+1)<< "syscall" << endl<<
            GetIdentation(i+1)<< "la $a0, newLine" << endl<<
            GetIdentation(i+1)<< "li $v0, 4" << endl<<
            GetIdentation(i+1)<< "syscall" << endl;
            break;

        case STRINGS:
            ss<<GetIdentation(i+1)<<"move $a0, " << place1 << endl<<
            GetIdentation(i+1)<< "li $v0, 4" << endl<<
            GetIdentation(i+1)<< "syscall" << endl<<
            GetIdentation(i+1)<< "la $a0, newLine" << endl<<
            GetIdentation(i+1)<< "li $v0, 4" << endl<<
            GetIdentation(i+1)<< "syscall" << endl;
            break;

        case CHARACTER:
            ss<<GetIdentation(i+1)<<"move $a0, " << place1 << endl<<
            GetIdentation(i+1)<< "li $v0, 11" << endl<<
            GetIdentation(i+1)<< "syscall" << endl<<
            GetIdentation(i+1)<< "la $a0, newLine" << endl<<
            GetIdentation(i+1)<< "li $v0, 4" << endl<<
            GetIdentation(i+1)<< "syscall" << endl;
            break;
        }

        it++;
    }
    return ss.str();
}

string AssignStatement::generateCode(string label1, string label2, int i)
{
    if (sTable.find(id) == sTable.end()) {
        printf("Variable %s doesn't exist.\n",id.c_str());
        exit(0);
    }

    string place1;
    string code = expr->generateCode(place1,i+1);
    stringstream ss;
    string place ="";

    if(expr->type!=sTable[id].type){
        printf("Incompatible types, variable %s expect %s type, found %s.\n",id.c_str(),getStringFromType(sTable[id].type).c_str(),getStringFromType(expr->type).c_str());
        exit(0);
    }

    place=newTemp();

    if(dim==0){
        ss << GetIdentation(i)<<"# "<<id<<"="<<expr->toString()<<";"<<endl
        <<code << endl;
        ss<<GetIdentation(i+1)<<"la " << place << ", " << id << endl <<
        GetIdentation(i+1)<<"sw " << place1 << ", " << "0(" << place << ")" << endl;

        releaseTemp(place1);
    }else{
        ss << GetIdentation(i)<<"# "<<id<<"["<<dim->toString()<<"]="<<expr->toString()<<";"<<endl
        <<code << endl;

        releaseTemp(place1);
        string DimCode;
        string place2=newTemp();
        string place3=newTemp();
        string place4=newTemp();

        DimCode=this->dim->generateCode(place2,i);
        releaseTemp(place1);
        releaseTemp(place2);
        releaseTemp(place3);
        releaseTemp(place4);

        ss<<DimCode<<endl<<
        GetIdentation(i)<<"la " << place3 << ", " << id << endl <<
        GetIdentation(i)<<"add " <<place2<<", "<< place2 << ", " << place2 << endl <<
        GetIdentation(i)<<"add " <<place2<<", "<< place2 << ", " << place2 << endl <<
        GetIdentation(i)<<"add " <<place4<<", "<< place2 << ", " << place3 << endl <<
        GetIdentation(i+1)<<"sw " << place1 << ", " << "0(" << place4 << ")" << endl;
    }
    releaseTemp(place);
    return ss.str();
}

string IfStatement::generateCode(string label1, string label2, int i) {
    string place1, place2;
    string code = this->cond->generateCode(place1,i+1);

    string lbl1 = newLabel();
    string lbl2 = newLabel();
    
    place2 = newTemp();
    stringstream ss;
    string place = newTemp();
    releaseTemp(place1);

    string bcode ="";
    StatementList::iterator it=this->trueBlock.begin();
    while(it!=this->trueBlock.end()){
        Statement *s=*it;
        bcode+= s->generateCode(label1, label2,i+1);
        it++;
    }
    
    string bcode2 = "";
    if (this->falseBlock.empty()){
        StatementList::iterator it2=this->falseBlock.begin();
        while(it2!=this->falseBlock.end()){
            Statement *s=*it2;
            bcode2+= s->generateCode(label1, label2,i+1);
            it2++;
        }
    }
    ss <<GetIdentation(i)<<"#if("<<cond->toString()<<"){\n"<<
        code << endl <<
        GetIdentation(i+1)<<"add " << place2 << ", " << "$zero, $zero\n" <<
        GetIdentation(i+1)<<"beq " << place1 << ", " << place2 << ", " << lbl1 << "\n" <<
        bcode << "\n" <<
        GetIdentation(i+1)<<"j " << lbl2 << "\n" <<
        GetIdentation(i)<<"#}else{\n"<<
        GetIdentation(i+1)<<lbl1 << ": \n" <<
        bcode2 <<
        GetIdentation(i)<<"#}\n"<<
        GetIdentation(i)<<lbl2 << ": \n";


    releaseTemp(place);
    return ss.str();
}

string WhileStatement::generateCode(string label1, string label2, int i) {
    string place1;
    string code = this->cond->generateCode(place1,i+2);
    label1 = newLabel();
    label2 = newLabel();
    stringstream ss;
    string place = newTemp();
    releaseTemp(place1);

    string bcode ="";
    StatementList::iterator it=this->statementBlock.begin();
    while(it!=this->statementBlock.end()){
        Statement * s=*it;
        bcode+= s->generateCode(label1,label2,i+2);
        it++;
    }
     
    ss <<GetIdentation(i)<<"#while("<<cond->toString()<<"){\n"<<
        GetIdentation(i+1)<<label1 <<":\n"<<
        code << endl <<
        GetIdentation(i+2)<<"beq " << place1 << ", " << "$zero, " << label2 << "\n" <<
        bcode <<
        GetIdentation(i+2)<<"j " << label1 << "\n" <<
        GetIdentation(i)<<"#}\n"<<
        GetIdentation(i)<<label2 << ": \n";

    releaseTemp(place);
    return ss.str();
}

string ForStatement::generateCode(string label1, string label2, int i){
    string place1;
    string conti;
    string code = this->cond->generateCode(place1,i+2);
    label1 = newLabel();
    label2 = newLabel();
    stringstream ss;
    string place = newTemp();
    releaseTemp(place1);
    string acode1,acode2,temp;

    if(!forAssignCode.empty()){
        temp=forAssignCode;
    }
    StatementList::iterator it2=assignStatement.begin();
    while(it2!=assignStatement.end()){
        Statement *s=*it2;
        acode1+= s->generateCode(label1,label2,i);
        it2++;
    }

    StatementList::iterator it3=finalAssignStatement.begin();
    while(it3!=finalAssignStatement.end()){
        Statement *s=*it3;
        acode2+= s->generateCode(label1,label2,i+2);
        it3++;
    }

    forAssignCode=acode2;

    string bcode ="";
    StatementList::iterator it=this->statementBlock.begin();
    while(it!=this->statementBlock.end()){
        Statement * s=*it;
        bcode+= s->generateCode(label1,label2,i+2);
        it++;
    }

    ss <<GetIdentation(i)<<"#for("<<cond->toString()<<"){\n"<<
        acode1 <<endl<<
        GetIdentation(i+1)<<label1 <<":\n"<<
        code << endl <<
        GetIdentation(i+2)<<"beq " << place1 << ", " << "$zero, " << label2 << "\n" <<
        bcode<<acode2<<
        GetIdentation(i+2)<<"j " << label1 << "\n" <<
        GetIdentation(i)<<"#}\n"<<
        GetIdentation(i)<<label2 << ": \n";

    releaseTemp(place);
    forAssignCode=temp;
    return ss.str();
}

string ReturnStatement::generateCode(string label1, string label2, int i){
    stringstream ss;
    
    return ss.str();
}

string MethodStatement::generateCode(string label1, string label2, int i){
    stringstream ss;
    
    return ss.str();
}

string BreakStatement::generateCode(string label1, string label2, int i) {
    stringstream ss;
    if(!label1.empty()){
        ss <<GetIdentation(i)<<"# break;\n"<<
        GetIdentation(i+1)<<"j " << label2 << "\n";
    }else{
        printf("Unexpected break.\n");
        exit(0);
    }
    return ss.str();
}

string ContinueStatement::generateCode(string label1, string label2, int i) {
    stringstream ss;
    if(!forAssignCode.empty()){
        ss<<forAssignCode<<endl;
    }
    if(!label1.empty()){
        ss <<GetIdentation(i)<< "# continue;\n"<<
        GetIdentation(i+1)<<"j " << label1 << "\n";
    }else{
        printf("Unexpected continue.\n");
        exit(0);
    }
    return ss.str();
}

string Declaration::generateCode(int i) {
    string place,code,place1;
    stringstream ss;
    DeclItemList::iterator it=ids.begin();
    if(value==0){
        ss<< GetIdentation(i)<<"# "<<getStringFromType(type)<<" ";
    }
    while(it!=ids.end()){
        DeclItem *item=*it;
        if (sTable.find(item->id) != sTable.end()) {
            printf("Variable %s already exist.\n",item->id.c_str());
            exit(0);
        }
        VValue v;
        v.type=type;
        sTable[item->id] =v;
        if(item->dimension>0){
            cout << item->id << ": .word 0";
            for(int c=1;c<item->dimension;c++){
                cout<<",0";
            }
            cout<< endl;
        }else{
            cout << item->id << ": .word 0" << endl;
        }
        if(value!=0){
            code = this->value->generateCode(place1,i+1);
            if(value->type!=sTable[item->id].type){
                printf("Incompatible types, variable %s expect %s type, found %s.\n",item->id.c_str(),getStringFromType(sTable[item->id].type).c_str(),getStringFromType(value->type).c_str());
                exit(0);
            }
            place =newTemp();
            releaseTemp(place1);

            ss << GetIdentation(i)<<"# "<<getStringFromType(v.type)<<" "<<item->id<<"="<<this->value->toString()<<";\n"<<code << endl <<
            GetIdentation(i+1)<<"la " << place << ", " << item->id << endl <<
            GetIdentation(i+1)<<"sw " << place1 << ", " << "0(" << place << ")" << endl;
            releaseTemp(place);
        }else{
            if(it==ids.begin()){
                ss<<item->id;
            }else{
                ss<<","<<item->id;
            }

        }
        it++;
        if(it==ids.end() && value==0){
            ss<<";\n";
        }
    }
    return ss.str();
}

string Method::generateCode(int i) {
    stringstream ss;
    ss<<"\n"<<GetIdentation(i)<<"#"<<getStringFromType(type)<<" "<<id<<"(){"<<endl<<
        GetIdentation(i)<<id<<":\n";
    DeclList::iterator it=this->declare.begin();
    while(it!=this->declare.end()){
        Declaration *d =*it;
        ss<<d->generateCode(i+1);
        it++;
    }

    ParamList::iterator it3=this->params.begin();
    while(it3!=this->params.end()){
        Param *p =*it3;
        ss<<p->generateCode(i+1);
        it3++;
    }

    string lab1,lab2;

    StatementList::iterator it2=this->statementBlock.begin();
    while(it2!=this->statementBlock.end()){
        Statement*s =*it2;
        ss<<s->generateCode(lab1,lab2,i+1)<<endl;
        it2++;
    }
    ss<<GetIdentation(i+1)<<"jr $ra\n"<<
        GetIdentation(i)<<"#}";
    return ss.str();
}


string Param::generateCode(int i)
{
    stringstream ss;
    if (sTable.find(id) != sTable.end()) {
        printf("Variable %s already exist.\n",id.c_str());
        exit(0);
    }
    VValue v;
    v.type=type;
    sTable[id] =v;
    cout << id << ": .word 0" << endl;
    return ss.str();
}
