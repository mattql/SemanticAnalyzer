%{
// Reconhecedor de uma linguagem simplificada
#include <iostream>
#include "syntactic.tab.h"
using namespace std;

string tipoDado = ""; // Variável para exibir o token DATATYPE no syntactic.y
string tipoPropriedade = ""; // Variável para exibir o token IDPROP no syntactic.y
%}

%option yylineno
%option noyywrap
delim       [ \t\n]
brancos     {delim}+
letra       [a-zA-Z]
card        [0-9]+
floats      [0-9]+("."[0-9]+)?
idclasse    [A-Z]{letra}+(_{letra}*)?
idprop      ("has"[A-Z]{letra}*)|("is"[A-Z]{letra}"Of"*)|([a-z]{letra}*)|([a-z][A-Z]{letra}*)
individname [A-Z]{letra}*{card}+
symbol      [\[\]\{\}\(\)><,=]|<=|>=
datatype    ("owl:"|"xsd:"|"rdfs:")[a-z]+

%%
{brancos}	       ; // remover espacos em branco, sem retorno
"some"             return SOME;
"all"              return ALL;
"value"            return VALUE;
"min"              return MIN;
"max"              return MAX;
"exactly"          return EXACTLY;
"that"             return THAT;
"not"              return NOT;
"and"              return AND;
"or"               return OR;
"only"             return ONLY;
"Class:"           return CLASS;
"EquivalentTo:"    return EQUIVALENTTO;
"Individuals:"     return INDIVIDUALS;
"SubClassOf:"      return SUBCLASSOF;
"DisjointClasses:" return DISJOINTCLASSES;
{idclasse}         return IDCLASSE;
{idprop}           {tipoPropriedade = yytext; return IDPROP;}
{symbol}           return SYMBOL;
{individname}      return INDIVIDNAME;
{datatype}         {tipoDado = yytext; return DATATYPE;}
{card}             return CARD;
{floats}           return FLOATS;
.                  cout << yytext << " é um token inválido!\n";
%%

// nenhuma função auxiliar é necessária