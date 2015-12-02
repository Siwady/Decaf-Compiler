/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

#include <cstdio>
#include <string>
#include "ast.h"
using namespace std;
extern int line;

int yylex();

void yyerror(const char *str)
{
    printf("%s, Line:%d\n", str,line);
}

#define YYERROR_VERBOSE 1
Program *program;


/* Line 189 of yacc.c  */
#line 91 "parser.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 214 of yacc.c  */
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



/* Line 214 of yacc.c  */
#line 181 "parser.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 193 "parser.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   238

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNRULES -- Number of states.  */
#define YYNSTATES  188

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,     2,     2,    44,     2,     2,
      35,    36,    47,    45,    37,    46,     2,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
      42,    39,    43,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,    34,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    10,    12,    13,    16,    18,    28,    37,
      39,    40,    44,    46,    49,    51,    52,    55,    57,    61,
      67,    72,    75,    79,    80,    82,    84,    87,    89,    92,
      95,   104,   112,   124,   128,   131,   134,   138,   140,   141,
     146,   147,   151,   153,   158,   162,   163,   168,   173,   177,
     179,   181,   183,   185,   187,   188,   192,   194,   198,   200,
     204,   206,   210,   214,   216,   220,   224,   228,   232,   234,
     238,   242,   246,   248,   252,   254,   258,   262,   264,   268,
     272,   274,   277,   279,   282,   284,   286,   288,   292,   294,
     296,   301,   303,   305,   307
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      51,     0,    -1,    18,     6,    33,    58,    52,    34,    -1,
      53,    -1,    -1,    53,    54,    -1,    54,    -1,    63,     6,
      35,    55,    36,    33,    58,    64,    34,    -1,    24,     6,
      35,    36,    33,    58,    64,    34,    -1,    56,    -1,    -1,
      56,    37,    57,    -1,    57,    -1,    63,     6,    -1,    59,
      -1,    -1,    59,    60,    -1,    60,    -1,    63,    61,    38,
      -1,    63,     6,    39,    89,    38,    -1,    61,    37,     6,
      62,    -1,     6,    62,    -1,    40,     3,    41,    -1,    -1,
      30,    -1,    29,    -1,    64,    65,    -1,    65,    -1,    69,
      38,    -1,    72,    38,    -1,    27,    35,    77,    36,    33,
      64,    34,    67,    -1,    28,    35,    77,    36,    33,    64,
      34,    -1,    26,    35,    68,    38,    77,    38,    68,    36,
      33,    64,    34,    -1,    22,    66,    38,    -1,    15,    38,
      -1,    17,    38,    -1,    16,    73,    38,    -1,    77,    -1,
      -1,    25,    33,    64,    34,    -1,    -1,    68,    37,    69,
      -1,    69,    -1,     6,    70,    39,    77,    -1,    40,    77,
      41,    -1,    -1,     6,    35,    75,    36,    -1,     6,    35,
      75,    36,    -1,    73,    37,    74,    -1,    74,    -1,     5,
      -1,     4,    -1,    77,    -1,    76,    -1,    -1,    76,    37,
      77,    -1,    77,    -1,    77,    14,    78,    -1,    78,    -1,
      78,    13,    79,    -1,    79,    -1,    79,    11,    80,    -1,
      79,    12,    80,    -1,    80,    -1,    80,    42,    81,    -1,
      80,    43,    81,    -1,    80,     9,    81,    -1,    80,    10,
      81,    -1,    81,    -1,    81,     7,    82,    -1,    81,     8,
      82,    -1,    81,    23,    82,    -1,    82,    -1,    82,    44,
      83,    -1,    83,    -1,    83,    45,    84,    -1,    83,    46,
      84,    -1,    84,    -1,    84,    47,    85,    -1,    84,    48,
      85,    -1,    85,    -1,    49,    86,    -1,    86,    -1,    46,
      87,    -1,    87,    -1,    89,    -1,    71,    -1,    35,    77,
      36,    -1,    88,    -1,     6,    -1,     6,    40,    77,    41,
      -1,     3,    -1,    90,    -1,    32,    -1,    31,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    66,    66,    71,    72,    76,    77,    80,    88,    92,
      93,    97,    98,   102,   111,   112,   117,   118,   122,   125,
     135,   147,   162,   163,   167,   168,   172,   173,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   188,   189,   193,
     194,   198,   202,   209,   213,   214,   218,   222,   226,   230,
     237,   238,   239,   243,   244,   248,   252,   259,   260,   264,
     265,   269,   270,   271,   275,   276,   277,   278,   279,   283,
     284,   285,   286,   290,   291,   295,   296,   297,   301,   302,
     303,   306,   307,   311,   312,   316,   317,   318,   319,   322,
     327,   334,   335,   339,   340
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_INT_CONSTANT", "T_CHAR_CONSTANT",
  "T_STRING_CONSTANT", "T_ID", "T_LEFT_BIT", "T_RIGHT_BIT", "T_LESS_EQUAL",
  "T_GREATER_EQUAL", "T_EQUAL", "T_NOT_EQUAL", "T_AND", "T_OR", "T_BREAK",
  "T_PRINT", "T_CONTINUE", "T_CLASS", "T_EXTENDS", "T_NEW", "T_NULL",
  "T_RETURN", "T_ROT", "T_VOID", "T_ELSE", "T_FOR", "T_IF", "T_WHILE",
  "T_BOOL", "T_INT", "T_FALSE", "T_TRUE", "'{'", "'}'", "'('", "')'",
  "','", "';'", "'='", "'['", "']'", "'<'", "'>'", "'%'", "'+'", "'-'",
  "'*'", "'/'", "'!'", "$accept", "program", "opt_methods", "method_list",
  "method", "params", "param_list", "param", "opt_declarations",
  "declaration_list", "declaration", "id_listP", "arr_size", "type",
  "statement_list", "statement", "opt_expr", "opt_else", "assign_list",
  "assign", "opt_arr", "method_call_expr", "method_call_statement",
  "arguments_list", "argument", "opt_expr_list", "expr_list", "expr",
  "expr_a", "expr_eq", "expr_re", "expr_bit", "expr_md", "expr_ar",
  "expr_fa", "expr_ne", "expr_neg", "term", "variable", "constant",
  "bool_constant", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   123,   125,    40,    41,    44,    59,    61,
      91,    93,    60,    62,    37,    43,    45,    42,    47,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    53,    54,    54,    55,
      55,    56,    56,    57,    58,    58,    59,    59,    60,    60,
      61,    61,    62,    62,    63,    63,    64,    64,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    66,    66,    67,
      67,    68,    68,    69,    70,    70,    71,    72,    73,    73,
      74,    74,    74,    75,    75,    76,    76,    77,    77,    78,
      78,    79,    79,    79,    80,    80,    80,    80,    80,    81,
      81,    81,    81,    82,    82,    83,    83,    83,    84,    84,
      84,    85,    85,    86,    86,    87,    87,    87,    87,    88,
      88,    89,    89,    90,    90
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     1,     0,     2,     1,     9,     8,     1,
       0,     3,     1,     2,     1,     0,     2,     1,     3,     5,
       4,     2,     3,     0,     1,     1,     2,     1,     2,     2,
       8,     7,    11,     3,     2,     2,     3,     1,     0,     4,
       0,     3,     1,     4,     3,     0,     4,     4,     3,     1,
       1,     1,     1,     1,     0,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     3,     1,     3,     1,     3,     3,     1,     3,     3,
       1,     2,     1,     2,     1,     1,     1,     3,     1,     1,
       4,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,    15,    25,    24,     4,    14,
      17,     0,     0,     0,     3,     6,     0,    16,    23,     0,
       0,     2,     5,     0,     0,     0,    21,     0,    18,     0,
      10,    91,    94,    93,     0,    92,     0,    23,     0,     0,
       9,    12,     0,    19,    22,    20,    15,     0,     0,    13,
       0,    15,    11,    45,     0,     0,     0,    38,     0,     0,
       0,     0,    27,     0,     0,     0,    54,     0,     0,    34,
      51,    50,    89,     0,     0,     0,    86,     0,    49,    52,
      58,    60,    63,    68,    72,    74,    77,    80,    82,    84,
      88,    85,    35,     0,    37,     0,     0,     0,     8,    26,
      28,    29,     0,     0,    53,    56,     0,     0,    54,     0,
       0,    83,    81,     0,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    45,     0,    42,     0,     0,     7,    47,     0,
      44,    43,     0,     0,    87,    48,    57,    59,    61,    62,
      66,    67,    64,    65,    69,    70,    71,    73,    75,    76,
      78,    79,     0,     0,     0,     0,    55,    46,    90,    41,
       0,     0,     0,     0,     0,     0,     0,    40,    31,     0,
       0,    30,     0,     0,     0,     0,    32,    39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    13,    14,    15,    39,    40,    41,     8,     9,
      10,    19,    26,    11,    61,    62,    93,   181,   133,    63,
      68,    76,    64,    77,    78,   103,   104,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      35
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -94
static const yytype_int16 yypact[] =
{
      -3,    12,    21,    -6,   -94,    74,   -94,   -94,    -1,    74,
     -94,    33,    56,    57,    -1,   -94,    59,   -94,    71,    95,
      -4,   -94,   -94,    70,     6,   109,   -94,   115,   -94,    89,
      74,   -94,   -94,   -94,    99,   -94,   102,   107,   117,   118,
     131,   -94,   166,   -94,   -94,   -94,    74,   146,    74,   -94,
     172,    74,   -94,    24,   138,     1,   145,    14,   162,   169,
     173,    66,   -94,   155,   163,   172,    14,    14,   168,   -94,
     -94,   -94,    31,    14,    67,    55,   -94,   101,   -94,   195,
     197,   141,    25,     3,   167,   116,   119,   -94,   -94,   -94,
     -94,   -94,   -94,   174,   195,   207,    14,    14,   -94,   -94,
     -94,   -94,   100,   178,   179,   195,    10,    14,    14,    14,
       8,   -94,   -94,     1,   -94,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,   -94,   175,   144,   -94,    42,    43,   -94,   -94,    14,
     -94,   195,   181,    11,   -94,   -94,   197,   141,    25,    25,
       3,     3,     3,     3,   167,   167,   167,   116,   119,   119,
     -94,   -94,   207,    14,   185,   186,   195,   -94,   -94,   -94,
       2,   172,   172,   207,   114,   129,   154,   196,   -94,   187,
     189,   -94,   172,   172,   143,   158,   -94,   -94
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -94,   -94,   -94,   -94,   209,   -94,   -94,   176,    38,   -94,
     216,   -94,   190,     0,   -64,   -61,   -94,   -94,    53,   -93,
     -94,   -94,   -94,   -94,   120,   121,   -94,   -54,   113,   122,
      78,   -45,   -28,   104,    75,    76,   156,   160,   -94,   208,
     -94
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      99,   102,   134,    94,    31,    70,    71,    72,    16,    31,
     123,   124,   105,   106,    16,     1,   115,    31,     3,   110,
      72,     4,   115,    12,   115,   115,   125,     5,     6,     7,
      42,    29,    32,    33,   119,   120,    73,    32,    33,    18,
     173,    99,   135,   136,   144,    32,    33,    74,    42,    73,
      75,   140,   168,   141,   105,   143,   115,   115,    31,    66,
      74,    72,    20,    75,    67,    23,   108,   121,   122,   169,
      31,   109,    53,    72,   150,   151,   152,   153,   164,   165,
     134,    54,    55,    56,    50,   166,    32,    33,    57,    65,
      73,    21,    58,    59,    60,   154,   155,   156,    32,    33,
      98,    74,    73,     6,     7,    30,    53,   174,   175,   170,
      24,    25,    36,    99,    99,    54,    55,    56,   184,   185,
      53,    37,    57,    99,    99,    38,    58,    59,    60,    54,
      55,    56,    27,    28,   137,    53,    57,    43,   113,   114,
      58,    59,    60,    44,    54,    55,    56,    25,   177,    53,
      46,    57,   117,   118,    47,    58,    59,    60,    54,    55,
      56,   127,   128,   178,    53,    57,   129,   130,    48,    58,
      59,    60,    49,    54,    55,    56,    69,   186,    53,    51,
      57,   162,   163,    92,    58,    59,    60,    54,    55,    56,
     179,   162,   187,   100,    57,   148,   149,    95,    58,    59,
      60,   101,   158,   159,    96,   160,   161,   107,    97,   115,
     116,   126,   131,   132,   138,    67,   139,   167,   171,   172,
     182,   180,   183,    22,    52,    17,   176,    45,   146,   142,
     157,   112,    34,   145,   111,     0,     0,     0,   147
};

