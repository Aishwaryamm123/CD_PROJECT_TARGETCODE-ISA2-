/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "ast.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <limits.h>
	// #define COUNT 10		//use while printing AST

	void yyerror(const char*);
	int yylex();
	extern FILE * yyin, *yyout;

	int x=0;	

	extern int line;
	
	int scope = 0;

	int unaryop = -1;		//unary operator type
	int assignop = -1;		//assignment operator == += -=
	int datatype = -1;		//type specifier
	int assigntype = -1;	//RHS type 
	int idcheck = -1;		//check if ID 
	int check_un = 0;		//check for undeclared variables


	char tempStr[100];		//sprintf

	struct node{
		char token[20];
		char name[20];
		int dtype;
		int scope;
		int lineno;
		int valid;
		union value{
			float f;
			int i;
			char c;
		}val;
		
		struct node *link;

	}*first = NULL, *tmp, *crt, *lhs;

	typedef struct Node{
		struct Node *left;
		struct Node *right;
		char token[100];
		struct Node *val;
		int level;
	}Node;

	typedef struct tree_stack{
		Node *node;
		struct tree_stack *next;
	}tree_stack;

	tree_stack *tree_top = NULL;
	char preBuf[1000000];

	struct node * checksym(char *);
	void addsymbol(struct node *,char *);	
	void addInt(struct node *, int, int);
	void addFloat(struct node *, int, float);
	void addChar(struct node *, int, char);
	void addfunc(struct node *t, int, char *);
	void printsymtable();

	struct node * addtosymbol(struct node * n);
	void cleansymbol();


	//AST 
	void create_node(char *token, int leaf);
	void push_tree(Node *newnode);
	Node *pop_tree();
	void preorder(Node* root);
	void printtree(Node* root);
	int getmaxlevel(Node *root);
	void printGivenLevel(Node* root, int level, int h);
	void get_levels(Node *root, int level);



#line 151 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
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
    HASH = 258,
    INCLUDE = 259,
    STDIO = 260,
    STDLIB = 261,
    MATH = 262,
    STRING = 263,
    TIME = 264,
    STRING_LITERAL = 265,
    HEADER_LITERAL = 266,
    PRINT = 267,
    RETURN = 268,
    INTEGER_LITERAL = 269,
    CHARACTER_LITERAL = 270,
    FLOAT_LITERAL = 271,
    IDENTIFIER = 272,
    INC_OP = 273,
    DEC_OP = 274,
    LE_OP = 275,
    GE_OP = 276,
    EQ_OP = 277,
    NE_OP = 278,
    MUL_ASSIGN = 279,
    DIV_ASSIGN = 280,
    MOD_ASSIGN = 281,
    ADD_ASSIGN = 282,
    SUB_ASSIGN = 283,
    CHAR = 284,
    INT = 285,
    FLOAT = 286,
    VOID = 287,
    FOR = 288
  };
#endif
/* Tokens.  */
#define HASH 258
#define INCLUDE 259
#define STDIO 260
#define STDLIB 261
#define MATH 262
#define STRING 263
#define TIME 264
#define STRING_LITERAL 265
#define HEADER_LITERAL 266
#define PRINT 267
#define RETURN 268
#define INTEGER_LITERAL 269
#define CHARACTER_LITERAL 270
#define FLOAT_LITERAL 271
#define IDENTIFIER 272
#define INC_OP 273
#define DEC_OP 274
#define LE_OP 275
#define GE_OP 276
#define EQ_OP 277
#define NE_OP 278
#define MUL_ASSIGN 279
#define DIV_ASSIGN 280
#define MOD_ASSIGN 281
#define ADD_ASSIGN 282
#define SUB_ASSIGN 283
#define CHAR 284
#define INT 285
#define FLOAT 286
#define VOID 287
#define FOR 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 92 "ast.y" /* yacc.c:355  */

	int ival;
	float fval;
	char cval;
	char string[128];
	struct node *ptr;

#line 265 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 282 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   234

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  161

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,     2,     2,    18,     2,     2,
      45,    46,    17,    14,    47,    15,     2,    16,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    49,    44,
      40,    19,    41,    48,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,    51,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    52,
      53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   128,   128,   142,   143,   144,   149,   150,   155,   156,
     161,   162,   163,   164,   165,   170,   171,   176,   177,   185,
     186,   187,   188,   192,   197,   198,   203,   208,   220,   221,
     228,   240,   241,   242,   243,   248,   249,   254,   254,   365,
     432,   433,   433,   682,   683,   684,   685,   686,   687,   692,
     693,   708,   709,   714,   715,   720,   754,   763,   781,   799,
     810,   811,   812,   817,   818,   846,   847,   848,   849,   850,
     851,   856,   857,   866,   878,   879,   888,   897,   906,   919,
     920,   925,   934,   935,   940,   954,   973,   991,  1018,  1019,
    1024,  1031,  1032,  1033,  1038,  1039,  1044,  1045,  1050,  1051
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "HASH", "INCLUDE", "STDIO", "STDLIB",
  "MATH", "STRING", "TIME", "STRING_LITERAL", "HEADER_LITERAL", "PRINT",
  "RETURN", "'+'", "'-'", "'/'", "'*'", "'%'", "'='", "INTEGER_LITERAL",
  "CHARACTER_LITERAL", "FLOAT_LITERAL", "IDENTIFIER", "INC_OP", "DEC_OP",
  "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "CHAR", "INT", "FLOAT", "VOID",
  "FOR", "'<'", "'>'", "'{'", "'}'", "';'", "'('", "')'", "','", "'?'",
  "':'", "'!'", "'~'", "\"INC_OP\"", "\"DEC_OP\"", "$accept", "S",
  "program", "translation_unit", "ext_dec", "libraries",
  "compound_statement", "block_item_list", "block_item", "printstat",
  "declaration", "statement", "iteration_statement", "type_specifier",
  "init_declarator_list", "init_declarator", "$@1",
  "assignment_expression", "$@2", "assignment_operator",
  "conditional_expression", "expression_statement", "expression",
  "primary_expression", "postfix_expression", "unary_expression",
  "unary_operator", "equality_expression", "relational_expression",
  "additive_expression", "multiplicative_expression",
  "function_definition", "function_call", "declarator", "parameter_list",
  "parameter_declaration", "identifier_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,    43,    45,    47,    42,    37,    61,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
      60,    62,   123,   125,    59,    40,    41,    44,    63,    58,
      33,   126,   289,   290
};
# endif

