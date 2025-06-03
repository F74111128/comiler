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
#line 4 "compiler.y"

    #include "compiler_common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    int yylex_destroy ();
    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    /* Used to generate code */
    /* As printf; the usage: CODEGEN("%d - %s\n", 100, "Hello world"); */
    /* We do not enforce the use of this macro */
    #define CODEGEN(...) \
        do { \
            for (int i = 0; i < g_indent_cnt; i++) { \
                fprintf(fout, "\t"); \
            } \
            fprintf(fout, __VA_ARGS__); \
        } while (0)





    /* Symbol table function - you can add new functions if needed. */
    /* parameters and return type can be changed */
    static void create_symbol();
    static void insert_symbol();
    static void lookup_symbol();
    static void dump_symbol();

    /* Global variables */
    bool g_has_error = false;
    FILE *fout = NULL;
    int g_indent_cnt = 0;
    char type[20];
    int param_cnt = 0;
    char current_expr_type[20]; // 用于跟踪当前表达式的类型

#line 121 "y.tab.c"

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

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    LET = 258,                     /* LET  */
    MUT = 259,                     /* MUT  */
    NEWLINE = 260,                 /* NEWLINE  */
    INT = 261,                     /* INT  */
    FLOAT = 262,                   /* FLOAT  */
    BOOL = 263,                    /* BOOL  */
    STR = 264,                     /* STR  */
    TRUE = 265,                    /* TRUE  */
    FALSE = 266,                   /* FALSE  */
    GEQ = 267,                     /* GEQ  */
    LEQ = 268,                     /* LEQ  */
    EQL = 269,                     /* EQL  */
    NEQ = 270,                     /* NEQ  */
    LOR = 271,                     /* LOR  */
    LAND = 272,                    /* LAND  */
    ADD_ASSIGN = 273,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 274,              /* SUB_ASSIGN  */
    MUL_ASSIGN = 275,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 276,              /* DIV_ASSIGN  */
    REM_ASSIGN = 277,              /* REM_ASSIGN  */
    IF = 278,                      /* IF  */
    ELSE = 279,                    /* ELSE  */
    FOR = 280,                     /* FOR  */
    WHILE = 281,                   /* WHILE  */
    LOOP = 282,                    /* LOOP  */
    PRINT = 283,                   /* PRINT  */
    PRINTLN = 284,                 /* PRINTLN  */
    FUNC = 285,                    /* FUNC  */
    RETURN = 286,                  /* RETURN  */
    BREAK = 287,                   /* BREAK  */
    ID = 288,                      /* ID  */
    ARROW = 289,                   /* ARROW  */
    AS = 290,                      /* AS  */
    IN = 291,                      /* IN  */
    DOTDOT = 292,                  /* DOTDOT  */
    RSHIFT = 293,                  /* RSHIFT  */
    LSHIFT = 294,                  /* LSHIFT  */
    INT_LIT = 295,                 /* INT_LIT  */
    FLOAT_LIT = 296,               /* FLOAT_LIT  */
    STRING_LIT = 297,              /* STRING_LIT  */
    IDENT = 298                    /* IDENT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define LET 258
#define MUT 259
#define NEWLINE 260
#define INT 261
#define FLOAT 262
#define BOOL 263
#define STR 264
#define TRUE 265
#define FALSE 266
#define GEQ 267
#define LEQ 268
#define EQL 269
#define NEQ 270
#define LOR 271
#define LAND 272
#define ADD_ASSIGN 273
#define SUB_ASSIGN 274
#define MUL_ASSIGN 275
#define DIV_ASSIGN 276
#define REM_ASSIGN 277
#define IF 278
#define ELSE 279
#define FOR 280
#define WHILE 281
#define LOOP 282
#define PRINT 283
#define PRINTLN 284
#define FUNC 285
#define RETURN 286
#define BREAK 287
#define ID 288
#define ARROW 289
#define AS 290
#define IN 291
#define DOTDOT 292
#define RSHIFT 293
#define LSHIFT 294
#define INT_LIT 295
#define FLOAT_LIT 296
#define STRING_LIT 297
#define IDENT 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 60 "compiler.y"

    int i_val;
    float f_val;
    char *s_val;
    /* ... */

