#include "TAD.h"

Conjunto *criaNo(int valor){
  // Aloca um espaço na memória para a varíavel novo (que é do tipo struct Conjunto).
  Conjunto *novo = (Conjunto*)malloc(sizeof(Conjunto));

  /* Verifica se novo existe, e se não existir, no caso não tiver memória para ele 
  ser alocado, printa erro e sai do programa. */
  if (novo == NULL){
    printf("Error");
    exit(1);
  }
  /* E e se novo existir o espaço 'valor' de novo (novo->valor) recebe o 'valor' 
  recebido como parâmetro pela função. Já o espaço para prox de novo (novo->prox) 
  recebe NULL. E por fim, retornamos 'novo' que representará o nó na lista simplemente 
  encadeada (Conjunto). */
  novo->valor = valor;
  novo->prox = NULL;
  return novo;
}


Conjunto *buscaListaOrd(Conjunto *A, int valor, Conjunto **pred){
  /* Cria uma variável aux do tipo ponteiro da estrutura Conjunto. Ela irá ser o nó
  cabeça da lista, pois recebe o próximo da lista A (fazendo com que a lista 
  nunca seja vazia e aponte sempre para o nó cabeça). */
  Conjunto *aux = A->prox;
  /* A variável pred (predecessora) irá receber o início da lista. Como aux 
  recebe o próximo, pred receberá o 'atual'. */
  (*pred) = A;
  /* Enquanto a variável aux for diferente de NULL iremos percorrer toda a lista
  em busca de encontrar o 'valor'. */
  while (aux != NULL)
  {
    /* Se valor for menor ou igual que aux->valor isso quer dizer que achamos valor. Daremos
    um break para sair do while e retornaremos aux que é 'valor'. */
    if (valor <= aux->valor) break;
    /* Se o if acima não for satisfeito faremos com que a variável pred receba
    o valor atual (nesse caso será aux). */
    (*pred) = aux;
    /* Percorreremos aux (que aponta para o próximo da lista A) até que seja
    NULL e saia do while, ou até achar valor. */
    aux = aux->prox;
  }
  // Retorna aux no final de tudo.
  return aux;
}

void libera(Conjunto *A){
  /* Equanto A existir (A!=NULL) eu percorrerei toda a lista até ela ser NULL, removendo,
  também, o nó cabeça dessa lista. */
  while (A){
    // Crio uma cópia para a lista que irá apontar para o início dela.
    Conjunto *aux = A;
    // Percorro aux até ele ser igual a NULL e sair do while.
    A = A->prox;
    // Dou um free em aux, liberando todo o espaço de memória da respectiva lista.
    free(aux);
  }
}


void insereOrd(Conjunto *A, int ch){
  /* Realizo um 'if' passando a lista A e o valor (ch) para a função 'verficaElemento'
  , para então verificar se esse elemento que eu quero inserir não está na lista,
  pois não podemos inserir elementos repetidos em um conjunto. Se essea condição
  for verdadeira, então, realizamos os comandos dentro do 'if'. */
  if (verificaElemento(A, ch) == 0){
    // Cria uma variável novo que irá ser do tipo ponteiro de Conjunto, e receberá um nó com ch (valor).
    Conjunto *novo = criaNo(ch);
    // Definide pred começando como NULL.
    Conjunto *pred = NULL;
    // Faz com que aux receba o valor de ch (valor) buscado através da função buscaListaOrd. 
    Conjunto *aux = buscaListaOrd(A, ch, &pred);
    // O campo prox da lista 'novo' que contém um nó receberá aux (que nesse caso será o ch (valor) buscado).
    novo->prox = aux;
    // O campo prox da variável pred (do tipo ponteiro de Conjunto) receberá novo.
    pred->prox = novo;
    // Realiza o print informando que o elemento realmente foi inserido.
    printf("Elemento inserido com sucesso!\n");
  }
  /* Se a condição do 'if' não for satisfeita, isso é, já existir um elemento igual 
  ao elemento que eu quero inserir nessa lista, entrará no else e realizará um print 
  informando que não é possível inserir elementos repetidos nessa lista (conjunto). */
  else{
    printf("Nao eh possivel inserir elementos repetidos!\n");
  }
}

