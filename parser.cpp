/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

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
Program *program;

#line 84 "parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "tokens.h".  */
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
    T_ELSE = 281,
    T_FOR = 282,
    T_IF = 283,
    T_WHILE = 284,
    T_BOOL = 285,
    T_INT = 286,
    T_FALSE = 287,
    T_TRUE = 288
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 19 "parser.y" /* yacc.c:355  */

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

#line 178 "parser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TOKENS_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 193 "parser.cpp" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   246

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  192

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,     2,     2,    45,     2,     2,
      36,    37,    48,    46,    38,    47,     2,    49,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
      43,    40,    44,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    41,     2,    42,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,    35,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    65,    65,    70,    71,    75,    76,    79,    87,    91,
      92,    96,    97,   101,   110,   111,   116,   117,   121,   124,
     134,   146,   161,   162,   166,   167,   171,   172,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   188,   189,
     193,   194,   198,   202,   209,   213,   214,   218,   222,   226,
     230,   237,   238,   239,   243,   244,   248,   252,   259,   260,
     264,   265,   269,   270,   271,   275,   276,   277,   278,   279,
     283,   284,   285,   286,   290,   291,   295,   296,   297,   301,
     302,   303,   306,   307,   311,   312,   316,   317,   318,   319,
     322,   327,   334,   335,   339,   340
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_INT_CONSTANT", "T_CHAR_CONSTANT",
  "T_STRING_CONSTANT", "T_ID", "T_LEFT_BIT", "T_RIGHT_BIT", "T_LESS_EQUAL",
  "T_GREATER_EQUAL", "T_EQUAL", "T_NOT_EQUAL", "T_AND", "T_OR", "T_BREAK",
  "T_PRINT", "T_READ", "T_CONTINUE", "T_CLASS", "T_EXTENDS", "T_NEW",
  "T_NULL", "T_RETURN", "T_ROT", "T_VOID", "T_ELSE", "T_FOR", "T_IF",
  "T_WHILE", "T_BOOL", "T_INT", "T_FALSE", "T_TRUE", "'{'", "'}'", "'('",
  "')'", "','", "';'", "'='", "'['", "']'", "'<'", "'>'", "'%'", "'+'",
  "'-'", "'*'", "'/'", "'!'", "$accept", "program", "opt_methods",
  "method_list", "method", "params", "param_list", "param",
  "opt_declarations", "declaration_list", "declaration", "id_listP",
  "arr_size", "type", "statement_list", "statement", "opt_expr",
  "opt_else", "assign_list", "assign", "opt_arr", "method_call_expr",
  "method_call_statement", "arguments_list", "argument", "opt_expr_list",
  "expr_list", "expr", "expr_a", "expr_eq", "expr_re", "expr_bit",
  "expr_md", "expr_ar", "expr_fa", "expr_ne", "expr_neg", "term",
  "variable", "constant", "bool_constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   123,   125,    40,    41,    44,    59,
      61,    91,    93,    60,    62,    37,    43,    45,    42,    47,
      33
};
# endif

