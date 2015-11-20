/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_TOKENS_H_INCLUDED
# define YY_YY_TOKENS_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_INT_CONSTANT = 258,
    T_CHAR_CONSTANT = 259,
    T_STRING_CONSTANT = 260,
    T_ID = 261,
    T_LEFT_BIT = 262,
    T_RIGHT_BIT = 263,
    T_LESS_EQUAL = 264,
    T_GREATER_EQUAL = 265,
    T_EQUAL = 266,
    T_NOT_EQUAL = 267,
    T_AND = 268,
    T_OR = 269,
    T_BREAK = 270,
    T_PRINT = 271,
    T_READ = 272,
    T_CONTINUE = 273,
    T_CLASS = 274,
    T_EXTENDS = 275,
    T_NEW = 276,
    T_NULL = 277,
    T_RETURN = 278,
    T_ROT = 279,
    T_VOID = 280,
    T_MAIN = 281,
    T_ELSE = 282,
    T_FOR = 283,
    T_IF = 284,
    T_WHILE = 285,
    T_BOOL = 286,
    T_INT = 287,
    T_FALSE = 288,
    T_TRUE = 289
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 21 "parser.y" /* yacc.c:1909  */

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

#line 109 "tokens.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TOKENS_H_INCLUDED  */
