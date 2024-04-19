%{
#include <iostream>
#include <cstring>
using namespace std;

extern int yylineno; 
extern char * yytext;
char vetorClasses[400]; // Vetor para armazenar nomes de Classe
int isClass = 0; // Saber se é ou não é classe
int errosSemanticos = 0; // Total de erros semânticos

int yylex(void);
int yyparse(void);
void yyerror(const char *);

// Constantes de cores para saída do terminal
#define RED      "\x1b[31m"
#define GREEN    "\x1b[32m"
#define BLUE     "\x1b[34m"
#define YELLOW   "\x1b[33m"
#define MAGENTA  "\x1b[35m"
#define CYAN     "\x1b[36m"
#define PURPLE   "\x1b[38;5;141m"
#define NOCOLOR  "\x1b[0m"
%}

// Declaração dos tokens utilizados e vindos do analisador léxico
%token SOME ALL VALUE MIN MAX EXACTLY THAT NOT AND OR ONLY
CLASS EQUIVALENTTO INDIVIDUALS SUBCLASSOF DISJOINTCLASSES
IDCLASSE IDPROP SYMBOL INDIVIDNAME DATATYPE CARD

%%

// Início do analisador
start: class options // Token Class: é obrigatório em todas as Classes
	| start class options
	;

// Definição do que é uma Classe: Token Class: e ID (nome) da classe
class: CLASS IDCLASSE {isClass = 0; strcpy(vetorClasses, yytext);} // Código para exibir nome da classe no método de erro sintático
	;

// Classifica a Classe em um dos 6 tipos
options: primitiva {cout << GREEN   << "1️⃣  Classe Primitiva \n";}
	| definida     {cout << BLUE    << "2️⃣  Classe Definida \n";}
	| axioma       {cout << YELLOW  << "3️⃣  Classe com axioma de fechamento \n";}
	| aninhada     {cout << MAGENTA << "4️⃣  Classe com descrições aninhadas \n";}
	| enumerada    {cout << CYAN    << "5️⃣  Classe Enumerada \n";}
	| coberta      {cout << PURPLE  << "6️⃣  Classe Coberta \n";}
	|
	;

// Define como uma classe primitiva deve ser escrita
primitiva: subclassof 
	| subclassof disjointclasses individuals 
	| disjointclasses 
	| individuals 
	| subclassof disjointclasses
	| subclassof individuals

	;

// Regras que definem como deve ser um SubclassOf (Token + conteúdo do bloco)
subclassof: SUBCLASSOF subclassofDescript
	;

// Definição do que deve ter no conteúdo de um bloco SubclassOf
subclassofDescript: IDPROP SOME IDCLASSE SYMBOL subclassofDescript
	| IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL subclassofDescript
	| IDCLASSE SYMBOL IDPROP SOME IDCLASSE //
	| IDCLASSE
	| IDPROP SOME IDCLASSE
	| IDPROP SOME DATATYPE
	| IDCLASSE AND SYMBOL IDPROP minmax CARD DATATYPE SYMBOL // employee
	;

// Regras que definem como deve ser um DisjointClasses (Token + conteúdo do bloco)
disjointclasses: DISJOINTCLASSES disjointclassesDescript
	;

// Definição do que deve ter no conteúdo de um bloco DisjointClasses
disjointclassesDescript: IDCLASSE
	| disjointclassesDescript SYMBOL IDCLASSE
	;

// Regras que definem como deve ser um Individuals (Token + conteúdo do bloco)
individuals: INDIVIDUALS individualsDescript
	;

// Definição do que deve ter no conteúdo de um bloco Individuals
individualsDescript: INDIVIDNAME
	| individualsDescript SYMBOL INDIVIDNAME
	;

// Define como uma classe definida deve ser escrita
definida: equivalenttoD
	| equivalenttoD individuals
	;

// Regras que definem como deve ser um EquivalentTo (Token + conteúdo do bloco)
// ** para ser usado na classe Definida **
equivalenttoD: EQUIVALENTTO equivalenttoDescript
	;

// Definição do que deve ter no conteúdo de um bloco EquivalentTo
// ** para ser usado na classe Definida **
equivalenttoDescript: IDCLASSE AND SYMBOL IDPROP SOME DATATYPE SYMBOL SYMBOL CARD SYMBOL SYMBOL
	| IDCLASSE AND SYMBOL IDPROP SOME IDCLASSE SYMBOL // esse igual
	| IDCLASSE AND SYMBOL IDPROP minmax CARD IDCLASSE SYMBOL
	;

// Regra auxiliar para escolher entre os tokens MIN ou MAX
minmax: MIN
	| MAX
	;

// Define como uma classe com axioma de fechamento deve ser escrita
axioma: SUBCLASSOF subclassofAxiomaDescript
	| SUBCLASSOF subclassofAxiomaDescript disjointclasses
	| SUBCLASSOF subclassofAxiomaDescript disjointclasses individuals
	;

// Define como deve ser um SubclassOf
// ** para ser usado na classe com axioma de fechamento **
// TODO juntar com o outro subclassOf
subclassofAxiomaDescript: IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP ONLY SYMBOL IDCLASSE SYMBOL /* um */
	| IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP ONLY SYMBOL IDCLASSE OR IDCLASSE SYMBOL /* dois */
	| IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP ONLY SYMBOL IDCLASSE OR IDCLASSE OR IDCLASSE SYMBOL /* três */
	| IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP ONLY SYMBOL IDCLASSE OR IDCLASSE OR IDCLASSE OR IDCLASSE SYMBOL /* quatro */
	;

// Regras que definem como uma classe com descrições aninhadas deve ser escrita
aninhada: equivalenttoA
	| equivalenttoA individuals
	;

// Define como deve ser um EquivalentTo
// ** para ser usado na classe com descrições aninhadas **
// TODO tentar juntar com o outro equivalentto
equivalenttoA: EQUIVALENTTO IDCLASSE AND SYMBOL IDPROP someOnlyValueOr equivalenttoAnin
	/* | EQUIVALENTTO IDCLASSE AND equivalenttoAninB */
	;

/* equivalenttoAninB: SYMBOL IDPROP someOnlyValueOr IDCLASSE SYMBOL 
	| SYMBOL IDPROP someOnlyValueOr DATATYPE SYMBOL
	; */

// As duas regras abaixo são auxiliares para caso tenham vários aninhamentos
equivalenttoAnin: SYMBOL classOrProp someOnlyValueOr IDCLASSE SYMBOL SYMBOL aninhadaAux
	;

aninhadaAux: someOnlyValueOr SYMBOL IDPROP someOnlyValueOr SYMBOL IDPROP someOnlyValueOr INDIVIDNAME SYMBOL SYMBOL aninhadaAux |
	;

// Regra auxiliar para escolher entre os tokens SOME, ONLY VALUE ou OR
someOnlyValueOr: SOME | ONLY | VALUE | OR
	;

// Regra auxiliar para escolher entre os tokens IDCLASSE ou IDPROP
classOrProp: IDCLASSE | IDPROP
	;

// Regras que definem como uma classe Enumerada deve ser escrita
enumerada: EQUIVALENTTO SYMBOL enumInstances SYMBOL
	;

// Dentro do bloco EquivalentTo existe um nome de indivíduo, ou vários separados por vírgula e entre chaves
enumInstances: INDIVIDNAME
	| enumInstances SYMBOL INDIVIDNAME
	;

// Regras que definem como uma classe Coberta deve ser escrita
coberta: EQUIVALENTTO cobertaDescript
	;

// Dentro do bloco EquivalentTo existe um nome de classe, ou vários separados por OR
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