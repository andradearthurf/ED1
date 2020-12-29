#include <stdio.h>
#include <stdlib.h>

typedef struct pol{
  /* Definindo a estrutura (pol) na qual irá conter os respectivos polinômios em uma
  lista simplesmente encadeada. Essa estrutura possui um coef (coeficiente), expo
  (expoente) e um ponteiro para o prox (para o próximo elemento da lista). */
  int coef;
  int expo;
  struct pol *prox;
} Pol;

/* Função que cria um nó na lista simplesmente encadeada, recebendo como parâmetros
o coeficiente e o expoente para essa lista. */
Pol *criaNo(int coef, int expo){

  // Aloca um espaço na memória para a varíavel novo (que é do tipo struct Pol).
  Pol *novo = (struct pol *)malloc(sizeof(struct pol));

  /* Verfica se novo existe, e se existir o espaço de coef de novo (novo->coef) 
  recebe o coef recebido como parâmetro pela função, o mesmo acontece para expo. 
  Já o espaço para prox de novo (novo->prox) recebe NULL. */
  if (novo){
    novo->coef = coef;
    novo->expo = expo;
    novo->prox = NULL;
  }

  /* Se novo não existir, no caso não tiver memória para ele ser alocado, printa
  erro e sai do programa. */
  else{
    printf("Erro");
    exit(1);
  }

  // No final retorna a lista com a criação de seu nó nela.
  return novo;
}

/* Função que libera o espaço de memória que foi alocado anteriormente para uma
respectiva lista encadeada.*/
void LiberaPolinomio(Pol *p){

  // Crio uma cópia para a lista que irá apontar para o início dela.
  Pol *aux = p;

  // Equanto aux existir eu percorrerei todo a lista até ele ser NULL.
  while (aux){

    // Crio a variável 'removido' e faço ela receber aux (que nesse caso aponta pro início da lista).
    Pol *removido = aux;

    // Percorrer aux até ele ser igual a NULL e sair do while.
    aux = aux->prox;

    // Dou um free em removido, liberando todo o espaço de memória da respectiva lista.
    free(removido);
    }
}

/* Função que busca em uma lista ordenada o expo (expoente) dela e o retorna por
final. O que faciliará para inserir ordenamente na lista. */
Pol *buscaListaOrd(Pol *p, int expo, Pol **pred){

  /* Cria uma variável aux do tipo ponteiro da estrutura Pol. Ela irá ser o nó
  cabeça da lista, pois recebe o próximo da lista p (fazendo com que a lista 
  nunca seja vazia e aponte sempre para o nó cabeça). */
  Pol *aux = p->prox;

  /* A variável pred (predecessora) irá receber o início da lista. Como aux 
  recebe o próximo, pred receberá o 'atual'. */
  (*pred) = p;

  /* Enquanto a variável aux for diferente de NULL iremos percorrer toda a lista
  em busca de encontrar o expo. */
    while (aux != NULL){

      /* Se expo for maior que aux->expo isso quer dizer que achamos expo. Daremos
      um break para sair do while e retornaremos aux que é expo. */
      if (expo > aux->expo) break;

      /* Se o if acima não for satisfeito faremos com que a variável pred receba
      o valor atual (nesse caso será aux). */
      (*pred) = aux;

      /* Percorreremos aux (que aponta para o próximo da lista p) até que seja
      NULL e saia do while, ou até achar expo. */
      aux = aux->prox;
    }

  // Retorna aux no final de tudo.  
  return aux;
}

/* Função que insere ordenadamente o coeficiente (coef) e o expoente (expo) em
uma lista simplesmente encadeada (o que formará um polinômio). */
void insereOrd (Pol *p, int coef, int expo) {

  // Cria uma variável novo que irá ser do tipo ponteiro de Pol, e receberá um nó com coef e expo.
  Pol *novo = criaNo(coef, expo);

  // Definide pred começando como NULL.
  Pol *pred = NULL;

  // Faz com que aux receba o valor de expo buscado através da função buscaListaOrd. 
  Pol *aux = buscaListaOrd(p, expo, &pred);

  // O campo prox da lista 'novo' que contém um nó receberá aux (que nesse caso será o expo).
  novo->prox = aux;

  // O campo prox da variável pred (do tipo ponteiro de Pol) receberá novo.
  pred->prox = novo;
}

