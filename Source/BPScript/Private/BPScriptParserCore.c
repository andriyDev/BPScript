/* A Bison parser, made by GNU Bison 3.0.  */

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
#define YYBISON_VERSION "3.0"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "bisoncfg.y" /* yacc.c:339  */

	#define _GNU_SOURCE
	#include <stdio.h>
#line 6 "bisoncfg.y" /* yacc.c:339  */

  static void print_token_value (FILE *, int, YYSTYPE);
  #define YYPRINT(F, N, L) print_token_value (F, N, L)

#line 75 "Source/BPScript/Private/BPScriptParserCore.c" /* yacc.c:339  */

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "BPScriptParserCore.h".  */
#ifndef YY_YY_SOURCE_BPSCRIPT_PRIVATE_BPSCRIPTPARSERCORE_H_INCLUDED
# define YY_YY_SOURCE_BPSCRIPT_PRIVATE_BPSCRIPTPARSERCORE_H_INCLUDED
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
    ID = 258,
    NUM = 259,
    PRIM = 260,
    STR = 261,
    TRUE = 262,
    FALSE = 263,
    NONE = 264,
    DISPATCHER = 265,
    EVENT = 266,
    DEFAULTSKW = 267,
    CONSTRUCTION = 268,
    FUNCTION = 269,
    MACRO = 270,
    COLLAPSED = 271,
    REF = 272,
    EXEC = 273,
    IF = 274,
    ELSE = 275,
    VAR = 276,
    FOR = 277,
    FOREACH = 278,
    WHILE = 279,
    BREAK = 280,
    RETURN = 281,
    END = 282,
    LOCAL = 283,
    LOGAND = 284,
    LOGOR = 285,
    GTE = 286,
    LTE = 287,
    EQ = 288,
    NEQ = 289
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SOURCE_BPSCRIPT_PRIVATE_BPSCRIPTPARSERCORE_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 161 "Source/BPScript/Private/BPScriptParserCore.c" /* yacc.c:358  */

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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
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
#define YYLAST   535

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  86
/* YYNRULES -- Number of rules.  */
#define YYNRULES  182
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  409

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
       2,     2,     2,     2,     2,    43,    42,    55,    41,     2,
      50,    51,    40,    52,    39,    53,    57,    54,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    35,    48,
      46,    49,    47,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    44,     2,    45,    56,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,    38,    37,     2,     2,     2,     2,
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
static const yytype_uint8 yyrline[] =
{
       0,    50,    50,    52,    52,    52,    52,    52,    52,    54,
      54,    55,    55,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    58,    60,    61,    61,    62,    62,    62,    62,
      62,    63,    63,    63,    63,    65,    65,    66,    66,    67,
      68,    68,    69,    69,    71,    71,    72,    72,    74,    74,
      76,    77,    77,    79,    80,    80,    81,    82,    82,    82,
      84,    85,    85,    86,    86,    87,    87,    88,    88,    90,
      91,    92,    92,    92,    94,    96,    98,    99,    99,   100,
     100,   102,   103,   103,   104,   104,   104,   105,   105,   107,
     107,   108,   108,   109,   109,   110,   110,   111,   111,   113,
     115,   115,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   119,   121,   122,   122,   123,
     123,   125,   125,   125,   126,   126,   126,   126,   126,   127,
     127,   127,   128,   128,   128,   129,   129,   129,   129,   130,
     130,   131,   131,   131,   131,   132,   132,   134,   136,   136,
     137,   137,   138,   138,   140,   140,   142,   143,   143,   144,
     144,   145,   146,   146,   146,   148,   149,   149,   149,   151,
     152,   153,   154,   156,   157,   159,   161,   163,   164,   164,
     166,   167,   167
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUM", "PRIM", "STR", "\"true\"",
  "\"false\"", "\"None\"", "\"dispatcher\"", "\"event\"", "\"defaults\"",
  "\"construction\"", "\"function\"", "\"macro\"", "\"collapsed\"",
  "\"ref\"", "\"Exec\"", "\"if\"", "\"else\"", "\"var\"", "\"for\"",
  "\"foreach\"", "\"while\"", "\"break\"", "\"return\"", "\"end\"",
  "\"local\"", "\"&&\"", "\"||\"", "\">=\"", "\"<=\"", "\"==\"", "\"!=\"",
  "':'", "'{'", "'}'", "'|'", "','", "'*'", "'&'", "'$'", "'#'", "'['",
  "']'", "'<'", "'>'", "';'", "'='", "'('", "')'", "'+'", "'-'", "'/'",
  "'%'", "'^'", "'.'", "$accept", "Class", "Value", "Interfaces",
  "NextInterface", "ClassBody", "Variable", "DataType", "StoredType",
  "RefType", "ElementType", "Properties", "NextProperty", "Property",
  "PropertyEnding", "PropertyValue", "Initilization", "InitVal",
  "ContainerBody", "ArrayBody", "OptionalValue", "MapBody",
  "OptionalValuePair", "ValuePair", "ValuePairEnding", "Dispatcher",
  "OptionalParameters", "Parameter", "ParameterEnding", "NextParameter",
  "Defaults", "VarDefault", "VarDefaultValue", "Construction", "Event",
  "Function", "OptionalReturnValues", "NextReturnValue", "Macro",
  "MacroOptionalParams", "MacroParam", "MacroNextParam",
  "MacroOptionalReturnValues", "MacroRetVal", "MacroNextRetVal",
  "MacroBodies", "MacroBody", "CollapsedNodes", "ExecBody", "Statement",
  "NamedPin", "PinNames", "NextPin", "Pin", "Expression", "ExpressionB",
  "ExpressionA", "Expression0", "Expression1", "Expression2",
  "Expression3", "Expression4", "ExpressionFunctionCall", "EFCParams",
  "EFCParam", "EFCNextParam", "EFCRetVal", "FunctionCall", "CallParams",
  "CallNextParam", "FunctionCallEnding", "FCBody", "IfStatement",
  "OptionalElse", "ForLoop", "ForBreakLoop", "ForEachLoop",
  "ForEachBreakLoop", "WhileLoop", "WhileBreakLoop", "BreakStatement",
  "ReturnStatement", "EndStatement", "OptionalEndExec", "LocalVar",
  "OptionalInit", YY_NULL
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
     285,   286,   287,   288,   289,    58,   123,   125,   124,    44,
      42,    38,    36,    35,    91,    93,    60,    62,    59,    61,
      40,    41,    43,    45,    47,    37,    94,    46
};
# endif