static const yytype_int16 yycheck[] =
{
      61,    65,    95,    57,     3,     4,     5,     6,     8,     3,
       7,     8,    66,    67,    14,    18,    14,     3,     6,    73,
       6,     0,    14,    24,    14,    14,    23,    33,    29,    30,
      30,    35,    31,    32,     9,    10,    35,    31,    32,     6,
      38,   102,    96,    97,    36,    31,    32,    46,    48,    35,
      49,    41,    41,   107,   108,   109,    14,    14,     3,    35,
      46,     6,     6,    49,    40,     6,    35,    42,    43,   162,
       3,    40,     6,     6,   119,   120,   121,   122,    36,    36,
     173,    15,    16,    17,    46,   139,    31,    32,    22,    51,
      35,    34,    26,    27,    28,   123,   124,   125,    31,    32,
      34,    46,    35,    29,    30,    35,     6,   171,   172,   163,
      39,    40,     3,   174,   175,    15,    16,    17,   182,   183,
       6,     6,    22,   184,   185,    36,    26,    27,    28,    15,
      16,    17,    37,    38,    34,     6,    22,    38,    37,    38,
      26,    27,    28,    41,    15,    16,    17,    40,    34,     6,
      33,    22,    11,    12,    36,    26,    27,    28,    15,    16,
      17,    45,    46,    34,     6,    22,    47,    48,    37,    26,
      27,    28,     6,    15,    16,    17,    38,    34,     6,    33,
      22,    37,    38,    38,    26,    27,    28,    15,    16,    17,
      36,    37,    34,    38,    22,   117,   118,    35,    26,    27,
      28,    38,   127,   128,    35,   129,   130,    39,    35,    14,
      13,    44,    38,     6,    36,    40,    37,    36,    33,    33,
      33,    25,    33,    14,    48,     9,   173,    37,   115,   108,
     126,    75,    24,   113,    74,    -1,    -1,    -1,   116
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    51,     6,     0,    33,    29,    30,    58,    59,
      60,    63,    24,    52,    53,    54,    63,    60,     6,    61,
       6,    34,    54,     6,    39,    40,    62,    37,    38,    35,
      35,     3,    31,    32,    89,    90,     3,     6,    36,    55,
      56,    57,    63,    38,    41,    62,    33,    36,    37,     6,
      58,    33,    57,     6,    15,    16,    17,    22,    26,    27,
      28,    64,    65,    69,    72,    58,    35,    40,    70,    38,
       4,     5,     6,    35,    46,    49,    71,    73,    74,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    38,    66,    77,    35,    35,    35,    34,    65,
      38,    38,    64,    75,    76,    77,    77,    39,    35,    40,
      77,    87,    86,    37,    38,    14,    13,    11,    12,     9,
      10,    42,    43,     7,     8,    23,    44,    45,    46,    47,
      48,    38,     6,    68,    69,    77,    77,    34,    36,    37,
      41,    77,    75,    77,    36,    74,    78,    79,    80,    80,
      81,    81,    81,    81,    82,    82,    82,    83,    84,    84,
      85,    85,    37,    38,    36,    36,    77,    36,    41,    69,
      77,    33,    33,    38,    64,    64,    68,    34,    34,    36,
      25,    67,    33,    33,    64,    64,    34,    34
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1464 of yacc.c  */
#line 66 "parser.y"
    { program=new Program((yyvsp[(2) - (6)].id_t),(yyvsp[(4) - (6)].decl_list),(yyvsp[(5) - (6)].mtd_list));;}
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 71 "parser.y"
    {(yyval.mtd_list)=(yyvsp[(1) - (1)].mtd_list);;}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 72 "parser.y"
    {(yyval.mtd_list)=new MethodList(); ;}
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 76 "parser.y"
    {(yyval.mtd_list)=(yyvsp[(1) - (2)].mtd_list);  (yyval.mtd_list)->push_back((yyvsp[(2) - (2)].method_t));;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 77 "parser.y"
    {(yyval.mtd_list)=new MethodList(); (yyval.mtd_list)->push_back((yyvsp[(1) - (1)].method_t));;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 80 "parser.y"
    {
																			if((yyvsp[(1) - (9)].type_t)==INT){
																				(yyval.method_t)=new Method(M_INT,(yyvsp[(2) - (9)].id_t),*(yyvsp[(4) - (9)].prm_list),*(yyvsp[(7) - (9)].decl_list),*(yyvsp[(8) - (9)].st_list_t));
																			}else
																			{	
																				(yyval.method_t)=new Method(M_BOOLEAN,(yyvsp[(2) - (9)].id_t),*(yyvsp[(4) - (9)].prm_list),*(yyvsp[(7) - (9)].decl_list),*(yyvsp[(8) - (9)].st_list_t));
																			}												
																		;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 88 "parser.y"
    { (yyval.method_t)=new Method(M_VOID,(yyvsp[(2) - (8)].id_t),*(new ParamList()),*(yyvsp[(6) - (8)].decl_list),*(yyvsp[(7) - (8)].st_list_t));;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 92 "parser.y"
    {(yyval.prm_list)=(yyvsp[(1) - (1)].prm_list);;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 93 "parser.y"
    {(yyval.prm_list)=new ParamList();;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 97 "parser.y"
    {(yyval.prm_list)=(yyvsp[(1) - (3)].prm_list); (yyval.prm_list)->push_back((yyvsp[(3) - (3)].param_t));;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 98 "parser.y"
    {(yyval.prm_list)=new ParamList(); (yyval.prm_list)->push_back((yyvsp[(1) - (1)].param_t));;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 102 "parser.y"
    {
						string id=(yyvsp[(2) - (2)].id_t);
						free((yyvsp[(2) - (2)].id_t));
						(yyval.param_t)=new Param((yyvsp[(1) - (2)].type_t),id);
					;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 111 "parser.y"
    {(yyval.decl_list)=(yyvsp[(1) - (1)].decl_list);;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 112 "parser.y"
    {(yyval.decl_list)=new DeclList();;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 117 "parser.y"
    {(yyval.decl_list)=(yyvsp[(1) - (2)].decl_list);  (yyval.decl_list)->push_back((yyvsp[(2) - (2)].decl));;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 118 "parser.y"
    {(yyval.decl_list)=new DeclList();  (yyval.decl_list)->push_back((yyvsp[(1) - (1)].decl));;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 122 "parser.y"
    {	
									(yyval.decl)=new Declaration((yyvsp[(1) - (3)].type_t),*(yyvsp[(2) - (3)].item_l),0);
								;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 125 "parser.y"
    {
	       									DeclItemList *ids=new DeclItemList();
	       									string id=(yyvsp[(2) - (5)].id_t);
	       									DeclItem *item=new DeclItem(id);
	       									ids->push_back(item);
	       									(yyval.decl)=new Declaration((yyvsp[(1) - (5)].type_t),*ids,(yyvsp[(4) - (5)].expr_t));
	       								;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 135 "parser.y"
    { 
										(yyval.item_l)=(yyvsp[(1) - (4)].item_l); 
										string id=(yyvsp[(3) - (4)].id_t);
										DeclItem* item;
										if((yyvsp[(4) - (4)].num_t)!=0){
											item=new DeclItem(id,(yyvsp[(4) - (4)].num_t));
										}else{
											item=new DeclItem(id);
										}
										
										(yyval.item_l)->push_back(item);
									;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 147 "parser.y"
    {
						  				string id=(yyvsp[(1) - (2)].id_t);
						  				
						  				DeclItem* item;
										if((yyvsp[(2) - (2)].num_t)!=0){
											item=new DeclItem(id,(yyvsp[(2) - (2)].num_t));
										}else{
											item=new DeclItem(id);
										}
										
						  				(yyval.item_l)=new DeclItemList();
						  				(yyval.item_l)->push_back(item);
						  			;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 162 "parser.y"
    {(yyval.num_t)=(yyvsp[(2) - (3)].num_t);;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 163 "parser.y"
    {(yyval.num_t)=0;;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 167 "parser.y"
    {(yyval.type_t)=INT;;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 168 "parser.y"
    {(yyval.type_t)=BOOLEAN;;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 172 "parser.y"
    { (yyval.st_list_t)=(yyvsp[(1) - (2)].st_list_t); (yyval.st_list_t)->push_back((yyvsp[(2) - (2)].st_t));;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 173 "parser.y"
    { (yyval.st_list_t) = new StatementList(); (yyval.st_list_t)->push_back((yyvsp[(1) - (1)].st_t)); ;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 177 "parser.y"
    {(yyval.st_t)=(yyvsp[(1) - (2)].st_t);;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 178 "parser.y"
    {(yyval.st_t)=(yyvsp[(1) - (2)].st_t);;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 179 "parser.y"
    {(yyval.st_t)=new IfStatement((yyvsp[(3) - (8)].expr_t),*(yyvsp[(6) - (8)].st_list_t),*(yyvsp[(8) - (8)].st_list_t));;}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 180 "parser.y"
    {(yyval.st_t)=new WhileStatement((yyvsp[(3) - (7)].expr_t),*(yyvsp[(6) - (7)].st_list_t));;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 181 "parser.y"
    {(yyval.st_t)=new ForStatement(*(yyvsp[(3) - (11)].st_list_t),(yyvsp[(5) - (11)].expr_t),*(yyvsp[(7) - (11)].st_list_t),*(yyvsp[(10) - (11)].st_list_t));;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 182 "parser.y"
    {(yyval.st_t)=new ReturnStatement((yyvsp[(2) - (3)].expr_t));;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 183 "parser.y"
    {(yyval.st_t)=new BreakStatement();;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 184 "parser.y"
    {(yyval.st_t)=new ContinueStatement();;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 185 "parser.y"
    {(yyval.st_t)=new PrintStatement(*(yyvsp[(2) - (3)].expr_list_t));;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 188 "parser.y"
    {(yyval.expr_t)=(yyvsp[(1) - (1)].expr_t);;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 189 "parser.y"
    {(yyval.expr_t)=0;;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 193 "parser.y"
    { (yyval.st_list_t) = (yyvsp[(3) - (4)].st_list_t); ;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 194 "parser.y"
    {(yyval.st_list_t)=new StatementList();;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 198 "parser.y"
    {
										(yyval.st_list_t)=(yyvsp[(1) - (3)].st_list_t);
										(yyval.st_list_t)->push_back((yyvsp[(3) - (3)].st_t));
									;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 202 "parser.y"
    {
		   								(yyval.st_list_t)=new StatementList();
		   								(yyval.st_list_t)->push_back((yyvsp[(1) - (1)].st_t));
		   							;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 209 "parser.y"
    {(yyval.st_t)=new AssignStatement((yyvsp[(1) - (4)].id_t),(yyvsp[(2) - (4)].expr_t),(yyvsp[(4) - (4)].expr_t));;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 213 "parser.y"
    { (yyval.expr_t)=(yyvsp[(2) - (3)].expr_t);;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 214 "parser.y"
    {(yyval.expr_t)=0;;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 218 "parser.y"
    {(yyval.expr_t)=new MethodExpr((yyvsp[(1) - (4)].id_t),*(yyvsp[(3) - (4)].expr_list_t));;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 222 "parser.y"
    {(yyval.st_t)=new MethodStatement((yyvsp[(1) - (4)].id_t),*(yyvsp[(3) - (4)].expr_list_t));;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 226 "parser.y"
    {
													(yyval.expr_list_t)=(yyvsp[(1) - (3)].expr_list_t); 
													(yyval.expr_list_t)->push_back((yyvsp[(3) - (3)].expr_t));
												;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 230 "parser.y"
    {
	           										(yyval.expr_list_t)=new ExprList(); 
	           										(yyval.expr_list_t)->push_back((yyvsp[(1) - (1)].expr_t));
	           									;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 237 "parser.y"
    {(yyval.expr_t)=new StrExpr((yyvsp[(1) - (1)].string_t));;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 238 "parser.y"
    {(yyval.expr_t)=new CharExpr((yyvsp[(1) - (1)].char_t));;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 239 "parser.y"
    {(yyval.expr_t)=(yyvsp[(1) - (1)].expr_t); ;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 243 "parser.y"
    {(yyval.expr_list_t)=(yyvsp[(1) - (1)].expr_list_t);;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 244 "parser.y"
    {(yyval.expr_list_t)=new ExprList();;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 248 "parser.y"
    {
									(yyval.expr_list_t)=(yyvsp[(1) - (3)].expr_list_t);
									(yyval.expr_list_t)->push_back((yyvsp[(3) - (3)].expr_t));
								;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 252 "parser.y"
    {
		 							(yyval.expr_list_t)=new ExprList();
		 							(yyval.expr_list_t)->push_back((yyvsp[(1) - (1)].expr_t));
		 						;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 259 "parser.y"
    {(yyval.expr_t)=new OrExpr((yyvsp[(1) - (3)].expr_t),(yyvsp[(3) - (3)].expr_t));;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 260 "parser.y"
    {(yyval.expr_t)=(yyvsp[(1) - (1)].expr_t);;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 264 "parser.y"
    {(yyval.expr_t)=new AndExpr((yyvsp[(1) - (3)].expr_t),(yyvsp[(3) - (3)].expr_t));;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 269 "parser.y"
    {(yyval.expr_t)=new EqualExpr((yyvsp[(1) - (3)].expr_t),(yyvsp[(3) - (3)].expr_t));;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 270 "parser.y"
    {(yyval.expr_t)=new NotEqualExpr((yyvsp[(1) - (3)].expr_t),(yyvsp[(3) - (3)].expr_t));;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 271 "parser.y"
    {(yyval.expr_t)=(yyvsp[(1) - (1)].expr_t);;}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 275 "parser.y"
    {(yyval.expr_t)=new LessThanExpr((yyvsp[(1) - (3)].expr_t),(yyvsp[(3) - (3)].expr_t));;}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 276 "parser.y"
    {(yyval.expr_t)=new GreaterThanExpr((yyvsp[(1) - (3)].expr_t),(yyvsp[(3) - (3)].expr_t));;}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 277 "parser.y"
    {(yyval.expr_t)=new LessThanEqualExpr((yyvsp[(1) - (3)].expr_t),(yyvsp[(3) - (3)].expr_t));;}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 278 "parser.y"
    {(yyval.expr_t)=new GreaterThanEqualExpr((yyvsp[(1) - (3)].expr_t),(yyvsp[(3) - (3)].expr_t));;}
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 279 "parser.y"
    {(yyval.expr_t)=(yyvsp[(1) - (1)].expr_t);;}
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 283 "parser.y"
    {(yyval.expr_t)=new ShiftLeftExpr((yyvsp[(1) - (3)].expr_t),(yyvsp[(3) - (3)].expr_t));;}
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 284 "parser.y"
    {(yyval.expr_t)=new ShiftRightExpr((yyvsp[(1) - (3)].expr_t),(yyvsp[(3) - (3)].expr_t));;}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 285 "parser.y"
    {(yyval.expr_t)=new RotExpr((yyvsp[(1) - (3)].expr_t),(yyvsp[(3) - (3)].expr_t));;}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 286 "parser.y"
    {(yyval.expr_t)=(yyvsp[(1) - (1)].expr_t);;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 290 "parser.y"
    {(yyval.expr_t)=new ModExpr((yyvsp[(1) - (3)].expr_t),(yyvsp[(3) - (3)].expr_t));;}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 291 "parser.y"
    {(yyval.expr_t)=(yyvsp[(1) - (1)].expr_t);;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 295 "parser.y"
    {(yyval.expr_t)=new AddExpr((yyvsp[(1) - (3)].expr_t),(yyvsp[(3) - (3)].expr_t));;}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 296 "parser.y"
    {(yyval.expr_t)=new SubExpr((yyvsp[(1) - (3)].expr_t),(yyvsp[(3) - (3)].expr_t));;}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 297 "parser.y"
    {(yyval.expr_t)=(yyvsp[(1) - (1)].expr_t);;}
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 301 "parser.y"
    {(yyval.expr_t)=new MultExpr((yyvsp[(1) - (3)].expr_t),(yyvsp[(3) - (3)].expr_t));;}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 302 "parser.y"
    {(yyval.expr_t)=new DivExpr((yyvsp[(1) - (3)].expr_t),(yyvsp[(3) - (3)].expr_t));;}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 303 "parser.y"
    {(yyval.expr_t)=(yyvsp[(1) - (1)].expr_t);;}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 306 "parser.y"
    {(yyval.expr_t)=new NotExpr((yyvsp[(2) - (2)].expr_t));;}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 307 "parser.y"
    {(yyval.expr_t)=(yyvsp[(1) - (1)].expr_t);;}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 311 "parser.y"
    {(yyval.expr_t)=new NegativeExpr((yyvsp[(2) - (2)].expr_t));;}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 312 "parser.y"
    {(yyval.expr_t)=(yyvsp[(1) - (1)].expr_t);;}
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 316 "parser.y"
    {(yyval.expr_t)=(yyvsp[(1) - (1)].expr_t);;}
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 317 "parser.y"
    {(yyval.expr_t)=(yyvsp[(1) - (1)].expr_t);;}
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 318 "parser.y"
    {(yyval.expr_t)=(yyvsp[(2) - (3)].expr_t);;}
    break;

  case 88:

/* Line 1464 of yacc.c  */
#line 319 "parser.y"
    {(yyval.expr_t)=(yyvsp[(1) - (1)].expr_t);;}
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 322 "parser.y"
    { 
				string id = (yyvsp[(1) - (1)].id_t);
				free((yyvsp[(1) - (1)].id_t));
				(yyval.expr_t) = new IdExpr(id);
			 ;}
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 327 "parser.y"
    {
							string id = (yyvsp[(1) - (4)].id_t);
							free((yyvsp[(1) - (4)].id_t));
							(yyval.expr_t) = new ArrayExpr(id,(yyvsp[(3) - (4)].expr_t));
						  ;}
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 334 "parser.y"
    {(yyval.expr_t) = new IntExpr((yyvsp[(1) - (1)].num_t)); ;}
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 335 "parser.y"
    {(yyval.expr_t) = (yyvsp[(1) - (1)].expr_t);;}
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 339 "parser.y"
    {(yyval.expr_t) = new BoolExpr(true); ;}
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 340 "parser.y"
    {(yyval.expr_t) = new BoolExpr(false); ;}
    break;



/* Line 1464 of yacc.c  */
#line 2286 "parser.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1684 of yacc.c  */
#line 343 "parser.y"


