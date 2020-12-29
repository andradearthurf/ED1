#include "TAD.h"

typedef struct listaConjuntos{
  /* Definindo a estrutura (listaConjuntos) na qual irá conter um ponteiro para 
  a estrutura Conjunto e estará em um vetor (que conterá todos os conjuntos criados). 
  Essa estrutura possui, também, um id (identificador único), que irá ser usado 
  para identificar cada conjunto criado nessa lista de conjuntos. */
  int id;
  Conjunto *conjunto;
}ListaConjuntos;

/* Função do tipo 'int' (inteiro) que recebe o vetor do tipo ListaConjuntos,
a quantidade de elementos da lista (qtdElementosLista) e o id do conjunto. Essa 
função busca no vetor (lista de conjuntos) o respectivo id, que irá ser retornado 
caso esse 'id' for encontrado ou -1 caso o id não for encontrado. */
int buscaConjuntoLista(ListaConjuntos *vet,  int qtdElementosLista,  int idConjunto){
  /* É realizado um loop for que irá de 0 até a quantidade de elementos que esse
  vetor possui (qtdElementosLista), e com isso é feito um 'if' verificando se naquela
  posição do vetor e no campo 'id', ela é igual ao idConjunto passado por parâmetro
  na função, se for igual ele entra no if e retorna 'i' que representa o 'id' desse
  conjunto. Caso o 'if' não for satisfeito, quer dizer que esse conjunto não foi
  encontrado e portanto é retornado -1. */
  for (int i = 0; i < qtdElementosLista; i++){
    if (vet[i].id == idConjunto){
      return i;
    }
  }
  return -1;
}

/* Função do tipo 'void' que rebece o vetor do tipo ListaConjuntos, e a quantidade
de elementos que esse vetor (lista de Conjuntos) possui. Essa função irá ser respónsavel por
liberar a lista de conjuntos, desalocando a memória anteriormente alocada para a
lista de conjuntos. */
void liberaConjuntoLista(ListaConjuntos *vet, int qtdElementosLista){
  // Define uma variável inteira i começando com 0.
  int i = 0;
  /* Equanto i for menor que a quantidade de elementos (qtdElementosLista) que 
  esse vetor possui, ele irá chamar a função 'libera' implementada no aqruivo 
  'TAD.c', realizando a liberação de todos os conjuntos nesse vetor, desalocando
  a memória.  */
  while (i < qtdElementosLista){
    libera(vet[i].conjunto);
    // Incrementa i até que seja igual a qtdElementosLista, e então sairá do while.
    i++;
  }
  /* Dou um free em vet (passado como parâmetro para a função), liberando o 
  espaço de memória que foi alocado para esse vetor. */
  free(vet);
}

/* Função do tipo 'void' que recebe o vetor (que será ponteiro de ponteiro, para 
conseguir realocar memória a cada chamada da função) do tipo ListaConjuntos, um ponteiro
para a quantidade de elementos (para atualizar essa quantidade diretamente na
memória), o id do conjunto e um ponteiro tam que será o tamanho da alocação de 
memória que irá ser feita para esse vetor. Essa função irá ficar responsável por
inserir um conjunto no vetor, que nesse caso irá ser uma lista com todos os conjuntos. */
void inserirConjunto(ListaConjuntos **vet, int *qtdElementosLista, int idConjunto, int *tam){
  /* Define uma variável inteira 'aux' que irá receber a função 'buscaConjuntoLista'
  , pois iremos buscar se esse conjunto já está na lista de conjuntos ou não 
  (aux irá conter -1 caso o conjunto não seja achado, ou o id do conjunto caso
  o mesmo for achado na lista de conjuntos). */ 
  int aux = buscaConjuntoLista(*vet, *qtdElementosLista, idConjunto);
  /* Se aux for igual a -1, isso quer dizer que não existe nenhum conjunto com 
  aquele 'id' buscado na lista de conjuntos, e portanto pode-se incluir o respectivo
  conjunto nessa lista. */
  if (aux == -1){
    // Faz a alocação de memória para o campo 'conjunto' no vetor.
    (*vet)[*qtdElementosLista].conjunto = (Conjunto *)calloc(1, sizeof(Conjunto));
    /* Faz com que o campo 'id' no vetor receba o 'idConjunto' passado como parâmetro, 
    representando o id do conjunto no qual irá ser inserido. */
    (*vet)[*qtdElementosLista].id = idConjunto;
    /* Atualizo a 'qtdElementosLista' (incrementando em uma unidade), que representa 
    a quantidade de elementos que essa lista de conjuntos possui, fazemos isso pois 
    iremos inserir um conjunto lá. */
    (*qtdElementosLista)++;
    /* Se 'qtdElementosLista' for maior ou igual a 'tam', entramos no respectivo 
    'if' e teremos que alocar mais espaço de memória para introduzir o conjunto 
    na lista. */
    if (*qtdElementosLista >= *tam){
      // Fazemos 'tam' receber mais 5 de tamanho.
      (*tam) = (*tam) + 5;
      /* Faz um realloc em 'vet', pois iremos realocar mais memória para introduzir
      mais conjuntos nessa lista de conjunto. Isso é feito quando o tamanho do vetor
      já foi extrapolado, e precisa-se de mais memória. */ 
      (*vet) = (ListaConjuntos *)realloc((*vet), (*tam) * sizeof(ListaConjuntos));
    }
    // Realiza um print falando que o conjunto foi inserido com sucesso.
    printf("Conjunto inserido com sucesso!\n");
  }
  /* Se o repectivo 'id' contido em aux já existir (aux != -1) nessa lista, não podemos 
  inserir um conjunto com id repetido. Logo o programa entra no else e realiza o 
  respectivo print informando que não é possível incluir conjuntos com 'id' 
  iguais. */
  else{
    printf("Nao eh possivel inserir um conjunto com mesemo 'id'\n");
  }
}

