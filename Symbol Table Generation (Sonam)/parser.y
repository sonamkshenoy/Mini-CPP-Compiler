%{
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


    // Symbol table Function declarations
    void updateSymbolTable(char* name, char* value, int scope);
	int findInSymbolTable(int scope, char *name);
	void displaySymbolTable();
	int insertInSymbolTable(int* count, int scope, char *datatype, char* name, int line_no, char* value);

%}


%token INTNUM FLOATNUM
%token ID
%token INT FLOAT VOID DOUBLE BOOL CHAR STRING
%token MAIN
%token PRIVATE PUBLIC
%token IF ELSE WHILE RETURN

/*
%token MAIN
%token HASH INCLUDE STDLIB IOSTREAM MATH_H STRING_H TIME_H HEADERFILE 
%token VOID CHAR INT FLOAT DOUBLE BOOL STRING
%token IF ELSE WHILE // SWITCH CASE DEFAULT
%token RETURN // CONTINUE BREAK USING NAMESPACE STD ENDL
%token PUBLIC PRIVATE	// STRUCT PROTECTED
//%token PRINT COUTOP CINOP COUT CIN
%token ID NUM
*/
%token ADD_OP SUB_OP MUL_OP DIV_OP MOD_OP // INC_OP DEC_OP
%token LE_OP GE_OP EQ_OP NE_OP LT_OP GT_OP
//%token ADD_ASGN SUB_ASGN MUL_ASGN DIV_ASGN MOD_ASGN
//%token AND_OP OR_OP NOT_OP


/*%type C_PROG
%type PROGRAM
%type CLASS CLASS_LIST
%type MEMBER
%type VAR_DECL VAR_DECL_LIST
%type METHOD_DECL METHOD_DECL_LIST 
%type METHOD_DEF METHOD_DEF_LIST
%type CLASS_METHOD_DEF CLASS_METHOD_DEF_LIST
%type MAIN_FUNC 
%type PARAM PARAM_LIST
%type IDENT
%type TYPE
%type COMP_STMNT
%type STMNT STMNT_LIST
%type EXPR_STMMT
%type ASSIGN_STMNT
%type RET_STMNT
%type ITER_STMNT
%type COND_STMNT
%type EXPR
%type ASGN_OP_EXPR
%type REF_EXPR
%type REF_VAR_EXPR
%type REF_CALL_EXPR
%type IDENT_EXPR
%type CALL_EXPR
%type ARG ARG_LIST
*/


/* priority definitions from top to down, the priority becomes higher */
%right ASGN_EQ_OP
//%right ADD_ASGN SUB_ASGN MUL_ASGN DIV_ASGN MOD_ASGN
%left EQ_OP NE_OP
%left LE_OP GE_OP GT_OP LT_OP
%left ADD_OP SUB_OP
%left MUL_OP DIV_OP MOD_OP
%left '(' ')'
//%left '[' ']'
//%left '{' '}'

/*no associativity symbols */
%nonassoc IF_THEN
%nonassoc ELSE
// %nonassoc ADD_ASGN SUB_ASGN MUL_ASGN DIV_ASGN MOD_ASGN


	
%start S


%%
/*
S
	: C_PROG
	;

C_PROG 
	: HASH INCLUDE LT_OP LIB GT_OP PROGRAM
	| HASH INCLUDE HEADERFILE PROGRAM
	| PROGRAM
	;
		
LIB
	: STDLIB
	| IOSTREAM
	| MATH_H
	| STRING_H
	| TIME_H
	; */


S
	: PROGRAM
	;

PROGRAM : CLASS_LIST CLASS_METHOD_DEF_LIST MAIN_FUNC
	| CLASS_LIST MAIN_FUNC
	| CLASS_METHOD_DEF_LIST MAIN_FUNC
	| MAIN_FUNC
	;

CLASS_LIST
	: CLASS 
	| CLASS_LIST CLASS
	;

