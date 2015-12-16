#ifndef _TREE_H_ 
#define _TREE_H_

#include <string>
#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <cstring>
#include <sstream>
#include <list>
#include <map>

using namespace std;

#define IMPLEMENT_BINARY_EXPR_TOSTRING(OP, PRECEDENCE)  \
    string toStringHelper(int &prec) {                  \
        stringstream ss;                                \
        string str1, str2;                              \
        int prec1, prec2;                               \
                                                        \
        str1 = expr1->toStringHelper(prec1);            \
        str2 = expr2->toStringHelper(prec2);            \
        if (prec1 < PRECEDENCE)                         \
            str1 = addParenthesis(str1);                \
        if (prec2 < PRECEDENCE)                         \
            str2 = addParenthesis(str2);                \
                                                        \
        ss << str1 << " " OP " " << str2;               \
        prec = PRECEDENCE;                              \
        return ss.str();                                \
    }


enum VarType {
    INT, BOOLEAN, STRINGS, CHARACTER, FUNCTION, ARRAY,VOID
};

inline string getStringFromType(VarType type){
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

inline string addParenthesis(string str){
        string ss;
        ss="( "+str+" )";
        return ss;
}

inline string ConvertToString(int num){
    ostringstream convert;
    convert << num;
    return convert.str();
}
inline string ConvertToString(char ch){
    ostringstream convert;
    convert << ch;
    return convert.str();
}

typedef list<string> IdList;

struct mVariable{
    int Offset;
    VarType type;
};

struct VValue {

    int IntValue() {
        return u.ivalue;
    }

    bool BoolValue() {
        if (type == INT) {
            return true;
        }
        
        return u.bvalue;
    }

    char* StringValue() {
        return u.svalue;
    }

    char CharValue() {
        return u.cvalue;
    }

    void setIntArrayValue(int pos, int val) {
        if(pos>=ArraySize){
            printf("Out of range.\n");
            exit(0);
        }
        u.a_ivalue[pos]=val;
    }

    void setBoolArrayValue(int pos, bool val) {
        if(pos>=ArraySize){
            printf("Out of range.\n");
            exit(0);
        }
        u.a_bvalue[pos]=val;
    }
    int getIntArrayValue() {
        if(Pos>=ArraySize){
            printf("Out of range.\n");
            exit(0);
        }
        return u.a_ivalue[Pos];
    }

    bool getBoolArrayValue() {
        if(Pos>=ArraySize){
            printf("Out of range.\n");
            exit(0);
        }
        return u.a_bvalue[Pos];
    }

    VarType type;
    bool isArray;
    int ArraySize;
    int Pos;

    union {
        int ivalue;
        bool bvalue;
        char* svalue;
        char cvalue;

        int* a_ivalue;
        bool* a_bvalue;
    } u;
};
class DeclItem {
public:

    DeclItem(string id) {
        this-> id = id;
        this->dimension=0;
    }
    
    DeclItem(string id, int dimension) {
        this-> id = id;
        this->dimension = dimension;
    }
    string id;
    int dimension;
};
typedef list<DeclItem*> DeclItemList;

class Expr {
public:
    virtual string generateCode(string &place, int i) = 0;
    virtual string toStringHelper(int &prec) = 0;
    string toString() {
        int tmp;
        return toStringHelper(tmp);
    }
    VarType type;
    virtual VarType ValidateSemantic()=0;
};

typedef list<Expr*> ExprList;

class BinaryExpr : public Expr {
public:

    BinaryExpr(Expr *expr1, Expr *expr2) {
        this->expr1 = expr1;
        this->expr2 = expr2;
    }

    Expr *expr1;
    Expr *expr2;
};

class LessThanExpr : public BinaryExpr {
public:

    LessThanExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {
    }

    string generateCode(string &place, int i);
    VarType ValidateSemantic(){return this->type;}
    IMPLEMENT_BINARY_EXPR_TOSTRING("<", 40)
};

class GreaterThanExpr : public BinaryExpr {
public:

    GreaterThanExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {
    }

    string generateCode(string &place,int i);
    VarType ValidateSemantic(){return this->type;}
    IMPLEMENT_BINARY_EXPR_TOSTRING(">", 40)
};

class LessThanEqualExpr : public BinaryExpr {
public:

    LessThanEqualExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {
    }

    string generateCode(string &place,int i);
    VarType ValidateSemantic(){return this->type;}
    IMPLEMENT_BINARY_EXPR_TOSTRING("<=", 40)
};

class GreaterThanEqualExpr : public BinaryExpr {
public:

    GreaterThanEqualExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {
    }

    string generateCode(string &place,int i);
    VarType ValidateSemantic(){return this->type;}
    IMPLEMENT_BINARY_EXPR_TOSTRING(">=", 40)
};

class NotEqualExpr : public BinaryExpr {
public:

    NotEqualExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {
    }

    string generateCode(string &place,int i);
    VarType ValidateSemantic(){return this->type;}
    IMPLEMENT_BINARY_EXPR_TOSTRING("!=", 30)
};

class EqualExpr : public BinaryExpr {
public:

    EqualExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {
    }

    string generateCode(string &place,int i);
    VarType ValidateSemantic(){return this->type;}
    IMPLEMENT_BINARY_EXPR_TOSTRING("==", 30)
};

class AddExpr : public BinaryExpr {
public:

    AddExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {
    }

    string generateCode(string &place,int i);
    VarType ValidateSemantic(){return this->type;}
    IMPLEMENT_BINARY_EXPR_TOSTRING("+", 70)
};

class SubExpr : public BinaryExpr {
public:

    SubExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {
    }

    string generateCode(string &place,int i);
    VarType ValidateSemantic(){return this->type;}
    IMPLEMENT_BINARY_EXPR_TOSTRING("-", 70)
};

class MultExpr : public BinaryExpr {
public:

    MultExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {
    }

    string generateCode(string &place,int i);
    VarType ValidateSemantic(){return this->type;}
    IMPLEMENT_BINARY_EXPR_TOSTRING("*", 80)
};

class DivExpr : public BinaryExpr {
public:

    DivExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {
    }

    string generateCode(string &place,int i);
    VarType ValidateSemantic(){return this->type;}
    IMPLEMENT_BINARY_EXPR_TOSTRING("/", 80)
};

class NegativeExpr : public Expr {
public:

    NegativeExpr(Expr *expr) {
        this->expr = expr;
    }

    Expr *expr;
    string generateCode(string &place,int i);
    VarType ValidateSemantic(){return this->type;}
    string toStringHelper(int &prec){ prec = 100; return "-"+expr->toString(); }
};

class NotExpr : public Expr {
public:

    NotExpr(Expr *expr) {
        this->expr = expr;
    }

    Expr *expr;
    string generateCode(string &place,int i);
    string toStringHelper(int &prec){ prec = 90; return "!"+expr->toString();}
    VarType ValidateSemantic(){return this->type;}
};

class OrExpr : public BinaryExpr {
public:

    OrExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {
    }

    string generateCode(string &place,int i);
    VarType ValidateSemantic(){return this->type;}
    IMPLEMENT_BINARY_EXPR_TOSTRING("||", 10)
};

class AndExpr : public BinaryExpr {
public:

    AndExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {
    }

    string generateCode(string &place,int i);
    VarType ValidateSemantic(){return this->type;}
    IMPLEMENT_BINARY_EXPR_TOSTRING("||", 20)
};

class ShiftLeftExpr : public BinaryExpr {
public:

    ShiftLeftExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {
    }

    string generateCode(string &place,int i);
    VarType ValidateSemantic(){return this->type;}
    IMPLEMENT_BINARY_EXPR_TOSTRING("<<", 50)
};

class RotExpr : public BinaryExpr {
public:

    RotExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {
    }

    string generateCode(string &place,int i);
    VarType ValidateSemantic(){return this->type;}
    IMPLEMENT_BINARY_EXPR_TOSTRING("rot", 50)
};

class ModExpr : public BinaryExpr {
public:

    ModExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {
    }

    string generateCode(string &place,int i);
    VarType ValidateSemantic(){return this->type;}
     IMPLEMENT_BINARY_EXPR_TOSTRING("%", 60)
};

class ShiftRightExpr : public BinaryExpr {
public:

    ShiftRightExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {
    }

    string generateCode(string &place,int i);
    VarType ValidateSemantic(){return this->type;}
    IMPLEMENT_BINARY_EXPR_TOSTRING(">>", 50)
};

class IntExpr : public Expr {
public:

    IntExpr(int value) {
        this->value.type = INT;
        this->value.u.ivalue = value;
    }

    VValue value;
    string generateCode(string &place,int i);
    string toStringHelper(int &prec) { prec = 110; return ConvertToString(value.IntValue()); }
    VarType ValidateSemantic(){return this->type;}
};

class BoolExpr : public Expr {
public:

    BoolExpr(bool value) {
        this->value.type = BOOLEAN;
        this->value.u.bvalue = value;
    }

    VValue value;
    string generateCode(string &place,int i);
    string toStringHelper(int &prec){ prec = 110; return value.BoolValue()?"True":"False";}
    VarType ValidateSemantic(){return this->type;}
};

class IdExpr : public Expr {
public:

    IdExpr(string id) {
        this->id = id;
    }

    string id;
    string generateCode(string &place,int i);
    string toStringHelper(int &prec) { prec = 110; return id; }
    VarType ValidateSemantic(){return this->type;}
};

class ArrayExpr : public Expr {
public:

    ArrayExpr(string id, Expr* dim) {
        this->id = id;
        this->dim = dim;
    }

    string id;
    Expr* dim;
    string generateCode(string &place,int i);
    string toStringHelper(int &prec) { prec = 110; return id+"["+dim->toString()+"]"; }
    VarType ValidateSemantic(){return this->type;}
};

class StrExpr : public Expr {
public:

    StrExpr(string id) {
        this->val = id;
    }

    string val;
    string generateCode(string &place,int i);
    string toStringHelper(int &prec){ prec = 110; return "\""+val+"\""; }
    VarType ValidateSemantic(){return this->type;}
};

class CharExpr : public Expr {
public:

    CharExpr(char value) {
        this->value.type = CHARACTER;
        this->value.u.cvalue = value;
    }

    VValue value;
    string generateCode(string &place, int i);
    string toStringHelper(int &prec){
        prec = 110;
        switch (value.CharValue()) {
        case '\n':
            return "\'\\n\'";
            break;
        case '\t':
            return "\'\\t\'";
            break;
        case '\r':
            return "\'\\r\'";
            break;
        case '\a':
            return "\'\\a\'";
            break;
        case '\\':
            printf("unknown escape character. \n");
            exit(0);
            break;
        default:
            return "\'"+ConvertToString(value.CharValue())+ "\'";
        }

    }
    VarType ValidateSemantic(){return this->type;}
};

class MethodExpr : public Expr {
public:

    MethodExpr(string id, ExprList ls) {
        this->id = id;
        this->exprs = ls;
    }

    string id;
    ExprList exprs;
    string generateCode(string &place,int i);
    string toStringHelper(int &prec){
        string result="";
        result+=id+"(";
        ExprList::iterator it=exprs.begin();
        while(it!=exprs.end()){
            Expr *e=*it;
            if(it==exprs.begin()){
                result+=e->toString();
            }else{
                result+=","+e->toString();
            }
            it++;
        }
        result+=")";
        return result;
    }
    VarType ValidateSemantic();
};

enum StatementKind {
    BLOCK_STATEMENT,
    PRINT_STATEMENT,
    ASSIGN_STATEMENT,
    IF_STATEMENT,
    WHILE_STATEMENT,
    FOR_STATEMENT,
    CONTINUE_STATEMENT,
    BREAK_STATEMENT,
    RETURN_STATEMENT,
    METHOD_STATEMENT
};

class Statement {
public:
    virtual StatementKind getKind() = 0;
    virtual string generateCode (string label1,string label2,int i) = 0;
    virtual string toString()=0;
    virtual void ValidateSemantic()=0;
};

typedef list<Statement*> StatementList;

class ReturnStatement : public Statement {
public:

    ReturnStatement(Expr* expr) {
        this->expr = expr;
    }

    StatementKind getKind() {
        return RETURN_STATEMENT;
    }
    string generateCode (string label1,string label2,int i);
    Expr* expr;
    string toString(){ return "return "+expr->toString()+";";}
    void ValidateSemantic();
};

class ContinueStatement : public Statement {
public:

    ContinueStatement() {
    }

    StatementKind getKind() {
        return CONTINUE_STATEMENT;
    }
    string generateCode (string label1,string label2,int i);
    string toString(){return "continue;";}
    void ValidateSemantic(){}
};

class BreakStatement : public Statement {
public:

    BreakStatement() {
    }

    StatementKind getKind() {
        return BREAK_STATEMENT;
    }
    string generateCode (string label1,string label2,int i);
    string toString(){return "break;";}
    void ValidateSemantic(){}
};

class MethodStatement : public Statement {
public:

    MethodStatement(string id, ExprList ls) {
        this->id = id;
        this->exprs = ls;
    }

    StatementKind getKind() {
        return METHOD_STATEMENT;
    }
    string generateCode(string label1,string label2,int i);
    
    string id;
    ExprList exprs;
    string toString(){
        string exp="";
        ExprList::iterator it=exprs.begin();
        while(it!=exprs.end()){
            Expr *e=*it;
            if(it==exprs.begin()){
                exp+=e->toString();
            }else{
                exp+=","+e->toString();
            }
            it++;
        }

        return id+"("+exp+")";
    }
    void ValidateSemantic();
};

class PrintStatement : public Statement {
public:

    PrintStatement(ExprList expr) {
        this->expr = expr;
    }

    StatementKind getKind() {
        return PRINT_STATEMENT;
    }
    string generateCode (string label1,string label2,int i);
    ExprList expr;
    string toString(){
        string exp="";
        ExprList::iterator it=expr.begin();
        while(it!=expr.end()){
            Expr *e=*it;
            if(it==expr.begin()){
                exp+=e->toString();
            }else{
                exp+=","+e->toString();
            }
            it++;
        }
        return "print "+exp+";";
    }
    void ValidateSemantic(){}
};

class AssignStatement : public Statement {
public:

    AssignStatement(string id, Expr* dim, Expr *expr) {
        this->id = id;
        this->dim = dim;
        this->expr = expr;
    }

    StatementKind getKind() {
        return ASSIGN_STATEMENT;
    }
    string generateCode (string label1,string label2,int i);
    string id;
    Expr *expr;
    Expr *dim;
    string toString(){
        string exp="";
        if(dim==0){
            exp+=id+" = "+expr->toString();
        }else{
            exp+=id+"["+dim->toString()+"] = "+expr->toString();
        }
        return exp;
    }
    void ValidateSemantic();
};

class IfStatement : public Statement {
public:

    IfStatement(Expr *cond, list<Statement *>trueBlock, list<Statement *>falseBlock) {
        this->cond = cond;
        this->trueBlock = trueBlock;
        this->falseBlock = falseBlock;
    }

    StatementKind getKind() {
        return IF_STATEMENT;
    }
    string generateCode (string label1,string label2,int i);
    Expr *cond;
    list<Statement *>trueBlock;
    list<Statement *>falseBlock;
    string toString(){return "if("+cond->toString()+"){\n";}
    void ValidateSemantic();
};

class WhileStatement : public Statement {
public:

    WhileStatement(Expr *cond, list<Statement *>statementBlock) {
        this->cond = cond;
        this->statementBlock = statementBlock;
    }

    StatementKind getKind() {
        return WHILE_STATEMENT;
    }
    string generateCode (string label1,string label2,int i);
    Expr *cond;
    list<Statement *>statementBlock;
    string toString(){return "while("+cond->toString()+"){\n";}
    void ValidateSemantic();
};

class ForStatement : public Statement {
public:

    ForStatement(StatementList assignStatement, Expr *cond, StatementList finalAssignStatement, list<Statement *> statementBlock) {
        this->assignStatement = assignStatement;
        this->cond = cond;
        this->finalAssignStatement = finalAssignStatement;
        this->statementBlock = statementBlock;
    }

    StatementKind getKind() {
        return FOR_STATEMENT;
    }
    string generateCode (string label1,string label2,int i);
    StatementList assignStatement;
    Expr *cond;
    StatementList finalAssignStatement;
    list<Statement *> statementBlock;
    string toString(){
        string assign1="";
        string assign2="";
        StatementList::iterator it=assignStatement.begin();
        while(it!=assignStatement.end()){
            Statement*s=*it;
            if(it==assignStatement.begin()){
                assign1+=s->toString();
            }else{
                assign1+=","+s->toString();
            }
            it++;
        }
        StatementList::iterator it2=finalAssignStatement.begin();
        while(it2!=finalAssignStatement.end()){
            Statement*s=*it2;
            if(it2==finalAssignStatement.begin()){
                assign2+=s->toString();
            }else{
                assign2+=","+s->toString();
            }
            it2++;
        }
        return "for("+assign1+"; "+cond->toString()+"; "+assign2+"){\n";
    }

    void ValidateSemantic();
};

class Declaration {
public:

    Declaration(VarType type, DeclItemList ids, Expr *value) {
        this->ids = ids;
        this->type = type;
        this->value = value;
    }
    string generateCode(int i);
    string generateInMethodCode(int i, int &offset);
    DeclItemList ids;
    VarType type;
    Expr* value;
    void ValidateSemantic();
    void ValidateInMethodSemantic();
};

class Param {
public:

    Param(VarType type, string id) {
        this->id = id;
        this->type = type;
    }
    string id;
    VarType type;
    void generateCode(int offset);
    string toString(){
        return getStringFromType(this->type)+" "+this->id;
    }
    void ValidateSemantic(VarType paramType,VarType exprType,string id);
};

typedef list<Param*> ParamList;
typedef list<Declaration*> DeclList;

class Method {
public:
    Method(){
    
    }
    Method(VarType type, string id, ParamList params, DeclList declare, list<Statement*> statementBlock) {
        this->id = id;
        this->type = type;
        this->statementBlock = statementBlock;
        this->params = params;
        this->declare = declare;
        this->offset=(this->params.size()+this->declare.size()+1)*4;

    }
    string id;
    VarType type;
    string generateCode(int i);
    list<Statement*> statementBlock;
    ParamList params;
    DeclList declare;
    int offset;
    map<string, mVariable> LTable;
    string toString(){
        string parameters="";
        ParamList::iterator it=params.begin();
        while(it!=params.end()){
            Param *p=*it;
            if(it==params.begin()){
                parameters+=p->toString();
            }else{
                parameters+=","+p->toString();
            }
            it++;
        }
        return getStringFromType(type)+" "+id+"("+parameters+"){";
    }

    void ValidateSemantic();
};
typedef list<Method*> MethodList;


class Program {
public:
    Program(string id,DeclList *variables,MethodList *methods){
        this->id=id;
        this->Variables = variables;
        this->Methods = methods;
    }
    string generateCode();
    string id;
    MethodList *Methods;
    DeclList *Variables;
    string toString(){return "class "+id+"{";}
    void ValidateSemantic();
};

typedef list<AssignStatement*> AssignList;

extern map<string, VValue> sTable;
extern map<string, Method*> mTable;
typedef map<string, Method*> AcVariables;
extern VValue returnValue;
extern string CurrentMethod;
#endif
