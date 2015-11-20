%{
#include <cstdio>
#include <string>
#include "tree.h"
using namespace std;
extern int line;

int yylex();

void yyerror(const char *str)
{
    printf("%s, Line:%d\n", str,line);
}

#define YYERROR_VERBOSE 1
MainMethod*    main_method;
MethodList *methods;
DeclList * declarationList;
%}

%union {
    char *id_t;
    char *string_t;
    int  num_t;
    char char_t;
    DeclList *decl_list;
    Declaration *decl;
    MethodList * mtd_list;
    Method *method_t;
    MainMethod *main_t;
    ParamList * prm_list;
    Param * param_t;
    VarType type_t;
    Expr *expr_t;
    ExprList *expr_list_t;
    IdList *idlist_t;
    StatementList *st_list_t;
    Statement *st_t;
}

%token<num_t> T_INT_CONSTANT 
%token<char_t> T_CHAR_CONSTANT 
%token<string_t> T_STRING_CONSTANT
%token<id_t> T_ID 
%token T_LEFT_BIT T_RIGHT_BIT T_LESS_EQUAL T_GREATER_EQUAL T_EQUAL T_NOT_EQUAL T_AND T_OR
%token T_BREAK T_PRINT T_READ T_CONTINUE T_CLASS T_EXTENDS T_NEW T_NULL T_RETURN T_ROT T_VOID T_MAIN
%token T_ELSE T_FOR T_IF T_WHILE
%token T_BOOL T_INT
%token T_FALSE T_TRUE
%type<idlist_t> id_listP
%type<decl_list> opt_declarations declaration_list
%type<decl> declaration
%type<mtd_list> opt_methods method_list
%type<method_t> method
%type<main_t> main_method
%type<prm_list> params param_list
%type<param_t> param
%type<type_t> type

%type<expr_t> constant bool_constant opt_expr expr argument expr_a expr_eq expr_re expr_bit expr_md expr_ar expr_fa expr_ne expr_neg term method_call_expr opt_arr

%type<expr_list_t> arguments_list opt_expr_list expr_list 
%type<st_list_t>  assign_list statement_list opt_else
%type<st_t> statement  assign method_call_statement 

%%

program: T_CLASS T_ID '{' opt_declarations opt_methods main_method opt_methods '}'{declarationList=$4; methods=$7; main_method=$6;}

						  //FALTA

;
opt_methods: method_list  {$$=$1;}
			|{$$=0; }
				
;

method_list: method_list  method  {$$=$1;  $$->push_back($2);}
	       | method  {$$=new MethodList(); $$->push_back($1);}

;
method:type T_ID '(' params ')' '{' opt_declarations statement_list '}'	{
																			if($1==INT){
																				$$=new Method(M_INT,$2,*$4,*$7,*$8);
																			}else
																			{	
																				$$=new Method(M_BOOLEAN,$2,*$4,*$7,*$8);
																			}												
																		}//FALTA

;

main_method:T_VOID T_MAIN '(' ')' '{' opt_declarations statement_list '}'{ $$=new MainMethod(*$6,*$7);}

;

params: param_list	 {$$=$1;}
	  | {$$=new ParamList();}

;

param_list: param_list  ',' param   {$$=$1; $$->push_back($3);}
	      | param {$$=new ParamList(); $$->push_back($1);}

;

param : type T_ID 	{
						string id=$2;
						free($2);
						$$=new Param($1,id);
					}

;


opt_declarations:declaration_list {$$=$1;}
				| {$$=new DeclList();}

;


declaration_list: declaration_list declaration   {$$=$1;  $$->push_back($2);}
                | declaration {$$=new DeclList();  $$->push_back($1);}

;

declaration:type id_listP ';'	{	
									$$=new Declaration($1,*$2,0);
								}
	       |type T_ID  '='  constant ';'{
	       									IdList *ids=new IdList();
	       									string id=$2;
	       									ids->push_back(id);
	       									$$=new Declaration($1,*ids,$4);
	       								}

;

id_listP: id_listP ',' T_ID { 
								$$=$1; 
								string id=$3;
								$$->push_back(id);
							}
          | T_ID	{
          				string id=$1;
          				$$=new IdList();
          				$$->push_back(id);
          			}

;
type: T_INT  {$$=INT;}
     |T_BOOL {$$=BOOLEAN;}

;

statement_list: statement_list statement	{ $$=$1; $$->push_back($2);}
        		| statement 				{ $$ = new StatementList(); $$->push_back($1); }

;

