#include "ABB.h"

Arvore *criaNoArvore(void *valor){
  // Aloca um espaço na memória para a varíavel novo (que é do tipo struct Arvore).
  Arvore *novo = (Arvore *)calloc(1, sizeof(Arvore));
  /* Verifica se novo existe, e se não existir, no caso não tiver memória para ele 
  ser alocado, printa erro e sai do programa. */
  if (!novo)
  {
    printf("ERRO");
    exit(1);
  }
  /* E e se novo existir o espaço 'info' de novo (novo->info) recebe o 'valor' 
  recebido como parâmetro pela função. E por fim, retornamos 'novo' que representará 
  o nó/folha na árvore binária de busca. */
  novo->info = valor;
  return novo;
}

void imprime(Arvore *T, int cont, void (*cb) (void *)){
  /* Realizo um 'if' para verificar se a árvore binária de busca T existe (é 
  diferente de NULL), e caso for entrará no respectivo if. */
  if (T != NULL){
    /* Faço um laço 'for' para ir printando '----' que irá representar o print 
    por nível da árvore binária de busca. */
    for (int i = 0; i <= cont; i++)
  {
    printf("----");
  }
  printf(" ");
  // Chama a função 'cb' que representa um callback que realizará a impressão do campo info.
  cb(T->info);
  printf("\n");
  /* Chama a função 'imprime' de forma recursiva para imprimir primeiramente em pre
  ordem (pela esquerda) os elementos (apenas o id) que estão na árvore. */
  imprime(T->esq, cont+1, cb);
  imprime(T->dir, cont+1, cb);
  }
}

void libera(Arvore *T, void (*liberaInfo) (void *)){
  /* Realizo um 'if' para verificar se a árvore binária de busca T existe (é 
  diferente de NULL), e caso for entrará no respectivo if. */
  if (T != NULL){
    /* Chama de forma recursiva a função 'libera' passando como parâmetros pra 
    ela a posição da direita da árvore e posteriormente a posição da esquerda, 
    e a callback para liberar todas as estruturas dentro da árvore. */
    libera(T->dir, liberaInfo);
    libera(T->esq, liberaInfo);
    /* Chama a função 'liberaInfo' que nesse caso é a callback para especificamente 
    liberar o campo 'info' da árvore. */
    liberaInfo(T->info);
    /* Por fim, da um 'free' na árvore T, desalocando toda memória anteriormente 
    alocada para ela. */
    free(T);
  }
}

void imprimeInfo(Arvore *T, void *valor, int (*cbCompara)(void *, void *), void (*cb) (void *)){
  // Cria uma variável 'arvore' que será do tipo estrutura de 'Arvore'.
  Arvore *novo;
  /* Faz com que a variável 'novo' receba a função 'buscaRec', buscando na árvore
  de busca binária o respectivo 'valor' passado como parâmetro para a função (
  nesse caso irá buscar a estrutura que está dentro da árvore). */
  novo = buscaRec(T, valor, cbCompara);
  /* Se 'novo' existir, isso quer dizer que existe uma estrutura dentro da árvore
  que poderá, nesse caso, ser impressa, portanto entrará no 'if' abaixo.  */
  if (novo != NULL){
    /* Faz com que 'cb' que será a callback para impressão receba o campo 'info' 
    de novo e com isso irá ser realizado a impressão desse campo */ 
    cb(novo->info);
  }
}

