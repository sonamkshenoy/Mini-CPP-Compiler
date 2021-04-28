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
#line 1 "parser.y"

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#define YYSTYPE char *

	int yylex(void);
	void yyerror(char *);


	// Symbol table node structure

	typedef struct entry{
        int scope;
        int value;
        char name[100];
        char datatype[50];
        int line_no;
        int valid;
    }entry;

    entry symbolTable[1000];


    // Number of records (identifiers) in the symbol table
    int numRecords = 0;

    // Scope and line number updated in lex file, used to update here, in yacc file
    extern int current_scope;
    extern int yylineno;


    char currentTypeName[100];
	int inInitDeclarator = 0;


    // Symbol table Function declarations
    void updateSymbolTable(char* name, char* value, int scope);
	int findInSymbolTable(int scope, char *name);
	void displaySymbolTable();
	int insertInSymbolTable(int* count, int scope, char *datatype, char* name, int line_no, char* value);
	extern void incrementScope();
	extern void decrementScope();
	int doOperation(char* first, char* second, char op, int scope);


#line 117 "y.tab.c"

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
    T_IDENTIFIER = 258,
    T_CONSTANT = 259,
    T_STRING_LITERAL = 260,
    T_PTR_OP = 261,
    T_INC_OP = 262,
    T_DEC_OP = 263,
    T_LE_OP = 264,
    T_GE_OP = 265,
    T_EQ_OP = 266,
    T_NE_OP = 267,
    T_AND_OP = 268,
    T_OR_OP = 269,
    T_CHAR = 270,
    T_INT = 271,
    T_FLOAT = 272,
    T_DOUBLE = 273,
    T_VOID = 274,
    T_CLASS = 275,
    T_PUBLIC = 276,
    T_PRIVATE = 277,
    T_ELLIPSIS = 278,
    T_CASE = 279,
    T_DEFAULT = 280,
    T_IF = 281,
    T_ELSE = 282,
    T_SWITCH = 283,
    T_WHILE = 284,
    T_FOR = 285,
    T_BREAK = 286,
    T_CONTINUE = 287,
    T_RETURN = 288,
    T_IFX = 289
  };
#endif
/* Tokens.  */
#define T_IDENTIFIER 258
#define T_CONSTANT 259
#define T_STRING_LITERAL 260
#define T_PTR_OP 261
#define T_INC_OP 262
#define T_DEC_OP 263
#define T_LE_OP 264
#define T_GE_OP 265
#define T_EQ_OP 266
#define T_NE_OP 267
#define T_AND_OP 268
#define T_OR_OP 269
#define T_CHAR 270
#define T_INT 271
#define T_FLOAT 272
#define T_DOUBLE 273
#define T_VOID 274
#define T_CLASS 275
#define T_PUBLIC 276
#define T_PRIVATE 277
#define T_ELLIPSIS 278
#define T_CASE 279
#define T_DEFAULT 280
#define T_IF 281
#define T_ELSE 282
#define T_SWITCH 283
#define T_WHILE 284
#define T_FOR 285
#define T_BREAK 286
#define T_CONTINUE 287
#define T_RETURN 288
#define T_IFX 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
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
#define YYFINAL  33
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   748

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  144
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  256

#define YYUNDEFTOK  2
#define YYMAXUTOK   289


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
       2,     2,     2,    46,     2,     2,     2,    48,    41,     2,
      35,    36,    42,    43,    40,    44,    39,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    54,    56,
      49,    55,    50,    53,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,    51,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,    52,    58,    45,     2,     2,     2,
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
static const yytype_int16 yyrline[] =
{
       0,    66,    66,    71,    72,    73,    77,    78,    79,    80,
      81,    82,    83,    87,    88,    92,    93,    94,    95,    99,
     100,   101,   102,   103,   104,   108,   109,   113,   117,   124,
     125,   129,   136,   140,   141,   145,   149,   153,   160,   161,
     165,   172,   173,   180,   181,   188,   189,   196,   197,   204,
     205,   212,   213,   228,   236,   240,   244,   245,   249,   253,
     254,   258,   259,   263,   264,   268,   274,   283,   284,   285,
     286,   287,   291,   295,   296,   297,   298,   299,   300,   301,
     305,   306,   310,   311,   315,   316,   320,   321,   337,   338,
     342,   343,   347,   348,   352,   353,   354,   355,   356,   357,
     358,   362,   363,   364,   365,   366,   367,   368,   372,   373,
     377,   378,   382,   383,   387,   388,   389,   393,   394,   398,
     399,   403,   404,   405,   409,   410,   411,   415,   416,   420,
     421,   425,   426,   427,   428,   432,   433,   434,   435,   439,
     440,   441,   442,   446,   447
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_IDENTIFIER", "T_CONSTANT",
  "T_STRING_LITERAL", "T_PTR_OP", "T_INC_OP", "T_DEC_OP", "T_LE_OP",
  "T_GE_OP", "T_EQ_OP", "T_NE_OP", "T_AND_OP", "T_OR_OP", "T_CHAR",
  "T_INT", "T_FLOAT", "T_DOUBLE", "T_VOID", "T_CLASS", "T_PUBLIC",
  "T_PRIVATE", "T_ELLIPSIS", "T_CASE", "T_DEFAULT", "T_IF", "T_ELSE",
  "T_SWITCH", "T_WHILE", "T_FOR", "T_BREAK", "T_CONTINUE", "T_RETURN",
  "T_IFX", "'('", "')'", "'['", "']'", "'.'", "','", "'&'", "'*'", "'+'",
  "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'",
  "':'", "'='", "';'", "'{'", "'}'", "$accept", "primary_expression",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "unary_operator", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "type_specifier", "declarator", "direct_declarator",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "all_statement", "single_statement", "statement",
  "simple_statement", "compound_statement", "declaration_list",
  "statement_list", "expression_statement", "selection_statement",
  "switch_block", "case_list", "case_statement", "iteration_statement",
  "member", "class_member", "function_definition", "class_declarartion",
  "external_declaration", "S", YY_NULLPTR
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
     285,   286,   287,   288,   289,    40,    41,    91,    93,    46,
      44,    38,    42,    43,    45,   126,    33,    47,    37,    60,
      62,    94,   124,    63,    58,    61,    59,   123,   125
};
# endif