/* Função do tipo 'void' que recebe o vetor do tipo ListaConjuntos, a quantidade 
de elementos na lista (qtdElementosLista), o elemento que iremos inserir e o id 
do conjunto que iremos inserir o respectivo elemento. Essa função é responsável 
por inserir um elemento em um conjunto. */
void inserirElementoConjuntoLista(ListaConjuntos *vet, int qtdElementosLista, int elemento, int idConjunto){
  /* Define uma variável inteira 'aux' que irá receber a função 'buscaConjuntoLista'
  , pois iremos buscar se esse conjunto já está na lista de conjuntos ou não 
  (aux irá conter -1 caso o conjunto não seja achado, ou o id do conjunto caso
  o mesmo for achado na lista de conjuntos). */ 
  int aux = buscaConjuntoLista(vet, qtdElementosLista, idConjunto);
  /* Se aux for igual a -1, isso quer dizer que não existe nenhum conjunto com 
  aquele 'id' buscado na lista de conjuntos, e portanto não terá como inserir
  o elemento. */
  if (aux == -1){
    // Realiza o print para informar o usuário que não encontrou o respectivo conjunto.
    printf("Nao achou o conjunto na lista de conjuntos...\n");
  }
  /* Se aux for diferente de -1, isso quer dizer que aux contém o 'id' de um 
  conjunto que está na lista de conjuntos, e portanto será possivel inserir o 
  elemento nesse conjunto. */
  else{
      /* Chamamos a função 'insereOrd' para inserir o elemento, ordenadamente, 
      no campo conjunto do vetor (lista de elementos). O elemento é inserido na
      posição 'aux' do vetor, pois aux contém o 'id' do respectivo cojunto. */
      insereOrd(vet[aux].conjunto, elemento);
  }
}

/* Função do tipo 'void' que recebe o vetor do tipo ListaConjuntos, a quantidade 
de elementos na lista (qtdElementosLista), o elemento que iremos exlcuir e o id 
do conjunto que iremos exlcuir o respectivo elemento. Essa função é responsável 
por excluir um elemento em um conjunto. */
void exlcuiElementoConjuntoLista(ListaConjuntos *vet, int qtdElementosLista, int elemento, int idConjunto){
  /* Define uma variável inteira 'aux' que irá receber a função 'buscaConjuntoLista'
  , pois iremos buscar se esse conjunto já está na lista de conjuntos ou não 
  (aux irá conter -1 caso o conjunto não seja achado, ou o id do conjunto caso
  o mesmo for achado na lista de conjuntos). */ 
  int aux = buscaConjuntoLista(vet, qtdElementosLista, idConjunto);
  /* Se aux for igual a -1, isso quer dizer que não existe nenhum conjunto com 
  aquele 'id' buscado na lista de conjuntos, e portanto não terá como excluir
  o elemento. */
  if (aux == -1){
    // Realiza o print para informar o usuário que não encontrou o respectivo conjunto.
    printf("Nao achou o conjunto na lista de conjuntos...\n");
  }
  /* Se aux for diferente de -1, isso quer dizer que aux contém o 'id' de um 
  conjunto que está na lista de conjuntos, e portanto será possivel excluir o 
  elemento nesse conjunto. */
  else{
    /* Chamamos a função 'excluiElemento' para excluir o elemento, no campo 
    conjunto do vetor (lista de elementos). O elemento é excluido através da posição 
    'aux' do vetor, pois aux contém o 'id' do respectivo cojunto (que iremos  exlcuir
    o elemento). */
    excluiElemento(vet[aux].conjunto, elemento);
  }
}

/* Função do tipo 'void' que recebe o vetor do tipo ListaConjuntos e a quantidade 
de elementos na lista (qtdElementosLista). Essa função é responsável por imprimir 
todos os conjuntos existentes da lista de conjuntos (vetor). */
void imprimirConjuntos(ListaConjuntos *vet, int qtdElementosLista){
  /* É realizado um loop for que irá de 0 até a quantidade de elementos que esse
  vetor possui (qtdElementosLista), e com isso é feito um print do conjunto que
  iremos imprimir os elementos, e, posteriormente, chamar a função 'imprimeElementosConjunto'
  para imprimir os elementos contidos nesse conjunto. */
  if (qtdElementosLista != 0){
    for (int i = 0; i < qtdElementosLista; i++){
    printf("Conjunto (%d):", vet[i].id);
    imprimeElementosConjunto(vet[i].conjunto);
    }
  }
  /* Caso 'qtdElementosLista' for igual a zero, isso implica que não possui 
  conjuntos no vetor (lista de conjuntos). Com isso o programa entra no else e 
  realiza o print informando que não há conjuntos para imprimir. */
  else{
    printf("Nao possui conjuntos para imprimir!\n");
  }
}