#define YYPACT_NINF -90

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-90)))

#define YYTABLE_NINF -94

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      40,    21,   -90,   -90,   -90,   -90,   -90,    20,   -90,   175,
     -90,   -90,    11,   -90,   -16,    -5,   -90,   -90,    37,    18,
     -90,   -16,    90,   -14,   -90,    40,   183,    38,   -90,    17,
     -90,    43,   134,   -90,   -90,   -90,   -90,   -90,    48,    61,
     -90,   -90,   150,   -90,   -90,   -90,   -90,   -90,   124,   -90,
      87,   -90,   -90,   -90,    17,   -90,   -90,   -90,    45,   -90,
      49,    53,   150,    42,    74,    -4,   100,   137,   113,   -90,
     -90,   160,    34,   -90,    52,   -90,   -90,   -90,   -90,   -90,
     -90,   153,   150,   180,   -90,   199,   -90,   -90,   134,    77,
     -90,   -90,   -90,   -90,   150,   -90,   -90,   174,   -90,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   -90,    84,   -90,   -90,   115,   -90,   201,    40,   -90,
     168,   134,   -90,   -90,   -90,   -90,   -90,   -90,   -90,   -90,
     150,   -90,    74,    74,   133,    -4,    -4,    -4,    -4,   100,
     100,   -90,   -90,   -90,   181,   170,   -90,   -90,   -90,   -90,
     150,   150,   -90,   150,   182,   172,   176,   -90,   -90,    16,
     -90
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    90,    32,    33,    34,    31,     0,     2,     5,
       6,     8,     0,     9,     0,     0,     1,     7,    39,     0,
      35,     0,     0,     0,    87,     0,     0,     0,    26,     0,
      86,     0,     0,    65,    66,    56,    58,    57,    55,     0,
      15,    51,     0,    67,    68,    69,    70,    27,     0,    17,
       0,    19,    20,    29,     0,    53,    40,    28,     0,    60,
      63,    82,     0,    49,    71,    74,    79,     0,     0,    98,
      93,    97,     0,    94,     0,     4,    10,    11,    12,    13,
      14,     0,     0,    39,    36,     0,    55,    22,     0,     0,
      16,    18,    23,    52,     0,    61,    62,     0,    64,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,    96,    91,     0,    92,     0,     0,    38,
       0,     0,    59,    54,    43,    46,    47,    48,    44,    45,
       0,    82,    72,    73,     0,    77,    78,    75,    76,    80,
      81,    84,    83,    85,    89,     0,    95,    99,     3,    24,
       0,     0,    42,     0,    88,     0,     0,    50,    25,     0,
      30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -90,   -90,   -22,   -90,   216,   -90,    -2,   -90,   184,   -90,
     -15,    69,   -90,   -21,   -90,   200,   -90,   -77,   -90,   -90,
      78,   -24,   -42,   -90,   -90,   -58,   -90,   -90,    97,   -89,
     114,   -90,   -90,     6,   -90,   118,   122
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    81,    47,    48,    49,    50,
      11,    52,    53,    12,    19,    20,    27,    55,    97,   130,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    13,    67,    14,    72,    73,    74
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      89,    54,    71,    75,    98,   119,    25,    51,    87,    69,
     106,   107,    24,   135,   136,   137,   138,   123,    21,    30,
      16,     3,     4,     5,     6,    15,    22,    54,    68,    23,
      33,    34,    70,    51,    18,    26,    35,    36,    37,    86,
      83,   131,   131,     1,   131,   131,   131,   131,   131,   131,
     141,   142,   143,   152,    68,    39,   -37,    82,    22,   134,
      41,    42,    28,     2,   121,    29,    43,    44,    45,    46,
      99,   100,   -41,    95,    96,     3,     4,     5,     6,   -90,
     114,   115,   -90,   -41,   -41,   -41,   -41,   -41,    85,    93,
     101,    71,    94,   -90,    71,   131,   148,   151,   116,   117,
     102,   103,    31,    32,    33,    34,    88,    69,   155,   156,
      35,    36,    37,    38,   104,   105,   108,   109,   110,     3,
       4,     5,     6,   122,    94,     3,     4,     5,     6,    39,
     144,    92,    22,    40,    41,    42,    31,    32,    33,    34,
      43,    44,    45,    46,    35,    36,    37,    38,    33,    34,
       3,     4,     5,     6,    35,    36,    37,    86,   112,     3,
       4,     5,     6,    39,    33,    34,    22,    90,    41,    42,
      35,    36,    37,    86,    43,    44,    45,    46,    41,    42,
      94,   111,   153,   113,    43,    44,    45,    46,    76,    77,
      78,    79,    80,   124,   118,    42,   132,   133,     2,   -37,
      43,    44,    45,    46,   125,   126,   127,   128,   129,   120,
       3,     4,     5,     6,   149,   150,   154,   117,   158,    94,
     139,   140,   159,    94,   147,    17,   -93,   -92,   160,    84,
       0,   157,    91,   146,   145
};