#line 267 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_LET = 3,                        /* LET  */
  YYSYMBOL_MUT = 4,                        /* MUT  */
  YYSYMBOL_NEWLINE = 5,                    /* NEWLINE  */
  YYSYMBOL_INT = 6,                        /* INT  */
  YYSYMBOL_FLOAT = 7,                      /* FLOAT  */
  YYSYMBOL_BOOL = 8,                       /* BOOL  */
  YYSYMBOL_STR = 9,                        /* STR  */
  YYSYMBOL_TRUE = 10,                      /* TRUE  */
  YYSYMBOL_FALSE = 11,                     /* FALSE  */
  YYSYMBOL_GEQ = 12,                       /* GEQ  */
  YYSYMBOL_LEQ = 13,                       /* LEQ  */
  YYSYMBOL_EQL = 14,                       /* EQL  */
  YYSYMBOL_NEQ = 15,                       /* NEQ  */
  YYSYMBOL_LOR = 16,                       /* LOR  */
  YYSYMBOL_LAND = 17,                      /* LAND  */
  YYSYMBOL_ADD_ASSIGN = 18,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 19,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 20,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 21,                /* DIV_ASSIGN  */
  YYSYMBOL_REM_ASSIGN = 22,                /* REM_ASSIGN  */
  YYSYMBOL_IF = 23,                        /* IF  */
  YYSYMBOL_ELSE = 24,                      /* ELSE  */
  YYSYMBOL_FOR = 25,                       /* FOR  */
  YYSYMBOL_WHILE = 26,                     /* WHILE  */
  YYSYMBOL_LOOP = 27,                      /* LOOP  */
  YYSYMBOL_PRINT = 28,                     /* PRINT  */
  YYSYMBOL_PRINTLN = 29,                   /* PRINTLN  */
  YYSYMBOL_FUNC = 30,                      /* FUNC  */
  YYSYMBOL_RETURN = 31,                    /* RETURN  */
  YYSYMBOL_BREAK = 32,                     /* BREAK  */
  YYSYMBOL_ID = 33,                        /* ID  */
  YYSYMBOL_ARROW = 34,                     /* ARROW  */
  YYSYMBOL_AS = 35,                        /* AS  */
  YYSYMBOL_IN = 36,                        /* IN  */
  YYSYMBOL_DOTDOT = 37,                    /* DOTDOT  */
  YYSYMBOL_RSHIFT = 38,                    /* RSHIFT  */
  YYSYMBOL_LSHIFT = 39,                    /* LSHIFT  */
  YYSYMBOL_INT_LIT = 40,                   /* INT_LIT  */
  YYSYMBOL_FLOAT_LIT = 41,                 /* FLOAT_LIT  */
  YYSYMBOL_STRING_LIT = 42,                /* STRING_LIT  */
  YYSYMBOL_IDENT = 43,                     /* IDENT  */
  YYSYMBOL_44_ = 44,                       /* '>'  */
  YYSYMBOL_45_ = 45,                       /* '<'  */
  YYSYMBOL_46_ = 46,                       /* '+'  */
  YYSYMBOL_47_ = 47,                       /* '-'  */
  YYSYMBOL_48_ = 48,                       /* '*'  */
  YYSYMBOL_49_ = 49,                       /* '/'  */
  YYSYMBOL_50_ = 50,                       /* '%'  */
  YYSYMBOL_51_ = 51,                       /* '!'  */
  YYSYMBOL_52_ = 52,                       /* '{'  */
  YYSYMBOL_53_ = 53,                       /* '}'  */
  YYSYMBOL_54_ = 54,                       /* '('  */
  YYSYMBOL_55_ = 55,                       /* ')'  */
  YYSYMBOL_56_ = 56,                       /* ':'  */
  YYSYMBOL_57_ = 57,                       /* '='  */
  YYSYMBOL_58_ = 58,                       /* ';'  */
  YYSYMBOL_59_ = 59,                       /* '['  */
  YYSYMBOL_60_ = 60,                       /* ']'  */
  YYSYMBOL_61_ = 61,                       /* '&'  */
  YYSYMBOL_62_ = 62,                       /* '"'  */
  YYSYMBOL_63_ = 63,                       /* ','  */
  YYSYMBOL_YYACCEPT = 64,                  /* $accept  */
  YYSYMBOL_Program = 65,                   /* Program  */
  YYSYMBOL_GlobalStatementList = 66,       /* GlobalStatementList  */
  YYSYMBOL_GlobalStatement = 67,           /* GlobalStatement  */
  YYSYMBOL_WhileStatement = 68,            /* WhileStatement  */
  YYSYMBOL_69_1 = 69,                      /* $@1  */
  YYSYMBOL_IfStatement = 70,               /* IfStatement  */
  YYSYMBOL_71_2 = 71,                      /* $@2  */
  YYSYMBOL_72_3 = 72,                      /* $@3  */
  YYSYMBOL_FunctionDeclStmt = 73,          /* FunctionDeclStmt  */
  YYSYMBOL_74_4 = 74,                      /* $@4  */
  YYSYMBOL_OPTION_STORE = 75,              /* OPTION_STORE  */
  YYSYMBOL_ASSIGN = 76,                    /* ASSIGN  */
  YYSYMBOL_Expr = 77,                      /* Expr  */
  YYSYMBOL_LORExpr = 78,                   /* LORExpr  */
  YYSYMBOL_LANDExpr = 79,                  /* LANDExpr  */
  YYSYMBOL_EqualityExpr = 80,              /* EqualityExpr  */
  YYSYMBOL_RelExpr = 81,                   /* RelExpr  */
  YYSYMBOL_AddExpr = 82,                   /* AddExpr  */
  YYSYMBOL_Term = 83,                      /* Term  */
  YYSYMBOL_Factor = 84,                    /* Factor  */
  YYSYMBOL_Type = 85,                      /* Type  */
  YYSYMBOL_86_5 = 86,                      /* $@5  */
  YYSYMBOL_OPTIONAL_NEWLINE = 87,          /* OPTIONAL_NEWLINE  */
  YYSYMBOL_STORE_DATA = 88,                /* STORE_DATA  */
  YYSYMBOL_89_6 = 89,                      /* $@6  */
  YYSYMBOL_OPTION_ELEMENT = 90,            /* OPTION_ELEMENT  */
  YYSYMBOL_91_7 = 91,                      /* $@7  */
  YYSYMBOL_DATA = 92                       /* DATA  */
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  50
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   325

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  175

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


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
       2,     2,     2,    51,    62,     2,     2,    50,    61,     2,
      54,    55,    48,    46,    63,    47,     2,    49,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    56,    58,
      45,    57,    44,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    60,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,    53,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   101,   101,   105,   106,   110,   111,   112,   113,   114,
     118,   118,   123,   123,   128,   127,   132,   136,   137,   138,
     139,   140,   140,   144,   145,   149,   150,   153,   154,   155,
     156,   157,   158,   160,   161,   163,   166,   167,   169,   172,
     173,   174,   177,   180,   181,   183,   186,   189,   192,   195,
     196,   198,   205,   212,   213,   215,   222,   229,   236,   237,
     239,   242,   245,   248,   255,   256,   260,   264,   268,   272,
     276,   277,   293,   294,   295,   296,   297,   298,   298,   301,
     302,   305,   306,   307,   308,   309,   310,   311,   311,   314,
     314,   315,   318,   323,   328,   333,   338
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "LET", "MUT",
  "NEWLINE", "INT", "FLOAT", "BOOL", "STR", "TRUE", "FALSE", "GEQ", "LEQ",
  "EQL", "NEQ", "LOR", "LAND", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN",
  "DIV_ASSIGN", "REM_ASSIGN", "IF", "ELSE", "FOR", "WHILE", "LOOP",
  "PRINT", "PRINTLN", "FUNC", "RETURN", "BREAK", "ID", "ARROW", "AS", "IN",
  "DOTDOT", "RSHIFT", "LSHIFT", "INT_LIT", "FLOAT_LIT", "STRING_LIT",
  "IDENT", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'{'",
  "'}'", "'('", "')'", "':'", "'='", "';'", "'['", "']'", "'&'", "'\"'",
  "','", "$accept", "Program", "GlobalStatementList", "GlobalStatement",
  "WhileStatement", "$@1", "IfStatement", "$@2", "$@3", "FunctionDeclStmt",
  "$@4", "OPTION_STORE", "ASSIGN", "Expr", "LORExpr", "LANDExpr",
  "EqualityExpr", "RelExpr", "AddExpr", "Term", "Factor", "Type", "$@5",
  "OPTIONAL_NEWLINE", "STORE_DATA", "$@6", "OPTION_ELEMENT", "$@7", "DATA", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-90)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-60)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     233,     2,   -90,    46,    46,   -44,   -90,   -25,    -7,    27,
      34,   233,   -90,   -90,    17,   -90,   -90,    14,    -1,   -90,
     -90,     4,   -90,   -90,   235,   235,    46,     6,    23,    58,
      60,    11,     8,    -8,   -32,   -16,   266,   -90,    26,    46,
      49,    50,   -90,   -90,   -90,   -90,   -90,   -90,    46,   233,
     -90,   -90,    80,    54,    48,    22,    69,   -90,   -90,   -90,
     -90,    88,    88,    73,    72,   -90,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   235,   235,   235,    22,
     235,   235,   -90,    82,    46,    84,    87,   139,   -90,   -90,
     -90,   -90,   -90,    91,   106,   105,   -90,    93,   -90,   -90,
     -90,   -90,   143,   146,    81,    98,   -90,   -90,   233,    60,
     257,    11,   275,     8,    70,     8,    -8,    77,    -8,    -8,
      -8,   -32,   -90,   -32,   -16,   -16,   -16,   -90,    88,    88,
     233,   103,   108,   112,   -90,    27,   233,   113,   -90,   114,
     -90,   117,   -90,    91,   -90,   -90,   151,   182,   -90,   120,
      27,   -90,   190,   -90,   -27,   -90,   142,   125,   -90,   -90,
     -90,   233,   -90,   -90,   148,   -90,   -90,   -90,   221,   -90,
     126,   -90,   -27,   -90,   -90
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      80,     0,    79,    80,    80,     0,    21,     0,     0,    80,
       0,    80,     4,     9,     8,     5,     7,     0,     0,    68,
      69,    65,    66,    67,     0,     0,    80,     0,     0,    33,
      36,    39,    43,    49,    53,    58,    37,    34,     0,    80,
       0,     0,    28,    29,    30,    31,    32,    27,    80,    80,
       1,     3,     7,     0,    86,     0,     0,    68,    69,    66,
      67,    63,    64,     0,     0,    12,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,     0,     0,     0,     0,
       0,     0,    10,     0,    80,     0,     0,    80,    14,    84,
      85,    81,    82,    86,     0,     0,    19,     0,    72,    73,
      74,    75,     0,     0,    86,     0,    60,    94,    80,    35,
      40,    38,    44,    41,    50,    42,    47,    54,    48,    45,
      46,    51,    59,    52,    55,    56,    57,    71,    62,    61,
      80,     0,     0,     0,    24,    80,    80,     0,    87,     0,
      26,     0,    76,    86,    18,    70,    80,    80,    23,     0,
      80,     6,    80,    20,     0,    83,     0,     0,    13,    11,
      22,    80,    15,    91,     0,    88,    77,    25,    80,    89,
       0,    17,     0,    78,    90
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -90,   -90,   -46,   -11,   -90,   -90,   -90,   -90,   -90,   -90,
     -90,    85,   -90,     1,   -90,   124,   127,   -24,    41,   -14,
      18,   118,   -90,    -2,   -89,   -90,    24,   -90,   -90
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    10,    11,    12,    13,   130,    14,   108,   136,    15,
      40,    96,    48,    28,    29,    30,    31,    32,    33,    34,
      35,   104,   170,    16,    97,   154,   165,   172,    37
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,    36,    36,    87,   137,    38,    17,    49,    41,    52,
      39,    42,    43,    44,    45,    46,    76,    77,    78,    79,
      70,    71,    80,    81,    36,    68,    69,    63,    98,    99,
     100,   101,     2,   163,    50,    18,   164,    36,    74,    75,
      83,    53,    61,    62,   113,   115,    36,    54,    64,    86,
      47,     2,    72,    73,   157,    55,    19,    20,    89,    90,
     121,   123,   146,    56,   110,   112,   114,   114,   117,   117,
     117,   117,   122,   122,    66,    65,    51,    67,    82,    21,
      -2,   102,    36,   103,   147,   132,    22,    23,    91,    92,
     152,    89,    90,    24,   124,   125,   126,    25,   128,   129,
      26,    89,    90,    84,    85,    93,    88,    94,    27,   105,
      95,   116,   118,   119,   120,   168,   -54,   -54,   -59,   -59,
     -59,    91,    92,    79,     2,   -59,   -59,   -59,   106,    57,
      58,    91,    92,   151,   107,    51,    51,   131,   143,   133,
      94,    51,     1,    95,     2,   134,   138,   139,   161,   141,
      94,   140,    21,    95,     1,   142,     2,    51,   145,    59,
      60,   148,     3,   149,   150,     4,    24,     5,     6,     7,
      25,   153,     8,    26,     3,   156,   155,     4,   160,     5,
       6,     7,   166,   167,     8,     1,   173,     2,   169,   144,
     109,     9,   135,     1,   111,     2,   174,   127,     0,     0,
       0,     0,     0,     9,   158,     3,     0,     0,     4,     0,
       5,     6,     7,     3,     0,     8,     4,     0,     5,     6,
       7,     0,     0,     8,     1,     0,     2,     0,     0,     0,
       0,     0,     0,     0,     9,   159,     1,     0,     2,     0,
       0,     0,     9,   162,     3,    57,    58,     4,     0,     5,
       6,     7,     0,     0,     8,     0,     3,     0,     0,     4,
       0,     5,     6,     7,     0,     0,     8,     0,    21,   -50,
     -50,   -44,   -44,     9,   171,    59,    60,     0,   -50,   -50,
     -44,   -44,    24,   -40,     0,     9,    25,   -50,   -50,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -50,   -50,   -54,   -54,   -59,   -59,   -59,     0,     0,
     -50,   -50,   -54,   -54,   -59,   -59,   -59,     0,     0,   -50,
     -50,   -54,   -54,   -59,   -59,   -59
};

