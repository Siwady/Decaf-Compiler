
#include "tree.h"
#include <algorithm>

using namespace std;

#define IMPLEMENT_RELATIONAL_OPERATION(CLASS,OP) 								\
    VValue CLASS::evaluate()													\
    {																			\
        VValue val;																\
        VValue e1,e2;															\
        val.type=BOOLEAN;														\
        e1=expr1->evaluate();													\
        e2=expr2->evaluate();													\
        if(e1.type==INT && e2.type==INT){										\
                val.type=BOOLEAN;													\
                val.u.bvalue=e1.IntValue() OP e2.IntValue(); 						\
        }else if(e1.type==INT && e2.type==BOOLEAN){									\
                val.u.bvalue=e1.IntValue() OP e2.BoolValue(); 						\
                                                                                                                                                        \
        }else if(e2.type==INT && e1.type==BOOLEAN){									\
                val.u.bvalue=e2.IntValue() OP e1.BoolValue(); 						\
                                                                                                                                                        \
        }else{																	\
                printf("Expected Bool or Integer"); 								\
        }																		\
        return val;																\
    }	

#define IMPLEMENT_ARITHMETIC_OPERATION(CLASS,OP) 								\
	VValue CLASS::evaluate()													\
	{																			\
		VValue val;																\
		VValue e1,e2;															\
																				\
		e1=expr1->evaluate();													\
		e2=expr2->evaluate();													\
																				\
	 	if(e1.type==INT && e2.type==INT){										\
	 		val.type=INT;														\
			val.u.ivalue=e1.IntValue() OP e2.IntValue(); 						\
	 	}																		\
	 	return val;																\
 	}

IMPLEMENT_RELATIONAL_OPERATION(LessThanExpr, <)
IMPLEMENT_RELATIONAL_OPERATION(GreaterThanExpr, >)
IMPLEMENT_RELATIONAL_OPERATION(LessThanEqualExpr, <=)
IMPLEMENT_RELATIONAL_OPERATION(GreaterThanEqualExpr, >=)
IMPLEMENT_RELATIONAL_OPERATION(NotEqualExpr, !=)
IMPLEMENT_RELATIONAL_OPERATION(EqualExpr, ==)
IMPLEMENT_RELATIONAL_OPERATION(OrExpr, ||)
IMPLEMENT_RELATIONAL_OPERATION(AndExpr, &&)

IMPLEMENT_ARITHMETIC_OPERATION(AddExpr, +)
IMPLEMENT_ARITHMETIC_OPERATION(SubExpr, -)
IMPLEMENT_ARITHMETIC_OPERATION(MultExpr, *)
IMPLEMENT_ARITHMETIC_OPERATION(DivExpr, /)
IMPLEMENT_ARITHMETIC_OPERATION(ShiftLeftExpr, <<)
IMPLEMENT_ARITHMETIC_OPERATION(ShiftRightExpr, >>)
IMPLEMENT_ARITHMETIC_OPERATION(ModExpr, %)

map<string, VValue> sTable;
map<string, Method*> mTable;
VValue returnValue;
string MethodName;

string getTextForEnum(int enumVal) {
    switch (enumVal) {
        case BOOLEAN:
            return "Boolean";
        case INT:
            return "Int";

        default:
            return "Not recognized..";
    }
}

void PrintStatement::execute() {
    VValue result;
    list<Expr*>::iterator it = expr.begin();
    while (it != expr.end()) {
        Expr *e = *it;
        result = e->evaluate();
        if (result.type == INT) {
            if(result.isArray==1){
                printf("%d", result.getIntArrayValue());
            }else{
                printf("%d", result.IntValue());
            }
        } else if (result.type == STRINGS) {
            string s = result.StringValue();
            for (int i = 0; i < s.size(); i++) {

                if (s.at(i) == '\\' && i + 1 < s.size() && s.at(i + 1) == 'n') {
                    printf("\n");
                    i++;
                } else if (s.at(i) == '\\' && i + 1 < s.size() && s.at(i + 1) == 't') {
                    printf("\t");
                    i++;
                } else if (s.at(i) == '\\' && i + 1 < s.size() && s.at(i + 1) == 'r') {
                    printf("\r");
                    i++;
                } else if (s.at(i) == '\\' && i + 1 < s.size() && s.at(i + 1) == 'a') {
                    printf("\a");
                    i++;
                } else if (s.at(i) == '\\' && i + 1 < s.size() && s.at(i + 1) == '\\') {
                    printf("\\");
                    i++;
                } else if(s.at(i) == '\\' && i + 1 < s.size()){
                    printf("unknown escape character. \n");
                    exit(0);
                }else{
                    printf("%c", s.at(i));
                }

            }
        } else if (result.type == BOOLEAN) {
            if(result.isArray==1){
                printf("%s", result.getBoolArrayValue()?"True":"False");
            }else{
                printf("%s", result.BoolValue()?"True":"False");
            }
        } else if (result.type == CHARACTER) {
            printf("%c", result.CharValue());
        }
        it++;
    }
}

