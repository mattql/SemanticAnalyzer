/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "syntactic.y"

#include <iostream>
#include <cstring>
using namespace std;

extern int yylineno; 
extern char * yytext;

char vetorClasses[400]; // Vetor para armazenar nomes de Classe
int isClass = 0; // Saber se é ou não é classe
char codigoErro; // Controle do método de exibição de erro semântico
int errosSemanticos = 0; // Total de erros semânticos
// Total de cada tipo de classe (6 variaveis abaixo)
int total_primitiva = 0; 
int total_definida = 0;
int total_axioma = 0;
int total_aninhada = 0;
int total_enumerada = 0;
int total_coberta = 0;
// Total de data property e object property
int total_dataProperty = 0;
int total_objectProperty = 0;

extern string tipoDado; // Exibe o token datatype
extern string tipoPropriedade; // Exibe o token propriedade

int yylex(void);
int yyparse(void);
void yyerror(const char *);
void semanticError(char codigoErro, int yylineno, char * vetorClasses);
void propriedades(char propriedade, char * vetorClasses);

// Constantes de cores para saída do terminal
#define RED      "\x1b[38;5;196m"
#define GREEN    "\x1b[38;5;46m"
#define GREEN2   "\x1b[32m"
#define BLUE     "\x1b[38;5;12m"
#define YELLOW   "\x1b[38;5;226m"
#define MAGENTA  "\x1b[38;5;165m"
#define MAGENTA2 "\x1b[35m"
#define CYAN     "\x1b[36m"
#define PURPLE   "\x1b[38;5;141m"
#define ORANGE   "\x1b[38;5;214m"
#define WHITE    "\x1b[37m"
#define NOCOLOR  "\x1b[0m"

#line 118 "syntactic.tab.c"

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

