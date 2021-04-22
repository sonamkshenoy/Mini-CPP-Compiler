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
#line 1 "AST.y"

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h>
	#include <stdarg.h>
	#include "header.h"
    #define LIMIT 1024
    #define MAX_MEMBER 10			// max number of member in struct
	#define TYPE_LENGTH 6			// length of type int float void ....
	#define MAX_NO_OF_STRUCT 20		// max_no of structure 
	void yyerror(const char*);
	int yylex();
	
	/* prototypes */
	int ex (nodeType *p, int flag);
	/* function prototype to create a node for an operation */ 
	nodeType *opr(int oper, int nops, ...);
	/* function prototype to create a node for an identifier */
	nodeType *id(char *identifier);
	/* function prototype to create a node for a constat */
	nodeType *con(char *value);

    int find_struct_variable(char *identifier);
    nodeType *opr_struct(int oper, int num);
	int if_assign = 1;
    int struct_num =0; // initial number of structures
    char struct_members[1024];
    struct struct_data{
		char struct_name[LIMIT];
		char member_name[MAX_MEMBER][LIMIT];
		int index_to_insert_member;				// to know at which index do we have to insert new member
	}struct_variable[MAX_NO_OF_STRUCT];


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
#line 38 "AST.y"

	int ival;
	nodeType *nPtr;
	char string[128];

#line 254 "y.tab.c"

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
#define YYLAST   264

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  175

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
      46,    47,     2,     2,    54,     2,    50,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    52,    55,
       2,    53,     2,    51,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    49,     2,     2,     2,     2,     2,     2,
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
       0,    86,    86,    87,    91,    92,    93,    97,    98,    99,
     100,   101,   102,   106,   107,   108,   111,   116,   119,   122,
     125,   132,   133,   137,   141,   142,   143,   144,   148,   149,
     150,   154,   155,   156,   157,   158,   162,   163,   164,   168,
     169,   173,   174,   178,   179,   182,   183,   184,   185,   190,
     191,   196,   197,   201,   202,   206,   207,   208,   220,   227,
     236,   237,   238,   239,   240,   244,   245,   267,   275,   276,
     280,   281,   285,   286,   290,   291,   295,   300,   313,   314,
     315,   316,   317,   321,   324,   325,   329,   330,   334,   335,
     339,   340,   344,   345,   349,   350,   354,   358,   359,   362,
     363,   369
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
  "WHILE", "'('", "')'", "'['", "']'", "'.'", "'?'", "':'", "'='", "','",
  "';'", "'{'", "'}'", "$accept", "headers", "libraries",
  "primary_expression", "postfix_expression", "unary_expression",
  "unary_operator", "multiplicative_expression", "additive_expression",
  "relational_expression", "equality_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "expression", "declaration",
  "init_declarator_list", "init_declarator", "array", "type_specifier",
  "struct_specifier", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "statement", "switch_statement", "case_statement",
  "case_statement_int", "compound_statement", "block_item_list",
  "block_item", "expression_statement", "while_statement",
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
     295,   296,   297,   298,   299,   300,    40,    41,    91,    93,
      46,    63,    58,    61,    44,    59,   123,   125
};
# endif

