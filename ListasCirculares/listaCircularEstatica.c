#include <stdio.h>
#include <stdlib.h>

/* Função que recebe o vetor, elemento que você quer inserir e o tamanho do vetor. 
Recebe também um ponteiro ocupado que representa quando a lista está cheia ou não, 
um ponteiro pro início da lista e um pro fim. E por fim, a função insere o 
respectivo elemento no início da lista.*/
void inserirInicio(int *vet, int elemento, int tam, int *ocupado, int *inicio, int *fim){
  /* Realizo um 'if' para verificar se o tamanho do vetor é maior que 0, pois
  só é permitido inserir elementos na lista se o vetor tiver um tamanho inteiro 
  positivo diferente de zero. Se 'tam' for maior que zero ele entrará no 'if' e
  executará os devidos comandos. */
  if (tam > 0){
    /* Realiza um 'if' para verificar se a variável ocupado é igual a zero (correspondendo
    que o vetor está vazio caso seja zero). Se ocupado for igual a zero ele entrará no if. */
    if ((*ocupado) == 0){
      /* Como o vetor não possui elementos, posso inserir o primeiro elemento na 
      posição 'inicio', já que realmente ele será inserido no início. */
      vet[*inicio] = elemento;
      /* Faço com que 'fim' e 'inicio' sejam igual (começem na mesma posição), pois 
      é uma lista circular. */
      *fim = *inicio;
      /* Atualizo a variável 'ocupado', pois agora o vetor não estará vazio e ocupado 
      não pode mais valer zero.*/
      (*ocupado)++;
      // Realizo o print informando que o elemento foi inserido com sucesso.
      printf("Elemento inserido no inicio com sucesso!\n\n");
    }
    /* Caso 'ocupado' não seja igual a zero (quer dizer que o vetor está ocupado 
    e que existe elementos nele), ele entrará no else abaixo. */
    else{
      /* Realiza um 'if' para verificar se a variável 'ocupado' é menor que o tam 
      (tamanho do vetor), se realmente for menor irá entra no 'if'. Isso serve 
      para verificar se o vetor está totalmente cheio ou não. */
      if ((*ocupado) < tam){
        /* Realiza um decremento na variável 'inicio' fazendo com que ela se desloque 
        uma posição para trás. */
        (*inicio)--;
        // Atualiza a variável 'ocupado', pois iremos inserir um elemento no vetor. 
        (*ocupado)++;
        /* Realiza um 'if' para verificar se a variável 'inicio' é menor que zero, 
        e se for negativo isso mostra que estamos inserindo uma posição anterior ao 
        início da lista (como é uma lista circular, isso representa o final da lista). */ 
        if ((*inicio) < 0){
          /* Se 'inicio' for menor que zero entrará no 'if' e com isso a variável 
          'inicio' deve receber 'tam - 1' que significa a posição final dessa lista. 
          Fazemos isso pois a posição anterior a posição inicial da lista é equivalente, 
          em uma lista cirular, a posição final dessa lista ('inicio' agora valerá 
          como se fosse a posição final da lista) */
          (*inicio) = tam - 1;
        }
      // Atribuiremos 'vet' na posição 'inicio' o elemento que queremos inserir no início.
      vet[*inicio] = elemento;
      // Realizo o print informando que o elemento foi inserido com sucesso.
      printf("Elemento inserido no inicio com sucesso!\n\n");
      }
      /* Caso 'ocupado' não for menor que o 'tam' (tamanho do vetor), quer dizer 
      que o vetor ja está cheio (pois 'ocupado' irá ser igual ao tamanho do vetor), 
      e então entraremos no else. */
      else{
        // Realizo o print informando que o vetor está cheio.
        printf("O vetor esta cheio!\n\n");
      }
    }
  }
  /* No caso do tamanho digitado pelo úsuario for menor ou igual a zero ele entrará 
  no else e realizará o print */
  else{
    printf("O vetor nao tem espaco para colocar elementos!\n\n");
  }
}

