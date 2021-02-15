%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	
	#include "y.tab.h"

	extern void yyerror(char *);
	void print_token();
	
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

	/*	Headers and Libraries	*/
.*\/\/.*    			{;}
.*"/*"([^*]|\*+[^*/])*+\*"/" 	{;}
"#include"[ ]*"<".*">"\n 	{
					/*printf("%s\n", yytext);*/
				}
"#include"[ ]*"\"".*"\"" 	{
					/*printf("%s\n", yytext);*/
				}


	/* Constants	*/
0{D}+{IS}?		{ print_token(); yylval=atoi(yytext); return(T_CONSTANT); }
{D}+{IS}?		{ print_token(); yylval=atoi(yytext); return(T_CONSTANT); }
L?'(\\.|[^\\'])+'	{ print_token(); return(T_CONSTANT); }
{D}+{E}{FS}?		{ print_token(); yylval=atof(yytext); return(T_CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{ print_token(); yylval=atof(yytext); return(T_CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{ print_token(); yylval=atof(yytext); return(T_CONSTANT); }


	/* String Literal	*/
L?\"(\\.|[^\\"])*\"	{ print_token(); return(T_STRING_LITERAL); }


	/* Language Constructs	*/
	/*"main"	{ print_token(); return (T_MAIN); }*/
"class"		{ print_token(); return(T_CLASS); }
"public"	{ print_token(); return (T_PUBLIC); }
"private"	{ print_token(); return (T_PRIVATE); }
	/*"using"	{ print_token(); return (T_USING); }*/
	/*"namespace"	{ print_token(); return (T_NAMESPACE); }*/
	/*"std"		{ print_token(); return (T_STD); }*/
	/*"print"	{ print_token(); return (T_PRINT); }*/
	/*"cout"	{ print_token(); return (T_COUT); }*/
	/*"endl"	{ print_token(); return (T_ENDL); }*/


	/*	Data Types	*/
"void"		{ print_token(); return (T_VOID); }
"char"		{ print_token(); return (T_CHAR); }
"int"		{ print_token(); return (T_INT); }
"float"		{ print_token(); return (T_FLOAT); }
"double"	{ print_token(); return (T_DOUBLE); }


	/*	Control Structures */	

"if"		{ print_token(); return (T_IF); }
"else"		{ print_token(); return (T_ELSE); }
"while"		{ print_token(); return (T_WHILE); }
"for"		{ print_token(); return (T_FOR); }
	
"switch"	{ print_token(); return (T_SWITCH); }
"case"		{ print_token(); return (T_CASE); }
"default"	{ print_token(); return (T_DEFAULT); }
"break"		{ print_token(); return (T_BREAK); }
"continue"	{ print_token(); return (T_CONTINUE); }
"return"	{ print_token(); return (T_RETURN); }


	/*	Assignmet Operators	*/
	/*
"+="	{ print_token(); return (T_ADD_ASGN); }
"-="	{ print_token(); return (T_SUB_ASGN); }
"*="	{ print_token(); return (T_MUL_ASGN); }
"/="	{ print_token(); return (T_DIV_ASGN); }
"%="	{ print_token(); return (T_MOD_ASGN); }
	*/

	/*	Relational Operators	*/
"<="	{ print_token(); return (T_LE_OP); }
">="	{ print_token(); return (T_GE_OP); }
"=="	{ print_token(); return (T_EQ_OP); }
"!="	{ print_token(); return (T_NE_OP); }
"<"	{ print_token(); return ('<'); }
">"	{ print_token(); return ('>');	}

	/*	Logical Operators	*/
"&&"	{ print_token(); return (T_AND_OP); }
"||"	{ print_token(); return (T_OR_OP); }	
"!"	{ print_token(); return ('!'); }


	/*	Arithmetic Operators	*/
"++"	{ print_token(); return (T_INC_OP); }
"--"	{ print_token(); return (T_DEC_OP); }

"+"	{ print_token(); return ('+'); }
"-"	{ print_token(); return ('-'); }	
"*"	{ print_token(); return ('*'); }
"/"	{ print_token(); return ('/'); }
"%"	{ print_token(); return ('%'); }


	/*	Synatx	*/
"="		{ print_token(); return ('='); }
"->"		{ print_token(); return (T_PTR_OP); }
("["|"<:")	{ print_token(); return ('['); }
("]"|":>")	{ print_token(); return (']'); }
"."		{ print_token(); return ('.'); }
";"		{ print_token(); return (';'); }
","		{ print_token(); return (','); }
":"		{ print_token(); return (':'); }
("{"|"<%")	{ print_token(); return ('{'); }
("}"|"%>")	{ print_token(); return ('}'); }
"("		{ print_token(); return ('('); }
")"		{ print_token(); return (')'); }

"&"		{ print_token(); return('&'); }
"~"		{ print_token(); return('~'); }
"^"		{ print_token(); return('^'); }
"|"		{ print_token(); return('|'); }
"?"		{ print_token(); return('?'); }


{ID} 		{ print_token(); return(T_IDENTIFIER); }
[\n]*		{ /*printf("\n"); */
		}
[ \t\v\f]*	{ /*printf(" "); */
		}

	/*	Other	*/
.		{ /* ignore bad characters */ }

%%

void print_token()
{
	;
}

int yywrap(void)
{
	return 1;
}
