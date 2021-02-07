#!/bin/bash

yacc -d parser.y
lex patterns.l
gcc lex.yy.c y.tab.c
./a.out
