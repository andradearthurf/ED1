#include <stdlib.h>
#include <stdio.h>

//a)
int buscaBinariaRecursiva(int vet[], int inicio, int fim, int num){
  int meio = (fim + inicio) / 2;

  if (inicio > fim){ // caso base
    return -1;
  }
  else if (vet[meio] == num){ // caso base
      return meio;
    }
  
  else{  
    if (vet[meio] > num){ // passo recursivo
      return buscaBinariaRecursiva(vet, inicio, meio-1, num); 
    }
    else if (vet[meio] < num){ //passo recursivo
      return buscaBinariaRecursiva(vet, meio+1, fim, num); 
    }
  }
}

//d)
int main(){
  int *V = NULL;
  int n = 0;
  int valor = 0;

  printf("Digite o tamanho do vetor desejado: ");
  scanf("%d", &n);

  V = (int *)malloc(n * sizeof(int));
  
  printf("\nDigite em ordem crescente os valores desejados no vetor: \n");
  for (int i = 0; i < n; i++){
    printf("Digite o %d elemento: ", i + 1);
    scanf("%d", &V[i]);
  }

  printf("\n");

  for (int i = 0; i < n; i++){
    printf("%d ", V[i]);
  }
  
  printf("\n\nDigite um valor para buscar dentro do vetor: ");
  scanf("%d", &valor);

  if (buscaBinariaRecursiva(V, 0, n-1, valor) == -1){
    printf("O elemento informado nao existe no vetor.");
  } 
  
  else{
     printf("A posicao do valor %d no vetor eh: %d", valor, buscaBinariaRecursiva(V, 0, n-1, valor));
  }

  free(V);
}

/*
QUESTÕES:

a) A questão 'a' resume-se em implementar o algoritmo recursivo da busca binária em um vetor de números
inteiros, ordenado de forma não decrescente, com tamanho N. Tal algoritmo se encontra entre as linhas
11 e 29, ele recebe um vetor de inteiros, a posição inicial do vetor, a posição final e o elemento a ser 
buscado, retornando no final, se o elemento for encontrado, a posição do mesmo;

b) O algoritmo de busca binária sempre irá cair no caso base, desde que o elemento a ser buscado exista no vetor
e seja igual ao elemento do meio. Nesse caso a posição do meio será retornada.
  Já para quando o elemento não existir dentro do vetor, o intervalo será dividido sucessivamente até que tenha pelo 
menos 1 posição a ser verificada no vetor, desse modo conforme for o elemento a ser buscado a variável 'inicio' irá 
receber uma unidade ou a variável 'fim' será decrescida em uma unidade, fazendo com que o 'inicio' seja maior
que o 'fim'. Com isso o algoritmo irá retornar -1, pois o 'inicio' será maior que o 'fim' e esse é o caso base do 
elemento não ter sido encontrado no vetor; 

c) O passo recursivo resume-se em verificar as condições quando o número buscado for maior que o valor do meio, e 
quando o valor do meio é maior que o número buscado. Nesses casos chamaremos recursivamente a função passando novos
valores para as variáveis 'inicio' e 'fim' afim de achar o valor a ser buscado.
  Já o subproblema encarrega-se de realizar a busca binária, ou seja, comparar o valor central do vetor com o elemento
a ser buscado no novo subintervalo a ser analisado;

d) A questão 'd' resume-se, basicamente, na implementação da função 'main' para testar o algoritmo de busca binária recursiva,
tal função está implementada entre as linhas 32 e 66. Alocamos dinâmicamente um vetor de inteiros, preenchemos ele, 
imprimos e por final testamos, inserindo um elemento, se tal elemento está ou não no respectivo vetor.

*/