#define YYPACT_NINF (-179)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     692,  -179,  -179,  -179,  -179,  -179,  -179,  -179,    18,    24,
    -179,    58,   243,   119,    30,  -179,  -179,  -179,   671,   -16,
       9,  -179,    -1,  -179,   208,  -179,   238,  -179,    58,  -179,
     119,   662,   586,  -179,  -179,    21,  -179,    24,  -179,   659,
    -179,   119,  -179,  -179,  -179,   659,   659,    19,    42,    59,
      62,    86,    96,   541,   659,  -179,  -179,  -179,  -179,  -179,
    -179,  -179,  -179,  -179,   212,    31,   659,   230,    25,  -179,
      72,   263,   113,   106,   115,   152,     0,  -179,  -179,    84,
    -179,  -179,  -179,   282,   326,  -179,  -179,  -179,  -179,   124,
    -179,  -179,  -179,  -179,    24,   158,   156,  -179,    51,  -179,
    -179,  -179,   167,   153,   174,   176,  -179,  -179,  -179,  -179,
    -179,   659,   659,   659,   570,  -179,  -179,  -179,    85,    90,
    -179,  -179,   599,   659,   209,  -179,   659,  -179,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,  -179,  -179,   370,  -179,
    -179,   414,  -179,  -179,   198,  -179,   231,  -179,   713,   713,
    -179,    91,    93,   103,   570,  -179,  -179,  -179,   108,  -179,
      80,  -179,  -179,  -179,  -179,  -179,   230,   230,  -179,  -179,
    -179,  -179,    72,    72,   263,   113,   106,   115,   152,   -10,
    -179,  -179,    32,  -179,   142,  -179,  -179,  -179,  -179,  -179,
      57,  -179,   447,   480,   182,   480,   615,  -179,   659,  -179,
     659,  -179,  -179,   188,  -179,   194,   196,  -179,   223,  -179,
    -179,  -179,   252,  -179,   480,   155,  -179,  -179,  -179,   713,
    -179,   480,   284,    38,  -179,   480,   458,  -179,   239,   302,
     253,  -179,  -179,   260,   524,   255,   524,  -179,   524,  -179,
    -179,   524,   262,  -179,  -179,  -179
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   142,    73,    68,    69,    70,    71,    67,     0,     0,
     140,     0,    62,     0,    72,   139,   141,   144,     0,     0,
       0,    60,     0,    64,    66,    61,     0,   109,     0,   134,
       0,     0,     0,     1,   143,     0,    74,     0,    59,     0,
     132,     0,     2,     3,     4,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,    20,    21,    22,    23,
      24,   112,   107,     6,    15,    25,     0,    29,    32,    33,
      38,    41,    43,    45,    47,    49,    51,    54,    57,     0,
     111,    93,    92,     0,     0,    94,    95,   116,    96,    66,
     108,   133,    87,    79,    85,     0,    80,    82,     0,    76,
      25,    58,     0,     0,     0,     0,    63,    65,   131,    16,
      17,     0,     0,     0,     0,    97,    98,   100,     0,     0,
      11,    12,     0,     0,     0,    55,     0,    18,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   113,   105,     0,   106,
     110,     0,    84,    77,     0,    78,     0,    75,     0,     0,
     138,     0,     0,     0,     0,    99,     5,     8,     0,    14,
       0,    10,    53,    26,    27,    28,    30,    31,    36,    37,
      34,    35,    39,    40,    42,    44,    46,    48,    50,     0,
      56,   104,     0,   103,     0,    81,    83,    86,   128,   130,
       0,   127,     0,     0,     0,     0,     0,     9,     0,     7,
       0,   101,   102,     0,   129,     0,     0,    90,   114,    88,
      91,    89,     0,   124,     0,     0,    13,    52,   137,     0,
     136,     0,     0,     0,   125,     0,     0,   115,     0,     0,
       0,   118,   126,     0,     0,     0,     0,   135,   122,   123,
     120,     0,     0,   121,   119,   117
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -179,  -179,  -179,  -179,   -30,  -179,   160,  -179,   169,   181,
     183,   192,   180,   193,   203,  -179,   -29,   -89,  -179,   -28,
    -179,     5,     1,  -179,   299,  -179,    29,  -179,  -179,  -179,
     195,  -179,   -73,  -179,   -77,   -42,   -13,   -20,   -71,   -94,
    -179,  -179,  -179,   -82,  -179,  -178,  -151,    34,  -179,   319,
    -179
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    63,    64,   168,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,   126,    79,
     102,   198,    28,    22,    23,    12,    13,    14,    95,    96,
      97,    98,   218,   219,    80,    81,    82,    30,    84,    85,
      86,    87,   233,   250,    88,   199,   200,   201,    16,    17,
      18
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      29,    11,   100,   101,    41,    10,    83,   150,   202,   100,
     107,    40,   148,    25,   143,   109,   110,    91,    27,    11,
     164,    19,   214,    10,   214,   118,   119,     2,   108,    27,
     145,    27,    94,   169,    15,    90,   127,   172,    20,    37,
      24,    35,   103,   104,   210,    36,    90,     3,     4,     5,
       6,     7,    15,   144,   111,    38,   190,    89,   214,     9,
       2,     2,   239,   240,   151,    31,    89,    32,   131,   132,
     206,   150,     3,     4,     5,     6,     7,   112,   236,   105,
     194,   133,   134,   161,   162,   163,   125,   155,    90,    27,
     211,   156,     9,     9,   113,   170,   241,   114,   173,   174,
     175,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,    21,   213,   189,   150,   209,   226,
     145,   135,   136,   152,   145,   145,   166,   203,   192,   204,
     145,   145,   223,   145,     3,     4,     5,     6,     7,   205,
     146,   165,   115,   145,   207,    42,    43,    44,   208,    45,
      46,   234,   116,    27,   139,    94,    90,   140,   237,    11,
      11,   220,   242,   220,   252,   142,   253,   141,    47,   254,
      48,    49,    50,    51,    52,    53,    26,    54,   225,    39,
     100,   227,   220,    55,    56,    57,    58,    59,    60,   220,
     221,   235,   221,   220,   153,   145,   154,    90,    61,    26,
     212,    11,   248,    11,   248,   157,   248,   158,   217,   248,
     217,   221,   171,     3,     4,     5,     6,     7,   221,   120,
     121,   195,   221,     3,     4,     5,     6,     7,   159,   217,
      11,   249,   160,   249,   197,   249,   217,    11,   249,   222,
     217,    42,    43,    44,   228,    45,    46,   122,   229,   123,
     231,   124,   230,     3,     4,     5,     6,     7,     3,     4,
       5,     6,     7,    39,    47,    26,    48,    49,    50,    51,
      52,    53,   128,    54,   137,   138,   232,   129,   130,    55,
      56,    57,    58,    59,    60,    42,    43,    44,   238,    45,
      46,   176,   177,   244,    61,    26,    62,     3,     4,     5,
       6,     7,   178,   179,   180,   181,   245,   246,    47,   251,
      48,    49,    50,    51,    52,    53,   247,    54,   182,   183,
     255,   186,   184,    55,    56,    57,    58,    59,    60,    42,
      43,    44,   185,    45,    46,   187,   106,    34,    61,    26,
     147,     3,     4,     5,     6,     7,   188,     0,     0,   196,
       0,     0,    47,     0,    48,    49,    50,    51,    52,    53,
       0,    54,     0,     0,     0,     0,     0,    55,    56,    57,
      58,    59,    60,    42,    43,    44,     0,    45,    46,     0,
       0,     0,    61,    26,   149,     3,     4,     5,     6,     7,
       0,     0,     0,     0,     0,     0,    47,     0,    48,    49,
      50,    51,    52,    53,     0,    54,     0,     0,     0,     0,
       0,    55,    56,    57,    58,    59,    60,    42,    43,    44,
       0,    45,    46,     0,     0,     0,    61,    26,   191,     3,
       4,     5,     6,     7,     0,     0,     0,     0,     0,     0,
      47,     0,    48,    49,    50,    51,    52,    53,     0,    54,
       2,     0,     0,     0,     0,    55,    56,    57,    58,    59,
      60,     2,     3,     4,     5,     6,     7,     0,   215,     0,
      61,    26,   193,     3,     4,     5,     6,     7,     0,     0,
       0,     0,     9,    42,    43,    44,     0,    45,    46,     0,
       0,     0,     0,     9,     0,     3,     4,     5,     6,     7,
       0,     0,     0,     0,     0,   216,    47,     0,    48,    49,
      50,    51,    52,    53,     0,    54,   243,     0,     0,     0,
       0,    55,    56,    57,    58,    59,    60,    42,    43,    44,
       0,    45,    46,     0,     0,     0,    61,    26,     0,     0,
       0,     0,     0,     0,    42,    43,    44,     0,    45,    46,
      47,     0,    48,    49,    50,    51,    52,    53,     0,    54,
       0,     0,     0,     0,     0,    55,    56,    57,    58,    59,
      60,     0,     0,    42,    43,    44,    54,    45,    46,     0,
      61,    26,    55,    56,    57,    58,    59,    60,     0,    42,
      43,    44,     0,    45,    46,     0,     0,   117,     0,     0,
       0,     0,    42,    43,    44,    54,    45,    46,     0,     0,
       0,    55,    56,    57,    58,    59,    60,     0,    42,    43,
      44,    54,    45,    46,    99,     0,    61,    55,    56,    57,
      58,    59,    60,     0,    54,   167,     0,     0,     0,     0,
      55,    56,    57,    58,    59,    60,     0,     0,     0,     0,
      54,   224,     0,     0,     0,     0,    55,    56,    57,    58,
      59,    60,    42,    43,    44,    92,    45,    46,     0,     0,
       0,    33,     1,     0,     2,     0,     0,     3,     4,     5,
       6,     7,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     0,     1,    54,     2,     0,     0,    93,     0,
      55,    56,    57,    58,    59,    60,     9,     3,     4,     5,
       6,     7,     8,     0,     0,     0,     2,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     9,     3,     4,
       5,     6,     7,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     9
};