#include "syntactic.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SOME = 3,                       /* SOME  */
  YYSYMBOL_ALL = 4,                        /* ALL  */
  YYSYMBOL_VALUE = 5,                      /* VALUE  */
  YYSYMBOL_MIN = 6,                        /* MIN  */
  YYSYMBOL_MAX = 7,                        /* MAX  */
  YYSYMBOL_EXACTLY = 8,                    /* EXACTLY  */
  YYSYMBOL_THAT = 9,                       /* THAT  */
  YYSYMBOL_NOT = 10,                       /* NOT  */
  YYSYMBOL_AND = 11,                       /* AND  */
  YYSYMBOL_OR = 12,                        /* OR  */
  YYSYMBOL_ONLY = 13,                      /* ONLY  */
  YYSYMBOL_CLASS = 14,                     /* CLASS  */
  YYSYMBOL_EQUIVALENTTO = 15,              /* EQUIVALENTTO  */
  YYSYMBOL_INDIVIDUALS = 16,               /* INDIVIDUALS  */
  YYSYMBOL_SUBCLASSOF = 17,                /* SUBCLASSOF  */
  YYSYMBOL_DISJOINTCLASSES = 18,           /* DISJOINTCLASSES  */
  YYSYMBOL_IDCLASSE = 19,                  /* IDCLASSE  */
  YYSYMBOL_IDPROP = 20,                    /* IDPROP  */
  YYSYMBOL_SYMBOL = 21,                    /* SYMBOL  */
  YYSYMBOL_INDIVIDNAME = 22,               /* INDIVIDNAME  */
  YYSYMBOL_DATATYPE = 23,                  /* DATATYPE  */
  YYSYMBOL_CARD = 24,                      /* CARD  */
  YYSYMBOL_FLOATS = 25,                    /* FLOATS  */
  YYSYMBOL_YYACCEPT = 26,                  /* $accept  */
  YYSYMBOL_start = 27,                     /* start  */
  YYSYMBOL_class = 28,                     /* class  */
  YYSYMBOL_options = 29,                   /* options  */
  YYSYMBOL_primitiva = 30,                 /* primitiva  */
  YYSYMBOL_subclassof = 31,                /* subclassof  */
  YYSYMBOL_subclassofDescript = 32,        /* subclassofDescript  */
  YYSYMBOL_disjointclasses = 33,           /* disjointclasses  */
  YYSYMBOL_disjointclassesDescript = 34,   /* disjointclassesDescript  */
  YYSYMBOL_individuals = 35,               /* individuals  */
  YYSYMBOL_individualsDescript = 36,       /* individualsDescript  */
  YYSYMBOL_definida = 37,                  /* definida  */
  YYSYMBOL_equivalenttoD = 38,             /* equivalenttoD  */
  YYSYMBOL_equivalenttoDescript = 39,      /* equivalenttoDescript  */
  YYSYMBOL_minmaxexactly = 40,             /* minmaxexactly  */
  YYSYMBOL_axioma = 41,                    /* axioma  */
  YYSYMBOL_subclassofAxiomaDescript = 42,  /* subclassofAxiomaDescript  */
  YYSYMBOL_objectProperty = 43,            /* objectProperty  */
  YYSYMBOL_aninhada = 44,                  /* aninhada  */
  YYSYMBOL_equivalenttoA = 45,             /* equivalenttoA  */
  YYSYMBOL_equivalenttoAnin = 46,          /* equivalenttoAnin  */
  YYSYMBOL_aninhadaAux = 47,               /* aninhadaAux  */
  YYSYMBOL_someOnlyValueOr = 48,           /* someOnlyValueOr  */
  YYSYMBOL_classOrProp = 49,               /* classOrProp  */
  YYSYMBOL_enumerada = 50,                 /* enumerada  */
  YYSYMBOL_enumInstances = 51,             /* enumInstances  */
  YYSYMBOL_coberta = 52,                   /* coberta  */
  YYSYMBOL_cobertaDescript = 53            /* cobertaDescript  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   201

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  26
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  191

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   280


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    56,    56,    57,    61,    65,    66,    67,    68,    69,
      70,    71,    75,    76,    78,    79,    80,    81,    85,    89,
      90,    91,    92,    93,    94,    96,    98,   102,   106,   107,
     111,   115,   116,   120,   121,   123,   124,   125,   130,   137,
     138,   140,   142,   143,   147,   147,   147,   151,   152,   154,
     155,   160,   161,   162,   163,   172,   176,   177,   179,   180,
     185,   194,   197,   198,   202,   202,   202,   202,   206,   207,
     211,   212,   213,   214,   216,   217,   221,   222,   226,   227,
     228,   229,   231,   232,   236,   237
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SOME", "ALL", "VALUE",
  "MIN", "MAX", "EXACTLY", "THAT", "NOT", "AND", "OR", "ONLY", "CLASS",
  "EQUIVALENTTO", "INDIVIDUALS", "SUBCLASSOF", "DISJOINTCLASSES",
  "IDCLASSE", "IDPROP", "SYMBOL", "INDIVIDNAME", "DATATYPE", "CARD",
  "FLOATS", "$accept", "start", "class", "options", "primitiva",
  "subclassof", "subclassofDescript", "disjointclasses",
  "disjointclassesDescript", "individuals", "individualsDescript",
  "definida", "equivalenttoD", "equivalenttoDescript", "minmaxexactly",
  "axioma", "subclassofAxiomaDescript", "objectProperty", "aninhada",
  "equivalenttoA", "equivalenttoAnin", "aninhadaAux", "someOnlyValueOr",
  "classOrProp", "enumerada", "enumInstances", "coberta",
  "cobertaDescript", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-81)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -8,    27,     5,    79,   -81,   -81,    79,    44,   -13,    72,
      34,   -81,   -81,    86,   -81,   -81,   -81,    58,   -81,   -81,
      58,   -81,   -81,   -81,    13,    36,   -81,    55,   -81,    59,
      -3,    57,   -81,    58,    68,   -81,    77,    50,    84,   -81,
     -81,    84,   -81,    84,   -81,   108,   -81,   109,    94,    90,
     110,    84,   -81,    96,   111,   113,     7,    84,   -81,    90,
     112,   123,   -81,   -81,   -81,   115,    61,   -81,    11,    84,
     -81,   -81,   116,   134,   117,   -81,   -81,   -81,   -81,   -81,
     118,     8,   119,   -81,   110,    84,   -81,   113,   -81,    99,
     122,    92,   124,    43,   -81,   -81,   -81,   -81,   -81,   -81,
      25,   121,   -81,    84,   -81,   125,    91,    22,   -81,   126,
      78,   127,   128,   131,    97,   -81,   -81,    90,   130,   120,
     132,   100,    43,   133,   -81,   135,   -81,   -81,    24,   -81,
     136,   139,    39,   138,    98,   -81,   -81,   141,   -81,   140,
     142,   105,   143,   144,   145,   -81,   148,    42,   147,   149,
     150,   151,   157,   152,   107,   -81,   -81,    24,   155,   156,
      48,   -81,   158,   159,   164,   160,   162,   -81,   165,   166,
      24,   171,   174,   167,   168,   170,   172,   169,   179,    24,
     -81,   175,   173,   181,   176,   177,   178,   180,    24,   -81,
     -81
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    11,     4,     1,    11,     0,     0,     0,
       0,     2,     5,    12,    14,    15,     6,    33,     7,     8,
      56,     9,    10,     3,    84,     0,    38,    78,    31,    30,
      22,     0,    18,    47,    23,    28,    27,     0,    16,    17,
      37,    35,    36,    58,    59,     0,    76,     0,     0,     0,
      79,    82,    83,     0,     0,     0,     0,    49,    50,     0,
       0,     0,    13,    34,    57,     0,    70,    85,    22,     0,
      81,    32,     0,     0,    21,    55,    24,    48,    19,    29,
       0,     0,     0,    77,    71,    74,    75,     0,    80,     0,
       0,     0,     0,    64,    66,    44,    45,    46,    67,    65,
       0,     0,    40,     0,    73,    21,     0,     0,    20,    23,
       0,     0,     0,     0,     0,    60,    72,     0,     0,     0,
       0,     0,     0,     0,    43,     0,    68,    69,     0,    26,
       0,     0,     0,    23,     0,    41,    64,     0,    25,     0,
       0,     0,     0,     0,     0,    51,     0,     0,    23,     0,
       0,     0,     0,     0,     0,    39,    42,    63,     0,     0,
       0,    61,     0,     0,     0,     0,     0,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,     0,     0,     0,     0,     0,     0,     0,    63,    54,
      62
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -81,   -81,   153,   146,   -81,   -23,    -9,    37,   -81,   -10,
     -81,   -81,   185,   -81,    56,   -81,   -81,   -53,   -81,   -81,
     -81,   -26,   -80,   -81,   -81,   -81,   -81,   -81
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,    11,    12,    13,    78,    14,    36,    15,
      29,    16,    17,    26,   100,    18,    33,    34,    19,    20,
     115,   161,   162,   128,    21,    47,    22,    27
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      32,   101,    74,    39,    50,     5,     1,    42,    54,    28,
      44,    93,    82,    94,    95,    96,    97,    52,    55,     1,
      98,    99,    54,    58,    45,    56,    75,   136,    62,    94,
      76,    63,    87,    64,   105,   120,    98,    99,   109,    82,
      32,    70,    56,    84,   112,    56,     4,    77,   137,   113,
      38,    56,   140,    35,    41,   153,    86,    43,    46,    88,
      56,   165,    75,    24,    51,    25,   111,    48,   133,    61,
      57,     8,    49,    10,     8,   104,    10,     8,    49,    10,
      53,   122,   108,    83,    95,    96,    97,    69,   148,    59,
     173,    30,    31,   116,     7,     8,     9,    10,    60,   182,
       8,    37,     8,    85,    10,    95,    96,    97,   108,    68,
      31,    68,   107,    67,   118,   119,   126,   127,    71,    68,
     132,   103,   142,   143,    68,   147,    68,   160,    10,    65,
      66,    79,    72,    73,    80,    81,    89,    90,    91,    92,
     102,    75,   114,   130,   110,   106,   117,   121,   123,   124,
     125,   129,    23,   131,   134,     6,   135,   138,   139,   141,
     144,   145,   190,   146,   149,   150,   151,   152,   154,   158,
     155,   156,   157,   159,   163,   164,   168,     0,     0,   166,
     167,   169,   170,   174,   171,   172,   175,   177,   176,   178,
     180,   181,   179,   185,   183,   184,   187,   186,    40,   188,
       0,   189
};

static const yytype_int16 yycheck[] =
{
       9,    81,    55,    13,    27,     0,    14,    17,    11,    22,
      20,     3,    65,     5,     6,     7,     8,    27,    21,    14,
      12,    13,    11,    33,    11,     3,    19,     3,    38,     5,
      23,    41,    21,    43,    87,    13,    12,    13,    91,    92,
      49,    51,     3,    66,    19,     3,    19,    57,   128,    24,
      13,     3,    13,    19,    17,    13,    66,    20,    22,    69,
       3,    13,    19,    19,    27,    21,    23,    12,   121,    19,
      33,    16,    17,    18,    16,    85,    18,    16,    17,    18,
      21,     3,    91,    22,     6,     7,     8,    50,   141,    21,
     170,    19,    20,   103,    15,    16,    17,    18,    21,   179,
      16,    15,    16,    66,    18,     6,     7,     8,   117,    19,
      20,    19,    20,    19,    23,    24,    19,    20,    22,    19,
      20,    84,    24,    25,    19,    20,    19,    20,    18,    21,
      21,    19,    21,    20,    11,    20,    20,     3,    21,    21,
      21,    19,    21,    23,    20,    89,    21,    21,    21,    21,
      19,    21,     6,    21,    21,     2,    21,    21,    19,    21,
      19,    21,   188,    21,    21,    21,    21,    19,    21,    12,
      21,    21,    21,    21,    19,    19,    12,    -1,    -1,    21,
      21,    21,    20,    12,    19,    19,    12,    19,    21,    19,
      21,    12,    20,    12,    19,    22,    19,    21,    13,    21,
      -1,    21
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    14,    27,    28,    19,     0,    28,    15,    16,    17,
      18,    29,    30,    31,    33,    35,    37,    38,    41,    44,
      45,    50,    52,    29,    19,    21,    39,    53,    22,    36,
      19,    20,    32,    42,    43,    19,    34,    15,    33,    35,
      38,    33,    35,    33,    35,    11,    22,    51,    12,    17,
      31,    33,    35,    21,    11,    21,     3,    33,    35,    21,
      21,    19,    35,    35,    35,    21,    21,    19,    19,    33,
      35,    22,    21,    20,    43,    19,    23,    35,    32,    19,
      11,    20,    43,    22,    31,    33,    35,    21,    35,    20,
       3,    21,    21,     3,     5,     6,     7,     8,    12,    13,
      40,    48,    21,    33,    35,    43,    40,    20,    32,    43,
      20,    23,    19,    24,    21,    46,    35,    21,    23,    24,
      13,    21,     3,    21,    21,    19,    19,    20,    49,    21,
      23,    21,    20,    43,    21,    21,     3,    48,    21,    19,
      13,    21,    24,    25,    19,    21,    21,    20,    43,    21,
      21,    21,    19,    13,    21,    21,    21,    21,    12,    21,
      20,    47,    48,    19,    19,    13,    21,    21,    12,    21,
      20,    19,    19,    48,    12,    12,    21,    19,    19,    20,
      21,    12,    48,    19,    22,    12,    21,    19,    21,    21,
      47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    26,    27,    27,    28,    29,    29,    29,    29,    29,
      29,    29,    30,    30,    30,    30,    30,    30,    31,    32,
      32,    32,    32,    32,    32,    32,    32,    33,    34,    34,
      35,    36,    36,    37,    37,    37,    37,    37,    38,    39,
      39,    39,    39,    39,    40,    40,    40,    41,    41,    41,
      41,    42,    42,    42,    42,    43,    44,    44,    44,    44,
      45,    46,    47,    47,    48,    48,    48,    48,    49,    49,
      50,    50,    50,    50,    50,    50,    51,    51,    52,    52,
      52,    52,    52,    52,    53,    53
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     2,     1,     1,     1,     1,     1,
       1,     0,     1,     3,     1,     1,     2,     2,     2,     3,
       5,     3,     1,     1,     3,     8,     7,     2,     1,     3,
       2,     1,     3,     1,     3,     2,     2,     2,     2,    11,
       5,     8,    11,     7,     1,     1,     1,     2,     4,     3,
       3,     9,    13,    17,    21,     3,     1,     3,     2,     2,
       7,     7,    11,     0,     1,     1,     1,     1,     1,     1,
       4,     5,     7,     6,     5,     5,     1,     3,     2,     3,
       5,     4,     3,     3,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 4: /* class: CLASS IDCLASSE  */
