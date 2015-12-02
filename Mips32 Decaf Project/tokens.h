/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
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
     T_CONTINUE = 272,
     T_CLASS = 273,
     T_EXTENDS = 274,
     T_NEW = 275,
     T_NULL = 276,
     T_RETURN = 277,
     T_ROT = 278,
     T_VOID = 279,
     T_ELSE = 280,
     T_FOR = 281,
     T_IF = 282,
     T_WHILE = 283,
     T_BOOL = 284,
     T_INT = 285,
     T_FALSE = 286,
     T_TRUE = 287
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1685 of yacc.c  */
#line 20 "parser.y"

    char *id_t;
    char *string_t;
    int  num_t;
    char char_t;
    DeclList *decl_list;
    Declaration *decl;
    MethodList * mtd_list;
    Method *method_t;
    ParamList * prm_list;
    Param * param_t;
    VarType type_t;
    Expr *expr_t;
    ExprList *expr_list_t;
    IdList *idlist_t;
    StatementList *st_list_t;
    Statement *st_t;
    DeclItemList *item_l;



/* Line 1685 of yacc.c  */
#line 105 "tokens.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


