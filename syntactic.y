%{
#include <iostream>
#include <cstring>
using namespace std;

extern int yylineno; 
extern char * yytext;
char vetorClasses[400]; // Vetor para armazenar nomes de Classe
int isClass = 0; // Saber se é ou não é classe

// Variáveis para controle
int errosSemanticos = 0; // Total de erros semânticos
int total_primitiva = 0;
int total_definida = 0;
int total_axioma = 0;
int total_aninhada = 0;
int total_enumerada = 0;
int total_coberta = 0;
char codigoErro;
extern string tipoDado;

int yylex(void);
int yyparse(void);
void yyerror(const char *);
void semanticError(char codigoErro, int yylineno, char * vetorClasses);

// Constantes de cores para saída do terminal
#define RED     "\x1b[38;5;196m"
#define GREEN   "\x1b[38;5;46m"
#define BLUE    "\x1b[38;5;12m"
#define YELLOW  "\x1b[38;5;226m"
#define MAGENTA "\x1b[38;5;165m"
#define CYAN    "\x1b[36m"
#define PURPLE  "\x1b[38;5;141m"
#define ORANGE  "\x1b[38;5;214m"
#define WHITE   "\x1b[37m"
#define NOCOLOR "\x1b[0m"
%}

// Declaração dos tokens utilizados e vindos do analisador léxico
%token SOME ALL VALUE MIN MAX EXACTLY THAT NOT AND OR ONLY
CLASS EQUIVALENTTO INDIVIDUALS SUBCLASSOF DISJOINTCLASSES
IDCLASSE IDPROP SYMBOL INDIVIDNAME DATATYPE CARD FLOATS

%%

// Início do analisador
start: class options // Token Class: é obrigatório em todas as Classes
	| start class options
	;

// Definição do que é uma Classe: Token Class: e ID (nome) da classe
class: CLASS IDCLASSE {isClass = 0; strcpy(vetorClasses, yytext);} // Código para exibir nome da classe no método de erro sintático
	;

// Classifica a Classe em um dos 6 tipos
options: primitiva
	| definida
	| axioma
	| aninhada
	| enumerada
	| coberta
	|
	;

// Define como uma classe primitiva deve ser escrita
primitiva: subclassof {cout << GREEN << "1️⃣  Classe Primitiva ⭢ " << vetorClasses << "\n"; total_primitiva++;}
	| subclassof disjointclasses individuals {cout << GREEN << "1️⃣  Classe Primitiva ⭢ " << vetorClasses << "\n"; total_primitiva++;}
	// Regras abaixo são semanticamente erradas
	| disjointclasses {semanticError('C', yylineno, vetorClasses); errosSemanticos++;}
	| individuals {semanticError('D', yylineno, vetorClasses); errosSemanticos++;}
	| subclassof disjointclasses {semanticError('A', yylineno, vetorClasses); errosSemanticos++;}
	| subclassof individuals {semanticError('B', yylineno, vetorClasses); errosSemanticos++;}
	;

// Regras que definem como deve ser um SubclassOf (Token + conteúdo do bloco)
subclassof: SUBCLASSOF subclassofDescript
	;

// Definição do que deve ter no conteúdo de um bloco SubclassOf
subclassofDescript: IDPROP SOME IDCLASSE SYMBOL subclassofDescript
	| IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL subclassofDescript
	| IDCLASSE SYMBOL IDPROP SOME IDCLASSE
	| IDCLASSE
	| IDPROP SOME IDCLASSE
	| IDPROP SOME DATATYPE
	| IDCLASSE AND SYMBOL IDPROP minmaxexactly CARD DATATYPE SYMBOL // Coerção: Deve haver um número (CARD) após MIN, MAX ou EXACTLY e antes de tipo de dado
	// Regra abaixo é semanticamente errada
	| IDCLASSE AND SYMBOL IDPROP minmaxexactly DATATYPE SYMBOL {semanticError('G', yylineno, vetorClasses); errosSemanticos++;}
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
definida: equivalenttoD {cout << BLUE << "2️⃣  Classe Definida ⭢ " << vetorClasses << "\n"; total_definida++;}
	| equivalenttoD disjointclasses individuals {cout << BLUE << "2️⃣  Classe Definida ⭢ " << vetorClasses << "\n"; total_definida++;}
	// Regras abaixo são semanticamente erradas
	| equivalenttoD disjointclasses {semanticError('A', yylineno, vetorClasses); errosSemanticos++;}
	| equivalenttoD individuals {semanticError('B', yylineno, vetorClasses); errosSemanticos++;}
	| subclassof equivalenttoD {semanticError('E', yylineno, vetorClasses); errosSemanticos++;}
	;

