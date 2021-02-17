%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	
	#include "y.tab.h"

	extern void yyerror(char *);
	void print_token(char *text, char *tokentext);
	
%}

%option yylineno


D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*
ID 			{L}({L}|{D})*



%%


	/*	Comments	*/

\/\/.*\n		{ print_token(yytext, "comment"); }
"/*"([^*]|\*+[^*/])*\*+"/"	{ print_token(yytext, "comment"); }


	/*	Headers and Libraries	*/
"#include"[ ]*"<".*">"\n 	{
					/*printf("%s\n", yytext);*/
				}
"#include"[ ]*"\"".*"\"" 	{
					/*printf("%s\n", yytext);*/
				}

	/* Constants	*/
0{D}+{IS}?				{ print_token(yytext, "T_CONSTANT");return(T_CONSTANT); }
{D}+{IS}?				{ print_token(yytext, "T_CONSTANT"); return(T_CONSTANT); }
L?'(\\.|[^\\'])+'		{ print_token(yytext, "T_CONSTANT"); return(T_CONSTANT); }
{D}+{E}{FS}?			{ print_token(yytext, "T_CONSTANT"); return(T_CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{ print_token(yytext, "T_CONSTANT"); return(T_CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{ print_token(yytext, "T_CONSTANT"); return(T_CONSTANT); }


	/* String Literal	*/
L?\"(\\.|[^\\"])*\"	{ print_token(yytext, "T_STRING_LITERAL"); return(T_STRING_LITERAL); }


	/* Language Constructs	*/
"class"		{ print_token(yytext, "T_CLASS"); return(T_CLASS); }
"public"	{ print_token(yytext, "T_PUBLIC"); return (T_PUBLIC); }
"private"	{ print_token(yytext, "T_PRIVATE"); return (T_PRIVATE); }


	/*	Data Types	*/
"void"		{ print_token(yytext, "T_VOID"); return (T_VOID); }
"char"		{ print_token(yytext, "T_CHAR"); return (T_CHAR); }
"int"		{ print_token(yytext, "T_INT"); return (T_INT); }
"float"		{ print_token(yytext, "T_FLOAT"); return (T_FLOAT); }
"double"	{ print_token(yytext, "T_DOUBLE"); return (T_DOUBLE); }


	/*	Control Structures */	
"if"		{ print_token(yytext, "T_IF"); return (T_IF); }
"else"		{ print_token(yytext, "T_ELSE"); return (T_ELSE); }
"while"		{ print_token(yytext, "T_WHILE"); return (T_WHILE); }
"for"		{ print_token(yytext, "T_FOR"); return (T_FOR); }
	
"switch"	{ print_token(yytext, "T_SWITCH"); return (T_SWITCH); }
"case"		{ print_token(yytext, "T_CASE"); return (T_CASE); }
"default"	{ print_token(yytext, "T_DEFAULT"); return (T_DEFAULT); }
"break"		{ print_token(yytext, "T_BREAK"); return (T_BREAK); }
"continue"	{ print_token(yytext, "T_CONTINUE"); return (T_CONTINUE); }
"return"	{ print_token(yytext, "T_RETURN"); return (T_RETURN); }


	/*	Relational Operators	*/
"<="	{ print_token(yytext, "T_LE_OP"); return (T_LE_OP); }
">="	{ print_token(yytext, "T_GE_OP"); return (T_GE_OP); }
"=="	{ print_token(yytext, "T_EQ_OP"); return (T_EQ_OP); }
"!="	{ print_token(yytext, "T_NE_OP"); return (T_NE_OP); }
"<"		{ print_token(yytext, "<"); return ('<'); }
">"		{ print_token(yytext, ">"); return ('>');	}

	/*	Logical Operators	*/
"&&"	{ print_token(yytext, "T_AND_OP"); return (T_AND_OP); }
"||"	{ print_token(yytext, "T_OR_OP"); return (T_OR_OP); }	
"!"		{ print_token(yytext, "!"); return ('!'); }


	/*	Arithmetic Operators	*/
"++"	{ print_token(yytext, "T_INC_OP"); return (T_INC_OP); }
"--"	{ print_token(yytext, "T_DEC_OP"); return (T_DEC_OP); }

"+"		{ print_token(yytext, "+"); return ('+'); }
"-"		{ print_token(yytext, "-"); return ('-'); }	
"*"		{ print_token(yytext, "*"); return ('*'); }
"/"		{ print_token(yytext, "/"); return ('/'); }
"%"		{ print_token(yytext, "%"); return ('%'); }


	/*	Synatx	*/
"="			{ print_token(yytext, "="); return ('='); }
"->"		{ print_token(yytext, "T_PTR_OP"); return (T_PTR_OP); }
("["|"<:")	{ print_token(yytext, "["); return ('['); }
("]"|":>")	{ print_token(yytext, "]"); return (']'); }
"."			{ print_token(yytext, "."); return ('.'); }
";"			{ print_token(yytext, ";"); return (';'); }
","			{ print_token(yytext, ","); return (','); }
":"			{ print_token(yytext, ":"); return (':'); }
("{"|"<%")	{ print_token(yytext, "{"); return ('{'); }
("}"|"%>")	{ print_token(yytext, "}"); return ('}'); }
"("			{ print_token(yytext, "("); return ('('); }
")"			{ print_token(yytext, ")"); return (')'); }

"&"			{ print_token(yytext, "&"); return('&'); }
"~"			{ print_token(yytext, "~"); return('~'); }
"^"			{ print_token(yytext, "^"); return('^'); }
"|"			{ print_token(yytext, "|"); return('|'); }
"?"			{ print_token(yytext, "?"); return('?'); }


{ID} 		{ print_token(yytext, "T_IDENTIFIER"); return(T_IDENTIFIER); }
[\n]*		{ print_token(yytext, "whitespace"); }
[ \t\v\f]*	{ print_token(yytext, "whitespace"); }






	/*	Other	*/
.			{  }

%%

void print_token(char *text, char *token_text)
{
	printf("%s\t\t%s\n", text, token_text)
	;
}

int yywrap(void)
{
	return 1;
}

