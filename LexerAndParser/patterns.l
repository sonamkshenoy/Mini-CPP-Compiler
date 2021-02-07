%{
	#include <stdio.h>
	#include "y.tab.h"
	void yyerror(char *);
%}

digit [0-9]
letter [a-zA-Z]
id {letter}({letter}{digit})*
digits {digit}+
optionalFractionPart (\.{digits})?
optionalExponentPart ([Ee][+-]?{digits})?
assignmentOperator =
arithmeticOperator [+|-|*|/|%]
relationalOperator [<|>|<=|>=|==|!=]
number {digits}{optionalFractionPart}{optionalExponentPart}

%%

"int" return INT;
"float" return FLOAT;
"while" return WHILE;
"switch" return SWITCH;
"case" return CASE;
{id} return ID;
{number} return NUM;
assignmentOperator return ASSIGN_OP;
arithmeticOperator return ARITH_OP;
relationalOperator return REL_OP;
[\n|\t|' '] ;
. return *yytext;

%%

int yywrap(void){
	return 1;
}