// Regras que definem como deve ser um EquivalentTo (Token + conteúdo do bloco)
// ** para ser usado na classe Definida **
equivalenttoD: EQUIVALENTTO equivalenttoDescript
	;

// Definição do que deve ter no conteúdo de um bloco EquivalentTo
// ** para ser usado na classe Definida **
equivalenttoDescript: IDCLASSE AND SYMBOL IDPROP SOME DATATYPE SYMBOL SYMBOL CARD SYMBOL SYMBOL // Coerção: Se o tipo de dado é integer tem que vir um CARD (inteiro) e não um FLOATS
	| IDCLASSE AND SYMBOL IDPROP SOME IDCLASSE SYMBOL
	| IDCLASSE AND SYMBOL IDPROP minmaxexactly CARD IDCLASSE SYMBOL // Coerção: Deve haver um número (CARD) após MIN, MAX ou EXACTLY e antes de nome de classe
	// Regra abaixo é semanticamente errada
	| IDCLASSE AND SYMBOL IDPROP SOME DATATYPE SYMBOL SYMBOL FLOATS SYMBOL SYMBOL {cout << ORANGE << "Tipo de dado encontrado: '" << tipoDado << "' na classe: " << vetorClasses << " \n" << NOCOLOR; semanticError('F', yylineno, vetorClasses); errosSemanticos++;}
	| IDCLASSE AND SYMBOL IDPROP minmaxexactly IDCLASSE SYMBOL {semanticError('G', yylineno, vetorClasses); errosSemanticos++;}
	;

// Regra auxiliar para escolher entre os tokens MIN, MAX ou EXACTLY
minmaxexactly: MIN | MAX | EXACTLY
	;

// Define como uma classe com axioma de fechamento deve ser escrita
axioma: SUBCLASSOF subclassofAxiomaDescript {cout << YELLOW << "3️⃣ 1️⃣  Classe com axioma de fechamento e Primitiva ⭢ " << vetorClasses << "\n"; total_axioma++;}
	| SUBCLASSOF subclassofAxiomaDescript disjointclasses individuals {cout << YELLOW << "3️⃣ 1️⃣  Classe com axioma de fechamento e Primitiva ⭢ " << vetorClasses << "\n"; total_axioma++;}
	// Regras abaixo são semanticamente erradas
	| SUBCLASSOF subclassofAxiomaDescript disjointclasses {semanticError('A', yylineno, vetorClasses); errosSemanticos++;}
	| SUBCLASSOF subclassofAxiomaDescript individuals {semanticError('B', yylineno, vetorClasses); errosSemanticos++;}
	;

// Define como deve ser um SubclassOf
// ** para ser usado na classe com axioma de fechamento **
// TODO juntar com o outro subclassOf
subclassofAxiomaDescript: IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP ONLY SYMBOL IDCLASSE SYMBOL /* um */
	| IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP ONLY SYMBOL IDCLASSE OR IDCLASSE SYMBOL /* dois */
	| IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP ONLY SYMBOL IDCLASSE OR IDCLASSE OR IDCLASSE SYMBOL /* três */
	| IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP ONLY SYMBOL IDCLASSE OR IDCLASSE OR IDCLASSE OR IDCLASSE SYMBOL /* quatro */
	// Regras semanticamente erradas para declaração do axioma de fechamento ANTES da declaração das triplas
	//| IDCLASSE SYMBOL IDPROP ONLY SYMBOL IDCLASSE SYMBOL SYMBOL IDPROP SOME IDCLASSE  /* um */ {cout << RED << "🔴 Erro semântico (linha: " << yylineno << ") | Classe: " << vetorClasses <<  " | Axioma de fechamento declarado ANTES das triplas existenciais \n❗ É esperado a declaraçao do axioma de fechamento DEPOIS da declaração das triplas existenciais ❗\n"; errosSemanticos++;}
	//| IDCLASSE SYMBOL IDPROP ONLY SYMBOL IDCLASSE OR IDCLASSE SYMBOL SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP SOME IDCLASSE /* dois */ {cout << RED << "🔴 Erro semântico (linha: " << yylineno << ") | Classe: " << vetorClasses <<  " | Axioma de fechamento declarado ANTES das triplas existenciais \n❗ É esperado a declaraçao do axioma de fechamento DEPOIS da declaração das triplas existenciais ❗\n"; errosSemanticos++;}
	//| IDCLASSE SYMBOL IDPROP ONLY SYMBOL IDCLASSE OR IDCLASSE OR IDCLASSE SYMBOL SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP SOME IDCLASSE /* três */ {cout << RED << "🔴 Erro semântico (linha: " << yylineno << ") | Classe: " << vetorClasses <<  " | Axioma de fechamento declarado ANTES das triplas existenciais \n❗ É esperado a declaraçao do axioma de fechamento DEPOIS da declaração das triplas existenciais ❗\n"; errosSemanticos++;}
	//| IDCLASSE SYMBOL IDPROP ONLY SYMBOL IDCLASSE OR IDCLASSE OR IDCLASSE OR IDCLASSE SYMBOL SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP SOME IDCLASSE SYMBOL IDPROP SOME IDCLASSE /* quatro */ {cout << RED << "🔴 Erro semântico (linha: " << yylineno << ") | Classe: " << vetorClasses <<  " | Axioma de fechamento declarado ANTES das triplas existenciais \n❗ É esperado a declaraçao do axioma de fechamento DEPOIS da declaração das triplas existenciais ❗\n"; errosSemanticos++;}
	;