/* Função que recebe o vetor, elemento que você quer inserir e o tamanho do vetor. 
Recebe também um ponteiro ocupado que representa quando a lista está cheia ou não, 
um ponteiro pro início da lista e um pro fim. E por fim, a função insere o 
respectivo elemento no final da lista.*/ 
void inserirFim(int *vet, int elemento, int tam, int *ocupado, int *inicio, int *fim){
  /* Realizo um 'if' para verificar se o tamanho do vetor é maior que 0, pois
  só é permitido inserir elementos na lista se o vetor tiver um tamanho inteiro 
  positivo diferente de zero. Se 'tam' for maior que zero ele entrará no 'if' e
  executará os devidos comandos. */
  if (tam > 0){
    /* Realiza um 'if' para verificar se a variável ocupado é igual a zero (correspondendo
    que o vetor está vazio caso seja zero). Se ocupado for igual a zero ele entrará no if. */
    if ((*ocupado) == 0){
      /* Como o vetor não possui elementos, posso inserir o primeiro elemento na 
      posição 'fim', já que realmente ele será inserido no final. */
      vet[*fim] = elemento;
      /* Faço com que 'fim' e 'inicio' sejam igual (começem na mesma posição), pois 
      é uma lista circular. */
      *fim = *inicio;
      /* Atualizo a variável 'ocupado', pois agora o vetor não estará vazio e ocupado 
      não pode mais valer zero.*/
      (*ocupado)++;
      // Realizo o print informando que o elemento foi inserido com sucesso.
      printf("Elemento inserido no fim com sucesso!\n\n");
    }
    /* Caso 'ocupado' não seja igual a zero (quer dizer que o vetor está ocupado 
    e que existe elementos nele), ele entrará no else abaixo. */
    else{
      /* Realiza um 'if' para verificar se a variável 'ocupado' é menor que o tam 
      (tamanho do vetor), se realmente for menor irá entra no 'if'. Isso serve 
      para verificar se o vetor está totalmente cheio ou não. */
      if ((*ocupado) < tam){
        /* Realiza um incremento na variável 'fim' fazendo com que ela se desloque 
        uma posição para frente. */
        (*fim)++;
        // Atualiza a variável 'ocupado', pois iremos inserir um elemento no vetor. 
        (*ocupado)++;
        /* Realiza um 'if' para verificar se a variável 'fim' é igual ao 'tam' (tamanho do vetor), 
        e se for igual isso mostra que estamos inserindo uma posição depois ao 
        fim da lista (o fim da lista é representado como 'tam - 1'). */
        if ((*fim) == tam){
          /* Se 'fim' for igual a 'tam' entrará no 'if' e com isso a variável 
          'fim' deve receber 0 que significa a posição inicial dessa lista. Fazemos 
          isso, pois como estamos em uma lista circular a posição depois da posição 
          final do vetor corresponde a posição 'inicio' dessa lista ('fim' agora 
          valerá como se fosse a posição inicial da lista) */
          (*fim) = 0;
        }
        // Atribuiremos 'vet' na posição 'fim' o elemento que queremos inserir no final.
        vet[*fim] = elemento;
        // Realizo o print informando que o elemento foi inserido com sucesso.
        printf("Elemento inserido no fim com sucesso!\n\n");
      }
      /* Caso 'ocupado' não for menor que o 'tam' (tamanho do vetor), quer dizer 
      que o vetor ja está cheio (pois 'ocupado' irá ser igual ao tamanho do vetor), 
      e então entraremos no else. */
      else{
        // Realizo o print informando que o vetor está cheio.
        printf("O vetor esta cheio!\n\n");
      }
    }
  }
  /* No caso do tamanho digitado pelo úsuario for menor ou igual a zero ele entrará 
  no else e realizará o print */
  else{
    printf("O vetor nao tem espaco para colocar elementos!\n\n");
  }
}