/* Função do tipo 'void' que recebe o vetor do tipo ListaConjuntos, a quantidade 
de elementos na lista (qtdElementosLista) e o id do conjunto que iremos imprimir 
os respectivos elementos. Essa função é responsável por imprimir os elementos 
de um conjunto. */
void imprimirELementosConjuntoLista(ListaConjuntos *vet, int qtdElementosLista, int idConjunto){
  /* Define uma variável inteira 'aux' que irá receber a função 'buscaConjuntoLista'
  , pois iremos buscar se esse conjunto já está na lista de conjuntos ou não 
  (aux irá conter -1 caso o conjunto não seja achado, ou o id do conjunto caso
  o mesmo for achado na lista de conjuntos). */ 
  int aux = buscaConjuntoLista(vet, qtdElementosLista, idConjunto);
  /* Se aux for igual a -1, isso quer dizer que não existe nenhum conjunto com 
  aquele 'id' buscado na lista de conjuntos, e portanto não terá como imprimir
  os elementos. */
  if (aux == -1){
    // Realiza o print para informar o usuário que não encontrou o respectivo conjunto.
    printf("Nao achou o conjunto na lista de conjuntos...\n");
  }
  /* Se aux for diferente de -1, isso quer dizer que aux contém o 'id' de um 
  conjunto que está na lista de conjuntos, e portanto será possivel imprimir os 
  elementos desse conjunto. */
  else{
    printf("Conjunto (%d):", idConjunto);
    /* Chamamos a função 'imprimeElementosConjunto' para imprimir os elementos, no campo 
    conjunto do vetor (lista de elementos). Os elementos serão impresssos através da posição 
    'aux' do vetor, pois aux contém o 'id' do respectivo cojunto (que iremos imprimir
    os elementos). */
    imprimeElementosConjunto(vet[aux].conjunto);
  }
}

/* Função do tipo 'void' que recebe o vetor do tipo ListaConjuntos, a quantidade 
de elementos na lista (qtdElementosLista) e o id do conjunto que iremos esvaziar. 
Essa função é responsável por esvaziar (retirar todos os elementos) de um conjunto. */
void esvaziaConjutoLista(ListaConjuntos *vet, int qtdElementosLista, int idConjunto){
  /* Define uma variável inteira 'aux' que irá receber a função 'buscaConjuntoLista'
  , pois iremos buscar se esse conjunto já está na lista de conjuntos ou não 
  (aux irá conter -1 caso o conjunto não seja achado, ou o id do conjunto caso
  o mesmo for achado na lista de conjuntos). */ 
  int aux = buscaConjuntoLista(vet, qtdElementosLista, idConjunto);
  /* Se aux for igual a -1, isso quer dizer que não existe nenhum conjunto com 
  aquele 'id' buscado na lista de conjuntos, e portanto não terá como esvaziar
  o conjunto. */
  if (aux == -1){
    // Realiza o print para informar o usuário que não encontrou o respectivo conjunto.
    printf("Nao achou o conjunto na lista de conjuntos...\n");
  }
  /* Se aux for diferente de -1, isso quer dizer que aux contém o 'id' de um 
  conjunto que está na lista de conjuntos, e portanto será possível esvaziar o 
  respectivo conjunto. */
  else{
    /* Chamamos a função 'esvaziaConjunto' para retirar os elementos, no campo 
    conjunto do vetor (lista de elementos). Os elementos serão removidos através da posição 
    'aux' do vetor, pois aux contém o 'id' do respectivo cojunto (que iremos esvaziar). */
    esvaziaConjunto(vet[aux].conjunto);
    // Realiza o print para informar que o conjunto foi esvaziado com sucesso.
    printf("Conjunto esvaziado com sucesso!\n");
  }
}

/* Função do tipo 'void' que recebe o vetor do tipo ListaConjuntos, a quantidade 
de elementos na lista (qtdElementosLista) e o id do conjunto que iremos verificar 
se está vazio. Essa função é responsável por verificar se um respectivo conjunto 
está vazio ou não. */
void verificaVazioConjuntoLista(ListaConjuntos *vet, int qtdElementosLista, int idConjunto){
  /* Define uma variável inteira 'aux' que irá receber a função 'buscaConjuntoLista'
  , pois iremos buscar se esse conjunto já está na lista de conjuntos ou não 
  (aux irá conter -1 caso o conjunto não seja achado, ou o id do conjunto caso
  o mesmo for achado na lista de conjuntos). */ 
  int aux = buscaConjuntoLista(vet, qtdElementosLista, idConjunto);
  /* Se aux for igual a -1, isso quer dizer que não existe nenhum conjunto com 
  aquele 'id' buscado na lista de conjuntos, e portanto não terá como realizar a verificação
  se o conjunto está vazio ou não. */
  if (aux == -1){
    // Realiza o print para informar o usuário que não encontrou o respectivo conjunto.
    printf("Nao achou o conjunto na lista de conjuntos...\n");
  }
  /* Se aux for diferente de -1, isso quer dizer que aux contém o 'id' de um 
  conjunto que está na lista de conjuntos, e portanto será possível realizar a
  verificação do respectivo conjunto. */
  else{
    /* É realizado um 'if' que chama a função 'verificaVazio' passando vet na posição
    aux (que sera o id do conjunto) no campo conjunto. Caso essa função retorne 1
    isso quer dizer que o conjunto é vazio, e portanto é realizado o print informando
    que o conjunto está vazio, caso contrário o conjunto não está vazio e um print
    informando, também, é mostrado. */
    if (verificaVazio(vet[aux].conjunto) == 1) printf("O conjunto esta vazio!\n");
    else printf("O conjunto nao esta vazio!\n");
  }
}

