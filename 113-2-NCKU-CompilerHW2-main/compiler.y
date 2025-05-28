/* Please feel free to modify any content */

/* Definition section */
%{
    #include "compiler_common.h"
    // #define YYDEBUG 1
    // int yydebug = 1;
    typedef struct {
        int index;
        char* name;
        int mut;
        char* type;
        int addr;
        int lineno;
        char* func_sig;
    } Symbol_table;

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

    /* Symbol table function - you can add new functions if needed. */
    /* parameters and return type can be changed */
    static void create_symbol();
    static void insert_symbol();
    static char* lookup_symbol_type(char* name);
    static int lookup_symbol_addr(char* name);
    static void dump_all_symbol();
    static void dump_symbol();
    /* Global variables */
    bool HAS_ERROR = false;
    int scope_level = 0;
    int symbol_index[10] = {0};
    Symbol_table symbol_table[10][10]={0};
    int addr = -1;
    int total_lines = 0;
    char tempname[20];
    int mut = 0;
    char cvt[3];
    char type_temp[20];
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
%left '>' '<' GEQ LEQ EQL NEQ
%left '+' '-'
%left '*' '/' '%'
%right '!'

/* Nonterminal with return, which need to sepcify type */
%type <s_val> Type Expr LORExpr LANDExpr EqualityExpr RelExpr AddExpr Term Factor ASSIGN 
/* Yacc will start at this nonterminal */
%start Program

/* Grammar section */
%%

Program
    : { create_symbol(); } GlobalStatementList OPTIONAL_NEWLINE { dump_all_symbol();} 
;

GlobalStatementList 
    : GlobalStatementList GlobalStatement
    | GlobalStatement
;

GlobalStatement
    : FunctionDeclStmt 
    | '{' 
    {
        scope_level++;
        create_symbol();
    }
     OPTIONAL_NEWLINE GlobalStatementList '}' { dump_symbol(); }OPTIONAL_NEWLINE
    | OPTIONAL_NEWLINE
    | IfStatement
    | WhileStatement
;

WhileStatement
    : WHILE Expr '{' {
        scope_level++;
        create_symbol();
        }
        GlobalStatementList '}'{dump_symbol();}
IfStatement
    : IF  Expr  '{' {
        scope_level++;
        create_symbol();
        }
        GlobalStatementList '}'{dump_symbol();}
    | IfStatement ELSE '{' 
        {
        scope_level++;
        create_symbol();
        }
         GlobalStatementList '}'{dump_symbol();}
    | OPTIONAL_NEWLINE
;

FunctionDeclStmt
    :FUNC{printf("func: ");} ID{printf("%s\n",$<s_val>3);} '(' ')'
    {        
        insert_symbol($<s_val>3, -1, "func", yylineno, "(V)V");
        scope_level++;
        create_symbol();
    }
    '{'  OPTIONAL_NEWLINE GlobalStatementList '}'
    | PRINTLN '(' '\"' STRING_LIT '\"' ')' {
        printf("STRING_LIT \"%s\"\n", $<s_val>4);
        printf("PRINTLN str\n");
    } ';' OPTIONAL_NEWLINE
    | PRINT '(' '\"' STRING_LIT '\"' ')' {
        printf("STRING_LIT \"%s\"\n", $<s_val>4);
        printf("PRINT str\n");
    } ';' OPTIONAL_NEWLINE
    | LET ID{strcpy(tempname, $<s_val>2);}  ':' Type OPTION_STORE
    | LET MUT ID{strcpy(tempname, $<s_val>3);mut=1;}  ':' Type{strcpy(type_temp, $<s_val>6);} OPTION_STORE
    | LET MUT ID{strcpy(tempname, $<s_val>3);mut=1;}  '=' STORE_DATA ';'
    | PRINTLN '(' Expr ')' ';' {printf("PRINTLN %s\n",$<s_val>3);}
    | PRINT '(' Expr ')' ';' {printf("PRINT %s\n",$<s_val>3);}
    | ID ASSIGN Expr ';'{
        if(strcmp($<s_val>2, "ASSIGN") == 0){
            printf("ASSIGN\n");
        }
        else if(strcmp($<s_val>2, "ADD_ASSIGN") == 0){
            printf("ADD_ASSIGN\n");
        }
        else if(strcmp($<s_val>2, "SUB_ASSIGN") == 0){
            printf("SUB_ASSIGN\n");
        }
        else if(strcmp($<s_val>2, "MUL_ASSIGN") == 0){
            printf("MUL_ASSIGN\n");
        }
        else if(strcmp($<s_val>2, "DIV_ASSIGN") == 0){
            printf("DIV_ASSIGN\n");
        }
        else if(strcmp($<s_val>2, "REM_ASSIGN") == 0){
            printf("REM_ASSIGN\n");
        }
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
Expr        : LORExpr { $$ = $1; }
            | DATA

LORExpr     : LORExpr LOR LANDExpr { printf("LOR\n"); $$ = "bool";  }
            | LANDExpr{ $$ = $1; }
            | OPTIONAL_NEWLINE

LANDExpr    : LANDExpr LAND EqualityExpr { printf("LAND\n"); $$ = "bool"; }
            | EqualityExpr{ $$ = $1; };
            | OPTIONAL_NEWLINE
EqualityExpr: EqualityExpr EQL RelExpr { printf("EQL\n"); $$ = "bool"; }
            | EqualityExpr NEQ RelExpr { printf("NEQ\n"); $$ = "bool"; }
            | RelExpr{ $$ = $1; }
            | OPTIONAL_NEWLINE

RelExpr     : RelExpr '>' AddExpr { printf("GTR\n"); $$ = "bool"; }
            | RelExpr '<' AddExpr { printf("LSS\n"); $$ = "bool"; }
            | RelExpr GEQ AddExpr { printf("GEQ\n"); $$ = "bool"; }
            | RelExpr LEQ AddExpr { printf("LEQ\n"); $$ = "bool"; }
            | AddExpr{ $$ = $1; }
            | OPTIONAL_NEWLINE

AddExpr     : AddExpr '+' Term { printf("ADD\n"); 
                if (strcmp($1, "i32") == 0 && strcmp($3, "i32") == 0) {
                    $$ = "i32";
                } 
                else {
                    $$ = "f32";
                } 
            }
            | AddExpr '-' Term { printf("SUB\n"); 
                if (strcmp($1, "i32") == 0 && strcmp($3, "i32") == 0) {
                    $$ = "i32";
                } 
                else {
                    $$ = "f32";
                } 
            }
            | Term { $$ = $1; }
            | OPTIONAL_NEWLINE

Term        : Term '*' Factor { 
                printf("MUL\n");
                if (strcmp($1, "i32") == 0 && strcmp($3, "i32") == 0) {
                        $$ = "i32";
                    } 
                    else {
                        $$ = "f32";
                    } 
                }
            | Term '/' Factor {
                 printf("DIV\n");
                 if (strcmp($1, "i32") == 0 && strcmp($3, "i32") == 0) {
                        $$ = "i32";
                    } 
                    else {
                        $$ = "f32";
                    } 
                }
            | Term '%' Factor { printf("REM\n"); $$ = "i32";}
            | Factor { $$ = $1; }
            | OPTIONAL_NEWLINE
Factor
    : '(' Expr ')'{
        $$ = $<s_val>2;
    }
    | '-' Factor {printf("NEG\n");$$ = $<s_val>2;}
    | '!' Factor {printf("NOT\n");$$ = "bool";}
    | ID {strcpy(tempname, $<s_val>1);printf("IDENT (name=%s, address=%d)\n", $<s_val>1,lookup_symbol_addr($<s_val>1));$$ =lookup_symbol_type($<s_val>1);}
    | INT_LIT {printf("INT_LIT %d\n", $<i_val>1);$$ = "i32";}
    | FLOAT_LIT {printf("FLOAT_LIT %f\n", $<f_val>1);$$ = "f32";}
    | TRUE  { printf("bool TRUE\n");    $$ = "bool";}
    | FALSE { printf("bool FALSE\n");   $$ = "bool";}
    | Factor AS Type {
                                    if(strcmp($<s_val>1, "i32" ) == 0){
                                            cvt[0]='i';
                                    }
                                    else if(strcmp($<s_val>1, "f32") == 0){
                                        cvt[0]='f';
                                    }
                                    else if(strcmp($<s_val>1, "bool") == 0){
                                        cvt[0]='b';
                                    }
                                    else if(strcmp($<s_val>1, "str") == 0){
                                        cvt[0]='s';
                                    }

                                    if(strcmp($<s_val>3, "i32") == 0){
                                        cvt[2]='i';
                                    }
                                    else if(strcmp($<s_val>3, "f32") == 0){
                                        cvt[2]='f';
                                    }
                                    else if(strcmp($<s_val>3, "bool") == 0){
                                        cvt[2]='b';
                                    }
                                    else if(strcmp($<s_val>3, "str") == 0){
                                        cvt[2]='s';
                                    }
                                    $$=$<s_val>3;
                                    printf("%s\n",cvt);
            }
;

Type
    : INT   { $$ = "i32"; }
    | FLOAT { $$ = "f32"; }
    | BOOL  { $$ = "bool"; }
    | STR   { $$ = "str"; }
    | '&' STR { $$ = "&str"; }
; 
OPTIONAL_NEWLINE
    : NEWLINE { yylineno++; }
    |
;
STORE_DATA
    : INT_LIT {printf("INT_LIT %d\n", $<i_val>1);insert_symbol(tempname,mut, "i32",  yylineno,"-");mut=0;}
    | FLOAT_LIT {printf("FLOAT_LIT %f\n", $<f_val>1);insert_symbol(tempname,mut, "f32",  yylineno,"-");mut=0;}
    | '"'STRING_LIT '"' {printf("STRING_LIT \"%s\"\n", $<s_val>2);insert_symbol(tempname,mut, "str",  yylineno,"-");mut=0;}
    | TRUE {printf("bool TRUE\n");insert_symbol(tempname,mut, "bool",  yylineno,"-");mut=0;}
    | FALSE {printf("bool FALSE\n");insert_symbol(tempname,mut, "bool",  yylineno,"-");mut=0;}
    | '"' '"' {printf("STRING_LIT \"%s\"\n","");insert_symbol(tempname,mut, "str",  yylineno,"-");mut=0;}
    |  {insert_symbol(tempname,mut, type_temp,  yylineno,"-");mut=0;}
;
DATA
    : INT_LIT {printf("INT_LIT %d\n", $<i_val>1);}
    | FLOAT_LIT {printf("FLOAT_LIT %f\n", $<f_val>1);}
    | '"'STRING_LIT '"' {printf("STRING_LIT \"%s\"\n", $<s_val>2);}
    | TRUE {printf("bool TRUE\n");}
    | FALSE {printf("bool FALSE\n");}
;
%%

/* C code section */
int main(int argc, char *argv[])
{
    cvt[1]='2';
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    yylineno = 0;
    yyparse();

	printf("Total lines: %d\n", yylineno);
    fclose(yyin);
    return 0;
}

static void create_symbol() {
    printf("> Create symbol table (scope level %d)\n", scope_level);
    symbol_index[scope_level] = 0;
}

static void insert_symbol(char* name, int mut, char* type, int lineno, char* func_sig) {
    int index = symbol_index[scope_level];
    symbol_table[scope_level][index].index = index;
    symbol_table[scope_level][index].name = strdup(name);
    symbol_table[scope_level][index].mut = mut;
    symbol_table[scope_level][index].type = strdup(type);
    symbol_table[scope_level][index].addr = addr++;
    symbol_table[scope_level][index].lineno = lineno+1;
    symbol_table[scope_level][index].func_sig = strdup(func_sig);
    printf("> Insert `%s` (addr: %d) to scope level %d\n", name, symbol_table[scope_level][index].addr, scope_level);
    symbol_index[scope_level]++;
}

static  int lookup_symbol_addr(char* name) {
    for (int level = scope_level; level >= 0; level--) {
        for (int i = 0; i < symbol_index[level]; i++) {
            if (strcmp(symbol_table[level][i].name, name) == 0) {
                    return symbol_table[level][i].addr;
            }
        }
    }
    return -1;
}

static char* lookup_symbol_type(char* name) {
    for (int level = scope_level; level >= 0; level--) {
        for (int i = 0; i < symbol_index[level]; i++) {
            if (strcmp(symbol_table[level][i].name, name) == 0) {
                return symbol_table[level][i].type;
            }
        }
    }
    return NULL;
}

static void dump_all_symbol() {
    for (int level = scope_level; level >= 0; level--) {
        printf("\n> Dump symbol table (scope level: %d)\n", level);
        printf("%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n",
            "Index", "Name", "Mut","Type", "Addr", "Lineno", "Func_sig");

        for (int i = 0; i < symbol_index[level]; i++) {
            Symbol_table s = symbol_table[level][i];
            printf("%-10d%-10s%-10d%-10s%-10d%-10d%-10s\n",
                s.index, s.name, s.mut, s.type, s.addr, s.lineno, s.func_sig);
        }
    }
}

static void dump_symbol() {
    int level = scope_level--;
    printf("\n> Dump symbol table (scope level: %d)\n", level);
    printf("%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n",
        "Index", "Name", "Mut", "Type", "Addr", "Lineno", "Func_sig");
    for (int i = 0; i < symbol_index[level]; i++) {
        Symbol_table s = symbol_table[level][i];
        printf("%-10d%-10s%-10d%-10s%-10d%-10d%-10s\n",
            s.index, s.name, s.mut, s.type, s.addr, s.lineno, s.func_sig);
    }
}
