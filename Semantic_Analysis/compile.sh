yacc -d SymbolTable.y
lex -w SymbolTable.l
gcc -g y.tab.c lex.yy.c -ll -o SymbolTable

yacc -d AST.y
lex -w AST.l
gcc -Wall -fno-stack-protector -g -w y.tab.c lex.yy.c graph.c -ll -o AST