/* Função do tipo 'void' que recebe o vetor do tipo ListaConjuntos, a quantidade 
de elementos na lista (qtdElementosLista), o elemento que iremos verificar e o id 
do conjunto que iremos verificar o respectivo elemento. Essa função é responsável 
por verificar se um elemento pertence dentro do respectivo conjunto. */
void verificaElementoConjuntoLista(ListaConjuntos *vet, int qtdElementosLista, int elemento, int idConjunto){
  /* Define uma variável inteira 'aux' que irá receber a função 'buscaConjuntoLista'
  , pois iremos buscar se esse conjunto já está na lista de conjuntos ou não 
  (aux irá conter -1 caso o conjunto não seja achado, ou o id do conjunto caso
  o mesmo for achado na lista de conjuntos). */ 
  int aux = buscaConjuntoLista(vet, qtdElementosLista, idConjunto);
  /* Se aux for igual a -1, isso quer dizer que não existe nenhum conjunto com 
  aquele 'id' buscado na lista de conjuntos, e portanto não terá como verificar
  se o elemento pertence ao conjunto. */
  if (aux == -1){
    // Realiza o print para informar o usuário que não encontrou o respectivo conjunto.
    printf("Nao achou o conjunto na lista de conjuntos...\n");
  }
  /* Se aux for diferente de -1, isso quer dizer que aux contém o 'id' de um 
  conjunto que está na lista de conjuntos, e portanto será possível verificar a
  existência do elemento no respectivo conjunto. */
  else{
    /* É realizado um 'if' que chama a função 'verificaElemento' passando vet na posição
    aux (que sera o id do conjunto) no campo conjunto. Caso essa função retorne 1
    isso quer dizer que o elemento está no conjunto, e portanto é realizado o print informando
    que o elemento está no conjunto, caso contrário o elemento não está no conjunto e um print
    informando, também, é mostrado. */
    if (verificaElemento(vet[aux].conjunto, elemento) == 1) printf("O elemento %d esta no conjunto!\n", elemento);
    else printf("O elemento %d nao esta no conjunto!\n", elemento);
  }
}

/* Função do tipo 'void' que recebe o vetor do tipo ListaConjuntos, a quantidade 
de elementos na lista (qtdElementosLista), o id do primeiro conjunto que iremos 
verificar e o id do segundo conjunto que iremos verificar. Essa função é responsável 
por verificar se um conjunto está contido em outro. */
void contidoConjuntoLista(ListaConjuntos *vet, int qtdElementosLista, int idConjunto1, int idConjunto2){
  /* Define uma variável inteira 'aux1' que irá receber a função 'buscaConjuntoLista'
  , pois iremos buscar se esse conjunto já está na lista de conjuntos ou não 
  (aux irá conter -1 caso o conjunto não seja achado, ou o id do conjunto caso
  o mesmo for achado na lista de conjuntos). */ 
  int aux1 = buscaConjuntoLista(vet, qtdElementosLista, idConjunto1);
  /* Define uma variável inteira 'aux2' que irá receber a função 'buscaConjuntoLista'
  , pois iremos buscar se esse conjunto já está na lista de conjuntos ou não 
  (aux irá conter -1 caso o conjunto não seja achado, ou o id do conjunto caso
  o mesmo for achado na lista de conjuntos). */ 
  int aux2 = buscaConjuntoLista(vet, qtdElementosLista, idConjunto2);
  /* Se aux1 ou aux2 for igual a -1, isso quer dizer que não existe nenhum conjunto com 
  aquele 'id' buscado na lista de conjuntos (buscado em aux1 e aux2), e portanto não 
  terá como verificar se um conjunto está contido no outro. */
  if (aux1 == -1 || aux2 == -1){
    // Realiza o print para informar o usuário que não encontrou o respectivo conjunto.
    printf("Nao achou o conjunto na lista de conjuntos...\n");
  }
  /* Se aux1 e aux2 for diferente de -1, isso quer dizer que aux1 e aux2 contém o 
  'id' de um conjunto que está na lista de conjuntos, e portanto será possível 
  verificar a se um conjunto está contido no outro. */
  else{
     /* É realizado um 'if' que chama a função 'contido' passando vet na posição
    aux1 (que sera o id do primeiro conjunto) e vet na posição aux2 (que sera o id 
    do segundo conjunto), ambos no campo conjunto. Caso essa função retorne 1 isso 
    quer dizer que um conjunto está contido no outro, e portanto é realizado o print 
    informando, caso contrário o conjunto não está contido no outro e um print informando, 
    também, é mostrado. */
    if  (contido(vet[aux1].conjunto, vet[aux2].conjunto) == 1) printf("O conjunto %d esta contido no conjunto %d !\n", idConjunto1, idConjunto2);
    else printf("O conjunto %d nao esta contido no conjunto %d !\n", idConjunto1, idConjunto2);
  }
}

