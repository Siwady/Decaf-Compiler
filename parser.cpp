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
MainMethod*    main_method;
MethodList *methods;
DeclList * declarationList;

#line 86 "parser.cpp" /* yacc.c:339  */

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
#line 21 "parser.y" /* yacc.c:355  */

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

#line 181 "parser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TOKENS_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 196 "parser.cpp" /* yacc.c:358  */

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
#define YYLAST   237

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,     2,     2,    46,     2,     2,
      37,    38,    49,    47,    39,    48,     2,    50,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    40,
      44,    41,    45,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    68,    68,    73,    74,    78,    79,    82,    93,    97,
      98,   102,   103,   107,   116,   117,   122,   123,   127,   130,
     139,   144,   151,   152,   156,   157,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   174,   175,   179,   180,
     184,   188,   195,   199,   200,   204,   208,   212,   216,   223,
     224,   225,   229,   230,   234,   238,   245,   246,   250,   251,
     255,   256,   257,   261,   262,   263,   264,   265,   269,   270,
     271,   272,   276,   277,   281,   282,   283,   287,   288,   289,
     292,   293,   297,   298,   302,   303,   308,   309,   312,   313,
     317,   318
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
  "T_NULL", "T_RETURN", "T_ROT", "T_VOID", "T_MAIN", "T_ELSE", "T_FOR",
  "T_IF", "T_WHILE", "T_BOOL", "T_INT", "T_FALSE", "T_TRUE", "'{'", "'}'",
  "'('", "')'", "','", "';'", "'='", "'['", "']'", "'<'", "'>'", "'%'",
  "'+'", "'-'", "'*'", "'/'", "'!'", "$accept", "program", "opt_methods",
  "method_list", "method", "main_method", "params", "param_list", "param",
  "opt_declarations", "declaration_list", "declaration", "id_listP",
  "type", "statement_list", "statement", "opt_expr", "opt_else",
  "assign_list", "assign", "opt_arr", "method_call_expr",
  "method_call_statement", "arguments_list", "argument", "opt_expr_list",
  "expr_list", "expr", "expr_a", "expr_eq", "expr_re", "expr_bit",
  "expr_md", "expr_ar", "expr_fa", "expr_ne", "expr_neg", "term",
  "constant", "bool_constant", YY_NULLPTR
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
     285,   286,   287,   288,   289,   123,   125,    40,    41,    44,
      59,    61,    91,    93,    60,    62,    37,    43,    45,    42,
      47,    33
};
# endif

