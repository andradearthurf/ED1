#include "ABB.h"

typedef struct garrafa{
  /* Definindo a estrutura (garrafa) na qual irá conter o 'id', valor e capacidade
  que essa estrutura 'garrafa' irá ter, ela será alocada dentro do campo 'info'
  da árvore binária de busca. */
  int id;
  float valor;
  float capacidade;
}Garrafa;

/* Função do tipo ponteiro para a 'Garrafa' que recebe como parâmetro uma estrutura
de 'Garrafa' e realiza operações para criar uma nova 'Garrafa' na estrutura. Ela
retorna um novo elemento com todas as informações que a estrutura 'Garrafa' possui. */
Garrafa *criaGarrafa(Garrafa G){
  // Aloca um espaço na memória para a variável novaGarrafa (que é do tipo struct Garrafa).
  Garrafa *novaGarrafa = (Garrafa *)malloc(sizeof(Garrafa));
  // Faz com que no espaço 'id' da variável 'novaGarrafa', receba o 'id' digitado pelo usuário.
  novaGarrafa->id = G.id;
  // Faz com que no espaço 'valor' da variável 'novaGarrafa', receba o 'valor' digitado pelo usuário.
  novaGarrafa->valor = G.valor;
  // Faz com que no espaço 'capacidade' da variável 'novaGarrafa', receba a 'capacidade' digitado pelo usuário.
  novaGarrafa->capacidade = G.capacidade;
  /* Retorna a 'novaGarrafa' com o set das informações. Criando, então, uma nova 
  'Garrafa' que será inserida, posteriormente, na árvore binária de busca */
  return novaGarrafa;
}

/* Função do tipo 'int' que recebe dois ponteiros do tipo void (nesse caso é void 
pois estamos trabalhando com tipo genérico de dados). Essa função é responsável
por comparar os elementos do tipo 'Garrafa' dentro da árvore binária de busca,
retornando, então, 1 ou 0 ou -1. */
int cbCompara(void *G1, void *G2){
  /* Cria uma variável aux1 do tipo ponteiro da estrutura 'Garrafa'. Ela realiza 
  um casting, fazendo com que G1 (passado como parâmetro na função) deixe de ser
  void e vire do tipo ponteiro para 'Garrafa' através de aux1. */
  Garrafa *aux1 = (Garrafa*) G1;
  /* Cria uma variável aux2 do tipo ponteiro da estrutura 'Garrafa'. Ela realiza 
  um casting, fazendo com que G2 (passado como parâmetro na função) deixe de ser
  void e vire do tipo ponteiro para 'Garrafa' através de aux2. */
  Garrafa *aux2 = (Garrafa*) G2;

  /* Realiza um 'if' para verificar se aux1->id (o campo id de aux1) é maior que 
  o campo id de aux2 (aux2->id), se for menor a função retornará 1. */
  if (aux1->id > aux2->id) return 1;
  /* Realiza um 'if' para verificar se aux1->id (o campo id de aux1) é menor que 
  o campo id de aux2 (aux2->id), se for menor a função retornará 0. */
  else if (aux1->id < aux2->id) return 0;
  /* Caso os dois "if's" acima não forem satisfeitos, entrará no else e, então, 
  retornará -1, pois provavelmente os dois elementos serão iguais. */
  else return -1; 
}

/* Função do tipo 'void' que recebe um ponteiro do tipo void (nesse caso é void
pois estamos trabalhando com tipo genérico de dados). Essa função é responsável 
por liberar memória (dar free) nos elementos que são do tipo 'Garrafa' e estarão
dentro da árvore binária de busca (essa função servirá de callback). */
void liberaInfo(void *G){ 
  /* Cria uma variável aux do tipo ponteiro da estrutura 'Garrafa'. Ela realiza 
  um casting, fazendo com que G (passado como parâmetro na função) deixe de ser
  void e vire do tipo ponteiro para 'Garrafa' através de aux. */
  Garrafa *aux = (Garrafa *) G;
  /* Da um free em 'aux', fazendo com que a memória alocada para ele seja 
  liberada e desalocada. */
  free(aux);
}

