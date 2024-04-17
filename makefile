all: syntAnalyzer

# Compiladores
CPP=g++
FLEX=flex 
BISON=bison

syntAnalyzer: lex.yy.c syntactic.tab.c
	$(CPP) lex.yy.c syntactic.tab.c -std=c++17 -o syntAnalyzer

lex.yy.c: lexer.l
	$(FLEX) lexer.l

syntactic.tab.c: syntactic.y
	$(BISON) -d syntactic.y

clean:
	rm syntAnalyzer lex.yy.c syntactic.tab.c syntactic.tab.h