Arvore *buscaRec(Arvore *T, void *valor, int (*cbCompara)(void *, void *)){
  /* Realizo um 'if' para verificar se a árvore binária de busca T não existe (é 
  igual a NULL), e caso for entrará no respectivo if e para o passo anterior da
  recursão irá ser realizado um return NULL. */
  if (!T) return NULL;
  /* Caso o 'valor' seja igual ao campo 'T->info' (isso é garantido pela função de
  callback 'cbCompara' quando a comparação é < 0), é retornado T, pois isso quer 
  dizer que o respectivo elemento já foi encontrado. */
  else if (cbCompara(valor, T->info) < 0 ) return T; 
  /* Caso o 'valor' seja maior que o campo 'T->info' (isso é garantido pela função de
  callback 'cbCompara' quando a comparação é igual a 0), quer dizer que o elemento
  é menor logo estará para esquerda da árvore, com isso é retornado recursivamente
  a 'buscaRec' passando como parâmetro a árvore para o campo T->esq. */
  else if (cbCompara(valor ,T->info) == 0) return buscaRec(T->esq, valor, cbCompara);
  /* Caso nenhuma das condições acima for satisfeita quer dizer que o elemento
  está pela direita da árvore, logo é realizado um return de forma recursiva o 
  'buscaRec' passando como parâmetro o campo da árvore o T->dir. */
  else return buscaRec(T->dir, valor, cbCompara);
}

Arvore *insercaoRec(Arvore *T, void *valor, int (*cbCompara)(void *, void *), void (*liberaInfo) (void *)){
  /* Realizo um 'if' para verificar se a árvore binária de busca T não existe (é 
  igual a NULL), e caso for entrará no respectivo if e fará a criação do nó/folha
  do respectivo 'valor' passado como parâmetro para a função. */
  if (T == NULL) return criaNoArvore(valor);
  /* Caso o 'valor' seja diferente do campo 'T->info' (isso é garantido pela função de
  callback 'cbCompara' quando a comparação é >= 0), ele entrará no respectivo else
  if para, então, realizar as chamadas recursivas. Os dois campos precisam ser 
  diferentes, pois não é permitido alocar elementos iguais na árvore. */
  else if (cbCompara(T->info, valor) >= 0){
    /* Caso o campo 'T->info' seja maior que o 'valor' (isso é garantido pela função de
    callback 'cbCompara' quando a comparação é igual a 1), quer dizer que o elemento
    é menor logo estará para esquerda da árvore, com isso é retornado recursivamente
    a 'buscaRec' passando como parâmetro a árvore para o campo T->esq. */
    if (cbCompara(T->info, valor) == 1) T->esq = insercaoRec(T->esq, valor, cbCompara, liberaInfo);
    /* Caso a condição acima não for satisfeita quer dizer que o elemento
    está pela direita da árvore, logo é realizado um return de forma recursiva o 
    'buscaRec' passando como parâmetro o campo da árvore o T->dir. */
    else T->dir = insercaoRec(T->dir, valor, cbCompara, liberaInfo);
    /* No fim é retornado a árvore T com o respectivo elemento inserido (nesse 
    caso uma folha inserida na árvore). */
    return T;
  }
  /* Caso 'T->info' for igual a 'valor' isso quer dizer que não poderemos inserir 
  um elemento repetido na árvore, logo entrará no else. */
  else {
    /* Chama a função 'liberaInfo' que nesse caso é a callback para especificamente 
    liberar o campo 'info' da árvore. */
    liberaInfo(T->info);
    // No fim é retornado a árvore T (pois é necessário) com nenhum elemento inserido nela.
    return T;
  }
}