/* Função do tipo 'void' que recebe um ponteiro do tipo void (nesse caso é void
pois estamos trabalhando com tipo genérico de dados). Essa função é responsável
por imprimir todos os dados da estrutura 'Garrafa' que estrá no campo 'info' da
árvore binária de busca (essa função servirá de callback). */
void cbImprime(void *G){
  /* Cria uma variável aux do tipo ponteiro da estrutura 'Garrafa'. Ela realiza 
  um casting, fazendo com que G (passado como parâmetro na função) deixe de ser
  void e vire do tipo ponteiro para 'Garrafa' através de aux. */
  Garrafa *aux = (Garrafa*) G;
  // Reliza o print do respectivo 'id' na estrutura 'Garrafa'. 
  printf("\nid: %d\n", aux->id);
  // Reliza o print do respectivo 'valor' na estrutura 'Garrafa'. 
  printf("Valor: %.2f\n",aux->valor);
  // Reliza o print da respectiva 'capacidade' na estrutura 'Garrafa'. 
  printf("Capacidade (ml): %.2f\n", aux->capacidade);
}

/* Função do tipo 'void' que recebe um ponteiro do tipo void (nesse caso é void
pois estamos trabalhando com tipo genérico de dados). Essa função é responsável
por imprimir apenas o 'id' da estrutura 'Garrafa' (essa função servirá de callback).  */
void cbImprimeId(void *G){
  /* Cria uma variável aux do tipo ponteiro da estrutura 'Garrafa'. Ela realiza 
  um casting, fazendo com que G (passado como parâmetro na função) deixe de ser
  void e vire do tipo ponteiro para 'Garrafa' através de aux. */
  Garrafa *aux = (Garrafa*) G;
  // Reliza o print do respectivo 'id' na estrutura 'Garrafa'.
  printf("Id: %d", aux->id);
}

/* Função do tipo 'void' que recebe um ponteiro do tipo estrutura de 'Arvore' e
um int 'id' (que será o id que iremos buscar e imprimir os dados da respectiva 
estrutura que contém esse id). Essa função é responsável por fazer a busca do 
elemento na árvore através do 'id' e imprimir as informações do elemento buscado. */
void imprimeGarrafa(Arvore *T, int id){
  // Cria uma variável 'garrafa' que será do tipo estrutura 'Garrafa'.
  Garrafa garrafa;
  /* Faz com que o campo 'id' da variável 'garrafa' receba o id passado como 
  parâmetro na função. */
  garrafa.id = id;
  /* Realiza um 'if' para verifica (com a função de 'buscaRec') se aquele elemento 
  realmente existe na árvore, e se não existir ele entrará no if e realizará o 
  print. */
  if (buscaRec(T, &garrafa, cbCompara) == NULL){
    printf("\nElemento nao existe.\n");
  }
  /* Caso o elemento realmente esteja na árvore binária de busca, entrará no else 
  e chamará a função 'imprimeInfo' que realizará o print de todas as informações 
  que a estrutura 'Garrafa' possui. */
  else imprimeInfo(T, &garrafa, cbCompara, cbImprime);
}

/* Função do tipo ponteiro para 'Arvore' que recebe como parâmetro um ponteiro do
tipo estrutura de 'Garrafa' e outro do tipo 'Arvore'. Essa função é responsável por
inserir um elemento do tipo 'Garrafa' na árvore de busca binária, e retornar
a árvore com o elemento inserido.  */
Arvore *insereGarrafa(Garrafa *G, Arvore *T){
  /* Realiza um 'if' para verifica (com a função de 'buscaRec') se aquele elemento 
  realmente existe na árvore, e se não existir ele entrará no if e realizará a 
  inserção com a função 'insercaoRec' e realizara, também, o print. */
  if (buscaRec(T, G, cbCompara) == NULL){
    printf("\nElemento inserido com sucesso.\n");
    /* Realiza o return chamando a função 'insercaoRec' para inserir o respectivo
    elemento (estrutura) na árvore binária de busca. */
    return insercaoRec(T, G, cbCompara, liberaInfo);
  }
  /* Caso já exista o respectivo elemento (estrutura com id igual) não será possivel 
  inserir esse elemento repetidamente, logo entrará no else e realizará o print 
  informando. */
  else printf("\nErro. Elemento ja existe!\n");
  // No final é retornado a estrutura T que é representado pela árvore binária de busca.
  return T;
}