CLASS
	: TYPE ID '{' PRIVATE ':' MEMBER PUBLIC ':' MEMBER '}' ';'
	| TYPE ID '{' PRIVATE ':' MEMBER '}' ';'
	| TYPE ID '{' PUBLIC ':' MEMBER '}' ';'
	| TYPE ID '{' '}' ';'
	;

MEMBER
	: VAR_DECL_LIST METHOD_DECL_LIST METHOD_DEF_LIST
	| VAR_DECL_LIST METHOD_DECL_LIST
	| VAR_DECL_LIST METHOD_DEF_LIST
	| METHOD_DECL_LIST METHOD_DEF_LIST
	| VAR_DECL_LIST
	| METHOD_DECL_LIST
	| METHOD_DEF_LIST
	;

VAR_DECL_LIST
	: VAR_DECL_LIST VAR_DECL
	| VAR_DECL
	;

VAR_DECL
	: TYPE IDENT ASGN_EQ_OP INTNUM ';' {
		if(!insertInSymbolTable(&numRecords, current_scope, $1, $2,  yylineno, $4)){
			yyerror("Variable reinitialized");
		}
	}
	| TYPE IDENT ASGN_EQ_OP FLOATNUM ';' {
		if(!insertInSymbolTable(&numRecords, current_scope, $1, $2,  yylineno, $4)){
			yyerror("Variable reinitialized");
		}
	}
	| TYPE IDENT ASGN_EQ_OP IDENT ';' {
		if(!insertInSymbolTable(&numRecords, current_scope, $1, $2,  yylineno, $4)){
			yyerror("Variable on LHS reinitialized or variable on RHS not present");
		}
	}
	| TYPE IDENT ';' {
		if(!insertInSymbolTable(&numRecords, current_scope, $1, $2, yylineno, "0")){
			yyerror("Variable redeclared");
		}
		displaySymbolTable();
	}
	;

METHOD_DECL_LIST
	: METHOD_DECL
	| METHOD_DECL_LIST METHOD_DECL
	;

METHOD_DECL
	: TYPE ID '(' PARAM_LIST ')' ';'
	| TYPE ID '(' ')' ';'
	;

METHOD_DEF_LIST 
	: METHOD_DEF
	| METHOD_DEF_LIST METHOD_DEF
	;

METHOD_DEF
	: TYPE ID '(' PARAM_LIST ')' COMP_STMNT
	| TYPE ID '(' ')' COMP_STMNT
	;

CLASS_METHOD_DEF_LIST 
	: CLASS_METHOD_DEF
	| CLASS_METHOD_DEF_LIST CLASS_METHOD_DEF
	;

CLASS_METHOD_DEF
	: TYPE ID ':' ':' ID '(' PARAM_LIST ')' COMP_STMNT
	| TYPE ID ':' ':' ID '(' ')' COMP_STMNT
	;

MAIN_FUNC
	: INT MAIN '(' ')' COMP_STMNT
	| VOID MAIN '(' ')' COMP_STMNT
	| INT MAIN '(' VOID ')' COMP_STMNT
	| VOID MAIN '(' VOID ')' COMP_STMNT
	;

PARAM_LIST
	: PARAM
	| PARAM_LIST ',' PARAM
	;

PARAM
	: TYPE IDENT
	;

IDENT
	: ID
	| ID '[' INTNUM ']'
	;

TYPE
	: VOID 
	| CHAR
	| INT
	| FLOAT
	| DOUBLE
	| BOOL
	| STRING
	| ID
	;

COMP_STMNT
	: '{' '}'
	| '{' STMNT_LIST '}'
	| '{' VAR_DECL_LIST STMNT_LIST '}'
	| '{' VAR_DECL_LIST '}'
	;

STMNT_LIST
	: STMNT
	| STMNT_LIST STMNT
	;
	
STMNT
	: EXPR_STMNT
	| ASGN_STMNT
	| RET_STMNT
	| ITER_STMNT
//	| COND_STMNT
	| COMP_STMNT
	| ';'
	;


EXPR_STMNT
	: EXPR ';'
	;

