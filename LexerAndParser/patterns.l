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
number {digits}{optionalFractionPart}{optionalExponentPart}
%%

"main" {return MAINFUNC;}
"include" {return INCLUDE;}

({letter}|"_")({letter}|"_"|{digit})*\.h {return HEADERFILE; /* ".h" not mandatory in CPP header files. Remove that */;}
{id} {return ID;}
"void" {return VOID;}
"int" {return INT;}
"float" {return FLOAT;}
"if" {return IF;}
"else" {return ELSE;}
"while" {return WHILE;}
"switch" {return SWITCH;}
"case" {return CASE;}
{number} {return NUM;}
"=" {return ASSIGN_OP;}
arithmeticOperator {return ARITH_OP;}
["<"|">"|"<="|">="|"=="|"!="] {return REL_OP;}
[\n|\t|' '] ;
. {return *yytext;}

%%


int yywrap(void){
	return 1;
}