%{
	#include <stdio.h>
	int yylex(void);
	void yyerror(char *);
%}

%token MAINFUNC 

%token HASH INCLUDE STDLIB IOSTREAM MATH_H STRING_H TIME_H HEADERFILE 

%token VOID CHAR INT FLOAT DOUBLE BOOL STRING

%token IF ELSE WHILE SWITCH CASE DEFAULT

%token CONTINUE BREAK RETURN USING NAMESPACE STD ENDL

%token STRUCT CLASS PUBLIC PRIVATE PROTECTED

%token PRINT COUTOP CINOP COUT CIN

%token ID NUM

%token ADD_ASGN SUB_ASGN MUL_ASGN DIV_ASGN MOD_ASGN

%token LE_OP GE_OP EQ_OP NE_OP LT_OP GT_OP

%token AND_OP OR_OP NOT_OP

%token INC_OP DEC_OP

%token ASGN_OP

%token DOT

	
%start Prog


%%

Prog 
	: HEADERS
	;

HEADERS
	: '#' INCLUDE '<' HEADERFILE '>' HEADERS
	| '#' INCLUDE '"' HEADERFILE '"' HEADERS
	| MAINWRAPPER
	;

MAINWRAPPER
	: VOID MAINFUNC'('')' MAINBODY
	| INT MAINFUNC'('')' MAINBODY;
	;

MAINBODY
	: '{' S '}' { printf("Valid!\n"); YYACCEPT; }
	;

S
	: Decl ';' S
	| Assign ';' S
	| Init ';' S
	| IF'('Cond')''{'S'}' S
	| IF'('Cond')''{'S'}' ELSE '{'S'}' S
	| WHILE '(' Cond ')' '{' S '}' S
	| /*NULL*/
	;

Decl
	: Type ListVar
	;

Type
	: INT
	| FLOAT
	;

ListVar
	: ID
	| ListVar ',' ID
	;

Assign
	: ID ASGN_OP E 
	;

Init
	: Type ID ASGN_OP E
	;

Rel_op
	: LE_OP 
	| GE_OP 
	| EQ_OP 
	| NE_OP 
	| LT_OP 
	| GT_OP
	;

Cond
	: ID Rel_op ID
	| ID Rel_op NUM
	| NUM Rel_op ID
	;

E
	: E '+' T
	| E '-' T
	| T
	;

T
	: T '*' F
	| T '/' F
	| F
	;

F
	: G '^' F
	| G
	;

G
	: '(' E ')'
	| ID
	| NUM
	;

%%

void yyerror(char *s){
	printf("%s\n", s);
}

int main(){
	yyparse();
	return 0;
}