void insere(Conjunto *A, int ch){
  /* Realizo um 'if' passando a lista A e o valor (ch) para a função 'verficaElemento'
  , para então verificar se esse elemento que eu quero inserir não está na lista (retornando 0),
  pois não podemos inserir elementos repetidos em um conjunto. Se essea condição
  for verdadeira, então, realizamos os comandos dentro do 'if'. */
  if (verificaElemento(A, ch) == 0){
    // Cria uma variável novo que irá ser do tipo ponteiro de Conjunto, e receberá um nó com ch (valor).
    Conjunto *novo = criaNo(ch);
    // Definide pred começando como NULL.
    Conjunto *pred = NULL;
    // Faz com que aux receba o valor de ch (valor) buscado através da função buscaListaOrd. 
    Conjunto *aux = buscaListaOrd(A, ch, &pred);
    // O campo prox da lista 'novo' que contém um nó receberá aux (que nesse caso será o ch (valor) buscado).
    novo->prox = aux;
    // O campo prox da variável pred (do tipo ponteiro de Conjunto) receberá novo.
    pred->prox = novo;
  }
  /* Essa função não possui else, pois o obejtivo dela em relação a 'insereOrd' 
  é não realizar o print do if nem do else. */
}

void excluiElemento(Conjunto *A, int valor){
  // Definide pred começando como NULL.
  Conjunto *pred = NULL;
  // Faz com que aux receba o valor de ch (valor) buscado através da função buscaListaOrd. 
  Conjunto *aux = buscaListaOrd(A, valor, &pred);
  // Definide removido começando como NULL
  Conjunto *removido = NULL;
  /* Realiza um 'if' para verificar se aux realmente existe e chamamos a função
  'verificaElemento' passando como parâmetro a lista A e o 'valor' e caso o elemento
  seja encontrado (retornará 1), ele entrará no 'if' e realizará os apontamentos
  para remover o respectivo elemento. */
  if (aux != NULL && verificaElemento(A, valor) == 1){
    /* Faz com que 'removido' receba do conteúdo de 'aux' (fazendo com que 
    removido seja uma cópia de aux). */
    removido = aux;
    /* Faz com que o ponteiro prox de pred receba o removido->prox (o próximo de 
    removido, nesse caso o próximo de aux). */
    pred->prox = removido->prox;
    // Faz com que aux receba removido->prox (o próximo de removido).
    aux = removido->prox;
    /* Dou um free em removido, liberando o espaço de memória, e constatando 
    que o elemento realmente foi removido do conjunto. */
    free(removido);
    // Realizo o print informando que o elemento foi realmente removido.
    printf("Elemento removido com sucesso!\n");
  }
  // Caso o elemento não seja encontrado entrará no else abaixo.
  else{
    // Faz com que o ponteiro prod de pred (pred->prox) receba NULL.
    pred->prox = NULL;
    // Realiza o print informando que o elemento não existe no conjunto.
    printf("Elemento nao existe no conjunto!\n");
  }
}

void imprimeElementosConjunto(Conjunto *A){
  printf("\n");
  /* Cria uma variável aux do tipo ponteiro da estrutura Conjunto. Ela irá ser o nó
  cabeça da lista, pois recebe o próximo da lista A (fazendo com que a lista 
  nunca seja vazia e aponte sempre para o nó cabeça). */
  Conjunto *aux = A->prox;
  /* Verifica se 'aux' é igual a NULL, é feito isso para realizar o tratamento de erro caso o 
  cliente peça para imprimir uma lista que esteja vazia. Logo ele entrará no 
  'if' e realizará o print informando que o conjunto (lista) está vazio. */
  if (aux == NULL){
    printf("O conjunto esta vazio!\n");
  }
  /* Caso 'aux' não seja NULL, isso quer dizer que a lista (conjunto) não está 
  vazio, e portanto ele entrará no else abaixo. */
  else{
    /* Equanto aux existir (aux!=NULL) eu percorrerei toda a lista até ela ser NULL, realizando
    o print dos repectivos elementos da lista. */
    while(aux != NULL){
    printf("%d \n", aux->valor);
    /* Percorreremos aux (que aponta para o próximo da lista A) até que seja
    NULL e saia do while. */
    aux = aux->prox;  
  }
  printf("\n");
  } 
}

void esvaziaConjunto(Conjunto *A){
  /* Cria uma variável aux do tipo ponteiro da estrutura Conjunto. Ela irá ser o nó
  cabeça da lista, pois recebe o próximo da lista A (fazendo com que a lista 
  nunca seja vazia e aponte sempre para o nó cabeça). */
  Conjunto *aux = A->prox;
  /* Equanto aux existir (aux!=NULL) eu percorrerei toda a lista até ela ser NULL, realizando
  os repectivos comandos para remover os elementos do conjunto. */
  while(aux != NULL){
    /* Cria uma variável removido que é do tipo ponteiro da estrutura Conjunto, 
    e faz ela receber 'aux', fazendo com que ela seja uma cópia de aux para não 
    remover diretamente ele. */
    Conjunto *removido = aux;
    /* Percorreremos aux (que aponta para o próximo da lista A) até que seja
    NULL e saia do while. */
    aux = aux->prox;
    /* Dou um free em removido, liberando o espaço de memória, e constatando 
    que o elemento realmente foi removido do conjunto. */
    free(removido);
  }
  /* Faz com que A->prox (nó cabeça) receba NULL, fazendo, então, que a lista seja 
  NULL e fique relamente vazia e sem lixo de memória. */
  A->prox = NULL;
}