/* Função do tipo 'void' que recebe o vetor do tipo ListaConjuntos, a quantidade 
de elementos na lista (qtdElementosLista), o id do primeiro conjunto que iremos 
verificar e o id do segundo conjunto que iremos verificar. Essa função é responsável 
por verificar se um conjunto é igual ao outro. */
void iguaisConjuntoLista(ListaConjuntos *vet, int qtdElementosLista, int idConjunto1, int idConjunto2){
  /* Define uma variável inteira 'aux1' que irá receber a função 'buscaConjuntoLista'
  , pois iremos buscar se esse conjunto já está na lista de conjuntos ou não 
  (aux irá conter -1 caso o conjunto não seja achado, ou o id do conjunto caso
  o mesmo for achado na lista de conjuntos). */
  int aux1 = buscaConjuntoLista(vet, qtdElementosLista, idConjunto1);
  /* Define uma variável inteira 'aux2' que irá receber a função 'buscaConjuntoLista'
  , pois iremos buscar se esse conjunto já está na lista de conjuntos ou não 
  (aux irá conter -1 caso o conjunto não seja achado, ou o id do conjunto caso
  o mesmo for achado na lista de conjuntos). */ 
  int aux2 = buscaConjuntoLista(vet, qtdElementosLista, idConjunto2);
  /* Se aux1 ou aux2 for igual a -1, isso quer dizer que não existe nenhum conjunto com 
  aquele 'id' buscado na lista de conjuntos (buscado em aux1 e aux2), e portanto não 
  terá como verificar se um conjunto é igual ao outro. */
  if (aux1 == -1 || aux2 == -1){
    // Realiza o print para informar o usuário que não encontrou o respectivo conjunto.
    printf("Nao achou o conjunto na lista de conjuntos...\n");
  }
  /* Se aux1 e aux2 for diferente de -1, isso quer dizer que aux1 e aux2 contém o 
  'id' de um conjunto que está na lista de conjuntos, e portanto será possível 
  verificar a se um conjunto é igual ao outro. */
  else{
    /* É realizado um 'if' que chama a função 'iguais' passando vet na posição
    aux1 (que sera o id do primeiro conjunto) e vet na posição aux2 (que sera o id 
    do segundo conjunto), ambos no campo conjunto. Caso essa função retorne 1 isso 
    quer dizer que um conjunto é igual ao outro, e portanto é realizado o print 
    informando, caso contrário o conjunto não será igual ao outro e um print informando, 
    também, é mostrado. */
    if  (iguais(vet[aux1].conjunto, vet[aux2].conjunto) == 1) printf("O conjunto %d eh igual ao conjunto %d !\n", idConjunto1, idConjunto2);
    else printf("O conjunto %d nao eh igual ao conjunto %d !\n", idConjunto1, idConjunto2);
  }
}

/* Função do tipo 'void' que recebe o vetor do tipo ListaConjuntos, a quantidade 
de elementos na lista (qtdElementosLista), o id do primeiro conjunto que iremos 
realizar a união, e o id do segundo conjunto que iremos unir. Essa função é responsável 
por fazer a união entre dois conjuntos. */
void uniaoConjuntoLista(ListaConjuntos *vet, int qtdElementosLista, int idConjunto1, int idConjunto2){
  /* Define uma variável inteira 'aux1' que irá receber a função 'buscaConjuntoLista'
  , pois iremos buscar se esse conjunto já está na lista de conjuntos ou não 
  (aux irá conter -1 caso o conjunto não seja achado, ou o id do conjunto caso
  o mesmo for achado na lista de conjuntos). */
  int aux1 = buscaConjuntoLista(vet, qtdElementosLista, idConjunto1);
  /* Define uma variável inteira 'aux2' que irá receber a função 'buscaConjuntoLista'
  , pois iremos buscar se esse conjunto já está na lista de conjuntos ou não 
  (aux irá conter -1 caso o conjunto não seja achado, ou o id do conjunto caso
  o mesmo for achado na lista de conjuntos). */
  int aux2 = buscaConjuntoLista(vet, qtdElementosLista, idConjunto2);
  /* Se aux1 ou aux2 for igual a -1, isso quer dizer que não existe nenhum conjunto com 
  aquele 'id' buscado na lista de conjuntos (buscado em aux1 e aux2), e portanto não 
  terá como fazer a união entre os dois conjuntos. */
  if (aux1 == -1 || aux2 == -1){
    // Realiza o print para informar o usuário que não encontrou o respectivo conjunto.
    printf("Nao achou o conjunto na lista de conjuntos...\n");
  }
  /* Se aux1 e aux2 for diferente de -1, isso quer dizer que aux1 e aux2 contém o 
  'id' de um conjunto que está na lista de conjuntos, e portanto será possível 
  fazer a união entre os dois conjuntos. */
  else{
    /* Cria uma lista (conjunto) A que irá ser do tipo ponteiro da estrutura Conjunto, como 
    estamos trabalhando com nó cabeça temos que alocar um espaço na memória para 
    essa lista usando a ferramenta calloc. */
    Conjunto *A = (Conjunto *)calloc(1, sizeof(Conjunto));
    /* Fazemos 'A' receber a função 'uniao' que irá receber o conjunto 1 cuja posição
    é aux1 e o conjunto 2 cuja posição é aux2. Essa função retornará um conjunto
    com a união entre os dois conjuntos (1 e 2). */
    A = uniao(vet[aux1].conjunto, vet[aux2].conjunto);
    // Realizo um print mostrando de qual conjunto é a união.
    printf("\nUniao entre o conjunto %d e %d eh:", idConjunto1, idConjunto2);
    /* Chamo a função 'imprimeElementosConjunto' para imprimir os elementos do 
    conjunto A (que nesse caso contém a união dos dois respectivos conjuntos). */
    imprimeElementosConjunto(A);
    /* Chamo a função 'libera' que irá liberar a memória do conjunto A, pois tal 
    conjunto só servirá para ser impresso em tela, e por isso devemos liberar a 
    memória dele no final */
    libera(A);
  }
}