void BlockStatement::execute() {
    list<Statement *>::iterator it = stList.begin();

    while (it != stList.end()) {
        Statement *st = *it;

        st->execute();
        it++;
    }
}

void AssignStatement::execute() {
    
    VValue var;
    bool method=false;
    if (sTable.find(id) == sTable.end()) {
        if (mTable.find(MethodName) != mTable.end()) {
            if (mTable[MethodName]->LTable.find(id) != mTable[MethodName]->LTable.end()) {
                var= mTable[MethodName]->LTable[id];
                method=true;
            }else{
                printf("Variable %s is not declared\n", id.c_str());
                exit(0);
            }
        }else{
            printf("Variable %s is not declared\n", id.c_str());
            exit(0);
        }
    }else{
        var=sTable[id];
        method=false;
    }
    
    VValue result = expr->evaluate();
    result.isArray=false;
    
    if(var.isArray==1){
        
        if(dim==0){
            printf("%s is an Array",id.c_str());
        }
        int d=dim->evaluate().IntValue();
        if(var.type==INT){
            var.setIntArrayValue(d,result.IntValue());
        }else{
            var.setBoolArrayValue(d,result.BoolValue());
        }
        if(method){
            mTable[MethodName]->LTable[id]=var;
        }else{
            sTable[id] = var;
        }
    }else{
        if(var.type!=result.type){
            printf("Incompatible types.\n");
        }
        if(method){
            mTable[MethodName]->LTable[id]=result;
        }else{
            sTable[id] = result;
        }
    }
}

void IfStatement::execute() {
    
    int result = cond->evaluate().IntValue();

    if (result) {
        StatementList::iterator it = trueBlock.begin();
        while (it != trueBlock.end()) {
            Statement* s = *it;
            s->execute();
            if (s->getKind() == BREAK_STATEMENT) {
                return;
            }
            it++;
        }
    } else if (falseBlock.size() != 0) {
        StatementList::iterator it2 = falseBlock.begin();
        while (it2 != falseBlock.end()) {
            Statement* s = *it2;
            s->execute();
            if (s->getKind() == BREAK_STATEMENT) {
                return;
            }
            it2++;
        }
    }
    
    
}

void WhileStatement::execute() {
    continueWhile:
        while (cond->evaluate().BoolValue()) {
            StatementList::iterator it = statementBlock.begin();
            while (it != statementBlock.end()) {
                Statement* s = *it;
                s->execute();
                if (s->getKind() == BREAK_STATEMENT) {
                    return;
                }
                if (s->getKind() == CONTINUE_STATEMENT) {
                    goto continueWhile;
                }
                it++;
            }
        }
}

void Method::execute() {
    if (mTable.find(id) != mTable.end()) {
        printf("there is already a method with that name \"%s\"\n", id.c_str());
        exit(0);
    }
    if(id.find(string("main"))!=string::npos && params.size()>0){
        printf("main Method can't have params.\n");
    }
    
    ParamList::iterator it3 = this->params.begin();
    while (it3 != this->params.end()) {
        Param *s = *it3;
        if (LTable.find(s->id) != LTable.end() && sTable.find(s->id) != sTable.end()) {
            printf("Variables \"%s\" already exist.", s->id.c_str());
        }
        VValue v;
        v.type = s->type;
        v.u.bvalue = false;
        v.u.cvalue = '\0';
        v.u.ivalue = 0;
        v.u.svalue = '\0';
        v.isArray=false;
        v.ArraySize=0;
        this->LTable[s->id] = v;
        it3++;
    }

    DeclList::iterator it = this->declare.begin();
    while (it != this->declare.end()) {
        Declaration *d = *it;
        DeclItemList::iterator it2 = d->ids.begin();
        while (it2 != d->ids.end()) {
            DeclItem *s = *it2;
            if (LTable.find(s->id) != LTable.end() && sTable.find(s->id) != sTable.end()) {
                printf("Variables \"%s\" already exist.", s->id.c_str());
            }
            if(d->value!=0){
                this->LTable[s->id] = d->value->evaluate();
            }else{
                VValue v;
                v.type = d->type;
                v.u.bvalue = false;
                v.u.cvalue = '\0';
                v.u.ivalue = 0;
                v.u.svalue = '\0';
                v.isArray=false;
                v.ArraySize=0;
                this->LTable[s->id] = v;
                
            }
            it2++;
        }
        it++;
    }
    mTable[id] = this;
}