Arvore *removerNaArvore (Arvore *T, void *valor, int (*cbCompara)(void *, void *), void (*liberaInfo) (void *)){
  /* Realizo um 'if' para verificar se a árvore binária de busca T não existe (é 
  igual a NULL), e caso for entrará no respectivo if e para o passo anterior da
  recursão irá ser realizado um return NULL. */
  if (T == NULL) return NULL;
  /* Caso o campo 'T->info' seja maior que o 'valor' (isso é garantido pela função de
  callback 'cbCompara' quando a comparação é igual a 1), quer dizer que o elemento
  é menor logo estará para esquerda da árvore, com isso é retornado recursivamente
  a 'buscaRec' passando como parâmetro a árvore para o campo T->esq. */
  else if (cbCompara(T->info, valor) == 1)
    T->esq = removerNaArvore(T->esq, valor, cbCompara, liberaInfo);
  /* Caso o campo 'T->info' seja menor que o 'valor' (isso é garantido pela função de
  callback 'cbCompara' quando a comparação é igual a 0), quer dizer que o elemento
  é maior logo estará para direita da árvore, com isso é retornado recursivamente
  a 'buscaRec' passando como parâmetro a árvore para o campo T->dir. */
  else if (cbCompara(T->info, valor) == 0)
    T->dir = removerNaArvore(T->dir, valor, cbCompara, liberaInfo);
  /* Caso as condições acima não forem satisfeitas quer dizer que o programa achou 
  uma árvore, e com isso entrará no respectivo else abaixo. */
  else {
    /* Caso T->esq e T->dir sejam iguais a NULL quer dizer a árvore não tem folhas, 
    possui apenas a raiz. */
    if (T->esq == NULL && T->dir == NULL) {
      /* Chama a função 'liberaInfo' que nesse caso é a callback para especificamente 
      liberar o campo 'info' da árvore. */
      liberaInfo(T->info);
      /* Da um 'free' no nó T, desalocando toda memória anteriormente 
      alocada para ele. */
      free (T);
      // Faz com que T seja igual a NULL para não dar problema de memória posteriormente.
      T = NULL;
    }
    /* Caso T->esq seja NULL e T->dir seja diferente de NULL, isso quer dizer que 
    a árvore só possuirá folhas nas direita, com isso entrará no else if abaixo. */
    else if (T->esq == NULL && T->dir !=NULL) {
      // Cria uma variável 'arvore' que será do tipo estrutura de 'Arvore' e começará como T.
      Arvore  *A = T;
      // Faz T receber o campo a direita de T (T->dir), pois é nesse campo que iremos remover a folha.
      T = T->dir;
      /* Chama a função 'liberaInfo' que nesse caso é a callback para especificamente 
      liberar o campo 'info' da árvore (nesse caso libera A, pois é copia de T
      e não podemos liberar diretamente T) . */
      liberaInfo(A->info);
      /* Da um 'free' no nó A, desalocando toda memória anteriormente 
      alocada para ele. */
      free (A);
    }
    /* Caso T->dir seja NULL e T->esq seja diferente de NULL, isso quer dizer que 
    a árvore só possuirá folhas na esquerda, com isso entrará no else if abaixo. */
    else if (T->dir == NULL && T->esq != NULL) {
      // Cria uma variável 'arvore' que será do tipo estrutura de 'Arvore' e começará como T.
      Arvore *A = T;
      // Faz T receber o campo a esquerda de T (T->esq), pois é nesse campo que iremos remover a folha.
      T = T->esq;
      /* Chama a função 'liberaInfo' que nesse caso é a callback para especificamente 
      liberar o campo 'info' da árvore (nesse caso libera A, pois é copia de T
      e não podemos liberar diretamente T) . */
      liberaInfo(A->info);
      /* Da um 'free' no nó A, desalocando toda memória anteriormente 
      alocada para ele. */
      free (A);
    }
    /* Caso nenhum dos "if's" acimas sejam satisfeitos, quer dizer que a árvore
    tem folha na esquerda e na direita simultaneamente, e com isso entrará no else
    abaixo. */
    else {
      // Cria uma variável 'arvore' que será do tipo estrutura de 'Arvore' e começará como T->esq.
      Arvore *A = T->esq;
      /* Relizo um  loop while que irá percorrer toda a variável A->dir para verificar
      se realemte todo o campor da direita dessa árvore é diferente de NULL. (já
      que essa variável começa com os elementos / folhas à esquerda de T)*/
      while (A->dir != NULL) {
        A = A->dir;
      }
      /* Realizo a troca dos elementos, passando T->info para A->info, e, então, 
      permitindo que o elemento respectivo seja removido da árvore. */
      T->info = A->info;
      // Faço a variável A->info receber o 'valor'.
      A->info = valor;
      /* Faz com que T->esq receba a função 'removerNaArvore', para, então, 
      remover o respectivo elemento que estará a esquerda da árvore. */
      T->esq = removerNaArvore(T->esq,valor, cbCompara, liberaInfo);
    }
  }
  /* No fim é retornado a árvore T com o respectivo elemento removido (nesse caso 
  folha removida da árvore). */
  return T;
}