/* Função do tipo 'void' que recebe o vetor do tipo ListaConjuntos, a quantidade 
de elementos na lista (qtdElementosLista), o id do primeiro conjunto que iremos 
realizar a interseção, e o id do segundo conjunto que iremos fazer a interseção. 
Essa função é responsável por fazer a interseção entre dois conjuntos. */
void intersecaoConjuntoLista(ListaConjuntos *vet, int qtdElementosLista, int idConjunto1, int idConjunto2){
  /* Define uma variável inteira 'aux1' que irá receber a função 'buscaConjuntoLista'
  , pois iremos buscar se esse conjunto já está na lista de conjuntos ou não 
  (aux irá conter -1 caso o conjunto não seja achado, ou o id do conjunto caso
  o mesmo for achado na lista de conjuntos). */
  int aux1 = buscaConjuntoLista(vet, qtdElementosLista, idConjunto1);
  /* Define uma variável inteira 'aux2' que irá receber a função 'buscaConjuntoLista'
  , pois iremos buscar se esse conjunto já está na lista de conjuntos ou não 
  (aux irá conter -1 caso o conjunto não seja achado, ou o id do conjunto caso
  o mesmo for achado na lista de conjuntos). */
  int aux2 = buscaConjuntoLista(vet, qtdElementosLista, idConjunto2);
  /* Se aux1 ou aux2 for igual a -1, isso quer dizer que não existe nenhum conjunto com 
  aquele 'id' buscado na lista de conjuntos (buscado em aux1 e aux2), e portanto não 
  terá como fazer a interseção entre os dois conjuntos. */
  if (aux1 == -1 || aux2 == -1){
    // Realiza o print para informar o usuário que não encontrou o respectivo conjunto.
    printf("Nao achou o conjunto na lista de conjuntos...\n");
  }
  /* Se aux1 e aux2 for diferente de -1, isso quer dizer que aux1 e aux2 contém o 
  'id' de um conjunto que está na lista de conjuntos, e portanto será possível 
  fazer a interseção entre os dois conjuntos. */
  else{
    /* Cria uma lista (conjunto) A que irá ser do tipo ponteiro da estrutura Conjunto, como 
    estamos trabalhando com nó cabeça temos que alocar um espaço na memória para 
    essa lista usando a ferramenta calloc. */
    Conjunto *A = (Conjunto *)calloc(1, sizeof(Conjunto));
    /* Fazemos 'A' receber a função 'intersecao' que irá receber o conjunto 1 cuja posição
    é aux1 e o conjunto 2 cuja posição é aux2. Essa função retornará um conjunto
    com a interseção entre os dois conjuntos (1 e 2). */
    A = intersecao(vet[aux1].conjunto, vet[aux2].conjunto);
    // Realizo um print mostrando de qual conjunto é a interseção.
    printf("\nIntersecao entre o conjunto %d e %d eh:", idConjunto1, idConjunto2);
    /* Chamo a função 'imprimeElementosConjunto' para imprimir os elementos do 
    conjunto A (que nesse caso contém a interseção dos dois respectivos conjuntos). */
    imprimeElementosConjunto(A);
    /* Chamo a função 'libera' que irá liberar a memória do conjunto A, pois tal 
    conjunto só servirá para ser impresso em tela, e por isso devemos liberar a 
    memória dele no final */
    libera(A);
  }
}

/* Função do tipo 'void' que recebe o vetor do tipo ListaConjuntos, a quantidade 
de elementos na lista (qtdElementosLista), o id do primeiro conjunto e do segundo 
conjunto, para então realizar o complemento realtivo entre os conjuntos. Essa 
função é responsável por fazer o complemento relativo entre dois conjuntos. */
void complementoConjuntoLista(ListaConjuntos *vet, int qtdElementosLista, int idConjunto1, int idConjunto2){
  /* Define uma variável inteira 'aux1' que irá receber a função 'buscaConjuntoLista'
  , pois iremos buscar se esse conjunto já está na lista de conjuntos ou não 
  (aux irá conter -1 caso o conjunto não seja achado, ou o id do conjunto caso
  o mesmo for achado na lista de conjuntos). */
  int aux1 = buscaConjuntoLista(vet, qtdElementosLista, idConjunto1);
  /* Define uma variável inteira 'aux2' que irá receber a função 'buscaConjuntoLista'
  , pois iremos buscar se esse conjunto já está na lista de conjuntos ou não 
  (aux irá conter -1 caso o conjunto não seja achado, ou o id do conjunto caso
  o mesmo for achado na lista de conjuntos). */
  int aux2 = buscaConjuntoLista(vet, qtdElementosLista, idConjunto2);
  /* Se aux1 ou aux2 for igual a -1, isso quer dizer que não existe nenhum conjunto com 
  aquele 'id' buscado na lista de conjuntos (buscado em aux1 e aux2), e portanto não 
  terá como fazer o complemento relativo entre os dois conjuntos. */
  if (aux1 == -1 || aux2 == -1){
    // Realiza o print para informar o usuário que não encontrou o respectivo conjunto.
    printf("Nao achou o conjunto na lista de conjuntos...\n");
  }
  /* Se aux1 e aux2 for diferente de -1, isso quer dizer que aux1 e aux2 contém o 
  'id' de um conjunto que está na lista de conjuntos, e portanto será possível 
  fazer o complemento relativo entre os dois conjuntos. */
  else{
    /* Cria uma lista (conjunto) A que irá ser do tipo ponteiro da estrutura Conjunto, como 
    estamos trabalhando com nó cabeça temos que alocar um espaço na memória para 
    essa lista usando a ferramenta calloc. */
    Conjunto *A = (Conjunto *)calloc(1, sizeof(Conjunto));
    /* Fazemos 'A' receber a função 'complementoRelativo' que irá receber o conjunto
    1 cuja posição é aux1 e o conjunto 2 cuja posição é aux2. Essa função retornará 
    um conjunto com o complemento relativo entre os dois conjuntos (1 e 2). */
    A = complementoRelativo(vet[aux1].conjunto, vet[aux2].conjunto);
    // Realizo um print mostrando de qual conjunto é o complemento relativo.
    printf("\nComplemento relativo entre o conjunto %d e %d eh:", idConjunto1, idConjunto2);
    /* Chamo a função 'imprimeElementosConjunto' para imprimir os elementos do 
    conjunto A (que nesse caso contém o complemento relativo dos dois respectivos conjuntos). */
    imprimeElementosConjunto(A);
    /* Chamo a função 'libera' que irá liberar a memória do conjunto A, pois tal 
    conjunto só servirá para ser impresso em tela, e por isso devemos liberar a 
    memória dele no final */
    libera(A);
  }
}

