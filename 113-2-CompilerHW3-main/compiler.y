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
    static char* lookup_symbol_type(char* name);
    static void dump_all_symbol();
    static void dump_symbol();
    static int lookup_symbol(char* name, const char* field);

    /* Global variables */
    bool g_has_error = false;
    FILE *fout = NULL;
    int g_indent_cnt = 0;
    char type[20];
     bool HAS_ERROR = false;
    int scope_level = 0;
    int symbol_index[10] = {0};
    Symbol_table symbol_table[10][10]={0};
    int addr = -1;
    int total_lines = 0;
    char tempname[20];
    int mut = 0;
    char cvt[3];
    char type_temp[20],temp[20],temp1[20],assigntype[20];//temp is assign type
    int error=0,undefine=0;
    int exist=0;
    

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
%left AS
%right '!'

/* Nonterminal with return, which need to sepcify type */
%type <s_val> Type Expr LORExpr LANDExpr EqualityExpr RelExpr AddExpr Term Factor ASSIGN DATA

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
    : FunctionDeclStmt{error=0;}
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
    :FUNC ID '(' ')' 
    {        
        insert_symbol($<s_val>2, -1, "func", yylineno, "(V)V");
        scope_level++;
        create_symbol();
    }
    '{'  OPTIONAL_NEWLINE GlobalStatementList '}'
    | LET ID{strcpy(tempname, $<s_val>2);}  ':' Type OPTION_STORE
    | LET MUT ID{strcpy(tempname, $<s_val>3);mut=1;}  ':' Type{strcpy(type_temp, $<s_val>6);} OPTION_STORE
    | LET MUT ID{strcpy(tempname, $<s_val>3);mut=1;}  '=' STORE_DATA ';'
    | PRINTLN {CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;\n");}'(' Expr{
            strcpy(type, $<s_val>4);
            printf("type: %s\n",type);
            if(strcmp(type,"S")==0||strcmp(type,"String")==0){strcpy(type,"Ljava/lang/String;");}
            else if(strcmp(type,"A")==0){strcpy(type,"Ljava/lang/Object;");}
        } 
        ')' ';' 
    { 
        CODEGEN("invokevirtual java/io/PrintStream/println(%s)V\n",type); 
    }
    | PRINT {CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;\n");}'(' Expr{
            strcpy(type, $<s_val>4);
            if(strcmp(type,"S")==0||strcmp(type,"String")==0){strcpy(type,"Ljava/lang/String;");}
            else if(strcmp(type,"A")==0){strcpy(type,"Ljava/lang/Object;");}
        } ')' ';' {CODEGEN("invokevirtual java/io/PrintStream/println(%s)V\n",type); }
    | ID{  if(strcmp(lookup_symbol_type($<s_val>1), "i32") == 0){strcpy(temp1,"iload");}    else if(strcmp(lookup_symbol_type($<s_val>1), "f32") == 0){strcpy(temp1,"fload");}   else if(strcmp(lookup_symbol_type($<s_val>1), "bool") == 0){strcpy(temp1,"iload");}  else if(strcmp(lookup_symbol_type($<s_val>1), "str") == 0){strcpy(temp1,"aload");}else if(strcmp(lookup_symbol_type($<s_val>1), "array") == 0){strcpy(temp1,"aload");
    }}  ASSIGN Expr ';'
    {
        if(strcmp(($<s_val>4), "I") == 0){strcpy(temp,"istore");}    else if(strcmp($<s_val>4, "F") == 0){strcpy(temp,"fstore");}   else if(strcmp($<s_val>4, "Z") == 0){strcpy(temp,"istore");}  else if(strcmp($<s_val>4, "S") == 0){strcpy(temp,"astore");}else if(strcmp($<s_val>4, "A") == 0){strcpy(temp,"astore");}
    
    if(strlen(assigntype)!=0)
        CODEGEN("%s\n",assigntype);
    CODEGEN("%s %d\n",temp,lookup_symbol($<s_val>1,"addr"));
    strcpy(assigntype,"");
    }
;
OPTION_STORE
    : '=' STORE_DATA ';'
    | STORE_DATA ';'
;
ASSIGN
    : '=' 
    | ADD_ASSIGN {CODEGEN("%s %d\n",temp1,lookup_symbol($<s_val>1,"addr")); if(strcmp(type,"I")==0){strcpy(assigntype,"iadd");}else if(strcmp(type,"F")==0){strcpy(assigntype,"fadd");}}
    | SUB_ASSIGN {CODEGEN("%s %d\n",temp1,lookup_symbol($<s_val>1,"addr"));if(strcmp(type,"I")==0){strcpy(assigntype,"isub");}else if(strcmp(type,"F")==0){strcpy(assigntype,"fsub");}}
    | MUL_ASSIGN {CODEGEN("%s %d\n",temp1,lookup_symbol($<s_val>1,"addr"));if(strcmp(type,"I")==0){strcpy(assigntype,"imul");}else if(strcmp(type,"F")==0){strcpy(assigntype,"fmul");}}
    | DIV_ASSIGN {CODEGEN("%s %d\n",temp1,lookup_symbol($<s_val>1,"addr"));if(strcmp(type,"I")==0){strcpy(assigntype,"idiv");}else if(strcmp(type,"F")==0){strcpy(assigntype,"fdiv");}}
    | REM_ASSIGN {CODEGEN("%s %d\n",temp1,lookup_symbol($<s_val>1,"addr"));if(strcmp(type,"I")==0){strcpy(assigntype,"irem");}else if(strcmp(type,"F")==0){strcpy(assigntype,"error");}}
