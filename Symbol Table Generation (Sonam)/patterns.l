%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	#define YYSTYPE char*
	#include "y.tab.h"
	extern YYSTYPE yylval;

	void yyerror(char *);


	// scope of identifiers till now
	int current_scope = 1;

%}

INTNUM [0-9]+
FLOATNUM [0-9]+\.[0-9]+
ID [A-Za-z][A-Za-z0-9_]*     
SPACE [ \t\r\n]


%%


	/*	Lines	*/

	// [\n]				{ line++; }
	// "//".*["\n"*]			{ line++; };
	// "/*"(.|"\n")*"*/"(" "|\n)*	{ line++; };


	/*	Comments	*/


	/*	Main Function	*/
"main"	{ return MAIN; }


	/*	Headers and Libraries	*/
	/*
"#"				{ return HASH; }
"include"			{ return INCLUDE; }
"stdlib.h"			{ return STDLIB; }
"iostream"			{ return IOSTREAM; }
"math.h"			{ return MATH_H; }
"string.h"			{ return STRING_H; }
"time.h"			{ return TIME_H; }
\"{alphanum}+(".h"|".c")\"	{ return HEADERFILE; }
	*/

	/*	Data Types	*/
"void"		{ 
				yylval = strdup(yytext);
				return VOID; 
			}
"char"		{ 
				yylval = strdup(yytext);
				return CHAR; 
			}
"int"		{	
				yylval = strdup(yytext); 
				return INT; 
			}
"float"		{ 
				yylval = strdup(yytext);
				return FLOAT; 
			}
"double"	{ 
				yylval = strdup(yytext);
				return DOUBLE; 
			}
"bool"		{ 
				yylval = strdup(yytext);
				return BOOL; 
			}
"string"	{ 
				yylval = strdup(yytext);
				return STRING; 
			}

	/*	Control Structures	*/
"if"		{ return IF; }
"else"		{ return ELSE; }
"while"		{ return WHILE; }
	/*
"switch"	{ return SWITCH; }
"case"		{ return CASE; }
"default"	{ return DEFAULT; }
	*/

	/*	Other Statements	*/
"return"	{ return RETURN; }
	/*
"continue"	{ return CONTINUE; }
"break"		{ return BREAK; }
"using"		{ return USING; }
"namespace"	{ return NAMESPACE; }
"std"		{ return STD; }
"endl"		{ return ENDL; }
	*/

	/*	"struct"	{ return STRUCT; }	*/
"public"	{ return PUBLIC; }
"private"	{ return PRIVATE; }
	/*	"protected"	{ return PROTECTED; }	*/

	/*
"printf"	{ return PRINT; }
"<<"		{ return COUT_OP; }
">>"		{ return CIN_OP; }
"cout"		{ return COUT; }
"cin"		{ return CIN; }
	*/


	/*
\".*\"		{ return STRING_LITERAL; }
	*/

	/*	Assignmet Operators	*/
	/*
"+="	{ return ADD_ASGN; }
"-="	{ return SUB_ASGN; }
"*="	{ return MUL_ASGN; }
"/="	{ return DIV_ASGN; }
"%="	{ return MOD_ASGN; }
	*/

	/*	Relational Operators	*/
"<="	{ return LE_OP; }
">="	{ return GE_OP; }
"=="	{ return EQ_OP; }
"!="	{ return NE_OP; }
"<"	{ return LT_OP; }
">"	{ return GT_OP;	}

	/*	Logical Operators	*/
	/*
"&&"	{ return AND_OP; }
"||"	{ return OR_OP; }	
"!"	{ return NOT_OP; }
	*/

	/*	Arithmetic Operators	*/
	/*
"++"	{ return INC_OP; }
"--"	{ return DEC_OP; }
	*/
"+"	{ 
		yylval = strdup(yytext);
		return ADD_OP; 
	}
"-"	{ 
		yylval = strdup(yytext);
		return SUB_OP; 
	}	
"*"	{ 
		yylval = strdup(yytext);
		return MUL_OP; 
	}
"/"	{ 
		yylval = strdup(yytext);
		return DIV_OP; 
	}
"%"	{ 
		yylval = strdup(yytext);
		return MOD_OP; 
	}


	/*	Synatx	*/
"="		{ return ASGN_EQ_OP; }
("["|"<:")	{ return '['; }
("]"|":>")	{ return ']'; }
"."		{ return '.'; }
";"		{ return ';'; }
","		{ return ','; }
":"		{ return ':'; }
"{"		{ 
			++current_scope;
			return '{'; 
		}
"}"		{ 
			--current_scope;
			return '}'; 
		}
"("		{ return '('; }
")"		{ return ')'; }

{INTNUM}	{
				yylval = strdup(yytext);
				return INTNUM; 
			}

{FLOATNUM}	{
				yylval = strdup(yytext);
    			return FLOATNUM;
			}

{ID}	{
			yylval = strdup(yytext);
		    return ID;
		}

{SPACE} {/*do nothing here*/}



%%


int yywrap(void)
{
	return 1;
}