/* Função responsável por apresentar um switch case com opções para utilizar as 
funções implementadas acima. */
void menu(ListaConjuntos **vet, int *qtdElementosLista, int op, int *tam){
  // Criando as variáveis que serão lidas para executar as respectivas funções.
  int idConjunto, idConjunto2, elemento;

  /* Faremos um switch case para solicitar a quem irá usar o programa a função 
  que deseja utilizar. */
  switch (op){
  case 1:
    /* Caso ele digite '1' irá ser realizado as devidas leituras e chamará a 
    função inserirConjunto. */
    printf("\nInserindo um conjunto na lista de conjuntos...\n");
    printf("Digite o 'id' do conjunto que deseja criar: ");
    scanf("%d", &idConjunto);
    inserirConjunto(vet, qtdElementosLista, idConjunto, tam);
    break;

  case 2:
    /* Caso ele digite '2' irá ser realizado as devidas leituras e chamará a 
    função inserirElementoConjuntoLista. */
    printf("\nInserindo um elemento no conjunto...\n");
    printf("Digite o 'id' do conjunto que deseja inserir o elemento: ");
    scanf("%d", &idConjunto);
    printf("Digite o elemento que deseja inserir: ");
    scanf("%d", &elemento);
    inserirElementoConjuntoLista(*vet, *qtdElementosLista, elemento, idConjunto);
    break;

  case 3:
    /* Caso ele digite '3' irá ser realizado as devidas leituras e chamará a 
    função exlcuiElementoConjuntoLista. */
    printf("\nRemovendo um elemento de um conjunto...\n");
    printf("Digite o 'id' do conjunto que deseja remover o elemento: ");
    scanf("%d", &idConjunto);
    printf("Digite o elemento que deseja remover do conjunto: ");
    scanf("%d", &elemento);
    exlcuiElementoConjuntoLista(*vet, *qtdElementosLista, elemento, idConjunto);
    break;

  case 4:
    /* Caso ele digite '4' irá ser realizado as devidas leituras e chamará a 
    função imprimirELementosConjuntoLista. */
    printf("\nImprimindo os elementos de um conjunto...\n");
    printf("Digite o 'id' do conjunto que deseja imprimir: ");
    scanf("%d", &idConjunto);
    imprimirELementosConjuntoLista(*vet, *qtdElementosLista, idConjunto);
    break;

  case 5:
    /* Caso ele digite '5' chamará a função imprimirConjuntos. */
    printf("\nImprimindo todos os conjuntos...\n");
    imprimirConjuntos(*vet, *qtdElementosLista);
    break;

  case 6:
    /* Caso ele digite '6' irá ser realizado as devidas leituras e chamará a 
    função esvaziaConjutoLista. */
    printf("\nEsvaziando um conjunto...\n");
    printf("Digite o 'id' do conjunto que deseja esvaziar: ");
    scanf("%d", &idConjunto);
    esvaziaConjutoLista(*vet, *qtdElementosLista, idConjunto);
    break;

  case 7:
    /* Caso ele digite '7' irá ser realizado as devidas leituras e chamará a 
    função verificaVazioConjuntoLista. */
    printf("\nVerficando se um conjunto eh vazio...\n");
    printf("Digite o 'id' do conjunto que deseja verificar se esta vazio: ");
    scanf("%d", &idConjunto);
    verificaVazioConjuntoLista(*vet, *qtdElementosLista, idConjunto);
    break;

  case 8:
    /* Caso ele digite '8' irá ser realizado as devidas leituras e chamará a 
    função verificaElementoConjuntoLista. */
    printf("\nVerificando se um elemento pertence ao conjunto...\n");
    printf("Digite o 'id' do conjunto que deseja verificar: ");
    scanf("%d", &idConjunto);
    printf("Digite o elemento que deseja verificar: ");
    scanf("%d", &elemento);
    verificaElementoConjuntoLista(*vet, *qtdElementosLista, elemento, idConjunto);
    break;

  case 9:
    /* Caso ele digite '9' irá ser realizado as devidas leituras e chamará a 
    função contidoConjuntoLista. */
    printf("\nVerificando se um conjunto esta contido em outro...\n");
    printf("Digite o primeiro 'id' do conjunto que deseja verificar: ");
    scanf("%d", &idConjunto);
    printf("Digite o segundo 'id' do conjunto que deseja verificar: ");
    scanf("%d", &idConjunto2);
    contidoConjuntoLista(*vet, *qtdElementosLista, idConjunto, idConjunto2);
    break;

  case 10:
    /* Caso ele digite '10' irá ser realizado as devidas leituras e chamará a 
    função iguaisConjuntoLista. */
    printf("\nVerificando se dois conjunto sao iguais...\n");
    printf("Digite o primeiro 'id' do conjunto que deseja verificar: ");
    scanf("%d", &idConjunto);
    printf("Digite o segundo 'id' do conjunto que deseja verificar: ");
    scanf("%d", &idConjunto2);
    iguaisConjuntoLista(*vet, *qtdElementosLista, idConjunto, idConjunto2);
    break;

  case 11:
    /* Caso ele digite '11' irá ser realizado as devidas leituras e chamará a 
    função uniaoConjuntoLista. */
    printf("\nFazendo a uniao entre dois conjuntos...\n");
    printf("Digite o primeiro 'id' que deseja fazer a uniao: ");
    scanf("%d", &idConjunto);
    printf("Digite o segundo 'id' que deseja fazer a uniao: ");
    scanf("%d", &idConjunto2);
    uniaoConjuntoLista(*vet, *qtdElementosLista, idConjunto, idConjunto2);
    break;
  
  case 12:
    /* Caso ele digite '12' irá ser realizado as devidas leituras e chamará a 
    função intersecaoConjuntoLista. */
    printf("\nFazendo a intersecao entre dois conjuntos...\n");
    printf("Digite o primeiro 'id' que deseja fazer a intersecao: ");
    scanf("%d", &idConjunto);
    printf("Digite o segundo 'id' que deseja fazer a intersecao: ");
    scanf("%d", &idConjunto2);
    intersecaoConjuntoLista(*vet, *qtdElementosLista, idConjunto, idConjunto2);
    break;
  
  case 13:
    /* Caso ele digite '13' irá ser realizado as devidas leituras e chamará a 
    função complementoConjuntoLista. */
    printf("\nFazendo o complemento relatico entre dois conjuntos (A - B)...\n");
    printf("Digite o primeiro 'id' que deseja fazer o complemento relativo (conjunto A): ");
    scanf("%d", &idConjunto);
    printf("Digite o segundo 'id' que deseja fazer o complemento relativo (conjunto B): ");
    scanf("%d", &idConjunto2);
    complementoConjuntoLista(*vet, *qtdElementosLista, idConjunto2, idConjunto);
    break;

  default:
    break;
  }
}

