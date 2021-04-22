/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "ICG.y"

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#define LIMIT 1024

//	extern int lineno = 0;
	void yyerror(const char*);
	int yylex();
	int temp_no = 0;
	int label1= 0; //while
	int label= 0; //switch
	int switch_counter=0;
	int case_end=0;
	FILE *outfile;

	void arithmetic_gen(char op[5]);
	void display_stack();
	void label_push1(int label);
	void push(char *);
	char *pop();
	char *top(int off);
	void label_push(int);
	char *label_pop();
    void gen_false_code();
    void gen_true_code();

	typedef struct Stack {
		char *items[LIMIT];
		int top;
	}Stack;
	Stack stack;
	Stack label_stack;


#line 106 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    PREPROC = 258,
    STDIO = 259,
    MATH = 260,
    STRING = 261,
    IDENTIFIER = 262,
    INTEGER_LITERAL = 263,
    FLOAT_LITERAL = 264,
    STRING_LITERAL = 265,
    HEADER_LITERAL = 266,
    CHARACTER_LITERAL = 267,
    INC_OP = 268,
    DEC_OP = 269,
    LE_OP = 270,
    GE_OP = 271,
    EQ_OP = 272,
    NE_OP = 273,
    LT = 274,
    GT = 275,
    AND_LOG = 276,
    OR_LOG = 277,
    NOT = 278,
    ADD_ASSIGN = 279,
    SUB_ASSIGN = 280,
    MUL_ASSIGN = 281,
    DIV_ASSIGN = 282,
    MOD_ASSIGN = 283,
    CHAR = 284,
    INT = 285,
    FLOAT = 286,
    VOID = 287,
    MAIN = 288,
    BREAK = 289,
    SWITCH = 290,
    CASE = 291,
    DEFAULT = 292,
    RETURN = 293,
    SUB = 294,
    ADD = 295,
    MUL = 296,
    DIV = 297,
    MOD = 298,
    STRUCT = 299,
    WHILE = 300
  };
#endif
/* Tokens.  */
#define PREPROC 258
#define STDIO 259
#define MATH 260
#define STRING 261
#define IDENTIFIER 262
#define INTEGER_LITERAL 263
#define FLOAT_LITERAL 264
#define STRING_LITERAL 265
#define HEADER_LITERAL 266
#define CHARACTER_LITERAL 267
#define INC_OP 268
#define DEC_OP 269
#define LE_OP 270
#define GE_OP 271
#define EQ_OP 272
#define NE_OP 273
#define LT 274
#define GT 275
#define AND_LOG 276
#define OR_LOG 277
#define NOT 278
#define ADD_ASSIGN 279
#define SUB_ASSIGN 280
#define MUL_ASSIGN 281
#define DIV_ASSIGN 282
#define MOD_ASSIGN 283
#define CHAR 284
#define INT 285
#define FLOAT 286
#define VOID 287
#define MAIN 288
#define BREAK 289
#define SWITCH 290
#define CASE 291
#define DEFAULT 292
#define RETURN 293
#define SUB 294
#define ADD 295
#define MUL 296
#define DIV 297
#define MOD 298
#define STRUCT 299
#define WHILE 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 37 "ICG.y"

    int ival;
	char string[128];

#line 253 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   252

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  195

