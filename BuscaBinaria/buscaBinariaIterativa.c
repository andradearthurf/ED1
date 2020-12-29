#include <stdio.h>
#include <stdlib.h>

//a)
int buscaBinariaIterativa (int vet[], int tamanho, int num){
  int inicio = 0;                    // 1 (complexidade)
  int meio = 0;                      // 1 (complexidade)
  int fim = tamanho - 1;             // 1 (complexidade)
  
  while (inicio <= fim){             // 1 (complexidade)
    meio = (inicio + fim) / 2;       // 1 (complexidade)

    if (num < vet[meio]){            // 1 (complexidade)
      fim = meio - 1;                // 1 (complexidade)
    }
    else if (num > vet[meio]){       // 1 (complexidade)
      inicio = meio + 1;             // 1 (complexidade)
    }
    else{       
      return meio;                   // 0 (nas aulas o return não possuia complexidade)
    }
  }
  return -1;                         // 0 (nas aulas o return não possuia complexidade)
}

//c)
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

  if (buscaBinariaIterativa(V, n, valor) == -1){
    printf("O elemento informado nao existe no vetor.");
  } 
  
  else{
     printf("A posicao do valor %d no vetor eh: %d", valor, buscaBinariaIterativa(V, n, valor));
  }

  free(V);
}

/*
QUESTÕES:

a) A questão 'a' resume-se em implementar o algoritmo iterativo da busca binária em um vetor de números
inteiros, ordenado de forma não decrescente, com tamanho N. Tal algoritmo se encontra entre as linhas
11 e 30, ele recebe um vetor de inteiros, o tamanho e o número que se deseja buscar no vetor, retornando no
final, se o elemento for encontrado, a posição do mesmo;

b) A garantia de termino do meu algoritmo se baseia na condição do while (inicio <= fim). Quando o valor digitado 
pelo usúario for encontrado o algoritmo retornará a posição desse valor. Caso o elemento não seja achado, o vetor
será subdividido até chega na última execução do while, desde que o elemento buscado seja menor que o elemento central
do vetor a variável 'fim' receberá 'meio - 1', logo a varíavel 'inicio' será maior que 'fim', com isso os códigos dentro
do while não serão executados (a condição do while não será satisfeita) e retornará -1. Já se o elemento buscado for
maior que o elemento central a variável 'inicio' receberá 'meio + 1', logo o 'incio' será maior que o 'fim' e com isso
o algoritmo sairá do while e retornará -1;

c) A questão 'c' resume-se, basicamente, na implementação da função 'main' para testar o algoritmo de busca binária,
tal função está implementada entre as linhas 33 e 67. Alocamos dinâmicamente um vetor de inteiros, preenchemos ele, 
imprimos e por final testamos, inserindo um elemento, se tal elemento está ou não no respectivo vetor;

d) Se considerarmos o pior caso teremos que o algoritmo entrará dentro do while irá analisar o primeiro 'if', porém
como é o pior caso ele cairá no segundo 'if', logo iremos contar complexidade 1 na atribuição da varíavel meio,
a condição do primeiro 'if', a condição do segundo 'if' e na atribuição da varíavel inicio. A condição dentro do while 
também irá ter complexidade 1 (e se somarmos isso dará 5).
Já fora do while irá ter complexidade 1 na atribuição do inicio, do meio e no fim (somando tudo irá dar 3).

O while irá executar um máximo de k repetições sempre 'dividindo' o vetor para encontrar o elemento, até o 
vetor ter pelo menos um elemento, então temos a expressão:

n/2^k = 1
n = 2^k (isolando o n)
log2(n) = log2(2^k) (aplicando log nos dois lados)
log2(n) = k -> Complexidade do while. (achamos o valor de k repetição e logo sua complexidade)

f(n) = 3(complexidade fora do while) + 5log2(n)(5 * a complexidade do while)

f(n) = 3 + 5log2(n)
Função assíntotica = log2(n)

*/