statement: assign ';'													{$$=$1;}
	   | method_call_statement ';'											{$$=$1;}
	   | T_IF '(' expr ')' '{'statement_list '}' opt_else								{$$=new IfStatement($3,*$6,*$8);}
	   | T_WHILE '(' expr ')' '{'statement_list '}'									    {$$=new WhileStatement($3,*$6);}
	   | T_FOR '(' assign_list  ';'  expr  ';'  assign_list  ')' '{'statement_list '}'	{$$=new ForStatement(*$3,$5,*$7,*$10);}
	   | T_RETURN opt_expr  ';'											{$$=new ReturnStatement($2);}
	   | T_BREAK ';'													{$$=new BreakStatement();}
	   | T_CONTINUE ';'													{$$=new ContinueStatement();}
	   | T_PRINT arguments_list ';'										{$$=new PrintStatement(*$2);}
	   | T_READ id_listP 	';'											{$$=new ReadStatement(*$2);}

;

opt_expr: expr	{$$=$1;}
		| 		{$$=0;}

;

opt_else: T_ELSE '{'statement_list '}'	{ $$ = $3; }
	 	| {$$=new StatementList();}

;

assign_list: assign_list ',' assign	{
										$$=$1;
										$$->push_back($3);
									}
		   | assign					{
		   								$$=new StatementList();
		   								$$->push_back($1);
		   							}
	
;

assign: T_ID opt_arr '=' expr {$$=new AssignStatement($1,$2,$4);}

;

opt_arr:'[' expr ']' { $$=$2;}
	   |{$$=0;}

;

method_call_expr:T_ID '(' opt_expr_list ')'	{$$=new MethodExpr($1,*$3);}

;

method_call_statement:T_ID '(' opt_expr_list ')'	{$$=new MethodStatement($1,*$3);}

;

arguments_list: arguments_list  ','  argument	{
													$$=$1; 
													$$->push_back($3);
												}
	           |argument						{
	           										$$=new ExprList(); 
	           										$$->push_back($1);
	           									}

;

argument: T_STRING_CONSTANT	{$$=new StrExpr($1);}
		| T_CHAR_CONSTANT	{$$=new CharExpr($1);}
	   	|  expr				{$$=$1; }

;

opt_expr_list: expr_list {$$=$1;}
	         | 	{$$=0;}

;

expr_list: expr_list  ','  expr	{
									$$=$1;
									$$->push_back($3);
								}
		 | expr 				{
		 							$$=new ExprList();
		 							$$->push_back($1);
		 						}

;

expr: expr T_OR expr		{$$=new OrExpr($1,$3);}
	| expr_a					{$$=$1;}

;

expr_a:expr_a T_AND expr_a 	{$$=new AndExpr($1,$3);}
	| expr_eq
		
;

expr_eq: expr_eq T_EQUAL expr_eq 		{$$=new EqualExpr($1,$3);}
	   | expr_eq T_NOT_EQUAL expr_eq 	{$$=new NotEqualExpr($1,$3);}
	   | expr_re						{$$=$1;}

;

expr_re: expr_re '<' expr_re 				{$$=new LessThanExpr($1,$3);}
	   | expr_re '>' expr_re 				{$$=new GreaterThanExpr($1,$3);}
	   | expr_re T_LESS_EQUAL expr_re 		{$$=new LessThanEqualExpr($1,$3);}
	   | expr_re T_GREATER_EQUAL expr_re	{$$=new GreaterThanEqualExpr($1,$3);}
	   | expr_bit 							{$$=$1;}

;

expr_bit: expr_bit T_LEFT_BIT expr_bit		{$$=new ShiftLeftExpr($1,$3);}
		| expr_bit T_RIGHT_BIT expr_bit		{$$=new ShiftRightExpr($1,$3);}
		| expr_bit T_ROT expr_bit			{$$=new RotExpr($1,$3);}
		| expr_md 							{$$=$1;}

;

expr_md: expr_md '%' expr_md	{$$=new ModExpr($1,$3);}
	   | expr_ar 				{$$=$1;}

;

expr_ar : expr_ar '+' expr_ar 	{$$=new AddExpr($1,$3);}
		| expr_ar '-' expr_ar 	{$$=new SubExpr($1,$3);}
		| expr_fa 				{$$=$1;}

;

expr_fa : expr_fa '*' expr_fa	{$$=new MultExpr($1,$3);}
		| expr_fa '/' expr_fa	{$$=new DivExpr($1,$3);}
		| expr_ne				{$$=$1;}
;

expr_ne	: '!' expr_ne 	{$$=new NotExpr($2);}
		| expr_neg		{$$=$1;}

;

expr_neg: '-' term		{$$=new NegativeExpr($2);}
		| term 			{$$=$1;}

;

term: constant			{$$=$1;}
	| T_ID 				{
							string id = $1;
                            free($1);
                            $$ = new IdExpr(id);
                        }
	| method_call_expr	{$$=$1;}
	| '(' expr ')'		{$$=$2;}
;

constant: T_INT_CONSTANT	{$$ = new IntExpr($1); }
		| bool_constant		{$$ = $1;}
		
;

bool_constant: T_TRUE	{$$ = new BoolExpr(true); }
	          |T_FALSE	{$$ = new BoolExpr(false); }
;

%%