#define YYPACT_NINF -275

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-275)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      21,    -2,    40,    81,  -275,    43,    85,    70,   107,  -275,
     117,  -275,   303,   107,   176,   151,   184,   186,   198,   228,
     205,    33,  -275,  -275,  -275,  -275,  -275,  -275,  -275,  -275,
    -275,  -275,   183,   232,   268,  -275,   234,   234,   281,   154,
    -275,   284,   213,   119,   294,   255,   286,    77,   318,   277,
     280,   338,  -275,  -275,  -275,  -275,  -275,   234,    33,   306,
     299,  -275,    33,   344,   310,  -275,   234,   174,  -275,    59,
     312,    20,    22,    62,   316,    12,   357,    33,  -275,  -275,
    -275,   320,   328,  -275,  -275,  -275,  -275,  -275,  -275,  -275,
    -275,  -275,  -275,  -275,  -275,   330,   331,   119,   278,   234,
     106,  -275,  -275,  -275,   370,   334,   342,   349,  -275,  -275,
    -275,  -275,  -275,  -275,   378,  -275,   353,   397,   399,    60,
     365,   401,   367,   404,   405,    60,  -275,    82,    60,  -275,
     128,   113,   204,   223,    95,   354,   109,  -275,  -275,   361,
     372,  -275,   364,   410,    60,   399,  -275,   200,  -275,   318,
     377,   374,    33,   413,   423,   376,  -275,   379,  -275,   238,
    -275,   334,   378,   389,  -275,   119,    -5,   393,   396,   403,
    -275,  -275,   408,   406,   407,   394,     2,   402,   451,   411,
     453,   409,    19,    60,    12,    78,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    83,  -275,    12,  -275,  -275,   418,    13,   328,   464,
    -275,  -275,   331,  -275,   434,   467,   432,   334,   437,   278,
     378,  -275,   425,   389,  -275,   119,  -275,   426,   444,   378,
    -275,  -275,  -275,   378,  -275,   399,  -275,  -275,   440,    60,
     436,    60,   441,    60,   442,   128,   430,  -275,   113,   113,
     204,   204,   204,   204,   223,   223,    95,    95,   354,   354,
     354,   109,    29,  -275,  -275,    60,   435,  -275,  -275,   443,
    -275,    33,   448,   334,   278,  -275,   432,     9,  -275,   439,
     449,  -275,  -275,  -275,  -275,  -275,   452,   378,  -275,  -275,
     446,   454,   403,   406,  -275,     3,  -275,   222,   447,   243,
     450,    97,  -275,   457,  -275,   128,  -275,   483,   490,  -275,
     432,  -275,  -275,   492,   493,   458,     8,   437,  -275,  -275,
     461,   462,  -275,  -275,  -275,   465,  -275,  -275,   115,    60,
      60,    60,    60,   466,   148,   497,  -275,   468,   469,   165,
    -275,  -275,  -275,     9,  -275,   470,  -275,  -275,  -275,   202,
    -275,  -275,  -275,   240,   484,   170,   327,   187,   329,  -275,
    -275,  -275,  -275,    33,  -275,  -275,   458,  -275,   266,     8,
    -275,   283,  -275,    35,  -275,   471,    60,   473,    60,   309,
     500,  -275,   326,  -275,  -275,  -275,  -275,  -275,   189,  -275,
     225,  -275,   469,  -275,   352,   369,   474,   395,   475,  -275,
    -275,  -275,  -275,  -275,  -275,   412,   438,  -275,  -275
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     9,     0,     0,    11,    13,
       0,    10,     0,    11,     0,     0,     0,     0,     0,     0,
       0,     0,     2,    14,    15,    16,    17,    18,    19,    20,
      21,    12,     0,     0,     0,   100,    35,    35,     0,    26,
      24,     0,    31,    61,     0,     0,     0,     0,     0,     0,
       0,     0,    27,    28,    29,    30,    25,    35,     0,     0,
       0,    23,     0,     0,     0,    62,    35,     0,    69,   119,
       0,     0,     0,     0,     0,   148,   178,     0,    74,   101,
     102,     0,   117,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    40,    37,    61,    82,    35,
       0,    34,    33,    32,     0,    65,     0,     0,     3,     8,
       7,     4,     5,     6,     0,    71,     0,     0,   157,     0,
       0,     0,     0,     0,     0,     0,   175,     3,     0,   146,
     150,   123,   128,   131,   134,   138,   140,   144,   143,     0,
     152,   179,     0,     0,     0,     0,   116,     0,    39,     0,
       0,     0,     0,     0,     0,     0,    83,     0,    44,     0,
      22,    65,     0,    67,    60,    61,    51,     0,     0,    54,
      70,   120,   119,   159,     0,     3,     0,     0,     0,     0,
       0,     0,     0,     0,   148,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   176,     0,   149,   177,   181,     0,   117,     0,
      42,    41,    37,    36,    77,     0,    87,    65,    89,    82,
       0,    46,     0,    67,    66,     0,    64,     0,     0,     0,
      50,    73,    72,     0,    53,     0,   158,   162,     0,     0,
       0,     0,     0,     0,     0,   151,     0,   145,   121,   122,
     126,   127,   125,   124,   129,   130,   132,   133,   135,   136,
     137,   139,     0,   141,   153,     0,     0,   115,   118,     0,
      38,     0,     0,    65,     0,    86,    87,     0,    96,     0,
       0,    48,    49,    45,    63,    68,     0,     0,    57,    56,
      51,     0,    54,   159,   156,     0,   100,     0,     0,     0,
       0,     0,   100,   154,   142,   182,   180,     0,     0,   100,
      87,    88,    85,     0,     0,    93,    81,    89,    47,   100,
       0,     0,    52,    55,   160,     0,   100,   161,     0,     0,
       0,     0,     0,     0,     0,     0,   147,     0,    79,     0,
      84,    92,    91,     0,    90,     0,   100,    95,    96,     0,
      59,    58,   100,     0,   166,     0,     0,     0,     0,   100,
     173,   155,    43,     0,    78,    76,    93,   100,     0,    99,
      75,     0,   164,     0,   165,     0,     0,     0,     0,     0,
       0,    94,     0,    98,   163,   100,   168,   100,     0,   100,
       0,   174,    79,    97,     0,     0,     0,     0,     0,    80,
     167,   169,   100,   171,   100,     0,     0,   170,   172
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -275,  -275,   -64,  -275,   499,  -275,  -275,   -21,   455,  -275,
    -275,   -20,   302,   366,  -275,  -275,  -275,  -275,  -275,  -212,
     226,  -211,   227,   285,  -275,  -275,   -92,   292,  -157,   297,
    -275,  -275,  -275,  -275,  -275,  -275,  -275,   129,  -275,   304,
     248,  -263,   207,   182,   160,   179,  -275,  -275,  -274,  -275,
    -275,  -275,   321,  -116,  -118,    92,   110,   133,   144,   -35,
     332,   333,  -275,   346,   325,  -275,  -275,  -275,  -275,   239,
    -275,  -275,   162,  -275,  -275,  -275,  -275,  -275,  -275,  -275,
    -275,  -275,  -275,  -275,  -275,  -275
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,   129,     7,    11,    12,    23,    63,    42,    56,
      61,    49,   150,    96,   148,   211,   160,   222,   280,   167,
     230,   168,   234,   169,   289,    24,    64,    65,   163,   226,
      25,    46,   116,    26,    27,    28,   272,   364,    29,   155,
     156,   275,   278,   315,   344,   316,   347,    30,    47,    79,
      80,    81,   146,    82,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   204,   336,    83,   174,   236,
     294,   295,    84,   374,    85,    86,    87,    88,    89,    90,
      91,    92,    93,   142,    94,   266
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      41,   176,   173,   115,   223,   151,   325,   182,   281,   282,
     185,   345,    39,   312,    40,   127,   109,    50,   110,   111,
     112,   113,   328,   120,     1,   122,   207,   313,   334,   208,
     228,   186,   187,     3,   229,   339,    39,   100,    40,   326,
       4,   104,   186,   187,   346,   349,   107,   340,   186,   187,
     166,   327,   353,   238,    70,   121,   143,   123,   186,   187,
     276,   267,   128,   175,   109,   245,   110,   111,   112,   113,
     244,   385,   368,   227,   304,   320,   321,   154,   371,   157,
      69,     6,   262,   210,     5,   379,   108,   109,     8,   110,
     111,   112,   113,   382,   117,   221,    70,   124,   224,    71,
      72,    73,    74,    75,    76,    77,     9,   186,   187,   118,
     128,   394,   125,   395,    78,   397,   310,   183,    69,   293,
      13,   297,    39,   299,    40,   301,   186,   187,   405,   247,
     406,   215,   184,   128,    70,   196,    62,    71,    72,    73,
      74,    75,    76,    77,   188,   189,    10,   305,   333,   197,
     198,    69,   354,   200,   158,   159,   166,   186,   187,   190,
     191,   258,   259,   260,   288,   290,   201,    70,    69,   291,
      71,    72,    73,    74,    75,    76,    77,   108,   109,    32,
     110,   111,   112,   113,    70,   360,    33,    71,    72,    73,
      74,    75,    76,    77,    52,    53,    54,    55,   154,   186,
     187,    36,   365,   108,   109,    69,   110,   111,   112,   113,
     114,   355,   356,   357,   358,   375,   186,   187,   186,   187,
      34,    70,    35,   166,    71,    72,    73,    74,    75,    76,
      77,    37,   377,    43,   396,    44,   209,   192,   193,   370,
      38,   108,   109,    69,   110,   111,   112,   113,    58,    59,
     308,   186,   187,   154,   186,   187,   314,    60,   388,    70,
     390,   329,    71,    72,    73,    74,    75,    76,    77,    69,
     398,    45,   186,   187,   220,   194,   195,   372,   248,   249,
      48,    39,   331,    40,    51,    70,    69,    57,    71,    72,
      73,    74,    75,    76,    77,   152,   153,    66,   250,   251,
     252,   253,    70,   383,    67,    71,    72,    73,    74,    75,
      76,    77,    69,    14,    15,    16,    17,    18,    19,    20,
     384,    95,   314,    68,    21,   254,   255,    97,    70,    69,
      98,    71,    72,    73,    74,    75,    76,    77,   256,   257,
      22,    99,   380,   102,   103,    70,   391,   105,    71,    72,
      73,    74,    75,    76,    77,    69,   186,   187,   186,   187,
     141,   106,   119,   393,   126,   147,   376,   145,   378,   144,
     149,    70,    69,   161,    71,    72,    73,    74,    75,    76,
      77,   108,   109,   162,   110,   111,   112,   113,    70,   400,
     164,    71,    72,    73,    74,    75,    76,    77,    69,   165,
     171,   170,   172,   177,   178,   179,   401,   180,   181,   202,
     199,   203,   205,   206,    70,    69,   216,    71,    72,    73,
      74,    75,    76,    77,   213,   214,   217,   218,   225,   219,
     231,    70,   403,   232,    71,    72,    73,    74,    75,    76,
      77,    69,   233,   117,   184,   235,   239,   108,   109,   407,
     110,   111,   112,   113,   240,   241,   242,    70,   237,   243,
      71,    72,    73,    74,    75,    76,    77,   265,   269,   271,
     273,   274,   277,   283,   298,   408,   296,   286,   302,   300,
     287,   303,   307,   306,   309,   229,   318,   337,   319,   228,
     317,   330,   335,   338,   332,   341,   342,   343,   350,   351,
     361,   352,   359,   392,   373,   362,   367,   387,   363,   389,
     402,   404,    31,   101,   270,   212,   322,   285,   292,   323,
     284,   399,   311,   279,   348,   366,   381,   369,   264,   268,
     246,   261,   324,     0,   263,   386
};

