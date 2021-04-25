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

%}

%token T_IDENTIFIER T_CONSTANT T_STRING_LITERAL 
%token T_PTR_OP T_INC_OP T_DEC_OP T_LE_OP T_GE_OP T_EQ_OP T_NE_OP
%token T_AND_OP T_OR_OP 
%token T_CHAR T_INT T_FLOAT T_DOUBLE T_VOID
%token T_CLASS T_PUBLIC T_PRIVATE
%token T_ELLIPSIS
%token T_CASE T_DEFAULT T_IF T_ELSE T_SWITCH T_WHILE T_FOR T_BREAK T_CONTINUE T_RETURN 


%nonassoc T_IFX
%nonassoc T_ELSE


%start S

%%

primary_expression
	: T_IDENTIFIER {
		if(findInSymbolTable(current_scope, $1) == -1){
			yyerror("Variable not declared");
		}
	}
	| T_CONSTANT
	| T_STRING_LITERAL
	| '(' expression ')'
	;

postfix_expression
	: primary_expression
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression '.' T_IDENTIFIER
	| postfix_expression T_INC_OP
	| postfix_expression T_DEC_OP
	;

argument_expression_list
	: argument_expression_list ',' assignment_expression
	| assignment_expression
	;

unary_expression
	: postfix_expression
	| T_INC_OP unary_expression 
	| T_DEC_OP unary_expression 
	| unary_operator unary_expression
	;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;

multiplicative_expression
	: unary_expression
	| multiplicative_expression '*' unary_expression { 
		int value = doOperation($1, $3, '*', current_scope);
		sprintf($$, "%d", value);
	}
	| multiplicative_expression '/' unary_expression { 
		int value = doOperation($1, $3, '/', current_scope);
		sprintf($$, "%d", value);
	}
	| multiplicative_expression '%' unary_expression { 
		int value = doOperation($1, $3, '%', current_scope);
		sprintf($$, "%d", value);
	}
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression { 
		int value = doOperation($1, $3, '+', current_scope);
		sprintf($$, "%d", value);
	}
	| additive_expression '-' multiplicative_expression { 
		int value = doOperation($1, $3, '-', current_scope);
		sprintf($$, "%d", value);
	}
	;

shift_expression
	: additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression T_LE_OP shift_expression
	| relational_expression T_GE_OP shift_expression
	;

equality_expression
	: relational_expression
	| equality_expression T_EQ_OP relational_expression
	| equality_expression T_NE_OP relational_expression
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression T_AND_OP inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression T_OR_OP logical_and_expression
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression
	;

assignment_expression
	: unary_expression assignment_operator assignment_expression  {
		if (findInSymbolTable(current_scope, $1) == -1) {
		      yyerror("Variable not declared");
		}
		updateSymbolTable($1, $3, current_scope);
		displaySymbolTable();
	}
	;
	| conditional_expression 
	;

assignment_operator
	: '='
	;

expression
	: expression ',' assignment_expression
	| assignment_expression
	;

constant_expression
	: conditional_expression
	;

declaration
	: declaration_specifiers init_declarator_list ';'
	| declaration_specifiers ';'
	;

declaration_specifiers
	: type_specifier declaration_specifiers 
	| type_specifier
	;

init_declarator_list
	: init_declarator_list ',' init_declarator
	| init_declarator
	;

init_declarator
	:  declarator '=' conditional_expression {
		if(!insertInSymbolTable(&numRecords, current_scope, currentTypeName, $1,  yylineno, $3)){
			yyerror("Variable on LHS reinitialized or variable on RHS not present");
		}
		displaySymbolTable();
	}
	| declarator {
		if(!insertInSymbolTable(&numRecords, current_scope, currentTypeName, $1, yylineno, "0")){
			yyerror("Variable redeclared");
		}
		displaySymbolTable();
	}
	;

type_specifier
	: T_VOID { strcpy(currentTypeName, $1); }
	| T_CHAR { strcpy(currentTypeName, $1); }
	| T_INT { strcpy(currentTypeName, $1); }
	| T_FLOAT { strcpy(currentTypeName, $1); }
	| T_DOUBLE { strcpy(currentTypeName, $1); }
	;

declarator
	: direct_declarator
	;

direct_declarator
	: T_IDENTIFIER
	| '(' declarator ')'
	| direct_declarator '[' constant_expression ']'
	| direct_declarator '[' ']'
	| direct_declarator '(' parameter_type_list ')'
	| direct_declarator '(' identifier_list ')'
	| direct_declarator '(' ')'
	;

parameter_type_list
	: parameter_list
	| parameter_list ',' T_ELLIPSIS
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers
	;

identifier_list
	: identifier_list ',' T_IDENTIFIER
	| T_IDENTIFIER
	;

	/*
initializer
	: assignment_expression
	| '{' initializer_list '}'
	;

initializer_list
	: initializer_list ',' initializer
	| initializer
	;
	*/

all_statement
	: single_statement
	| compound_statement
	;

single_statement
	: declaration
	| simple_statement
	;

statement
	: compound_statement
	| simple_statement
	;

simple_statement
	: expression_statement
	| selection_statement
	| iteration_statement
	| T_BREAK ';'
	| T_CONTINUE ';'
	| T_RETURN expression ';'
	| T_RETURN ';'
	;

compound_statement
	: '{' declaration_list statement_list declaration_list '}'
	| '{' statement_list declaration_list statement_list  '}'
	| '{' statement_list declaration_list  '}'
	| '{' declaration_list statement_list '}'
	| '{' declaration_list '}'
	| '{' statement_list '}'
	| '{' '}'
	; 

declaration_list
	: declaration_list declaration
	| declaration
	;

statement_list
	: statement_list statement
	| statement
	;

expression_statement
	: ';'
	| expression ';'
	;

selection_statement
	: T_IF '(' expression ')' all_statement %prec T_IFX  
	| T_IF '(' expression ')' all_statement T_ELSE all_statement
	| switch_block 
	;

switch_block
	: T_SWITCH '(' expression ')' '{' case_list T_DEFAULT ':' case_statement '}'
	| T_SWITCH '(' expression ')' '{' case_list '}'
	;

case_list
	: case_list T_CASE T_CONSTANT ':' case_statement
	| T_CASE T_CONSTANT ':' case_statement
	;

case_statement
	: simple_statement case_statement
	| simple_statement
	| compound_statement
	;

iteration_statement
	: T_WHILE '(' expression ')' all_statement
	| T_FOR '(' expression_statement expression_statement ')' all_statement 
	| T_FOR '(' expression_statement expression_statement expression ')' all_statement 
	;

member
	: function_definition 
	| declaration 
	;

class_member
	: class_member member
	| member
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement 
	| declaration_specifiers declarator compound_statement
	| declarator declaration_list compound_statement
	| declarator compound_statement
	;

class_declarartion
	: T_CLASS T_IDENTIFIER '{' T_PRIVATE ':' class_member T_PUBLIC ':' class_member '}' ';' 
	| T_CLASS T_IDENTIFIER '{' T_PRIVATE ':' class_member '}' ';' 
	| T_CLASS T_IDENTIFIER '{' T_PUBLIC ':' class_member '}' ';' 
	| T_CLASS T_IDENTIFIER '{' '}' ';' 
	;

external_declaration
	: function_definition
	| declaration
	| class_declarartion
	| error {yyerrok; yyclearin;}
	;

S
	: S external_declaration
	| external_declaration	
	;


%%


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
    symbolTable[*count].valid = 1;

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

        	if(symbolTable[i].valid == 1){
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