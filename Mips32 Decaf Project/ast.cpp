
#include "ast.h"
#include <algorithm>
#include <sstream>

using namespace std;

const char *temps[] = {"$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", "$t8", "$t9", "$t10", "$t11", "$t12", "$t13", "$t14", "$t15", "$t16", "$t17", "$t18", "$t19"};
#define TEMP_COUNT (sizeof(temps)/sizeof(temps[0]))       

int label;
map<string, int> tempMap;
map<string, VValue> sTable;
map<string, Method*> mTable;

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
    sstm << s << label++;
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
string GetIdentation(int i)
{
    string s="";
    for(int j=0;j<i;j++)
    {
        s+="   ";
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

    MethodList::iterator it2=this->Methods->begin();
    while(it2!=this->Methods->end()){
        Method *m =*it2;
        if(m->id.find(string("main"))!=string::npos){
            ss<<m->generateCode(1)<<endl;
        }
        it2++;
    }
    ss<<"#}";
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
    
    return ss.str();
}

string IntExpr::generateCode(string &place, int i)
{
    stringstream ss;
    
    place = newTemp();
    
    ss << GetIdentation(i)<<"li " << place << ", " << value.IntValue();
    
    return ss.str();
}
string BoolExpr::generateCode(string &place, int i)
{
    stringstream ss;
    
    place = newTemp();
    
    ss <<GetIdentation(i)<< "li " << place << ", " << value.BoolValue();
    
    return ss.str();
}

string IdExpr::generateCode(string &place, int i)
{
	if(sTable.find(id) == sTable.end())
	{
		printf("Id %s no existe!\n",id.c_str());
		exit(0);
	}
	stringstream ss;

	place = newTemp();
        
    ss <<
    GetIdentation(i)<<"la " << place << ", " << id << endl <<
    GetIdentation(i)<<"lw " << place << ", " << "0("<< place << ")" << endl;

	return ss.str();
		
}

string NegativeExpr::generateCode(string& place, int i){
    stringstream ss;
    
    return ss.str();
}

string CharExpr::generateCode(string& place, int i){
    stringstream ss;
    
    return ss.str();
}

string StrExpr::generateCode(string& place, int i){
    stringstream ss;
    
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

    return ss.str();
}

string RotExpr::generateCode(string& place, int i){
    stringstream ss;
    
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

    return ss.str();
}

string ModExpr::generateCode(string &place, int i)
{
    stringstream ss;

    return ss.str();
}

string NotExpr::generateCode(string &place, int i)
{
    stringstream ss;

    return ss.str();
}

string ArrayExpr::generateCode(string &place, int i)
{
    stringstream ss;

    return ss.str();
}

//------------------------------------GENERATE CODE  STATEMENT---------------------------------------------


string PrintStatement::generateCode(string label1, string label2, int i)
{
    string place1;
    ExprList::iterator it=expr.begin();
    string code;
    stringstream ss;
    ss<<GetIdentation(i)<<"#-PrintStatement-\n";
    while(it!=expr.end()){
        Expr *e=*it;
        code = e->generateCode(place1,i+1);
        releaseTemp(place1);
        ss <<code << endl <<
        GetIdentation(i+1)<<"move $a0, " << place1 << endl<<
        GetIdentation(i+1)<< "li $v0, 1" << endl<<
        GetIdentation(i+1)<< "syscall" << endl<<
        GetIdentation(i+1)<< "la $a0, newLine" << endl<<
        GetIdentation(i+1)<< "li $v0, 4" << endl<<
        GetIdentation(i+1)<< "syscall" << endl;
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

    place=newTemp();
    releaseTemp(place1);
    ss << GetIdentation(i)<<"#-AssignStatement-\n"<<code << endl <<
    GetIdentation(i+1)<<"la " << place << ", " << id << endl <<
    GetIdentation(i+1)<<"sw " << place1 << ", " << "0(" << place << ")" << endl;
    releaseTemp(place);

    return ss.str();
}

string IfStatement::generateCode(string label1, string label2, int i) {
    string place1, place2;
    string code = this->cond->generateCode(place1,i);

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
    ss <<GetIdentation(i)<<"#-IfStatement -\n"<<
        GetIdentation(i+1)<<code << endl <<
        GetIdentation(i+1)<<"addi " << place2 << ", " << "$zero, 1\n" <<
        GetIdentation(i+1)<<"beq " << place1 << ", " << place2 << ", " << lbl1 << "\n" <<
        GetIdentation(i+1)<<bcode2 << "\n" <<
        GetIdentation(i+1)<<"j " << lbl2 << "\n" <<
        GetIdentation(i+1)<<lbl1 << ": \n" <<
        GetIdentation(i+1)<<bcode <<
        GetIdentation(i+1)<<lbl2 << ": \n";

    releaseTemp(place);
    return ss.str();
}

string WhileStatement::generateCode(string label1, string label2, int i) {
    string place1;
    string code = this->cond->generateCode(place1,i);
    label1 = newLabel();
    label2 = newLabel();
    stringstream ss;
    string place = newTemp();
    releaseTemp(place1);

    string bcode ="";
    StatementList::iterator it=this->statementBlock.begin();
    while(it!=this->statementBlock.end()){
        Statement * s=*it;
        bcode+= s->generateCode(label1,label2,i+1);
    }
     
    ss <<GetIdentation(i)<<"#-WhileStatement -\n"<<
        GetIdentation(i+1)<<label1 <<":\n"<<
        GetIdentation(i+1)<<code << endl <<
        GetIdentation(i+1)<<"beq " << place1 << ", " << "$zero, " << label2 << "\n" <<
        GetIdentation(i+1)<<bcode <<
        GetIdentation(i+1)<<"j " << label1 << "\n" <<
        GetIdentation(i+1)<<label2 << ": \n";

    releaseTemp(place);
    return ss.str();
}

string ForStatement::generateCode(string label1, string label2, int i){
    stringstream ss;
    
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
        ss << "#-BreakStatement -\n"<< 
                "j " << label2 << "\n";
    }else{
        printf("Unexpected break.\n");
        exit(0);
    }
    return ss.str();
}

string ContinueStatement::generateCode(string label1, string label2, int i) {
    stringstream ss;
    if(!label1.empty()){
        ss << "#-ContinueStatement -\n"<< 
                "j " << label1 << "\n";
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
    while(it!=ids.end()){
        DeclItem *item=*it;
        if (sTable.find(item->id) != sTable.end()) {
            printf("Variable %s already exist.\n",item->id.c_str());
            exit(0);
        }
        VValue v;
        v.type=type;
        sTable[item->id] =v;
        cout << item->id << ": .word 0" << endl;
        if(value!=0){
            code = this->value->generateCode(place1,i+1);

            place =newTemp();
            releaseTemp(place1);

            ss << GetIdentation(i)<<"#-AssignStatement-\n"<<code << endl <<
            GetIdentation(i+1)<<"la " << place << ", " << item->id << endl <<
            GetIdentation(i+1)<<"sw " << place1 << ", " << "0(" << place << ")" << endl;
            releaseTemp(place);
        }
        it++;
    }
    return ss.str();
}

string Method::generateCode(int i) {
    stringstream ss;
    ss<<"\n"<<GetIdentation(i)<<"#"<<getStringFromType(type)<<" "<<id<<"(){"<<endl;
    DeclList::iterator it=this->declare.begin();
    while(it!=this->declare.end()){
        Declaration *d =*it;
        ss<<d->generateCode(i+1);
        it++;
    }
    string lab1,lab2;

    StatementList::iterator it2=this->statementBlock.begin();
    while(it2!=this->statementBlock.end()){
        Statement*s =*it2;
        ss<<s->generateCode(lab1,lab2,i+1)<<endl;
        it2++;
    }
    ss<<GetIdentation(i)<<"#}";
    return ss.str();
}