static const yytype_int16 yycheck[] =
{
      11,     3,     4,    49,    93,     4,     4,     9,    33,    11,
      54,    18,    19,    20,    21,    22,    48,    49,    50,    35,
      12,    13,    38,    39,    26,    14,    15,    26,     6,     7,
       8,     9,     5,    60,     0,    33,    63,    39,    46,    47,
      39,    24,    24,    25,    68,    69,    48,    33,    42,    48,
      57,     5,    44,    45,   143,    56,    10,    11,    10,    11,
      74,    75,   108,    59,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    16,    52,    87,    17,    52,    33,
       0,    59,    84,    61,   130,    84,    40,    41,    40,    41,
     136,    10,    11,    47,    76,    77,    78,    51,    80,    81,
      54,    10,    11,    54,    54,    57,    52,    59,    62,    40,
      62,    70,    71,    72,    73,   161,    46,    47,    48,    49,
      50,    40,    41,    35,     5,    48,    49,    50,    55,    10,
      11,    40,    41,   135,    62,   146,   147,    55,    57,    55,
      59,   152,     3,    62,     5,    58,    40,    42,   150,     6,
      59,    58,    33,    62,     3,     9,     5,   168,    60,    40,
      41,    58,    23,    55,    52,    26,    47,    28,    29,    30,
      51,    58,    33,    54,    23,    58,    62,    26,    58,    28,
      29,    30,    40,    58,    33,     3,    60,     5,    40,   104,
      66,    52,    53,     3,    67,     5,   172,    79,    -1,    -1,
      -1,    -1,    -1,    52,    53,    23,    -1,    -1,    26,    -1,
      28,    29,    30,    23,    -1,    33,    26,    -1,    28,    29,
      30,    -1,    -1,    33,     3,    -1,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    53,     3,    -1,     5,    -1,
      -1,    -1,    52,    53,    23,    10,    11,    26,    -1,    28,
      29,    30,    -1,    -1,    33,    -1,    23,    -1,    -1,    26,
      -1,    28,    29,    30,    -1,    -1,    33,    -1,    33,    12,
      13,    14,    15,    52,    53,    40,    41,    -1,    12,    13,
      14,    15,    47,    17,    -1,    52,    51,    12,    13,    54,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,    23,    26,    28,    29,    30,    33,    52,
      65,    66,    67,    68,    70,    73,    87,     4,    33,    10,
      11,    33,    40,    41,    47,    51,    54,    62,    77,    78,
      79,    80,    81,    82,    83,    84,    87,    92,    77,    54,
      74,    33,    18,    19,    20,    21,    22,    57,    76,    87,
       0,    67,    87,    24,    33,    56,    59,    10,    11,    40,
      41,    84,    84,    77,    42,    52,    16,    17,    14,    15,
      12,    13,    44,    45,    46,    47,    48,    49,    50,    35,
      38,    39,    52,    77,    54,    54,    77,    66,    52,    10,
      11,    40,    41,    57,    59,    62,    75,    88,     6,     7,
       8,     9,    59,    61,    85,    40,    55,    62,    71,    79,
      87,    80,    87,    81,    87,    81,    82,    87,    82,    82,
      82,    83,    87,    83,    84,    84,    84,    85,    84,    84,
      69,    55,    77,    55,    58,    53,    72,    88,    40,    42,
      58,     6,     9,    57,    75,    60,    66,    66,    58,    55,
      52,    87,    66,    58,    89,    62,    58,    88,    53,    53,
      58,    87,    53,    60,    63,    90,    40,    58,    66,    40,
      86,    53,    91,    60,    90
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    66,    66,    67,    67,    67,    67,    67,
      69,    68,    71,    70,    72,    70,    70,    73,    73,    73,
      73,    74,    73,    73,    73,    75,    75,    76,    76,    76,
      76,    76,    76,    77,    77,    78,    78,    78,    79,    79,
      79,    80,    80,    80,    80,    81,    81,    81,    81,    81,
      81,    82,    82,    82,    82,    83,    83,    83,    83,    83,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    85,    85,    85,    85,    85,    86,    85,    87,
      87,    88,    88,    88,    88,    88,    88,    89,    88,    91,
      90,    90,    92,    92,    92,    92,    92
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     1,     5,     1,     1,     1,
       0,     6,     0,     6,     0,     6,     1,     8,     5,     4,
       6,     0,     6,     5,     4,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     3,     1,
       1,     3,     3,     1,     1,     3,     3,     3,     3,     1,
       1,     3,     3,     1,     1,     3,     3,     3,     1,     1,
       3,     3,     3,     2,     2,     1,     1,     1,     1,     1,
       4,     3,     1,     1,     1,     1,     2,     0,     6,     1,
       0,     1,     1,     3,     1,     1,     0,     0,     4,     0,
       4,     1,     1,     1,     3,     1,     1
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
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
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 10: /* $@1: %empty  */
#line 118 "compiler.y"
                     {

        }
#line 1757 "y.tab.c"
    break;

  case 12: /* $@2: %empty  */
#line 123 "compiler.y"
                    {

        }
#line 1765 "y.tab.c"
    break;

  case 13: /* IfStatement: IF Expr '{' $@2 GlobalStatementList '}'  */
#line 126 "compiler.y"
                               {}
#line 1771 "y.tab.c"
    break;

  case 14: /* $@3: %empty  */
#line 128 "compiler.y"
        {

        }
#line 1779 "y.tab.c"
    break;

  case 15: /* IfStatement: IfStatement ELSE '{' $@3 GlobalStatementList '}'  */
#line 131 "compiler.y"
                                {}
#line 1785 "y.tab.c"
    break;

  case 21: /* $@4: %empty  */
#line 140 "compiler.y"
              {CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;\n");}
#line 1791 "y.tab.c"
    break;

  case 22: /* FunctionDeclStmt: PRINTLN $@4 '(' Expr ')' ';'  */
#line 141 "compiler.y"
    { 
        CODEGEN("invokevirtual java/io/PrintStream/println(Ljava/lang/%s;)V\n",type); 
    }
#line 1799 "y.tab.c"
    break;

  case 23: /* FunctionDeclStmt: PRINT '(' Expr ')' ';'  */
#line 144 "compiler.y"
                             {}
#line 1805 "y.tab.c"
    break;

  case 24: /* FunctionDeclStmt: ID ASSIGN Expr ';'  */
#line 145 "compiler.y"
                        {
    }
#line 1812 "y.tab.c"
    break;

  case 27: /* ASSIGN: '='  */
#line 153 "compiler.y"
          {(yyval.s_val) = "ASSIGN";}
#line 1818 "y.tab.c"
    break;

  case 28: /* ASSIGN: ADD_ASSIGN  */
#line 154 "compiler.y"
                 {(yyval.s_val) = "ADD_ASSIGN";}
#line 1824 "y.tab.c"
    break;

  case 29: /* ASSIGN: SUB_ASSIGN  */
#line 155 "compiler.y"
                 {(yyval.s_val) = "SUB_ASSIGN";}
#line 1830 "y.tab.c"
    break;

  case 30: /* ASSIGN: MUL_ASSIGN  */
#line 156 "compiler.y"
                 {(yyval.s_val) = "MUL_ASSIGN";}
#line 1836 "y.tab.c"
    break;

  case 31: /* ASSIGN: DIV_ASSIGN  */
#line 157 "compiler.y"
                 {(yyval.s_val) = "DIV_ASSIGN";}
#line 1842 "y.tab.c"
    break;

  case 32: /* ASSIGN: REM_ASSIGN  */
#line 158 "compiler.y"
                 {(yyval.s_val) = "REM_ASSIGN";}
#line 1848 "y.tab.c"
    break;

  case 33: /* Expr: LORExpr  */
#line 160 "compiler.y"
                      { (yyval.s_val) = (yyvsp[0].s_val);}
#line 1854 "y.tab.c"
    break;

  case 35: /* LORExpr: LORExpr LOR LANDExpr  */
#line 163 "compiler.y"
                                   { 

            }
#line 1862 "y.tab.c"
    break;

  case 36: /* LORExpr: LANDExpr  */
#line 166 "compiler.y"
                      { (yyval.s_val) = (yyvsp[0].s_val); }
#line 1868 "y.tab.c"
    break;

  case 38: /* LANDExpr: LANDExpr LAND EqualityExpr  */
#line 169 "compiler.y"
                                         { 

            }
#line 1876 "y.tab.c"
    break;

  case 39: /* LANDExpr: EqualityExpr  */
#line 172 "compiler.y"
                          { (yyval.s_val) = (yyvsp[0].s_val);}
#line 1882 "y.tab.c"
    break;

  case 41: /* EqualityExpr: EqualityExpr EQL RelExpr  */
#line 174 "compiler.y"
                                       { 

            }
#line 1890 "y.tab.c"
    break;

  case 42: /* EqualityExpr: EqualityExpr NEQ RelExpr  */
#line 177 "compiler.y"
                                       { 

            }
#line 1898 "y.tab.c"
    break;

  case 43: /* EqualityExpr: RelExpr  */
#line 180 "compiler.y"
                     {}
#line 1904 "y.tab.c"
    break;

  case 45: /* RelExpr: RelExpr '>' AddExpr  */
#line 183 "compiler.y"
                                  { 

            }
#line 1912 "y.tab.c"
    break;

  case 46: /* RelExpr: RelExpr '<' AddExpr  */
#line 186 "compiler.y"
                                  {

            }
#line 1920 "y.tab.c"
    break;

  case 47: /* RelExpr: RelExpr GEQ AddExpr  */
#line 189 "compiler.y"
                                  { 

            }
#line 1928 "y.tab.c"
    break;

  case 48: /* RelExpr: RelExpr LEQ AddExpr  */
#line 192 "compiler.y"
                                  { 

            }
#line 1936 "y.tab.c"
    break;

  case 51: /* AddExpr: AddExpr '+' Term  */
#line 198 "compiler.y"
                               { 
        if (strcmp(current_expr_type, "F") == 0) {
            CODEGEN("fadd\n");
        } else {
            CODEGEN("iadd\n");
        }
    }
#line 1948 "y.tab.c"
    break;

  case 52: /* AddExpr: AddExpr '-' Term  */
#line 205 "compiler.y"
                       { 
        if (strcmp(current_expr_type, "F") == 0) {
            CODEGEN("fsub\n");
        } else {
            CODEGEN("isub\n");
        }
    }
#line 1960 "y.tab.c"
    break;

  case 53: /* AddExpr: Term  */
#line 212 "compiler.y"
           { (yyval.s_val) = (yyvsp[0].s_val); }
#line 1966 "y.tab.c"
    break;

  case 55: /* Term: Term '*' Factor  */
#line 215 "compiler.y"
                              { 
        if (strcmp(current_expr_type, "F") == 0) {
            CODEGEN("fmul\n");
        } else {
            CODEGEN("imul\n");
        }
    }
#line 1978 "y.tab.c"
    break;

  case 56: /* Term: Term '/' Factor  */
#line 222 "compiler.y"
                      {
        if (strcmp(current_expr_type, "F") == 0) {
            CODEGEN("fdiv\n");
        } else {
            CODEGEN("idiv\n");
        }
    }
#line 1990 "y.tab.c"
    break;

  case 57: /* Term: Term '%' Factor  */
#line 229 "compiler.y"
                      {
        if (strcmp(current_expr_type, "F") == 0) {
            CODEGEN("frem\n");
        } else {
            CODEGEN("irem\n");
        }
    }
#line 2002 "y.tab.c"
    break;

  case 58: /* Term: Factor  */
#line 236 "compiler.y"
             { (yyval.s_val) = (yyvsp[0].s_val); }
#line 2008 "y.tab.c"
    break;

  case 60: /* Factor: '(' Expr ')'  */
#line 239 "compiler.y"
                  {

    }
#line 2016 "y.tab.c"
    break;

  case 61: /* Factor: Factor LSHIFT Factor  */
#line 242 "compiler.y"
                           {
        strcpy(current_expr_type, "I");
    }
#line 2024 "y.tab.c"
    break;

  case 62: /* Factor: Factor RSHIFT Factor  */
#line 245 "compiler.y"
                           { 
        strcpy(current_expr_type, "I");
    }
#line 2032 "y.tab.c"
    break;

  case 63: /* Factor: '-' Factor  */
#line 248 "compiler.y"
                 {
        if (strcmp(current_expr_type, "F") == 0) {
            CODEGEN("fneg\n");
        } else {
            CODEGEN("ineg\n");
        }
    }
#line 2044 "y.tab.c"
    break;

  case 64: /* Factor: '!' Factor  */
#line 255 "compiler.y"
                 {}
#line 2050 "y.tab.c"
    break;

  case 65: /* Factor: ID  */
#line 256 "compiler.y"
         {
        strcpy(current_expr_type, "I");
        CODEGEN("iload %d\n", 0); 
    }
#line 2059 "y.tab.c"
    break;

  case 66: /* Factor: INT_LIT  */
#line 260 "compiler.y"
              {
        strcpy(current_expr_type, "I");
        CODEGEN("ldc %d\n", (yyvsp[0].i_val));
    }
#line 2068 "y.tab.c"
    break;

  case 67: /* Factor: FLOAT_LIT  */
#line 264 "compiler.y"
                {
        strcpy(current_expr_type, "F");
        CODEGEN("ldc %f\n", (yyvsp[0].f_val));
    }
#line 2077 "y.tab.c"
    break;

  case 68: /* Factor: TRUE  */
#line 268 "compiler.y"
           {
        strcpy(current_expr_type, "Z");
        CODEGEN("ldc 1\n");
    }
#line 2086 "y.tab.c"
    break;

  case 69: /* Factor: FALSE  */
#line 272 "compiler.y"
            {
        strcpy(current_expr_type, "Z");
        CODEGEN("ldc 0\n");
    }
#line 2095 "y.tab.c"
    break;

  case 70: /* Factor: ID '[' INT_LIT ']'  */
#line 276 "compiler.y"
                        {}
#line 2101 "y.tab.c"
    break;

  case 71: /* Factor: Factor AS Type  */
#line 277 "compiler.y"
                     {
        if (strcmp((yyvsp[0].s_val), "f32") == 0) {
            if (strcmp(current_expr_type, "I") == 0) {
                CODEGEN("i2f\n");
            }
            strcpy(current_expr_type, "F");
        } else if (strcmp((yyvsp[0].s_val), "i32") == 0) {
            if (strcmp(current_expr_type, "F") == 0) {
                CODEGEN("f2i\n");
            }
            strcpy(current_expr_type, "I");
        }
    }
#line 2119 "y.tab.c"
    break;

  case 72: /* Type: INT  */
#line 293 "compiler.y"
            { (yyval.s_val) = "i32"; }
#line 2125 "y.tab.c"
    break;

  case 73: /* Type: FLOAT  */
#line 294 "compiler.y"
            { (yyval.s_val) = "f32"; }
#line 2131 "y.tab.c"
    break;

  case 74: /* Type: BOOL  */
#line 295 "compiler.y"
            { (yyval.s_val) = "bool"; }
#line 2137 "y.tab.c"
    break;

  case 75: /* Type: STR  */
#line 296 "compiler.y"
            { (yyval.s_val) = "str"; }
#line 2143 "y.tab.c"
    break;

  case 76: /* Type: '&' STR  */
#line 297 "compiler.y"
              { (yyval.s_val) = "&str"; }
#line 2149 "y.tab.c"
    break;

  case 77: /* $@5: %empty  */
#line 298 "compiler.y"
                          { }
#line 2155 "y.tab.c"
    break;

  case 78: /* Type: '[' INT ';' INT_LIT $@5 ']'  */
#line 298 "compiler.y"
                                  { (yyval.s_val) = "array"; }
#line 2161 "y.tab.c"
    break;

  case 79: /* OPTIONAL_NEWLINE: NEWLINE  */
#line 301 "compiler.y"
              { yylineno++; }
#line 2167 "y.tab.c"
    break;

  case 81: /* STORE_DATA: INT_LIT  */
#line 305 "compiler.y"
              {CODEGEN("ldc %d\n",(yyvsp[0].i_val));CODEGEN("istore %d\n",param_cnt++);}
#line 2173 "y.tab.c"
    break;

  case 82: /* STORE_DATA: FLOAT_LIT  */
#line 306 "compiler.y"
                {CODEGEN("ldc %f\n",(yyvsp[0].f_val));CODEGEN("fstore %d\n",param_cnt++);}
#line 2179 "y.tab.c"
    break;

  case 83: /* STORE_DATA: '"' STRING_LIT '"'  */
#line 307 "compiler.y"
                        {CODEGEN("ldc \"%s\"\n",(yyvsp[-2].s_val));CODEGEN("astore %d\n",param_cnt++);}
#line 2185 "y.tab.c"
    break;

  case 84: /* STORE_DATA: TRUE  */
#line 308 "compiler.y"
           {CODEGEN("ldc 1\n");CODEGEN("istore %d\n",param_cnt++);}
#line 2191 "y.tab.c"
    break;

  case 85: /* STORE_DATA: FALSE  */
#line 309 "compiler.y"
            {CODEGEN("ldc 0\n");CODEGEN("istore %d\n",param_cnt++);}
#line 2197 "y.tab.c"
    break;

  case 86: /* STORE_DATA: %empty  */
#line 310 "compiler.y"
       {CODEGEN("ldc 0\n");CODEGEN("istore %d\n",param_cnt++);}
#line 2203 "y.tab.c"
    break;

  case 87: /* $@6: %empty  */
#line 311 "compiler.y"
                  {}
#line 2209 "y.tab.c"
    break;

  case 88: /* STORE_DATA: '[' INT_LIT $@6 OPTION_ELEMENT  */
#line 311 "compiler.y"
                                     {}
#line 2215 "y.tab.c"
    break;

  case 89: /* $@7: %empty  */
#line 314 "compiler.y"
                 {}
#line 2221 "y.tab.c"
    break;

  case 92: /* DATA: INT_LIT  */
#line 318 "compiler.y"
               { 
        strcpy(type, "I"); 
        strcpy(current_expr_type, "I");
        CODEGEN("ldc %d\n", (yyvsp[0].i_val)); 
    }
#line 2231 "y.tab.c"
    break;

  case 93: /* DATA: FLOAT_LIT  */
#line 323 "compiler.y"
                { 
        strcpy(type, "F"); 
        strcpy(current_expr_type, "F");
        CODEGEN("ldc %f\n", (yyvsp[0].f_val)); 
    }
#line 2241 "y.tab.c"
    break;

  case 94: /* DATA: '"' STRING_LIT '"'  */
#line 328 "compiler.y"
                         { 
        strcpy(type, "String"); 
        strcpy(current_expr_type, "String");
        CODEGEN("ldc \"%s\"\n", (yyvsp[-1].s_val)); 
    }
#line 2251 "y.tab.c"
    break;

  case 95: /* DATA: TRUE  */
#line 333 "compiler.y"
           { 
        strcpy(type, "Z"); 
        strcpy(current_expr_type, "Z");
        CODEGEN("ldc 1\n"); 
    }
#line 2261 "y.tab.c"
    break;

  case 96: /* DATA: FALSE  */
#line 338 "compiler.y"
            { 
        strcpy(type, "Z"); 
        strcpy(current_expr_type, "Z");
        CODEGEN("ldc 0\n"); 
    }
#line 2271 "y.tab.c"
    break;


#line 2275 "y.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 344 "compiler.y"


/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }
    if (!yyin) {
        printf("file `%s` doesn't exists or cannot be opened\n", argv[1]);
        exit(1);
    }

    /* Codegen output init */
    char *bytecode_filename = "hw3.j";
    fout = fopen(bytecode_filename, "w");
    CODEGEN(".source hw3.j\n");
    CODEGEN(".class public Main\n");
    CODEGEN(".super java/lang/Object\n");
    CODEGEN(".method public static main([Ljava/lang/String;)V\n.limit stack 100\n.limit locals 100\n");
    /* Symbol table init */
    // Add your code

    yylineno = 0;
    yyparse();

    CODEGEN("return\n");
    CODEGEN(".end method\n");
    /* Symbol table dump */
    // Add your code

	printf("Total lines: %d\n", yylineno);
    fclose(fout);
    fclose(yyin);

    if (g_has_error) {
        remove(bytecode_filename);
    }
    yylex_destroy();
    return 0;
}

static void create_symbol() {
    printf("> Create symbol table (scope level %d)\n", 0);
}

static void insert_symbol() {
    printf("> Insert `%s` (addr: %d) to scope level %d\n", "XXX", 0, 0);
}

static void lookup_symbol() {
}

static void dump_symbol() {
    printf("\n> Dump symbol table (scope level: %d)\n", 0);
    printf("%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n",
        "Index", "Name", "Mut","Type", "Addr", "Lineno", "Func_sig");
    printf("%-10d%-10s%-10d%-10s%-10d%-10d%-10s\n",
            0, "name", 0, "type", 0, 0, "func_sig");
}
