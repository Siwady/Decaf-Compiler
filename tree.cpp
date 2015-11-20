#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <cstring>
#include "tree.h"
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

	IMPLEMENT_RELATIONAL_OPERATION(LessThanExpr,<)
	IMPLEMENT_RELATIONAL_OPERATION(GreaterThanExpr,>)
	IMPLEMENT_RELATIONAL_OPERATION(LessThanEqualExpr,<=)
	IMPLEMENT_RELATIONAL_OPERATION(GreaterThanEqualExpr,>=)
	IMPLEMENT_RELATIONAL_OPERATION(NotEqualExpr,!=)
	IMPLEMENT_RELATIONAL_OPERATION(EqualExpr,==)
	IMPLEMENT_RELATIONAL_OPERATION(OrExpr,||)
	IMPLEMENT_RELATIONAL_OPERATION(AndExpr,&&)
	
	IMPLEMENT_ARITHMETIC_OPERATION(AddExpr,+)
	IMPLEMENT_ARITHMETIC_OPERATION(SubExpr,-)
	IMPLEMENT_ARITHMETIC_OPERATION(MultExpr,*)
	IMPLEMENT_ARITHMETIC_OPERATION(DivExpr,/)
	IMPLEMENT_ARITHMETIC_OPERATION(ShiftLeftExpr,<<)
	IMPLEMENT_ARITHMETIC_OPERATION(ShiftRightExpr,>>)
	IMPLEMENT_ARITHMETIC_OPERATION(ModExpr,%)

map<string, VValue> sTable;
map<string, Method*> mTable;
VValue returnValue;
string MethodName;

string getTextForEnum( int enumVal )
{
  switch( enumVal )
  {
    case BOOLEAN:
      return "Boolean";
    case INT:
      return "Int";

    default:
      return "Not recognized..";
  }
}
void PrintStatement::execute() 
{	
	VValue result;
    list<Expr*>::iterator it=expr.begin();
    while(it!= expr.end()){
    	Expr *e=*it;
    	result=e->evaluate();
        if(result.type==INT){	
                printf("%d", result.IntValue());
        }else if(result.type==STRINGS)
        {
            string s=result.StringValue();
            for(int i=0;i<s.size();i++){

                if(s.at(i)=='\\' && i+1< s.size() && s.at(i+1)=='n'){
                    printf("\n");
                    i++;
                }else if(s.at(i)=='\\' && i+1< s.size() && s.at(i+1)=='t'){
                    printf("\t");
                    i++;
                }else if(s.at(i)=='\\' && i+1< s.size() && s.at(i+1)=='r'){
                    printf("\r");
                    i++;
                }else if(s.at(i)=='\\' && i+1< s.size() && s.at(i+1)=='a'){
                    printf("\a");
                    i++;
                }else if(s.at(i)=='\\' && i+1< s.size() && s.at(i+1)=='\\'){
                    printf("\\");
                    i++;
                }
                else{
                    printf("%c",s.at(i));
                }

            }
        }
        else if(result.type==BOOLEAN)
        {
                printf("%d",result.BoolValue());
        }
        else if(result.type==CHARACTER)
        {
                printf("%c",result.CharValue());
        }
        it++;
    }
}

void BlockStatement::execute() 
{	
    list<Statement *>::iterator it = stList.begin();
    
    while (it != stList.end()) {
        Statement *st = *it;
        
        st->execute();
        it++;
    }   
}

void AssignStatement::execute()
{
    if(sTable.find(id)==sTable.end()){
        printf("Variable %s is not declared\n", id.c_str());
        exit(0);
    }
    VValue result = expr->evaluate();
    sTable[id] = result;
}