#define YYPACT_NINF -101

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-101)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -10,     5,    15,   -16,  -101,    76,  -101,  -101,    -9,    76,
    -101,    29,    61,    36,    -9,  -101,    78,  -101,    83,    94,
      51,  -101,  -101,    60,    20,   105,  -101,   112,  -101,    88,
      76,  -101,  -101,  -101,    96,  -101,    97,    79,   116,   110,
     124,  -101,   148,  -101,  -101,  -101,    76,   131,    76,  -101,
      86,    76,  -101,   -11,   130,     1,   171,   145,    14,   144,
     163,   177,    62,  -101,   153,   168,    86,    14,    14,   176,
    -101,  -101,  -101,    57,    14,    33,    26,  -101,    99,  -101,
     205,   207,   141,    31,    75,   178,   121,   134,  -101,  -101,
    -101,  -101,  -101,    79,   156,  -101,   182,   205,   216,    14,
      14,  -101,  -101,  -101,  -101,   113,   187,   188,   205,    -4,
      14,    14,    14,    -6,  -101,  -101,     1,  -101,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,  -101,  -101,   184,   159,  -101,    49,
      58,  -101,  -101,    14,  -101,   205,   190,     0,  -101,  -101,
     207,   141,    31,    31,    75,    75,    75,    75,   178,   178,
     178,   121,   134,   134,  -101,  -101,   216,    14,   194,   195,
     205,  -101,  -101,  -101,    10,    86,    86,   216,   128,   143,
     172,   204,  -101,   197,   198,  -101,    86,    86,   158,   173,
    -101,  -101
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,    15,    25,    24,     4,    14,
      17,     0,     0,     0,     3,     6,     0,    16,    23,     0,
       0,     2,     5,     0,     0,     0,    21,     0,    18,     0,
      10,    92,    95,    94,     0,    93,     0,    23,     0,     0,
       9,    12,     0,    19,    22,    20,    15,     0,     0,    13,
       0,    15,    11,    46,     0,     0,     0,     0,    39,     0,
       0,     0,     0,    27,     0,     0,     0,    55,     0,     0,
      34,    52,    51,    90,     0,     0,     0,    87,     0,    50,
      53,    59,    61,    64,    69,    73,    75,    78,    81,    83,
      85,    89,    86,    23,     0,    35,     0,    38,     0,     0,
       0,     8,    26,    28,    29,     0,     0,    54,    57,     0,
       0,    55,     0,     0,    84,    82,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,    33,    46,     0,    43,     0,
       0,     7,    48,     0,    45,    44,     0,     0,    88,    49,
      58,    60,    62,    63,    67,    68,    65,    66,    70,    71,
      72,    74,    76,    77,    79,    80,     0,     0,     0,     0,
      56,    47,    91,    42,     0,     0,     0,     0,     0,     0,
       0,    41,    31,     0,     0,    30,     0,     0,     0,     0,
      32,    40
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -101,  -101,  -101,  -101,   219,  -101,  -101,   186,    54,  -101,
     226,   180,   200,    46,   -65,   -62,  -101,  -101,    63,   -96,
    -101,  -101,  -101,  -101,   122,   132,  -101,   -55,   123,   120,
      91,    81,  -100,   115,    84,    85,   166,   170,  -101,   222,
    -101
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    13,    14,    15,    39,    40,    41,     8,     9,
      10,    19,    26,    11,    62,    63,    96,   185,   137,    64,
      69,    77,    65,    78,    79,   106,   107,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      35
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     102,   105,   138,    97,    31,    71,    72,    73,   118,     1,
     118,     3,   108,   109,   118,     4,    12,    31,     5,   113,
      73,     6,     7,    31,   118,    67,   158,   159,   160,    31,
      68,   148,    73,    32,    33,    18,    31,    74,   144,    73,
     122,   123,   172,   102,   139,   140,    32,    33,    75,   177,
      74,    76,    32,    33,    16,   145,   108,   147,    32,    33,
      16,    75,    74,   118,    76,    32,    33,    20,    53,    74,
     173,    21,   118,    75,   124,   125,    42,    54,    55,    56,
      57,   138,   126,   127,    23,    58,   168,    29,   170,    59,
      60,    61,    53,   111,    42,   169,    30,   101,   112,   128,
      50,    54,    55,    56,    57,    66,     6,     7,    36,    58,
     178,   179,   174,    59,    60,    61,   102,   102,    37,    53,
      25,   188,   189,    24,    25,    38,   102,   102,    54,    55,
      56,    57,    27,    28,    53,    43,    58,   116,   117,    44,
      59,    60,    61,    54,    55,    56,    57,    47,   141,    53,
      46,    58,   120,   121,    49,    59,    60,    61,    54,    55,
      56,    57,    48,   181,    53,    51,    58,   130,   131,    70,
      59,    60,    61,    54,    55,    56,    57,    93,   182,    53,
      98,    58,   132,   133,    95,    59,    60,    61,    54,    55,
      56,    57,   103,   190,    27,   134,    58,   166,   167,    99,
      59,    60,    61,   154,   155,   156,   157,   104,   191,   183,
     166,   152,   153,   100,   162,   163,   110,   164,   165,   118,
     119,   135,   136,   129,   142,    68,   143,   171,   175,   176,
     184,   186,   187,    22,    52,    17,    94,    45,   149,   151,
     180,   150,   115,   146,   161,   114,    34
};

