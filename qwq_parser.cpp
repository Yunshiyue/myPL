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
#line 7 "qwq.yy"

    #include "AstNode.h"
    #include "ClassDeclaration.h"
    #include "CommonStatement.h"
    #include "Expression.h"
    #include "FunctionDeclaration.h"
    #include "Literal.h"
    #include "Statement.h"
    #include "StringExpression.h"
    #include "Type.h"
    #include "VariableDeclaration.h"

    #include <stdio.h>
    #include <string>

    extern int yylex();
    int yyerror(char const * s);
    #define YYERROR_VERBOSE
    #define YYDEBUG 1

    #define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)


#line 111 "qwq_parser.cpp"

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

#include "qwq_parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TINTEGER = 3,                   /* TINTEGER  */
  YYSYMBOL_TREAL = 4,                      /* TREAL  */
  YYSYMBOL_TBOOL = 5,                      /* TBOOL  */
  YYSYMBOL_TCHAR = 6,                      /* TCHAR  */
  YYSYMBOL_TSTRING = 7,                    /* TSTRING  */
  YYSYMBOL_TIDENTIFIER = 8,                /* TIDENTIFIER  */
  YYSYMBOL_TPOWER = 9,                     /* TPOWER  */
  YYSYMBOL_TEDIV = 10,                     /* TEDIV  */
  YYSYMBOL_TSADD = 11,                     /* TSADD  */
  YYSYMBOL_TSSUB = 12,                     /* TSSUB  */
  YYSYMBOL_TADD = 13,                      /* TADD  */
  YYSYMBOL_TSUB = 14,                      /* TSUB  */
  YYSYMBOL_TMUL = 15,                      /* TMUL  */
  YYSYMBOL_TDIV = 16,                      /* TDIV  */
  YYSYMBOL_TMOD = 17,                      /* TMOD  */
  YYSYMBOL_TAND = 18,                      /* TAND  */
  YYSYMBOL_TOR = 19,                       /* TOR  */
  YYSYMBOL_TNOT = 20,                      /* TNOT  */
  YYSYMBOL_TEQ = 21,                       /* TEQ  */
  YYSYMBOL_TNE = 22,                       /* TNE  */
  YYSYMBOL_TGE = 23,                       /* TGE  */
  YYSYMBOL_TLE = 24,                       /* TLE  */
  YYSYMBOL_TGT = 25,                       /* TGT  */
  YYSYMBOL_TLT = 26,                       /* TLT  */
  YYSYMBOL_TARROW = 27,                    /* TARROW  */
  YYSYMBOL_TIF = 28,                       /* TIF  */
  YYSYMBOL_TELSE = 29,                     /* TELSE  */
  YYSYMBOL_TELIF = 30,                     /* TELIF  */
  YYSYMBOL_TFOR = 31,                      /* TFOR  */
  YYSYMBOL_TWHILE = 32,                    /* TWHILE  */
  YYSYMBOL_TIN = 33,                       /* TIN  */
  YYSYMBOL_TTHIS = 34,                     /* TTHIS  */
  YYSYMBOL_TPUBLIC = 35,                   /* TPUBLIC  */
  YYSYMBOL_TPRIVATE = 36,                  /* TPRIVATE  */
  YYSYMBOL_TPROTECTED = 37,                /* TPROTECTED  */
  YYSYMBOL_TEXTEND = 38,                   /* TEXTEND  */
  YYSYMBOL_TCLASS = 39,                    /* TCLASS  */
  YYSYMBOL_TDEF = 40,                      /* TDEF  */
  YYSYMBOL_TRETURN = 41,                   /* TRETURN  */
  YYSYMBOL_TCONTINUE = 42,                 /* TCONTINUE  */
  YYSYMBOL_TBREAK = 43,                    /* TBREAK  */
  YYSYMBOL_TINTTK = 44,                    /* TINTTK  */
  YYSYMBOL_TBOOLTK = 45,                   /* TBOOLTK  */
  YYSYMBOL_TDOUBLETK = 46,                 /* TDOUBLETK  */
  YYSYMBOL_TCHARTK = 47,                   /* TCHARTK  */
  YYSYMBOL_TSTRTK = 48,                    /* TSTRTK  */
  YYSYMBOL_TARRTK = 49,                    /* TARRTK  */
  YYSYMBOL_TTEMP = 50,                     /* TTEMP  */
  YYSYMBOL_TTYNAME = 51,                   /* TTYNAME  */
  YYSYMBOL_TSUBS = 52,                     /* TSUBS  */
  YYSYMBOL_TREVS = 53,                     /* TREVS  */
  YYSYMBOL_TTITLES = 54,                   /* TTITLES  */
  YYSYMBOL_TUPS = 55,                      /* TUPS  */
  YYSYMBOL_TLOWS = 56,                     /* TLOWS  */
  YYSYMBOL_57_ = 57,                       /* '='  */
  YYSYMBOL_58_ = 58,                       /* '<'  */
  YYSYMBOL_59_ = 59,                       /* ','  */
  YYSYMBOL_60_ = 60,                       /* '>'  */
  YYSYMBOL_61_ = 61,                       /* '('  */
  YYSYMBOL_62_ = 62,                       /* ')'  */
  YYSYMBOL_63_ = 63,                       /* '{'  */
  YYSYMBOL_64_ = 64,                       /* '}'  */
  YYSYMBOL_65_ = 65,                       /* ';'  */
  YYSYMBOL_66_ = 66,                       /* '.'  */
  YYSYMBOL_67_ = 67,                       /* '['  */
  YYSYMBOL_68_ = 68,                       /* ':'  */
  YYSYMBOL_69_ = 69,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 70,                  /* $accept  */
  YYSYMBOL_program = 71,                   /* program  */
  YYSYMBOL_stmt = 72,                      /* stmt  */
  YYSYMBOL_type = 73,                      /* type  */
  YYSYMBOL_74_val_type = 74,               /* val-type  */
  YYSYMBOL_75_func_decl = 75,              /* func-decl  */
  YYSYMBOL_76_func_head = 76,              /* func-head  */
  YYSYMBOL_77_fp_list = 77,                /* fp-list  */
  YYSYMBOL_78_stmt_list = 78,              /* stmt-list  */
  YYSYMBOL_block = 79,                     /* block  */
  YYSYMBOL_80_class_decl = 80,             /* class-decl  */
  YYSYMBOL_81_class_head = 81,             /* class-head  */
  YYSYMBOL_82_var_decl = 82,               /* var-decl  */
  YYSYMBOL_83_var_decl_assign = 83,        /* var-decl-assign  */
  YYSYMBOL_84_var_decl_stmt = 84,          /* var-decl-stmt  */
  YYSYMBOL_85_common_stmt = 85,            /* common-stmt  */
  YYSYMBOL_86_if_stmt = 86,                /* if-stmt  */
  YYSYMBOL_87_while_stmt = 87,             /* while-stmt  */
  YYSYMBOL_88_jump_stmt = 88,              /* jump-stmt  */
  YYSYMBOL_89_for_stmt = 89,               /* for-stmt  */
  YYSYMBOL_90_c_like_for = 90,             /* c-like-for  */
  YYSYMBOL_91_py_like_for = 91,            /* py-like-for  */
  YYSYMBOL_92_range_for = 92,              /* range-for  */
  YYSYMBOL_93_return_stmt = 93,            /* return-stmt  */
  YYSYMBOL_expr = 94,                      /* expr  */
  YYSYMBOL_95_expr_stmt = 95,              /* expr-stmt  */
  YYSYMBOL_96_assign_expr = 96,            /* assign-expr  */
  YYSYMBOL_97_func_expr = 97,              /* func-expr  */
  YYSYMBOL_98_ap_list = 98,                /* ap-list  */
  YYSYMBOL_99_str_expr = 99,               /* str-expr  */
  YYSYMBOL_100_str_operation = 100,        /* str-operation  */
  YYSYMBOL_101_slice_expr = 101,           /* slice-expr  */
  YYSYMBOL_102_arithmetic_expr = 102,      /* arithmetic-expr  */
  YYSYMBOL_103_addition_opt = 103,         /* addition-opt  */
  YYSYMBOL_104_logical_expr = 104,         /* logical-expr  */
  YYSYMBOL_105_logical_opt = 105,          /* logical-opt  */
  YYSYMBOL_106_relation_expr = 106,        /* relation-expr  */
  YYSYMBOL_107_relation_opt = 107,         /* relation-opt  */
  YYSYMBOL_item = 108,                     /* item  */
  YYSYMBOL_109_multi_opt = 109,            /* multi-opt  */
  YYSYMBOL_factor = 110,                   /* factor  */
  YYSYMBOL_111_arr_access = 111,           /* arr-access  */
  YYSYMBOL_ident = 112,                    /* ident  */
  YYSYMBOL_literal = 113                   /* literal  */
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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  72
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   527

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  119
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  242

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   311


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
      61,    62,     2,     2,    59,     2,    66,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    68,    65,
      58,    57,    60,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    67,     2,    69,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    63,     2,    64,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   172,   172,   173,   177,   178,   179,   182,   183,   187,
     188,   189,   190,   191,   192,   200,   204,   205,   206,   207,
     210,   211,   212,   215,   216,   217,   220,   224,   227,   228,
     229,   230,   234,   235,   238,   239,   240,   241,   244,   245,
     249,   250,   251,   252,   253,   254,   255,   259,   260,   264,
     269,   270,   275,   276,   277,   279,   282,   287,   291,   296,
     297,   301,   302,   303,   304,   305,   309,   313,   314,   318,
     319,   322,   323,   324,   328,   329,   330,   331,   334,   335,
     336,   337,   338,   339,   343,   348,   349,   352,   353,   357,
     358,   361,   362,   366,   370,   371,   372,   373,   374,   375,
     379,   380,   384,   385,   386,   387,   388,   392,   393,   394,
     395,   396,   397,   401,   402,   408,   412,   413,   414,   415
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
  "\"end of file\"", "error", "\"invalid token\"", "TINTEGER", "TREAL",
  "TBOOL", "TCHAR", "TSTRING", "TIDENTIFIER", "TPOWER", "TEDIV", "TSADD",
  "TSSUB", "TADD", "TSUB", "TMUL", "TDIV", "TMOD", "TAND", "TOR", "TNOT",
  "TEQ", "TNE", "TGE", "TLE", "TGT", "TLT", "TARROW", "TIF", "TELSE",
  "TELIF", "TFOR", "TWHILE", "TIN", "TTHIS", "TPUBLIC", "TPRIVATE",
  "TPROTECTED", "TEXTEND", "TCLASS", "TDEF", "TRETURN", "TCONTINUE",
  "TBREAK", "TINTTK", "TBOOLTK", "TDOUBLETK", "TCHARTK", "TSTRTK",
  "TARRTK", "TTEMP", "TTYNAME", "TSUBS", "TREVS", "TTITLES", "TUPS",
  "TLOWS", "'='", "'<'", "','", "'>'", "'('", "')'", "'{'", "'}'", "';'",
  "'.'", "'['", "':'", "']'", "$accept", "program", "stmt", "type",
  "val-type", "func-decl", "func-head", "fp-list", "stmt-list", "block",
  "class-decl", "class-head", "var-decl", "var-decl-assign",
  "var-decl-stmt", "common-stmt", "if-stmt", "while-stmt", "jump-stmt",
  "for-stmt", "c-like-for", "py-like-for", "range-for", "return-stmt",
  "expr", "expr-stmt", "assign-expr", "func-expr", "ap-list", "str-expr",
  "str-operation", "slice-expr", "arithmetic-expr", "addition-opt",
  "logical-expr", "logical-opt", "relation-expr", "relation-opt", "item",
  "multi-opt", "factor", "arr-access", "ident", "literal", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-126)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-112)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     394,  -126,  -126,  -126,  -126,  -126,  -126,   -37,     9,   -12,
      58,    58,    25,    -1,    13,  -126,  -126,  -126,  -126,  -126,
      31,    43,   113,   284,  -126,    19,  -126,  -126,    40,  -126,
      40,    61,    63,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,    64,  -126,  -126,   443,     7,  -126,  -126,
     392,    87,  -126,   250,   483,   -31,   196,  -126,    38,   224,
      75,    38,    93,    73,  -126,    70,   242,  -126,  -126,   224,
      89,    80,  -126,  -126,   224,   -39,   442,  -126,  -126,  -126,
    -126,  -126,   104,   265,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,    38,    38,  -126,  -126,    38,  -126,  -126,  -126,
    -126,  -126,    38,   113,   113,   113,   113,    58,   113,  -126,
     392,    81,  -126,    82,    14,    26,   -26,    83,   -31,   -17,
      86,    94,    58,   224,  -126,    92,  -126,   224,  -126,   102,
     113,   113,   332,  -126,  -126,    99,     1,   105,  -126,  -126,
    -126,  -126,   501,   392,   483,   483,  -126,    98,  -126,  -126,
     220,   108,    56,    40,   113,   224,  -126,    58,    38,    38,
     113,    40,  -126,   -57,  -126,   167,   111,   116,    58,  -126,
     290,  -126,  -126,   113,  -126,  -126,  -126,   113,   113,  -126,
     144,   110,   117,   118,   119,   121,   123,  -126,   224,   163,
     132,   154,   156,    22,  -126,   139,   350,   131,    40,    58,
      40,    58,    58,   113,  -126,   224,  -126,    58,    58,   113,
     113,   113,  -126,  -126,  -126,  -126,  -126,   152,   -17,   153,
     155,  -126,   160,   195,  -126,   362,   172,    40,    40,    40,
     224,    58,  -126,  -126,  -126,  -126,  -126,   -24,  -126,   208,
     224,  -126
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,   118,   119,   117,   116,    74,   115,     0,     0,     0,
       0,     0,     0,     0,     0,    10,     9,    11,    12,    13,
       0,     0,     0,     0,     3,     0,     7,     4,     0,     5,
       0,     0,     0,    43,     6,    40,    41,    46,    42,    52,
      53,    54,    44,     0,    45,    65,    77,    63,    76,    64,
      62,    61,   112,    85,    89,   108,   107,   110,     0,     0,
       0,     0,    28,     0,    59,     0,   107,    51,    50,     0,
       0,     0,     1,     2,     0,    33,    23,    15,    27,    38,
      39,    66,     0,     0,    87,    88,    98,    99,    95,    97,
      94,    96,     0,     0,    91,    92,     0,   105,   106,   102,
     103,   104,     0,     0,     0,     0,    71,     0,     0,   111,
       0,   112,   100,   108,   107,     0,     0,     0,     0,     8,
       0,   112,     0,    20,    60,     0,     8,     0,   109,     0,
       0,    71,     0,    24,    77,    78,    75,     0,    80,    81,
      82,    83,    86,    93,    90,   101,    68,     0,    67,    72,
       0,     0,     0,     0,     0,     0,    33,     0,     0,     0,
       0,     0,    30,     0,    21,     0,     0,     0,     0,    34,
       0,    26,    25,     0,   114,    69,    73,    71,     0,   113,
      47,     0,     0,     0,   112,   112,     0,    49,     0,    16,
       0,     0,     0,    32,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,     0,    14,     0,     0,     0,
      71,     0,    70,    84,    48,    32,    58,     0,     0,     0,
       0,    18,     0,    29,    35,     0,     0,     0,     0,     0,
      20,     0,    37,    79,    55,    56,    57,     0,    31,    17,
       0,    19
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -126,  -126,   214,   -55,  -126,  -126,  -126,     8,  -126,    -9,
    -126,  -126,   -58,  -126,  -126,   -61,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,    33,  -126,   -56,   -45,  -125,   157,
    -126,  -126,     2,  -126,  -126,  -126,   -49,  -126,   149,  -126,
     120,    -5,     0,  -126
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    23,    24,    25,    26,    27,    28,   163,   132,    77,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,   150,    47,
      48,    49,    50,    92,    51,    96,    52,    93,    53,   102,
      54,    55,    66,    57
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      56,   116,   188,   117,   115,   189,   170,   157,    60,   111,
      62,    63,   121,   109,   125,   133,   109,     6,   130,   129,
      82,    78,   131,    56,    58,    75,   103,     6,     1,     2,
       3,     4,     5,     6,     6,   188,   104,   134,   239,   158,
     105,     1,     2,     3,     4,    65,     6,   109,   109,    61,
     154,   109,   196,   113,   118,    71,   113,   109,   114,   119,
     110,   114,   106,   110,    67,   164,     6,   107,   115,   126,
      59,   172,   166,    83,   126,   106,    56,    74,    68,   209,
     107,   154,   136,   210,   155,   225,    22,   113,   113,    69,
      64,   113,   114,   114,   110,   143,   114,   113,   110,    22,
     182,    70,   114,    76,   110,    94,    95,   151,   120,   184,
     185,     5,     6,   109,   109,   156,     1,     2,     3,     4,
       5,     6,   162,   126,   178,   179,    79,   167,    80,    81,
     204,   122,    56,   115,   123,   124,   146,   147,   148,   149,
     127,   152,   128,   153,   180,   217,   219,   160,   159,   104,
     221,   165,   187,   113,   113,   126,   161,   183,   114,   114,
     110,   110,   168,   169,   149,    83,   173,   174,   193,   177,
     190,   191,   164,   198,    22,   115,   192,   199,   112,   179,
     200,   112,   203,   176,   201,   241,   202,   181,   126,   214,
     205,   216,   206,   186,   207,   208,   118,   118,   211,   215,
     213,   218,   218,   176,    -8,   126,   195,   222,   223,   -75,
     149,   197,   112,   112,   227,   228,   144,   229,   234,   235,
     236,   230,   145,     1,     2,     3,     4,     5,     6,   176,
     126,   238,     6,   231,   233,   240,   220,    73,   237,   135,
     126,   142,   224,   149,   226,   -75,   -75,   -75,   -75,   -75,
     -75,     0,     0,   105,    -8,   -75,     0,   106,   176,    97,
      98,   -75,   107,   108,     0,    99,   100,   101,    15,    16,
      17,    18,    19,    20,     0,     0,     0,     0,   112,   112,
       0,    22,   175,     0,    72,     0,     0,     1,     2,     3,
       4,     5,     6,     1,     2,     3,     4,     5,     6,   105,
       0,   -75,     0,   106,   -75,     0,     0,   -75,   107,   108,
     -75,   -75,     7,     0,     0,     8,     9,   137,   138,   139,
     140,   141,     0,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     1,     2,     3,     4,     5,
       6,     0,     0,     0,     0,    22,     0,     0,     0,     0,
       0,    22,   194,     1,     2,     3,     4,     5,     6,     0,
       7,     0,     0,     8,     9,     1,     2,     3,     4,     5,
       6,     0,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,     0,     0,   171,     1,     2,     3,
       4,     5,     6,     0,     0,    84,    85,     0,     0,     0,
       0,    22,   212,    86,    87,    88,    89,    90,    91,     0,
       0,     0,     7,    22,   232,     8,     9,     0,     0,     0,
       0,     0,     0,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     1,     2,     3,     4,     5,
       6,     0,  -111,  -111,     0,    22,     0,  -111,  -111,  -111,
    -111,  -111,  -111,     0,  -111,  -111,  -111,  -111,  -111,  -111,
       7,     0,     0,     8,     9,     0,     0,     0,     0,     0,
       0,     0,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,  -100,  -100,     0,     0,  -100,  -100,  -100,  -100,
    -100,     0,     0,    22,  -100,  -100,  -100,  -100,  -100,  -100,
      97,    98,     0,     0,   -85,   -85,    99,   100,   101,     0,
       0,     0,   -85,   -85,   -85,   -85,   -85,   -85
};