/* Função que recebe o vetor e o tamanho do vetor. Recebe também um ponteiro 
ocupado que representa quando a lista está cheia ou não, um ponteiro pro início 
da lista e um pro fim. E por fim, a função remove o elemento que está no início 
da lista.*/
void removeInicio(int tam, int *ocupado, int *inicio){
  /* Realiza um 'if' para verificar se a variável ocupado é igual a zero (correspondendo
  que o vetor está vazio caso seja zero). Se ocupado for igual a zero ele entrará no if. */
  if ((*ocupado) == 0){
    /* Isso mostra que o vetor não possui elementos para serem removidos. Logo 
    o programa realiza o print idenficando que não possui elementos para remover. */
    printf("Nao possui elementos para remover!\n\n");
  }
  /* Caso 'ocupado' não seja igual a zero (quer dizer que o vetor está ocupado 
  e que existe elementos nele), ele entrará no else abaixo. */
  else{
    /* Realizo um 'if' para verificar se 'inicio' é igual a 'tam - 1', com isso 
    eu verifico se 'inicio' está na última posição do vetor, e caso esteja eu 
    entrarei no respectivo if. */
    if ((*inicio) == tam - 1){ 
      /* Quando 'inicio' for igual a 'tam - 1' a próxima posição do vetor nessa 
      lista circular será 0, logo atribuiremos 0 a variável 'inicio'. */
      (*inicio) = 0;
      // Atualiza a variável 'ocupado' (decrementando), pois iremos remover um elemento no vetor. 
      (*ocupado)--;
    }
    /* Caso a variável 'inicio' não esteja na última posição do vetor eu entrarei 
    no respectivo else. */
    else{
      /* Atualiza a variável 'inicio' a incrementando em uma unidade, isso representa 
      que estamos deslocando início para frente e logo em seguida iremos remover 
      esse elemento do início com 'ocupado--', decrementado a variável 'ocupado' 
      . Isso representa que removemos o respectivo elemento. */
      (*inicio)++;
      (*ocupado)--;
    }
    // Realizo o print informando que o elemento foi removido com sucesso do início. 
    printf("Elemento removido do inicio com sucesso!\n\n");
  }
}

/* Função que recebe o vetor e o tamanho do vetor. Recebe também um ponteiro 
ocupado que representa quando a lista está cheia ou não, um ponteiro pro início 
da lista e um pro fim. E por fim, a função remove o elemento que está no final 
da lista.*/
void removeFim(int tam, int *ocupado, int *fim){
  /* Realiza um 'if' para verificar se a variável ocupado é igual a zero (correspondendo
  que o vetor está vazio caso seja zero). Se ocupado for igual a zero ele entrará no if. */
  if ((*ocupado) == 0){
    /* Isso mostra que o vetor não possui elementos para serem removidos. Logo 
    o programa realiza o print idenficando que não possui elementos para remover. */
    printf("Nao possui elementos para remover!\n\n");
  }
  /* Caso 'ocupado' não seja igual a zero (quer dizer que o vetor está ocupado 
  e que existe elementos nele), ele entrará no else abaixo. */
  else{
    /* Realizo um 'if' para verificar se 'fim' é igual a 0, com isso eu verifico 
    se 'fim' está na primeira posição do vetor, e caso esteja eu entrarei no 
    respectivo if. */
    if ((*fim) == 0){
      /* Quando 'fim' for igual a 0 a posição anterior do vetor nessa lista 
      circular será a última posição, logo atribuiremos 'tam - 1' a variável 'fim'. */
      (*fim) = tam - 1;
      // Atualiza a variável 'ocupado' (decrementando), pois iremos remover um elemento no vetor. 
      (*ocupado)--;
    }
    /* Caso a variável 'fim' não esteja na primeira posição do vetor eu entrarei 
    no respectivo else. */
    else{
      /* Atualiza a variável 'fim' a decrementando em uma unidade, isso representa 
      que estamos deslocando fim para trás e logo em seguida iremos remover 
      esse elemento do final com 'ocupado--', decrementado a variável 'ocupado' 
      . Isso representa que removemos o respectivo elemento. */
      (*fim)--;
      (*ocupado)--;
    }
    // Realizo o print informando que o elemento foi removido com sucesso do início. 
    printf("Elemento removido do final com sucesso!\n\n");
  }
} 

/* Função responsável por imprimir toda a lista circular com a respectiva posição 
de cada elmento. */
void imprime(int *vet, int tam, int *ocupado, int *inicio){
  /* Atribuiremos 'inicio' a variável 'n', faremos isso para não usarmos diretamente 
  o ponteiro 'inicio'. */
  int n = (*inicio);
  // Criamos uma variável 'a' que será responsável para percorrer esse vetor.
  int a = 0;
  /* Enquanto a variável 'a' for menor que a quantidade de elementos que esse vetor 
  possui 'ocupado', ele realizará as instruções dentro do loop. */
  while (a < (*ocupado)){
    /* Realizo um 'if' para verificar se 'n' é igual a 'tam', nesse caso se ele 
    está em um posição depois da última, isso garante que a última posição também 
    seja mostrada. */
    if (n == tam){
      /* Se entrarmos no 'if' atribuiremos 0 a variável 'n', representando que 
      agora estamos na posição 0 (do início). */
      n = 0;
    }
    // Realiza o print, mostando o elemento e sua respectiva posição na lista.
    printf("%d (Posicao: %d)\n", vet[n], n);
    /* Atualizaremos a variável 'n' e a variável 'a' incrementando em uma unidade 
    a cada vez que passarmos no loop. */
    n++;
    a++;
  }
  printf("\n");
}