;
Expr        : LORExpr { $$ = $1;}
            | DATA

LORExpr     : LORExpr LOR LANDExpr { 
                CODEGEN("ior\n");
            }
            | LANDExpr{ $$ = $1; }
            | OPTIONAL_NEWLINE

LANDExpr    : LANDExpr LAND EqualityExpr { 
                CODEGEN("iand\n");
            }
            | EqualityExpr{ $$ = $1;};
            | OPTIONAL_NEWLINE
EqualityExpr: EqualityExpr EQL RelExpr { 

            }
            | EqualityExpr NEQ RelExpr { 

            }
            | RelExpr{ $$ = $1;}
            | OPTIONAL_NEWLINE

RelExpr     : RelExpr '>' AddExpr { 
                $$ = "Z"; 
                if(strcmp($1,"F")==0||strcmp($1,"F")==0){
                    CODEGEN("fcmpg\n");
                    CODEGEN("ifgt L_float_true\n");
                    CODEGEN("iconst_0\n");
                    CODEGEN("goto L_float_cmpend\n");
                    CODEGEN("L_float_true:\n");
                    CODEGEN("iconst_1\n");
                    CODEGEN("L_float_cmpend:\n");
                }
                else{
                CODEGEN("if_icmpgt L_true\n");
                CODEGEN("iconst_0\n");
                CODEGEN("goto L_cmpend\n");
                CODEGEN("L_true:\n");
                CODEGEN("iconst_1\n");
                CODEGEN("L_cmpend:\n");
                }
            }
            | RelExpr '<' AddExpr {
                $$ = "Z"; 
            }
            | RelExpr GEQ AddExpr { 
                $$ = "Z"; 
            }
            | RelExpr LEQ AddExpr { 
                $$ = "Z"; 
            }
            | AddExpr{ $$ = $1; }
            | OPTIONAL_NEWLINE

AddExpr     : AddExpr '+' Term { 
         if (strcmp($1, "I") == 0 && strcmp($3, "I") == 0) {
             CODEGEN("iadd\n");
                    $$ = "I";
                } 
                else {
                    $$ = "F";
                    CODEGEN("fadd\n");
                } 
    }
    | AddExpr '-' Term { 
        if (strcmp($1, "I") == 0 && strcmp($3, "I") == 0) {
            CODEGEN("isub\n");
            $$ = "I";
        } 
        else {
            $$ = "F";
            CODEGEN("fsub\n");
        } 
    }
    | Term { $$ = $1; }
    | OPTIONAL_NEWLINE

Term        : Term '*' Factor { 
        if (strcmp($1, "I") == 0 && strcmp($3, "I") == 0) {
            CODEGEN("imul\n");
            $$ = "I";
        } 
        else {
            $$ = "F";
            CODEGEN("fmul\n");
        }
    }
    | Term '/' Factor {
        if (strcmp($1, "I") == 0 && strcmp($3, "I") == 0) {
            CODEGEN("idiv\n");
            $$ = "I";
        } 
        else {
            $$ = "F";
            CODEGEN("fdiv\n");
        }
    }
    | Term '%' Factor {
        if (strcmp($1, "I") == 0 && strcmp($3, "I") == 0) {
            CODEGEN("irem\n");
            $$ = "I";
        } 
    }
    | Factor { $$ = $1;}
    | OPTIONAL_NEWLINE