static const yytype_int16 yycheck[] =
{
      13,     0,    32,    32,    24,     0,    26,    84,   159,    39,
      39,    24,    83,    12,    14,    45,    46,    30,    13,    18,
     114,     3,   200,    18,   202,    53,    54,     3,    41,    24,
      40,    26,    31,   122,     0,    30,    66,   126,     9,    40,
      11,    57,    21,    22,    54,    36,    41,    15,    16,    17,
      18,    19,    18,    53,    35,    56,   145,    28,   236,    35,
       3,     3,    24,    25,    84,    35,    37,    37,    43,    44,
     164,   148,    15,    16,    17,    18,    19,    35,   229,    58,
     151,     9,    10,   111,   112,   113,    55,    36,    83,    84,
      58,    40,    35,    35,    35,   123,    58,    35,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    56,    58,   144,   194,    38,   208,
      40,    49,    50,    94,    40,    40,    36,    36,   148,    36,
      40,    40,   205,    40,    15,    16,    17,    18,    19,    36,
      56,    56,    56,    40,    36,     3,     4,     5,    40,     7,
       8,   224,    56,   148,    41,   154,   151,    51,   231,   158,
     159,   203,   235,   205,   246,    13,   248,    52,    26,   251,
      28,    29,    30,    31,    32,    33,    57,    35,   206,    55,
     210,   210,   224,    41,    42,    43,    44,    45,    46,   231,
     203,    36,   205,   235,    36,    40,    40,   192,    56,    57,
      58,   200,   244,   202,   246,    38,   248,    54,   203,   251,
     205,   224,     3,    15,    16,    17,    18,    19,   231,     7,
       8,    23,   235,    15,    16,    17,    18,    19,    54,   224,
     229,   244,    56,   246,     3,   248,   231,   236,   251,    57,
     235,     3,     4,     5,    56,     7,     8,    35,    54,    37,
      27,    39,    56,    15,    16,    17,    18,    19,    15,    16,
      17,    18,    19,    55,    26,    57,    28,    29,    30,    31,
      32,    33,    42,    35,    11,    12,    24,    47,    48,    41,
      42,    43,    44,    45,    46,     3,     4,     5,     4,     7,
       8,   131,   132,    54,    56,    57,    58,    15,    16,    17,
      18,    19,   133,   134,   135,   136,     4,    54,    26,    54,
      28,    29,    30,    31,    32,    33,    56,    35,   137,   138,
      58,   141,   139,    41,    42,    43,    44,    45,    46,     3,
       4,     5,   140,     7,     8,   142,    37,    18,    56,    57,
      58,    15,    16,    17,    18,    19,   143,    -1,    -1,   154,
      -1,    -1,    26,    -1,    28,    29,    30,    31,    32,    33,
      -1,    35,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,
      44,    45,    46,     3,     4,     5,    -1,     7,     8,    -1,
      -1,    -1,    56,    57,    58,    15,    16,    17,    18,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    28,    29,
      30,    31,    32,    33,    -1,    35,    -1,    -1,    -1,    -1,
      -1,    41,    42,    43,    44,    45,    46,     3,     4,     5,
      -1,     7,     8,    -1,    -1,    -1,    56,    57,    58,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    28,    29,    30,    31,    32,    33,    -1,    35,
       3,    -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      46,     3,    15,    16,    17,    18,    19,    -1,    21,    -1,
      56,    57,    58,    15,    16,    17,    18,    19,    -1,    -1,
      -1,    -1,    35,     3,     4,     5,    -1,     7,     8,    -1,
      -1,    -1,    -1,    35,    -1,    15,    16,    17,    18,    19,
      -1,    -1,    -1,    -1,    -1,    58,    26,    -1,    28,    29,
      30,    31,    32,    33,    -1,    35,    58,    -1,    -1,    -1,
      -1,    41,    42,    43,    44,    45,    46,     3,     4,     5,
      -1,     7,     8,    -1,    -1,    -1,    56,    57,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,     8,
      26,    -1,    28,    29,    30,    31,    32,    33,    -1,    35,
      -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      46,    -1,    -1,     3,     4,     5,    35,     7,     8,    -1,
      56,    57,    41,    42,    43,    44,    45,    46,    -1,     3,
       4,     5,    -1,     7,     8,    -1,    -1,    56,    -1,    -1,
      -1,    -1,     3,     4,     5,    35,     7,     8,    -1,    -1,
      -1,    41,    42,    43,    44,    45,    46,    -1,     3,     4,
       5,    35,     7,     8,    38,    -1,    56,    41,    42,    43,
      44,    45,    46,    -1,    35,    36,    -1,    -1,    -1,    -1,
      41,    42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,
      35,    36,    -1,    -1,    -1,    -1,    41,    42,    43,    44,
      45,    46,     3,     4,     5,     3,     7,     8,    -1,    -1,
      -1,     0,     1,    -1,     3,    -1,    -1,    15,    16,    17,
      18,    19,    -1,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    -1,     1,    35,     3,    -1,    -1,    36,    -1,
      41,    42,    43,    44,    45,    46,    35,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    15,    16,    17,    18,    19,    20,    35,
      80,    81,    84,    85,    86,   106,   107,   108,   109,     3,
      85,    56,    82,    83,    85,    81,    57,    80,    81,    95,
      96,    35,    37,     0,   108,    57,    36,    40,    56,    55,
      95,    96,     3,     4,     5,     7,     8,    26,    28,    29,
      30,    31,    32,    33,    35,    41,    42,    43,    44,    45,
      46,    56,    58,    60,    61,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    78,
      93,    94,    95,    96,    97,    98,    99,   100,   103,    85,
      80,    95,     3,    36,    81,    87,    88,    89,    90,    38,
      63,    75,    79,    21,    22,    58,    83,    75,    95,    63,
      63,    35,    35,    35,    35,    56,    56,    56,    78,    78,
       7,     8,    35,    37,    39,    55,    77,    63,    42,    47,
      48,    43,    44,     9,    10,    49,    50,    11,    12,    41,
      51,    52,    13,    14,    53,    40,    56,    58,    97,    58,
      93,    96,    85,    36,    40,    36,    40,    38,    54,    54,
      56,    78,    78,    78,    98,    56,    36,    36,    62,    76,
      78,     3,    76,    63,    63,    63,    65,    65,    67,    67,
      67,    67,    68,    68,    69,    70,    71,    72,    73,    78,
      76,    58,    96,    58,    97,    23,    89,     3,    80,   104,
     105,   106,   105,    36,    36,    36,    98,    36,    40,    38,
      54,    58,    58,    58,   104,    21,    58,    80,    91,    92,
      94,    95,    57,    91,    36,    78,    76,    75,    56,    54,
      56,    27,    24,   101,    91,    36,   105,    91,     4,    24,
      25,    58,    91,    58,    54,     4,    54,    56,    94,    95,
     102,    54,   102,   102,   102,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    60,    60,    60,    60,    61,    61,    61,    61,
      61,    61,    61,    62,    62,    63,    63,    63,    63,    64,
      64,    64,    64,    64,    64,    65,    65,    65,    65,    66,
      66,    66,    67,    68,    68,    68,    68,    68,    69,    69,
      69,    70,    70,    71,    71,    72,    72,    73,    73,    74,
      74,    75,    75,    76,    76,    77,    78,    78,    79,    80,
      80,    81,    81,    82,    82,    83,    83,    84,    84,    84,
      84,    84,    85,    86,    86,    86,    86,    86,    86,    86,
      87,    87,    88,    88,    89,    89,    90,    90,    91,    91,
      92,    92,    93,    93,    94,    94,    94,    94,    94,    94,
      94,    95,    95,    95,    95,    95,    95,    95,    96,    96,
      97,    97,    98,    98,    99,    99,    99,   100,   100,   101,
     101,   102,   102,   102,   103,   103,   103,   104,   104,   105,
     105,   106,   106,   106,   106,   107,   107,   107,   107,   108,
     108,   108,   108,   109,   109
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     2,     2,     3,     1,     1,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     1,
       3,     3,     1,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     5,     3,     1,     1,     3,     1,     1,     3,
       2,     2,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     4,     3,     4,     4,     3,
       1,     3,     1,     3,     2,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       2,     5,     5,     4,     4,     3,     3,     2,     2,     1,
       2,     1,     1,     2,     5,     7,     1,    10,     7,     5,
       4,     2,     1,     1,     5,     6,     7,     1,     1,     2,
       1,     4,     3,     3,     2,    11,     8,     8,     5,     1,
       1,     1,     1,     2,     1
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
  case 2:
#line 66 "parser.y"
                       {
		if(findInSymbolTable(current_scope, yyvsp[0]) == -1){
			yyerror("Variable not declared");
		}
	}
#line 1704 "y.tab.c"
    break;

  case 26:
#line 109 "parser.y"
                                                         { 
		int value = doOperation(yyvsp[-2], yyvsp[0], '*', current_scope);
		sprintf(yyval, "%d", value);
	}
#line 1713 "y.tab.c"
    break;

  case 27:
#line 113 "parser.y"
                                                         { 
		int value = doOperation(yyvsp[-2], yyvsp[0], '/', current_scope);
		sprintf(yyval, "%d", value);
	}
#line 1722 "y.tab.c"
    break;

  case 28:
#line 117 "parser.y"
                                                         { 
		int value = doOperation(yyvsp[-2], yyvsp[0], '%', current_scope);
		sprintf(yyval, "%d", value);
	}
#line 1731 "y.tab.c"
    break;

  case 30:
#line 125 "parser.y"
                                                            { 
		int value = doOperation(yyvsp[-2], yyvsp[0], '+', current_scope);
		sprintf(yyval, "%d", value);
	}
#line 1740 "y.tab.c"
    break;

  case 31:
#line 129 "parser.y"
                                                            { 
		int value = doOperation(yyvsp[-2], yyvsp[0], '-', current_scope);
		sprintf(yyval, "%d", value);
	}
#line 1749 "y.tab.c"
    break;

  case 34:
#line 141 "parser.y"
                                                     { 
		int value = doOperation(yyvsp[-2], yyvsp[0], '<', current_scope);
		sprintf(yyval, "%d", value);
	}
#line 1758 "y.tab.c"
    break;

  case 35:
#line 145 "parser.y"
                                                     { 
		int value = doOperation(yyvsp[-2], yyvsp[0], '>', current_scope);
		sprintf(yyval, "%d", value);
	}
#line 1767 "y.tab.c"
    break;

  case 36:
#line 149 "parser.y"
                                                         { 
		int value = doOperation(yyvsp[-2], yyvsp[0], 'y', current_scope);
		sprintf(yyval, "%d", value);
	}
#line 1776 "y.tab.c"
    break;

  case 37:
#line 153 "parser.y"
                                                         { 
		int value = doOperation(yyvsp[-2], yyvsp[0], 'z', current_scope);
		sprintf(yyval, "%d", value);
	}
#line 1785 "y.tab.c"
    break;

  case 39:
#line 161 "parser.y"
                                                            { 
		int value = doOperation(yyvsp[-2], yyvsp[0], 'w', current_scope);
		sprintf(yyval, "%d", value);
	}
#line 1794 "y.tab.c"
    break;

  case 40:
#line 165 "parser.y"
                                                            { 
		int value = doOperation(yyvsp[-2], yyvsp[0], 'x', current_scope);
		sprintf(yyval, "%d", value);
	}
#line 1803 "y.tab.c"
    break;

  case 42:
#line 173 "parser.y"
                                                 { 
		int value = doOperation(yyvsp[-2], yyvsp[0], '&', current_scope);
		sprintf(yyval, "%d", value);
	}
#line 1812 "y.tab.c"
    break;

  case 44:
#line 181 "parser.y"
                                                     { 
		int value = doOperation(yyvsp[-2], yyvsp[0], '^', current_scope);
		sprintf(yyval, "%d", value);
	}
#line 1821 "y.tab.c"
    break;

  case 46:
#line 189 "parser.y"
                                                              { 
		int value = doOperation(yyvsp[-2], yyvsp[0], '|', current_scope);
		sprintf(yyval, "%d", value);
	}
#line 1830 "y.tab.c"
    break;

  case 48:
#line 197 "parser.y"
                                                                  { 
		int value = doOperation(yyvsp[-2], yyvsp[0], 'v', current_scope);
		sprintf(yyval, "%d", value);
	}
#line 1839 "y.tab.c"
    break;

  case 50:
#line 205 "parser.y"
                                                               { 
		int value = doOperation(yyvsp[-2], yyvsp[0], 'u', current_scope);
		sprintf(yyval, "%d", value);
	}
#line 1848 "y.tab.c"
    break;

  case 52:
#line 213 "parser.y"
                                                                          { 
		int value;

		if(atoi(yyvsp[-4])){
			// Sending to "doOperation" since the RHS can be an identifier too. Using add operation as dummy operation (just adding with 0)
			value = doOperation(yyvsp[-2], "0", '+', current_scope);
		}
		else{
			value = doOperation(yyvsp[0], "0", '+', current_scope);
		}
		sprintf(yyval, "%d", value);
	}
#line 1865 "y.tab.c"
    break;

  case 53:
#line 228 "parser.y"
                                                                      {
		if (findInSymbolTable(current_scope, yyvsp[-2]) == -1) {
		      yyerror("Variable not declared");
		}
		updateSymbolTable(yyvsp[-2], yyvsp[0], current_scope);
		displaySymbolTable();
	}
#line 1877 "y.tab.c"
    break;

  case 65:
#line 268 "parser.y"
                                                 {
		if(!insertInSymbolTable(&numRecords, current_scope, currentTypeName, yyvsp[-2],  yylineno, yyvsp[0])){
			yyerror("Variable on LHS reinitialized or variable on RHS not present");
		}
		displaySymbolTable();
	}
#line 1888 "y.tab.c"
    break;

  case 66:
#line 274 "parser.y"
                     {
		if(!insertInSymbolTable(&numRecords, current_scope, currentTypeName, yyvsp[0], yylineno, "0")){
			yyerror("Variable redeclared");
		}
		displaySymbolTable();
	}
#line 1899 "y.tab.c"
    break;

  case 67:
#line 283 "parser.y"
                 { strcpy(currentTypeName, yyvsp[0]); }
#line 1905 "y.tab.c"
    break;

  case 68:
#line 284 "parser.y"
                 { strcpy(currentTypeName, yyvsp[0]); }
#line 1911 "y.tab.c"
    break;

  case 69:
#line 285 "parser.y"
                { strcpy(currentTypeName, yyvsp[0]); }
#line 1917 "y.tab.c"
    break;

  case 70:
#line 286 "parser.y"
                  { strcpy(currentTypeName, yyvsp[0]); }
#line 1923 "y.tab.c"
    break;

  case 71:
#line 287 "parser.y"
                   { strcpy(currentTypeName, yyvsp[0]); }
#line 1929 "y.tab.c"
    break;

  case 142:
#line 442 "parser.y"
                {yyerrok; yyclearin;}
#line 1935 "y.tab.c"
    break;


#line 1939 "y.tab.c"

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
#line 451 "parser.y"



// Symbol table functions

// Returns 1 if valid insertion, else 0 if identifier already exists
int insertInSymbolTable(int* count, int scope, char *datatype, char* name, int line_no, char* value){
	printf("Inserting %s = %s\n", name, value);
	// Check if identifier already present in the same scope
	for(int j = 0; j < *count; ++j){
		if(!strcmp(symbolTable[j].name, name) && symbolTable[j].scope == scope && symbolTable[j].valid){
			return 0;
		}
	}

	// Check if the value passed is a variable or a number

	int identifierIndex = -1;

	for(int i = 0; i < *count; ++i)
	{
		if(!strcmp(symbolTable[i].name, value) && symbolTable[i].scope == scope && symbolTable[i].valid){
		    identifierIndex = i;
		}
	}

	int finalValue;

	// If variable, assign its value to current variable, else the number itself (converted from string to number)
	if(identifierIndex == -1){
		finalValue = atoi(value);
	}
	else{
		finalValue = symbolTable[identifierIndex].value;
	}


	// If not, insert values in symbol table
	symbolTable[*count].scope = scope;
    symbolTable[*count].line_no = line_no;
    symbolTable[*count].value = finalValue;
    strcpy(symbolTable[*count].name, name);
    strcpy(symbolTable[*count].datatype, datatype);
    symbolTable[*count].valid = scope;

    // Increment count of number of records in symbol table
    *count = *count + 1;

    return 1;
}

void displaySymbolTable(){
        printf("\n\nPrinting symbol table: \n");
        printf("Token\t\tData type\tScope\t\tValue\t\tLine number\tValidity\n");
        char scopeName[10];

        char validName[10];


        for(int i = 0; i < numRecords; ++i)
        {
        	if(symbolTable[i].scope == 1){
        		strcpy(scopeName, "Global");
        	}
        	else{
        		strcpy(scopeName, "Local");
        	}

        	if(symbolTable[i].valid >= symbolTable[i].scope){
        		strcpy(validName, "Valid");
        	}
        	else{
        		strcpy(validName, "Invalid");
        	}

        	printf("%s\t\t%s\t\t%d (%s)\t%d\t\t%d\t\t%d (%s)\n", symbolTable[i].name, symbolTable[i].datatype, symbolTable[i].scope, scopeName, symbolTable[i].value, symbolTable[i].line_no, symbolTable[i].valid, validName);
        }

        printf("\n\n");
}


// Returns position if finds record, else -1
int findInSymbolTable(int  scope, char *name){
	// printf("SCANNING %s %d ", name, scope);
	for(int i = 0; i < numRecords; ++i){
		// printf("HMM %d HMM", symbolTable[i].valid);
		if(!strcmp(symbolTable[i].name, name) && symbolTable[i].scope <= scope && symbolTable[i].valid){
		    // printf("FOUND");
			return i;
		}
	}
	return -1;
}


// Update value of identifier in symbol table (on assignment)
void updateSymbolTable(char* name, char* value, int scope){


	// Check if the value passed is a variable or a number

	int identifierIndex = -1;

	for(int i = 0; i < numRecords; ++i)
	{
		if(!strcmp(symbolTable[i].name, value) && symbolTable[i].scope == scope && symbolTable[i].valid){
		    identifierIndex = i;
		}
	}

	int finalValue;

	// If variable, assign its value to current variable, else the number itself (converted from string to number)
	if(identifierIndex == -1){
		finalValue = atoi(value);
	}
	else{
		finalValue = symbolTable[identifierIndex].value;
	}

	for(int i = 0; i < numRecords; ++i){
		if(!strcmp(symbolTable[i].name, name) && symbolTable[i].scope == scope && symbolTable[i].valid){
			symbolTable[i].value = finalValue;
		}
	}
}



// scope stores level at which the variable was declared/initialized. 
// valid stores depth level till which the outer variable can go to. Says if the variable is valid in a location where its scope is not applicable; hence invalid if valid < scope. 
// scope stored only once. valid changes.

void incrementScope(){
	for(int i = 0; i < numRecords; ++i){
	  if(symbolTable[i].valid) symbolTable[i].valid += 1;
	}
}

void decrementScope(){
  for(int i = 0; i < numRecords; ++i){
    if(symbolTable[i].valid != 0){
    	symbolTable[i].valid -= 1;
		if(symbolTable[i].valid < symbolTable[i].scope){
		  symbolTable[i].valid = 0;
		}
    }
  }
}


// Needed this function only to check if the elements we are performing the operation (relational/logical/arithmetic) are identifiers or numbers. Else could directly write int value = atoi($1) + atoi($3); sprintf($$, "%d", value) in the rule itself.

int doOperation(char* first, char* second, char op, int scope){
	// Check if the value passed is a variable or a number

	int identifierIndex = -1;

	int firstval = atoi(first);
	int secondval = atoi(second);

	for(int i = 0; i < numRecords; ++i)
	{
		if(!strcmp(symbolTable[i].name, first) && symbolTable[i].scope == scope && symbolTable[i].valid){
		    firstval = symbolTable[i].value;
		}
		if(!strcmp(symbolTable[i].name, second) && symbolTable[i].scope == scope && symbolTable[i].valid){
			secondval = symbolTable[i].value;
		}
	}

	switch(op){
		case '+': return firstval + secondval;
		case '-': return firstval - secondval;
		case '*': return firstval * secondval;
		case '/': return firstval / secondval;
		case '<': return firstval < secondval;
		case '>': return firstval > secondval;
		case '^': return firstval ^ secondval;
		case '|': return firstval | secondval;
		case '&': return firstval & secondval;
		case 'u': return firstval || secondval;
		case 'v': return firstval && secondval;
		case 'w': return firstval == secondval;
		case 'x': return firstval != secondval;
		case 'y': return firstval <= secondval;
		case 'z': return firstval >= secondval;
	}
	
}


void yyerror(char *s){
	extern int yylineno;
	printf("\n\nERROR:\n Line number: %d \t Error: %s\n", yylineno, s);
}

int main(){
	current_scope = 1;
	numRecords = 0;
	yyparse();
	return 0;
}


/*

Deleted part:

declarator '=' T_CONSTANT {
		if(!insertInSymbolTable(&numRecords, current_scope, currentTypeName, $1,  yylineno, $3)){
			yyerror("Variable reinitialized");
		}
		displaySymbolTable();
	}
	| declarator '=' T_IDENTIFIER {
		if(!insertInSymbolTable(&numRecords, current_scope, currentTypeName, $1,  yylineno, $3)){
			yyerror("Variable on LHS reinitialized or variable on RHS not present");
		}
		displaySymbolTable();
	}
	|

*/