#define YYPACT_NINF (-149)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     118,    52,  -149,   -30,  -149,  -149,    -5,  -149,  -149,     0,
    -149,    43,  -149,  -149,    92,   -21,   -11,   147,    29,  -149,
      99,  -149,  -149,  -149,  -149,  -149,  -149,    49,    46,   147,
    -149,   147,   165,  -149,     1,   117,     3,  -149,   144,  -149,
    -149,   113,   176,  -149,  -149,  -149,   132,  -149,   175,  -149,
     152,  -149,  -149,  -149,  -149,  -149,    58,    58,  -149,     3,
    -149,   169,    -3,     3,   157,   -12,   212,   217,   191,    -4,
    -149,  -149,  -149,    71,  -149,  -149,  -149,   203,  -149,   132,
    -149,  -149,  -149,    41,  -149,  -149,   171,     3,   209,     3,
       3,     3,  -149,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,   166,   178,   206,
    -149,  -149,   187,  -149,  -149,  -149,  -149,   100,  -149,  -149,
    -149,  -149,  -149,  -149,     3,  -149,    70,  -149,  -149,  -149,
    -149,  -149,  -149,  -149,  -149,   157,   157,   -12,   -12,   -12,
     -12,   212,   212,   217,   191,    68,  -149,     3,     3,  -149,
    -149,  -149,  -149,  -149,     3,    64,    86,  -149,   193,   197,
     207,   158,     3,   202,   -13,  -149,   129,   204,   158,  -149,
    -149,  -149,   158,   158,   158
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    61,    62,    63,    60,     0,   101,   100,     0,
      64,     0,    97,     2,     0,     0,    67,     0,    56,    51,
       0,    53,     1,    98,     4,     5,     6,     0,     0,     0,
      62,    73,     0,    68,     0,     0,     0,    57,     0,    52,
       3,     0,     0,    72,    65,    69,    76,    70,     0,    74,
       0,     7,     8,    10,    11,     9,     0,     0,    23,     0,
      13,    21,    24,     0,    28,    31,    36,    39,    41,    43,
      45,    55,    54,     0,    99,    66,    77,     0,    71,    59,
      19,    20,    49,     0,    17,    18,     0,     0,     0,     0,
       0,     0,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    88,     0,    92,    93,    81,    78,     0,    90,    79,
      80,    75,    58,    12,     0,    14,     0,    16,    47,    48,
      46,    25,    26,    27,    24,    30,    29,    34,    35,    32,
      33,    37,    38,    40,    42,     0,    82,     0,     0,    95,
      89,    91,    50,    15,     0,     0,     0,    44,     0,     0,
       0,     0,     0,     0,     0,    84,     0,     0,     0,    83,
      85,    96,     0,    87,    86
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -149,  -149,  -149,   189,  -149,   -63,  -149,   151,   139,   148,
     153,   150,  -149,  -148,   -32,   -58,     9,  -149,   220,   -27,
     194,  -149,   230,    44,   229,  -149,   184,  -149,  -149,  -149,
      98,   222,  -108,  -112,  -149,  -149,  -149,   253
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,    27,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    82,   112,   113,    20,    21,    37,
       9,    10,    32,    33,    34,    48,    49,   114,   115,   164,
     165,   116,   117,   118,   119,   120,    11,    12
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      92,    83,    16,    15,    71,   151,   157,    18,    46,     8,
      51,    52,    53,    54,   167,    55,    56,    57,   105,    76,
       8,    89,    90,   162,   163,    28,    58,    96,    97,   126,
     131,   132,   133,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,    22,   169,    29,     1,   106,   145,    59,
      91,    17,   122,   166,   151,    19,    47,   128,   129,   130,
     173,   151,   151,    13,   174,    51,    52,    53,    54,    40,
      55,    14,     2,     3,     4,     5,    45,    35,    51,    52,
      53,    54,    36,    55,    56,    57,    45,     6,   123,   155,
     156,   134,   152,    41,    58,   124,    24,    25,    26,   134,
       2,    30,     4,     5,    59,   107,   108,    51,    52,    53,
      54,   158,    55,    56,    57,     6,   109,    59,   124,   153,
     154,     1,   124,    58,   124,    50,   110,    73,   111,     2,
      30,     4,     5,   159,   107,   108,    51,    52,    53,    54,
     124,    55,    56,    57,     6,   109,    59,     2,     3,     4,
       5,    18,    58,    38,    39,   110,    73,   150,     2,    30,
       4,     5,     6,   107,   108,    51,    52,    53,    54,    73,
      55,    56,    57,     6,   109,    59,     2,    30,     4,     5,
      35,    58,    84,    85,   110,    73,   171,     2,    30,     4,
       5,     6,   107,   108,     2,    30,     4,     5,    93,    94,
      95,    79,     6,   109,    59,     2,    30,     4,     5,     6,
      46,    31,   104,   110,    73,    86,   127,    87,   125,    88,
       6,   146,    44,    31,   147,    31,    31,    98,    99,    77,
      78,   100,   101,    75,   102,   103,    31,   137,   138,   139,
     140,   124,   149,   162,   163,    80,    81,   135,   136,   160,
     141,   142,   148,   161,   168,   144,   172,   143,    72,    42,
      43,   121,   170,    74,    23
};

