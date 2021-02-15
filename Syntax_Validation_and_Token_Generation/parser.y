%{

#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int yylex();
void yyerror(char *);
extern int yylineno;
int valid = 1;

%}


%token T_IDENTIFIER T_CONSTANT T_STRING_LITERAL 
%token T_PTR_OP T_INC_OP T_DEC_OP T_LE_OP T_GE_OP T_EQ_OP T_NE_OP
%token T_AND_OP T_OR_OP 
//%token T_ADD_ASSGN T_SUB_ASSIGN T_MUL_ASSIGN T_DIV_ASSIGN T_MOD_ASSGIN
%token T_CHAR T_INT T_FLOAT T_DOUBLE T_VOID
%token T_CLASS T_PUBLIC T_PRIVATE
%token T_ELLIPSIS
%token T_CASE T_DEFAULT T_IF T_ELSE T_SWITCH T_WHILE T_FOR T_BREAK T_CONTINUE T_RETURN 


%nonassoc T_IFX
%nonassoc T_ELSE


%start translation_unit


%%

primary_expression
	: T_IDENTIFIER
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
	| multiplicative_expression '*' unary_expression
	| multiplicative_expression '/' unary_expression
	| multiplicative_expression '%' unary_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
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
	: unary_expression assignment_operator assignment_expression 
	| conditional_expression
	;

assignment_operator
	: '='
//	| T_MUL_ASSIGN
//	| T_DIV_ASSIGN
//	| T_MOD_ASSIGN
//	| T_ADD_ASSIGN
//	| T_SUB_ASSIGN
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
	: declarator '=' initializer
	| declarator
	;
type_specifier
	: T_VOID
	| T_CHAR
	| T_INT
	| T_FLOAT
	| T_DOUBLE
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

initializer
	: assignment_expression
	| '{' initializer_list '}'
	;

initializer_list
	: initializer_list ',' initializer
	| initializer
	;

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

translation_unit
	: external_declaration
	| translation_unit external_declaration
	| T_CLASS external_declaration
	;

external_declaration
	: function_definition
	| declaration
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement 
	| declaration_specifiers declarator compound_statement
	| declarator declaration_list compound_statement
	| declarator compound_statement
	;

%%

void yyerror(char *s)
{
 	fprintf(stderr,"\n%s at line no %d\n", s, yylineno);  
	valid = 0;
}

int main()
{
	yyparse();
	if (valid)
		printf("\nParsing Successful :)\n\n");
	else
		printf("\nParsing Unsuccessful :(\n\n");
	return 0;
}