void Program::Initialize() {
    if (Variables != 0) {
        list<Declaration*>::iterator it = Variables->begin();

        while (it != Variables->end()) {
            Declaration *de = *it;
            de->execute();
            it++;
        }
    }
    if (Methods != 0) {
        MethodList::iterator it = Methods->begin();

        while (it != Methods->end()) {
            Method* m = *it;
            m->execute();
            it++;
        }
    }
}

void Program::RunMain(){
    /*MethodList::iterator it= Methods->begin();
    bool found=false;
    while(it!=Methods->end())
    {  
        Method *m =*it;
        if(m->id.find(string("main"))!=string::npos)
        {   
            StatementList::iterator it2 = m->statementBlock.begin();
            while (it2 != m->statementBlock.end()) {
                Statement* s = *it2;
                s->execute();
                it2++;
            }
            
            found=true;
        }
        it++;
    }
    
    if(!found){
        printf("There is no method called \"main\"\n");
    }*/
    MethodName="main";
    if(mTable.find("main")==mTable.end()){
        printf("There is no method called \"main\"\n");
    }
    Method *m =mTable["main"];
    StatementList::iterator it = m->statementBlock.begin();
    while (it != m->statementBlock.end()) {
        Statement* s = *it;
        s->execute();
        it++;
    }
    MethodName="";
}

void ForStatement::execute() {
    StatementList::iterator it = assignStatement.begin();
    while (it != assignStatement.end()) {
        Statement* s = *it;
        if (s->getKind() != ASSIGN_STATEMENT) {
            printf("Expected Assign statement");
            exit(0);
        }
        s->execute();
        it++;
    }

    while(cond->evaluate().BoolValue()) {
        StatementList::iterator it3 = statementBlock.begin();
        while (it3 != statementBlock.end()) {
            Statement* s = *it3;
            s->execute();
            if (s->getKind() == BREAK_STATEMENT) {
                return;
            }
            if (s->getKind() == CONTINUE_STATEMENT) {
                goto continueFor;
                
            }
            it3++;
        }
        continueFor:
            StatementList::iterator it2 = finalAssignStatement.begin();
            while (it2 != finalAssignStatement.end()) {
                Statement* s2 = *it2;
                if (s2->getKind() != ASSIGN_STATEMENT) {
                    printf("Expected Assign statement");
                    exit(0);
                }
                s2->execute();
                it2++;
            }
    }
}

void Declaration::execute() {
    VValue val;
    if (value != 0) {
        val = value->evaluate();

        if (val.type != type) {
            printf("incompatible types");
        }
    }
    if (type == INT) {
        val.u.ivalue = val.IntValue();
    } else if (type == BOOLEAN) {
        val.u.bvalue = val.BoolValue();
    }
    DeclItemList::iterator it = ids.begin();
    while (it != ids.end()) {
        DeclItem *id = *it;
        if (sTable.find(id->id) != sTable.end()) {
            printf("Variable %s is already declared\n", id->id.c_str());
            exit(0);
        }
        if (id->dimension > 0) {
            val.type=type;
            val.isArray = true;
            val.ArraySize = id->dimension;
            if(val.type==INT){
                val.u.a_ivalue=new int[id->dimension];
                for(int i=0;i<id->dimension;i++){
                    val.setIntArrayValue(i,0);
                }
            }else{
                val.u.a_bvalue=new bool[id->dimension];
                for(int i=0;i<id->dimension;i++){
                    val.setBoolArrayValue(i,false);
                }
            }
        }
        sTable[id->id] = val;
        it++;
    }
}

void ReadStatement::execute() {
    list<string>::iterator it = ids.begin();
    while (it != ids.end()) {
        string id = *it;
        string input = "";
        if (sTable.find(id) == sTable.end()) {
            printf("Variable %s is not declared\n", id.c_str());
            exit(0);
        }
        getline(cin, input);
        //sTable[id]=val;
        it++;
    }
}

void ContinueStatement::execute() {
    //Nothing to do.
}

void BreakStatement::execute() {
    //Nothing to do.
}

void ReturnStatement::execute() {
    VValue v;
    if (expr == 0) {
        v.isArray=false;
        returnValue = v;
    } else {
        returnValue = this->expr->evaluate();
        returnValue.isArray=false;
    }
}