#line 61 "syntactic.y"
                      {isClass = 0; strcpy(vetorClasses, yytext);}
#line 1282 "syntactic.tab.c"
    break;

  case 12: /* primitiva: subclassof  */
#line 75 "syntactic.y"
                      {cout << GREEN << "\n1️⃣  Classe Primitiva ⭢ " << vetorClasses << "\n"; total_primitiva++;}
#line 1288 "syntactic.tab.c"
    break;

  case 13: /* primitiva: subclassof disjointclasses individuals  */
#line 76 "syntactic.y"
                                                 {cout << GREEN << "\n1️⃣  Classe Primitiva ⭢ " << vetorClasses << "\n"; total_primitiva++;}
#line 1294 "syntactic.tab.c"
    break;

  case 14: /* primitiva: disjointclasses  */
#line 78 "syntactic.y"
                          {semanticError('C', yylineno, vetorClasses); errosSemanticos++;}
#line 1300 "syntactic.tab.c"
    break;

  case 15: /* primitiva: individuals  */
#line 79 "syntactic.y"
                      {semanticError('D', yylineno, vetorClasses); errosSemanticos++;}
#line 1306 "syntactic.tab.c"
    break;

  case 16: /* primitiva: subclassof disjointclasses  */
#line 80 "syntactic.y"
                                     {semanticError('A', yylineno, vetorClasses); errosSemanticos++;}