/* Função do tipo ponteiro para 'Arvore' que recebe como parâmetro um ponteiro
do tipo estrutura de 'Garrada' e um int 'id'. Essa função é responsável por remover
o elemento (estrutura garrafa) da árvore binária de busca através do 'id' que
irá ser passado como parâmetro para a função, e retornar a árvore com o elemento 
removido. */
Arvore *removeGarrafa(Arvore *T, int id){
  // Cria uma variável 'garrafa' que será do tipo estrutura 'Garrafa'.
  Garrafa garrafa;
  /* Faz com que o campo 'id' da variável 'garrafa' receba o id passado como 
  parâmetro na função. */
  garrafa.id = id;
  /* Realiza um 'if' para verifica (com a função de 'buscaRec') se aquele elemento 
  realmente existe na árvore, e se existir ele entrará no if e realizará a remoçãp
   com a função 'removerNaArvore' e realizará, também, o print. */
  if (buscaRec(T, &garrafa, cbCompara)){
    /* Faz T (que é a árvore) receber a função de remoção para remover o respectivo 
    elemento através do 'id' (por dentro dessa função ela já retorna a árvore com 
    o elemento removido). */
    T = removerNaArvore(T, &garrafa, cbCompara, liberaInfo);
    printf("\nElemento removido com sucesso.\n");
  }
  /* Caso não exista o respectivo elemento (id inexistente) não será possivel 
  remover esse elemento, logo entrará no else e realizará o print informando. */
  else printf("\nElemento nao existe.\n");
  // No final é retornado a estrutura T que é representado pela árvore binária de busca.
  return T;
}

/* Função do tipo void que recebe uma estrutura 'Arvore' e um int op (que será a 
opção para o switch case). Essa função é responsável por apresentar um switch case com 
opções para utilizar as funções implementadas no decorrer do código. */
void menu(Arvore **T, int op){
  // Criando as variáveis que serão lidas para executar as respectivas funções.
  // Essas variáveis representarão o campo 'info' da árvore de busca binária.
  int id;
  float valor, capacidade;
  // Cria uma variável 'garrafa' que será do tipo estrutura 'Garrafa'.
  Garrafa G;
  
  /* Faremos um switch case para solicitar a quem irá usar o programa a função 
  que deseja utilizar. */
  switch (op){
  case 1:
    /* Caso ele digite '1' irá ser realizado as devidas leituras e chamará a 
    função 'insereGarrafa', para inserir essa estrutura na árvore binária de busca. */
    printf("\nInserindo uma garrafa...\n");
    printf("Digite o id que deseja inserir: ");
    scanf("%d", &id);
    G.id = id;
    printf("Digite o valor da garrafa: ");
    scanf("%f", &valor);
    G.valor = valor;
    printf("Digite a capacidade da garrafa: ");
    scanf("%f", &capacidade);
    G.capacidade = capacidade;
    Garrafa *garrafa = criaGarrafa(G);
    *T = insereGarrafa( garrafa, *T);
    break;

  case 2:
    /* Caso ele digite '2' irá ser realizado as devidas leituras e chamará a 
    função 'imprimeGarrafa', para imprimir as informações dessa estrutura que 
    está na árvore binária de busca. */
    printf("\nBuscando uma garrafa...\n");
    printf("Digite o id da garrafa que deseja buscar: ");
    scanf("%d", &id);
    imprimeGarrafa(*T, id);
    break;

  case 3:
    /* Caso ele digite '3' irá ser realizado as devidas leituras e chamará a 
    função 'removeGarrafa', para remover a estrutura que está na árvore binária 
    de busca. */
    printf("\nRemovendo uma garrafa...\n");
    printf("Digite o id da garrafa que deseja buscar: ");
    scanf("%d", &id);
    *T = removeGarrafa(*T, id);
    break;

  case 4:
    /* Caso ele digite '4' irá ser realizado as devidas impressões e chamará a 
    função 'imprime', para imprimir todas as estruturas que estão na árvore binária 
    de busca (pelo seu respectivo id). */
    printf("\nImprimindo a arvore...\n");
    if (*T == NULL){
      printf("\nA arvore esta vazia\n");
    }
    else imprime(*T, 1, cbImprimeId);
    printf("\n");
    break;

  default:
    break;
  }
}

int main(){
  // Cria uma variável 'arvore' que será do tipo estrutura de 'Arvore' e começará como NULL.
  Arvore *arvore = NULL;
  // Definimos a variável 'op' que irá ser lida pela função 'menu'.
  int op;
  
  // 'do while' para fazer um menu de opções repetidas vezes até que o usuário deseje sair dele.
  do{
    printf("\n1 - Inserir um elemento: \n");
    printf("2 - Buscar um elemento: \n");
    printf("3 - Excluir um elemento: \n");
    printf("4 - Imprimir a arvore: \n");
    printf("5 - Sair: \n");
    scanf("%d", &op);
    printf("\n");

  /* Caso op esteja entre 1 e 4 chamamos a função menu, caso contrário eu chamo
  novamente as opções até o usuário digitar uma opção válida.*/
  if (op >= 1 && op <= 4) menu(&arvore, op);

  }while (op != 5);// Quando op for 14 eu saio do programa.

  /* Utilizo a função 'libera', para que no fim do programa eu desaloque toda a 
  memória alocada para essa árvore binária de busca. */
  libera(arvore, liberaInfo);

  return 0;
}