void IfStatement::execute()
{
    int result = cond->evaluate().IntValue();
    
    if (result) {
        StatementList::iterator it=trueBlock.begin();
        while(it!=trueBlock.end())
        {
                Statement* s=*it;
                s->execute();
                if(s->getKind()==BREAK_STATEMENT)
                {
                    return;
                }
                it++;
        }
    } else if (falseBlock.size() != 0) {
        StatementList::iterator it2=falseBlock.begin();
        while(it2!=falseBlock.end())
        {
            Statement* s=*it2;
            s->execute();
            if(s->getKind()==BREAK_STATEMENT)
            {
                return;
            }
            it2++;
        }
    }
}

void WhileStatement::execute()
{
    while (cond->evaluate().BoolValue())
    {   
    	StatementList::iterator it=statementBlock.begin();
        while(it!=statementBlock.end())
        {
            Statement* s=*it;
            s->execute();
            if(s->getKind()==BREAK_STATEMENT)
            {
                return;
            }
            it++;
        }
    }
}
void Method::execute()
{
    if(mTable.find(id)!= mTable.end())
    {
        printf("there is already a method with that name \"%s\"\n",id.c_str());
        exit(0);
    }
    ParamList::iterator it3=this->params.begin();
    while(it3!=this->params.end()){
        Param *s=*it3;
        if(LTable.find(s->id)!=LTable.end() && sTable.find(s->id)!=sTable.end()){
            printf("Variables \"%s\" already exist.",s->id.c_str());
        }
        VValue v;
        v.type=s->type;
        v.u.bvalue=false;
        v.u.cvalue='\0';
        v.u.ivalue=0;
        v.u.svalue='\0';
        this->LTable[s->id]=v;
        it3++;
    }
    
    DeclList::iterator it=this->declare.begin();
    while(it!=this->declare.end()){
        Declaration *d=*it;
        IdList::iterator it2=d->ids.begin();
        while(it2!=d->ids.end()){
            string s=*it2;
            if(LTable.find(s)!=LTable.end() && sTable.find(s)!=sTable.end()){
                printf("Variables \"%s\" already exist.",s.c_str());
            }
            this->LTable[s]=d->value->evaluate();
            it2++;
        }
        it++;
    }
    mTable[id]=this;
}

void MainMethod::execute()
{
    StatementList::iterator it=statementBlock.begin();
    while(it!=statementBlock.end())
    {
            Statement* s=*it;
            s->execute();
            it++;
    }
}

void ForStatement::execute()
{  
    StatementList::iterator it=assignStatement.begin();
    while(it!=assignStatement.end())
    {
            Statement* s=*it;
            if(s->getKind()!=ASSIGN_STATEMENT){
                    printf("Expected Assign statement");
                    exit(0);
            }
            s->execute();
            it++;
    }
	
    for(;cond->evaluate().BoolValue();)
    {   
    	StatementList::iterator it3=statementBlock.begin();
        while(it3!=statementBlock.end())
        {
                Statement* s=*it3;
                s->execute();
                if(s->getKind()==BREAK_STATEMENT)
                {
                    return;
                }
                it3++;
        }
    	StatementList::iterator it2=finalAssignStatement.begin();
    	while(it2!=finalAssignStatement.end())
        {
                Statement* s2=*it2;
                if(s2->getKind()!=ASSIGN_STATEMENT){
                        printf("Expected Assign statement");
                        exit(0);
                }
                s2->execute();
                it2++;
        }
    }
}


void Declaration::execute()
{
	VValue val=value->evaluate();
	if(val.type!=type){
		printf("incompatible types");
	}
	if(type==INT)
	{
		val.u.ivalue=val.IntValue();
	}else if(type==BOOLEAN){
		val.u.bvalue=val.BoolValue();
	}
	list<string>::iterator it=ids.begin();
	while(it!=ids.end())
	{
		string id=*it;
		if(sTable.find(id)!=sTable.end()){
			printf("Variable %s is already declared\n", id.c_str());
			exit(0);
		}
		sTable[id]=val;
		it++;
	}
}