#line 1312 "syntactic.tab.c"
    break;

  case 17: /* primitiva: subclassof individuals  */
#line 81 "syntactic.y"
                                 {semanticError('B', yylineno, vetorClasses); errosSemanticos++;}
#line 1318 "syntactic.tab.c"
    break;

  case 24: /* subclassofDescript: IDPROP SOME DATATYPE  */
#line 94 "syntactic.y"
                               {propriedades('D', vetorClasses); total_dataProperty++;}
#line 1324 "syntactic.tab.c"
    break;

  case 25: /* subclassofDescript: IDCLASSE AND SYMBOL IDPROP minmaxexactly CARD DATATYPE SYMBOL  */
#line 96 "syntactic.y"
                                                                        {propriedades('D', vetorClasses); total_dataProperty++;}
#line 1330 "syntactic.tab.c"
    break;

  case 26: /* subclassofDescript: IDCLASSE AND SYMBOL IDPROP minmaxexactly DATATYPE SYMBOL  */
#line 98 "syntactic.y"
                                                                   {semanticError('G', yylineno, vetorClasses); propriedades('D', vetorClasses); total_dataProperty++; errosSemanticos++;}
#line 1336 "syntactic.tab.c"
    break;

  case 33: /* definida: equivalenttoD  */
#line 120 "syntactic.y"
                        {cout << BLUE << "\n2️⃣  Classe Definida ⭢ " << vetorClasses << "\n"; total_definida++;}
