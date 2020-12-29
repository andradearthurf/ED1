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

No *insereInicio(No *L, int valor){
  No *n = criaNo(valor);
  if (L == NULL){
    n->prox = n;
    L = n;
  }
  else{
    n->prox = L->prox;
    L->prox = n;
  }
  return L;
}

No *insereFim(No *L, int valor){
  No *n = criaNo(valor);
  if (L == NULL){
    n->prox = n;
    L = n;
  }
  else{
    n->prox = L->prox;
    L->prox = n;
    L = n;
  }
  return L;
}

No *removeInicio(No *L){
  if (L){
    No *removido = L->prox;
    if (removido->prox && removido->prox != removido){
      L->prox = removido->prox;
    }
    else{
      L = NULL;
    }
    free(removido);
  }
  return L;
}

No *removeFim(No *L){
  if (L){
    No *aux = L->prox;
    if (aux->prox == aux){
      free(aux);
      L = NULL;
    }
    else{
      while(aux->prox != L){
        aux = aux->prox;
      }

      aux->prox = L->prox;
      free(L);
      L = aux;
    }
  }
  return L;
}

void imprimeLista(No *L){
  if (L){
    No *aux = L->prox;
    do{
      printf("%d ", aux->chave);
      aux = aux->prox;
    }while (aux != L->prox);
  }
}

int main(){
  No *L = NULL;
  L = insereFim(L, 2);
  L = insereFim(L, 3);
  L = insereFim(L, 4);
  L = removeFim(L);
  L = removeFim(L);
  

  imprimeLista(L);
}