void ReadStatement::execute()
{
    list<string>::iterator it=ids.begin();
    while(it!=ids.end())
    {
        string id=*it;
        string input="";
        if(sTable.find(id)==sTable.end()){
            printf("Variable %s is not declared\n", id.c_str());
            exit(0);
        }
        getline(cin, input);
        //sTable[id]=val;
        it++;
    }
}

void ContinueStatement::execute()
{
    
}

void BreakStatement::execute()
{
    
}

void ReturnStatement::execute()
{
    VValue v;
    if(expr==0){
        returnValue=v;
    }else{
        returnValue=this->expr->evaluate();
    }
}

void MethodStatement::execute()
{
    MethodName=this->id;
    if(mTable.find(id)==mTable.end())
    {
            printf("\nThere is not a method \"%s\"\n",id.c_str());
            exit(0);
    }
    Method* m=mTable[id];
    
    if(exprs.size()!=m->params.size()){
        printf("Expected %d parameters.\n",m->params.size());
        exit(0);
    }
    
    ExprList::iterator it2=exprs.begin();
    ParamList::iterator it3=m->params.begin();
    while(it2!=exprs.end())
    {
        VValue v=(*it2)->evaluate();
        Param * p=*it3;
        if(v.type!=p->type){
            printf("Expected %s type.\n ",getTextForEnum(p->type).c_str());
            exit(0);
        }
        m->LTable[p->id]=v;
        it2++;
        it3++;
    }
    
    StatementList::iterator it=m->statementBlock.begin();
    while(it!=m->statementBlock.end())
    {
            Statement* s=*it;
            s->execute();
            it++;
    }			
    MethodName="";
}


VValue IdExpr::evaluate()
{
    if(sTable.find(id) ==sTable.end()){
        if(mTable.find(MethodName)!=mTable.end()){
            if(mTable[MethodName]->LTable.find(id)!=mTable[MethodName]->LTable.end()){
                return mTable[MethodName]->LTable[id];
            }
        }
        printf("Variable %s is not declared\n", id.c_str());
        exit(0);
    }
   
    return sTable[id];
}

VValue StrExpr::evaluate()
{
    VValue value;
    value.type=STRINGS;
    value.u.svalue=strdup(val.c_str());
    return value;
}

VValue NegativeExpr::evaluate()
{
    VValue v=expr->evaluate();
    if(v.type==INT)
    {
            v.u.ivalue=v.IntValue()*(-1);
            return v;
    }else{
            printf("Expected integer.");
            exit(0);
    }

}

VValue NotExpr::evaluate()
{
	VValue v=expr->evaluate();
	if(v.type==BOOLEAN)
	{
            v.u.bvalue=!v.BoolValue();
            return v;
	}else if(v.IntValue()!=0){
            v.u.bvalue=!true;
            return v;
	}else 
	{
            v.u.bvalue=!false;
            return v;
	}
}

VValue MethodExpr::evaluate()
{
    MethodName=this->id;
    if(mTable.find(id)==mTable.end())
    {
            printf("\nThere is not a method \"%s\"\n",id.c_str());
            exit(0);
    }
    Method* m=mTable[id];
    
    if(exprs.size()!=m->params.size()){
        printf("Expected %d parameters.\n",m->params.size());
        exit(0);
    }
    
    ExprList::iterator it2=exprs.begin();
    ParamList::iterator it3=m->params.begin();
    while(it2!=exprs.end())
    {
        VValue v=(*it2)->evaluate();
        Param * p=*it3;
        if(v.type!=p->type){
            printf("Expected %s type.\n",getTextForEnum(p->type).c_str());
            exit(0);
        }
        m->LTable[p->id]=v;
        it2++;
        it3++;
    }
    
    StatementList::iterator it=m->statementBlock.begin();
    while(it!=m->statementBlock.end())
    {
            Statement* s=*it;
            s->execute();
            it++;
    }			
    MethodName="";
    return returnValue;
}

VValue RotExpr::evaluate()
{
	VValue v=expr1->evaluate();			//esta malo
	
	return v;
}