/* Função que recebe como parâmetro uma lista p1 (que no caso é um polinômio)
e soma os termos de mesmo expoente nesse polinômio, o que ajudará nas funções
de soma, subtração e multiplicação de polinômios. */
Pol *simplifica(Pol *p1){

  /* Define uma variável aux que será o nó cabeça dessa lista simplesmente encadeada,
  com isso a lista nunca será vazia e sempre apontará para o nó cabeça. */
  Pol *aux = p1->prox;

  /* Definine pred (predecessor) como o inicio da lista. Como o aux aponta para o
  próximo, pred irá ser o elemento 'atual'. */
  Pol *pred = p1;
  
  /* Cria uma lista p2 que irá ser do tipo struct Pol, como estamos trabalhando 
  com nó cabeça temos que alocar um espaço na memória para essa lista usando a 
  ferramenta calloc. */
  Pol *p2 =  (Pol *)calloc(1, sizeof(Pol));
  
  /* Define uma variável soma que irá começar com zero e somará os elementos, 
  na lista, de mesmo expoente*/
  int soma = 0;

  /* Enquanto a varável aux, que é o nó cabeça, existir iremos percorrer a lista e
  somar os elementos de mesmo expoente verificando cada caso. */
  while (aux){

    /* Esse 'if' é responsavel por testar se aux->prox (se tem um elemento próximo)
    existe e se existir ele verifica se o expoente 'atual' é igual ao 'próximo 
    expoente'. */
    if (aux->prox && aux->expo == aux->prox->expo){
      
      /* Se o 'if' for verdade ele realiza a acumulação da variável soma com o 
      coefiente, já que possuem mesmos expoentes e podemos somar seus coeficientes*/
      soma += aux->coef;
    }

    // Se os casos do 'if' acima não forem verdadadeiros cairá no 'else'
    else{

      // Testaremos novamente se existe um próximo elemento, pois não podemos somar NULL.
      if (aux->prox){

        // Se o 'if' for verdade ele faz a acumulação da variável 'soma' com o coeficiente.
        soma += aux->coef;

        /* Caso a soma for diferente de zero, pois é desnecessário colocar termos
        de valor 0 no nosso polinômio, ele insere ordenado a soma como parâmetro
        e o valor do expoente correspondente à soma que é aux->expo. */
        if (soma != 0) insereOrd(p2, soma, aux->expo);

        // Zera a variável soma para ser usada novamente em outros casos.
        soma = 0;
      }

      // Nesse 'else if' testaremos se o expoente atual é igual ao proximo expoente. 
      else if (pred->expo == aux->expo){

        /* Se o 'esle if' for verdade faremos a acumulação da variável soma com
        o coeficente já que os expoentes irão ser iguais. */
        soma += aux->coef;

        /* Caso a soma for diferente de zero, pois é desnecessário colocar termos
        de valor 0 no nosso polinômio, ele insere ordenado a soma como parâmetro
        e o valor do expoente correspondente à soma que é pred->expo. */
        if (soma != 0) insereOrd(p2, soma, pred->expo);
      }

      /* Se não cair nem no 'if' nem no 'else if', cairemos no else. Isso quer 
      dizer que ambos foram falsos. */
      else{

        /* Caso a soma for diferente de zero, pois é desnecessário colocar termos
        de valor 0 no nosso polinômio, ele insere ordenado a soma como parâmetro
        e o valor do expoente correspondente à soma que é pred->expo. */
        if (soma != 0) insereOrd(p2, soma, pred->expo);

        /* Caso o coeficiente do 'último' elemento for diferente de zero iremos
        inseri-lo ordenado como coeficiente e expoente (nesse caso não tem nenhum
        elemento para juntar com esse elemento, o expoente dele é só dele). */
        if (aux->coef != 0) insereOrd(p2, aux->coef, aux->expo);
      }
    }

    // Fazemos com que pred receba aux, para andarem juntos percorendo a lista.
    pred = aux;

    /* Percorreremos aux (que aponta para o próximo da lista p) até que seja
    NULL e saia do while, ou até que umas das condições seja aceita e saia, 
    então, do while. */
    aux = aux->prox;
  }
  
  // Liberamos o espaço da memória alocado para p1.
  LiberaPolinomio(p1);

  /* Retornaremos no final a lista simplificada, com os termos de mesmo 
  expoentes somados. */
  return p2;
}

