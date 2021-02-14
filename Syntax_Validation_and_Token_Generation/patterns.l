%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	
	#include "y.tab.h"

	void yyerror(char *);
	void print_token();
	
%}

D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*

ID 			{L}({L}|{D})*
%option yylineno

%%

	/*	Headers and Libraries	*/
.*\/\/.*    {;}
.*"/*"([^*]|\*+[^*/])*+\*"/" {;}
"#include"[ ]*"<".*">"\n {printf("%s\n", yytext);}
"#include"[ ]*"\"".*"\"" {printf("%s\n", yytext);}

0{D}+{IS}?				{ print_token();yylval=atoi(yytext); return(CONSTANT); }
{D}+{IS}?				{ print_token();yylval=atoi(yytext); return(CONSTANT); }
L?'(\\.|[^\\'])+'		{ print_token(); return(CONSTANT); }

{D}+{E}{FS}?			{ print_token(); yylval=atof(yytext);return(CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{ print_token(); yylval=atof(yytext);return(CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{ print_token(); yylval=atof(yytext);return(CONSTANT); }

L?\"(\\.|[^\\"])*\"		{ print_token(); return(STRING_LITERAL); }

	/*"main"		{ return (MAIN); }*/

	/*	Data Types	*/
"void"		{ print_token(); return (VOID); }
"char"		{ print_token(); return (CHAR); }
"int"		{ print_token(); return (INT); }
"float"		{ print_token(); return (FLOAT); }
"double"	{ print_token(); return (DOUBLE); }
"class"		{print_token(); return(CLASS);}

	/*	Control Structures */	
"if"		{ print_token(); return (IF); }
"else"		{ print_token(); return (ELSE); }
"while"		{ print_token(); return (WHILE); }
"for"		{ print_token(); return (FOR); }
	
"switch"	{ print_token(); return (SWITCH); }
"case"		{ print_token(); return (CASE); }
"default"	{ print_token(); return (DEFAULT); }
"break"		{ print_token(); return (BREAK); }

"return"	{ print_token(); return (RETURN); }
	/*
"using"		{ return USING; }
"namespace"	{ return NAMESPACE; }
"std"		{ return STD; }
"endl"		{ return ENDL; }
	*/

	/*	"struct"	{ return STRUCT; }	*/
	/*"public"	{ princode(); return (PUBLIC); }
	"private"	{ princode(); return (PRIVATE); }*/
	/*	Assignmet Operators	*/
	/*
"+="	{ return ADD_ASGN; }
"-="	{ return SUB_ASGN; }
"*="	{ return MUL_ASGN; }
"/="	{ return DIV_ASGN; }
"%="	{ return MOD_ASGN; }
	*/

	/*	Relational Operators	*/
"<="	{ print_token(); return (LE_OP); }
">="	{ print_token(); return (GE_OP); }
"=="	{ print_token(); return (EQ_OP); }
"!="	{ print_token(); return (NE_OP); }
"<"		{ print_token(); return ('<'); }
">"		{ print_token(); return ('>');	}

	/*	Logical Operators	*/
"&&"	{ print_token(); return (AND_OP); }
"||"	{ print_token(); return (OR_OP); }	
"!"		{ print_token(); return ('!'); }


	/*	Arithmetic Operators	*/
"++"	{ print_token(); return (INC_OP); }
"--"	{ print_token(); return (DEC_OP); }
"->"	{ print_token(); return(PTR_OP); }

"+"		{ print_token(); return ('+'); }
"-"		{ print_token(); return ('-'); }	
"*"		{ print_token(); return ('*'); }
"/"		{ print_token(); return ('/'); }
"%"		{ print_token(); return ('%'); }

	/*	Synatx	*/
"="				{ print_token(); return ('='); }
("["|"<:")		{ print_token(); return ('['); }
("]"|":>")		{ print_token(); return (']'); }
"."				{ print_token(); return ('.'); }
";"				{ print_token(); return (';'); }
","				{ print_token(); return (','); }
":"				{ print_token(); return (':'); }
("{"|"<%")		{ print_token(); return ('{'); }
("}"|"%>")		{ print_token(); return ('}'); }
"("				{ print_token(); return ('('); }
")"				{ print_token(); return (')'); }
"&"				{ print_token(); return('&'); }
"~"				{ print_token(); return('~'); }
"^"				{ print_token(); return('^'); }
"|"				{ print_token(); return('|'); }
"?"				{ print_token(); return('?'); }

{ID} 				{print_token(); return(IDENTIFIER);}
[\n]* 				{ printf("\n");}
[ \t\n\v\f]*		{ printf(" "); }

.			{ /* ignore bad characters */ }

%%

void print_token()
{
	ECHO;
}

int yywrap(void)
{
	return 1;
}