int verificaVazio(Conjunto *A){
  /* Realiza um 'if' para verificar se A->prox é igual a NULL, e caso for isso quer
  dizer que a lista (conjunto) está vazia e é retornando o valor 1. Caso contrário
  a lista não estará vazia e é retornado o valor 0. */
  if (A->prox == NULL) return 1;
  else return 0;
}

int verificaElemento(Conjunto *A, int valor){
  // Definide pred começando como NULL.
  Conjunto *pred = NULL;
  // Faz com que aux receba o valor de ch (valor) buscado através da função buscaListaOrd. 
  Conjunto *aux = buscaListaOrd(A, valor, &pred);
  /* Realiza um 'if' para verificar se aux existe e se o valor passado como parâmetro
  pela função 'verificaElemento' é igual ao valor encontrado com a função 'buscaListaOrd' 
  (por meio de aux), caso isso for verdade quer dizer que o elemento está na lista 
  e é retornado o valor 1. Caso contrário o elemento não foi encontrado e é retornado 
  o valor 0. */
  if (aux && aux->valor == valor) return 1;
  else return 0;
}

int contido(Conjunto *A, Conjunto *B){
  /* Cria uma variável aux do tipo ponteiro da estrutura Conjunto. Ela irá ser o nó
  cabeça da lista, pois recebe o próximo da lista A (fazendo com que a lista 
  nunca seja vazia e aponte sempre para o nó cabeça). */
  Conjunto *aux = A->prox;
  // Define duas variáveis temporárias 'temp1' e 'temp2' para auxiliar na realização da função 'contido'.
  int temp1 = 0, temp2 = 0;
  /* Enquanto a variável aux existir (aux!=NULL) iremos percorrer toda a lista (A) incrementando
  temp1 se o elemento do conjunto A (aux->valor) estiver no conjunto B (faz-se 
  isso atráves da função já implementada 'verificaElemento'), e acumlando temp2 
  a cada vez que aux é percorrido. */
  while(aux){
    if (verificaElemento(B, aux->valor) == 1){
      temp1++;
    }
    temp2++;
    /* Percorreremos aux (que aponta para o próximo da lista A) até que seja
    NULL e saia do while. */
    aux = aux->prox;
  }
  /* Realiza um 'if' para verifica se temp1 é igual a temp2, e caso seja verdade 
  isso quer dizer que o conjunto A está contido no conjunto B, e, portando, é 
  retornado 1. */
  if (temp1 == temp2) return 1;
  /* Se temp1 não for igual a temp2, logo o conjunto A não está contido em B, 
  e com isso é retornado o valor 0. */
  else return 0;
}

int iguais(Conjunto *A, Conjunto *B){
  /* É possível analisar a igualdade de dois conjuntos, de acordo com a teoria
  de conjuntos, se ambos os conjuntos estiverem um contido no outro (se A estiver 
  contido em B e se B estiver contido em A). Com isso é realizado um 'if' para 
  verificar se o conjunto A está contido em B e vice-versa, se isso for verdade, 
  quer dizer que os conjuntos são iguais, e portanto é retornado o valor 1. Caso 
  contrário, os conjuntos não são iguais e o valor 0 é retornado. */
  if (contido(A, B) == 1 && contido(B, A) == 1) return 1;
  else return 0;
}