#line 1342 "syntactic.tab.c"
    break;

  case 34: /* definida: equivalenttoD disjointclasses individuals  */
#line 121 "syntactic.y"
                                                    {cout << BLUE << "\n2️⃣  Classe Definida ⭢ " << vetorClasses << "\n"; total_definida++;}
#line 1348 "syntactic.tab.c"
    break;

  case 35: /* definida: equivalenttoD disjointclasses  */
#line 123 "syntactic.y"
                                        {semanticError('A', yylineno, vetorClasses); errosSemanticos++;}
#line 1354 "syntactic.tab.c"
    break;

  case 36: /* definida: equivalenttoD individuals  */
#line 124 "syntactic.y"
                                    {semanticError('B', yylineno, vetorClasses); errosSemanticos++;}
#line 1360 "syntactic.tab.c"
    break;

  case 37: /* definida: subclassof equivalenttoD  */
#line 125 "syntactic.y"
                                   {semanticError('E', yylineno, vetorClasses); errosSemanticos++;}
#line 1366 "syntactic.tab.c"
    break;

  case 39: /* equivalenttoDescript: IDCLASSE AND SYMBOL IDPROP SOME DATATYPE SYMBOL SYMBOL CARD SYMBOL SYMBOL  */
#line 137 "syntactic.y"
                                                                                  {propriedades('D', vetorClasses); total_dataProperty++;}
#line 1372 "syntactic.tab.c"
    break;

  case 41: /* equivalenttoDescript: IDCLASSE AND SYMBOL IDPROP minmaxexactly CARD IDCLASSE SYMBOL  */
#line 140 "syntactic.y"
                                                                        {propriedades('O', vetorClasses); total_objectProperty++;}
#line 1378 "syntactic.tab.c"
    break;

  case 42: /* equivalenttoDescript: IDCLASSE AND SYMBOL IDPROP SOME DATATYPE SYMBOL SYMBOL FLOATS SYMBOL SYMBOL  */
#line 142 "syntactic.y"
                                                                                      {cout << ORANGE << "\nTipo de dado encontrado: '" << tipoDado << "' na classe: " << vetorClasses << NOCOLOR; semanticError('F', yylineno, vetorClasses); propriedades('D', vetorClasses); total_dataProperty++; errosSemanticos++;}
#line 1384 "syntactic.tab.c"
    break;

  case 43: /* equivalenttoDescript: IDCLASSE AND SYMBOL IDPROP minmaxexactly IDCLASSE SYMBOL  */
#line 143 "syntactic.y"
                                                                   {semanticError('G', yylineno, vetorClasses); propriedades('O', vetorClasses); total_objectProperty++; errosSemanticos++;}
#line 1390 "syntactic.tab.c"
    break;

  case 47: /* axioma: SUBCLASSOF subclassofAxiomaDescript  */
#line 151 "syntactic.y"
                                            {cout << YELLOW << "\n3️⃣ 1️⃣  Classe com axioma de fechamento e Primitiva ⭢ " << vetorClasses << "\n"; total_axioma++;}
#line 1396 "syntactic.tab.c"
    break;

  case 48: /* axioma: SUBCLASSOF subclassofAxiomaDescript disjointclasses individuals  */
#line 152 "syntactic.y"
                                                                          {cout << YELLOW << "\n3️⃣ 1️⃣  Classe com axioma de fechamento e Primitiva ⭢ " << vetorClasses << "\n"; total_axioma++;}
#line 1402 "syntactic.tab.c"
    break;

  case 49: /* axioma: SUBCLASSOF subclassofAxiomaDescript disjointclasses  */
#line 154 "syntactic.y"
                                                              {semanticError('A', yylineno, vetorClasses); errosSemanticos++;}
#line 1408 "syntactic.tab.c"
    break;

  case 50: /* axioma: SUBCLASSOF subclassofAxiomaDescript individuals  */
#line 155 "syntactic.y"
                                                          {semanticError('B', yylineno, vetorClasses); errosSemanticos++;}
#line 1414 "syntactic.tab.c"
    break;

  case 51: /* subclassofAxiomaDescript: IDCLASSE SYMBOL objectProperty SYMBOL IDPROP ONLY SYMBOL IDCLASSE SYMBOL  */