// Função que recebe dois polinômios (p1 e p2) e retorna a soma deles.
Pol *somaPol(Pol *p1, Pol *p2){

  /* Define uma variável aux1 que será o nó cabeça da lista p1 simplesmente encadeada,
  com isso a lista nunca será vazia e sempre apontará para o nó cabeça. */
  Pol *aux1 = p1->prox;  

  /* Define uma variável aux2 que será o nó cabeça da lista p2 simplesmente encadeada,
  com isso a lista nunca será vazia e sempre apontará para o nó cabeça. */
  Pol *aux2 = p2->prox; 

  /* Cria uma lista p3 que irá ser do tipo struct Pol, como estamos trabalhando 
  com nó cabeça temos que alocar um espaço na memória para essa lista usando a 
  ferramenta calloc. */
  Pol *p3=  (Pol *)calloc(1, sizeof(Pol));

  /* Enquanto aux1 existir iremos inserir ordenado todos os elementos (coef e 
  expo) da lista p1 (através de aux1) na lista p3.*/
  while (aux1){
    insereOrd(p3, aux1->coef, aux1->expo);

    // Percorrer aux1 até ele ser igual a NULL e saia do while.
    aux1 = aux1->prox;
  }

  /* Enquanto aux2 existir iremos inserir ordenado todos os elementos (coef e 
  expo) da lista p2 (através de aux2) na lista p3.*/
  while (aux2){
    insereOrd(p3, aux2->coef, aux2->expo);

    // Percorrer aux2 até ele ser igual a NULL e saia do while.
    aux2 = aux2->prox;
  }

  /* Como ja temos a lista p3 com as duas listas juntas (p1 e p2), basta juntar as duas 
  listas somando, com a função simplifica. */

  // Liberamos o espaço da memória alocado para p1.
  LiberaPolinomio(p1);

  // Liberamos o espaço da memória alocado para p3.
  LiberaPolinomio(p2);

  /* Simplificamos a lista p3, nesse caso somaremos a lista p1 com p2 (os termos 
  de mesmo expoente), o que resultará na soma dos dois polinômios. */
  p3 = simplifica(p3);

  // Retornaremos no final a lista p3 com a soma dos dois polinômios. 
  return p3;
}

// Função que recebe dois polinômios (p1 e p2) e retorna a subtração deles.
Pol *subtraiPol(Pol *p1, Pol *p2){

  /* Define uma variável aux1 que será o nó cabeça da lista p1 simplesmente encadeada,
  com isso a lista nunca será vazia e sempre apontará para o nó cabeça. */
  Pol *aux1 = p1->prox;  

  /* Define uma variável aux2 que será o nó cabeça da lista p2 simplesmente encadeada,
  com isso a lista nunca será vazia e sempre apontará para o nó cabeça. */
  Pol *aux2 = p2->prox; 

  /* Cria uma lista p3 que irá ser do tipo struct Pol, como estamos trabalhando 
  com nó cabeça temos que alocar um espaço na memória para essa lista usando a 
  ferramenta calloc. */
  Pol *p3=  (Pol *)calloc(1, sizeof(Pol));

  /* Enquanto aux1 existir iremos inserir ordenado todos os elementos (coef e 
  expo) da lista p1 (através de aux1) na lista p3.*/
  while (aux1){
    insereOrd(p3, aux1->coef, aux1->expo);

    // Percorrer aux1 até ele ser igual a NULL e saia do while.
    aux1 = aux1->prox;
  }

  /* Enquanto aux2 existir iremos inserir ordenado todos os elementos (coef e 
  expo) da lista p2 (através de aux2) na lista p3.*/
  while (aux2){

    /* Porém como iremos fazer a subtração de p1 - p2 temos que passa os 
    coeficientes de p2 como negativos, para na hora de juntar obter a subtração 
    dos polinômios*/
    insereOrd(p3, -aux2->coef, aux2->expo);

    // Percorrer aux2 até ele ser igual a NULL e saia do while.
    aux2 = aux2->prox;
  }

  // Liberamos o espaço da memória alocado para p1.
  LiberaPolinomio(p1);

  // Liberamos o espaço da memória alocado para p2.
  LiberaPolinomio(p2);

  /* Simplificamos a lista p3, nesse caso faremos a junção da lista p1 com 
  p2, o que resultará na subtração de p1 com p2. */
  p3 = simplifica(p3);

  // Retornaremos no final a lista p3 com a subtração dos dois polinômios. 
  return p3;
}