int main(){
  // Definimos a variável 'op' que irá ser lida pela função 'menu'.
  int op;
  /* Definimos a variável 'qtdElementosLista' que será a quantidade de elementos 
  na lista de conjuntos, e começará com 0. */
  int qtdElementosLista = 0;
  // Definindo um 'tam' fixo (10) que irá servir para alocar espaço na memória para o vetor.
  int tam  = 10;

  /* Definimos uma variável 'vet' que irá ser do tipo ponteiro de ListaConjuntos 
  e nesse caso será o vetor/lista de conjuntos do nosso programa. Irá ser alocado 
  dinâmicamente um espaço na memória de 'tam' (10) para esse vetor, porém a função de 
  inserção de conjuntos já trata o caso desse 'tam' extrapolar e com isso é dado 
  um realloc nesse vetor. */
  ListaConjuntos *vet = (ListaConjuntos*)malloc(tam * sizeof(ListaConjuntos));

  // 'do while' para fazer um menu de opções repetidas vezes até que o usuário deseje sair dele.
  do{
  printf("\n1  - Inserir um conjunto na lista de conjuntos: \n");
  printf("2  - Inserir um elemento em um conjunto: \n");
  printf("3  - Remover um elemento de um conjunto: \n");
  printf("4  - Imprimir os elementos de um conjunto: \n");
  printf("5  - Imprimir todos os conjuntos: \n");
  printf("6  - Esvaziar um conjunto: \n");
  printf("7  - Verificar se um conjunto eh vazio: \n");
  printf("8  - Verificar se um elemento pertence a um conjunto: \n");
  printf("9  - Verificar se um conjunto esta contido em outro: \n");
  printf("10 - Verificar se dois conjuntos sao iguais: \n");
  printf("11 - Fazer a uniao entre dois conjuntos: \n");
  printf("12 - Fazer a intersecao entre dois conjuntos: \n");
  printf("13 - Fazer o complemento relativo entre dois conjuntos: \n");
  printf("14 - Sair:\n");
  scanf("%d", &op);

  /* Caso op esteja entre 1 e 13 chamamos a função menu, caso contrário eu chamo
  novamente as opções até o usuário digitar uma opção válida.*/
  if (op >= 1 && op <= 13) menu(&vet, &qtdElementosLista, op, &tam);

  }while (op != 14); // Quando op for 14 eu saio do programa.
  
  /* Utilizo a função 'liberaConjuntoLista', para que no fim do programa eu desaloque
  toda a memória alocada para essa lista de conjuntos. */
  liberaConjuntoLista(vet, qtdElementosLista);

  return 0;
}