#define YYUNDEFTOK  2
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      46,    47,     2,     2,    54,     2,    48,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    52,    55,
       2,    53,     2,    51,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,     2,    57,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    70,    70,    71,    75,    76,    77,    81,    82,    83,
      84,    85,    86,    89,    90,    91,    92,    93,    94,    95,
      96,    99,   100,   103,   106,   107,   108,   109,   112,   113,
     114,   117,   118,   119,   120,   121,   124,   125,   126,   130,
     131,   135,   136,   140,   141,   141,   141,   144,   145,   146,
     147,   150,   151,   155,   156,   159,   160,   165,   166,   167,
     172,   173,   177,   178,   179,   180,   181,   184,   185,   186,
     189,   190,   193,   194,   197,   198,   201,   202,   205,   206,
     209,   210,   211,   212,   213,   217,   217,   217,   220,   221,
     225,   225,   226,   226,   229,   229,   230,   230,   234,   235,
     238,   239,   242,   243,   246,   247,   250,   250,   254,   255,
     255,   250,   259,   260,   263,   264,   265
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PREPROC", "STDIO", "MATH", "STRING",
  "IDENTIFIER", "INTEGER_LITERAL", "FLOAT_LITERAL", "STRING_LITERAL",
  "HEADER_LITERAL", "CHARACTER_LITERAL", "INC_OP", "DEC_OP", "LE_OP",
  "GE_OP", "EQ_OP", "NE_OP", "LT", "GT", "AND_LOG", "OR_LOG", "NOT",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "CHAR", "INT", "FLOAT", "VOID", "MAIN", "BREAK", "SWITCH", "CASE",
  "DEFAULT", "RETURN", "SUB", "ADD", "MUL", "DIV", "MOD", "STRUCT",
  "WHILE", "'('", "')'", "'.'", "'['", "']'", "'?'", "':'", "'='", "','",
  "';'", "'{'", "'}'", "$accept", "headers", "libraries",
  "primary_expression", "postfix_expression", "unary_expression",
  "unary_operator", "multiplicative_expression", "additive_expression",
  "relational_expression", "equality_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression", "$@1", "$@2",
  "assignment_expression", "expression", "declaration",
  "init_declarator_list", "init_declarator", "array", "type_specifier",
  "struct_specifier", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "statement", "switch_statement", "$@3", "$@4",
  "case_statement", "case_statement_int", "$@5", "$@6",
  "case_statement_int1", "$@7", "$@8", "compound_statement",
  "block_item_list", "block_item", "expression_statement",
  "while_statement", "$@9", "$@10", "$@11", "$@12", "$@13",
  "translation_unit", "external_declaration", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,    40,    41,    46,    91,
      93,    63,    58,    61,    44,    59,   123,   125
};
# endif

