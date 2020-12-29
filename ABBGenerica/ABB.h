#ifndef __ABB_H__
#define __ABB_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arvore{
  /* Definindo a estrutura (arvore) na qual irá conter um ponteiro para as 
  informações dos elementos na árvore (info), e um ponteiro para a direita da árvore e 
  outro para a esquerda. Essa estrutura  será uma árvore binária de busca e irá 
  armazenar as informações dos respectivos elementos que irá ser inserido (nesse 
  caso do tipo genérico de dados) e os ponteiros 'esq' e 'dir' orientam para onde 
  esse elemento irá na árvore. */
  void *info;
  struct arvore *esq, *dir;
}Arvore;

/* Função do tipo ponteiro para 'Arvore' que recebe como parâmetro o valor (nesse 
caso é do tipo void, pois estamos trabalhando com tipo genérico de dados), que 
é o elemento que irá ser inserido na estrutua 'Arvore'. E por fim, cria um nó/ 
folha em uma árvore binária de busca, e o retorna. */
Arvore *criaNoArvore(void *valor);

/* Função do tipo 'void' que recebe uma árvore binária de busca, um inteiro 
contador para o nível da árvore e uma callback que irá ser responsável por 
imprimir os 'id's' dos elementos na árvore. E com isso, ela imprime por nível
os elementos que estão na árvore binária de busca. */
void imprime(Arvore *T, int cont, void (*cbImprime) (void *));

/* Função do tipo 'void' que recebe uma árvore binária de busca e uma callback 
para liberar o campo 'info' da árvore. E, com isso, libera o espaço de memória que 
foi alocado anteriormente para a respectiva árvore. */
void libera(Arvore *T, void (*liberaInfo) (void *));

/* Função do tipo 'void' que recebe uma árvore binária de busca, um valor do tipo
void (pois estamos trabalhando com tipo genárico de dados), uma callback para comparar
os elementos dentro da função (usamos essa função, pois precisamos usar a função
de busca), e por fim uma callback para realizar a impressão do campo 'info' na árvore. 
Com isso, essa função imprime todos os dados que estão no campo 'info' da árvore. */
void imprimeInfo(Arvore *T, void *valor, int (*cbCompara)(void *, void *), void (*cb) (void *));

/* Função do tipo ponteiro para 'Arvore' que recebe como parâmetro uma árvore
binária de busca, um valor (nesse caso é do tipo void, pois estamos trabalhando 
com tipo genérico de dados), e uma callback para comparar os elementos dentro da
da função. Por fim, a função realiza uma busca na árvore binária de busca, retornando
o respectivo elemento buscado. */
Arvore *buscaRec(Arvore *T, void *valor, int (*cbCompara)(void *, void *));

/* Função do tipo ponteiro para 'Arvore' que recebe como parâmetro uma árvore binária
de busca, um valor (nesse caso é do tipo void, pois estamos trabalhando com tipo
genérico de dados), uma callback que irá comparar os elementos e outra callback para
liberar (desalocar) o campo 'info' da árvore. Por fim, a função realiza a inserção
dentro da árvore e a retorna com o elemento inserido. */
Arvore *insercaoRec(Arvore *T, void *valor, int (*cbCompara)(void *, void *), void (*liberaInfo) (void *));

/* Função do tipo ponteiro para 'Arvore' que recebe como parâmetro uma árvore binária
de busca, um valor (nesse caso é do tipo void, pois estamos trabalhando com tipo
genérico de dados), uma callback que irá comparar os elementos e outra callback para
liberar (desalocar) o campo 'info' da árvore. Por fim, a função realiza a remoção 
de um elemento dentro da árvore e a retorna com o elemento removido. */
Arvore *removerNaArvore (Arvore *T, void *valor, int (*cbCompara)(void *, void *), void (*liberaInfo) (void *));

#endif