static const yytype_uint8 yycheck[] =
{
      62,    66,    98,    58,     3,     4,     5,     6,    14,    19,
      14,     6,    67,    68,    14,     0,    25,     3,    34,    74,
       6,    30,    31,     3,    14,    36,   126,   127,   128,     3,
      41,    37,     6,    32,    33,     6,     3,    36,    42,     6,
       9,    10,    42,   105,    99,   100,    32,    33,    47,    39,
      36,    50,    32,    33,     8,   110,   111,   112,    32,    33,
      14,    47,    36,    14,    50,    32,    33,     6,     6,    36,
     166,    35,    14,    47,    43,    44,    30,    15,    16,    17,
      18,   177,     7,     8,     6,    23,    37,    36,   143,    27,
      28,    29,     6,    36,    48,    37,    36,    35,    41,    24,
      46,    15,    16,    17,    18,    51,    30,    31,     3,    23,
     175,   176,   167,    27,    28,    29,   178,   179,     6,     6,
      41,   186,   187,    40,    41,    37,   188,   189,    15,    16,
      17,    18,    38,    39,     6,    39,    23,    38,    39,    42,
      27,    28,    29,    15,    16,    17,    18,    37,    35,     6,
      34,    23,    11,    12,     6,    27,    28,    29,    15,    16,
      17,    18,    38,    35,     6,    34,    23,    46,    47,    39,
      27,    28,    29,    15,    16,    17,    18,     6,    35,     6,
      36,    23,    48,    49,    39,    27,    28,    29,    15,    16,
      17,    18,    39,    35,    38,    39,    23,    38,    39,    36,
      27,    28,    29,   122,   123,   124,   125,    39,    35,    37,
      38,   120,   121,    36,   130,   131,    40,   132,   133,    14,
      13,    39,     6,    45,    37,    41,    38,    37,    34,    34,
      26,    34,    34,    14,    48,     9,    56,    37,   116,   119,
     177,   118,    76,   111,   129,    75,    24
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    19,    52,     6,     0,    34,    30,    31,    59,    60,
      61,    64,    25,    53,    54,    55,    64,    61,     6,    62,
       6,    35,    55,     6,    40,    41,    63,    38,    39,    36,
      36,     3,    32,    33,    90,    91,     3,     6,    37,    56,
      57,    58,    64,    39,    42,    63,    34,    37,    38,     6,
      59,    34,    58,     6,    15,    16,    17,    18,    23,    27,
      28,    29,    65,    66,    70,    73,    59,    36,    41,    71,
      39,     4,     5,     6,    36,    47,    50,    72,    74,    75,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,     6,    62,    39,    67,    78,    36,    36,
      36,    35,    66,    39,    39,    65,    76,    77,    78,    78,
      40,    36,    41,    78,    88,    87,    38,    39,    14,    13,
      11,    12,     9,    10,    43,    44,     7,     8,    24,    45,
      46,    47,    48,    49,    39,    39,     6,    69,    70,    78,
      78,    35,    37,    38,    42,    78,    76,    78,    37,    75,
      79,    80,    81,    81,    82,    82,    82,    82,    83,    83,
      83,    84,    85,    85,    86,    86,    38,    39,    37,    37,
      78,    37,    42,    70,    78,    34,    34,    39,    65,    65,
      69,    35,    35,    37,    26,    68,    34,    34,    65,    65,
      35,    35
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    55,    55,    56,
      56,    57,    57,    58,    59,    59,    60,    60,    61,    61,
      62,    62,    63,    63,    64,    64,    65,    65,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    67,    67,
      68,    68,    69,    69,    70,    71,    71,    72,    73,    74,
      74,    75,    75,    75,    76,    76,    77,    77,    78,    78,
      79,    79,    80,    80,    80,    81,    81,    81,    81,    81,
      82,    82,    82,    82,    83,    83,    84,    84,    84,    85,
      85,    85,    86,    86,    87,    87,    88,    88,    88,    88,
      89,    89,    90,    90,    91,    91
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     1,     0,     2,     1,     9,     8,     1,
       0,     3,     1,     2,     1,     0,     2,     1,     3,     5,
       4,     2,     3,     0,     1,     1,     2,     1,     2,     2,
       8,     7,    11,     3,     2,     2,     3,     3,     1,     0,
       4,     0,     3,     1,     4,     3,     0,     4,     4,     3,
       1,     1,     1,     1,     1,     0,     3,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     1,     2,     1,     2,     1,     1,     1,     3,     1,
       1,     4,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 65 "parser.y" /* yacc.c:1646  */
    { program=new Program((yyvsp[-2].decl_list),(yyvsp[-1].mtd_list));}
#line 1420 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 70 "parser.y" /* yacc.c:1646  */
    {(yyval.mtd_list)=(yyvsp[0].mtd_list);}
#line 1426 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 71 "parser.y" /* yacc.c:1646  */
    {(yyval.mtd_list)=new MethodList(); }
#line 1432 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 75 "parser.y" /* yacc.c:1646  */
    {(yyval.mtd_list)=(yyvsp[-1].mtd_list);  (yyval.mtd_list)->push_back((yyvsp[0].method_t));}
#line 1438 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 76 "parser.y" /* yacc.c:1646  */
    {(yyval.mtd_list)=new MethodList(); (yyval.mtd_list)->push_back((yyvsp[0].method_t));}
#line 1444 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 79 "parser.y" /* yacc.c:1646  */
    {
																			if((yyvsp[-8].type_t)==INT){
																				(yyval.method_t)=new Method(M_INT,(yyvsp[-7].id_t),*(yyvsp[-5].prm_list),*(yyvsp[-2].decl_list),*(yyvsp[-1].st_list_t));
																			}else
																			{	
																				(yyval.method_t)=new Method(M_BOOLEAN,(yyvsp[-7].id_t),*(yyvsp[-5].prm_list),*(yyvsp[-2].decl_list),*(yyvsp[-1].st_list_t));
																			}												
																		}
#line 1457 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 87 "parser.y" /* yacc.c:1646  */
    { (yyval.method_t)=new Method(M_VOID,(yyvsp[-6].id_t),*(new ParamList()),*(yyvsp[-2].decl_list),*(yyvsp[-1].st_list_t));}
#line 1463 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 91 "parser.y" /* yacc.c:1646  */
    {(yyval.prm_list)=(yyvsp[0].prm_list);}
#line 1469 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 92 "parser.y" /* yacc.c:1646  */
    {(yyval.prm_list)=new ParamList();}
#line 1475 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 96 "parser.y" /* yacc.c:1646  */
    {(yyval.prm_list)=(yyvsp[-2].prm_list); (yyval.prm_list)->push_back((yyvsp[0].param_t));}
#line 1481 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 97 "parser.y" /* yacc.c:1646  */
    {(yyval.prm_list)=new ParamList(); (yyval.prm_list)->push_back((yyvsp[0].param_t));}
#line 1487 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 101 "parser.y" /* yacc.c:1646  */
    {
						string id=(yyvsp[0].id_t);
						free((yyvsp[0].id_t));
						(yyval.param_t)=new Param((yyvsp[-1].type_t),id);
					}
#line 1497 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 110 "parser.y" /* yacc.c:1646  */
    {(yyval.decl_list)=(yyvsp[0].decl_list);}
#line 1503 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 111 "parser.y" /* yacc.c:1646  */
    {(yyval.decl_list)=new DeclList();}
#line 1509 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 116 "parser.y" /* yacc.c:1646  */
    {(yyval.decl_list)=(yyvsp[-1].decl_list);  (yyval.decl_list)->push_back((yyvsp[0].decl));}
#line 1515 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 117 "parser.y" /* yacc.c:1646  */
    {(yyval.decl_list)=new DeclList();  (yyval.decl_list)->push_back((yyvsp[0].decl));}
#line 1521 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 121 "parser.y" /* yacc.c:1646  */
    {	
									(yyval.decl)=new Declaration((yyvsp[-2].type_t),*(yyvsp[-1].item_l),0);
								}
#line 1529 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 124 "parser.y" /* yacc.c:1646  */
    {
	       									DeclItemList *ids=new DeclItemList();
	       									string id=(yyvsp[-3].id_t);
	       									DeclItem *item=new DeclItem(id);
	       									ids->push_back(item);
	       									(yyval.decl)=new Declaration((yyvsp[-4].type_t),*ids,(yyvsp[-1].expr_t));
	       								}
#line 1541 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 134 "parser.y" /* yacc.c:1646  */
    { 
										(yyval.item_l)=(yyvsp[-3].item_l); 
										string id=(yyvsp[-1].id_t);
										DeclItem* item;
										if((yyvsp[0].num_t)!=0){
											item=new DeclItem(id,(yyvsp[0].num_t));
										}else{
											item=new DeclItem(id);
										}
										
										(yyval.item_l)->push_back(item);
									}
#line 1558 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 146 "parser.y" /* yacc.c:1646  */
    {
						  				string id=(yyvsp[-1].id_t);
						  				
						  				DeclItem* item;
										if((yyvsp[0].num_t)!=0){
											item=new DeclItem(id,(yyvsp[0].num_t));
										}else{
											item=new DeclItem(id);
										}
										
						  				(yyval.item_l)=new DeclItemList();
						  				(yyval.item_l)->push_back(item);
						  			}
#line 1576 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 161 "parser.y" /* yacc.c:1646  */
    {(yyval.num_t)=(yyvsp[-1].num_t);}
#line 1582 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 162 "parser.y" /* yacc.c:1646  */
    {(yyval.num_t)=0;}
#line 1588 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 166 "parser.y" /* yacc.c:1646  */
    {(yyval.type_t)=INT;}
#line 1594 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 167 "parser.y" /* yacc.c:1646  */
    {(yyval.type_t)=BOOLEAN;}
#line 1600 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 171 "parser.y" /* yacc.c:1646  */
    { (yyval.st_list_t)=(yyvsp[-1].st_list_t); (yyval.st_list_t)->push_back((yyvsp[0].st_t));}
#line 1606 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 172 "parser.y" /* yacc.c:1646  */
    { (yyval.st_list_t) = new StatementList(); (yyval.st_list_t)->push_back((yyvsp[0].st_t)); }
#line 1612 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 176 "parser.y" /* yacc.c:1646  */
    {(yyval.st_t)=(yyvsp[-1].st_t);}
#line 1618 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 177 "parser.y" /* yacc.c:1646  */
    {(yyval.st_t)=(yyvsp[-1].st_t);}
#line 1624 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 178 "parser.y" /* yacc.c:1646  */
    {(yyval.st_t)=new IfStatement((yyvsp[-5].expr_t),*(yyvsp[-2].st_list_t),*(yyvsp[0].st_list_t));}
#line 1630 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 179 "parser.y" /* yacc.c:1646  */
    {(yyval.st_t)=new WhileStatement((yyvsp[-4].expr_t),*(yyvsp[-1].st_list_t));}
#line 1636 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 180 "parser.y" /* yacc.c:1646  */
    {(yyval.st_t)=new ForStatement(*(yyvsp[-8].st_list_t),(yyvsp[-6].expr_t),*(yyvsp[-4].st_list_t),*(yyvsp[-1].st_list_t));}
#line 1642 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 181 "parser.y" /* yacc.c:1646  */
    {(yyval.st_t)=new ReturnStatement((yyvsp[-1].expr_t));}
#line 1648 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 182 "parser.y" /* yacc.c:1646  */
    {(yyval.st_t)=new BreakStatement();}
#line 1654 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 183 "parser.y" /* yacc.c:1646  */
    {(yyval.st_t)=new ContinueStatement();}
#line 1660 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 184 "parser.y" /* yacc.c:1646  */
    {(yyval.st_t)=new PrintStatement(*(yyvsp[-1].expr_list_t));}
#line 1666 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 185 "parser.y" /* yacc.c:1646  */
    {(yyval.st_t)=new ReadStatement(*(yyvsp[-1].item_l));}
#line 1672 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 188 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=(yyvsp[0].expr_t);}
#line 1678 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 189 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=0;}
#line 1684 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 193 "parser.y" /* yacc.c:1646  */
    { (yyval.st_list_t) = (yyvsp[-1].st_list_t); }
#line 1690 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 194 "parser.y" /* yacc.c:1646  */
    {(yyval.st_list_t)=new StatementList();}
#line 1696 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 198 "parser.y" /* yacc.c:1646  */
    {
										(yyval.st_list_t)=(yyvsp[-2].st_list_t);
										(yyval.st_list_t)->push_back((yyvsp[0].st_t));
									}
#line 1705 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 202 "parser.y" /* yacc.c:1646  */
    {
		   								(yyval.st_list_t)=new StatementList();
		   								(yyval.st_list_t)->push_back((yyvsp[0].st_t));
		   							}
#line 1714 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 209 "parser.y" /* yacc.c:1646  */
    {(yyval.st_t)=new AssignStatement((yyvsp[-3].id_t),(yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1720 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 213 "parser.y" /* yacc.c:1646  */
    { (yyval.expr_t)=(yyvsp[-1].expr_t);}
#line 1726 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 214 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=0;}
#line 1732 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 218 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new MethodExpr((yyvsp[-3].id_t),*(yyvsp[-1].expr_list_t));}
#line 1738 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 222 "parser.y" /* yacc.c:1646  */
    {(yyval.st_t)=new MethodStatement((yyvsp[-3].id_t),*(yyvsp[-1].expr_list_t));}
#line 1744 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 226 "parser.y" /* yacc.c:1646  */
    {
													(yyval.expr_list_t)=(yyvsp[-2].expr_list_t); 
													(yyval.expr_list_t)->push_back((yyvsp[0].expr_t));
												}
#line 1753 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 230 "parser.y" /* yacc.c:1646  */
    {
	           										(yyval.expr_list_t)=new ExprList(); 
	           										(yyval.expr_list_t)->push_back((yyvsp[0].expr_t));
	           									}
#line 1762 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 237 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new StrExpr((yyvsp[0].string_t));}
#line 1768 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 238 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new CharExpr((yyvsp[0].char_t));}
#line 1774 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 239 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=(yyvsp[0].expr_t); }
#line 1780 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 243 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_list_t)=(yyvsp[0].expr_list_t);}
#line 1786 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 244 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_list_t)=new ExprList();}
#line 1792 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 248 "parser.y" /* yacc.c:1646  */
    {
									(yyval.expr_list_t)=(yyvsp[-2].expr_list_t);
									(yyval.expr_list_t)->push_back((yyvsp[0].expr_t));
								}
#line 1801 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 252 "parser.y" /* yacc.c:1646  */
    {
		 							(yyval.expr_list_t)=new ExprList();
		 							(yyval.expr_list_t)->push_back((yyvsp[0].expr_t));
		 						}
#line 1810 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 259 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new OrExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1816 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 260 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=(yyvsp[0].expr_t);}
#line 1822 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 264 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new AndExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1828 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 269 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new EqualExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1834 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 270 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new NotEqualExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1840 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 271 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=(yyvsp[0].expr_t);}
#line 1846 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 275 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new LessThanExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1852 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 276 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new GreaterThanExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1858 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 277 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new LessThanEqualExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1864 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 278 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new GreaterThanEqualExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1870 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 279 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=(yyvsp[0].expr_t);}
#line 1876 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 283 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new ShiftLeftExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1882 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 284 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new ShiftRightExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1888 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 285 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new RotExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1894 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 286 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=(yyvsp[0].expr_t);}
#line 1900 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 290 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new ModExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1906 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 291 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=(yyvsp[0].expr_t);}
#line 1912 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 295 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new AddExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1918 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 296 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new SubExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1924 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 297 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=(yyvsp[0].expr_t);}
#line 1930 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 301 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new MultExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1936 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 302 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new DivExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1942 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 303 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=(yyvsp[0].expr_t);}
#line 1948 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 306 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new NotExpr((yyvsp[0].expr_t));}
#line 1954 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 307 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=(yyvsp[0].expr_t);}
#line 1960 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 311 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new NegativeExpr((yyvsp[0].expr_t));}
#line 1966 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 312 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=(yyvsp[0].expr_t);}
#line 1972 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 316 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=(yyvsp[0].expr_t);}
#line 1978 "parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 317 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=(yyvsp[0].expr_t);}
#line 1984 "parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 318 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=(yyvsp[-1].expr_t);}
#line 1990 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 319 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=(yyvsp[0].expr_t);}
#line 1996 "parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 322 "parser.y" /* yacc.c:1646  */
    { 
				string id = (yyvsp[0].id_t);
				free((yyvsp[0].id_t));
				(yyval.expr_t) = new IdExpr(id);
			 }
#line 2006 "parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 327 "parser.y" /* yacc.c:1646  */
    {
							string id = (yyvsp[-3].id_t);
							free((yyvsp[-3].id_t));
							(yyval.expr_t) = new ArrayExpr(id,(yyvsp[-1].expr_t));
						  }
#line 2016 "parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 334 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new IntExpr((yyvsp[0].num_t)); }
#line 2022 "parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 335 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 2028 "parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 339 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new BoolExpr(true); }
#line 2034 "parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 340 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new BoolExpr(false); }
#line 2040 "parser.cpp" /* yacc.c:1646  */
    break;


#line 2044 "parser.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 343 "parser.y" /* yacc.c:1906  */

