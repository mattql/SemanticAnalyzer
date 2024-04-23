%{
#include <iostream>
#include <cstring>
using namespace std;

extern int yylineno; 
extern char * yytext;

char vetorClasses[400]; // Vetor para armazenar nomes de Classe
int isClass = 0; // Saber se é ou não é classe
char codigoErro; // Controle do método de exibição de erro semântico
int errosSemanticos = 0; // Total de erros semânticos
// Total de cada tipo de classe (6 variaveis abaixo)
int total_primitiva = 0; 
int total_definida = 0;
int total_axioma = 0;
int total_aninhada = 0;
int total_enumerada = 0;
int total_coberta = 0;
// Total de data property e object property
int total_dataProperty = 0;
int total_objectProperty = 0;

extern string tipoDado; // Exibe o token datatype
extern string tipoPropriedade; // Exibe o token propriedade

int yylex(void);
int yyparse(void);
void yyerror(const char *);
void semanticError(char codigoErro, int yylineno, char * vetorClasses);
void propriedades(char propriedade, char * vetorClasses);

// Constantes de cores para saída do terminal
#define RED      "\x1b[38;5;196m"
#define GREEN    "\x1b[38;5;46m"
#define GREEN2   "\x1b[32m"
#define BLUE     "\x1b[38;5;12m"
#define YELLOW   "\x1b[38;5;226m"
#define MAGENTA  "\x1b[38;5;165m"
#define MAGENTA2 "\x1b[35m"
#define CYAN     "\x1b[36m"
#define PURPLE   "\x1b[38;5;141m"
#define ORANGE   "\x1b[38;5;214m"
#define WHITE    "\x1b[37m"
#define NOCOLOR  "\x1b[0m"
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
primitiva: subclassof {cout << GREEN << "\n1️⃣  Classe Primitiva ⭢ " << vetorClasses << "\n"; total_primitiva++;} // Ao achar uma classe válida, exibe na tela e incrementa total de classes daquele tipo, todas as classes seguem esse padrão
	| subclassof disjointclasses individuals {cout << GREEN << "\n1️⃣  Classe Primitiva ⭢ " << vetorClasses << "\n"; total_primitiva++;}
	// Regras abaixo são semanticamente erradas
	// Chamada do método semanticError: É passado o código do erro semântico correspondente, linha e classe do erro, e incrementa total de erros, todas as chamadas desse método seguem esse padrão (explicação dos códigos dentro do método)
	| disjointclasses {semanticError('C', yylineno, vetorClasses); errosSemanticos++;}
	| individuals {semanticError('D', yylineno, vetorClasses); errosSemanticos++;}
	| subclassof disjointclasses {semanticError('A', yylineno, vetorClasses); errosSemanticos++;}
	| subclassof individuals {semanticError('B', yylineno, vetorClasses); errosSemanticos++;}
	;

// Regras que definem como deve ser um SubclassOf (Token + conteúdo do bloco)
subclassof: SUBCLASSOF subclassofDescript
	;

// Definição do que deve ter no conteúdo de um bloco SubclassOf
subclassofDescript: objectProperty SYMBOL subclassofDescript
	| IDCLASSE SYMBOL objectProperty SYMBOL subclassofDescript 
	| IDCLASSE SYMBOL objectProperty
	| IDCLASSE
	| objectProperty
	| IDPROP SOME DATATYPE {propriedades('D', vetorClasses); total_dataProperty++;} // Chamada do método propriedades: é passado o código (tipo) da propriedade e a classe dela, todas as chamadas desse método seguem esse padrão (explicação dos códigos dentro do método)
	// Coerção: Deve haver um número (CARD) após MIN, MAX ou EXACTLY e antes de tipo de dado
	| IDCLASSE AND SYMBOL IDPROP minmaxexactly CARD DATATYPE SYMBOL {propriedades('D', vetorClasses); total_dataProperty++;}
	// Regra abaixo é semanticamente errada
	| IDCLASSE AND SYMBOL IDPROP minmaxexactly DATATYPE SYMBOL {semanticError('G', yylineno, vetorClasses); propriedades('D', vetorClasses); total_dataProperty++; errosSemanticos++;}
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
definida: equivalenttoD {cout << BLUE << "\n2️⃣  Classe Definida ⭢ " << vetorClasses << "\n"; total_definida++;}
	| equivalenttoD disjointclasses individuals {cout << BLUE << "\n2️⃣  Classe Definida ⭢ " << vetorClasses << "\n"; total_definida++;}
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
equivalenttoDescript: 
	// Coerção: Se o tipo de dado é integer tem que vir um CARD (inteiro) e não um FLOATS (float)
	IDCLASSE AND SYMBOL IDPROP SOME DATATYPE SYMBOL SYMBOL CARD SYMBOL SYMBOL {propriedades('D', vetorClasses); total_dataProperty++;}
	| IDCLASSE AND SYMBOL objectProperty SYMBOL
	// Coerção: Deve haver um número (CARD) após MIN, MAX ou EXACTLY e antes de nome de classe
	| IDCLASSE AND SYMBOL IDPROP minmaxexactly CARD IDCLASSE SYMBOL {propriedades('O', vetorClasses); total_objectProperty++;}
	// Regras abaixo são semanticamente erradas
	| IDCLASSE AND SYMBOL IDPROP SOME DATATYPE SYMBOL SYMBOL FLOATS SYMBOL SYMBOL {cout << ORANGE << "\nTipo de dado encontrado: '" << tipoDado << "' na classe: " << vetorClasses << NOCOLOR; semanticError('F', yylineno, vetorClasses); propriedades('D', vetorClasses); total_dataProperty++; errosSemanticos++;}
	| IDCLASSE AND SYMBOL IDPROP minmaxexactly IDCLASSE SYMBOL {semanticError('G', yylineno, vetorClasses); propriedades('O', vetorClasses); total_objectProperty++; errosSemanticos++;}
	;

// Regra auxiliar para escolher entre os tokens MIN, MAX ou EXACTLY
minmaxexactly: MIN | MAX | EXACTLY
	;

// Define como uma classe com axioma de fechamento deve ser escrita
axioma: SUBCLASSOF subclassofAxiomaDescript {cout << YELLOW << "\n3️⃣ 1️⃣  Classe com axioma de fechamento e Primitiva ⭢ " << vetorClasses << "\n"; total_axioma++;} // Classes que forem Primitivas ou Definidas além da classificação específica, exibe os dois resultados na tela
	| SUBCLASSOF subclassofAxiomaDescript disjointclasses individuals {cout << YELLOW << "\n3️⃣ 1️⃣  Classe com axioma de fechamento e Primitiva ⭢ " << vetorClasses << "\n"; total_axioma++;}
	// Regras abaixo são semanticamente erradas
	| SUBCLASSOF subclassofAxiomaDescript disjointclasses {semanticError('A', yylineno, vetorClasses); errosSemanticos++;}
	| SUBCLASSOF subclassofAxiomaDescript individuals {semanticError('B', yylineno, vetorClasses); errosSemanticos++;}
	;

// Define como deve ser um SubclassOf
// ** para ser usado na classe com axioma de fechamento **
subclassofAxiomaDescript: IDCLASSE SYMBOL objectProperty SYMBOL IDPROP ONLY SYMBOL IDCLASSE SYMBOL {propriedades('O', vetorClasses); total_objectProperty++;} /* um */
	| IDCLASSE SYMBOL objectProperty SYMBOL objectProperty SYMBOL IDPROP ONLY SYMBOL IDCLASSE OR IDCLASSE SYMBOL {propriedades('O', vetorClasses); total_objectProperty++;} /* dois */
	| IDCLASSE SYMBOL objectProperty SYMBOL objectProperty SYMBOL objectProperty SYMBOL IDPROP ONLY SYMBOL IDCLASSE OR IDCLASSE OR IDCLASSE SYMBOL {propriedades('O', vetorClasses); total_objectProperty++;} /* três */
	| IDCLASSE SYMBOL objectProperty SYMBOL objectProperty SYMBOL objectProperty SYMBOL objectProperty SYMBOL IDPROP ONLY SYMBOL IDCLASSE OR IDCLASSE OR IDCLASSE OR IDCLASSE SYMBOL {propriedades('O', vetorClasses); total_objectProperty++;} /* quatro */
	// Regras semanticamente erradas para declaração do axioma de fechamento ANTES da declaração das triplas
	//| IDCLASSE SYMBOL IDPROP ONLY SYMBOL IDCLASSE SYMBOL SYMBOL objectProperty  /* um */ {cout << RED << "🔴 Erro semântico (linha: " << yylineno << ") | Classe: " << vetorClasses <<  " | Axioma de fechamento declarado ANTES das triplas existenciais \n❗ É esperado a declaraçao do axioma de fechamento DEPOIS da declaração das triplas existenciais ❗\n"; errosSemanticos++;}
	//| IDCLASSE SYMBOL IDPROP ONLY SYMBOL IDCLASSE OR IDCLASSE SYMBOL SYMBOL objectProperty SYMBOL objectProperty /* dois */ {cout << RED << "🔴 Erro semântico (linha: " << yylineno << ") | Classe: " << vetorClasses <<  " | Axioma de fechamento declarado ANTES das triplas existenciais \n❗ É esperado a declaraçao do axioma de fechamento DEPOIS da declaração das triplas existenciais ❗\n"; errosSemanticos++;}
	//| IDCLASSE SYMBOL IDPROP ONLY SYMBOL IDCLASSE OR IDCLASSE OR IDCLASSE SYMBOL SYMBOL objectProperty SYMBOL objectProperty SYMBOL objectProperty /* três */ {cout << RED << "🔴 Erro semântico (linha: " << yylineno << ") | Classe: " << vetorClasses <<  " | Axioma de fechamento declarado ANTES das triplas existenciais \n❗ É esperado a declaraçao do axioma de fechamento DEPOIS da declaração das triplas existenciais ❗\n"; errosSemanticos++;}
	//| IDCLASSE SYMBOL IDPROP ONLY SYMBOL IDCLASSE OR IDCLASSE OR IDCLASSE OR IDCLASSE SYMBOL SYMBOL objectProperty SYMBOL objectProperty SYMBOL objectProperty SYMBOL objectProperty /* quatro */ {cout << RED << "🔴 Erro semântico (linha: " << yylineno << ") | Classe: " << vetorClasses <<  " | Axioma de fechamento declarado ANTES das triplas existenciais \n❗ É esperado a declaraçao do axioma de fechamento DEPOIS da declaração das triplas existenciais ❗\n"; errosSemanticos++;}
	;

// Define quando uma propriedade é object property
objectProperty: IDPROP SOME IDCLASSE {propriedades('O', vetorClasses); total_objectProperty++;}
	;

// Regras que definem como uma classe com descrições aninhadas deve ser escrita
aninhada: equivalenttoA {cout << MAGENTA << "\n4️⃣ 2️⃣  Classe com descrições aninhadas e Definida ⭢ " << vetorClasses << "\n"; total_aninhada++;}
	| equivalenttoA disjointclasses individuals {cout << MAGENTA << "\n4️⃣ 2️⃣  Classe com descrições aninhadas e Definida ⭢ " << vetorClasses << "\n"; total_aninhada++;}
	// Regras abaixo são semanticamente erradas
	| equivalenttoA disjointclasses {semanticError('A', yylineno, vetorClasses); errosSemanticos++;}
	| equivalenttoA individuals {semanticError('B', yylineno, vetorClasses); errosSemanticos++;}
	;

// Define como deve ser um EquivalentTo
// ** para ser usado na classe com descrições aninhadas **
equivalenttoA: EQUIVALENTTO IDCLASSE AND SYMBOL IDPROP someOnlyValueOr equivalenttoAnin {propriedades('O', vetorClasses); total_objectProperty++;}
	;

// As duas regras abaixo são auxiliares para caso tenham vários aninhamentos
equivalenttoAnin: SYMBOL classOrProp someOnlyValueOr IDCLASSE SYMBOL SYMBOL aninhadaAux
	;

aninhadaAux: someOnlyValueOr SYMBOL IDPROP someOnlyValueOr SYMBOL IDPROP someOnlyValueOr INDIVIDNAME SYMBOL SYMBOL aninhadaAux {propriedades('O', vetorClasses); total_objectProperty++; total_objectProperty++;} // Incrementa duas vezes pois tem duas propriedades
	|
	;

// Regra auxiliar para escolher entre os tokens SOME, ONLY VALUE ou OR
someOnlyValueOr: SOME | ONLY | VALUE | OR
	;

// Regra auxiliar para escolher entre os tokens IDCLASSE ou IDPROP
classOrProp: IDCLASSE
	| IDPROP {propriedades('O', vetorClasses); total_objectProperty++;} // Essa propriedade está ligada a uma classe na regra equivalenttoAnin
	;

// Regras que definem como uma classe Enumerada deve ser escrita
enumerada: EQUIVALENTTO SYMBOL enumInstances SYMBOL {cout << CYAN << "\n5️⃣ 2️⃣  Classe Enumerada e Definida ⭢ " << vetorClasses << "\n"; total_enumerada++;}
	| EQUIVALENTTO SYMBOL enumInstances SYMBOL subclassof {cout << CYAN << "\n5️⃣ 2️⃣  Classe Enumerada e Definida ⭢ " << vetorClasses << "\n"; total_enumerada++;}
	| EQUIVALENTTO SYMBOL enumInstances SYMBOL subclassof disjointclasses individuals {cout << CYAN << "\n5️⃣ 2️⃣  Classe Enumerada e Definida ⭢ " << vetorClasses << "\n"; total_enumerada++;}
	| EQUIVALENTTO SYMBOL enumInstances SYMBOL disjointclasses individuals {cout << CYAN << "\n5️⃣ 2️⃣  Classe Enumerada e Definida ⭢ " << vetorClasses << "\n"; total_enumerada++;}
	// Regras abaixo são semanticamente erradas
	| EQUIVALENTTO SYMBOL enumInstances SYMBOL disjointclasses {semanticError('A', yylineno, vetorClasses); errosSemanticos++;}
	| EQUIVALENTTO SYMBOL enumInstances SYMBOL individuals {semanticError('B', yylineno, vetorClasses); errosSemanticos++;}
	;

// Dentro do bloco EquivalentTo existe um nome de indivíduo, ou vários separados por vírgula e entre chaves
enumInstances: INDIVIDNAME
	| enumInstances SYMBOL INDIVIDNAME
	;

// Regras que definem como uma classe Coberta deve ser escrita
coberta: EQUIVALENTTO cobertaDescript {cout << PURPLE  << "\n6️⃣ 2️⃣  Classe Coberta e Definida ⭢ " << vetorClasses << "\n"; total_coberta++;}
	| EQUIVALENTTO cobertaDescript subclassof {cout << PURPLE  << "\n6️⃣ 2️⃣  Classe Coberta e Definida ⭢ " << vetorClasses << "\n"; total_coberta++;}
	| EQUIVALENTTO cobertaDescript subclassof disjointclasses individuals {cout << PURPLE  << "\n6️⃣ 2️⃣  Classe Coberta e Definida ⭢ " << vetorClasses << "\n"; total_coberta++;}
	| EQUIVALENTTO cobertaDescript disjointclasses individuals {cout << PURPLE  << "\n6️⃣ 2️⃣  Classe Coberta e Definida ⭢ " << vetorClasses << "\n"; total_coberta++;}
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
			cout << RED << "\n🔴 Erro semântico (linha: " << yylineno << ") | Classe: " << vetorClasses <<  
			" | DisjointClasses deve preceder Individuals \n❗ É esperado Individuals depois ❗\n";
			break;
		case 'B': // Código B: Individuals sem DisjointClasses antes
			cout << RED << "\n🔴 Erro semântico (linha: " << yylineno << ") | Classe: " << vetorClasses <<  
			" | Individuals deve suceder DisjointClasses\n❗ É esperado DisjointClasses antes ❗\n";
			break;
		case 'C': // Código C: DisjointClasses sozinho na classe
			cout << RED << "\n🔴 Erro semântico (linha: " << yylineno << ") | Classe: " << vetorClasses <<  
			" | DisjointClasses não pode existir sozinha \n❗ É esperado SubclassOf ou EquivalentTo antes e Individuals depois ❗\n";
			break;
		case 'D': // Código D: Individuals sozinho na classe
			cout << RED << "\n🔴 Erro semântico (linha: " << yylineno << ") | Classe: " << vetorClasses <<  
			" | Individuals não pode existir sozinho \n❗ É esperado DisjointClasses antes ❗\n";
			break;
		case 'E': // Código E: EquivalentTo depois de SubclassOf
			cout << RED << "\n🔴 Erro semântico (linha: " << yylineno << ") | Classe: " << vetorClasses <<  
			" | EquivalentTo não deve suceder SubclassOf\n❗ EquivalentTo deve vir ANTES de SubclassOf ❗\n";
			break;
		// Códigos F e G são relacionados a Verificação Estática de Tipos por Coerção
		case 'F': // Código F: depois de um xsd:integer não veio um número inteiro
			cout << RED << "\n🔴 Erro semântico (linha: " << yylineno << ") | Classe: " << vetorClasses <<  
			" | Número é ponto flutuante\n❗ É esperado um número inteiro ❗\n";
			break;
		case 'G': // Código G: Não tem número entre MIN, MAX, ou EXACTLY e o nome de classe ou tipo de dado
			cout << RED << "\n🔴 Erro semântico (linha: " << yylineno << ") | Classe: " << vetorClasses <<  
			" | Entre o operador (min, max ou exactly) e o nome de classe ou tipo de dado *deve haver um número* \n❗ É esperado um número ❗\n";
			break;
	}
}