#define YYPACT_NINF (-157)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-45)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      19,    -3,  -157,   -20,  -157,  -157,    -4,  -157,  -157,    -2,
    -157,    15,  -157,  -157,   109,   -25,     5,   141,   -42,  -157,
      18,  -157,  -157,  -157,  -157,  -157,  -157,    46,    29,   141,
    -157,   141,   159,  -157,     2,    70,    73,  -157,    83,  -157,
    -157,    42,   170,  -157,  -157,  -157,    60,  -157,    89,  -157,
      66,  -157,  -157,  -157,  -157,  -157,    16,    16,  -157,    73,
    -157,   128,    40,    73,    79,    55,   209,   130,    97,     7,
    -157,  -157,  -157,    94,  -157,  -157,  -157,   120,  -157,    60,
    -157,  -157,  -157,    37,  -157,  -157,    87,   149,    73,    73,
      73,    73,  -157,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,   112,    90,  -157,   160,
    -157,  -157,   138,  -157,  -157,  -157,  -157,   123,  -157,  -157,
    -157,  -157,  -157,  -157,    73,  -157,  -157,    20,  -157,  -157,
    -157,  -157,  -157,  -157,  -157,    79,    79,    55,    55,    55,
      55,   209,   209,   130,    97,    73,  -157,   164,  -157,  -157,
    -157,  -157,  -157,  -157,   150,    73,    73,   174,    45,   150,
      73,  -157,  -157,  -157,   179,   191,   158,   183,    73,  -157,
      31,  -157,  -157,  -157,   189,    73,  -157,  -157,  -157,   152,
     190,   152,  -157,   192,   152,   152,   152,   193,   152,   186,
     152,   152,   152,  -157,   152
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    63,    64,    65,    62,     0,   116,   115,     0,
      66,     0,   112,     2,     0,     0,    69,     0,    57,    53,
       0,    55,     1,   113,     4,     5,     6,     0,     0,     0,
      64,    75,     0,    70,     0,     0,     0,    59,     0,    54,
       3,     0,     0,    74,    67,    71,    78,    72,     0,    76,
       0,     7,     8,     9,    10,    12,     0,     0,    23,     0,
      13,    21,    24,     0,    28,    31,    36,    39,    41,    43,
      47,    58,    56,     0,   114,    68,    79,     0,    73,    61,
      19,    20,    51,     0,    17,    18,     0,     0,     0,     0,
       0,     0,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    85,     0,
     104,    98,     0,   102,   103,    83,    80,     0,   100,    81,
      82,    77,    60,    11,     0,    14,    15,     0,    49,    50,
      48,    25,    26,    27,    24,    30,    29,    34,    35,    32,
      33,    37,    38,    40,    42,     0,    84,     0,   106,   105,
      99,   101,    52,    16,    45,     0,     0,     0,     0,   107,
       0,    86,   108,    46,     0,     0,     0,     0,     0,    92,
       0,    88,   109,    90,     0,     0,    96,    87,    89,     0,
       0,     0,    94,     0,   110,     0,    93,     0,     0,     0,
      91,     0,    97,   111,    95
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -157,  -157,  -157,   156,  -157,   -63,  -157,   126,   133,   134,
     136,   142,  -157,  -156,  -157,  -157,   -35,   -45,     6,  -157,
     208,   -19,   188,  -157,   219,   -22,   218,  -157,   173,  -157,
    -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
     210,    30,  -115,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
    -157,   241
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,    27,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,   106,   157,    82,   112,   113,    20,
      21,    37,     9,    10,    32,    33,    34,    48,    49,   114,
     115,   147,   164,   170,   171,   180,   174,   178,   187,   183,
     116,   117,   118,   119,   120,   156,   162,   165,   179,   189,
      11,    12
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      92,    71,   151,    16,   163,    18,     8,    35,    13,    46,
      45,    36,   173,    15,    83,    22,    14,     8,     1,   182,
      45,    28,     1,    51,    52,    53,    54,    76,    55,   105,
     131,   132,   133,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   127,     2,     3,     4,     5,     2,     3,
       4,     5,    17,    19,   128,   129,   130,    47,   -44,     6,
     122,    29,    59,     6,    89,    90,    40,   175,   176,   151,
     153,   151,    38,    39,   124,   151,    41,   151,    50,   151,
      51,    52,    53,    54,   123,    55,    56,    57,   177,   152,
      18,   124,   161,    91,    96,    97,    58,   134,    73,   124,
     154,    51,    52,    53,    54,   134,    55,    56,    57,    35,
     158,   159,   134,    24,    25,    26,    79,    58,   104,    59,
      93,    94,    95,     2,    30,     4,     5,    46,   107,   108,
      51,    52,    53,    54,   125,    55,    56,    57,     6,   109,
      59,    84,    85,    77,    78,   146,    58,   102,   103,   110,
      73,   111,     2,    30,     4,     5,   126,   107,   108,    51,
      52,    53,    54,   145,    55,    56,    57,     6,   109,    59,
       2,    30,     4,     5,    86,    58,    87,    88,   110,    73,
     150,     2,    30,     4,     5,     6,   107,   108,     2,    30,
       4,     5,   124,   149,   168,   169,     6,   109,    59,     2,
      30,     4,     5,     6,   124,    31,   148,   110,    73,   184,
     155,   186,    80,    81,     6,   190,    44,    31,   192,    31,
      31,   194,   135,   136,    98,    99,   160,    75,   100,   101,
      31,   137,   138,   139,   140,   166,   141,   142,   167,   172,
     143,   181,   185,   193,   188,   191,    72,   144,    42,    43,
     121,    74,    23
};

