#ifndef __TAD_H__
#define __TAD_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct conjunto{
  /* Definindo a estrutura (conjunto) na qual irá conter os elementos do conjunto
  ,e está em uma lista simplesmente encadeada. Essa estrutura possui, também, um 
  valor (elemento),e um ponteiro para o prox (para o próximo elemento da 
  lista). */
  int valor;
  struct  conjunto *prox;
}Conjunto;

/* Função do tipo ponteiro para 'Conjunto' que recebe como parâmetro o valor, que 
nesse caso é o elemento que irá ser inserido na estrutua 'Conjunto'. E por fim, 
cria um nó, o retornando, na lista simplesmente encadeada de 'Conjunto'. */
Conjunto *criaNo(int valor);

/* Função do tipo ponteiro para 'Conjunto' que recebe como parâmetro uma lista 
simplemente encadeada do tipo 'Conjunto', um valor (que será o elemento que irá 
ser buscado na lista) e um ponteiro para o predecessor. Com isso ela irá retornar, 
se encontrar, o valor buscado na respectiva lista (conjunto). */
Conjunto *buscaListaOrd(Conjunto *A, int valor, Conjunto **pred); 

/* Função do tipo 'void' que recebe uma lista simplemente encadeada do tipo 'Conjunto' 
e libera o espaço de memória que foi alocado anteriormente para a respectiva lista
encadeada. */
void libera(Conjunto *A);

/* Função do tipo 'void' que recebe uma lista simplesmente encadeada do tipo 
'Conjunto', e uma chave (valor), inserindo ordenadamente a chave na repectiva lista 
passada como parâmetro. Formando, então, um conjunto de elementos. */ 
void insereOrd(Conjunto *A, int ch); 
/* A função 'insere' é idêntica a função acima 'insereOrd', porém a única diferença 
é que ela não realiza o print quando não é possível inserir um elemento repetido 
no conjunto. */
void insere(Conjunto *A, int ch);

/* Função do tipo 'void' que recebe uma lista simplemente encadeada do tipo 'Conjunto',
e um valor, excluindo esse valor (que foi passado como parâmetro) da lista, se 
encontrarmos o respectivo valor. */
void excluiElemento(Conjunto *A, int valor);

/* Função do tipo 'void' que recebe uma lista simplemente encadeada do tipo 'Conjunto',
e realiza a impressão dos elementos contidos nessa lista, que nesse caso será a 
repesentação de um conjunto. */
void imprimeElementosConjunto(Conjunto *A);

/* Funçao do tipo 'void' que recebe uma lista simplesmente encadeada do tipo 'Conjunto'
e realiza a remoção de todos os elementos contidos nessa lista, esvaziando o repectivo
conjunto de elementos. */
void esvaziaConjunto(Conjunto *A);

/* Função do tipo 'int' (inteiro) que recebe uma lista simplesmente encadeada do
tipo 'Conjunto', retornando 1 caso a lista esteja vazia ou 0 caso ela não esteja
vazia. */
int verificaVazio(Conjunto *A); 

/* Função do tipo 'int' (inteiro) que recebe uma lista simplesmente encadeada do tipo
'Conjunto', e um valor. A função irá buscar esse 'valor' na lista (conjunto), retornando 1
caso o elemento pertença a esse conjunto ou 0 caso não pertença .*/
int verificaElemento(Conjunto *A, int valor);

/* Função do tipo 'int' (inteiro) que recebe duas listas simplesmente encadeadas do
tipo 'Conjunto', e retornar 1 caso o primeiro conjunto esteja contido no outro ou 0 
caso não esteja contido. */
int contido(Conjunto *A, Conjunto *B);

/* Função do tipo 'int' (inteiro) que recebe duas listas simplemente encadeadas do
tipo 'Conjunto', e retorna 1 caso os dois conjuntos forem iguais ou 0 caso não  
forem. */
int iguais(Conjunto * A, Conjunto *B);

/* Função do tipo ponteiro para 'Conjunto' que recebe duas listas simplemente encadeadas
do tipo 'conjunto', e retorna uma terceira lista (conjunto) com a união dos dois
repectivos conjuntos. */ 
Conjunto  *uniao(Conjunto *A, Conjunto *B); 

/* Função do tipo ponteiro para 'Conjunto' que recebe duas listas simplemente encadeadas
do tipo 'conjunto', e retorna uma terceira lista (conjunto) com a interseção dos dois
repectivos conjuntos. */ 
Conjunto *intersecao(Conjunto *A, Conjunto *B);

/* Função do tipo ponteiro para 'Conjunto' que recebe duas listas simplemente encadeadas
do tipo 'conjunto', e retorna uma terceira lista (conjunto) com o complemento relativo
do primeiro conjunto com o segundo. */
Conjunto *complementoRelativo(Conjunto *A, Conjunto *B);

#endif
