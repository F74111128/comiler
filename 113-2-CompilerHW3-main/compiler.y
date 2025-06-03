/* Please feel free to modify any content */

/* Definition section */
%{
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
%}

%error-verbose

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 *  - you can add new fields if needed.
 */
%union {
    int i_val;
    float f_val;
    char *s_val;
    /* ... */
}

/* Token without return */
%token LET MUT NEWLINE
%token INT FLOAT BOOL STR
%token TRUE FALSE
%token GEQ LEQ EQL NEQ LOR LAND
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN REM_ASSIGN
%token IF ELSE FOR WHILE LOOP
%token PRINT PRINTLN
%token FUNC RETURN BREAK
%token ID ARROW AS IN DOTDOT RSHIFT LSHIFT

/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <f_val> FLOAT_LIT
%token <s_val> STRING_LIT
%token <s_val> IDENT

%left LOR
%left LAND
%left LSHIFT RSHIFT
%left '>' '<' GEQ LEQ EQL NEQ
%left '+' '-'
%left '*' '/' '%'
%right '!'

/* Nonterminal with return, which need to sepcify type */
%type <s_val> Type Expr LORExpr LANDExpr EqualityExpr RelExpr AddExpr Term Factor ASSIGN DATA

/* Yacc will start at this nonterminal */
%start Program

/* Grammar section */
%%
Program
    : GlobalStatementList OPTIONAL_NEWLINE 
;

GlobalStatementList 
    : GlobalStatementList GlobalStatement
    | GlobalStatement 
;

GlobalStatement
    : FunctionDeclStmt
    | '{' OPTIONAL_NEWLINE GlobalStatementList '}' OPTIONAL_NEWLINE
    | OPTIONAL_NEWLINE
    | IfStatement
    | WhileStatement
;

WhileStatement
    : WHILE Expr '{' {

        }
        GlobalStatementList '}'
IfStatement
    : IF  Expr  '{' {

        }
        GlobalStatementList '}'{}
    | IfStatement ELSE '{' 
        {

        }
         GlobalStatementList '}'{}
    | OPTIONAL_NEWLINE
;

