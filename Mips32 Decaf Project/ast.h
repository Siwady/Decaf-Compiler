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

enum VarType {
    INT, BOOLEAN, STRINGS, CHARACTER, FUNCTION, ARRAY
};

enum MethodType {
    M_VOID, M_INT, M_BOOLEAN
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
    IMPLEMENT_BINARY_EXPR_TOSTRING("<", 40)
};

class GreaterThanExpr : public BinaryExpr {
public:

    GreaterThanExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {
    }

    string generateCode(string &place,int i);
    IMPLEMENT_BINARY_EXPR_TOSTRING(">", 40)
};

class LessThanEqualExpr : public BinaryExpr {
public:

    LessThanEqualExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {
    }

    string generateCode(string &place,int i);
    IMPLEMENT_BINARY_EXPR_TOSTRING("<=", 40)
};

class GreaterThanEqualExpr : public BinaryExpr {
public:

    GreaterThanEqualExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {
    }

    string generateCode(string &place,int i);
    IMPLEMENT_BINARY_EXPR_TOSTRING(">=", 40)
};

class NotEqualExpr : public BinaryExpr {
public:

    NotEqualExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {
    }

    string generateCode(string &place,int i);
    IMPLEMENT_BINARY_EXPR_TOSTRING("!=", 30)
};

class EqualExpr : public BinaryExpr {
public:

    EqualExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {
    }

    string generateCode(string &place,int i);
    IMPLEMENT_BINARY_EXPR_TOSTRING("==", 30)
};

class AddExpr : public BinaryExpr {
public:

    AddExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {
    }

    string generateCode(string &place,int i);
    IMPLEMENT_BINARY_EXPR_TOSTRING("+", 70)
};

class SubExpr : public BinaryExpr {
public:

    SubExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {
    }

    string generateCode(string &place,int i);
    IMPLEMENT_BINARY_EXPR_TOSTRING("-", 70)
};

class MultExpr : public BinaryExpr {
public:

    MultExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {
    }

    string generateCode(string &place,int i);
    IMPLEMENT_BINARY_EXPR_TOSTRING("*", 80)
};

class DivExpr : public BinaryExpr {
public:

    DivExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {
    }

    string generateCode(string &place,int i);
    IMPLEMENT_BINARY_EXPR_TOSTRING("/", 80)
};

class NegativeExpr : public Expr {
public:

    NegativeExpr(Expr *expr) {
        this->expr = expr;
    }

    Expr *expr;
    string generateCode(string &place,int i);
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
};

class OrExpr : public BinaryExpr {
public:

    OrExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {
    }

    string generateCode(string &place,int i);
    IMPLEMENT_BINARY_EXPR_TOSTRING("||", 10)
};

class AndExpr : public BinaryExpr {
public:

    AndExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {
    }

    string generateCode(string &place,int i);
    IMPLEMENT_BINARY_EXPR_TOSTRING("||", 20)
};

class ShiftLeftExpr : public BinaryExpr {
public:

    ShiftLeftExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {
    }

    string generateCode(string &place,int i);
    IMPLEMENT_BINARY_EXPR_TOSTRING("<<", 50)
};

class RotExpr : public BinaryExpr {
public:

    RotExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {
    }

    string generateCode(string &place,int i);
    IMPLEMENT_BINARY_EXPR_TOSTRING("rot", 50)
};

class ModExpr : public BinaryExpr {
public:

    ModExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {
    }

    string generateCode(string &place,int i);
     IMPLEMENT_BINARY_EXPR_TOSTRING("%", 60)
};

class ShiftRightExpr : public BinaryExpr {
public:

    ShiftRightExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {
    }

    string generateCode(string &place,int i);
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
};

class IdExpr : public Expr {
public:

    IdExpr(string id) {
        this->id = id;
    }

    string id;
    string generateCode(string &place,int i);
    string toStringHelper(int &prec) { prec = 110; return id; }
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
};

class StrExpr : public Expr {
public:

    StrExpr(string id) {
        this->val = id;
    }

    string val;
    string generateCode(string &place,int i);
    string toStringHelper(int &prec){ prec = 110; return "\""+val+"\""; }
};

class CharExpr : public Expr {
public:

    CharExpr(char value) {
        this->value.type = CHARACTER;
        this->value.u.cvalue = value;
    }

    VValue value;
    string generateCode(string &place, int i);
    string toStringHelper(int &prec){ prec = 110; return "\'"+ConvertToString(value.CharValue())+ "\'"; }
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
    
};

class ContinueStatement : public Statement {
public:

    ContinueStatement() {
    }

    StatementKind getKind() {
        return CONTINUE_STATEMENT;
    }
    string generateCode (string label1,string label2,int i);
};

class BreakStatement : public Statement {
public:

    BreakStatement() {
    }

    StatementKind getKind() {
        return BREAK_STATEMENT;
    }
    string generateCode (string label1,string label2,int i);
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
};

class Declaration {
public:

    Declaration(VarType type, DeclItemList ids, Expr *value) {
        this->ids = ids;
        this->type = type;
        this->value = value;
    }
    string generateCode(int i);
    DeclItemList ids;
    VarType type;
    Expr* value;
};

class Param {
public:

    Param(VarType type, string id) {
        this->id = id;
        this->type = type;
    }
    string id;
    VarType type;
};

typedef list<Param*> ParamList;
typedef list<Declaration*> DeclList;

class Method {
public:
    Method(){
    
    }
    Method(MethodType type, string id, ParamList params, DeclList declare, list<Statement*> statementBlock) {
        this->id = id;
        this->type = type;
        this->statementBlock = statementBlock;
        this->params = params;
        this->declare = declare;
    }
    string id;
    MethodType type;
    string generateCode(int i);
    list<Statement*> statementBlock;
    ParamList params;
    DeclList declare;
    map<string, VValue> LTable;
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
};

typedef list<AssignStatement*> AssignList;

extern map<string, VValue> sTable;
extern map<string, Method*> mTable;
typedef map<string, Method*> AcVariables;
extern VValue returnValue;
extern string MethodName;
#endif