/* Função responsável por apresentar um switch case com opções para utilizar as 
funções implementadas acima. */
void menu(int op, int *vet, int tam, int *ocupado, int *inicio, int *fim){
  // Variável 'elemento' que será usada para ler um elemento e inseri-lo na lista.
  int elemento;

  /* Faremos um switch case para solicitar a quem irá usar o programa a função 
  que deseja utilizar. */
  switch (op){
  case 1:
    /* Caso ele digite '1' irá ser realizado a leitura do elemento que deseja 
    inserir e chamamos a função 'inserirInicio' para inserir no início da lista. */
    printf("\nInserindo no inicio...\n");
    printf("Digite o elemento que deseja inserir: ");
    scanf("%d", &elemento);
    inserirInicio(vet, elemento, tam, ocupado, inicio, fim);
    break;

  case 2:
    /* Caso ele digite '2' irá ser realizado a leitura do elemento que deseja 
    inserir e chamamos a função 'inserirFim' para inserir no final da lista. */
    printf("\nInserindo no fim...\n");
    printf("Digite o elemento que deseja inserir: ");
    scanf("%d", &elemento);
    inserirFim(vet, elemento, tam, ocupado, inicio, fim);
    break;

  case 3:
    /* Caso ele digite '3' irá chamar a função 'removeInicio' para, então, remover
    o elemento que estiver no início da lista. */
    printf("\nRemovendo do inicio...\n");
    removeInicio(tam, ocupado, inicio);
    break;
  
  case 4:
    /* Caso ele digite '4' irá chamar a função 'removeFim' para, então, remover
    o elemento que estiver no final da lista. */
    printf("\nRemovendo do fim...\n");
    removeFim(tam, ocupado, fim);
    break;
  
  case 5:
    /* Caso ele digite '5' irá realizar um 'if' para verificar se o vetor não está
    vazio e assim chamar a função 'imprime' que imprimirá os elementos da lista.
    Caso o vetor estiver vazio ele realiza o print indicando que a lista não possui
    nenhum elemento. */
    if (*ocupado != 0){
      printf("\nImprimindo a lista...\n");
      imprime(vet, tam, ocupado, inicio);
    }
    else printf("\nO vetor nao possui nenhum elemento!\n\n");
    break;

  default:
    break;
  } 
}

int main(){
  // Definimos a variável 'op' que irá ser lida pela função 'menu'.
  int op; 
  /* Definimos a variável 'tam' que representa o tamanho do vetor e será lida
  para alocar esse tamanho para o vetor. */
  int tam;
  // Variável 'ocupado' iniciliazada com zero, representando que o vetor está vazio.
  int ocupado = 0;
  // Variável 'inicio' inicilizada com zero para mostrar a posição inicial do início da lista.
  int inicio = 0;
  /* Variável 'fim' iniciliazada também com zero, pois é uma lista circular, logo 
  o início tem a mesma posição do fim (zero nesse caso). */
  int fim = 0;

  /* Lendo a variável 'tam' que logo após ser lida irá servir para alocar 
  dinâmicamente um espaço da memória para o respectivo vetor. */ 
  printf("Digite o tamanho da lista que deseja: ");
  scanf("%d", &tam);
  printf("\n");
  int *vet = (int *)malloc(tam * sizeof(int));

  // 'do while' para fazer um menu de opções repetidas vezes até que o usuário deseje sair dele.
  do{
  printf("1 - Inserir no inicio: \n");
  printf("2 - Inserir no fim: \n");
  printf("3 - Remover no inicio: \n");
  printf("4 - Remover no fim: \n");
  printf("5 - Imprimir lista: \n");
  printf("6 - Sair: \n");
  scanf("%d", &op);

  /* Caso op esteja entre 1 e 5 chamamos a função menu, caso contrário eu chamo
  novamente as opções até o usuário digitar uma opção válida.*/
  if (op >= 1 && op <= 5) menu(op, vet, tam, &ocupado, &inicio, &fim);

  }while (op != 6);// Quando op for 6 eu saio do programa.
  
  free(vet);

  return 0;
}