// Regras que definem como uma classe com descrições aninhadas deve ser escrita
aninhada: equivalenttoA {cout << MAGENTA << "4️⃣ 2️⃣  Classe com descrições aninhadas e Definida ⭢ " << vetorClasses << "\n"; total_aninhada++;}
	| equivalenttoA disjointclasses individuals {cout << MAGENTA << "4️⃣ 2️⃣  Classe com descrições aninhadas e Definida ⭢ " << vetorClasses << "\n"; total_aninhada++;}
	// Regras abaixo são semanticamente erradas
	| equivalenttoA disjointclasses {semanticError('A', yylineno, vetorClasses); errosSemanticos++;}
	| equivalenttoA individuals {semanticError('B', yylineno, vetorClasses); errosSemanticos++;}
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
enumerada: EQUIVALENTTO SYMBOL enumInstances SYMBOL {cout << CYAN << "5️⃣ 2️⃣  Classe Enumerada e Definida ⭢ " << vetorClasses << "\n"; total_enumerada++;}
	| EQUIVALENTTO SYMBOL enumInstances SYMBOL subclassof {cout << CYAN << "5️⃣ 2️⃣  Classe Enumerada e Definida ⭢ " << vetorClasses << "\n"; total_enumerada++;}
	| EQUIVALENTTO SYMBOL enumInstances SYMBOL subclassof disjointclasses individuals {cout << CYAN << "5️⃣ 2️⃣  Classe Enumerada e Definida ⭢ " << vetorClasses << "\n"; total_enumerada++;}
	| EQUIVALENTTO SYMBOL enumInstances SYMBOL disjointclasses individuals {cout << CYAN << "5️⃣ 2️⃣  Classe Enumerada e Definida ⭢ " << vetorClasses << "\n"; total_enumerada++;}
	// Regras abaixo são semanticamente erradas
	| EQUIVALENTTO SYMBOL enumInstances SYMBOL disjointclasses {semanticError('A', yylineno, vetorClasses); errosSemanticos++;}
	| EQUIVALENTTO SYMBOL enumInstances SYMBOL individuals {semanticError('B', yylineno, vetorClasses); errosSemanticos++;}
	;

// Dentro do bloco EquivalentTo existe um nome de indivíduo, ou vários separados por vírgula e entre chaves
enumInstances: INDIVIDNAME
	| enumInstances SYMBOL INDIVIDNAME
	;

// Regras que definem como uma classe Coberta deve ser escrita
coberta: EQUIVALENTTO cobertaDescript {cout << PURPLE  << "6️⃣  2️⃣  Classe Coberta e Definida ⭢ " << vetorClasses << "\n"; total_coberta++;}
	| EQUIVALENTTO cobertaDescript subclassof {cout << PURPLE  << "6️⃣  2️⃣  Classe Coberta e Definida ⭢ " << vetorClasses << "\n"; total_coberta++;}
	| EQUIVALENTTO cobertaDescript subclassof disjointclasses individuals {cout << PURPLE  << "6️⃣  2️⃣  Classe Coberta e Definida ⭢ " << vetorClasses << "\n"; total_coberta++;}
	| EQUIVALENTTO cobertaDescript disjointclasses individuals {cout << PURPLE  << "6️⃣  2️⃣  Classe Coberta e Definida ⭢ " << vetorClasses << "\n"; total_coberta++;}
	// Regras abaixo são semanticamente erradas
	| EQUIVALENTTO cobertaDescript disjointclasses {semanticError('A', yylineno, vetorClasses); errosSemanticos++;}
	| EQUIVALENTTO cobertaDescript individuals {semanticError('B', yylineno, vetorClasses); errosSemanticos++;}
	;

