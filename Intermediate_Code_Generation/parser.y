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
%token T_CHAR T_INT T_FLOAT T_DOUBLE T_VOID
%token T_CLASS T_PUBLIC T_PRIVATE
%token T_ELLIPSIS
%token T_CASE T_DEFAULT T_IF T_ELSE T_SWITCH T_WHILE T_FOR T_BREAK T_CONTINUE T_RETURN 


%nonassoc T_IFX
%nonassoc T_ELSE


%start S

%%

primary_expression
	: T_IDENTIFIER 					{strcpy($$,$1);}
	| T_CONSTANT					{strcpy($$,$1);}
	| T_STRING_LITERAL 				{strcpy($$,$1);}
	| '(' expression ')' 			{strcpy($$,$1);}
	;

postfix_expression
	: primary_expression						{strcpy($$, $1);}
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression '.' T_IDENTIFIER
	| postfix_expression T_INC_OP
		{
			sprintf(buffer,"t%d ",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s + 1\n",buffer, $1);
			fprintf(fp_quad, "\t+\t\t%s\t\t1 \t\t%s\n", $1, buffer);

			fprintf(fp_icg, "%s = %s\n", $1, buffer);
			fprintf(fp_quad, "\t=\t\t%s\t\t  \t\t%s\n", buffer, $1);
			
		}	
	| postfix_expression T_DEC_OP
		{
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s - 1\n",buffer, $1);
			fprintf(fp_quad, "\t-\t\t%s\t\t1 \t\t%s\n", $1, buffer);

			fprintf(fp_icg, "%s = %s\n", $1, buffer);
			fprintf(fp_quad, "\t=\t\t%s\t\t  \t\t%s\n", buffer, $1);
		}
	;

argument_expression_list
	: argument_expression_list ',' assignment_expression
	| assignment_expression
	;

unary_expression
	: postfix_expression {strcpy($$, $1);}
	| T_INC_OP unary_expression
	{
		sprintf(buffer,"t%d",tempno++);
		m = strlen(buffer);
		buffer[m] = '\0';
		fprintf(fp_icg, "%s = %s + 1\n",buffer, $2);
		fprintf(fp_quad, "\t+\t\t%s\t\t1 \t\t%s\n", $2, buffer);
		strncpy($$, buffer, m+1);		//check out
		unaryop = -1;
	}

	| T_DEC_OP unary_expression
	{
		sprintf(buffer,"t%d",tempno++);
		m = strlen(buffer);
		buffer[m] = '\0';
		fprintf(fp_icg, "%s = %s - 1\n",buffer, $2);
		fprintf(fp_quad, "\t-\t\t%s\t\t1 \t\t%s\n", $2, buffer);
		strncpy($$, buffer, m+1);		//check out
		unaryop = -1;
	} 
	| unary_operator unary_expression
		{
			switch(unaryop){
				case 1: 
						sprintf(buffer,"t%d",tempno++);	
						m = strlen(buffer);
						buffer[m] = '\0';					
						fprintf(fp_icg, "%s = -%s\n",buffer, $2);	
						fprintf(fp_quad, "\t-\t\t%s\t\t  \t\t%s\n", $2, buffer);
						strncpy($$, buffer, m+1);						
						break;
			}
			unaryop = -1;
		}			
	;

unary_operator
	: '-' {	unaryop = 1;}
	| '*' {	unaryop = 2; }
	| '+' {	unaryop = 3; }
	| '&' {	unaryop = 4; }
	| '~' {	unaryop = 5; }
	| '!' {	unaryop = 6; }
	;

multiplicative_expression
	: unary_expression
	| multiplicative_expression '*' unary_expression
		{
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s * %s\n",buffer, $1, $3);
			fprintf(fp_quad, "\t*\t\t%s\t\t%s\t\t%s\n", $1, $3, buffer);

			strncpy($$, buffer, m+1);		//check out
		}
	| multiplicative_expression '/' unary_expression
		{
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s / %s\n",buffer, $1, $3);
			fprintf(fp_quad, "\t/\t\t%s\t\t%s\t\t%s\n", $1, $3, buffer);

			strncpy($$, buffer, m+1);		//check out
		}
	| multiplicative_expression '%' unary_expression
		{
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s %c %s\n",buffer, $1, '%',$3);
			fprintf(fp_quad, "\t%c\t\t%s\t\t%s\t\t%s\n", '%',$1, $3, buffer);

			strncpy($$, buffer, m+1);		//check out
		}
	;

additive_expression
	: multiplicative_expression {	strcpy($$, $1); }
	| additive_expression '+' multiplicative_expression
		{
			// printf("%s + %s\n", $1, $3 );
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s + %s\n",buffer, $1, $3);
			fprintf(fp_quad, "\t+\t\t%s\t\t%s\t\t%s\n", $1, $3, buffer);

			strncpy($$, buffer, m+1);		//check out
		}	
	| additive_expression '-' multiplicative_expression
		{
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s - %s\n",buffer, $1, $3);
			fprintf(fp_quad, "\t-\t\t%s\t\t%s\t\t%s\n", $1, $3, buffer);

			strncpy($$, buffer, m+1);		//check out
		}
	;

shift_expression
	: additive_expression {	strcpy($$, $1); }
	;

relational_expression
	: shift_expression 
	| relational_expression '<' shift_expression
		{
			sprintf(buffer,"t %d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s < %s\n",buffer, $1, $3);
			fprintf(fp_quad, "\t<\t\t%s\t\t%s\t\t%s\n", $1, $3, buffer);

			strncpy($$, buffer, m+1);		//check out
		}
	| relational_expression '>' shift_expression
		{
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s > %s\n",buffer, $1, $3);
			fprintf(fp_quad, "\t>\t\t%s\t\t%s\t\t%s\n", $1, $3, buffer);

			strncpy($$, buffer, m+1);		//check out
		}
	| relational_expression T_LE_OP shift_expression
		{
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s <= %s\n",buffer, $1, $3);
			fprintf(fp_quad, "\t<=\t\t%s\t\t%s\t\t%s\n", $1, $3, buffer);

			strncpy($$, buffer, m+1);		//check out
		}
	| relational_expression T_GE_OP shift_expression
		{
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s >= %s\n",buffer, $1, $3);
			fprintf(fp_quad, "\t>=\t\t%s\t\t%s\t\t%s\n", $1, $3, buffer);

			strncpy($$, buffer, m+1);		//check out
		}
	;

equality_expression
	: relational_expression {	strcpy($$, $1); }
	| equality_expression T_EQ_OP relational_expression
		{
			sprintf(buffer,"t %d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s == %s\n", buffer, $1, $3);
			fprintf(fp_quad, "\t==\t\t%s\t\t%s\t\t%s\n", $1, $3, buffer);

			strncpy($$, buffer, m+1);		//check out
		}
	| equality_expression T_NE_OP relational_expression
		{
			sprintf(buffer,"t %d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s != %s\n",buffer, $1, $3);
			fprintf(fp_quad, "\t!=\t\t%s\t\t%s\t\t%s\n", $1, $3, buffer);

			strncpy($$, buffer, m+1);		//check out
		}
	;

/*and_expression
	: equality_expression {	strcpy($$, $1);  }
	| and_expression '&' equality_expression {	strcpy($$, $1);  }
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
*/

conditional_expression
	: equality_expression 	{	strcpy($$, $1);  }
	| equality_expression
		{ 
			fprintf(fp_icg,"ifFalse t%d goto L%d\n", --tempno, ln); 
			fprintf(fp_quad, "\tifFalse\t\tt%d\t\t  \t\tL%d\n", tempno, ln);
			tempno++;		
			ln++;
		} 
	'?' expression 
		{
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s\n", buffer, $4);
			fprintf(fp_quad, "\t=\t\t%s\t\t  \t\t%s\n", $4, buffer);

			fprintf(fp_icg,"goto L%d\n", ln);
			fprintf(fp_quad, "\tgoto\t\t  \t\t  \t\tL%d\n", ln);

			fprintf(fp_icg,"L%d:\n", --ln);
			fprintf(fp_quad, "\tLabel\t\t  \t\t  \t\tL%d\n", ln);
			ln++;
		}
	':' conditional_expression	
		{
			
			fprintf(fp_icg, "%s = %s\n", buffer, $7);
			fprintf(fp_quad, "\t=\t\t%s\t\t  \t\t%s\n", $7, buffer);

			fprintf(fp_icg,"L%d:\n", ln);
			fprintf(fp_quad, "\tLabel\t\t  \t\t  \t\tL%d\n", ln);
			ln++;
		}

	;

assignment_expression
	: unary_expression assignment_operator assignment_expression
	 	{
			switch(assignop){
				case 0: 
						/*
						if(tempno > 0){
							fprintf(fp_icg, "%s = t%d\n", $1, --tempno); 
							fprintf(fp_quad, "\t=\t\tt%d\t\t  \t\t%s\n", tempno, $1);
							tempno++;
						}
						else if(tempno == 0){
							fprintf(fp_icg, "%s = %s\n", $1, $3); 
							fprintf(fp_quad, "\t=\t\t%s\t\t  \t\t%s\n", $3, $1);							
						}
						*/
						if(*$3!='\0')
						{
							fprintf(fp_icg, "%s = %s\n", $1, $3); 
							fprintf(fp_quad, "\t=\t\t%s\t\t  \t\t%s\n", $3, $1);
						}
						else
						{
							fprintf(fp_icg, "%s = t%d\n", $1, --tempno); 
							fprintf(fp_quad, "\t=\t\tt%d\t\t  \t\t%s\n", tempno, $1);
							tempno++;
						}
						break;

				case 1: 
						sprintf(buffer,"t%d",tempno++);
						m = strlen(buffer);
						buffer[m] = '\0';
						fprintf(fp_icg, "%s = %s + %s\n",buffer, $1, $3);
						fprintf(fp_quad, "\t+\t\t%s\t\t%s\t\t%s\n", $1, $3, buffer);

						fprintf(fp_icg, "%s = t%d\n", $1, --tempno); 
						fprintf(fp_quad, "\t=\t\tt%d\t\t  \t\t%s\n", tempno, $1);
						tempno++;
					
						break;
				case 2:
						sprintf(buffer,"t%d",tempno++);
						m = strlen(buffer);
						buffer[m] = '\0';
						fprintf(fp_icg, "%s = %s - %s\n",buffer, $1, $3);
						fprintf(fp_quad, "\t-\t\t%s\t\t%s\t\t%s\n", $1, $3, buffer);

						fprintf(fp_icg, "%s = t%d\n", $1, --tempno); 
						fprintf(fp_quad, "\t=\t\tt%d\t\t  \t\t%s\n", tempno, $1);
						tempno++;

						break;
				case 3:
						sprintf(buffer,"t%d",tempno++);
						m = strlen(buffer);
						buffer[m] = '\0';
						fprintf(fp_icg, "%s = %s * %s\n",buffer, $1, $3);
						fprintf(fp_quad, "\t*\t\t%s\t\t%s\t\t%s\n", $1, $3, buffer);

						fprintf(fp_icg, "%s = t%d\n", $1, --tempno); 
						fprintf(fp_quad, "\t=\t\tt%d\t\t  \t\t%s\n", tempno, $1);
						tempno++;

						break;
				case 4:
						sprintf(buffer,"t%d",tempno++);
						m = strlen(buffer);
						buffer[m] = '\0';
						fprintf(fp_icg, "%s = %s / %s\n",buffer, $1, $3);
						fprintf(fp_quad, "\t/\t\t%s\t\t%s\t\t%s\n", $1, $3, buffer);

						fprintf(fp_icg, "%s = t%d\n", $1, --tempno); 
						fprintf(fp_quad, "\t=\t\tt%d\t\t  \t\t%s\n", tempno, $1);
						tempno++;

						break;
				case 5:
						sprintf(buffer,"t%d",tempno++);
						m = strlen(buffer);
						buffer[m] = '\0';
						fprintf(fp_icg, "%s = %s %c %s\n",buffer, $1, '%',$3);
						fprintf(fp_quad, "\t%c\t\t%s\t\t%s\t\t%s\n", '%', $1, $3, buffer);

						fprintf(fp_icg, "%s = t%d\n", $1, --tempno); 
						fprintf(fp_quad, "\t=\t\tt%d\t\t  \t\t%s\n", tempno, $1);
						tempno++;

						break;
			}
			
			assignop = -1;

			
		}
	| conditional_expression {strcpy($$, $1);}
	;

assignment_operator
	: '='	{ assignop = 0; }
	;

expression
	: expression ',' assignment_expression
	| assignment_expression {	strcpy($$, $1); }
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
	| T_RETURN expression ';'
	| T_RETURN ';'
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

member
	: function_definition 
	| declaration 
	;

class_member
	: class_member member
	| member
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement 
	| declaration_specifiers declarator compound_statement
	| declarator declaration_list compound_statement
	| declarator compound_statement
	;

class_declarartion
	: T_CLASS T_IDENTIFIER '{' T_PRIVATE ':' class_member T_PUBLIC ':' class_member '}' ';' 
	| T_CLASS T_IDENTIFIER '{' T_PRIVATE ':' class_member '}' ';' 
	| T_CLASS T_IDENTIFIER '{' T_PUBLIC ':' class_member '}' ';' 
	| T_CLASS T_IDENTIFIER '{' '}' ';' 
	;

external_declaration
	: function_definition
	| declaration
	| class_declarartion
	| error {yyerrok; yyclearin;}
	;

S
	: S external_declaration
	| external_declaration	
	;

%%

void yyerror(char *s)
{
 	printf("\n%s at line no %d\n", s, yylineno);  
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
