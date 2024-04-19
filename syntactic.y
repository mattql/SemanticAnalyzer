%{
#include <iostream>
#include <cstring>
using namespace std;

extern char * yytext;
char vetorClasses[400];
int isClass = 0;
bool errorOccurred = false; // Variável para indicar se ocorreu um erro

int yylex(void);
int yyparse(void);
void yyerror(const char *);

#define RED     "\x1b[31m"
#define NOCOLOR  "\x1b[0m"
%}

%token SOME ALL VALUE MIN MAX EXACTLY THAT NOT AND OR ONLY
CLASS EQUIVALENTTO INDIVIDUALS SUBCLASSOF DISJOINTCLASSES
IDCLASSE IDPROP SYMBOL INDIVIDNAME DATATYPE CARD

%%

start: class options
	| start class options
	;

class: CLASS IDCLASSE {isClass = 0; strcpy(vetorClasses, yytext);}
	;

options: primitiva {cout << "Classe Primitiva. \n";}
	| definida {cout << "Classe Definida. \n";}
	| axioma {cout << "Classe com axioma de fechamento. \n";}
	| aninhada {cout << "Classe com descrições aninhadas. \n";}
	| enumerada {cout << "Classe Enumerada. \n";}
	| coberta {cout << "Classe Coberta. \n";}
	|
	;

primitiva: subclassof
	| disjointclasses
	| individuals
	| subclassof disjointclasses
	| subclassof individuals
	| subclassof disjointclasses individuals
	;

subclassof: SUBCLASSOF subclassofDescript
	;

subclassofDescript: IDPROP SOME IDCLASSE SYMBOL subclassofDescript
	| IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL subclassofDescript
	| IDCLASSE SYMBOL IDPROP SOME IDCLASSE //
	| IDCLASSE
	| IDPROP SOME IDCLASSE
	| IDPROP SOME DATATYPE
	| IDCLASSE AND SYMBOL IDPROP minmax CARD DATATYPE SYMBOL // employee
	;

disjointclasses: DISJOINTCLASSES disjointclassesDescript
	;

disjointclassesDescript: IDCLASSE
	| disjointclassesDescript SYMBOL IDCLASSE
	;

individuals: INDIVIDUALS individualsDescript
	;

individualsDescript: INDIVIDNAME
	| individualsDescript SYMBOL INDIVIDNAME
	;

definida: equivalenttoD
	| equivalenttoD individuals
	;

equivalenttoD: EQUIVALENTTO equivalenttoDescript
	;

equivalenttoDescript: IDCLASSE AND SYMBOL IDPROP SOME DATATYPE SYMBOL SYMBOL CARD SYMBOL SYMBOL
	| IDCLASSE AND SYMBOL IDPROP SOME IDCLASSE SYMBOL // esse igual
	| IDCLASSE AND SYMBOL IDPROP minmax CARD IDCLASSE SYMBOL
	;

minmax: MIN
	| MAX
	;

axioma: SUBCLASSOF subclassofAxiomaDescript
	| SUBCLASSOF subclassofAxiomaDescript disjointclasses
	| SUBCLASSOF subclassofAxiomaDescript disjointclasses individuals
	;

// 
subclassofAxiomaDescript: IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP ONLY SYMBOL IDCLASSE SYMBOL /* um */
	| IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP ONLY SYMBOL IDCLASSE OR IDCLASSE SYMBOL /* dois */
	| IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP ONLY SYMBOL IDCLASSE OR IDCLASSE OR IDCLASSE SYMBOL /* três */
	| IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP ONLY SYMBOL IDCLASSE OR IDCLASSE OR IDCLASSE OR IDCLASSE SYMBOL /* quatro */
	;

aninhada: equivalenttoA
	| equivalenttoA individuals
	;

equivalenttoA: EQUIVALENTTO IDCLASSE AND SYMBOL IDPROP someOnlyValueOr equivalenttoAnin
	/* | EQUIVALENTTO IDCLASSE AND equivalenttoAninB */
	;

/* equivalenttoAninB: SYMBOL IDPROP someOnlyValueOr IDCLASSE SYMBOL 
	| SYMBOL IDPROP someOnlyValueOr DATATYPE SYMBOL
	; */

equivalenttoAnin: SYMBOL classOrProp someOnlyValueOr IDCLASSE SYMBOL SYMBOL aninhadaAux
	;

aninhadaAux: someOnlyValueOr SYMBOL IDPROP someOnlyValueOr SYMBOL IDPROP someOnlyValueOr INDIVIDNAME SYMBOL SYMBOL aninhadaAux |
	;

someOnlyValueOr: SOME | ONLY | VALUE | OR
	;

classOrProp: IDCLASSE | IDPROP
	;

enumerada: EQUIVALENTTO SYMBOL enumInstances SYMBOL
	;

enumInstances: INDIVIDNAME
	| enumInstances SYMBOL INDIVIDNAME
	;

coberta: EQUIVALENTTO cobertaDescript
	;

cobertaDescript: IDCLASSE
	| cobertaDescript OR IDCLASSE
	;

%%

/* definido pelo analisador léxico */
extern FILE * yyin;

int main(int argc, char ** argv)
{
	/* se foi passado um nome de arquivo */
	if (argc > 1)
	{
		FILE * file;
		file = fopen(argv[1], "r");
		if (!file)
		{
			cout << "Arquivo " << argv[1] << " não encontrado!\n";
			exit(1);
		}
		
		/* entrada ajustada para ler do arquivo */
		yyin = file;
	}

	yyparse();
}

void yyerror(const char * s)
{
	/* variáveis definidas no analisador léxico */
	extern int yylineno;     

	if(isClass == 0){
	/* mensagem de erro exibe o símbolo que causou erro e o número da linha */
	cout << RED <<"-----------------------------------------------------------------\n";
    cout << RED <<"🔴 Erro sintático: símbolo \"" << yytext << "\" (linha " << yylineno << ") |📄 Classe: " << vetorClasses << "|\n";
	cout << RED <<"-----------------------------------------------------------------\n";
	cout << NOCOLOR;
	isClass = 1;
	}

	yyparse();
}