static const yytype_int16 yycheck[] =
{
      42,    22,    23,    25,    62,    82,    11,    22,    32,    23,
      14,    15,    14,   102,   103,   104,   105,    94,    12,    21,
       0,    35,    36,    37,    38,     4,    42,    48,    22,    45,
      14,    15,    46,    48,    23,    40,    20,    21,    22,    23,
      23,    99,   100,     3,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   130,    48,    39,    19,    19,    42,   101,
      44,    45,    44,    23,    88,    47,    50,    51,    52,    53,
      28,    29,    19,    24,    25,    35,    36,    37,    38,    42,
      46,    47,    45,    30,    31,    32,    33,    34,    45,    44,
      48,   112,    47,    45,   115,   153,   118,   121,    46,    47,
      26,    27,    12,    13,    14,    15,    45,    23,   150,   151,
      20,    21,    22,    23,    40,    41,    16,    17,    18,    35,
      36,    37,    38,    46,    47,    35,    36,    37,    38,    39,
      46,    44,    42,    43,    44,    45,    12,    13,    14,    15,
      50,    51,    52,    53,    20,    21,    22,    23,    14,    15,
      35,    36,    37,    38,    20,    21,    22,    23,    45,    35,
      36,    37,    38,    39,    14,    15,    42,    43,    44,    45,
      20,    21,    22,    23,    50,    51,    52,    53,    44,    45,
      47,    44,    49,    23,    50,    51,    52,    53,     5,     6,
       7,     8,     9,    19,    41,    45,    99,   100,    23,    19,
      50,    51,    52,    53,    30,    31,    32,    33,    34,    10,
      35,    36,    37,    38,    46,    47,    46,    47,    46,    47,
     106,   107,    46,    47,    23,     9,    45,    45,   159,    29,
      -1,   153,    48,   115,   112
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    23,    35,    36,    37,    38,    55,    56,    57,
      58,    64,    67,    85,    87,     4,     0,    58,    23,    68,
      69,    87,    42,    45,    60,    11,    40,    70,    44,    47,
      60,    12,    13,    14,    15,    20,    21,    22,    23,    39,
      43,    44,    45,    50,    51,    52,    53,    60,    61,    62,
      63,    64,    65,    66,    67,    71,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    86,    87,    23,
      46,    67,    88,    89,    90,    56,     5,     6,     7,     8,
       9,    59,    19,    23,    69,    45,    23,    75,    45,    76,
      43,    62,    44,    44,    47,    24,    25,    72,    79,    28,
      29,    48,    26,    27,    40,    41,    14,    15,    16,    17,
      18,    44,    45,    23,    46,    47,    46,    47,    41,    71,
      10,    75,    46,    71,    19,    30,    31,    32,    33,    34,
      73,    79,    82,    82,    76,    83,    83,    83,    83,    84,
      84,    79,    79,    79,    46,    90,    89,    23,    56,    46,
      47,    75,    71,    49,    46,    76,    76,    74,    46,    46,
      65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    56,    56,    57,    57,    58,    58,
      59,    59,    59,    59,    59,    60,    60,    61,    61,    62,
      62,    62,    62,    62,    63,    63,    64,    65,    65,    65,
      66,    67,    67,    67,    67,    68,    68,    70,    69,    69,
      71,    72,    71,    73,    73,    73,    73,    73,    73,    74,
      74,    75,    75,    76,    76,    77,    77,    77,    77,    77,
      78,    78,    78,    79,    79,    80,    80,    80,    80,    80,
      80,    81,    81,    81,    82,    82,    82,    82,    82,    83,
      83,    83,    84,    84,    84,    84,    85,    85,    86,    86,
      87,    87,    87,    87,    88,    88,    89,    89,    90,    90
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     6,     4,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     1,     2,     1,
       1,     2,     2,     2,     4,     6,     3,     1,     1,     1,
       7,     1,     1,     1,     1,     1,     3,     0,     4,     1,
       1,     0,     4,     1,     1,     1,     1,     1,     1,     1,
       5,     1,     2,     1,     3,     1,     1,     1,     1,     3,
       1,     2,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     2,     4,     3,
       1,     4,     4,     3,     1,     3,     2,     1,     1,     3
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
#line 128 "ast.y" /* yacc.c:1646  */
    {
				/*
				Todo: 
				Write a function to clean symbol symbol. Remove entries with dtype = -1. 
				Or just don't print it in symbol table
				cleansymbol();
				*/
				cleansymbol();	//I wrote a function already to remove dtype = -1
                printsymtable();
                return 0;
            }
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 178 "ast.y" /* yacc.c:1646  */
    {
				create_node("stmt", 0);
			}
#line 1518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 189 "ast.y" /* yacc.c:1646  */
    {
				create_node("return", 1);
			}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 208 "ast.y" /* yacc.c:1646  */
    {
						struct node *ftp;
						ftp = first;
						while(ftp!=NULL){
							if(ftp->scope == scope && ftp->valid == 1){
								ftp->valid = 0;
							}
							ftp=ftp->link;
						}
						scope--;

					}
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 229 "ast.y" /* yacc.c:1646  */
    { 
				// create_node("cond", 0); 
				// create_node("body", 0);
				create_node("for", 0); 
			}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 240 "ast.y" /* yacc.c:1646  */
    {	datatype = (yyvsp[0].ival); }
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 241 "ast.y" /* yacc.c:1646  */
    {	datatype = (yyvsp[0].ival); }
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 242 "ast.y" /* yacc.c:1646  */
    {	datatype = (yyvsp[0].ival); }
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 243 "ast.y" /* yacc.c:1646  */
    {	datatype = (yyvsp[0].ival); }
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 254 "ast.y" /* yacc.c:1646  */
    { create_node((yyvsp[0].ptr)->name, 1); }
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 255 "ast.y" /* yacc.c:1646  */
    {	


						if((yyvsp[-3].ptr)->dtype !=- 1 && (yyvsp[-3].ptr)->scope < scope && (yyvsp[-3].ptr)->valid == 1){
							// printf("case 1 \n" );
																		
							struct node *ftp, *nnode;
							nnode = (struct node *)malloc(sizeof(struct node));
							ftp = first;
							while(ftp->link!=NULL){
								ftp = ftp->link;
							}
							addsymbol(nnode,(yyvsp[-3].ptr)->name);	
							ftp->link = nnode;
							nnode->link = NULL;
							(yyvsp[-3].ptr) = nnode;

							if (datatype == 0){	
								
								addInt((yyvsp[-3].ptr), 0, (yyvsp[0].fval));
								if(assigntype == 1){
									printf("Line:%d: ", line);
									printf("\033[1;35m"); 
									printf("warning: ");
									printf("\033[0m");
									printf("implicit conversion from \'float\' to \'int\' \n\n");
								}
							}
							else if(datatype == 1){
								
								addFloat((yyvsp[-3].ptr), 1, (yyvsp[0].fval));
								if(assigntype == 2){
									printf("Line:%d: ", line);
									printf("\033[1;35m"); 
									printf("warning: ");
									printf("\033[0m");
									printf("implicit conversion from \'char\' to \'float\' \n\n");
								}
							}
							else if(datatype == 2){
								float tempf = (float)(yyvsp[0].fval);
								addChar((yyvsp[-3].ptr), 2, (int)tempf);

								if(assigntype == 1){
									printf("Line:%d: ", line);
									printf("\033[1;35m"); 
									printf("warning: ");
									printf("\033[0m");
									printf("implicit conversion from \'float\' to \'char\' \n\n");
								}
							}
							x = datatype;
							
							create_node("=", 0);

						}

						
						else if((yyvsp[-3].ptr)->dtype !=- 1){

								printf("Line:%d: ", line);
								printf("\033[1;31m");
								printf("error: ");
								printf("\033[0m");
								printf("redefinition of \'%s\' \n",  (yyvsp[-3].ptr)->name);
						}
						else{
							
							
							create_node("=", 0);

							if (datatype == 0){	
								
								addInt((yyvsp[-3].ptr), 0, (yyvsp[0].fval));
								if(assigntype == 1){
									printf("Line:%d: ", line);
									printf("\033[1;35m"); 
									printf("warning: ");
									printf("\033[0m");
									printf("implicit conversion from \'float\' to \'int\' \n\n");
								}
							}
							else if(datatype == 1){
								
								addFloat((yyvsp[-3].ptr), 1, (yyvsp[0].fval));
								if(assigntype == 2){
									printf("Line:%d: ", line);
									printf("\033[1;35m"); 
									printf("warning: ");
									printf("\033[0m");
									printf("implicit conversion from \'char\' to \'float\' \n\n");
								}
							}
							else if(datatype == 2){
								float tempf = (float)(yyvsp[0].fval);
								addChar((yyvsp[-3].ptr), 2, (int)tempf);

								if(assigntype == 1){
									printf("Line:%d: ", line);
									printf("\033[1;35m"); 
									printf("warning: ");
									printf("\033[0m");
									printf("implicit conversion from \'float\' to \'char\' \n\n");
								}
							}
							x = datatype;
							
						}
					}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 365 "ast.y" /* yacc.c:1646  */
    {	//previous. a , dtype = 1(int)
						// printf("type = %d\nscope = %d\nvalid = %d", $1->dtype, $1->scope, $1->valid);
						if((yyvsp[0].ptr)->dtype !=- 1 && (yyvsp[0].ptr)->scope < scope && (yyvsp[0].ptr)->valid == 1){
							// printf("case 1 \n" );
																		
							struct node *ftp, *nnode;
							nnode = (struct node *)malloc(sizeof(struct node));
							ftp = first;
							while(ftp->link!=NULL){
								ftp = ftp->link;
							}
							addsymbol(nnode,(yyvsp[0].ptr)->name);	
							ftp->link = nnode;
							nnode->link = NULL;							
							(yyvsp[0].ptr) = nnode;
							
							if (datatype == 0){	
								addInt((yyvsp[0].ptr), 0, INT_MIN);
							}
							else if(datatype == 1){
								addFloat((yyvsp[0].ptr), 1, INT_MIN);
							}
							else if(datatype == 2){
								addChar((yyvsp[0].ptr), 2, '-');
		
							}
							x = datatype;

							char buff[20];
							strcpy(buff, "Dc ");
							strcat(buff, (yyvsp[0].ptr)->name);
							create_node(buff, 1);

						}
						else if((yyvsp[0].ptr)->dtype !=- 1 ){
							printf("Line:%d: ", line);
							printf("\033[1;31m");
							printf("error: ");
							printf("\033[0m");
							printf("redefinition of \'%s\' \n", (yyvsp[0].ptr)->name);
						
						}else{
							

							if (datatype == 0){	
								addInt((yyvsp[0].ptr), 0, INT_MIN);
							}
							else if(datatype == 1){
								addFloat((yyvsp[0].ptr), 1, INT_MIN);
							}
							else if(datatype == 2){
								addChar((yyvsp[0].ptr), 2, '-');
		
							}
							x = datatype;

							char buff[20];
							strcpy(buff, "Dc ");
							strcat(buff, (yyvsp[0].ptr)->name);
							create_node(buff, 1);
						
						}
					}
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 432 "ast.y" /* yacc.c:1646  */
    {	(yyval.fval) = (yyvsp[0].fval); }
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 433 "ast.y" /* yacc.c:1646  */
    { crt = lhs; }
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 434 "ast.y" /* yacc.c:1646  */
    {							
				switch(assignop){
					case 0: if(idcheck == 1){
								create_node("=", 0);
								if(crt->dtype == 0){
									if(assigntype == 1){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'float\' to \'int\' \n\n");
									}
									crt->val.i = (int)(yyvsp[0].fval);
									
								}
								else if(crt->dtype == 1){
									if(assigntype == 2){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'char\' to \'float\' \n\n");
									}
									crt->val.f = (yyvsp[0].fval);
								}
								else if(crt->dtype == 2){
									if(assigntype == 1){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'float\' to \'char\' \n\n");
									}
									crt->val.c = (char)((int)(yyvsp[0].fval));
								}
							}
							else{
								printf("We'll see later\n");
							}
							crt = NULL;
							break;

					case 1: if(idcheck == 1){
								create_node("+=", 0);
								if(crt->dtype == 0){
									if(assigntype == 1){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'float\' to \'int\' \n\n");
									}
									crt->val.i = (int)(yyvsp[-3].fval) + (int)(yyvsp[0].fval);
								}
								else if(crt->dtype == 1){
									if(assigntype == 2){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'char\' to \'float\' \n\n");
									}
									crt->val.f = (yyvsp[-3].fval)+ (yyvsp[0].fval);
								}
								else if(crt->dtype == 2){
									if(assigntype == 1){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'float\' to \'char\' \n\n");
									}
									crt->val.c = (char)((int)(yyvsp[-3].fval) + (int)(yyvsp[0].fval));
								}
							}
							else{
								printf("We'll see later\n");
							}
							crt = NULL;
							break;

					case 2:	if(idcheck == 1){
							create_node("-=", 0);
								if(crt->dtype == 0){
									if(assigntype == 1){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'float\' to \'int\' \n\n");
									}
									crt->val.i = (int)(yyvsp[-3].fval) - (int)(yyvsp[0].fval);
								}
								else if(crt->dtype == 1){
									if(assigntype == 2){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'char\' to \'float\' \n\n");
									}
									crt->val.f = (yyvsp[-3].fval) - (yyvsp[0].fval);
								}
								else if(crt->dtype == 2){
									if(assigntype == 1){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'float\' to \'char\' \n\n");
									}
									crt->val.c = (char)((int)(yyvsp[-3].fval) - (int)(yyvsp[0].fval));
								}
							}
							else{
								printf("We'll see later\n");
							}
							crt = NULL;
							break;

					case 3:	if(idcheck == 1){
								create_node("*=", 0);
								if(crt->dtype == 0){
									if(assigntype == 1){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'float\' to \'int\' \n\n");
									}
									crt->val.i = (int)(yyvsp[-3].fval) * (int)(yyvsp[0].fval);
								}
								else if(crt->dtype == 1){
									if(assigntype == 2){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'char\' to \'float\' \n\n");
									}
									crt->val.f = (yyvsp[-3].fval) * (yyvsp[0].fval);
								}
								else if(crt->dtype == 2){
									if(assigntype == 1){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'float\' to \'char\' \n\n");
									}
									crt->val.c = (char)((int)(yyvsp[-3].fval) * (int)(yyvsp[0].fval));
								}
							}
							else{
								printf("We'll see later\n");
							}
							crt = NULL;
							break;

					case 4:	if(idcheck == 1){
								create_node("/=", 0);
								if(crt->dtype == 0){
									if(assigntype == 1){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'float\' to \'int\' \n\n");
									}
									crt->val.i = (int)(yyvsp[-3].fval) / (int)(yyvsp[0].fval);
								}
								else if(crt->dtype == 1){
									if(assigntype == 2){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'char\' to \'float\' \n\n");
									}
									crt->val.f = (yyvsp[-3].fval) / (yyvsp[0].fval);
								}
								else if(crt->dtype == 2){
									if(assigntype == 1){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'float\' to \'char\' \n\n");
									}
									crt->val.c = (char)((int)(yyvsp[-3].fval) / (int)(yyvsp[0].fval));
								}
							}
							else{
								printf("We'll see later\n");
							}
							crt = NULL;
							break;

					case 5:	if(idcheck == 1){
								create_node("%=", 0);
								if(crt->dtype == 0){
									if(assigntype == 1){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'float\' to \'int\' \n\n");
									}
									crt->val.i = (int)(yyvsp[-3].fval) % (int)(yyvsp[0].fval);
								}
								else if(crt->dtype == 1){
									if(assigntype == 2){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'char\' to \'float\' \n\n");
									}
									crt->val.f = (int)(yyvsp[-3].fval) % (int)(yyvsp[0].fval);
								}
								else if(crt->dtype == 2){
									if(assigntype == 1){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'float\' to \'char\' \n\n");
									}
									crt->val.c = (char)((int)(yyvsp[-3].fval) % (int)(yyvsp[0].fval));
								}
							}
							else{
								printf("We'll see later\n");
							}
							crt = NULL;
							break;


				}
				assignop = -1;
				assigntype = -1;
			}
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 682 "ast.y" /* yacc.c:1646  */
    {	assignop = 0;	}
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 683 "ast.y" /* yacc.c:1646  */
    {	assignop = 1;	}
#line 2036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 684 "ast.y" /* yacc.c:1646  */
    {	assignop = 2;	}
#line 2042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 685 "ast.y" /* yacc.c:1646  */
    {	assignop = 3;	}
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 686 "ast.y" /* yacc.c:1646  */
    {	assignop = 4;	}
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 687 "ast.y" /* yacc.c:1646  */
    {	assignop = 5;	}
#line 2060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 692 "ast.y" /* yacc.c:1646  */
    {	(yyval.fval) = (yyvsp[0].fval);	}
#line 2066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 694 "ast.y" /* yacc.c:1646  */
    {
				create_node("else", 0);
				create_node("if", 0);
				if((yyvsp[-4].fval) == 1){
					(yyval.fval) = (yyvsp[-2].fval);

				}else{
					(yyval.fval) = (yyvsp[0].fval);
				}
			}
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 708 "ast.y" /* yacc.c:1646  */
    {				}
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 709 "ast.y" /* yacc.c:1646  */
    {				}
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 714 "ast.y" /* yacc.c:1646  */
    {		}
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 715 "ast.y" /* yacc.c:1646  */
    {		}
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 721 "ast.y" /* yacc.c:1646  */
    {					
					idcheck = 1;
					lhs = (yyvsp[0].ptr);

					if((yyvsp[0].ptr)->dtype == -1 && check_un == 0){

						printf("Line:%d: ", line);
						printf("\033[1;31m");
						printf("error: ");
						printf("\033[0m");
						printf("use of undeclared identifier \'%s\' \n\n", (yyvsp[0].ptr)->name);

						check_un = 0;		// set check_un = -1

					}
					else if((yyvsp[0].ptr)->dtype == 0){
						(yyval.fval) = (yyvsp[0].ptr)->val.i;
						assigntype = 0;
						create_node((yyvsp[0].ptr)->name, 1);
					}
					else if((yyvsp[0].ptr)->dtype == 1){
						(yyval.fval) = (yyvsp[0].ptr)->val.f;
						assigntype = 1;
						create_node((yyvsp[0].ptr)->name, 1);
					}
					else if((yyvsp[0].ptr)->dtype == 2){
						(yyval.fval) = (yyvsp[0].ptr)->val.c;
						assigntype = 2;
						create_node((yyvsp[0].ptr)->name, 1);
					}
						
									
				}
#line 2143 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 755 "ast.y" /* yacc.c:1646  */
    {
					(yyval.fval) = (yyvsp[0].ival);
					assigntype = 0;
				
					sprintf(tempStr, "%d", (int)(yyvsp[0].ival));
					create_node(tempStr, 1);
				}
#line 2155 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 764 "ast.y" /* yacc.c:1646  */
    {	
					assigntype = 1;
					if(datatype == 1){
						(yyval.fval) = (yyvsp[0].fval);
					}
					else if(datatype == 0){
						
						(yyval.fval) = (int)(yyvsp[0].fval);
					}
					else if(datatype == 2){

						(yyval.fval) = (int)(yyvsp[0].fval);
					}

					sprintf(tempStr, "%f", (yyvsp[0].fval));
					create_node(tempStr, 1);
				}
#line 2177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 782 "ast.y" /* yacc.c:1646  */
    {	
					assigntype = 2;
					if(datatype == 2){
						int tempc = (int)(yyvsp[0].cval);
						(yyval.fval) =  (float)tempc;
					}
					else if(datatype == 0){
						(yyval.fval) = (int)(yyvsp[0].cval);
					}
					else if(datatype == 1){
						
						(yyval.fval) = (int)(yyvsp[0].cval);
					}

					sprintf(tempStr, "%c", (yyvsp[0].cval));
					create_node(tempStr, 1);
				}
#line 2199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 800 "ast.y" /* yacc.c:1646  */
    {
					(yyval.fval) = (yyvsp[-1].fval);
				}
#line 2207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 810 "ast.y" /* yacc.c:1646  */
    {	(yyval.fval) = (yyvsp[0].fval);	}
#line 2213 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 811 "ast.y" /* yacc.c:1646  */
    {	(yyvsp[-1].fval)++; (yyval.fval) = (yyvsp[-1].fval);	create_node("++", 0); }
#line 2219 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 812 "ast.y" /* yacc.c:1646  */
    {	(yyvsp[-1].fval)--; (yyval.fval) = (yyvsp[-1].fval);	create_node("--", 0); }
#line 2225 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 817 "ast.y" /* yacc.c:1646  */
    {	(yyval.fval) = (yyvsp[0].fval);	}
#line 2231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 819 "ast.y" /* yacc.c:1646  */
    {
					switch(unaryop){
						case 1:	(yyval.fval) = (yyvsp[0].fval);
								create_node("'+'", 0);
								break;
						case 2:	(yyval.fval) = -(yyvsp[0].fval);
								create_node("'+'", 0);
								break;
						case 3:	(yyval.fval) = !(yyvsp[0].fval);
								create_node("!", 0);
								break;
						case 4:	(yyval.fval) = ~((int)(yyvsp[0].fval));
								create_node("~", 0);
								break;	
						case 5:	(yyval.fval) = ++(yyvsp[0].fval);
								create_node("++", 0);							
								break;
						case 6:	(yyval.fval) = --(yyvsp[0].fval);
								create_node("--", 0);
								break;		
					}
					unaryop = -1;
				}
#line 2259 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 846 "ast.y" /* yacc.c:1646  */
    {	unaryop = 1;	}
#line 2265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 847 "ast.y" /* yacc.c:1646  */
    {	unaryop = 2;	}
#line 2271 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 848 "ast.y" /* yacc.c:1646  */
    {	unaryop = 3;	}
#line 2277 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 849 "ast.y" /* yacc.c:1646  */
    {	unaryop = 4;	}
#line 2283 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 850 "ast.y" /* yacc.c:1646  */
    {	unaryop = 5;	}
#line 2289 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 851 "ast.y" /* yacc.c:1646  */
    {	unaryop = 6;	}
#line 2295 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 856 "ast.y" /* yacc.c:1646  */
    {	(yyval.fval) = (yyvsp[0].fval);	}
#line 2301 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 858 "ast.y" /* yacc.c:1646  */
    { 
					create_node("==", 0);
					if((yyvsp[-2].fval) == (yyvsp[0].fval))
						(yyval.fval) = 1;
					else
						(yyval.fval) = 0;

				}
#line 2314 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 867 "ast.y" /* yacc.c:1646  */
    { 
					create_node("!=", 0);
					if((yyvsp[-2].fval) != (yyvsp[0].fval))
						(yyval.fval) = 1;
					else
						(yyval.fval) = 0;
				}
#line 2326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 878 "ast.y" /* yacc.c:1646  */
    {	(yyval.fval) = (yyvsp[0].fval);	}
#line 2332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 880 "ast.y" /* yacc.c:1646  */
    { 
					create_node("<", 0);
					if((yyvsp[-2].fval) < (yyvsp[0].fval))
						(yyval.fval) = 1;
					else
						(yyval.fval) = 0;

				}
#line 2345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 889 "ast.y" /* yacc.c:1646  */
    { 
					create_node(">", 0);
					if((yyvsp[-2].fval) > (yyvsp[0].fval))
						(yyval.fval) = 1;
					else
						(yyval.fval) = 0;

				}
#line 2358 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 898 "ast.y" /* yacc.c:1646  */
    { 
					create_node("<=", 0);
					if((yyvsp[-2].fval) <= (yyvsp[0].fval))
						(yyval.fval) = 1;
					else
						(yyval.fval) = 0;

				}
#line 2371 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 907 "ast.y" /* yacc.c:1646  */
    { 
					create_node(">=", 0);
					if((yyvsp[-2].fval) >= (yyvsp[0].fval))
						(yyval.fval) = 1;
					else
						(yyval.fval) = 0;

				}
#line 2384 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 919 "ast.y" /* yacc.c:1646  */
    {	(yyval.fval) = (yyvsp[0].fval);	}
#line 2390 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 921 "ast.y" /* yacc.c:1646  */
    {	
				create_node("+", 0);
				(yyval.fval) = (yyvsp[-2].fval) + (yyvsp[0].fval);	
			}
#line 2399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 926 "ast.y" /* yacc.c:1646  */
    {	
				create_node("-", 0);
				(yyval.fval) = (yyvsp[-2].fval) - (yyvsp[0].fval);	
			}
#line 2408 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 934 "ast.y" /* yacc.c:1646  */
    {	(yyval.fval) = (yyvsp[0].fval);	}
#line 2414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 936 "ast.y" /* yacc.c:1646  */
    {	
						create_node("*", 0);	
						(yyval.fval) = (yyvsp[-2].fval) * (yyvsp[0].fval);	
					}
#line 2423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 941 "ast.y" /* yacc.c:1646  */
    {	
						if((yyvsp[0].fval) == 0){
							printf("Line:%d: ", line);
							printf("\033[1;35m"); 
							printf("warning: ");
							printf("\033[0m");
							printf("division by zero is undefined\n\n");
							(yyval.fval) = INT_MAX;		//junk value in real
						}else{
							(yyval.fval) = (yyvsp[-2].fval) / (yyvsp[0].fval);	
							create_node("/", 0);
						}
					}
#line 2441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 955 "ast.y" /* yacc.c:1646  */
    {	
						if(assigntype == 1){
							printf("Line:%d: ", line);
							printf("\033[1;31m");
							printf("error: ");
							printf("\033[0m");
							printf("invalid operands to binary expression (\'float\' and \'float\') \n\n");
							}else{								
								(yyval.fval) = (int)(yyvsp[-2].fval) % (int)(yyvsp[0].fval);	
								create_node("%", 0);
							}
						}
#line 2458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 974 "ast.y" /* yacc.c:1646  */
    {
					create_node((yyvsp[-1].string), 3);
					struct node *ftp;
					ftp = first;
					while(ftp!=NULL){
						if(ftp->scope == scope && ftp->valid == 1){
							ftp->valid = 0;
						}
						else if(strcmp(ftp->token, "param") == 0 && ftp->valid == 1){
							ftp->valid = 0;
						}

						ftp=ftp->link;
					}
					scope--;

				}
#line 2480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 992 "ast.y" /* yacc.c:1646  */
    {	
					create_node((yyvsp[-1].string), 3);
					printf("Line:%d: ", line);
					printf("\033[1;35m"); 
					printf("warning: ");
					printf("\033[0m");
					printf("type specifier missing, defaults to \'int\' \n");

					struct node *ftp;
					ftp = first;
					while(ftp!=NULL){
						if(ftp->scope == scope && ftp->valid == 1){
							ftp->valid = 0;
						}
						else if(strcmp(ftp->token, "param") == 0 && ftp->valid == 1){
							ftp->valid = 0;
						}

						ftp=ftp->link;
					}
					scope--;
				}
#line 2507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1025 "ast.y" /* yacc.c:1646  */
    {	
					// printf("OKAY : %s\n", $1->name);
					// create_node($1->name, 1);
					addfunc((yyvsp[0].ptr), datatype, "function");	
					strcpy((yyval.string), (yyvsp[0].ptr)->name); 								
				}
#line 2518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1031 "ast.y" /* yacc.c:1646  */
    { }
#line 2524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1032 "ast.y" /* yacc.c:1646  */
    { }
#line 2530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1033 "ast.y" /* yacc.c:1646  */
    { }
#line 2536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1038 "ast.y" /* yacc.c:1646  */
    {}
#line 2542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1039 "ast.y" /* yacc.c:1646  */
    {}
#line 2548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1044 "ast.y" /* yacc.c:1646  */
    {	addfunc((yyvsp[0].ptr), datatype, "param");	}
#line 2554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1045 "ast.y" /* yacc.c:1646  */
    {}
#line 2560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1050 "ast.y" /* yacc.c:1646  */
    {		}
#line 2566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1051 "ast.y" /* yacc.c:1646  */
    {		}
#line 2572 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2576 "y.tab.c" /* yacc.c:1646  */
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
#line 1055 "ast.y" /* yacc.c:1906  */



void yyerror(const char *str){
	fflush(stdout);
	printf("Line:%d: ", line);
	printf("\033[1;31m");
	printf("error: ");
	printf("\033[0m");
	printf("%s\n", str);
}


int main(){
	yyout = fopen("output.c", "w");


	tree_top = (tree_stack*)malloc(sizeof(tree_stack));
	tree_top->node = NULL;
	tree_top->next = NULL;
	struct Node *root;

	printf("\n");
	yyparse();

	root = pop_tree();
	get_levels(root, 1);

	printtree(root);
	

	preorder(root);
	printf("\n\nPreorder Traversal\n\n");
	printf("%s\n", preBuf);

	fclose(yyout);
	return 0;
}


void addfunc(struct node *t,int type, char *s){
	if(t->dtype == -1) {
        t->dtype = type;
        t->val.i = 0;
        strcpy(t->token, s);
    }
}


void addInt(struct node *t,int type,int val) {
    if(t->dtype == -1) {
        t->dtype = type;
        t->val.i = val;
        strcpy(t->token, "identifier");
    }
}


void addFloat(struct node *t,int type,float val) {
    if(t->dtype == -1) {
        t->dtype = type;
        t->val.f = (float)val;
        strcpy(t->token, "identifier");
    }
}


void addChar(struct node *t,int type, char val) {
   	if(t->dtype == -1) {
   	    t->dtype = type;
   	    t->val.c = (char)val;
   	    strcpy(t->token, "identifier");
   	}
}


struct node * addtosymbol(struct node * n){
	if(first == NULL){
		first = n;
	}
	else{
		struct  node * ftp = first;
		while(ftp->link !=NULL) {
			ftp = ftp->link;
		}
		ftp->link = n;
	}
	return n;
}


struct node * checksym(char *vname) {
	struct node *ftp;
	struct node *rp;
	struct node *nnode;
	struct node *same;

	//not memory efficient
	// nnode = (struct node *)malloc(sizeof(struct node));
	// addsymbol(nnode,vname);


	if(first == NULL) {
		nnode = (struct node *)malloc(sizeof(struct node));
		addsymbol(nnode,vname);
	    first = nnode;
	}
	else {
	    ftp = first;
	    while(ftp!=NULL) {

	        if(strcmp(vname,ftp->name) == 0){
	            if(ftp->scope > scope && ftp->valid == 1) {	          	
					same = ftp; 
	            	return same;
	            }	
	            else if(ftp->scope == scope && ftp->valid == 1){
	            	same = ftp;
	            	return same;
	            }          	
	            else if(ftp->scope < scope && ftp->valid == 1){
	         		check_un = 1;	//no error 

	         		same = ftp;
	            	return same;
	         			            		         				         		       	         
	            } 
	          	else if(ftp->scope > scope && ftp->valid == 0){
	          		check_un = 0;	//undeclared
	          	}

	        }            
	        rp = ftp;
	        ftp = ftp->link;
	    }
	    nnode = (struct node *)malloc(sizeof(struct node));
		addsymbol(nnode,vname);

	    rp->link = nnode;
	}
	return nnode;
}


void addsymbol(struct node *tp, char *vname) {
    strcpy(tp->name,vname);
    tp->dtype = -1;
    tp->link = NULL;
    tp->scope = scope;
    tp->valid = 1;
    tp->lineno = line;
}


void cleansymbol(){
	struct node** pp = &first; 
    while (*pp) { 
  
        struct node* entry = *pp; 
 
        if (entry->dtype == -1  ) { 
            *pp = entry->link; 
            free(entry); 
        }
        else if(strcmp(entry->name,"main")== 0 && strcmp(entry->token, "function")==0){	//remove main entry from symbol table
        	*pp = entry->link; 
            free(entry); 
        }
        // Else move to next 
        else
            pp = &(entry->link); 
    } 
}


void printsymtable(){
	struct node *ftp;
    ftp=first;
    //blue
    printf("\n\nSymbol Table\n\n");
    //white

	printf("   Symbol\t\tName\t  Type\t      Scope\t   Line Number\t       Value \n");
	printf("-------------------------------------------------------------------------------------------------\n");
   
    while(ftp!=NULL) {
        char data_type[10];
        if(ftp->dtype==0)
        	strcpy(data_type,"int");
        if(ftp->dtype==1)
        	strcpy(data_type,"float");
        if(ftp->dtype==2)
        	strcpy(data_type,"char");
        if(ftp->dtype==3)
        	strcpy(data_type,"void");

        printf("%11s\t%12s\t%6s\t\t%d\t\t%d\t\t",ftp->token, ftp->name, data_type, ftp->scope, ftp->lineno);

        if(ftp->dtype == 0){
        	if(ftp->val.i == INT_MIN)
        		printf("-\n");
        	else
           		printf("%d\n",ftp->val.i);
        }
        else if(ftp->dtype == 1){
        	if(ftp->val.f == INT_MIN)
        		printf("-\n");
        	else
           		printf("%f\n",ftp->val.f);
       	}
        else if(ftp->dtype == 2){
            printf("%c\n",ftp->val.c);
        }
        else if(strcmp(ftp->token, "function")==0){
        	printf("-\n");
        }
        else{
	        printf("-	Delete it\n");
	    }
        ftp=ftp->link;
    }
    printf("\n\n\n");
}


void create_node(char *token, int leaf) {
	Node *l;
	Node *r;
	if(leaf==0) {

		r = pop_tree();
		l = pop_tree();
	}
	else if(leaf ==1) {
		l = NULL;
		r = NULL;
	}
	else {
		l = pop_tree();
		r = NULL;
	}

	Node *newnode = (Node*)malloc(sizeof(Node));
	strcpy(newnode->token, token);
	newnode->left = l;
	newnode->right = r;
	push_tree(newnode);
}


void push_tree(Node *newnode){
	tree_stack *temp= (tree_stack*)malloc(sizeof(tree_stack));
	temp->node = newnode;
	temp->next = tree_top;
	tree_top = temp;
}


Node* pop_tree(){
	tree_stack *temp = tree_top;
	tree_top = tree_top->next;
	Node *retnode = temp->node;
	if(temp != NULL)
		free(temp);
	return retnode;
}


void printtree(Node* root){
    int h = getmaxlevel(root)-1;
    int i;
	printf("\n\nAbstract Syntax Tree\n\n");

    for (i=1; i<=h; i++){
		printf("\t");
		for(int j=0;j<=h+1-i;j++){
			printf("      ");
		}
        printGivenLevel(root, i,h);

        printf("\n\n\n");
    }
}


int getmaxlevel(Node *root){
	int count=0;
	Node *temp= root;
	while(temp->left!=NULL){
		count++;
		temp=temp->left;
	}
	return count*2;
}


void printGivenLevel(Node* root, int level, int h){
    if (root == NULL)
        return;
    if (level == 1){
		for(int j=0; j<=h-1-level; j++){
			printf(" ");
		}
	    printf("%s ", root->token);
	}
    else if (level > 1){
        printGivenLevel(root->left, level-1,h);
		for(int j=0; j<=h-1-level; j++){
			printf(" ");
		}
        printGivenLevel(root->right, level-1,h);
    }
}


void preorder(Node * node){
	if (node == NULL)
		return;

	if(node->left!=NULL && node->right!=NULL)
		strcat(preBuf, "   ( ");
	strcat(preBuf, node->token);
	strcat(preBuf, "   ");

	preorder(node-> left);

	
	if(node->right){
		preorder(node-> right);
	}
	
	if(node->left!=NULL && node->right!=NULL)
		strcat(preBuf, ")   ");
	// printf("\n");
	
}

void get_levels(Node *root, int level){
	root->level = level;
	if(root->left == NULL && root->right == NULL){
		return;
	}
	if(root->left == NULL){
		get_levels(root->right, level+1);
	}
	else if(root->right == NULL){
		get_levels(root->left, level+1);
	}
	else{
		get_levels(root->left, level+1);
		get_levels(root->right, level+1);
	}
}