#line 160 "syntactic.y"
                                                                                                   {propriedades('O', vetorClasses); total_objectProperty++;}
#line 1420 "syntactic.tab.c"
    break;

  case 52: /* subclassofAxiomaDescript: IDCLASSE SYMBOL objectProperty SYMBOL objectProperty SYMBOL IDPROP ONLY SYMBOL IDCLASSE OR IDCLASSE SYMBOL  */
#line 161 "syntactic.y"
                                                                                                                     {propriedades('O', vetorClasses); total_objectProperty++;}
#line 1426 "syntactic.tab.c"
    break;

  case 53: /* subclassofAxiomaDescript: IDCLASSE SYMBOL objectProperty SYMBOL objectProperty SYMBOL objectProperty SYMBOL IDPROP ONLY SYMBOL IDCLASSE OR IDCLASSE OR IDCLASSE SYMBOL  */
#line 162 "syntactic.y"
                                                                                                                                                       {propriedades('O', vetorClasses); total_objectProperty++;}
#line 1432 "syntactic.tab.c"
    break;

  case 54: /* subclassofAxiomaDescript: IDCLASSE SYMBOL objectProperty SYMBOL objectProperty SYMBOL objectProperty SYMBOL objectProperty SYMBOL IDPROP ONLY SYMBOL IDCLASSE OR IDCLASSE OR IDCLASSE OR IDCLASSE SYMBOL  */
#line 163 "syntactic.y"
                                                                                                                                                                                         {propriedades('O', vetorClasses); total_objectProperty++;}
#line 1438 "syntactic.tab.c"
    break;

  case 55: /* objectProperty: IDPROP SOME IDCLASSE  */
#line 172 "syntactic.y"
                                     {propriedades('O', vetorClasses); total_objectProperty++;}
#line 1444 "syntactic.tab.c"
    break;

  case 56: /* aninhada: equivalenttoA  */
#line 176 "syntactic.y"
                        {cout << MAGENTA << "\n4️⃣ 2️⃣  Classe com descrições aninhadas e Definida ⭢ " << vetorClasses << "\n"; total_aninhada++;}
#line 1450 "syntactic.tab.c"
    break;

  case 57: /* aninhada: equivalenttoA disjointclasses individuals  */
#line 177 "syntactic.y"
                                                    {cout << MAGENTA << "\n4️⃣ 2️⃣  Classe com descrições aninhadas e Definida ⭢ " << vetorClasses << "\n"; total_aninhada++;}
#line 1456 "syntactic.tab.c"
    break;

  case 58: /* aninhada: equivalenttoA disjointclasses  */
#line 179 "syntactic.y"
                                        {semanticError('A', yylineno, vetorClasses); errosSemanticos++;}
#line 1462 "syntactic.tab.c"
    break;

  case 59: /* aninhada: equivalenttoA individuals  */
#line 180 "syntactic.y"
                                    {semanticError('B', yylineno, vetorClasses); errosSemanticos++;}
#line 1468 "syntactic.tab.c"
    break;

  case 60: /* equivalenttoA: EQUIVALENTTO IDCLASSE AND SYMBOL IDPROP someOnlyValueOr equivalenttoAnin  */
#line 185 "syntactic.y"
                                                                                        {propriedades('O', vetorClasses); total_objectProperty++;}
#line 1474 "syntactic.tab.c"
    break;

  case 62: /* aninhadaAux: someOnlyValueOr SYMBOL IDPROP someOnlyValueOr SYMBOL IDPROP someOnlyValueOr INDIVIDNAME SYMBOL SYMBOL aninhadaAux  */
#line 197 "syntactic.y"
                                                                                                                               {propriedades('O', vetorClasses); total_objectProperty++; total_objectProperty++;}
#line 1480 "syntactic.tab.c"
    break;

  case 69: /* classOrProp: IDPROP  */
#line 207 "syntactic.y"
                 {propriedades('O', vetorClasses); total_objectProperty++;}
#line 1486 "syntactic.tab.c"
    break;

  case 70: /* enumerada: EQUIVALENTTO SYMBOL enumInstances SYMBOL  */
#line 211 "syntactic.y"
                                                    {cout << CYAN << "\n5️⃣ 2️⃣  Classe Enumerada e Definida ⭢ " << vetorClasses << "\n"; total_enumerada++;}
#line 1492 "syntactic.tab.c"
    break;

  case 71: /* enumerada: EQUIVALENTTO SYMBOL enumInstances SYMBOL subclassof  */
#line 212 "syntactic.y"
                                                              {cout << CYAN << "\n5️⃣ 2️⃣  Classe Enumerada e Definida ⭢ " << vetorClasses << "\n"; total_enumerada++;}