FunctionDeclStmt
    :FUNC ID '(' ')' '{'  OPTIONAL_NEWLINE GlobalStatementList '}'
    | LET ID  ':' Type OPTION_STORE
    | LET MUT ID OPTION_STORE
    | LET MUT ID  '=' STORE_DATA ';' 
    | PRINTLN {CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;\n");}'(' Expr ')' ';' 
    { 
        CODEGEN("invokevirtual java/io/PrintStream/println(Ljava/lang/%s;)V\n",type); 
    }
    | PRINT '(' Expr ')' ';' {}
    | ID ASSIGN Expr ';'{
    } 
;
OPTION_STORE
    : '=' STORE_DATA ';'
    | STORE_DATA ';'
;
ASSIGN
    : '=' {$$ = "ASSIGN";}
    | ADD_ASSIGN {$$ = "ADD_ASSIGN";}
    | SUB_ASSIGN {$$ = "SUB_ASSIGN";}
    | MUL_ASSIGN {$$ = "MUL_ASSIGN";}
    | DIV_ASSIGN {$$ = "DIV_ASSIGN";}
    | REM_ASSIGN {$$ = "REM_ASSIGN";}
;
Expr        : LORExpr { $$ = $1;}
            | DATA

LORExpr     : LORExpr LOR LANDExpr { 

            }
            | LANDExpr{ $$ = $1; }
            | OPTIONAL_NEWLINE

LANDExpr    : LANDExpr LAND EqualityExpr { 

            }
            | EqualityExpr{ $$ = $1;};
            | OPTIONAL_NEWLINE
EqualityExpr: EqualityExpr EQL RelExpr { 

            }
            | EqualityExpr NEQ RelExpr { 

            }
            | RelExpr{}
            | OPTIONAL_NEWLINE

RelExpr     : RelExpr '>' AddExpr { 

            }
            | RelExpr '<' AddExpr {

            }
            | RelExpr GEQ AddExpr { 

            }
            | RelExpr LEQ AddExpr { 

            }
            | AddExpr
            | OPTIONAL_NEWLINE

AddExpr     : AddExpr '+' Term { 
        if (strcmp(current_expr_type, "F") == 0) {
            CODEGEN("fadd\n");
        } else {
            CODEGEN("iadd\n");
        }
    }
    | AddExpr '-' Term { 
        if (strcmp(current_expr_type, "F") == 0) {
            CODEGEN("fsub\n");
        } else {
            CODEGEN("isub\n");
        }
    }
    | Term { $$ = $1; }
    | OPTIONAL_NEWLINE

Term        : Term '*' Factor { 
        if (strcmp(current_expr_type, "F") == 0) {
            CODEGEN("fmul\n");
        } else {
            CODEGEN("imul\n");
        }
    }
    | Term '/' Factor {
        if (strcmp(current_expr_type, "F") == 0) {
            CODEGEN("fdiv\n");
        } else {
            CODEGEN("idiv\n");
        }
    }
    | Term '%' Factor {
        if (strcmp(current_expr_type, "F") == 0) {
            CODEGEN("frem\n");
        } else {
            CODEGEN("irem\n");
        }
    }
    | Factor { $$ = $1; }
    | OPTIONAL_NEWLINE
Factor
    : '(' Expr ')'{

    }
    | Factor LSHIFT Factor {
        strcpy(current_expr_type, "I");
    }
    | Factor RSHIFT Factor { 
        strcpy(current_expr_type, "I");
    }
    | '-' Factor {
        if (strcmp(current_expr_type, "F") == 0) {
            CODEGEN("fneg\n");
        } else {
            CODEGEN("ineg\n");
        }
    }
    | '!' Factor {}
    | ID {
        strcpy(current_expr_type, "I");
        CODEGEN("iload %d\n", 0); 
    }
    | INT_LIT {
        strcpy(current_expr_type, "I");
        CODEGEN("ldc %d\n", $<i_val>1);
    }
    | FLOAT_LIT {
        strcpy(current_expr_type, "F");
        CODEGEN("ldc %f\n", $<f_val>1);
    }
    | TRUE {
        strcpy(current_expr_type, "Z");
        CODEGEN("ldc 1\n");
    }
    | FALSE {
        strcpy(current_expr_type, "Z");
        CODEGEN("ldc 0\n");
    }
    | ID '[' INT_LIT ']'{} 
    | Factor AS Type {
        if (strcmp($<s_val>3, "f32") == 0) {
            if (strcmp(current_expr_type, "I") == 0) {
                CODEGEN("i2f\n");
            }
            strcpy(current_expr_type, "F");
        } else if (strcmp($<s_val>3, "i32") == 0) {
            if (strcmp(current_expr_type, "F") == 0) {
                CODEGEN("f2i\n");
            }
            strcpy(current_expr_type, "I");
        }
    }
;

Type
    : INT   { $$ = "i32"; }
    | FLOAT { $$ = "f32"; }
    | BOOL  { $$ = "bool"; }
    | STR   { $$ = "str"; }
    | '&' STR { $$ = "&str"; }
    | '[' INT ';' INT_LIT { } ']' { $$ = "array"; }
; 
OPTIONAL_NEWLINE
    : NEWLINE { yylineno++; }
    |
;
STORE_DATA
    : INT_LIT {CODEGEN("ldc %d\n",$<i_val>1);CODEGEN("istore %d\n",param_cnt++);}
    | FLOAT_LIT {CODEGEN("ldc %f\n",$<f_val>1);CODEGEN("fstore %d\n",param_cnt++);}
    | '"'STRING_LIT '"' {CODEGEN("ldc \"%s\"\n",$<s_val>1);CODEGEN("astore %d\n",param_cnt++);}
    | TRUE {CODEGEN("ldc 1\n");CODEGEN("istore %d\n",param_cnt++);}
    | FALSE {CODEGEN("ldc 0\n");CODEGEN("istore %d\n",param_cnt++);}
    |  {CODEGEN("ldc 0\n");CODEGEN("istore %d\n",param_cnt++);}
    | '[' INT_LIT {}  OPTION_ELEMENT {} 
;
OPTION_ELEMENT
    : ',' INT_LIT{} OPTION_ELEMENT
    | ']'
;
DATA
     : INT_LIT { 
        strcpy(type, "I"); 
        strcpy(current_expr_type, "I");
        CODEGEN("ldc %d\n", $<i_val>1); 
    }
    | FLOAT_LIT { 
        strcpy(type, "F"); 
        strcpy(current_expr_type, "F");
        CODEGEN("ldc %f\n", $<f_val>1); 
    }
    | '"' STRING_LIT '"' { 
        strcpy(type, "String"); 
        strcpy(current_expr_type, "String");
        CODEGEN("ldc \"%s\"\n", $<s_val>2); 
    }
    | TRUE { 
        strcpy(type, "Z"); 
        strcpy(current_expr_type, "Z");
        CODEGEN("ldc 1\n"); 
    }
    | FALSE { 
        strcpy(type, "Z"); 
        strcpy(current_expr_type, "Z");
        CODEGEN("ldc 0\n"); 
    }
;
%%

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