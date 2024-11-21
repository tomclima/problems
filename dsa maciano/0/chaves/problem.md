# Title
CHAVES

Malu precisa da sua ajuda para criar um programa que verifica se uma expressão está bem formada por chaves. A definição de expressão bem formada é a seguinte:

    Uma expressão vazia é sempre bem formada (i.e. uma string vazia)
    Se E é bem formada, então { E } também é bem formada
    Se E é bem formada, então E E também é bem formada

Ela conseguiu coletar alguns exemplos de expressões bem formadas para te ajudar a entender o problema:

    { { { } } }
    { } { }
    { { } } { }
    { { } { { } { } } }

E também alguns exemplos de expressões mal formadas:

    { } {
    { { } } { } }
    { } { } }
    { { } } { { { } }


## input
A única linha de entrada é composta por uma string E, a expressão formada por chaves. Cada chave estará separada por exatamente um espaço.

## output
Você deve produzir uma única linha de saída com o caractere S caso a expressão seja bem formada, ou N caso contrário.

## constraints

## example

(input)
{ { { } } }
____________
(output)
S

(input)
{ { } { } } { } 
____________
(output)
S

(input)
{ { } { } } } 
____________
(output)
N