#line 1498 "syntactic.tab.c"
    break;

  case 72: /* enumerada: EQUIVALENTTO SYMBOL enumInstances SYMBOL subclassof disjointclasses individuals  */
#line 213 "syntactic.y"
                                                                                          {cout << CYAN << "\n5️⃣ 2️⃣  Classe Enumerada e Definida ⭢ " << vetorClasses << "\n"; total_enumerada++;}
#line 1504 "syntactic.tab.c"
    break;

  case 73: /* enumerada: EQUIVALENTTO SYMBOL enumInstances SYMBOL disjointclasses individuals  */
#line 214 "syntactic.y"
                                                                               {cout << CYAN << "\n5️⃣ 2️⃣  Classe Enumerada e Definida ⭢ " << vetorClasses << "\n"; total_enumerada++;}
#line 1510 "syntactic.tab.c"
    break;

  case 74: /* enumerada: EQUIVALENTTO SYMBOL enumInstances SYMBOL disjointclasses  */
#line 216 "syntactic.y"
                                                                   {semanticError('A', yylineno, vetorClasses); errosSemanticos++;}
#line 1516 "syntactic.tab.c"
    break;

  case 75: /* enumerada: EQUIVALENTTO SYMBOL enumInstances SYMBOL individuals  */
#line 217 "syntactic.y"
                                                               {semanticError('B', yylineno, vetorClasses); errosSemanticos++;}
#line 1522 "syntactic.tab.c"
    break;

  case 78: /* coberta: EQUIVALENTTO cobertaDescript  */
#line 226 "syntactic.y"
                                      {cout << PURPLE  << "\n6️⃣ 2️⃣  Classe Coberta e Definida ⭢ " << vetorClasses << "\n"; total_coberta++;}
#line 1528 "syntactic.tab.c"
    break;

  case 79: /* coberta: EQUIVALENTTO cobertaDescript subclassof  */
#line 227 "syntactic.y"
                                                  {cout << PURPLE  << "\n6️⃣ 2️⃣  Classe Coberta e Definida ⭢ " << vetorClasses << "\n"; total_coberta++;}
#line 1534 "syntactic.tab.c"
    break;

  case 80: /* coberta: EQUIVALENTTO cobertaDescript subclassof disjointclasses individuals  */
#line 228 "syntactic.y"
                                                                              {cout << PURPLE  << "\n6️⃣ 2️⃣  Classe Coberta e Definida ⭢ " << vetorClasses << "\n"; total_coberta++;}
#line 1540 "syntactic.tab.c"
    break;

  case 81: /* coberta: EQUIVALENTTO cobertaDescript disjointclasses individuals  */
#line 229 "syntactic.y"
                                                                   {cout << PURPLE  << "\n6️⃣ 2️⃣  Classe Coberta e Definida ⭢ " << vetorClasses << "\n"; total_coberta++;}
#line 1546 "syntactic.tab.c"
    break;

  case 82: /* coberta: EQUIVALENTTO cobertaDescript disjointclasses  */
#line 231 "syntactic.y"
                                                       {semanticError('A', yylineno, vetorClasses); errosSemanticos++;}
#line 1552 "syntactic.tab.c"
    break;

  case 83: /* coberta: EQUIVALENTTO cobertaDescript individuals  */
#line 232 "syntactic.y"
                                                   {semanticError('B', yylineno, vetorClasses); errosSemanticos++;}
#line 1558 "syntactic.tab.c"
    break;


#line 1562 "syntactic.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 240 "syntactic.y"