static const yytype_int16 yycheck[] =
{
       0,    59,    59,    59,    59,    62,   131,    33,     8,    58,
      10,    11,    61,    58,    69,    76,    61,     8,    57,    74,
      13,    30,    61,    23,    61,    25,    57,     8,     3,     4,
       5,     6,     7,     8,     8,    59,    67,    82,    62,    65,
      57,     3,     4,     5,     6,    12,     8,    92,    93,    61,
      67,    96,   177,    58,    59,    22,    61,   102,    58,    59,
      58,    61,    61,    61,    65,   123,     8,    66,   123,    69,
      61,   132,   127,    66,    74,    61,    76,    58,    65,    57,
      66,    67,    82,    61,    58,   210,    61,    92,    93,    58,
      65,    96,    92,    93,    92,    93,    96,   102,    96,    61,
     155,    58,   102,    63,   102,    18,    19,   107,    33,   158,
     159,     7,     8,   158,   159,   115,     3,     4,     5,     6,
       7,     8,   122,   123,    68,    69,    65,   127,    65,    65,
     188,    38,   132,   188,    61,    65,   103,   104,   105,   106,
      51,   108,    62,    62,   153,   201,   202,    61,    65,    67,
     205,    59,   161,   158,   159,   155,    62,   157,   158,   159,
     158,   159,    60,   130,   131,    66,    61,    69,   168,    61,
       3,    60,   230,    29,    61,   230,    60,    60,    58,    69,
      62,    61,    59,   150,    65,   240,    65,   154,   188,   198,
      27,   200,    60,   160,    40,    39,   201,   202,    59,   199,
      69,   201,   202,   170,     8,   205,   173,   207,   208,    13,
     177,   178,    92,    93,    62,    62,    96,    62,   227,   228,
     229,    61,   102,     3,     4,     5,     6,     7,     8,   196,
     230,   231,     8,    38,    62,    27,   203,    23,   230,    82,
     240,    92,   209,   210,   211,     3,     4,     5,     6,     7,
       8,    -1,    -1,    57,    58,    13,    -1,    61,   225,     9,
      10,    65,    66,    67,    -1,    15,    16,    17,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,   158,   159,
      -1,    61,    62,    -1,     0,    -1,    -1,     3,     4,     5,
       6,     7,     8,     3,     4,     5,     6,     7,     8,    57,
      -1,    59,    -1,    61,    62,    -1,    -1,    65,    66,    67,
      68,    69,    28,    -1,    -1,    31,    32,    52,    53,    54,
      55,    56,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    61,    62,     3,     4,     5,     6,     7,     8,    -1,
      28,    -1,    -1,    31,    32,     3,     4,     5,     6,     7,
       8,    -1,    -1,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    64,     3,     4,     5,
       6,     7,     8,    -1,    -1,    13,    14,    -1,    -1,    -1,
      -1,    61,    62,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    28,    61,    62,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,     3,     4,     5,     6,     7,
       8,    -1,     9,    10,    -1,    61,    -1,    14,    15,    16,
      17,    18,    19,    -1,    21,    22,    23,    24,    25,    26,
      28,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    42,    43,    44,    45,    46,    47,
      48,    49,     9,    10,    -1,    -1,    13,    14,    15,    16,
      17,    -1,    -1,    61,    21,    22,    23,    24,    25,    26,
       9,    10,    -1,    -1,    13,    14,    15,    16,    17,    -1,
      -1,    -1,    21,    22,    23,    24,    25,    26
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    28,    31,    32,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    61,    71,    72,    73,    74,    75,    76,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    99,   100,   101,
     102,   104,   106,   108,   110,   111,   112,   113,    61,    61,
     112,    61,   112,   112,    65,    94,   112,    65,    65,    58,
      58,    94,     0,    72,    58,   112,    63,    79,    79,    65,
      65,    65,    13,    66,    13,    14,    21,    22,    23,    24,
      25,    26,   103,   107,    18,    19,   105,     9,    10,    15,
      16,    17,   109,    57,    67,    57,    61,    66,    67,    97,
     102,   106,   110,   111,   112,    73,    82,    96,   111,   112,
      33,   106,    38,    61,    65,    73,   112,    51,    62,    73,
      57,    61,    78,    85,    97,    99,   112,    52,    53,    54,
      55,    56,   108,   102,   110,   110,    94,    94,    94,    94,
      98,   112,    94,    62,    67,    58,   112,    33,    65,    65,
      61,    62,   112,    77,    82,    59,    73,   112,    60,    94,
      98,    64,    85,    61,    69,    62,    94,    61,    68,    69,
      79,    94,    73,   112,   106,   106,    94,    79,    59,    62,
       3,    60,    60,   112,    62,    94,    98,    94,    29,    60,
      62,    65,    65,    59,    82,    27,    60,    40,    39,    57,
      61,    59,    62,    69,    79,   112,    79,    96,   112,    96,
      94,    73,   112,   112,    94,    98,    94,    62,    62,    62,
      61,    38,    62,    62,    79,    79,    79,    77,   112,    62,
      27,    73
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    70,    71,    71,    72,    72,    72,    73,    73,    74,
      74,    74,    74,    74,    74,    75,    76,    76,    76,    76,
      77,    77,    77,    78,    78,    78,    79,    80,    81,    81,
      81,    81,    82,    82,    83,    83,    83,    83,    84,    84,
      85,    85,    85,    85,    85,    85,    85,    86,    86,    87,
      88,    88,    89,    89,    89,    90,    90,    91,    92,    93,
      93,    94,    94,    94,    94,    94,    95,    96,    96,    97,
      97,    98,    98,    98,    99,    99,    99,    99,   100,   100,
     100,   100,   100,   100,   101,   102,   102,   103,   103,   104,
     104,   105,   105,   106,   107,   107,   107,   107,   107,   107,
     108,   108,   109,   109,   109,   109,   109,   110,   110,   110,
     110,   110,   110,   111,   111,   112,   113,   113,   113,   113
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     6,     2,     5,    10,     7,    12,
       0,     1,     3,     0,     1,     2,     3,     2,     2,     7,
       4,     9,     5,     2,     4,     7,     5,     8,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     5,     7,     5,
       2,     2,     1,     1,     1,     9,     9,     9,     7,     2,
       3,     1,     1,     1,     1,     1,     2,     3,     3,     4,
       6,     0,     1,     2,     1,     1,     1,     1,     3,     8,
       3,     3,     3,     3,     6,     1,     3,     1,     1,     1,
       3,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     4,     4,     1,     1,     1,     1,     1
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

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: program stmt  */
#line 172 "qwq.yy"
                       { (yyvsp[-1].astNode) = (yyvsp[0].stmt); }
#line 1552 "qwq_parser.cpp"
    break;

  case 3: /* program: stmt  */
#line 173 "qwq.yy"
               { (yyval.astNode) = (yyvsp[0].stmt);}
#line 1558 "qwq_parser.cpp"
    break;

  case 4: /* stmt: func-decl  */
#line 177 "qwq.yy"
                  { (yyval.stmt) = (yyvsp[0].fDeclare); }
#line 1564 "qwq_parser.cpp"
    break;

  case 5: /* stmt: class-decl  */
#line 178 "qwq.yy"
                   { (yyval.stmt) = (yyvsp[0].cDeclare); }
#line 1570 "qwq_parser.cpp"
    break;

  case 6: /* stmt: common-stmt  */
#line 179 "qwq.yy"
                    { (yyval.stmt) = (yyvsp[0].cStatement); }
#line 1576 "qwq_parser.cpp"
    break;

  case 7: /* type: val-type  */
#line 182 "qwq.yy"
                 { (yyval.type) = (yyvsp[0].type); }
#line 1582 "qwq_parser.cpp"
    break;

  case 8: /* type: ident  */
#line 183 "qwq.yy"
              { (yyval.type) = new qwq::ClassType(TCLASS, std::shared_ptr<qwq::Identifier>((yyvsp[0].ident))); }
#line 1588 "qwq_parser.cpp"
    break;

  case 9: /* val-type: TBOOLTK  */
#line 187 "qwq.yy"
                    { (yyval.type) = new qwq::BooleanType(TBOOLTK); }
#line 1594 "qwq_parser.cpp"
    break;

  case 10: /* val-type: TINTTK  */
#line 188 "qwq.yy"
                   { (yyval.type) = new qwq::IntType(TINTTK); }
#line 1600 "qwq_parser.cpp"
    break;

  case 11: /* val-type: TDOUBLETK  */
#line 189 "qwq.yy"
                      { (yyval.type) = new qwq::DoubleType(TDOUBLETK); }
#line 1606 "qwq_parser.cpp"
    break;

  case 12: /* val-type: TCHARTK  */
#line 190 "qwq.yy"
                    { (yyval.type) = new qwq::CharType(TCHARTK); }
#line 1612 "qwq_parser.cpp"
    break;

  case 13: /* val-type: TSTRTK  */
#line 191 "qwq.yy"
                   { (yyval.type) = new qwq::StringType(TSTRTK); }
#line 1618 "qwq_parser.cpp"
    break;

  case 14: /* val-type: TARRTK '<' type ',' TINTEGER '>'  */
#line 192 "qwq.yy"
                                            { (yyval.type) = new qwq::ArrayType(TARRTK, std::shared_ptr<qwq::Type>(yyvsp[-3].type), (yyvsp[-1].integer)); }
#line 1624 "qwq_parser.cpp"
    break;

  case 15: /* func-decl: func-head block  */
#line 200 "qwq.yy"
                            { (yyval.fDeclare) = new qwq::FunctionDeclaration(std::shared_ptr<qwq::FunctionHead>((yyvsp[-1].fHead)), 
                                                                std::shared_ptr<qwq::Block>((yyvsp[0].block))); }
#line 1631 "qwq_parser.cpp"
    break;

  case 16: /* func-head: TDEF ident '(' fp-list ')'  */
#line 204 "qwq.yy"
                                       { (yyval.fHead) = new qwq::FunctionHead(nullptr, std::shared_ptr<qwq::Identifier>((yyvsp[-3].ident)), std::shared_ptr<qwq::VariableList>((yyvsp[-1].varList)), nullptr); }
#line 1637 "qwq_parser.cpp"
    break;

  case 17: /* func-head: TTEMP '<' TTYNAME type '>' TDEF ident '(' fp-list ')'  */
#line 205 "qwq.yy"
                                                                  { (yyval.fHead) = new qwq::FunctionHead(std::shared_ptr<qwq::Type>((yyvsp[-6].type)), std::shared_ptr<qwq::Identifier>((yyvsp[-3].ident)), std::shared_ptr<qwq::VariableList>((yyvsp[-1].varList)), nullptr); }
#line 1643 "qwq_parser.cpp"
    break;

  case 18: /* func-head: TDEF ident '(' fp-list ')' TARROW type  */
#line 206 "qwq.yy"
                                                   { (yyval.fHead) = new qwq::FunctionHead(nullptr, std::shared_ptr<qwq::Identifier>((yyvsp[-5].ident)), std::shared_ptr<qwq::VariableList>((yyvsp[-3].varList)), std::shared_ptr<qwq::Type>((yyvsp[0].type))); }
#line 1649 "qwq_parser.cpp"
    break;

  case 19: /* func-head: TTEMP '<' TTYNAME type '>' TDEF ident '(' fp-list ')' TARROW type  */
#line 207 "qwq.yy"
                                                                              { (yyval.fHead) = new qwq::FunctionHead(std::shared_ptr<qwq::Type>((yyvsp[-8].type)), std::shared_ptr<qwq::Identifier>((yyvsp[-5].ident)), std::shared_ptr<qwq::VariableList>((yyvsp[-3].varList)), std::shared_ptr<qwq::Type>((yyvsp[0].type))); }
#line 1655 "qwq_parser.cpp"
    break;

  case 20: /* fp-list: %empty  */
#line 210 "qwq.yy"
                 { (yyval.varList) = new qwq::VariableList(); }
#line 1661 "qwq_parser.cpp"
    break;

  case 21: /* fp-list: var-decl  */
#line 211 "qwq.yy"
                   { (yyval.varList) = new qwq::VariableList(); (yyval.varList)->push_back(std::shared_ptr<qwq::VariableDeclaration>((yyvsp[0].varDecl))); }
#line 1667 "qwq_parser.cpp"
    break;

  case 22: /* fp-list: fp-list ',' var-decl  */
#line 212 "qwq.yy"
                               { (yyvsp[-2].varList)->push_back(std::shared_ptr<qwq::VariableDeclaration>((yyvsp[0].varDecl))); }
#line 1673 "qwq_parser.cpp"
    break;

  case 23: /* stmt-list: %empty  */
#line 215 "qwq.yy"
                   { (yyval.stmtList) = new qwq::StatementList(); }
#line 1679 "qwq_parser.cpp"
    break;

  case 24: /* stmt-list: common-stmt  */
#line 216 "qwq.yy"
                        { (yyval.stmtList) = new qwq::StatementList(); (yyval.stmtList)->push_back(std::shared_ptr<qwq::CommonStatement>((yyvsp[0].cStatement))); }
#line 1685 "qwq_parser.cpp"
    break;

  case 25: /* stmt-list: stmt-list common-stmt  */
#line 217 "qwq.yy"
                                  { (yyvsp[-1].stmtList)->push_back(std::shared_ptr<qwq::CommonStatement>((yyvsp[0].cStatement))); }
#line 1691 "qwq_parser.cpp"
    break;

  case 26: /* block: '{' stmt-list '}'  */
#line 220 "qwq.yy"
                          { (yyval.block) = new qwq::Block(std::shared_ptr<qwq::StatementList>((yyvsp[-1].stmtList))); }
#line 1697 "qwq_parser.cpp"
    break;

  case 27: /* class-decl: class-head block  */
#line 224 "qwq.yy"
                               { (yyval.cDeclare) = new qwq::ClassDeclaration(std::shared_ptr<qwq::ClassHead>((yyvsp[-1].classHead)), std::shared_ptr<qwq::Block>((yyvsp[0].block))); }
#line 1703 "qwq_parser.cpp"
    break;

  case 28: /* class-head: TCLASS ident  */
#line 227 "qwq.yy"
                           { (yyval.classHead) = new qwq::ClassHead(std::shared_ptr<qwq::Identifier>((yyvsp[0].ident)), nullptr, nullptr); }
#line 1709 "qwq_parser.cpp"
    break;

  case 29: /* class-head: TTEMP '<' TTYNAME ident '>' TCLASS ident  */
#line 228 "qwq.yy"
                                                       { (yyval.classHead) = new qwq::ClassHead(std::shared_ptr<qwq::Identifier>((yyvsp[0].ident)), std::shared_ptr<qwq::Identifier>((yyvsp[-3].ident)), nullptr); }
#line 1715 "qwq_parser.cpp"
    break;

  case 30: /* class-head: TCLASS ident TEXTEND ident  */
#line 229 "qwq.yy"
                                         { (yyval.classHead) = new qwq::ClassHead(std::shared_ptr<qwq::Identifier>((yyvsp[-2].ident)), nullptr, std::shared_ptr<qwq::Identifier>((yyvsp[0].ident))); }
#line 1721 "qwq_parser.cpp"
    break;

  case 31: /* class-head: TTEMP '<' TTYNAME ident '>' TCLASS ident TEXTEND ident  */
#line 230 "qwq.yy"
                                                                     { (yyval.classHead) = new qwq::ClassHead(std::shared_ptr<qwq::Identifier>((yyvsp[-2].ident)), std::shared_ptr<qwq::Identifier>((yyvsp[-5].ident)), std::shared_ptr<qwq::Identifier>((yyvsp[0].ident))); }
#line 1727 "qwq_parser.cpp"
    break;

  case 32: /* var-decl: type '<' type '>' ident  */
#line 234 "qwq.yy"
                                    { (yyval.varDecl) = new qwq::VariableDeclaration(std::shared_ptr<qwq::Type>((yyvsp[-4].type)), std::shared_ptr<qwq::Type>((yyvsp[-2].type)), std::shared_ptr<qwq::Identifier>((yyvsp[0].ident)), (yyloc)); }
#line 1733 "qwq_parser.cpp"
    break;

  case 33: /* var-decl: type ident  */
#line 235 "qwq.yy"
                       { (yyval.varDecl) = new qwq::VariableDeclaration(std::shared_ptr<qwq::Type>((yyvsp[-1].type)), std::shared_ptr<qwq::Identifier>((yyvsp[0].ident)), (yyloc)); }
#line 1739 "qwq_parser.cpp"
    break;

  case 34: /* var-decl-assign: type ident '=' expr  */
#line 238 "qwq.yy"
                                      { (yyval.varDeclAssign) = new qwq::VarDeclByExpr(std::shared_ptr<qwq::Type>((yyvsp[-3].type)), std::shared_ptr<qwq::Identifier>((yyvsp[-2].ident)), std::shared_ptr<qwq::Expression>((yyvsp[0].expr)), (yyloc)); }
#line 1745 "qwq_parser.cpp"
    break;

  case 35: /* var-decl-assign: type '<' type '>' ident '=' expr  */
#line 239 "qwq.yy"
                                                   { (yyval.varDeclAssign) = new qwq::VarDeclByExpr(std::shared_ptr<qwq::Type>((yyvsp[-6].type)), std::shared_ptr<qwq::Type>((yyvsp[-4].type)), std::shared_ptr<qwq::Identifier>((yyvsp[-2].ident)), std::shared_ptr<qwq::Expression>((yyvsp[0].expr)), (yyloc)); }
#line 1751 "qwq_parser.cpp"
    break;

  case 36: /* var-decl-assign: type ident '(' ap-list ')'  */
#line 240 "qwq.yy"
                                             { (yyval.varDeclAssign) = new qwq::ObjectDeclaration(std::shared_ptr<qwq::Type>((yyvsp[-4].type)), nullptr, std::shared_ptr<qwq::Identifier>((yyvsp[-3].ident)), std::shared_ptr<qwq::ExpressionList>((yyvsp[-1].exprList)), (yyloc)); }
#line 1757 "qwq_parser.cpp"
    break;

  case 37: /* var-decl-assign: type '<' type '>' ident '(' ap-list ')'  */
#line 241 "qwq.yy"
                                                          { (yyval.varDeclAssign) = new qwq::ObjectDeclaration(std::shared_ptr<qwq::Type>((yyvsp[-7].type)), std::shared_ptr<qwq::Type>((yyvsp[-5].type)), std::shared_ptr<qwq::Identifier>((yyvsp[-3].ident)), std::shared_ptr<qwq::ExpressionList>((yyvsp[-1].exprList)), (yyloc)); }
#line 1763 "qwq_parser.cpp"
    break;

  case 38: /* var-decl-stmt: var-decl ';'  */
#line 244 "qwq.yy"
                             { (yyval.cStatement) = new qwq::VarDeclAssignStmt(std::shared_ptr<qwq::VariableDeclaration>((yyvsp[-1].varDecl))); }
#line 1769 "qwq_parser.cpp"
    break;

  case 39: /* var-decl-stmt: var-decl-assign ';'  */
#line 245 "qwq.yy"
                                    { (yyval.cStatement) = new qwq::VarDeclAssignStmt(std::shared_ptr<qwq::VariableDeclarationAssign>((yyvsp[-1].varDeclAssign))); }
#line 1775 "qwq_parser.cpp"
    break;

  case 40: /* common-stmt: if-stmt  */
#line 249 "qwq.yy"
                      { (yyval.cStatement) = (yyvsp[0].cStatement); }
#line 1781 "qwq_parser.cpp"
    break;

  case 41: /* common-stmt: while-stmt  */
#line 250 "qwq.yy"
                         { (yyval.cStatement) = (yyvsp[0].cStatement); }
#line 1787 "qwq_parser.cpp"
    break;

  case 42: /* common-stmt: for-stmt  */
#line 251 "qwq.yy"
                       { (yyval.cStatement) = (yyvsp[0].cStatement); }
#line 1793 "qwq_parser.cpp"
    break;

  case 43: /* common-stmt: var-decl-stmt  */
#line 252 "qwq.yy"
                            { (yyval.cStatement) = (yyvsp[0].cStatement); }
#line 1799 "qwq_parser.cpp"
    break;

  case 44: /* common-stmt: return-stmt  */
#line 253 "qwq.yy"
                          { (yyval.cStatement) = (yyvsp[0].cStatement); }
#line 1805 "qwq_parser.cpp"
    break;

  case 45: /* common-stmt: expr-stmt  */
#line 254 "qwq.yy"
                        { (yyval.cStatement) = (yyvsp[0].cStatement); }
#line 1811 "qwq_parser.cpp"
    break;

  case 46: /* common-stmt: jump-stmt  */
#line 255 "qwq.yy"
                        { (yyval.cStatement) = (yyvsp[0].cStatement); }
#line 1817 "qwq_parser.cpp"
    break;

  case 47: /* if-stmt: TIF '(' relation-expr ')' block  */
#line 259 "qwq.yy"
                                          { (yyval.cStatement) = new qwq::IfStatement(std::shared_ptr<qwq::RelationalExpression>((yyvsp[-2].relationExpr)), std::shared_ptr<qwq::Block>((yyvsp[0].block))); }
#line 1823 "qwq_parser.cpp"
    break;

  case 48: /* if-stmt: TIF '(' relation-expr ')' block TELSE block  */
#line 260 "qwq.yy"
                                                      { (yyval.cStatement) = new qwq::IfStatement(std::shared_ptr<qwq::RelationalExpression>((yyvsp[-4].relationExpr)), std::shared_ptr<qwq::Block>((yyvsp[-2].block)), std::shared_ptr<qwq::Block>((yyvsp[0].block))); }
#line 1829 "qwq_parser.cpp"
    break;

  case 49: /* while-stmt: TWHILE '(' relation-expr ')' block  */
#line 264 "qwq.yy"
                                                 { (yyval.cStatement) = new qwq::WhileStatement(std::shared_ptr<qwq::RelationalExpression>((yyvsp[-2].relationExpr)), 
                                                      std::shared_ptr<qwq::Block>((yyvsp[0].block))); }
#line 1836 "qwq_parser.cpp"
    break;

  case 50: /* jump-stmt: TBREAK ';'  */
#line 269 "qwq.yy"
                       { (yyval.cStatement) = new qwq::JumpStatement(TBREAK, (yyloc)); }
#line 1842 "qwq_parser.cpp"
    break;

  case 51: /* jump-stmt: TCONTINUE ';'  */
#line 270 "qwq.yy"
                          { (yyval.cStatement) = new qwq::JumpStatement(TCONTINUE, (yyloc)); }
#line 1848 "qwq_parser.cpp"
    break;

  case 52: /* for-stmt: c-like-for  */
#line 275 "qwq.yy"
                        { (yyval.cStatement) = (yyvsp[0].forStatement); }
#line 1854 "qwq_parser.cpp"
    break;

  case 53: /* for-stmt: py-like-for  */
#line 276 "qwq.yy"
                        { (yyval.cStatement) = (yyvsp[0].forStatement); }
#line 1860 "qwq_parser.cpp"
    break;

  case 54: /* for-stmt: range-for  */
#line 277 "qwq.yy"
                      { (yyval.cStatement) = (yyvsp[0].forStatement); }
#line 1866 "qwq_parser.cpp"
    break;

  case 55: /* c-like-for: TFOR '(' var-decl ';' relation-expr ';' assign-expr ')' block  */
#line 279 "qwq.yy"
                                                                            { (yyval.forStatement) = new qwq::CLikeForStatement(std::shared_ptr<qwq::VariableDeclaration>((yyvsp[-6].varDecl)), 
                  std::shared_ptr<qwq::RelationalExpression>((yyvsp[-4].relationExpr)), std::shared_ptr<qwq::AssignExpression>((yyvsp[-2].assignExpr)), 
                  std::shared_ptr<qwq::Block>((yyvsp[0].block)));;}
#line 1874 "qwq_parser.cpp"
    break;

  case 56: /* c-like-for: TFOR '(' assign-expr ';' relation-expr ';' assign-expr ')' block  */
#line 282 "qwq.yy"
                                                                               { (yyval.forStatement) = new qwq::CLikeForStatement(std::shared_ptr<qwq::AssignExpression>((yyvsp[-6].assignExpr)), 
                  std::shared_ptr<qwq::RelationalExpression>((yyvsp[-4].relationExpr)), std::shared_ptr<qwq::AssignExpression>((yyvsp[-2].assignExpr)), 
                  std::shared_ptr<qwq::Block>((yyvsp[0].block)));;}
#line 1882 "qwq_parser.cpp"
    break;

  case 57: /* py-like-for: TFOR ident TIN '(' expr ',' expr ')' block  */
#line 287 "qwq.yy"
                                                         { (yyval.forStatement) = new qwq::PyLikeForStatement(std::shared_ptr<qwq::Identifier>((yyvsp[-7].ident)), 
              std::shared_ptr<qwq::Expression>((yyvsp[-4].expr)), std::shared_ptr<qwq::Expression>((yyvsp[-2].expr)), std::shared_ptr<qwq::Block>((yyvsp[0].block))); }
#line 1889 "qwq_parser.cpp"
    break;

  case 58: /* range-for: TFOR '(' var-decl TIN ident ')' block  */
#line 291 "qwq.yy"
                                                  { (yyval.forStatement) = new qwq::RangeForStatement(std::shared_ptr<qwq::VariableDeclaration>((yyvsp[-4].varDecl)), 
                                                    std::shared_ptr<qwq::Identifier>((yyvsp[-2].ident)), std::shared_ptr<qwq::Block>((yyvsp[0].block))); }
#line 1896 "qwq_parser.cpp"
    break;

  case 59: /* return-stmt: TRETURN ';'  */
#line 296 "qwq.yy"
                          { (yyval.cStatement) = new qwq::ReturnStatement((yyloc)); }
#line 1902 "qwq_parser.cpp"
    break;

  case 60: /* return-stmt: TRETURN expr ';'  */
#line 297 "qwq.yy"
                               { (yyval.cStatement) = new qwq::ReturnStatement(std::shared_ptr<qwq::Expression>((yyvsp[-1].expr)), (yyloc)); }
#line 1908 "qwq_parser.cpp"
    break;

  case 61: /* expr: logical-expr  */
#line 301 "qwq.yy"
                     { (yyval.expr) = (yyvsp[0].logicalExpr); }
#line 1914 "qwq_parser.cpp"
    break;

  case 62: /* expr: arithmetic-expr  */
#line 302 "qwq.yy"
                        { (yyval.expr) = (yyvsp[0].arithExpr); }
#line 1920 "qwq_parser.cpp"
    break;

  case 63: /* expr: str-expr  */
#line 303 "qwq.yy"
                 { (yyval.expr) = (yyvsp[0].sExpr); }
#line 1926 "qwq_parser.cpp"
    break;

  case 64: /* expr: slice-expr  */
#line 304 "qwq.yy"
                   { (yyval.expr) = (yyvsp[0].sliceExpr); }
#line 1932 "qwq_parser.cpp"
    break;

  case 65: /* expr: assign-expr  */
#line 305 "qwq.yy"
                    { (yyval.expr) = (yyvsp[0].assignExpr); }
#line 1938 "qwq_parser.cpp"
    break;

  case 66: /* expr-stmt: expr ';'  */
#line 309 "qwq.yy"
                     { (yyval.cStatement) = new qwq::ExpressionStatement(std::shared_ptr<qwq::Expression>((yyvsp[-1].expr)), (yyloc)); }
#line 1944 "qwq_parser.cpp"
    break;

  case 67: /* assign-expr: ident '=' expr  */
#line 313 "qwq.yy"
                             { (yyval.assignExpr) = new qwq::AssignExpression(std::shared_ptr<qwq::Identifier>((yyvsp[-2].ident)), std::shared_ptr<qwq::Expression>((yyvsp[0].expr)), (yyloc)); }
#line 1950 "qwq_parser.cpp"
    break;

  case 68: /* assign-expr: arr-access '=' expr  */
#line 314 "qwq.yy"
                                  { (yyval.assignExpr) = new qwq::AssignExpression(std::shared_ptr<qwq::ArrayAccess>((yyvsp[-2].arrAcc)), std::shared_ptr<qwq::Expression>((yyvsp[0].expr)), (yyloc)); }
#line 1956 "qwq_parser.cpp"
    break;

  case 69: /* func-expr: ident '(' ap-list ')'  */
#line 318 "qwq.yy"
                                  { (yyval.funcExpr) = new qwq::FunctionCall(std::shared_ptr<qwq::Identifier>((yyvsp[-3].ident)), std::shared_ptr<qwq::ExpressionList>((yyvsp[-1].exprList)), (yyloc)); }
#line 1962 "qwq_parser.cpp"
    break;

  case 70: /* func-expr: ident '.' ident '(' ap-list ')'  */
#line 319 "qwq.yy"
                                            { (yyval.funcExpr) = new qwq::FunctionCall(std::shared_ptr<qwq::Identifier>((yyvsp[-5].ident)), std::shared_ptr<qwq::Identifier>((yyvsp[-3].ident)), std::shared_ptr<qwq::ExpressionList>((yyvsp[-1].exprList)), (yyloc)); }
#line 1968 "qwq_parser.cpp"
    break;

  case 71: /* ap-list: %empty  */
#line 322 "qwq.yy"
                 { (yyval.exprList) = new qwq::ExpressionList(); }
#line 1974 "qwq_parser.cpp"
    break;

  case 72: /* ap-list: expr  */
#line 323 "qwq.yy"
               { (yyval.exprList) = new qwq::ExpressionList(); (yyval.exprList)->push_back(std::shared_ptr<qwq::Expression>((yyvsp[0].expr))); }
#line 1980 "qwq_parser.cpp"
    break;

  case 73: /* ap-list: ap-list expr  */
#line 324 "qwq.yy"
                       { (yyvsp[-1].exprList)->push_back(std::shared_ptr<qwq::Expression>((yyvsp[0].expr))); }
#line 1986 "qwq_parser.cpp"
    break;

  case 74: /* str-expr: TSTRING  */
#line 328 "qwq.yy"
                    { (yyval.sExpr) = new qwq::StringLiteral(std::string(*(yyvsp[0].string))); }
#line 1992 "qwq_parser.cpp"
    break;

  case 75: /* str-expr: ident  */
#line 329 "qwq.yy"
                  { (yyval.sExpr) = new qwq::StringIdentifier(std::shared_ptr<qwq::Identifier>((yyvsp[0].ident))); }
#line 1998 "qwq_parser.cpp"
    break;

  case 76: /* str-expr: str-operation  */
#line 330 "qwq.yy"
                          { (yyval.sExpr) = (yyvsp[0].sExpr); }
#line 2004 "qwq_parser.cpp"
    break;

  case 77: /* str-expr: func-expr  */
#line 331 "qwq.yy"
                      { (yyval.sExpr) = new qwq::StringFuncExpression(std::shared_ptr<qwq::FunctionCall>((yyvsp[0].funcExpr))); }
#line 2010 "qwq_parser.cpp"
    break;

  case 78: /* str-operation: str-expr TADD str-expr  */
#line 334 "qwq.yy"
                                       { (yyval.sExpr) = new qwq::StringOperation(std::shared_ptr<qwq::StringExpression>((yyvsp[-2].sExpr)), (yyvsp[-1].token), std::shared_ptr<qwq::StringExpression>((yyvsp[0].sExpr))); }
#line 2016 "qwq_parser.cpp"
    break;

  case 79: /* str-operation: str-expr '.' TSUBS '(' expr ',' expr ')'  */
#line 335 "qwq.yy"
                                                         { (yyval.sExpr) = new qwq::StringOperation(std::shared_ptr<qwq::StringExpression>((yyvsp[-7].sExpr)), (yyvsp[-5].token), std::shared_ptr<qwq::Expression>((yyvsp[-3].expr)), std::shared_ptr<qwq::Expression>((yyvsp[-1].expr))); }
#line 2022 "qwq_parser.cpp"
    break;

  case 80: /* str-operation: str-expr '.' TREVS  */
#line 336 "qwq.yy"
                                   { (yyval.sExpr) = new qwq::StringOperation(std::shared_ptr<qwq::StringExpression>((yyvsp[-2].sExpr)), (yyvsp[0].token)); }
#line 2028 "qwq_parser.cpp"
    break;

  case 81: /* str-operation: str-expr '.' TTITLES  */
#line 337 "qwq.yy"
                                     { (yyval.sExpr) = new qwq::StringOperation(std::shared_ptr<qwq::StringExpression>((yyvsp[-2].sExpr)), (yyvsp[0].token)); }
#line 2034 "qwq_parser.cpp"
    break;

  case 82: /* str-operation: str-expr '.' TUPS  */
#line 338 "qwq.yy"
                                  { (yyval.sExpr) = new qwq::StringOperation(std::shared_ptr<qwq::StringExpression>((yyvsp[-2].sExpr)), (yyvsp[0].token)); }
#line 2040 "qwq_parser.cpp"
    break;

  case 83: /* str-operation: str-expr '.' TLOWS  */
#line 339 "qwq.yy"
                                   { (yyval.sExpr) = new qwq::StringOperation(std::shared_ptr<qwq::StringExpression>((yyvsp[-2].sExpr)), (yyvsp[0].token)); }
#line 2046 "qwq_parser.cpp"
    break;

  case 84: /* slice-expr: ident '[' expr ':' expr ']'  */
#line 343 "qwq.yy"
                                          { (yyval.sliceExpr) = new qwq::SliceExpression(std::shared_ptr<qwq::Identifier>((yyvsp[-5].ident)), 
                                            std::shared_ptr<qwq::Expression>((yyvsp[-3].expr)), std::shared_ptr<qwq::Expression>((yyvsp[-1].expr)), (yyloc)); }
#line 2053 "qwq_parser.cpp"
    break;

  case 85: /* arithmetic-expr: item  */
#line 348 "qwq.yy"
                       { (yyval.arithExpr) = new qwq::ArithmeticExpression(std::shared_ptr<qwq::Item>((yyvsp[0].item)), (yyloc)); }
#line 2059 "qwq_parser.cpp"
    break;

  case 86: /* arithmetic-expr: arithmetic-expr addition-opt item  */
#line 349 "qwq.yy"
                                                    { (yyval.arithExpr) = new qwq::ArithmeticExpression(std::shared_ptr<qwq::ArithmeticExpression>((yyvsp[-2].arithExpr)), std::shared_ptr<qwq::Item>((yyvsp[0].item)), (yyvsp[-1].token), (yyloc)); }
#line 2065 "qwq_parser.cpp"
    break;

  case 89: /* logical-expr: factor  */
#line 357 "qwq.yy"
                       { (yyval.logicalExpr) = new qwq::LogicalExpression(std::shared_ptr<qwq::Factor>((yyvsp[0].factor)), (yyloc)); }
#line 2071 "qwq_parser.cpp"
    break;

  case 90: /* logical-expr: logical-expr logical-opt factor  */
#line 358 "qwq.yy"
                                                { (yyval.logicalExpr) = new qwq::LogicalExpression(std::shared_ptr<qwq::LogicalExpression>((yyvsp[-2].logicalExpr)), std::shared_ptr<qwq::Factor>((yyvsp[0].factor)), (yyvsp[-1].token), (yyloc)); }
#line 2077 "qwq_parser.cpp"
    break;

  case 93: /* relation-expr: arithmetic-expr relation-opt arithmetic-expr  */
#line 366 "qwq.yy"
                                                             { (yyval.relationExpr) = new qwq::RelationalExpression(std::shared_ptr<qwq::ArithmeticExpression>((yyvsp[-2].arithExpr)),
                                      std::shared_ptr<qwq::ArithmeticExpression>((yyvsp[0].arithExpr)), (yyvsp[-1].token), (yyloc)); }
#line 2084 "qwq_parser.cpp"
    break;

  case 100: /* item: factor  */
#line 379 "qwq.yy"
               { (yyval.item) = new qwq::Item(std::shared_ptr<qwq::Factor>((yyvsp[0].factor))); }
#line 2090 "qwq_parser.cpp"
    break;

  case 101: /* item: item multi-opt factor  */
#line 380 "qwq.yy"
                               { (yyval.item) = new qwq::Item(std::shared_ptr<qwq::Item>((yyvsp[-2].item)), 
                                  std::shared_ptr<qwq::Factor>((yyvsp[0].factor)), (yyvsp[-1].token)); }
#line 2097 "qwq_parser.cpp"
    break;

  case 107: /* factor: ident  */
#line 392 "qwq.yy"
                { (yyval.factor) = new qwq::Factor(std::shared_ptr<qwq::Expression>((yyvsp[0].ident))); }
#line 2103 "qwq_parser.cpp"
    break;

  case 108: /* factor: arr-access  */
#line 393 "qwq.yy"
                     { (yyval.factor) = new qwq::Factor(std::shared_ptr<qwq::Expression>((yyvsp[0].arrAcc))); }
#line 2109 "qwq_parser.cpp"
    break;

  case 109: /* factor: '(' expr ')'  */
#line 394 "qwq.yy"
                       { (yyval.factor) = new qwq::Factor(std::shared_ptr<qwq::Expression>((yyvsp[-1].expr))); }
#line 2115 "qwq_parser.cpp"
    break;

  case 110: /* factor: literal  */
#line 395 "qwq.yy"
                  { (yyval.factor) = new qwq::Factor(std::shared_ptr<qwq::Expression>((yyvsp[0].literal))); }
#line 2121 "qwq_parser.cpp"
    break;

  case 111: /* factor: func-expr  */
#line 396 "qwq.yy"
                    { (yyval.factor) = new qwq::Factor(std::shared_ptr<qwq::Expression>((yyvsp[0].funcExpr))); }
#line 2127 "qwq_parser.cpp"
    break;

  case 112: /* factor: relation-expr  */
#line 397 "qwq.yy"
                        { (yyval.factor) = new qwq::Factor(std::shared_ptr<qwq::Expression>((yyvsp[0].relationExpr))); }
#line 2133 "qwq_parser.cpp"
    break;

  case 113: /* arr-access: ident '[' expr ']'  */
#line 401 "qwq.yy"
                                 { (yyval.arrAcc) = new qwq::ArrayAccess(std::shared_ptr<qwq::Identifier>((yyvsp[-3].ident)), std::shared_ptr<qwq::Expression>((yyvsp[-1].expr)), (yyloc)); }
#line 2139 "qwq_parser.cpp"
    break;

  case 114: /* arr-access: arr-access '[' expr ']'  */
#line 402 "qwq.yy"
                                      { (yyval.arrAcc) = new qwq::ArrayAccess(std::shared_ptr<qwq::ArrayAccess>((yyvsp[-3].arrAcc)), std::shared_ptr<qwq::Expression>((yyvsp[-1].expr)), (yyloc)); }
#line 2145 "qwq_parser.cpp"
    break;

  case 115: /* ident: TIDENTIFIER  */
#line 408 "qwq.yy"
                    { (yyval.ident) = new qwq::Identifier(*(yyvsp[0].string), (yylsp[0])); }
#line 2151 "qwq_parser.cpp"
    break;

  case 116: /* literal: TCHAR  */
#line 412 "qwq.yy"
                { (yyval.literal) = new qwq::Character((yyvsp[0].character)); }
#line 2157 "qwq_parser.cpp"
    break;

  case 117: /* literal: TBOOL  */
#line 413 "qwq.yy"
                { (yyval.literal) = new qwq::Boolean((yyvsp[0].boolean)); }
#line 2163 "qwq_parser.cpp"
    break;

  case 118: /* literal: TINTEGER  */
#line 414 "qwq.yy"
                   { (yyval.literal) = new qwq::Integer((yyvsp[0].integer)); }
#line 2169 "qwq_parser.cpp"
    break;

  case 119: /* literal: TREAL  */
#line 415 "qwq.yy"
                { (yyval.literal) = new qwq::Real((yyvsp[0].real)); }
#line 2175 "qwq_parser.cpp"
    break;


#line 2179 "qwq_parser.cpp"

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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 417 "qwq.yy"