ASGN_STMNT
	: REF_VAR_EXPR ASGN_EQ_OP EXPR ';' {
		if (findInSymbolTable(current_scope, $1) == -1) {
		      yyerror("Variable not declared");
		}
		updateSymbolTable($1, $3, current_scope);
	}
	;

/*
ASGN_OP
	: ASGN_EQ_OP
	| ADD_ASGN
	| SUB_ASGN
	| MUL_ASGN
	| DIV_ASGN
	| MOD_ASGN
	;
*/

RET_STMNT
	: RETURN ';'
	| RETURN EXPR ';'
	;

ITER_STMNT
	: WHILE '(' EXPR ')' STMNT 
	;

/*
COND_STMNT
	: IF '(' EXPR ')' STMNT IF_THEN
	| IF '(' EXPR ')' STMNT ELSE STMNT
	;
*/

EXPR
	: OP_EXPR
	| REF_EXPR
	| INTNUM
	| FLOATNUM
	;

OP_EXPR
	: EXPR ADD_OP EXPR
	| EXPR SUB_OP EXPR
	| EXPR MUL_OP EXPR
	| EXPR DIV_OP EXPR
	| EXPR MOD_OP EXPR
	
	| EXPR LT_OP EXPR
	| EXPR GT_OP EXPR
	| EXPR LE_OP EXPR
	| EXPR GE_OP EXPR
	| EXPR EQ_OP EXPR
	| EXPR NE_OP EXPR

	/*
	| EXPR AND_OP EXPR
	| EXPR OR_OP EXPR
	| NOT_OP EXPR 
	*/
	| '(' EXPR ')'
	;

REF_EXPR
	: REF_VAR_EXPR
	| REF_CALL_EXPR
	;

REF_VAR_EXPR
	: REF_EXPR '.' IDENT_EXPR
	| IDENT_EXPR
	;

REF_CALL_EXPR
	: REF_EXPR '.' CALL_EXPR
	| CALL_EXPR
	;

IDENT_EXPR
	: ID '[' EXPR ']'
	| ID {
		if(findInSymbolTable(current_scope, $1) == -1){
			yyerror("Variable not declared");
		}
	}
	;

CALL_EXPR
	: ID '(' ARG_LIST ')'
	| ID '(' ')'
	;

ARG_LIST
	: ARG
	| ARG_LIST ',' ARG
	;

ARG
	: EXPR
	;


%%


// Symbol table functions

// Returns 1 if valid insertion, else 0 if identifier already exists
int insertInSymbolTable(int* count, int scope, char *datatype, char* name, int line_no, char* value){
	
	// Check if identifier already present in the same scope
	for(int j = 0; j < *count; ++j){
		if(!strcmp(symbolTable[j].name, name) && symbolTable[j].scope == scope){ // one more condition?
			return 0;
		}
	}

	// Check if the value passed is a variable or a number

	int identifierIndex = -1;

	for(int i = 0; i < *count; ++i)
	{
		if(!strcmp(symbolTable[i].name, value) && symbolTable[i].scope == scope){
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
        printf("Printing symbol table: \n");
        printf("Token\t\tData type\tScope\t\tValue\t\tLine number\n");
        for(int i = 0; i < numRecords; ++i)
        {
        	printf("%s\t\t%s\t\t%d\t\t%d\t\t%d\n", symbolTable[i].name, symbolTable[i].datatype, symbolTable[i].scope, symbolTable[i].value, symbolTable[i].line_no);
        }
}


// Returns position if finds record, else -1
int findInSymbolTable(int  scope, char *name){
	int present = 0;
	for(int i = 0; i < numRecords; ++i){
		if(!strcmp(symbolTable[i].name, name) && symbolTable[i].scope <= scope){
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

void yyerror(char *s){
	extern int yylineno;
	printf("\n\nERROR:\n Line number: %d \t Error: %s\n", yylineno, s);
}

int main(){
	current_scope = 0;
	numRecords = 0;
	yyparse();
	return 0;
}
