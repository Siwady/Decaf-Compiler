%option noyywrap

%{
#include <cstdlib>
#include <cstring>
#include "tree.h"
#include "tokens.h"
#include <string>

int line=1;
%}

ID                  [A-Za-z_][A-Za-z_0-9]*
NUMBER              [0-9][0-9]*
STRING              \"(\\.|[^\\"])*\"
CHARACTER           "'"[^\\]"'"
HEXADECIMAL         ([0-9A-Fa-f])+
ESPECIAL_N          "'"(\\n)"'"
ESPECIAL_A          "'"(\\a)"'"
ESPECIAL_R          "'"(\\r)"'"
ESPECIAL_T          "'"(\\t)"'"
ESPECIAL_P          "'"(\\\\)"'"

%x str
%x hex

%%

"{" 				{ return '{'; }
"}" 				{ return '}'; }
"[" 				{ return '['; }
"]" 				{ return ']'; }
"," 				{ return ','; }
";" 				{ return ';'; }
"(" 				{ return '('; }
")" 				{ return ')'; }
"=" 				{ return '='; }
"-" 				{ return '-'; }
"!" 				{ return '!'; }
"+" 				{ return '+'; }
"*" 				{ return '*'; }
"/" 				{ return '/'; }
"<" 				{ return '<'; }
">" 				{ return '>'; }
"%" 				{ return '%'; }
"." 				{ return '.'; }

"<<" 				{ return T_LEFT_BIT; } 
">>" 				{ return T_RIGHT_BIT; }
"<=" 				{ return T_LESS_EQUAL; }
">=" 				{ return T_GREATER_EQUAL; }
"==" 				{ return T_EQUAL; }
"!=" 				{ return T_NOT_EQUAL; }
"&&" 				{ return T_AND; }
"||" 				{ return T_OR; }
"0x"				{ BEGIN(hex);}
[ \t] 				{}
\n  				{line++;}
"bool" 				{ return T_BOOL; }
"break" 			{ return T_BREAK; }
"print" 			{ return T_PRINT; }
"continue" 			{ return T_CONTINUE; }
"class" 			{ return T_CLASS; }
"else" 				{ return T_ELSE; }
"extends" 			{ return T_EXTENDS; }
"false" 			{ return T_FALSE; }
"for" 				{ return T_FOR; }
"if" 				{ return T_IF; }
"int"	 			{ return T_INT; }
"new"	 			{ return T_NEW; }
"null"	 			{ return T_NULL; }
"return" 			{ return T_RETURN; }
"rot"	 			{ return T_ROT; }
"true"	 			{ return T_TRUE; }
"void"	 			{ return T_VOID; }
"while" 			{ return T_WHILE; }
\" 					{ BEGIN(str);}

{NUMBER}			{ yylval.num_t = atoi(yytext); return T_INT_CONSTANT; }

<hex>{HEXADECIMAL}	{yylval.num_t=strtoul(strdup(yytext),0, 16); BEGIN(INITIAL); return T_INT_CONSTANT; }
{ID} 				{ yylval.id_t = strdup(yytext); return T_ID; }
{CHARACTER} 		{ yylval.char_t = yytext[1]; return T_CHAR_CONSTANT; }
<str>[^\"]* 		{ yylval.string_t = strdup(yytext); return T_STRING_CONSTANT;}
<str>\" 			{ BEGIN(INITIAL);}
{ESPECIAL_N} 		{ yylval.char_t = '\n'; return T_CHAR_CONSTANT; }
{ESPECIAL_R} 		{ yylval.char_t = '\r'; return T_CHAR_CONSTANT; }
{ESPECIAL_T} 		{ yylval.char_t = '\t'; return T_CHAR_CONSTANT; }
{ESPECIAL_A} 		{ yylval.char_t = '\a'; return T_CHAR_CONSTANT; }
{ESPECIAL_P} 		{ yylval.char_t = '\\'; return T_CHAR_CONSTANT; }
"//"[^\n]*			{}
.   				{ printf("Simbolo no valido\n"); }

%%