// Função que recebe dois polinômios (p1 e p2) e retorna a multiplicação deles.
Pol *multiplicaPol (Pol *p1, Pol *p2){

  /* Define uma variável aux1 que será o nó cabeça da lista p1 simplesmente encadeada,
  com isso a lista nunca será vazia e sempre apontará para o nó cabeça. */
  Pol *aux1 = p1->prox;

  /* Define uma variável aux2 que será o nó cabeça da lista p2 simplesmente encadeada,
  com isso a lista nunca será vazia e sempre apontará para o nó cabeça. */
  Pol *aux2 = p2->prox;

  /* Cria uma lista p3 que irá ser do tipo struct Pol, como estamos trabalhando 
  com nó cabeça temos que alocar um espaço na memória para essa lista usando a 
  ferramenta calloc. */
  Pol *p3 =  (Pol *)calloc(1, sizeof(Pol));
  
  /* Deifinimos as variáveis coef e expo para armazenarmos a multiplicação dos 
  coeficientes e a soma dos expoentes. */
  int coef;
  int expo;

  /* Enquanto aux1 e aux2 existir iremos percorrer os polinômios (as listas p1 
  e p2) simultâneamente e com isso realizar a multiplicação dos coeficientes do 
  polinômio p1 como polinômio p2 e somar seus respectivos expoentes. Em seguida 
  iremos inserir ordenadamente esses valores econtrados na lista p3. */
  while (aux1){
    aux2 = p2->prox;
    while(aux2){
      coef = aux1->coef * aux2->coef;
      expo = aux1->expo + aux2->expo;
      insereOrd(p3, coef, expo);

      // Percorrer aux2 até ele ser igual a NULL e saia do while.
      aux2 = aux2->prox;
    }

    // Percorrer aux1 até ele ser igual a NULL e saia do while.
    aux1 = aux1->prox;
  }

  // Liberamos o espaço da memória alocado para p1.
  LiberaPolinomio(p1);

  // Liberamos o espaço da memória alocado para p2.
  LiberaPolinomio(p2);

  /* Simplificaremos a lista p3, nesse caso faremos a junção (soma) dos coeficientes
  que possuem os mesmos expoentes, e com isso tornar o polinômio simplificado. */
  p3 = simplifica(p3);

  // Retornaremos no final a lista p3 com a multiplicação dos dois polinômios. 
  return p3;
  
}

// Função que imprime um polinômio.
void imprime (Pol *p){

  /* Define uma variável aux que será o nó cabeça da lista p simplesmente encadeada,
  com isso a lista nunca será vazia e sempre apontará para o nó cabeça. */
  Pol *aux = p->prox;

  // Se aux não existir isso quer dizer que a lista está vazia, logo irá realizar o print.
  if (aux == NULL){
    printf("Polinomio nulo\n");
  }

  /* Enquanto aux existir iremos percorrer a lista p completamente e printar 
  seus termos (coef e expo). */
  while (aux){

    /* Realizando verificaçãoes primeiramente para colocar o 'x^' se o expoente
    for diferente de 0, caso contrário não irá colocar. Posteriormente é realizado
    verificações se o coeficiente é positivo, caso verdadeiro é inserido um sinal
    '+' na frente dele, caso contrário não se insere nada e deixa ele com o sinal
    natural (nesse caso negativo). */ 
    if (aux->expo != 0){
      if (aux->coef > 0) printf("+ ");
      else printf(" ");
      printf("%dx^%d ", aux->coef, aux->expo);

      // Percorrer aux até ele ser igual a NULL e saia do while.
      aux = aux->prox;
    }
    else{
      if (aux->coef > 0) printf("+ ");
      else printf("");
      printf("%d ", aux->coef);

      // Percorrer aux até ele ser igual a NULL e saia do while.
      aux = aux->prox;
    }
  }
  printf("\n\n");
}

