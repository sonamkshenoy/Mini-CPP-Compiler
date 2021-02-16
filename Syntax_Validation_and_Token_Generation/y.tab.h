/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_IDENTIFIER = 258,
    T_CONSTANT = 259,
    T_STRING_LITERAL = 260,
    T_PTR_OP = 261,
    T_INC_OP = 262,
    T_DEC_OP = 263,
    T_LE_OP = 264,
    T_GE_OP = 265,
    T_EQ_OP = 266,
    T_NE_OP = 267,
    T_AND_OP = 268,
    T_OR_OP = 269,
    T_CHAR = 270,
    T_INT = 271,
    T_FLOAT = 272,
    T_DOUBLE = 273,
    T_VOID = 274,
    T_CLASS = 275,
    T_PUBLIC = 276,
    T_PRIVATE = 277,
    T_ELLIPSIS = 278,
    T_CASE = 279,
    T_DEFAULT = 280,
    T_IF = 281,
    T_ELSE = 282,
    T_SWITCH = 283,
    T_WHILE = 284,
    T_FOR = 285,
    T_BREAK = 286,
    T_CONTINUE = 287,
    T_RETURN = 288,
    T_IFX = 289
  };
#endif
/* Tokens.  */
#define T_IDENTIFIER 258
#define T_CONSTANT 259
#define T_STRING_LITERAL 260
#define T_PTR_OP 261
#define T_INC_OP 262
#define T_DEC_OP 263
#define T_LE_OP 264
#define T_GE_OP 265
#define T_EQ_OP 266
#define T_NE_OP 267
#define T_AND_OP 268
#define T_OR_OP 269
#define T_CHAR 270
#define T_INT 271
#define T_FLOAT 272
#define T_DOUBLE 273
#define T_VOID 274
#define T_CLASS 275
#define T_PUBLIC 276
#define T_PRIVATE 277
#define T_ELLIPSIS 278
#define T_CASE 279
#define T_DEFAULT 280
#define T_IF 281
#define T_ELSE 282
#define T_SWITCH 283
#define T_WHILE 284
#define T_FOR 285
#define T_BREAK 286
#define T_CONTINUE 287
#define T_RETURN 288
#define T_IFX 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