#define YYPACT_NINF -93

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-93)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -13,    19,    28,   -22,   -93,    40,   -93,   -93,    40,    40,
     -93,    26,     9,    40,   -93,    33,   -93,    -5,    27,    43,
      40,   -93,    46,    30,    80,   -93,    77,    70,    40,   -93,
     -93,   -93,    88,   -93,   -93,   106,   -93,   108,   121,   -93,
     156,   -93,   143,   148,    40,   -93,    40,    40,   -93,   173,
     173,   -11,   136,     4,   178,   152,    11,   158,   160,   161,
      59,   -93,   154,   159,    75,    11,    11,   163,   -93,   -93,
     -93,   168,    11,    13,    11,   -93,    57,   -93,   186,   193,
      68,    12,    16,   162,    69,    71,   -93,   -93,   -93,   -93,
     -93,    94,   -93,   167,   186,   203,    11,    11,   -93,   -93,
     -93,   -93,   -93,   172,   174,   186,    15,    11,    11,    35,
     -93,   -93,     4,   -93,    11,    11,    11,    11,    11,    11,
      11,    11,    11,    11,    11,    11,    11,    11,    11,    11,
     -93,   -93,   169,    96,   -93,    47,    56,   -93,    11,   -93,
     186,   176,   -93,   -93,   186,   193,    68,    68,    12,    12,
      12,    12,    16,    16,    16,   162,    69,    69,    71,    71,
     203,    11,   177,   180,   186,   -93,   -93,   -10,   173,   173,
     203,   109,   125,   111,   189,   -93,   182,   183,   -93,   173,
     173,   141,   157,   -93,   -93
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,    15,    23,    22,     4,    14,
      17,     0,     0,     3,     6,     0,    16,    21,     0,     0,
       4,     5,     0,     0,     0,    18,     0,     0,    10,    88,
      91,    90,     0,    89,    20,     0,     2,     0,     9,    12,
       0,    19,     0,     0,     0,    13,    15,    15,    11,     0,
       0,    44,     0,     0,     0,     0,    37,     0,     0,     0,
       0,    25,     0,     0,     0,    53,     0,     0,    32,    50,
      49,    85,     0,     0,     0,    86,     0,    48,    51,    57,
      59,    62,    67,    71,    73,    76,    79,    81,    83,    84,
      21,     0,    33,     0,    36,     0,     0,     0,     8,    24,
      26,    27,     7,     0,    52,    55,     0,     0,    53,     0,
      82,    80,     0,    34,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      35,    31,    44,     0,    41,     0,     0,    46,     0,    43,
      42,     0,    87,    47,    56,    58,    60,    61,    65,    66,
      63,    64,    68,    69,    70,    72,    74,    75,    77,    78,
       0,     0,     0,     0,    54,    45,    40,     0,     0,     0,
       0,     0,     0,     0,    39,    29,     0,     0,    28,     0,
       0,     0,     0,    30,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -93,   -93,   199,   -93,   207,   -93,   -93,   -93,   179,   105,
     -93,   212,   170,     7,   -50,   -59,   -93,   -93,    52,   -92,
     -93,   -93,   -93,   -93,   113,   118,   -93,   -54,   112,    49,
     -19,   -14,   103,    41,    53,   155,   -93,   164,   208,   -93
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    12,    13,    14,    20,    37,    38,    39,     8,
       9,    10,    18,    11,    60,    61,    93,   178,   133,    62,
      67,    75,    63,    76,    77,   103,   104,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    33
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      64,    99,    94,   134,   114,    99,     1,    29,    69,    70,
      71,   105,   106,     5,    29,    15,    29,    71,   109,    71,
      15,   118,   119,   122,   123,     3,    65,    15,     4,   114,
     170,    66,    17,    29,    19,    40,    23,    30,    31,    22,
     124,    72,   135,   136,    30,    31,    30,    31,    72,   114,
      72,    40,    73,   140,   105,    74,   120,   121,   139,    73,
     144,   114,    74,    30,    31,    51,    24,    25,   166,    26,
     114,     6,     7,   142,    52,    53,    54,    55,   134,   116,
     117,    51,    56,    28,   164,   162,    34,    57,    58,    59,
      52,    53,    54,    55,   163,    98,   112,   113,    56,   148,
     149,   150,   151,    57,    58,    59,    36,   167,   152,   153,
     154,   102,    99,    99,    35,    51,   126,   127,   171,   172,
     128,   129,    99,    99,    52,    53,    54,    55,    41,   181,
     182,    51,    56,    24,   130,   160,   161,    57,    58,    59,
      52,    53,    54,    55,    42,   174,    43,    51,    56,   176,
     160,    49,    50,    57,    58,    59,    52,    53,    54,    55,
      44,   175,    45,    51,    56,   146,   147,   156,   157,    57,
      58,    59,    52,    53,    54,    55,    68,   183,    46,    51,
      56,   158,   159,    47,    90,    57,    58,    59,    52,    53,
      54,    55,    92,   184,   100,    95,    56,    96,    97,   101,
     114,    57,    58,    59,   107,   108,   115,   131,   125,   132,
     137,    66,   168,   138,   165,   169,   177,   179,   180,    27,
      21,    16,   173,    48,    91,   143,   141,   145,   155,   111,
       0,    32,     0,     0,     0,     0,     0,   110
};