static const yytype_int16 yycheck[] =
{
      21,   119,   118,    67,   161,    97,     3,   125,   220,   220,
     128,     3,     3,   276,     5,     3,     4,    37,     6,     7,
       8,     9,   296,     3,     3,     3,   144,    18,   302,   145,
      35,    29,    30,    35,    39,   309,     3,    57,     5,    36,
       0,    62,    29,    30,    36,   319,    66,   310,    29,    30,
     114,    48,   326,    51,    19,    35,    77,    35,    29,    30,
     217,    48,    50,     3,     4,   183,     6,     7,     8,     9,
      51,    36,   346,   165,    45,   287,   287,    98,   352,    99,
       3,    38,   200,   147,     3,   359,     3,     4,     3,     6,
       7,     8,     9,   367,    35,   159,    19,    35,   162,    22,
      23,    24,    25,    26,    27,    28,    36,    29,    30,    50,
      50,   385,    50,   387,    37,   389,   273,    35,     3,   235,
       3,   239,     3,   241,     5,   243,    29,    30,   402,    51,
     404,   152,    50,    50,    19,    40,    17,    22,    23,    24,
      25,    26,    27,    28,    31,    32,    39,   265,    51,    54,
      55,     3,    37,    44,    48,    49,   220,    29,    30,    46,
      47,   196,   197,   198,   228,   229,    57,    19,     3,   233,
      22,    23,    24,    25,    26,    27,    28,     3,     4,     3,
       6,     7,     8,     9,    19,    37,    35,    22,    23,    24,
      25,    26,    27,    28,    40,    41,    42,    43,   219,    29,
      30,     3,    37,     3,     4,     3,     6,     7,     8,     9,
      36,   329,   330,   331,   332,    45,    29,    30,    29,    30,
      36,    19,    36,   287,    22,    23,    24,    25,    26,    27,
      28,     3,    45,    50,    45,     3,    36,    33,    34,    37,
      35,     3,     4,     3,     6,     7,     8,     9,    35,    36,
     271,    29,    30,   274,    29,    30,   277,    44,   376,    19,
     378,    39,    22,    23,    24,    25,    26,    27,    28,     3,
      45,     3,    29,    30,    36,    52,    53,    37,   186,   187,
      46,     3,    39,     5,     3,    19,     3,     3,    22,    23,
      24,    25,    26,    27,    28,    17,    18,     3,   188,   189,
     190,   191,    19,    37,    49,    22,    23,    24,    25,    26,
      27,    28,     3,    10,    11,    12,    13,    14,    15,    16,
      37,     3,   343,    37,    21,   192,   193,    50,    19,     3,
      50,    22,    23,    24,    25,    26,    27,    28,   194,   195,
      37,     3,   363,    37,    45,    19,    37,     3,    22,    23,
      24,    25,    26,    27,    28,     3,    29,    30,    29,    30,
       3,    51,    50,    37,    48,    35,    39,    39,    39,    49,
      39,    19,     3,     3,    22,    23,    24,    25,    26,    27,
      28,     3,     4,    49,     6,     7,     8,     9,    19,    37,
      48,    22,    23,    24,    25,    26,    27,    28,     3,    50,
       3,    48,     3,    38,     3,    38,    37,     3,     3,    48,
      56,    39,    48,     3,    19,     3,     3,    22,    23,    24,
      25,    26,    27,    28,    47,    51,     3,    51,    39,    50,
      37,    19,    37,    37,    22,    23,    24,    25,    26,    27,
      28,     3,    39,    35,    50,    39,    44,     3,     4,    37,
       6,     7,     8,     9,     3,    44,     3,    19,    51,    50,
      22,    23,    24,    25,    26,    27,    28,    49,     4,    35,
       3,    39,    35,    48,    38,    37,    36,    51,    36,    38,
      36,    51,    39,    48,    36,    39,    37,     4,    36,    35,
      51,    44,    35,     3,    44,     3,     3,    39,    37,    37,
       3,    36,    36,     3,    20,    37,    36,    36,    39,    36,
      36,    36,    13,    58,   212,   149,   290,   225,   233,   292,
     223,   392,   274,   219,   317,   343,   366,   348,   203,   208,
     184,   199,   293,    -1,   201,   373
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    59,    35,     0,     3,    38,    61,     3,    36,
      39,    62,    63,     3,    10,    11,    12,    13,    14,    15,
      16,    21,    37,    64,    83,    88,    91,    92,    93,    96,
     105,    62,     3,    35,    36,    36,     3,     3,    35,     3,
       5,    65,    66,    50,     3,     3,    89,   106,    46,    69,
      69,     3,    40,    41,    42,    43,    67,     3,    35,    36,
      44,    68,    17,    65,    84,    85,     3,    49,    37,     3,
      19,    22,    23,    24,    25,    26,    27,    28,    37,   107,
     108,   109,   111,   125,   130,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   142,     3,    71,    50,    50,     3,
      69,    66,    37,    45,    65,     3,    51,    69,     3,     4,
       6,     7,     8,     9,    36,    60,    90,    35,    50,    50,
       3,    35,     3,    35,    35,    50,    48,     3,    50,    60,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,     3,   141,    65,    49,    39,   110,    35,    72,    39,
      70,    84,    17,    18,    65,    97,    98,    69,    48,    49,
      74,     3,    49,    86,    48,    50,    60,    77,    79,    81,
      48,     3,     3,   111,   126,     3,   112,    38,     3,    38,
       3,     3,   112,    35,    50,   112,    29,    30,    31,    32,
      46,    47,    33,    34,    52,    53,    40,    54,    55,    56,
      44,    57,    48,    39,   123,    48,     3,   112,   111,    36,
      60,    73,    71,    47,    51,    65,     3,     3,    51,    50,
      36,    60,    75,    86,    60,    39,    87,    84,    35,    39,
      78,    37,    37,    39,    80,    39,   127,    51,    51,    44,
       3,    44,     3,    50,    51,   112,   121,    51,   113,   113,
     114,   114,   114,   114,   115,   115,   116,   116,   117,   117,
     117,   118,   112,   119,   122,    49,   143,    48,   110,     4,
      70,    35,    94,     3,    39,    99,    86,    35,   100,    97,
      76,    77,    79,    48,    87,    85,    51,    36,    60,    82,
      60,    60,    81,   111,   128,   129,    36,   112,    38,   112,
      38,   112,    36,    51,    45,   112,    48,    39,    65,    36,
      86,    98,    99,    18,    65,   101,   103,    51,    37,    36,
      77,    79,    78,    80,   127,     3,    36,    48,   106,    39,
      44,    39,    44,    51,   106,    35,   124,     4,     3,   106,
      99,     3,     3,    39,   102,     3,    36,   104,   100,   106,
      37,    37,    36,   106,    37,   112,   112,   112,   112,    36,
      37,     3,    37,    39,    95,    37,   101,    36,   106,   103,
      37,   106,    37,    20,   131,    45,    39,    45,    39,   106,
      65,   102,   106,    37,    37,    36,   130,    36,   112,    36,
     112,    37,     3,    37,   106,   106,    45,   106,    45,    95,
      37,    37,    36,    37,    36,   106,   106,    37,    37
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    60,    60,    60,    60,    60,    60,    61,
      61,    62,    62,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    64,    65,    66,    66,    67,    67,    67,    67,
      67,    68,    68,    68,    68,    69,    69,    70,    70,    71,
      72,    72,    73,    73,    74,    74,    75,    75,    76,    76,
      77,    78,    78,    79,    80,    80,    81,    82,    82,    82,
      83,    84,    84,    85,    85,    86,    86,    87,    87,    88,
      89,    90,    90,    90,    91,    92,    93,    94,    94,    95,
      95,    96,    97,    97,    98,    98,    98,    99,    99,   100,
     100,   101,   101,   102,   102,   103,   103,   104,   104,   105,
     106,   106,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   108,   109,   110,   110,   111,
     111,   112,   112,   112,   113,   113,   113,   113,   113,   114,
     114,   114,   115,   115,   115,   116,   116,   116,   116,   117,
     117,   118,   118,   118,   118,   119,   119,   120,   121,   121,
     122,   122,   123,   123,   124,   124,   125,   126,   126,   127,
     127,   128,   129,   129,   129,   130,   131,   131,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   141,
     142,   143,   143
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     1,     1,     1,     1,     1,     1,     0,
       3,     0,     3,     0,     2,     2,     2,     2,     2,     2,
       2,     2,     5,     2,     1,     2,     0,     1,     1,     1,
       1,     0,     2,     2,     2,     0,     4,     0,     3,     2,
       0,     2,     1,     5,     1,     3,     1,     3,     1,     1,
       2,     0,     3,     2,     0,     3,     3,     1,     3,     3,
       6,     0,     1,     5,     4,     0,     2,     0,     2,     4,
       4,     1,     3,     3,     4,    11,    10,     0,     4,     0,
       4,     8,     0,     1,     5,     4,     3,     0,     2,     0,
       3,     2,     2,     0,     3,     2,     0,     4,     3,    10,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     2,     0,     3,     1,
       3,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     3,
       1,     3,     4,     1,     1,     3,     1,     5,     0,     2,
       1,     3,     0,     2,     0,     2,     5,     0,     2,     0,
       3,     2,     0,     5,     4,     8,     0,     4,     2,    11,
      13,    11,    13,     7,     9,     2,     3,     3,     0,     1,
       5,     0,     2
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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
      
#line 1536 "Source/BPScript/Private/BPScriptParserCore.c" /* yacc.c:1646  */
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
#line 168 "bisoncfg.y" /* yacc.c:1906  */


// Epilogue

