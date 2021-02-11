%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	#include <iostream>

	#include "y.tab.h"

	void yyerror(char *);

	int line=1;
	extern int scope;
%}
digit		[0-9]
letter		[a-zA-Z_]
alphanum	[a-zA-Z_0-9]
id		{letter}({letter}{digit})*
digits		{digit}+
optionalFractionPart	(\.{digits})?
optionalExponentPart	([Ee][+-]?{digits})?
number		{digits}{optionalFractionPart}{optionalExponentPart}
whitespace	[ \t\v\f]


%%


	/*	Lines	*/
[\n]				{ line++; }
"//".*["\n"*]			{ line++; };
"/*"(.|"\n")*"*/"(" "|\n)*	{ line++; };

	/*	Comments	*/


	/*	Main Function	*/
"main"	{ return MAINFUNC; }


	/*	Headers and Libraries	*/
"#"				{ return HASH; }
"include"			{ return INCLUDE; }
"stdlib.h"			{ return STDLIB; }
"iostream"			{ return IOSTREAM; }
"math.h"			{ return MATH_H; }
"string.h"			{ return STRING_H; }
"time.h"			{ return TIME_H; }
\"{alphanum}+(".h"|".c")\"	{ return HEADERFILE; }

	/*	Data Types	*/
"void"		{ return VOID; }
"char"		{ return CHAR; }
"int"		{ return INT; }
"float"		{ return FLOAT; }
"double"	{ return DOUBLE; }
"bool"		{ return BOOL; }
"string"	{ return STRING; }

	/*	Control Structures	*/
"if"		{ return IF; }
"else"		{ return ELSE; }
"while"		{ return WHILE; }
"switch"	{ return SWITCH; }
"case"		{ return CASE; }
"default"	{ return DEFAULT; }

	/*	Other Statements	*/
"continue"	{ return CONTINUE; }
"break"		{ return BREAK; }
"return"	{ return RETURN; }
"using"		{ return USING; }
"namespace"	{ return NAMESPACE; }
"std"		{ return STD; }
"endl"		{ return ENDL; }

"struct"	{ return STRUCT; }
"class"		{ return CLASS; }
"public"	{ return PUBLIC; }
"private"	{ return PRIVATE; }
"protected"	{ return PROTECTED; }

"printf"	{ return PRINT; }
"<<"		{ return COUTOP; }
">>"		{ return CINOP; }
"cout"		{ return COUT; }
"cin"		{ return CIN; }

	/*	Indentifiers and Literals	*/
{id}		{ return ID; }
{number}	{ return NUM; }

	/*	Assignmet Operators	*/
"+="	{ return ADD_ASGN; }
"-="	{ return SUB_ASGN; }
"*="	{ return MUL_ASGN; }
"/="	{ return DIV_ASGN; }
"%="	{ return MOD_ASGN; }

	/*	Relational Operators	*/
"<="	{ return LE_OP; }
">="	{ return GE_OP; }
"=="	{ return EQ_OP; }
"!="	{ return NE_OP; }
"<"	{ return LT_OP; }
">"	{ return GT_OP;	}

	/*	Logical Operators	*/
"&&"	{ return AND_OP; }
"||"	{ return OR_OP; }	
"!"	{ return NOT_OP; }

	/*	Arithmetic Operators	*/
"++"	{ return INC_OP; }
"--"	{ return DEC_OP; }
"+"	{ return '+'; }
"-"	{ return '-'; }	
"*"	{ return '*'; }
"/"	{ return '/'; }
"%"	{ return '%'; }


	/*	Synatx	*/
"="		{ return ASGN_OP; }
("["|"<:")	{ return '['; }
("]"|":>")	{ return ']'; }
"."		{ return DOT; }
";"		{ return ';'; }
","		{ return ','; }
":"		{ return ':'; }
"{"		{ scope++; return '{'; }
"}"		{ return '}'; }
"("		{ return ')'; }
")"		{ return ')'; }

. {return *yytext;}


%%


int yywrap(void)
{
	return 1;
}
