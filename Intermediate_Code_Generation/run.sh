yacc -d ICG.y
lex ICG.l
gcc -fno-stack-protector -g y.tab.c lex.yy.c -ll -o ICG
./ICG < test.c