// Método para exibir as propriedades para a Verificação Estática de Tipos por Sobrecarregamento
void propriedades(char propriedade, char * vetorClasses){

	if(propriedade == 'D'){ // Código D: A propriedade é Data Property
		cout << WHITE << "\n❕ Propriedade encontrada: '" << tipoPropriedade << "' | Tipo: Data Property | Classe: " << vetorClasses << " ❕" << NOCOLOR << "\n";
	} else if(propriedade == 'O'){ // Código O: A propriedade é Object Property
		cout << WHITE << "\n❕ Propriedade encontrada: '" << tipoPropriedade << "' Tipo: Object Property | Classe: " << vetorClasses << " ❕" << NOCOLOR << "\n";
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

	// Tabela de resultados com o total de cada tipo de classe, propriedades e erros semânticos
	cout << "\n";
	cout << GREEN2 << "------------------------------------\n";
	cout << "        |RESULTADOS GERAIS|            \n";
	cout << "------------------------------------\n";
	cout << "\n-----------------------------------------------------------\n";
	cout << "** Total ⭢ | Classes - Propriedades - Erros semânticos | **\n";
	cout << "-----------------------------------------------------------\n";
	cout << "\n------------------------------------\n";
	cout << "Classes Primitivas: " << total_primitiva << "\n";
	cout << "------------------------------------\n";
	cout << "Classes Definidas: " << total_definida << "\n";
	cout << "------------------------------------\n";
	cout << "Classes com Axioma de Fechamento: " << total_axioma << "\n";
	cout << "------------------------------------\n";
	cout << "Classes com Descrições Aninhadas: " << total_aninhada << "\n";
	cout << "------------------------------------\n";
	cout << "Classes Enumeradas: " << total_enumerada<< "\n";
	cout << "------------------------------------\n";
	cout << "Classes Cobertas: " << total_coberta << "\n";
	cout << "------------------------------------\n";
	cout << NOCOLOR << "\n";
	cout << MAGENTA2 << "------------------------------------\n";
	cout << "Data Properties: " << total_dataProperty << "\n";
	cout << "------------------------------------\n";
	cout << "Object Properties: " << total_objectProperty << "\n";
	cout << "------------------------------------\n";
	cout << ORANGE << "\n------------------------------------\n";
	cout << "Erros Semânticos: " << errosSemanticos << "\n";
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