static const yytype_int16 yycheck[] =
{
      50,    60,    56,    95,    14,    64,    19,     3,     4,     5,
       6,    65,    66,    35,     3,     8,     3,     6,    72,     6,
      13,     9,    10,     7,     8,     6,    37,    20,     0,    14,
      40,    42,     6,     3,    25,    28,    41,    33,    34,     6,
      24,    37,    96,    97,    33,    34,    33,    34,    37,    14,
      37,    44,    48,   107,   108,    51,    44,    45,    43,    48,
     114,    14,    51,    33,    34,     6,    39,    40,   160,    26,
      14,    31,    32,    38,    15,    16,    17,    18,   170,    11,
      12,     6,    23,    37,   138,    38,     6,    28,    29,    30,
      15,    16,    17,    18,    38,    36,    39,    40,    23,   118,
     119,   120,   121,    28,    29,    30,    36,   161,   122,   123,
     124,    36,   171,   172,    37,     6,    47,    48,   168,   169,
      49,    50,   181,   182,    15,    16,    17,    18,    40,   179,
     180,     6,    23,    39,    40,    39,    40,    28,    29,    30,
      15,    16,    17,    18,    38,    36,    38,     6,    23,    38,
      39,    46,    47,    28,    29,    30,    15,    16,    17,    18,
      39,    36,     6,     6,    23,   116,   117,   126,   127,    28,
      29,    30,    15,    16,    17,    18,    40,    36,    35,     6,
      23,   128,   129,    35,     6,    28,    29,    30,    15,    16,
      17,    18,    40,    36,    40,    37,    23,    37,    37,    40,
      14,    28,    29,    30,    41,    37,    13,    40,    46,     6,
      38,    42,    35,    39,    38,    35,    27,    35,    35,    20,
      13,     9,   170,    44,    54,   112,   108,   115,   125,    74,
      -1,    23,    -1,    -1,    -1,    -1,    -1,    73
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    19,    53,     6,     0,    35,    31,    32,    61,    62,
      63,    65,    54,    55,    56,    65,    63,     6,    64,    25,
      57,    56,     6,    41,    39,    40,    26,    54,    37,     3,
      33,    34,    90,    91,     6,    37,    36,    58,    59,    60,
      65,    40,    38,    38,    39,     6,    35,    35,    60,    61,
      61,     6,    15,    16,    17,    18,    23,    28,    29,    30,
      66,    67,    71,    74,    66,    37,    42,    72,    40,     4,
       5,     6,    37,    48,    51,    73,    75,    76,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
       6,    64,    40,    68,    79,    37,    37,    37,    36,    67,
      40,    40,    36,    77,    78,    79,    79,    41,    37,    79,
      89,    87,    39,    40,    14,    13,    11,    12,     9,    10,
      44,    45,     7,     8,    24,    46,    47,    48,    49,    50,
      40,    40,     6,    70,    71,    79,    79,    38,    39,    43,
      79,    77,    38,    76,    79,    80,    81,    81,    82,    82,
      82,    82,    83,    83,    83,    84,    85,    85,    86,    86,
      39,    40,    38,    38,    79,    38,    71,    79,    35,    35,
      40,    66,    66,    70,    36,    36,    38,    27,    69,    35,
      35,    66,    66,    36,    36
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    54,    55,    55,    56,    57,    58,
      58,    59,    59,    60,    61,    61,    62,    62,    63,    63,
      64,    64,    65,    65,    66,    66,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    68,    68,    69,    69,
      70,    70,    71,    72,    72,    73,    74,    75,    75,    76,
      76,    76,    77,    77,    78,    78,    79,    79,    80,    80,
      81,    81,    81,    82,    82,    82,    82,    82,    83,    83,
      83,    83,    84,    84,    85,    85,    85,    86,    86,    86,
      87,    87,    88,    88,    89,    89,    89,    89,    90,    90,
      91,    91
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     1,     0,     2,     1,     9,     8,     1,
       0,     3,     1,     2,     1,     0,     2,     1,     3,     5,
       3,     1,     1,     1,     2,     1,     2,     2,     8,     7,
      11,     3,     2,     2,     3,     3,     1,     0,     4,     0,
       3,     1,     4,     3,     0,     4,     4,     3,     1,     1,
       1,     1,     1,     0,     3,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     1,
       2,     1,     2,     1,     1,     1,     1,     3,     1,     1,
       1,     1
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
#line 68 "parser.y" /* yacc.c:1646  */
    {declarationList=(yyvsp[-4].decl_list); methods=(yyvsp[-1].mtd_list); main_method=(yyvsp[-2].main_t);}
#line 1416 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 73 "parser.y" /* yacc.c:1646  */
    {(yyval.mtd_list)=(yyvsp[0].mtd_list);}
#line 1422 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 74 "parser.y" /* yacc.c:1646  */
    {(yyval.mtd_list)=0; }
#line 1428 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 78 "parser.y" /* yacc.c:1646  */
    {(yyval.mtd_list)=(yyvsp[-1].mtd_list);  (yyval.mtd_list)->push_back((yyvsp[0].method_t));}
#line 1434 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 79 "parser.y" /* yacc.c:1646  */
    {(yyval.mtd_list)=new MethodList(); (yyval.mtd_list)->push_back((yyvsp[0].method_t));}
#line 1440 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 82 "parser.y" /* yacc.c:1646  */
    {
																			if((yyvsp[-8].type_t)==INT){
																				(yyval.method_t)=new Method(M_INT,(yyvsp[-7].id_t),*(yyvsp[-5].prm_list),*(yyvsp[-2].decl_list),*(yyvsp[-1].st_list_t));
																			}else
																			{	
																				(yyval.method_t)=new Method(M_BOOLEAN,(yyvsp[-7].id_t),*(yyvsp[-5].prm_list),*(yyvsp[-2].decl_list),*(yyvsp[-1].st_list_t));
																			}												
																		}
#line 1453 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 93 "parser.y" /* yacc.c:1646  */
    { (yyval.main_t)=new MainMethod(*(yyvsp[-2].decl_list),*(yyvsp[-1].st_list_t));}
#line 1459 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 97 "parser.y" /* yacc.c:1646  */
    {(yyval.prm_list)=(yyvsp[0].prm_list);}
#line 1465 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 98 "parser.y" /* yacc.c:1646  */
    {(yyval.prm_list)=new ParamList();}
#line 1471 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 102 "parser.y" /* yacc.c:1646  */
    {(yyval.prm_list)=(yyvsp[-2].prm_list); (yyval.prm_list)->push_back((yyvsp[0].param_t));}
#line 1477 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 103 "parser.y" /* yacc.c:1646  */
    {(yyval.prm_list)=new ParamList(); (yyval.prm_list)->push_back((yyvsp[0].param_t));}
#line 1483 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 107 "parser.y" /* yacc.c:1646  */
    {
						string id=(yyvsp[0].id_t);
						free((yyvsp[0].id_t));
						(yyval.param_t)=new Param((yyvsp[-1].type_t),id);
					}
#line 1493 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 116 "parser.y" /* yacc.c:1646  */
    {(yyval.decl_list)=(yyvsp[0].decl_list);}
#line 1499 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 117 "parser.y" /* yacc.c:1646  */
    {(yyval.decl_list)=new DeclList();}
#line 1505 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 122 "parser.y" /* yacc.c:1646  */
    {(yyval.decl_list)=(yyvsp[-1].decl_list);  (yyval.decl_list)->push_back((yyvsp[0].decl));}
#line 1511 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 123 "parser.y" /* yacc.c:1646  */
    {(yyval.decl_list)=new DeclList();  (yyval.decl_list)->push_back((yyvsp[0].decl));}
#line 1517 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 127 "parser.y" /* yacc.c:1646  */
    {	
									(yyval.decl)=new Declaration((yyvsp[-2].type_t),*(yyvsp[-1].idlist_t),0);
								}
#line 1525 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 130 "parser.y" /* yacc.c:1646  */
    {
	       									IdList *ids=new IdList();
	       									string id=(yyvsp[-3].id_t);
	       									ids->push_back(id);
	       									(yyval.decl)=new Declaration((yyvsp[-4].type_t),*ids,(yyvsp[-1].expr_t));
	       								}
#line 1536 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 139 "parser.y" /* yacc.c:1646  */
    { 
								(yyval.idlist_t)=(yyvsp[-2].idlist_t); 
								string id=(yyvsp[0].id_t);
								(yyval.idlist_t)->push_back(id);
							}
#line 1546 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 144 "parser.y" /* yacc.c:1646  */
    {
          				string id=(yyvsp[0].id_t);
          				(yyval.idlist_t)=new IdList();
          				(yyval.idlist_t)->push_back(id);
          			}
#line 1556 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 151 "parser.y" /* yacc.c:1646  */
    {(yyval.type_t)=INT;}
#line 1562 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 152 "parser.y" /* yacc.c:1646  */
    {(yyval.type_t)=BOOLEAN;}
#line 1568 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 156 "parser.y" /* yacc.c:1646  */
    { (yyval.st_list_t)=(yyvsp[-1].st_list_t); (yyval.st_list_t)->push_back((yyvsp[0].st_t));}
#line 1574 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 157 "parser.y" /* yacc.c:1646  */
    { (yyval.st_list_t) = new StatementList(); (yyval.st_list_t)->push_back((yyvsp[0].st_t)); }
#line 1580 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 161 "parser.y" /* yacc.c:1646  */
    {(yyval.st_t)=(yyvsp[-1].st_t);}
#line 1586 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 162 "parser.y" /* yacc.c:1646  */
    {(yyval.st_t)=(yyvsp[-1].st_t);}
#line 1592 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 163 "parser.y" /* yacc.c:1646  */
    {(yyval.st_t)=new IfStatement((yyvsp[-5].expr_t),*(yyvsp[-2].st_list_t),*(yyvsp[0].st_list_t));}
#line 1598 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 164 "parser.y" /* yacc.c:1646  */
    {(yyval.st_t)=new WhileStatement((yyvsp[-4].expr_t),*(yyvsp[-1].st_list_t));}
#line 1604 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 165 "parser.y" /* yacc.c:1646  */
    {(yyval.st_t)=new ForStatement(*(yyvsp[-8].st_list_t),(yyvsp[-6].expr_t),*(yyvsp[-4].st_list_t),*(yyvsp[-1].st_list_t));}
#line 1610 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 166 "parser.y" /* yacc.c:1646  */
    {(yyval.st_t)=new ReturnStatement((yyvsp[-1].expr_t));}
#line 1616 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 167 "parser.y" /* yacc.c:1646  */
    {(yyval.st_t)=new BreakStatement();}
#line 1622 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 168 "parser.y" /* yacc.c:1646  */
    {(yyval.st_t)=new ContinueStatement();}
#line 1628 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 169 "parser.y" /* yacc.c:1646  */
    {(yyval.st_t)=new PrintStatement(*(yyvsp[-1].expr_list_t));}
#line 1634 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 170 "parser.y" /* yacc.c:1646  */
    {(yyval.st_t)=new ReadStatement(*(yyvsp[-1].idlist_t));}
#line 1640 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 174 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=(yyvsp[0].expr_t);}
#line 1646 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 175 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=0;}
#line 1652 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 179 "parser.y" /* yacc.c:1646  */
    { (yyval.st_list_t) = (yyvsp[-1].st_list_t); }
#line 1658 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 180 "parser.y" /* yacc.c:1646  */
    {(yyval.st_list_t)=new StatementList();}
#line 1664 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 184 "parser.y" /* yacc.c:1646  */
    {
										(yyval.st_list_t)=(yyvsp[-2].st_list_t);
										(yyval.st_list_t)->push_back((yyvsp[0].st_t));
									}
#line 1673 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 188 "parser.y" /* yacc.c:1646  */
    {
		   								(yyval.st_list_t)=new StatementList();
		   								(yyval.st_list_t)->push_back((yyvsp[0].st_t));
		   							}
#line 1682 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 195 "parser.y" /* yacc.c:1646  */
    {(yyval.st_t)=new AssignStatement((yyvsp[-3].id_t),(yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1688 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 199 "parser.y" /* yacc.c:1646  */
    { (yyval.expr_t)=(yyvsp[-1].expr_t);}
#line 1694 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 200 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=0;}
#line 1700 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 204 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new MethodExpr((yyvsp[-3].id_t),*(yyvsp[-1].expr_list_t));}
#line 1706 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 208 "parser.y" /* yacc.c:1646  */
    {(yyval.st_t)=new MethodStatement((yyvsp[-3].id_t),*(yyvsp[-1].expr_list_t));}
#line 1712 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 212 "parser.y" /* yacc.c:1646  */
    {
													(yyval.expr_list_t)=(yyvsp[-2].expr_list_t); 
													(yyval.expr_list_t)->push_back((yyvsp[0].expr_t));
												}
#line 1721 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 216 "parser.y" /* yacc.c:1646  */
    {
	           										(yyval.expr_list_t)=new ExprList(); 
	           										(yyval.expr_list_t)->push_back((yyvsp[0].expr_t));
	           									}
#line 1730 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 223 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new StrExpr((yyvsp[0].string_t));}
#line 1736 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 224 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new CharExpr((yyvsp[0].char_t));}
#line 1742 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 225 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=(yyvsp[0].expr_t); }
#line 1748 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 229 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_list_t)=(yyvsp[0].expr_list_t);}
#line 1754 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 230 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_list_t)=0;}
#line 1760 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 234 "parser.y" /* yacc.c:1646  */
    {
									(yyval.expr_list_t)=(yyvsp[-2].expr_list_t);
									(yyval.expr_list_t)->push_back((yyvsp[0].expr_t));
								}
#line 1769 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 238 "parser.y" /* yacc.c:1646  */
    {
		 							(yyval.expr_list_t)=new ExprList();
		 							(yyval.expr_list_t)->push_back((yyvsp[0].expr_t));
		 						}
#line 1778 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 245 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new OrExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1784 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 246 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=(yyvsp[0].expr_t);}
#line 1790 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 250 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new AndExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1796 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 255 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new EqualExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1802 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 256 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new NotEqualExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1808 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 257 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=(yyvsp[0].expr_t);}
#line 1814 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 261 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new LessThanExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1820 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 262 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new GreaterThanExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1826 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 263 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new LessThanEqualExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1832 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 264 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new GreaterThanEqualExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1838 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 265 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=(yyvsp[0].expr_t);}
#line 1844 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 269 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new ShiftLeftExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1850 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 270 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new ShiftRightExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1856 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 271 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new RotExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1862 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 272 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=(yyvsp[0].expr_t);}
#line 1868 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 276 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new ModExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1874 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 277 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=(yyvsp[0].expr_t);}
#line 1880 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 281 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new AddExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1886 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 282 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new SubExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1892 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 283 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=(yyvsp[0].expr_t);}
#line 1898 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 287 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new MultExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1904 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 288 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new DivExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1910 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 289 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=(yyvsp[0].expr_t);}
#line 1916 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 292 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new NotExpr((yyvsp[0].expr_t));}
#line 1922 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 293 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=(yyvsp[0].expr_t);}
#line 1928 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 297 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new NegativeExpr((yyvsp[0].expr_t));}
#line 1934 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 298 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=(yyvsp[0].expr_t);}
#line 1940 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 302 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=(yyvsp[0].expr_t);}
#line 1946 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 303 "parser.y" /* yacc.c:1646  */
    {
							string id = (yyvsp[0].id_t);
                            free((yyvsp[0].id_t));
                            (yyval.expr_t) = new IdExpr(id);
                        }
#line 1956 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 308 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=(yyvsp[0].expr_t);}
#line 1962 "parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 309 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=(yyvsp[-1].expr_t);}
#line 1968 "parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 312 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new IntExpr((yyvsp[0].num_t)); }
#line 1974 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 313 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1980 "parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 317 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new BoolExpr(true); }
#line 1986 "parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 318 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new BoolExpr(false); }
#line 1992 "parser.cpp" /* yacc.c:1646  */
    break;


#line 1996 "parser.cpp" /* yacc.c:1646  */
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
#line 321 "parser.y" /* yacc.c:1906  */