void MethodStatement::execute() {
    string previous=MethodName;
    MethodName = this->id;
    if (mTable.find(id) == mTable.end()) {
        printf("\nThere is not a method \"%s\"\n", id.c_str());
        exit(0);
    }
    Method* m = mTable[id];

    if (exprs.size() != m->params.size()) {
        printf("Expected %d parameters.\n", m->params.size());
        exit(0);
    }

    ExprList::iterator it2 = exprs.begin();
    ParamList::iterator it3 = m->params.begin();
    while (it2 != exprs.end()) {
        VValue v = (*it2)->evaluate();
        Param * p = *it3;
        if (v.type != p->type) {
            printf("Expected %s type.\n ", getTextForEnum(p->type).c_str());
            exit(0);
        }
        m->LTable[p->id] = v;
        it2++;
        it3++;
    }

    StatementList::iterator it = m->statementBlock.begin();
    while (it != m->statementBlock.end()) {
        Statement* s = *it;
        s->execute();
        it++;
    }
    MethodName = previous;
}

VValue IdExpr::evaluate() {
    if (sTable.find(id) == sTable.end()) {
        if (mTable.find(MethodName) != mTable.end()) {
            if (mTable[MethodName]->LTable.find(id) != mTable[MethodName]->LTable.end()) {
                return mTable[MethodName]->LTable[id];
            }
        }
        printf("Variable %s is not declared\n", id.c_str());
        exit(0);
    }

    return sTable[id];
}

VValue ArrayExpr::evaluate() {
    
    if (sTable.find(id) == sTable.end()) {
        if (mTable.find(MethodName) != mTable.end()) {
            if (mTable[MethodName]->LTable.find(id) != mTable[MethodName]->LTable.end()) {
                return mTable[MethodName]->LTable[id];
            }
        }
        printf("Variable %s is not declared\n", id.c_str());
        exit(0);
    }
    VValue v=sTable[id];
    v.Pos=dim->evaluate().IntValue();
    sTable[id]=v;
    return sTable[id];
}

VValue StrExpr::evaluate() {
    VValue value;
    value.type = STRINGS;
    value.u.svalue = strdup(val.c_str());
    value.isArray=false;
    return value;
}

VValue NegativeExpr::evaluate() {
    VValue v = expr->evaluate();
    v.isArray=false;
    if (v.type == INT) {
        v.u.ivalue = v.IntValue()*(-1);
        return v;
    } else {
        printf("Expected integer.");
        exit(0);
    }

}

VValue NotExpr::evaluate() {
    VValue v = expr->evaluate();
    v.isArray=false;
    if (v.type == BOOLEAN) {
        v.u.bvalue = !v.BoolValue();
        return v;
    } else if (v.IntValue() != 0) {
        v.u.bvalue = !true;
        return v;
    } else {
        v.u.bvalue = !false;
        return v;
    }
}

VValue MethodExpr::evaluate() {
    string previous=MethodName;
    MethodName = this->id;
    if (mTable.find(id) == mTable.end()) {
        printf("\nThere is not a method \"%s\"\n", id.c_str());
        exit(0);
    }
    Method* m = mTable[id];

    if (exprs.size() != m->params.size()) {
        printf("Expected %d parameters.\n", m->params.size());
        exit(0);
    }

    ExprList::iterator it2 = exprs.begin();
    ParamList::iterator it3 = m->params.begin();
    while (it2 != exprs.end()) {
        VValue v = (*it2)->evaluate();
        Param * p = *it3;
        if (v.type != p->type) {
            printf("Expected %s type.\n", getTextForEnum(p->type).c_str());
            exit(0);
        }
        m->LTable[p->id] = v;
        it2++;
        it3++;
    }

    StatementList::iterator it = m->statementBlock.begin();
    while (it != m->statementBlock.end()) {
        Statement* s = *it;
        s->execute();
        it++;
    }
    MethodName = previous;
    return returnValue;
}

VValue RotExpr::evaluate() {
    int number = expr1->evaluate().IntValue();
    int count = expr2->evaluate().IntValue();
    VValue v;
    v.type = INT;
    v.u.bvalue = false;
    v.u.cvalue = '\0';
    v.u.ivalue = 0;
    v.u.svalue = '\0';
    v.isArray=false;
    v.ArraySize=0;
    
    int firt_bit = (number >> 0) & 1;
    int last_bit = (number >> 31) & 1;
    
    if(count<0){
        number=number>>count;
        if(firt_bit==1){
            number |= 1 << 31;
        }
    }else if(count>0){
        number=number<<count;
        if(last_bit==1){
            number |= 1 << 0;
        }
    }
    
    v.u.ivalue=number;
    
    return v;
}