Conjunto *uniao(Conjunto *A, Conjunto *B){
  /* Cria uma lista C que irá ser do tipo ponteiro da estrutura Conjunto, como 
  estamos trabalhando com nó cabeça temos que alocar um espaço na memória para 
  essa lista usando a ferramenta calloc. */    
  Conjunto *C = (Conjunto *)calloc(1, sizeof(Conjunto));
  /* Cria uma variável aux1 do tipo ponteiro da estrutura Conjunto. Ela irá ser o nó
  cabeça da lista (B), pois recebe o próximo da lista B (fazendo com que a lista 
  nunca seja vazia e aponte sempre para o nó cabeça). */   
  Conjunto *aux1 = B->prox;
  /* Cria uma variável aux2 do tipo ponteiro da estrutura Conjunto. Ela irá ser o nó
  cabeça da lista (A), pois recebe o próximo da lista A (fazendo com que a lista 
  nunca seja vazia e aponte sempre para o nó cabeça). */
  Conjunto *aux2 = A->prox;
  /* Enquanto aux1 exisitir (aux1!=NULL) iremos percorrer toda a lista B (nesse caso, pois aux1
  aponta para a lista B) e usar a função 'insere', para iserir os elementos da lista
  B na lista C. */      
  while(aux1){
    insere(C, aux1->valor);
    /* Percorreremos aux1 (que aponta para o próximo da lista B) até que seja
    NULL e saia do while. */      
    aux1 = aux1 -> prox;          
  }
  /* Enquanto aux2 exisitir (aux2!=NULL) iremos percorrer toda a lista A (nesse caso, pois aux2
  aponta para a lista A) e usar a função 'insere', para iserir os elementos da lista
  A na lista C. */ 
  while (aux2){
    insere(C, aux2->valor);
    /* Percorreremos aux2 (que aponta para o próximo da lista A) até que seja
    NULL e saia do while. */
    aux2 = aux2->prox;
  }
  /* No fim de tudo é retornado a lista C que possui a respectiva união do conjunto A 
  com o conjunto B. */
  return C;       
}

Conjunto *intersecao(Conjunto *A, Conjunto *B){
  /* Cria uma lista C que irá ser do tipo ponteiro da estrutura Conjunto, como 
  estamos trabalhando com nó cabeça temos que alocar um espaço na memória para 
  essa lista usando a ferramenta calloc. */
  Conjunto *C = (Conjunto *)calloc(1, sizeof(Conjunto));
  /* Cria uma variável aux do tipo ponteiro da estrutura Conjunto. Ela irá ser o nó
  cabeça da lista (A), pois recebe o próximo da lista A (fazendo com que a lista 
  nunca seja vazia e aponte sempre para o nó cabeça). */
  Conjunto *aux = A->prox;
  /* Equanto aux existir (aux!=NULL) e o conjunto C também exisitr (C!=NULL), 
  iremos percorrer todo o conjunto A (pois nesse caso aux aponta para A), usando 
  a função 'verificaElemento' para verificar se há algum elemento de A no conjunto 
  B, e caso seja verdade é inserido esses elementos de A que também estão em B no 
  conjunto C. Fazendo com que o conjunto C fique com a interseção dos dois conjuntos 
  A e B. */
  while (aux && C){
    if (verificaElemento(B, aux->valor) == 1){
      insere(C, aux->valor);
    }
    /* Percorreremos aux (que aponta para o próximo da lista A) até que seja
    NULL e saia do while. */    
    aux = aux->prox;
  }
  /* No fim de tudo é retornado o conjunto C que possui a interseção dos conjuntos 
  A e B. */
  return C;
}

Conjunto *complementoRelativo(Conjunto *A, Conjunto *B){
  /* Cria uma lista C que irá ser do tipo ponteiro da estrutura Conjunto, como 
  estamos trabalhando com nó cabeça temos que alocar um espaço na memória para 
  essa lista usando a ferramenta calloc. */
  Conjunto *C = (Conjunto *)calloc(1, sizeof(Conjunto));
  /* Cria uma variável aux1 do tipo ponteiro da estrutura Conjunto. Ela irá ser o nó
  cabeça da lista (B), pois recebe o próximo da lista B (fazendo com que a lista 
  nunca seja vazia e aponte sempre para o nó cabeça). */
  Conjunto *aux1 = B->prox;
  /* Cria uma variável aux2 do tipo ponteiro da estrutura Conjunto. Ela irá receber
  a interseção entre o conjunto A e o conjunto B. Pois é preciso para a lógica
  de cálculo do complemento relativo. */
  Conjunto *aux2 = intersecao(A, B);
  /* Equanto aux1 existir, é realizado um 'if' para verificar (usando a função
  verificaElemento) se o elemento da lista B (aux1->valor) não está em aux2 (que
  nesse caso é a interseção entre A e B), se realmente esse elemento não estiver 
  em aux2, é chamada a função 'insere', e é inserido na lista C os elementos do
  conjunto B (aux1->valor). */
  while (aux1){
    if (verificaElemento(aux2, aux1->valor) == 0){
      insere(C, aux1->valor);
    }
    /* Percorreremos aux1 (que aponta para o próximo da lista B) até que seja
    NULL e saia do while. */    
    aux1 = aux1->prox;
  }
  /* É feita a liberação da variável aux2, pois como ela representa o conjunto 
  interseção de A e B e não irá mais ser usada, é preciso que esse conjunto (lista) 
  seja liberado (através da função libera, implementada anteriormente). */
  libera(aux2);
  /* No fim de tudo é retornado o conjunto C que possui o respectivo complemento relativo
  entre o conjunto A e B. */
  return C;
}