// Método que exibe os erros semânticos de acordo com o código
void semanticError(char codigoErro, int yylineno, char * vetorClasses){

	switch (codigoErro){
		// Códigos de A a E são relacionados a Análise da Precedência dos Operadores
		case 'A': // Código A: DisjointClasses sem Individuals depois
			cout << RED << "\n🔴 Erro semântico (linha: " << yylineno << ") | Classe: " << vetorClasses <<  
			" | DisjointClasses deve preceder Individuals \n❗ É esperado Individuals depois ❗\n";
			break;
		case 'B': // Código B: Individuals sem DisjointClasses antes
			cout << RED << "\n🔴 Erro semântico (linha: " << yylineno << ") | Classe: " << vetorClasses <<  
			" | Individuals deve suceder DisjointClasses\n❗ É esperado DisjointClasses antes ❗\n";
			break;
		case 'C': // Código C: DisjointClasses sozinho na classe
			cout << RED << "\n🔴 Erro semântico (linha: " << yylineno << ") | Classe: " << vetorClasses <<  
			" | DisjointClasses não pode existir sozinha \n❗ É esperado SubclassOf ou EquivalentTo antes e Individuals depois ❗\n";
			break;
		case 'D': // Código D: Individuals sozinho na classe
			cout << RED << "\n🔴 Erro semântico (linha: " << yylineno << ") | Classe: " << vetorClasses <<  
			" | Individuals não pode existir sozinho \n❗ É esperado DisjointClasses antes ❗\n";
			break;
		case 'E': // Código E: EquivalentTo depois de SubclassOf
			cout << RED << "\n🔴 Erro semântico (linha: " << yylineno << ") | Classe: " << vetorClasses <<  
			" | EquivalentTo não deve suceder SubclassOf\n❗ EquivalentTo deve vir ANTES de SubclassOf ❗\n";
			break;
		// Códigos F e G são relacionados a Verificação Estática de Tipos por Coerção
		case 'F': // Código F: depois de um xsd:integer não veio um número inteiro
			cout << RED << "\n🔴 Erro semântico (linha: " << yylineno << ") | Classe: " << vetorClasses <<  
			" | Número é ponto flutuante\n❗ É esperado um número inteiro ❗\n";
			break;
		case 'G': // Código G: Não tem número entre MIN, MAX, ou EXACTLY e o nome de classe ou tipo de dado
			cout << RED << "\n🔴 Erro semântico (linha: " << yylineno << ") | Classe: " << vetorClasses <<  
			" | Entre o operador (min, max ou exactly) e o nome de classe ou tipo de dado *deve haver um número* \n❗ É esperado um número ❗\n";
			break;
	}
}

// Método para exibir as propriedades para a Verificação Estática de Tipos por Sobrecarregamento
void propriedades(char propriedade, char * vetorClasses){

	if(propriedade == 'D'){ // Código D: Data Property
		cout << WHITE << "\n❕ Propriedade encontrada: '" << tipoPropriedade << "' | Tipo: Data Property | Classe: " << vetorClasses << " ❕" << NOCOLOR << "\n";
	} else if(propriedade == 'O'){ // Código O: Object Property
		cout << WHITE << "\n❕ Propriedade encontrada: '" << tipoPropriedade << "' Tipo: Object Property | Classe: " << vetorClasses << " ❕" << NOCOLOR << "\n";
	}
}

/* definido pelo analisador léxico */
extern FILE * yyin;

int main(int argc, char ** argv)
{
	/* se foi passado um nome de arquivo */
	if (argc > 1)
	{
		FILE * file;
		file = fopen(argv[1], "r");
		if (!file)
		{
			cout << "Arquivo " << argv[1] << " não encontrado!\n";
			exit(1);
		}
		
		/* entrada ajustada para ler do arquivo */
		yyin = file;
	}

	yyparse();

	// Tabela com o total de cada tipo de classe, propriedades e erros semânticos
	cout << "\n";
	cout << GREEN2 << "------------------------------------\n";
	cout << "        |RESULTADOS GERAIS|            \n";
	cout << "------------------------------------\n";
	cout << "\n-----------------------------------------------------------\n";
	cout << "** Total ⭢ | Classes - Propriedades - Erros semânticos | **\n";
	cout << "-----------------------------------------------------------\n";
	cout << "\n------------------------------------\n";
	cout << "Classes Primitivas: " << total_primitiva << "\n";
	cout << "------------------------------------\n";
	cout << "Classes Definidas: " << total_definida << "\n";
	cout << "------------------------------------\n";
	cout << "Classes com Axioma de Fechamento: " << total_axioma << "\n";
	cout << "------------------------------------\n";
	cout << "Classes com Descrições Aninhadas: " << total_aninhada << "\n";
	cout << "------------------------------------\n";
	cout << "Classes Enumeradas: " << total_enumerada<< "\n";
	cout << "------------------------------------\n";
	cout << "Classes Cobertas: " << total_coberta << "\n";
	cout << "------------------------------------\n";
	cout << NOCOLOR << "\n";
	cout << MAGENTA2 << "------------------------------------\n";
	cout << "Data Properties: " << total_dataProperty << "\n";
	cout << "------------------------------------\n";
	cout << "Object Properties: " << total_objectProperty << "\n";
	cout << "------------------------------------\n";
	cout << ORANGE << "\n------------------------------------\n";
	cout << "Erros Semânticos: " << errosSemanticos << "\n";
	cout << "------------------------------------\n";
	cout << NOCOLOR;
	cout << "\n";
}

void yyerror(const char * s)
{  
	if(isClass == 0){
	/* mensagem de erro exibe o símbolo que causou erro e o número da linha */
	cout << RED <<"-----------------------------------------------------------------\n";
    cout << RED <<"🔴 Erro sintático: símbolo \"" << yytext << "\" (linha " << yylineno << ") | Classe: " << vetorClasses << "|\n";
	cout << RED <<"-----------------------------------------------------------------\n";
	cout << NOCOLOR;
	isClass = 1;
	}

	yyparse();
}
