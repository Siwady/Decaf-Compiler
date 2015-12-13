
#include "ast.h"
#include <algorithm>
#include <sstream>

using namespace std;

const char *temps[] = {"$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", "$t8", "$t9"};
const char *Stemps[] = {"$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7"};
#define TEMP_COUNT (sizeof(temps)/sizeof(temps[0]))       

int Label,ChLabel,StrLabel;
map<string, int> tempMap;
map<string, VValue> sTable;
map<string, Method*> mTable;
map<string,string> StringConstants; //String Constants.
map<char,string> CharConstants;     //Char Constants.
string forAssignCode;
string EndMethod;
string MethodName;

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
string newSTemp() {
    int i;
    for (i = 0; i < 8; i++) {
        if (tempMap.find(Stemps[i]) == tempMap.end()) {
            tempMap[Stemps[i]] = 1;
            return string(Stemps[i]);
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
int GetOffset(ParamList params,DeclList declare){
    int offset=4;
    offset+=params.size()*4;
    DeclList::iterator it=declare.begin();
    while(it!=declare.end()){
        Declaration *d=*it;
        offset+=d->ids.size()*4;
        it++;
    }
    return offset;
}

string GetIndentation(int i)
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
    ss<<"#"<<this->toString()<<endl;
    DeclList::iterator it=this->Variables->begin();
    while(it!=this->Variables->end()){
        Declaration *d=*it;
        ss<<d->generateCode(1);
        it++;
    }
    ss<<GetIndentation(1)<<"jal main \n"<<
        GetIndentation(1)<<"j EndClass\n";

    MethodList::iterator it2=this->Methods->begin();
    while(it2!=this->Methods->end()){
        Method *m =*it2;
        ss<<m->generateCode(1)<<endl;
        it2++;
    }
    ss<<"\nEndClass:\n"<<
        GetIndentation(1)<< "li $v0, 10\n"<<
        GetIndentation(1)<< "syscall\n"<<
    "#}\n";

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

    ss<<code1 << endl <<
        code2 << endl <<
        GetIndentation(i)<<"add " << place << ", " << place1 << ", " << place2;
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
    
    ss<<code1 << endl <<
        code2 << endl <<
        GetIndentation(i)<<"sub " << place << ", " << place1 << ", " << place2;
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

    ss<<code1 << endl <<
        code2 << endl <<
        GetIndentation(i)<<"mult " << place1 << ", " << place2 << endl <<
        GetIndentation(i)<<"mflo " << place;

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

    ss<<code1 << endl <<
        code2 << endl <<
        GetIndentation(i)<<"div " << place1 << ", " << place2 << endl <<
        GetIndentation(i)<<"mflo " << place;

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
    
    ss<<code1 << endl <<
        code2 << endl <<
        GetIndentation(i)<<"slt " << place << ", " << place1 << ", " << place2;
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
    
    ss<<code1 << endl <<
        code2 << endl <<
        GetIndentation(i)<<"slt " << place << ", " << place2 << ", " << place1;
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
    
    ss<<code1 << endl <<
        code2 << endl <<
        GetIndentation(i)<<"slt "  << place << ", " << place2 << ", " << place1 <<"\n"<<
        GetIndentation(i)<<"nor "  << place << ", " << place  << ", " << place  << "\n"<<
        GetIndentation(i)<<"addi " << place << ", " << place  << ", 2";
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
    
    ss<<code1 << endl <<
        code2   << endl <<
        GetIndentation(i)<<"slt "  << place << ", " << place1 << ", " << place2 <<"\n"<<
        GetIndentation(i)<<"nor "  << place << ", " << place  << ", " << place  <<"\n"<<
        GetIndentation(i)<<"addi " << place << ", " << place  << ", 2";
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
    
    ss<<code1 << endl <<
        code2 << endl <<
        GetIndentation(i)<<"beq "<< place1 << ", " << place2 << ", " <<true_l<<"\n"<<
        GetIndentation(i)<<"li " << place  << ", " << "0\n"  <<
        GetIndentation(i)<<"j "  << end_l  << "\n" <<
        GetIndentation(i)<<true_l<< ":\n"  <<
        GetIndentation(i+1)<<"li " << place  << ", " << "1\n"  <<
        GetIndentation(i)<<end_l << ":\n";
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
    
    ss<<code1 << endl <<
        code2 << endl <<
        GetIndentation(i)<<"beq "<< place1 << ", " << place2 << ", " <<true_l<<"\n"<<
        GetIndentation(i)<<"li " << place  << ", " << "1\n"  <<
        GetIndentation(i)<<"j "  << end_l  << "\n" <<
        GetIndentation(i)<<true_l<< ":\n"  <<
        GetIndentation(i+1)<<"li " << place  << ", " << "0\n"  <<
        GetIndentation(i)<<end_l << ":\n";
    this->type=BOOLEAN;
    return ss.str();
}

string IntExpr::generateCode(string &place, int i)
{
    stringstream ss;
    place = newTemp();
    ss << GetIndentation(i)<<"li " << place << ", " << value.IntValue();
    this->type=INT;
    return ss.str();
}
string BoolExpr::generateCode(string &place, int i)
{
    stringstream ss;
    place = newTemp();
    ss <<GetIndentation(i)<< "li " << place << ", " << value.BoolValue();
    this->type=BOOLEAN;
    return ss.str();
}

string ArrayExpr::generateCode(string &place, int i)
{
    string place1=newTemp();
    string place2=newTemp();
    string place3=newTemp();
    string place4=newTemp();
    string code=this->dim->generateCode(place1,i);
    stringstream ss;

    place = newTemp();
    ss<<GetIndentation(i)<<"la " << place3 << ", " << id << endl <<
        code<<endl<<
        GetIndentation(i)<<"add " <<place2<<", "<< place1 << ", " << place1 << endl <<
        GetIndentation(i)<<"add " <<place2<<", "<< place2 << ", " << place2 << endl <<
        GetIndentation(i)<<"add " <<place4<<", "<< place2 << ", " << place3 << endl <<
        GetIndentation(i)<<"lw " << place << ", " << "0("<< place4 << ")";

    releaseTemp(place1);
    releaseTemp(place2);
    releaseTemp(place3);
    releaseTemp(place4);
    this->type=sTable[id].type;
    return ss.str();
}

string IdExpr::generateCode(string &place, int i)
{
    stringstream ss;
    Method *m=mTable[MethodName];

    if(m->LTable.find(id)!=m->LTable.end()){
        place = newSTemp();
        int offset=m->LTable[id].Offset;
        ss << GetIndentation(i)<<"lw " << place << ", " <<offset<<"($sp)";
        this->type=sTable[id].type;

    }else if (sTable.find(id) != sTable.end()) {
        place = newTemp();
        ss<<GetIndentation(i)<<"la " << place << ", " << id << endl <<
            GetIndentation(i)<<"lw " << place << ", " << "0("<< place << ")";
        this->type=sTable[id].type;
    }
    return ss.str();
}

string NegativeExpr::generateCode(string& place, int i){
    stringstream ss;
    string place1;
    string place2=newTemp();
    string code = this->expr->generateCode(place1,i);

    place = newTemp();
    ss<<code<<endl<<
        GetIndentation(i)<<"li " << place2 << ", -1" << endl <<
        GetIndentation(i)<<"mult " << place1<< ", "<< place2 << endl <<
        GetIndentation(i)<<"mflo " << place;
    this->type=INT;
    releaseTemp(place1);
    releaseTemp(place2);

    return ss.str();
}

string CharExpr::generateCode(string& place, int i){
    stringstream ss;
    string lab;

    this->type=CHARACTER;
    place = newTemp();
    if(CharConstants.find(this->value.CharValue())==CharConstants.end()){
        lab=newChar();
        CharConstants[this->value.CharValue()]=lab;
    }else{
        lab=CharConstants[this->value.CharValue()];
    }
    ss << GetIndentation(i)<<"lb " <<place<<", "<<lab;

    return ss.str();
}

string StrExpr::generateCode(string& place, int i){
    stringstream ss;
    string lab;

    this->type=STRINGS;
    place = newTemp();
    if(StringConstants.find(this->val)==StringConstants.end()){
        lab=newString();
        StringConstants[this->val]=lab;
    }else{
        lab=StringConstants[this->val];
    }
    ss << GetIndentation(i)<<"la " <<place<<", "<<lab;

    return ss.str();

}

string MethodExpr::generateCode(string& place, int i){
    stringstream ss;
    string parameters[]={"$a0","$a1","$a2","$a3"};
    string code,place1;
    int x=0;
    place=newTemp();
    ExprList::iterator it=this->exprs.begin();
    while(it!=exprs.end()){
        Expr *e=*it;
        code=e->generateCode(place1,i+1);
        ss<<GetIndentation(i)<<"#"<<e->toString()<<endl<<
            code<<endl<<
            GetIndentation(i+1)<<"add "<<parameters[x]<<", $zero, "<<place1<<endl;
        releaseTemp(place1);
        it++;
        x++;
    }
    ss<<GetIndentation(i)<<"jal "<<this->id<<endl<<
        GetIndentation(i)<<"add "<<place<<", $zero, $v0";

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
    ss<<code1 << endl <<
        code2 << endl <<
        GetIndentation(i)<<"sllv " << place << ", " << place1 << ", " << place2;
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
    ss<<code1 << endl <<
        code2 << endl <<
        GetIndentation(i)<<"srlv " << place << ", " << place1 << ", " << place2;
    this->type=INT;

    return ss.str();
}

string RotExpr::generateCode(string& place, int i){
    stringstream ss;
    string place1, place2;
    string code1 = expr1->generateCode(place1,i);
    string code2 = expr2->generateCode(place2,i);

    this->type=INT;
    place=newTemp();
    ss<<code1 <<endl<<
        code2 << endl <<
    GetIndentation(i)<<"rol "<< place <<", "<< place1<<", " << place2;

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
    ss<<code1 << endl <<
        code2 << endl <<
        GetIndentation(i)<<"and " << place << ", " << place1 << ", " << place2;
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
    ss<<code1 << endl <<
        code2 << endl <<
        GetIndentation(i)<<"or " << place << ", " << place1 << ", " << place2;
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
    ss<<code1 << endl <<
        code2 << endl <<
        GetIndentation(i)<<"div " << place1 << ", " << place2 << endl <<
        GetIndentation(i)<<"mfhi " << place;
    this->type=INT;

    return ss.str();
}

string NotExpr::generateCode(string &place, int i)
{
    stringstream ss;
    string place1;
    string code = this->expr->generateCode(place1,i);

    this->type=BOOLEAN;
    place = newTemp();
    ss<<code<<endl<<
        GetIndentation(i)<<"nor " << place << ", "<<place1<<", "<<place1 <<endl<<
        GetIndentation(i)<<"addi " << place << ", "<<place<<", 2";
    releaseTemp(place1);

    return ss.str();
}


//------------------------------------GENERATE CODE  STATEMENT---------------------------------------------


string PrintStatement::generateCode(string label1, string label2, int i)
{
    string place1;
    string code;
    stringstream ss;

    ss<<GetIndentation(i)<<"#"<<this->toString()<<endl;
    ExprList::iterator it=expr.begin();
    while(it!=expr.end()){
        Expr *e=*it;
        code = e->generateCode(place1,i+2);
        releaseTemp(place1);
        ss<<GetIndentation(i+1)<<"#"<<e->toString()<<endl<<
            code << endl<<
            GetIndentation(i+2)<<"move $a0, " << place1<<endl;

        switch (e->type) {
            case INT:
                ss<<GetIndentation(i+2)<< "li $v0, 1" << endl;
                break;
            case STRINGS:
                ss<<GetIndentation(i+2)<< "li $v0, 4" << endl;
                break;
            case CHARACTER:
                ss<<GetIndentation(i+2)<< "li $v0, 11" << endl;
                break;
            case BOOLEAN:
                ss<<GetIndentation(i+2)<< "li $v0, 1" << endl;
                break;
            default:
                ss<<GetIndentation(i+2)<< "li $v0, 1" << endl;
        }
        ss<<GetIndentation(i+2)<< "syscall" << endl;
        it++;
    }

    return ss.str();
}

string AssignStatement::generateCode(string label1, string label2, int i)
{
    Method* m=mTable[MethodName];
    string place1;
    string code = expr->generateCode(place1,i+1);
    stringstream ss;
    string place ="";
    place=newTemp();

    if(dim==0){
        ss << GetIndentation(i)<<"# "<<id<<"="<<expr->toString()<<";"<<endl
        <<code << endl;
        if(m->LTable.find(id)!=m->LTable.end()){
            int offset=m->LTable[id].Offset;
            ss << GetIndentation(i+1)<<"sw " << place1 << ", " <<offset<<"($sp)" << endl;

        }else if (sTable.find(id) != sTable.end()) {
            ss<<GetIndentation(i+1)<<"la " << place << ", " << id << endl <<
                GetIndentation(i+1)<<"sw " << place1 << ", " << "0(" << place << ")" << endl;
        }
        releaseTemp(place1);
    }else{
        ss<<GetIndentation(i)<<"# "<<id<<"["<<dim->toString()<<"]="<<expr->toString()<<";"<<endl<<
            code << endl;

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
            GetIndentation(i)<<"la " << place3 << ", " << id << endl <<
            GetIndentation(i)<<"add " <<place2<<", "<< place2 << ", " << place2 << endl <<
            GetIndentation(i)<<"add " <<place2<<", "<< place2 << ", " << place2 << endl <<
            GetIndentation(i)<<"add " <<place4<<", "<< place2 << ", " << place3 << endl <<
            GetIndentation(i+1)<<"sw " << place1 << ", " << "0(" << place4 << ")" << endl;
    }
    releaseTemp(place);
    return ss.str();
}

string IfStatement::generateCode(string label1, string label2, int i) {
    string place1, place2;
    string code = this->cond->generateCode(place1,i+1);
    string lbl1 = newLabel();
    string lbl2 = newLabel();
    stringstream ss;
    string place = newTemp();
    string bcode ="";
    string bcode2 = "";

    place2 = newTemp();
    releaseTemp(place1);
    StatementList::iterator it=this->trueBlock.begin();
    while(it!=this->trueBlock.end()){
        Statement *s=*it;
        bcode+= s->generateCode(label1, label2,i+1);
        it++;
    }
    if (!this->falseBlock.empty()){
        StatementList::iterator it2=this->falseBlock.begin();
        while(it2!=this->falseBlock.end()){
            Statement *s=*it2;
            bcode2+= s->generateCode(label1, label2,i+1);
            it2++;
        }
    }
    ss<<GetIndentation(i)<<"#"<<this->toString()<<
        code <<endl<<
        GetIndentation(i+1)<<"add " << place2 << ", " << "$zero, $zero\n" <<
        GetIndentation(i+1)<<"beq " << place1 << ", " << place2 << ", " << lbl1 << "\n" <<
        bcode <<endl<<
        GetIndentation(i+1)<<"j " << lbl2 << "\n" <<
        GetIndentation(i)<<"#}else{\n"<<
        GetIndentation(i+1)<<lbl1 << ": \n" <<
        bcode2 <<endl<<
        GetIndentation(i)<<"#}\n"<<
        GetIndentation(i)<<lbl2 << ": \n";

    releaseTemp(place);
    return ss.str();
}

string WhileStatement::generateCode(string label1, string label2, int i) {
    string place1;
    string code = this->cond->generateCode(place1,i+2);
    stringstream ss;
    string place = newTemp();
    string bcode ="";

    label1 = newLabel();
    label2 = newLabel();
    releaseTemp(place1);
    StatementList::iterator it=this->statementBlock.begin();
    while(it!=this->statementBlock.end()){
        Statement * s=*it;
        bcode+= s->generateCode(label1,label2,i+2);
        it++;
    }
     
    ss<<GetIndentation(i)<<"#"<<this->toString()<<
        GetIndentation(i+1)<<label1 <<":\n"<<
        code <<endl<<
        GetIndentation(i+2)<<"beq " << place1 << ", " << "$zero, " << label2 << "\n" <<
        bcode <<endl<<
        GetIndentation(i+2)<<"j " << label1 << "\n" <<
        GetIndentation(i)<<"#}\n"<<
        GetIndentation(i)<<label2 << ": \n";

    releaseTemp(place);
    return ss.str();
}

string ForStatement::generateCode(string label1, string label2, int i){
    string place1;
    string code = this->cond->generateCode(place1,i+2);
    string acode1,acode2,temp;
    stringstream ss;
    string place = newTemp();

    label1 = newLabel();
    label2 = newLabel();
    releaseTemp(place1);
    if(!forAssignCode.empty()){
        temp=forAssignCode;
    }
    StatementList::iterator it2=assignStatement.begin();
    while(it2!=assignStatement.end()){
        Statement *s=*it2;
        acode1+= s->generateCode(label1,label2,i+1);
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

    ss<<GetIndentation(i)<<"#"<<this->toString()<<
        acode1 <<endl<<
        GetIndentation(i+1)<<label1 <<":\n"<<
        code <<endl<<
        GetIndentation(i+2)<<"beq " << place1 << ", " << "$zero, " << label2 << "\n" <<
        bcode<<endl<<
        acode2<<endl<<
        GetIndentation(i+2)<<"j " << label1 << "\n" <<
        GetIndentation(i)<<"#}\n"<<
        GetIndentation(i)<<label2 << ": \n";

    releaseTemp(place);
    forAssignCode=temp;
    return ss.str();
}

string ReturnStatement::generateCode(string label1, string label2, int i){
    stringstream ss;
    string code;
    string place1;
    code=this->expr->generateCode(place1,i+1);

    ss<<GetIndentation(i)<<"#"<<this->toString()<<endl<<
        code<<endl<<
        GetIndentation(i+1)<<"add $v0, $zero, "<<place1<<endl<<
        GetIndentation(i+1)<<"j " << EndMethod << "\n";
    return ss.str();
}

string MethodStatement::generateCode(string label1, string label2, int i){
    stringstream ss;
    string parameters[]={"$a0","$a1","$a2","$a3"};
    string place,code;
    int x=0;
    Method *m=mTable[this->id];

    ExprList::iterator it=this->exprs.begin();
    while(it!=exprs.end()){
        Expr *e=*it;
        code=e->generateCode(place,i+2);
        ss<<GetIndentation(i+1)<<"#"<<e->toString()<<endl<<
            code<<endl<<
            GetIndentation(i+2)<<"add "<<parameters[x]<<", $zero, "<<place<<endl;
        releaseTemp(place);
        it++;
        x++;
    }

    ss<<GetIndentation(i+2)<<"jal "<<this->id<<endl;

    return ss.str();
}

string BreakStatement::generateCode(string label1, string label2, int i) {
    stringstream ss;
    if(!label1.empty()){
        ss<<GetIndentation(i)<<"#"<< this->toString()<<endl<<
            GetIndentation(i+1)<<"j " << label2 << "\n";
    }
    return ss.str();
}

string ContinueStatement::generateCode(string label1, string label2, int i) {
    stringstream ss;
    if(!forAssignCode.empty()){
        ss<<forAssignCode<<endl;
    }
    if(!label1.empty()){
        ss<<GetIndentation(i)<< "#"<<this->toString()<<endl<<
            GetIndentation(i+1)<<"j " << label1 << "\n";
    }
    return ss.str();
}

string Declaration::generateCode(int i) {
    string place,code,place1;
    stringstream ss;
    DeclItemList::iterator it=ids.begin();
    if(value==0){
        ss<<GetIndentation(i)<<"# "<<getStringFromType(type)<<" ";
    }
    while(it!=ids.end()){
        DeclItem *item=*it;
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
            place =newTemp();
            releaseTemp(place1);

            ss<<GetIndentation(i)<<"# "<<getStringFromType(v.type)<<" "<<item->id<<"="<<this->value->toString()<<";\n"<<
                code <<endl<<
                GetIndentation(i+1)<<"la " << place << ", " << item->id << endl <<
                GetIndentation(i+1)<<"sw " << place1 << ", " << "0(" << place << ")" << endl;
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

string Declaration::generateInMethodCode(int i,int &offset)
{
    string place,code,place1;
    stringstream ss;
    DeclItemList::iterator it=ids.begin();
    Method *m=mTable[MethodName];

    if(value==0){
        ss<< GetIndentation(i)<<"# "<<getStringFromType(type)<<" ";
    }
    while(it!=ids.end()){
        DeclItem *item=*it;
        m->LTable[item->id].Offset=offset;
        m->LTable[item->id].type=this->type;

        if(value!=0){
            code = this->value->generateCode(place1,i+1);
            releaseTemp(place1);
            ss<<GetIndentation(i)<<"# "<<getStringFromType(m->LTable[item->id].type)<<" "<<item->id<<"="<<this->value->toString()<<";\n"<<
                code <<endl<<
                GetIndentation(i+1)<<"sw " << place1 << ", "<<m->LTable[item->id].Offset<< "($sp)" << endl;
            releaseTemp(place);
        }else{
            if(it==ids.begin()){
                ss<<item->id;
            }else{
                ss<<","<<item->id;
            }
        }
        offset+=4;
        it++;
        if(it==ids.end() && value==0){
            ss<<";\n";
        }
    }
    return ss.str();
}

string Method::generateCode(int i) {
    string previous=MethodName;
    string previousEnd=EndMethod;
    string parameters[]={"$a0","$a1","$a2","$a3"};
    MethodName=this->id;
    EndMethod="End"+this->id;
    stringstream ss;
    this->offset=GetOffset(params,declare);
    int pos=4;
    int paramPosition=0;
    mTable[this->id]=this;

    ss<<"\n"<<GetIndentation(i)<<"#"<<this->toString()<<endl<<
        GetIndentation(i)<<id<<":\n"<<
        GetIndentation(i+1)<<"sw $ra, 0($sp)" << endl<<
        GetIndentation(i+1)<<"addi $sp, $sp, -"<<this->offset<<endl;

    ParamList::iterator it3=this->params.begin();
    while(it3!=this->params.end()){
        Param *p =*it3;
        p->generateCode(pos);
        ss<<GetIndentation(i+1)<<"sw "<<parameters[paramPosition++]<<", "<<pos<<"($sp)"<<endl;
        it3++;
        pos+=4;
    }

    DeclList::iterator it=this->declare.begin();
    while(it!=this->declare.end()){
        Declaration *d =*it;
        ss<<d->generateInMethodCode(i+1,pos)<<endl;
        it++;
    }
    string lab1,lab2;

    StatementList::iterator it2=this->statementBlock.begin();
    while(it2!=this->statementBlock.end()){
        Statement*s =*it2;
        ss<<s->generateCode(lab1,lab2,i+1)<<endl;
        it2++;
    }

    ss<<GetIndentation(i)<<EndMethod<<":\n"<<
        GetIndentation(i+1)<<"addi $sp, $sp, "<<this->offset<<endl<<
        GetIndentation(i+1)<<"lw $ra, 0($sp)" << endl<<
        GetIndentation(i+1)<<"jr $ra\n"<<
        GetIndentation(i)<<"#}";

    MethodName=previous;
    EndMethod=previousEnd;
    mTable[this->id]=this;

    return ss.str();
}

void Param::generateCode(int offset)
{
    Method *m=mTable[MethodName];
    m->LTable[id].Offset=offset;
    m->LTable[id].type=this->type;
}