// Dentro do bloco EquivalentTo existe um nome de classe, ou vários separados por OR
cobertaDescript: IDCLASSE
	| cobertaDescript OR IDCLASSE
	;

%%

// Método que exibe os erros semânticos de acordo com o código
void semanticError(char codigoErro, int yylineno, char * vetorClasses){

	switch (codigoErro){
		// Códigos de A a E são relacionados a Análise da Precedência dos Operadores
		case 'A': // Código A: DisjointClasses sem Individuals depois
			cout << RED << "🔴 Erro semântico (linha: " << yylineno << ") | Classe: " << vetorClasses <<  
			" | DisjointClasses deve preceder Individuals \n❗ É esperado Individuals depois ❗\n";
			break;
		case 'B': // Código B: Individuals sem DisjointClasses antes
			cout << RED << "🔴 Erro semântico (linha: " << yylineno << ") | Classe: " << vetorClasses <<  
			" | Individuals deve suceder DisjointClasses\n❗ É esperado DisjointClasses antes ❗\n";
			break;
		case 'C': // Código C: DisjointClasses sozinho na classe
			cout << RED << "🔴 Erro semântico (linha: " << yylineno << ") | Classe: " << vetorClasses <<  
			" | DisjointClasses não pode existir sozinha \n❗ É esperado SubclassOf ou EquivalentTo antes e Individuals depois ❗\n";
			break;
		case 'D': // Código D: Individuals sozinho na classe
			cout << RED << "🔴 Erro semântico (linha: " << yylineno << ") | Classe: " << vetorClasses <<  
			" | Individuals não pode existir sozinho \n❗ É esperado DisjointClasses antes ❗\n";
			break;
		case 'E': // Código E: EquivalentTo depois de SubclassOf
			cout << RED << "🔴 Erro semântico (linha: " << yylineno << ") | Classe: " << vetorClasses <<  
			" | EquivalentTo não deve suceder SubclassOf\n❗ EquivalentTo deve vir ANTES de SubclassOf ❗\n";
			break;
		// Códigos F e G são relacionados a Verificação Estática de Tipos por Coerção
		case 'F': // Código F: depois de um xsd:integer não veio um número inteiro
			cout << RED << "🔴 Erro semântico (linha: " << yylineno << ") | Classe: " << vetorClasses <<  
			" | Número é ponto flutuante\n❗ É esperado um número inteiro ❗\n";
			break;
		case 'G': // Código G: Não tem número entre MIN, MAX, ou EXACTLY e o nome de classe ou tipo de dado
			cout << RED << "🔴 Erro semântico (linha: " << yylineno << ") | Classe: " << vetorClasses <<  
			" | Entre o operador (min, max ou exactly) e o nome de classe ou tipo de dado *deve haver um número* \n❗ É esperado um número ❗\n";
			break;
		// Códigos H e X são relacionados a Verificação Estática de Tipos por Sobrecarregamento
		case 'H':
			
			break;
	}
}

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

	// Tabela com o total de cada tipo de classe e erros semânticos
	cout << "\n";
	cout << WHITE << "----------------------------------------------\n";
	cout << "Total de classes Primitivas: " << total_primitiva << "\n";
	cout << "----------------------------------------------\n";
	cout << "Total de classes Definidas: " << total_definida << "\n";
	cout << "----------------------------------------------\n";
	cout << "Total de classes com Axioma de Fechamento: " << total_axioma << "\n";
	cout << "----------------------------------------------\n";
	cout << "Total de classes com Descrições Aninhadas: " << total_aninhada << "\n";
	cout << "----------------------------------------------\n";
	cout << "Total de classes Enumeradas: " << total_enumerada<< "\n";
	cout << "----------------------------------------------\n";
	cout << "Total de classes Cobertas: " << total_coberta << "\n";
	cout << "----------------------------------------------\n";
	cout << "\n";
	cout << ORANGE << "------------------------------------\n";
	cout << "Total de erros Semânticos: " << errosSemanticos << "\n";
	cout << "------------------------------------\n";
	cout << NOCOLOR;
	cout << "\n";
}

void yyerror(const char * s)
{  
	if(isClass == 0){
	/* mensagem de erro exibe o símbolo que causou erro e o número da linha */
	cout << RED <<"-----------------------------------------------------------------\n";
    cout << RED <<"🔴 Erro sintático: símbolo \"" << yytext << "\" (linha " << yylineno << ") | Classe: " << vetorClasses << "|\n";
	cout << RED <<"-----------------------------------------------------------------\n";
	cout << NOCOLOR;
	isClass = 1;
	}

	yyparse();
}