/* Função que mostra um menu com opções para escolher entre as funções de soma,
subtração e multiplicação de polinômios. */
void menu(int op){

  /* Cria uma lista p1 que irá ser do tipo struct Pol, como estamos trabalhando 
  com nó cabeça temos que alocar um espaço na memória para essa lista usando a 
  ferramenta calloc. */
  Pol *p1 = (Pol *)calloc(1, sizeof(Pol)); 
  
  /* Cria uma lista p2 que irá ser do tipo struct Pol, como estamos trabalhando 
  com nó cabeça temos que alocar um espaço na memória para essa lista usando a 
  ferramenta calloc. */
  Pol *p2 = (Pol *)calloc(1, sizeof(Pol));

  /* Definimos a lista p3 como NULL, já que apenas vamos guardar nela as operações
  entre os polinômios p1 e p2, e posteriormente a retornaremos. */
  Pol *p3 = NULL;

  // Define as variávies coef e expo que serão lidas e inseridas nas respectivas listas.
  int coef, expo;

  /* Nesse trecho de código (da linha 441 até a 452) o programa lê o coeficiente
  e o exponte e insere ordenado na lista até que um valor seja zero e com isso a 
  leitura irá ser interrompida. */ 
  printf("\nDigite o coefiente e o expoente na mesma linha do primeiro polinomio: \n");
  do{
    scanf("%d %d", &coef, &expo);
    insereOrd(p1 , coef, expo);
  }while (coef != 0 || expo != 0);

  printf("\n");

  printf("\nDigite o coefiente e o expoente na mesma linha do segundo polinomio: \n");
  do{
    scanf("%d %d", &coef, &expo);
    insereOrd(p2 , coef, expo);
  }while (coef != 0 || expo != 0);

  // Faremos um switch case pedindo qual operação ele deseja realizar com os polinômios.
  switch (op)
  {
  case 1:
    // Chamando a função somaPol e a aplicando nos polinômios p1 e p2.
    p3 = somaPol(p1, p2);
    printf("\nA soma dos polinomios sera: ");
    break;
  
  case 2:
    // Chamando a função subtraiPol e a aplicando nos polinômios p1 e p2.
    p3 = subtraiPol(p1 ,p2);
    printf("\nA subtracao dos polinomios sera: ");
    break;
  
  case 3:
    // Chamando a função multiplicaPol e a aplicando nos polinômios p1 e p2.
    p3 = multiplicaPol(p1, p2);
    printf("\nA multiplicacao dos polinomios sera: ");
    break;

  default:
    break;
  }

  // Imprimiremos o polinômio resultante (p3).
  imprime(p3);

  // Liberamos o espaço da memória alocado para o polinômio p3.
  LiberaPolinomio(p3);
}

int main(){

  // Definimos a variável 'op' que irá ser lida pela função 'menu'.
  int op;

  // 'do while' para fazer um menu de opções repetidas vezes até que o usuário deseje sair dele.
  do{
    printf("1 - Somar dois polinomios: \n");
    printf("2 - Subtrair dois polinomios: \n");
    printf("3 - Multiplicar dois polinomios: \n");
    printf("4 - Sair : \n");
    scanf("%d", &op);
  
    /* Caso op esteja entre 1 e 3 chamamos a função menu, caso contrário eu chamo
    novamente as opções até o usuário digitar uma opção válida.*/
    if (op >= 1 && op <= 3) menu(op);
   
  }while (op != 4); // Quando op for 4 eu saio do programa. 

  return 0;
}