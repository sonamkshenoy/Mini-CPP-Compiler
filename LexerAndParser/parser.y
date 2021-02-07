%{
	#include <stdio.h>
	int yylex(void);
	void yyerror(char *);
%}

%start Prog

%token INT FLOAT IF ELSE WHILE SWITCH CASE INCLUDE ID NUM ASSIGN_OP ARITH_OP REL_OP

%%
Prog : S
	;
S:		
	Decl';' S
	| Assign';' S
	| IF'('Cond')''{'S'}' S
	| IF'('Cond')''{'S'}' ELSE '{'S'}' S
	| /*NULL*/
	;

Decl: 
	Type ListVar
	;

Type: 
	INT
	|FLOAT
	;

ListVar: 
	ID
	| ListVar ',' ID
	;

Assign: 
	ID '=' E 
	;

Cond: 
	ID REL_OP ID
	;

E: 
	E '+' T
	| E '-' T
	| T
	| ID
	;

T: 
	T '*' F
	| T '/' F
	| F
	;

F: 
	G '^' F
	| G
	;

G: 
	'(' E ')'
	|ID
	|NUM
	;

%%

void yyerror(char *s){
	printf("%s\n", s);
}

int main(){
	yyparse();
	return 0;
}