Factor
    : '(' Expr ')'{
        $$ = $<s_val>2;
    }
    | Factor LSHIFT Factor {
        strcpy(type, "I");
    }
    | Factor RSHIFT Factor { 
        strcpy(type, "I");
    }
    | '-' Factor {
        if (strcmp(type, "F") == 0) {
            CODEGEN("fneg\n");
            $$="F";
        } else {
            CODEGEN("ineg\n");
            $$="I";
        }
    }
    | '!' Factor {CODEGEN("iconst_1\n");CODEGEN("ixor\n");}
    | ID {
        if(strcmp(lookup_symbol_type($<s_val>1), "i32") == 0){strcpy(temp,"iload");$$ = "I";}else if(strcmp(lookup_symbol_type($<s_val>1), "f32") == 0){strcpy(temp,"fload");$$ = "F";}else if(strcmp(lookup_symbol_type($<s_val>1), "bool") == 0){strcpy(temp,"iload");$$ = "Z";}else if(strcmp(lookup_symbol_type($<s_val>1), "str") == 0){strcpy(temp,"aload");$$ = "S";}else if(strcmp(lookup_symbol_type($<s_val>1), "array") == 0){
            strcpy(temp,"aload");$$ = "A";
        }
        CODEGEN("%s %d\n",temp,lookup_symbol($<s_val>1,"addr")); 
        strcpy(tempname, $<s_val>1);
    }

    | INT_LIT {
        strcpy(type, "I");
        CODEGEN("ldc %d\n", $<i_val>1);
        $$ = "I";
    }
    | FLOAT_LIT {
        strcpy(type, "F");
        CODEGEN("ldc_w %f\n", $<f_val>1);
        $$ = "F";
    }
    | TRUE {
        strcpy(type, "Z");
        CODEGEN("iconst_1\n");
        $$ = "Z";
    }
    | FALSE {
        strcpy(type, "Z");
        CODEGEN("iconst_0\n");
        $$ = "Z";
    }
    | ID {strcpy(tempname, $<s_val>1);} '[' INT_LIT ']'{} 
    | Factor AS Type {
        if (strcmp($<s_val>3, "f32") == 0) {
            if (strcmp($<s_val>1, "I") == 0) {
                CODEGEN("i2f\n");
            }
            strcpy(type, "F");
            $$="F";
        } else if (strcmp($<s_val>3, "i32") == 0) {
            if (strcmp($<s_val>1, "F") == 0) {
                CODEGEN("f2i\n");
            }
            strcpy(type, "I");
            $$="I";
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
     : INT_LIT {CODEGEN("ldc %d\n",$<i_val>1);CODEGEN("istore %d\n",addr);insert_symbol(tempname,mut, "i32",  yylineno,"-");mut=0;}
    | FLOAT_LIT {CODEGEN("ldc_w %f\n",$<f_val>1);CODEGEN("fstore %d\n",addr);insert_symbol(tempname,mut, "f32",  yylineno,"-");mut=0;}
    | '"'STRING_LIT '"' {CODEGEN("ldc \"%s\"\n",$<s_val>2);CODEGEN("astore %d\n",addr);insert_symbol(tempname,mut, "str",  yylineno,"-");mut=0;}
    | TRUE {CODEGEN("ldc 1\n");CODEGEN("istore %d\n",addr);insert_symbol(tempname,mut, "bool",  yylineno,"-");mut=0;}
    | FALSE {CODEGEN("ldc 0\n");CODEGEN("istore %d\n",addr);insert_symbol(tempname,mut, "bool",  yylineno,"-");mut=0;}
    |  {
        if(strcmp(type_temp, "i32") == 0) {
            CODEGEN("ldc 0\n");
            CODEGEN("istore %d\n",addr);
        } else if(strcmp(type_temp, "f32") == 0) {
            CODEGEN("ldc_w 0.0\n");
            CODEGEN("fstore %d\n",addr);
        } else if(strcmp(type_temp, "bool") == 0) {
            CODEGEN("ldc 0\n");
            CODEGEN("istore %d\n",addr);
        } else if(strcmp(type_temp, "str") == 0 || strcmp(type_temp, "&str") == 0) {
            CODEGEN("ldc \"\"\n");
            CODEGEN("astore %d\n",addr);
        }
        insert_symbol(tempname,mut,type_temp,  yylineno,"-");
        mut=0;
    }
    | '[' INT_LIT {}  OPTION_ELEMENT {insert_symbol(tempname,mut, "array",  yylineno,"-");mut=0;} 
    | '"' '"' {CODEGEN("ldc \"%s\"\n","");CODEGEN("astore %d\n",addr);insert_symbol(tempname,mut, "str",  yylineno,"-");mut=0;}
;
OPTION_ELEMENT
    : ',' INT_LIT{} OPTION_ELEMENT
    | ']'
;
DATA
     : INT_LIT { 
        strcpy(type, "I"); 
        CODEGEN("ldc %d\n", $<i_val>1); 
        $$ = "I";
    }
    | FLOAT_LIT { 
        strcpy(type, "F"); 
        CODEGEN("ldc %f\n", $<f_val>1); 
        $$ = "F";
    }
    | '"' STRING_LIT '"' { 
        strcpy(type, "String"); 
        CODEGEN("ldc \"%s\"\n", $<s_val>2); 
        $$ = "S";
    }
    | TRUE { 
        strcpy(type, "Z"); 
        CODEGEN("ldc 1\n"); 
        $$ = "Z";
    }
    | FALSE { 
        strcpy(type, "Z"); 
        CODEGEN("ldc 0\n"); 
        $$ = "Z";
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

static int lookup_symbol(char* name, const char* field) {
    int find=0;
    for (int level = scope_level; level >= 0; level--) {
        for (int i = 0; i < symbol_index[level]; i++) {
            if (strcmp(symbol_table[level][i].name, name) == 0) {
                find=1;
                if (strcmp(field, "mut") == 0) {
                    return symbol_table[level][i].mut;
                } else if (strcmp(field, "addr") == 0) {
                    return symbol_table[level][i].addr;
                }
            }
        }
    }
    if(strcmp(field, "exist") == 0){
        if(find==1){
            return 1;
        }
        else{
            return 0;
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
