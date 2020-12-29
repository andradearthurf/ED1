#include <stdlib.h>
#include <stdio.h>

typedef struct no{
  int chave;
  struct no *prox;
}No;

No *criaNo(int valor){
  No *novo = (struct no *)malloc(sizeof(struct no));
  if (novo){
    novo->chave = valor;
    novo->prox = NULL;
    return novo;
  }
  else{
    printf("Erro");
    exit(1);
  }
}

void insereInicio(No *L, int valor){
  No *n = criaNo(valor);
  if (L->prox == L){
    n->prox = L;
    L->prox = n;
  }
  else{
    n->prox = L->prox;
    L->prox = n;
  }
}

void insereFim(No *L, int valor){
  No *n = criaNo(valor);
  if (L->prox == L){
    n->prox = L;
    L->prox = n;
  }
  else{
    No *aux = L->prox;
    while(aux->prox != L){
      aux = aux->prox;
    }
    aux->prox = n;
    n->prox = L;
  }
}

void removeInicio(No *L){
  No *removido = L->prox;
  if (removido->prox != removido){
    L->prox = removido->prox;
    free(removido);
  }
  else{
    L->prox = L;
  }
}

void removeFim(No *L){
  No *removido = L->prox;
  No *anterior = L;
  if (L->prox != L){
    while(removido->prox != L){
      anterior = removido;
      removido = removido->prox;
    }
    anterior->prox = L;
    free(removido);
  }
}

void imprimeLista(No *L){
 No *aux = L->prox;
  while (aux != L){
    printf("%d ", aux->chave);
    aux = aux->prox;
  }
}

int main(){
  No *L =(No *)calloc(1, sizeof(No));
  L->prox = L;
  insereFim(L, 1);
  insereFim(L, 3);
  insereFim(L, 4);
  removeFim(L);
  removeFim(L);
  removeFim(L);
  removeFim(L);
  removeFim(L);
  removeFim(L);
  removeFim(L);




  imprimeLista(L);
}