static const yytype_uint8 yycheck[] =
{
      63,    36,   117,     7,   160,     7,     0,    49,    11,     7,
      32,    53,   168,    33,    59,     0,    19,    11,     3,   175,
      42,    46,     3,     7,     8,     9,    10,    46,    12,    22,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,    88,    29,    30,    31,    32,    29,    30,
      31,    32,    56,    55,    89,    90,    91,    55,    51,    44,
      79,    56,    46,    44,    24,    25,    20,    36,    37,   184,
      50,   186,    54,    55,    54,   190,    47,   192,     8,   194,
       7,     8,     9,    10,    47,    12,    13,    14,    57,   124,
       7,    54,    47,    53,    39,    40,    23,   160,    56,    54,
     145,     7,     8,     9,    10,   168,    12,    13,    14,    49,
     155,   156,   175,     4,     5,     6,    50,    23,    21,    46,
      41,    42,    43,    29,    30,    31,    32,     7,    34,    35,
       7,     8,     9,    10,    47,    12,    13,    14,    44,    45,
      46,    13,    14,    54,    55,    55,    23,    17,    18,    55,
      56,    57,    29,    30,    31,    32,     7,    34,    35,     7,
       8,     9,    10,    51,    12,    13,    14,    44,    45,    46,
      29,    30,    31,    32,    46,    23,    48,    49,    55,    56,
      57,    29,    30,    31,    32,    44,    34,    35,    29,    30,
      31,    32,    54,    55,    36,    37,    44,    45,    46,    29,
      30,    31,    32,    44,    54,    17,    46,    55,    56,   179,
      46,   181,    56,    57,    44,   185,    57,    29,   188,    31,
      32,   191,    96,    97,    15,    16,    52,    57,    19,    20,
      42,    98,    99,   100,   101,    56,   102,   103,    47,    56,
     104,    52,    52,    57,    52,    52,    38,   105,    29,    31,
      77,    41,    11
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    29,    30,    31,    32,    44,    59,    76,    80,
      81,   108,   109,    11,    19,    33,     7,    56,     7,    55,
      77,    78,     0,   109,     4,     5,     6,    60,    46,    56,
      30,    80,    82,    83,    84,    49,    53,    79,    54,    55,
      20,    47,    82,    84,    57,    83,     7,    55,    85,    86,
       8,     7,     8,     9,    10,    12,    13,    14,    23,    46,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    74,    78,    56,    98,    57,    79,    54,    55,    50,
      61,    61,    74,    75,    13,    14,    46,    48,    49,    24,
      25,    53,    63,    41,    42,    43,    39,    40,    15,    16,
      19,    20,    17,    18,    21,    22,    72,    34,    35,    45,
      55,    57,    75,    76,    87,    88,    98,    99,   100,   101,
     102,    86,    79,    47,    54,    47,     7,    75,    74,    74,
      74,    63,    63,    63,    63,    65,    65,    66,    66,    66,
      66,    67,    67,    68,    69,    51,    55,    89,    46,    55,
      57,   100,    74,    50,    75,    46,   103,    73,    75,    75,
      52,    47,   104,    71,    90,   105,    56,    47,    36,    37,
      91,    92,    56,    71,    94,    36,    37,    57,    95,   106,
      93,    52,    71,    97,    99,    52,    99,    96,    52,   107,
      99,    52,    99,    57,    99
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    59,    60,    60,    60,    61,    61,    61,
      61,    61,    61,    62,    62,    62,    62,    62,    62,    62,
      62,    63,    63,    64,    65,    65,    65,    65,    66,    66,
      66,    67,    67,    67,    67,    67,    68,    68,    68,    69,
      69,    70,    70,    71,    72,    73,    71,    74,    74,    74,
      74,    75,    75,    76,    76,    77,    77,    78,    78,    78,
      79,    79,    80,    80,    80,    80,    80,    81,    81,    81,
      82,    82,    83,    83,    84,    84,    85,    85,    86,    86,
      87,    87,    87,    87,    87,    89,    90,    88,    91,    91,
      93,    92,    94,    92,    96,    95,    97,    95,    98,    98,
      99,    99,   100,   100,   101,   101,   103,   104,   105,   106,
     107,   102,   108,   108,   109,   109,   109
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     3,     3,     4,     2,     2,     2,
       2,     1,     2,     1,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     0,     0,     7,     1,     3,     3,
       3,     1,     3,     2,     3,     1,     3,     1,     3,     2,
       4,     3,     1,     1,     1,     1,     1,     4,     5,     2,
       1,     2,     2,     3,     2,     1,     1,     3,     1,     2,
       1,     1,     1,     1,     2,     0,     0,     9,     1,     2,
       0,     5,     0,     4,     0,     5,     0,     4,     2,     3,
       1,     2,     1,     1,     1,     2,     0,     0,     0,     0,
       0,    12,     1,     2,     5,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 7:
#line 81 "ICG.y"
                        {push((yyvsp[0].string)); strcpy((yyval.string), (yyvsp[0].string));}
#line 1596 "y.tab.c"
    break;

  case 8:
#line 82 "ICG.y"
                          {push((yyvsp[0].string)); strcpy((yyval.string), (yyvsp[0].string));}
#line 1602 "y.tab.c"
    break;

  case 9:
#line 83 "ICG.y"
                        {push((yyvsp[0].string)); strcpy((yyval.string), (yyvsp[0].string));}
#line 1608 "y.tab.c"
    break;

  case 10:
#line 84 "ICG.y"
                         {push((yyvsp[0].string)); strcpy((yyval.string), (yyvsp[0].string));}
#line 1614 "y.tab.c"
    break;

  case 11:
#line 85 "ICG.y"
                             {strcpy((yyval.string), (yyvsp[-1].string));}
#line 1620 "y.tab.c"
    break;

  case 12:
#line 86 "ICG.y"
                        {push((yyvsp[0].string)); strcpy((yyval.string), (yyvsp[0].string));}
#line 1626 "y.tab.c"
    break;

  case 13:
#line 89 "ICG.y"
                                {strcpy((yyval.string), (yyvsp[0].string));}
#line 1632 "y.tab.c"
    break;

  case 15:
#line 91 "ICG.y"
                                            {char buff[20];strcpy(buff,(yyvsp[-2].string));strcat(buff,".");strcat(buff,(yyvsp[0].string));strcpy((yyval.string),buff);push(buff);}
#line 1638 "y.tab.c"
    break;

  case 17:
#line 93 "ICG.y"
                                    {push((yyvsp[-1].string)); push("1"); arithmetic_gen("+"); fprintf(outfile, "%s = %s\n", pop(), pop());}
#line 1644 "y.tab.c"
    break;

  case 18:
#line 94 "ICG.y"
                                    {push((yyvsp[-1].string)); push("1"); arithmetic_gen("-"); fprintf(outfile, "%s = %s\n", pop(), pop());}
#line 1650 "y.tab.c"
    break;

  case 19:
#line 95 "ICG.y"
                                    {push((yyvsp[0].string)); push("1"); arithmetic_gen("+"); fprintf(outfile, "%s = %s\n", pop(), pop());}
#line 1656 "y.tab.c"
    break;

  case 20:
#line 96 "ICG.y"
                                    {push((yyvsp[0].string)); push("1"); arithmetic_gen("-"); fprintf(outfile, "%s = %s\n", pop(), pop());}
#line 1662 "y.tab.c"
    break;

  case 21:
#line 99 "ICG.y"
                                {strcpy((yyval.string), (yyvsp[0].string));}
#line 1668 "y.tab.c"
    break;

  case 22:
#line 100 "ICG.y"
                                          {char temp[5]; strcpy(temp, pop()); push("0"); push(temp); arithmetic_gen((yyvsp[-1].string));}
#line 1674 "y.tab.c"
    break;

  case 25:
#line 107 "ICG.y"
                                                         {arithmetic_gen("*");}
#line 1680 "y.tab.c"
    break;

  case 26:
#line 108 "ICG.y"
                                                         {arithmetic_gen("/");}
#line 1686 "y.tab.c"
    break;

  case 27:
#line 109 "ICG.y"
                                                         {arithmetic_gen("%");}
#line 1692 "y.tab.c"
    break;

  case 29:
#line 113 "ICG.y"
                                                            {arithmetic_gen("+");}
#line 1698 "y.tab.c"
    break;

  case 30:
#line 114 "ICG.y"
                                                            {arithmetic_gen("-");}
#line 1704 "y.tab.c"
    break;

  case 32:
#line 118 "ICG.y"
                                                       {arithmetic_gen("<");}
#line 1710 "y.tab.c"
    break;

  case 33:
#line 119 "ICG.y"
                                                       {arithmetic_gen(">");}
#line 1716 "y.tab.c"
    break;

  case 34:
#line 120 "ICG.y"
                                                          {arithmetic_gen("<=");}
#line 1722 "y.tab.c"
    break;

  case 35:
#line 121 "ICG.y"
                                                          {arithmetic_gen(">=");}
#line 1728 "y.tab.c"
    break;

  case 37:
#line 125 "ICG.y"
                                                          {arithmetic_gen("==");}
#line 1734 "y.tab.c"
    break;

  case 38:
#line 126 "ICG.y"
                                                          {arithmetic_gen("!=");}
#line 1740 "y.tab.c"
    break;

  case 40:
#line 131 "ICG.y"
                                                            {arithmetic_gen("&&");}
#line 1746 "y.tab.c"
    break;

  case 42:
#line 136 "ICG.y"
                                                             {arithmetic_gen("||");}
#line 1752 "y.tab.c"
    break;

  case 44:
#line 141 "ICG.y"
                                         {fprintf(outfile, "ifFalse %s goto L%d\n", pop(), ++label); char temp[5]; sprintf(temp, "t%d", temp_no++); push(temp);}
#line 1758 "y.tab.c"
    break;

  case 45:
#line 141 "ICG.y"
                                                                                                                                                                                {gen_true_code();}
#line 1764 "y.tab.c"
    break;

  case 46:
#line 141 "ICG.y"
                                                                                                                                                                                                                              {gen_false_code();}
#line 1770 "y.tab.c"
    break;

  case 48:
#line 145 "ICG.y"
                                                      {fprintf(outfile, "%s = %s\n", pop(), pop());}
#line 1776 "y.tab.c"
    break;

  case 49:
#line 146 "ICG.y"
                                                             {arithmetic_gen("+"); fprintf(outfile, "%s = %s\n", (yyvsp[-2].string), pop());}
#line 1782 "y.tab.c"
    break;

  case 50:
#line 147 "ICG.y"
                                                             {arithmetic_gen("-"); fprintf(outfile, "%s = %s\n", (yyvsp[-2].string), pop());}
#line 1788 "y.tab.c"
    break;

  case 57:
#line 165 "ICG.y"
                     {push((yyvsp[0].string)); strcpy((yyval.string), (yyvsp[0].string));}
#line 1794 "y.tab.c"
    break;

  case 58:
#line 166 "ICG.y"
                                               {push((yyvsp[-2].string));strcpy((yyval.string), (yyvsp[-2].string));fprintf(outfile, "%s = %s\n", pop(), pop());}
#line 1800 "y.tab.c"
    break;

  case 84:
#line 213 "ICG.y"
                    {fprintf(outfile," goto %s_%d\n  ",label_stack.items[label_stack.top],switch_counter-1);}
#line 1806 "y.tab.c"
    break;

  case 85:
#line 217 "ICG.y"
          {switch_counter++;}
#line 1812 "y.tab.c"
    break;

  case 86:
#line 217 "ICG.y"
                                                { label_push(label);label++;}
#line 1818 "y.tab.c"
    break;

  case 87:
#line 217 "ICG.y"
                                                                                                      {switch_counter--;fprintf(outfile, " %s_%d :", label_pop(),switch_counter);pop();}
#line 1824 "y.tab.c"
    break;

  case 90:
#line 225 "ICG.y"
                              {fprintf(outfile, " L_case%d_%d  : ifFalse %s = %s goto L_case%d_%d \n",label,switch_counter,top(0),pop(),label+1,switch_counter);++label;}
#line 1830 "y.tab.c"
    break;

  case 92:
#line 226 "ICG.y"
          {fprintf(outfile, " L_case%d_%d :", label,switch_counter);}
#line 1836 "y.tab.c"
    break;

  case 93:
#line 226 "ICG.y"
                                                                                          { fprintf(outfile, " goto %s_%d\n", label_stack.items[label_stack.top],switch_counter-1);}
#line 1842 "y.tab.c"
    break;

  case 94:
#line 229 "ICG.y"
                              {fprintf(outfile, " L_case%d_%d  : ifFalse %s = %s goto %s_%d \n ",label,switch_counter,top(0),pop(),label_stack.items[label_stack.top],switch_counter-1);++label;}
#line 1848 "y.tab.c"
    break;

  case 96:
#line 230 "ICG.y"
          {fprintf(outfile, " L_case%d_%d :", label,switch_counter);}
#line 1854 "y.tab.c"
    break;

  case 97:
#line 230 "ICG.y"
                                                                                          { fprintf(outfile, " goto %s_%d\n", label_stack.items[label_stack.top],switch_counter-1);}
#line 1860 "y.tab.c"
    break;

  case 106:
#line 250 "ICG.y"
          {fprintf(outfile, " L%d :", ++label1);}
#line 1866 "y.tab.c"
    break;

  case 107:
#line 250 "ICG.y"
                                                             {fprintf(outfile, "ifFalse %s  goto L%d\ngoto L%d \n", pop(), label1+2, label1+1);
label_push1(label1);
label_push1(label1+2); 
label_push1(label1+1);}
#line 1875 "y.tab.c"
    break;

  case 108:
#line 254 "ICG.y"
{ label1 += 2;}
#line 1881 "y.tab.c"
    break;

  case 109:
#line 255 "ICG.y"
          {fprintf(outfile, " %s :\n",label_pop());}
#line 1887 "y.tab.c"
    break;

  case 110:
#line 255 "ICG.y"
                                                                    {fprintf(outfile, " goto %s\n%s : \n",label_pop(), label_pop());}
#line 1893 "y.tab.c"
    break;


#line 1897 "y.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 267 "ICG.y"

void yyerror(const char *str)
{
	fflush(stdout);
	extern int yylineno;
	fprintf(stderr, "%s at line %d\n", str,yylineno);
}
int main(){
	stack.top = -1;
	push("$");
	outfile = fopen("output_file.txt", "w");
	if (yyparse() != 0)
	{
		printf("Parse failed\n");
		exit(0);
	}
	printf("success\n");
	int i = 0;
	fclose(outfile);
	system("cat output_file.txt");
	return 0;
}
void push(char *str)
{
	stack.items[++stack.top] = (char*)malloc(LIMIT);
	strcpy(stack.items[stack.top], str);
    //display_stack();
}
char *pop()
{
	if (stack.top <= -1) {
		printf("\nError in evaluating expression\n");
		exit(0);
	}
	char *str = (char*)malloc(LIMIT);
	strcpy(str, stack.items[stack.top--]);
	free(stack.items[stack.top+1]);
    //display_stack();
	return str;
}


char *top(int off)
{
	return stack.items[stack.top-off];
}
void arithmetic_gen(char op[5])
{
	char temp[5];
	sprintf(temp,"t%d",temp_no++);
  	fprintf(outfile,"%s = %s %s %s\n",temp,top(1),op,top(0));
	pop(); pop(); push(temp);
}

void display_stack()
{
	int i;
	for(i=0; i<=stack.top; i++)
		printf("%s ", stack.items[i]);
	printf("\n");
}

void label_push(int label)
{
	
	char temp[5];
	//fprintf(outfile,"LABEL BEFORE PUSH : %s  %d \n",label_stack.items[label_stack.top],label_stack.top);
	sprintf(temp, "L_case%d", label);
	label_stack.items[++label_stack.top] = malloc(LIMIT);
	strcpy(label_stack.items[label_stack.top], temp);
	//fprintf(outfile,"LABEL AFTER PUSH : %s  %d \n",label_stack.items[label_stack.top],label_stack.top);
	
}
void label_push1(int label)
{
	
	char temp[5];
	//fprintf(outfile,"LABEL BEFORE PUSH : %s  %d \n",label_stack.items[label_stack.top],label_stack.top);
	sprintf(temp, "L%d", label);
	label_stack.items[++label_stack.top] = malloc(LIMIT);
	strcpy(label_stack.items[label_stack.top], temp);
	//fprintf(outfile,"LABEL AFTER PUSH : %s  %d \n",label_stack.items[label_stack.top],label_stack.top);
	
}
char *label_pop()
{
	if (label_stack.top <= -1) {
		printf("\nError in evaluating expression\n");
		exit(0);
	}
	//fprintf(outfile,"LABEL BEFORE POP : %s  %d \n",label_stack.items[label_stack.top],label_stack.top);
	char *str = (char*)malloc(LIMIT);
	strcpy(str, label_stack.items[label_stack.top--]);
	free(label_stack.items[label_stack.top+1]);
	//fprintf(outfile,"LABEL AFTER POP : %s  %d \n",label_stack.items[label_stack.top],label_stack.top);
	return str;
}






void gen_true_code()
{
	if (stack.top > -1)
	{
		fprintf(outfile, "%s = %s\ngoto L%d\n", top(0), pop(), label+1);
		label_push(label+1);
		fprintf(outfile, "L%d :\n", label);
		label_push(label+1);
	}
	else
		fprintf(outfile, "%s\ngoto L%d\n", pop(), ++label);
}
void gen_false_code()
{
	if (stack.top > -1)
	{
		fprintf(outfile, "%s = %s\ngoto %s\n", top(0), pop(), label_pop());
		fprintf(outfile, "%s :\n", label_pop());
		label++;
	}
	else
		fprintf(outfile, "%s\ngoto L%d\n", pop(), label-1);
}