static const yytype_uint8 yycheck[] =
{
      63,    59,     7,    33,    36,   117,   154,     7,     7,     0,
       7,     8,     9,    10,   162,    12,    13,    14,    22,    46,
      11,    24,    25,    36,    37,    46,    23,    39,    40,    87,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     0,    57,    56,     3,    51,   106,    46,
      53,    56,    79,   161,   166,    55,    55,    89,    90,    91,
     168,   173,   174,    11,   172,     7,     8,     9,    10,    20,
      12,    19,    29,    30,    31,    32,    32,    48,     7,     8,
       9,    10,    53,    12,    13,    14,    42,    44,    47,   147,
     148,   154,   124,    47,    23,    54,     4,     5,     6,   162,
      29,    30,    31,    32,    46,    34,    35,     7,     8,     9,
      10,    47,    12,    13,    14,    44,    45,    46,    54,    49,
      52,     3,    54,    23,    54,     8,    55,    56,    57,    29,
      30,    31,    32,    47,    34,    35,     7,     8,     9,    10,
      54,    12,    13,    14,    44,    45,    46,    29,    30,    31,
      32,     7,    23,    54,    55,    55,    56,    57,    29,    30,
      31,    32,    44,    34,    35,     7,     8,     9,    10,    56,
      12,    13,    14,    44,    45,    46,    29,    30,    31,    32,
      48,    23,    13,    14,    55,    56,    57,    29,    30,    31,
      32,    44,    34,    35,    29,    30,    31,    32,    41,    42,
      43,    49,    44,    45,    46,    29,    30,    31,    32,    44,
       7,    17,    21,    55,    56,    46,     7,    48,    47,    50,
      44,    55,    57,    29,    46,    31,    32,    15,    16,    54,
      55,    19,    20,    57,    17,    18,    42,    98,    99,   100,
     101,    54,    55,    36,    37,    56,    57,    96,    97,    56,
     102,   103,    46,    56,    52,   105,    52,   104,    38,    29,
      31,    77,   164,    41,    11
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    29,    30,    31,    32,    44,    59,    74,    78,
      79,    94,    95,    11,    19,    33,     7,    56,     7,    55,
      75,    76,     0,    95,     4,     5,     6,    60,    46,    56,
      30,    78,    80,    81,    82,    48,    53,    77,    54,    55,
      20,    47,    80,    82,    57,    81,     7,    55,    83,    84,
       8,     7,     8,     9,    10,    12,    13,    14,    23,    46,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    76,    56,    89,    57,    77,    54,    55,    49,
      61,    61,    72,    73,    13,    14,    46,    48,    50,    24,
      25,    53,    63,    41,    42,    43,    39,    40,    15,    16,
      19,    20,    17,    18,    21,    22,    51,    34,    35,    45,
      55,    57,    73,    74,    85,    86,    89,    90,    91,    92,
      93,    84,    77,    47,    54,    47,    73,     7,    72,    72,
      72,    63,    63,    63,    63,    65,    65,    66,    66,    66,
      66,    67,    67,    68,    69,    73,    55,    46,    46,    55,
      57,    91,    72,    49,    52,    73,    73,    71,    47,    47,
      56,    56,    36,    37,    87,    88,    90,    71,    52,    57,
      88,    57,    52,    90,    90
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    59,    60,    60,    60,    61,    61,    61,
      61,    61,    61,    62,    62,    62,    62,    62,    62,    62,
      62,    63,    63,    64,    65,    65,    65,    65,    66,    66,
      66,    67,    67,    67,    67,    67,    68,    68,    68,    69,
      69,    70,    70,    71,    71,    72,    72,    72,    72,    73,
      73,    74,    74,    75,    75,    76,    76,    76,    77,    77,
      78,    78,    78,    78,    78,    79,    79,    79,    80,    80,
      81,    81,    82,    82,    83,    83,    84,    84,    85,    85,
      85,    85,    85,    86,    87,    87,    88,    88,    89,    89,
      90,    90,    91,    91,    92,    92,    93,    94,    94,    95,
      95,    95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     4,     3,     2,     2,     2,
       2,     1,     2,     1,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     5,     1,     3,     3,     3,     1,
       3,     2,     3,     1,     3,     3,     1,     2,     4,     3,
       1,     1,     1,     1,     1,     4,     5,     2,     1,     2,
       2,     3,     2,     1,     1,     3,     1,     2,     1,     1,
       1,     1,     2,     7,     1,     2,     4,     3,     2,     3,
       1,     2,     1,     1,     1,     2,     7,     1,     2,     5,
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
#line 97 "AST.y"
                                {(yyval.nPtr) = id((yyvsp[0].string));}
#line 1584 "y.tab.c"
    break;

  case 8:
#line 98 "AST.y"
                                {(yyval.nPtr) = con((yyvsp[0].string));}
#line 1590 "y.tab.c"
    break;

  case 9:
#line 99 "AST.y"
                                {(yyval.nPtr) = con((yyvsp[0].string));}
#line 1596 "y.tab.c"
    break;

  case 10:
#line 100 "AST.y"
                                {(yyval.nPtr) = con((yyvsp[0].string));}
#line 1602 "y.tab.c"
    break;

  case 11:
#line 101 "AST.y"
                                {(yyval.nPtr) = con((yyvsp[0].string));}
#line 1608 "y.tab.c"
    break;

  case 12:
#line 102 "AST.y"
                                {(yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1614 "y.tab.c"
    break;

  case 13:
#line 106 "AST.y"
                                {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1620 "y.tab.c"
    break;

  case 15:
#line 108 "AST.y"
                                                {
                                                (yyval.nPtr) = opr('#',2,(yyvsp[-3].nPtr),(yyvsp[-1].nPtr));
                                            }
#line 1628 "y.tab.c"
    break;

  case 16:
#line 111 "AST.y"
                                            {
											char *tmp = strcat((yyvsp[-2].nPtr)->id.name,".");
											tmp = strcat(tmp, (yyvsp[0].string));		
											(yyval.nPtr) = id(tmp);
										}
#line 1638 "y.tab.c"
    break;

  case 17:
#line 116 "AST.y"
                                                        {
											(yyval.nPtr) = opr('=', 2, (yyvsp[-1].nPtr), opr('+', 2, (yyvsp[-1].nPtr), con("1") ) );
										}
#line 1646 "y.tab.c"
    break;

  case 18:
#line 119 "AST.y"
                                                        {
											(yyval.nPtr) = opr('=', 2, (yyvsp[-1].nPtr), opr('-', 2, (yyvsp[-1].nPtr), con("1") ) );										
										}
#line 1654 "y.tab.c"
    break;

  case 19:
#line 122 "AST.y"
                                                        {
											(yyval.nPtr) = opr('=', 2, (yyvsp[0].nPtr), opr('+', 2, (yyvsp[0].nPtr), con("1") ) );										
										}
#line 1662 "y.tab.c"
    break;

  case 20:
#line 125 "AST.y"
                                                        {
											(yyval.nPtr) = opr('=', 2, (yyvsp[0].nPtr), opr('-', 2, (yyvsp[0].nPtr), con("1") ) );										
										}
#line 1670 "y.tab.c"
    break;

  case 21:
#line 132 "AST.y"
                                                {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1676 "y.tab.c"
    break;

  case 22:
#line 133 "AST.y"
                                                                {(yyval.nPtr) = opr('!', 1, (yyvsp[0].nPtr));}
#line 1682 "y.tab.c"
    break;

  case 24:
#line 141 "AST.y"
                                                                        {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1688 "y.tab.c"
    break;

  case 25:
#line 142 "AST.y"
                                                                        {(yyval.nPtr) = opr('*', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1694 "y.tab.c"
    break;

  case 26:
#line 143 "AST.y"
                                                                        {(yyval.nPtr) = opr('/', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1700 "y.tab.c"
    break;

  case 27:
#line 144 "AST.y"
                                                                        {(yyval.nPtr) = opr('%', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1706 "y.tab.c"
    break;

  case 28:
#line 148 "AST.y"
                                                                        {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1712 "y.tab.c"
    break;

  case 29:
#line 149 "AST.y"
                                                                        {(yyval.nPtr) = opr('+', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1718 "y.tab.c"
    break;

  case 30:
#line 150 "AST.y"
                                                                        {(yyval.nPtr) = opr('-', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1724 "y.tab.c"
    break;

  case 32:
#line 155 "AST.y"
                                                                        {(yyval.nPtr) = opr('<', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1730 "y.tab.c"
    break;

  case 33:
#line 156 "AST.y"
                                                                        {(yyval.nPtr) = opr('>', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1736 "y.tab.c"
    break;

  case 34:
#line 157 "AST.y"
                                                                        {(yyval.nPtr) = opr(LE_OP, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1742 "y.tab.c"
    break;

  case 35:
#line 158 "AST.y"
                                                                        {(yyval.nPtr) = opr(GE_OP, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1748 "y.tab.c"
    break;

  case 36:
#line 162 "AST.y"
                                                                        {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1754 "y.tab.c"
    break;

  case 37:
#line 163 "AST.y"
                                                                        {(yyval.nPtr) = opr(EQ_OP, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1760 "y.tab.c"
    break;

  case 38:
#line 164 "AST.y"
                                                                        {(yyval.nPtr) = opr(NE_OP, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1766 "y.tab.c"
    break;

  case 39:
#line 168 "AST.y"
                                                                                        {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1772 "y.tab.c"
    break;

  case 40:
#line 169 "AST.y"
                                                            {(yyval.nPtr)=opr(AND_LOG,2,(yyvsp[-2].nPtr),(yyvsp[0].nPtr));}
#line 1778 "y.tab.c"
    break;

  case 41:
#line 173 "AST.y"
                                                                                        {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1784 "y.tab.c"
    break;

  case 42:
#line 174 "AST.y"
                                                             {(yyval.nPtr)=opr(OR_LOG,2,(yyvsp[-2].nPtr),(yyvsp[0].nPtr));}
#line 1790 "y.tab.c"
    break;

  case 43:
#line 178 "AST.y"
                                                                                {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1796 "y.tab.c"
    break;

  case 44:
#line 179 "AST.y"
                                                                                {(yyval.nPtr) = opr('?', 2, (yyvsp[-4].nPtr), opr(':', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)) );}
#line 1802 "y.tab.c"
    break;

  case 45:
#line 182 "AST.y"
                                                                        {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1808 "y.tab.c"
    break;

  case 46:
#line 183 "AST.y"
                                                     {(yyval.nPtr) = opr('=', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1814 "y.tab.c"
    break;

  case 47:
#line 184 "AST.y"
                                                            {(yyval.nPtr) = opr('=', 2, (yyvsp[-2].nPtr), opr('+', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)) );}
#line 1820 "y.tab.c"
    break;

  case 48:
#line 185 "AST.y"
                                                            {(yyval.nPtr) = opr('=', 2, (yyvsp[-2].nPtr), opr('-', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)) );}
#line 1826 "y.tab.c"
    break;

  case 49:
#line 190 "AST.y"
                                                                        {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1832 "y.tab.c"
    break;

  case 50:
#line 191 "AST.y"
                                                        {(yyval.nPtr)=opr(',',2,(yyvsp[-2].nPtr),(yyvsp[0].nPtr));}
#line 1838 "y.tab.c"
    break;

  case 52:
#line 197 "AST.y"
                                                                        {if(if_assign==0){(yyval.nPtr) = opr('STRUCT', 2,(yyvsp[-1].nPtr),(yyvsp[-2].nPtr));} else{(yyval.nPtr) = opr('DEC', 1, (yyvsp[-1].nPtr));} }
#line 1844 "y.tab.c"
    break;

  case 53:
#line 201 "AST.y"
                                                                                                {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1850 "y.tab.c"
    break;

  case 54:
#line 202 "AST.y"
                                                                        {(yyval.nPtr) = opr(',', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1856 "y.tab.c"
    break;

  case 55:
#line 206 "AST.y"
                                                                        {(yyval.nPtr) = opr('=', 2, id((yyvsp[-2].string)), (yyvsp[0].nPtr));}
#line 1862 "y.tab.c"
    break;

  case 56:
#line 207 "AST.y"
                                                                                                {(yyval.nPtr) = id((yyvsp[0].string));}
#line 1868 "y.tab.c"
    break;

  case 57:
#line 208 "AST.y"
                                                                                                {  char buff[50];
                                                            strcpy(buff,(yyvsp[-1].string));
                                                            strcat(buff,"(");
                                                            strcat(buff,(yyvsp[0].string));
                                                            buff[strlen(buff)-1]=')';
                                                            buff[strlen(buff)]='\0';
                                                            (yyval.nPtr) = id(buff); 
                                                        }
#line 1881 "y.tab.c"
    break;

  case 58:
#line 220 "AST.y"
                                                                {
                                                    char buff[50];
                                                   strcpy(buff, (yyvsp[-2].string));
                                                    strcat(buff,",");   
                                                    strcat(buff,(yyvsp[0].string));
                                                    strcpy((yyval.string),buff);               
                                                }
#line 1893 "y.tab.c"
    break;

  case 59:
#line 227 "AST.y"
                                                                        {       char buff[50];
                                                        strcpy(buff, (yyvsp[-1].string));
                                                        strcat(buff,",");
                                                       strcpy((yyval.string),buff);
                                                }
#line 1903 "y.tab.c"
    break;

  case 60:
#line 236 "AST.y"
                {if_assign = 1;}
#line 1909 "y.tab.c"
    break;

  case 61:
#line 237 "AST.y"
                {if_assign = 1;}
#line 1915 "y.tab.c"
    break;

  case 62:
#line 238 "AST.y"
                {if_assign = 1;}
#line 1921 "y.tab.c"
    break;

  case 63:
#line 239 "AST.y"
                        {if_assign = 1;}
#line 1927 "y.tab.c"
    break;

  case 64:
#line 240 "AST.y"
                                {if_assign = 0; (yyval.nPtr)=(yyvsp[0].nPtr);}
#line 1933 "y.tab.c"
    break;

  case 66:
#line 245 "AST.y"
                                                                                    {  
                                                                                    (yyval.nPtr)=(yyvsp[-1].nPtr);
                                                                                    // initializing its values into structure;
                                                                                    strcpy(struct_variable[struct_num].struct_name,(yyvsp[-3].string));
                                                                                    struct_variable[struct_num].index_to_insert_member=0;
                                                                                    char *token;  
                                                                                        token = strtok(struct_members, "#");
                                                                                        
                                                                                        while( token != NULL )
                                                                                         {
                                                                                            strcpy(struct_variable[struct_num].member_name[struct_variable[struct_num].index_to_insert_member],token);
                                                                                            struct_variable[struct_num].index_to_insert_member++;
                                                                                            token = strtok(NULL, "#");
                                                                                        }
                                                                                    /*printf("INFO ON STRUCTURE VARIABLES!!\n\n\n");
                                                                                    for(int i =0;i<struct_variable[struct_num].index_to_insert_member;i++)
                                                                                    {
                                                                                        printf("STRUCTURE NAME %s    MEMBER NAME %s    MEMBER NO :   %d      \n\n\n",struct_variable[struct_num].struct_name,struct_variable[struct_num].member_name[i],struct_variable[struct_num].index_to_insert_member);
                                                                                    }*/
                                                                                    strcpy(struct_members,"\0");
                                                                                    struct_num++;
                                                                                }
#line 1960 "y.tab.c"
    break;

  case 67:
#line 267 "AST.y"
                                                                                    {
                                                                                    int num = find_struct_variable((yyvsp[0].string));
                                                                                    (yyval.nPtr) = opr_struct('STRUCT_MEM',num);

                                                                                }
#line 1970 "y.tab.c"
    break;

  case 68:
#line 275 "AST.y"
                              {(yyval.nPtr)=(yyvsp[0].nPtr);}
#line 1976 "y.tab.c"
    break;

  case 69:
#line 276 "AST.y"
                                                      {(yyval.nPtr) =  opr('STRUCT_MEM', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr));}
#line 1982 "y.tab.c"
    break;

  case 71:
#line 281 "AST.y"
                                                              { if(if_assign==0){(yyval.nPtr) = opr(';', 2,(yyvsp[-2].nPtr), (yyvsp[-1].nPtr));} else {(yyval.nPtr) = (yyvsp[-1].nPtr);}}
#line 1988 "y.tab.c"
    break;

  case 73:
#line 286 "AST.y"
                                                                                                { if(if_assign==0){(yyval.nPtr)=(yyvsp[0].nPtr);}}
#line 1994 "y.tab.c"
    break;

  case 74:
#line 290 "AST.y"
                            {  (yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2000 "y.tab.c"
    break;

  case 75:
#line 291 "AST.y"
                                                       { (yyval.nPtr) = opr(',',2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 2006 "y.tab.c"
    break;

  case 76:
#line 295 "AST.y"
                                                                {    (yyval.nPtr) = id((yyvsp[0].string));      
                                                                strcat(struct_members,(yyvsp[0].string)); 
                                                                strcat(struct_members,"#");    

                                                            }
#line 2016 "y.tab.c"
    break;

  case 77:
#line 300 "AST.y"
                                                              { char buff[50];
                                                            strcpy(buff,(yyvsp[-1].string));
                                                            strcat(buff,"(");
                                                            strcat(buff,(yyvsp[0].string));
                                                            buff[strlen(buff)-1]=')';
                                                            buff[strlen(buff)]='\0';
                                                            (yyval.nPtr) = id(buff); 
                                                            strcat(struct_members,buff); 
                                                            strcat(struct_members,"#"); 
                                                            }
#line 2031 "y.tab.c"
    break;

  case 78:
#line 313 "AST.y"
                                {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2037 "y.tab.c"
    break;

  case 79:
#line 314 "AST.y"
                                {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2043 "y.tab.c"
    break;

  case 80:
#line 315 "AST.y"
                                {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2049 "y.tab.c"
    break;

  case 81:
#line 316 "AST.y"
                                {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2055 "y.tab.c"
    break;

  case 82:
#line 317 "AST.y"
                    {/*$$=opr(BREAK,1,$1);*/(yyval.nPtr)=id((yyvsp[-1].string));}
#line 2061 "y.tab.c"
    break;

  case 83:
#line 321 "AST.y"
                                                   {(yyval.nPtr)=opr(SWITCH,2,(yyvsp[-4].nPtr),(yyvsp[-1].nPtr));}
#line 2067 "y.tab.c"
    break;

  case 84:
#line 324 "AST.y"
                     {(yyval.nPtr)=(yyvsp[0].nPtr);}
#line 2073 "y.tab.c"
    break;

  case 85:
#line 325 "AST.y"
                                    {(yyval.nPtr) = opr('CASES', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr));}
#line 2079 "y.tab.c"
    break;

  case 86:
#line 329 "AST.y"
                                                 {(yyval.nPtr)=opr(CASE,2,(yyvsp[-2].nPtr),(yyvsp[0].nPtr));}
#line 2085 "y.tab.c"
    break;

  case 87:
#line 330 "AST.y"
                              {(yyval.nPtr)=opr(DEFAULT,1,(yyvsp[0].nPtr));}
#line 2091 "y.tab.c"
    break;

  case 89:
#line 335 "AST.y"
                                        {(yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 2097 "y.tab.c"
    break;

  case 90:
#line 339 "AST.y"
                        {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2103 "y.tab.c"
    break;

  case 91:
#line 340 "AST.y"
                                     {(yyval.nPtr) = opr(';', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr));}
#line 2109 "y.tab.c"
    break;

  case 92:
#line 344 "AST.y"
                        {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2115 "y.tab.c"
    break;

  case 93:
#line 345 "AST.y"
                                {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2121 "y.tab.c"
    break;

  case 95:
#line 350 "AST.y"
                         {(yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 2127 "y.tab.c"
    break;

  case 96:
#line 354 "AST.y"
                                                           {(yyval.nPtr) = opr(WHILE, 2, (yyvsp[-4].nPtr), (yyvsp[-1].nPtr));}
#line 2133 "y.tab.c"
    break;

  case 99:
#line 362 "AST.y"
                                                {ex((yyvsp[0].nPtr), 0); /*freeNode($2);*/}
#line 2139 "y.tab.c"
    break;

  case 100:
#line 363 "AST.y"
                                                                        {
												//if(if_assign)
												{											
													ex((yyvsp[0].nPtr), 2); /*freeNode($2);*/
												}
											}
#line 2150 "y.tab.c"
    break;


#line 2154 "y.tab.c"

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
#line 372 "AST.y"


void yyerror(const char *str)
{
	fflush(stdout);
	fprintf(stderr, "*** %s\n", str);
}

int main(){
    strcpy(struct_members,"\0");
	if(!yyparse())
	{
		printf("Successful\n");
	}
	else
		printf("Unsuccessful\n");

	return 0;
}

nodeType *con(char *value)
{
	nodeType *p;
	/* allocate node */
	if ((p = malloc(sizeof(nodeType))) == NULL)
		yyerror("out of memory");
	/* copy information */
	p->type = typeCon;
	strcpy(p->con.value, value);
	//printf("in con %s\n",value);
	return p;
}
nodeType *id(char *identifier) {
	nodeType *p;
	/* allocate node */
	if ((p = malloc(sizeof(nodeType))) == NULL)
		yyerror("out of memory");
	/* copy information */
	p->type = typeId;
	strcpy(p->id.name,identifier);
	//printf("The copied identifier %s\n", p->id.name);
	return p;
}

nodeType *opr(int oper, int nops, ...)
{
	va_list ap;
	nodeType *p;
	int i;
	/* allocate node, extending op array */
	if ((p = malloc(sizeof(nodeType) +(nops-1) * sizeof(nodeType *))) == NULL)
		yyerror("out of memory");
	/* copy information */
	p->type = typeOpr;
	p->opr.oper = oper;
	p->opr.nops = nops;
	va_start(ap, nops);
	for (i = 0; i < nops; i++)
	{
		p->opr.op[i] = va_arg(ap, nodeType*);
		//printf("in opr %d  i   %d\n",oper,i);
	}
	va_end(ap);
	return p;
}

nodeType *opr_struct(int oper, int num)
{
	//va_list ap;
	nodeType *p;
	int i;
	/* allocate node, extending op array */
	if ((p = malloc(sizeof(nodeType) +(struct_variable[num].index_to_insert_member-1) * sizeof(nodeType *))) == NULL)
		yyerror("out of memory");
	/* copy information */
	p->type = typeOpr;
	p->opr.oper = oper;
	p->opr.nops = struct_variable[num].index_to_insert_member;
	//va_start(ap, nops);
	for (i = 0; i < struct_variable[num].index_to_insert_member; i++)
	{
		p->opr.op[i] = id(struct_variable[num].member_name[i]);
		//printf("in opr %d  i   %d\n",oper,i);
	}
	//va_end(ap);
	return p;
}

int find_struct_variable(char *identifier)
{
    for(int i=0;i<struct_num;i++)
    {
        if(!strcmp(struct_variable[i].struct_name,identifier))
        {
            return i;
        }
    }
}
