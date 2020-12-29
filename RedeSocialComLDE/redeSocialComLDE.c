#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listaAmigos{
  /* Definindo a estrutura (listaAmigos) na qual irá conter a lista de amigos do
  usuario e está em uma lista duplamente encadeada. Essa estrutura possui, também, um 
  id (identificador único), um ponteiro para o prox (para o próximo elemento da 
  lista) e um ponteiro pred (para o elemento anterior nessa lista). */
  int id;

  struct listaAmigos *prox;
  struct listaAmigos *pred;

} ListaAmigos;

typedef struct usuario {
  /* Definindo a estrutura (usuario) na qual irá conter os usuarios que serão 
  cadastrados no sistema e estará em uma lista duplamente encadeada. Essa estrutura 
  possui, também, um id (identificador unico), um nome, idade e um email para o 
  usuario. Esssa estrutura também possui uma identificação para a estrutura'listaAmigos', 
  fazendo o relacionamento que o usuario possui uma lista de amigos.Também podemos 
  encontrar um ponteiro para o prox (para o próximo elemento da lista) e um ponteiro 
  pred (para o elemento anterior nessa lista). */
  int id;
  char nome[50];
  int idade;
  char email[50];

  struct listaAmigos *listaAmigos;

  struct usuario *prox;
  struct usuario *pred;

} Usuario;

/* Função que irá ficar responsável por criar um usuario na lista de usuarios,
nesse caso essa função irá criar um nó nessa lista e inserir as informações que 
um usuario tem, todas nesse nó. */
Usuario *criaUsuario(int id, char *nome, int idade, char *email){

  // Aloca um espaço na memória para a variável novo (que é do tipo struct usuario).
  Usuario *novo = (struct usuario *)malloc(sizeof(struct usuario)); 

  /* Verifica se novo existe, e se existir o espaço de id de novo (novo->id) 
  recebe o id recebido como parâmetro pela função, o mesmo acontece para o nome
  (aqui temos que atribuir com a função strcpy, copiando o novo->nome de nome),
  para a idade e também com o email. Já o espaço para prox de novo (novo->prox) 
  recebe NULL, assim como o pred. */
  if (novo){
    novo->id = id;
    strcpy(novo->nome, nome);
    novo->idade = idade;
    strcpy(novo->email, email);
    novo->prox = NULL;
    novo->pred = NULL;

    /* A lista de amigos que novo possui deve ser inicializada com calloc, pois
    ao decorrer do código estaremos usando nó cabeça, logo isso é necessário, e
    também porque listaAmigos é uma estrutura e por isso deve ser alocado um epaço
    de memória para ela. */
    novo->listaAmigos = (ListaAmigos *)calloc(1, sizeof(ListaAmigos));
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

/* Função que irá ficar responsável por criar um amigo com um id na lista de 
amigos, nesse caso essa função irá criar um nó nessa lista e inserir as informações 
(id) que um amigo tem, todas nesse nó. */
ListaAmigos *criaListaAmigos(int id){

  // Aloca um espaço na memória para a variável novo (que é do tipo struct listaAmigos).
  ListaAmigos *novo = (struct listaAmigos *)malloc(sizeof(struct listaAmigos)); 

  /* Verfica se novo existe, e se existir o espaço de id de novo (novo->id) 
  recebe o id recebido como parâmetro pela função. Já o espaço para prox de novo 
  (novo->prox) recebe NULL assim como pred (novo->pred = NULL). */
  if (novo){
    novo->id = id;
    novo->prox = NULL;
    novo->pred = NULL;
  }

  /* Se novo não existir, no caso não tiver memória para ele ser alocado, printa
  erro e sai do programa. */
  else{
    printf("Erro ");
    exit(1);
  }

  // No final retorna a lista com a criação de seu nó nela.
  return novo;
}

/* Função que busca em uma lista ordenada o id de um usuario e o retorna por
final. O que faciliará para inserir ordenamente na lista duplamente encadeada e
fazer operações de busca a um usuario pra ver se ele realmente existe. */
Usuario *pegarUsuario(Usuario *usuario, int id){

  /* Cria uma variável aux do tipo ponteiro da estrutura Usuario. Ela irá ser o nó
  cabeça da lista, pois recebe o próximo da lista usuario (fazendo com que a lista 
  nunca seja vazia e aponte sempre para o nó cabeça). */
  Usuario *aux = usuario->prox;

  /* Enquanto a variável aux for diferente de NULL e o id for maior que o aux->id 
  iremos percorrer toda a lista em busca de encontrar o id. Como estamos bucando
  em uma lista já ordenada fica fácil encontrar. */
  while (aux != NULL && id > aux->id)
    /* Percorreremos aux (que aponta para o próximo da lista usuario) até que seja
    NULL e saia do while, porém só irá sair do while se, também, id for maior que
    aux->id e com isso quando sair do while irá retornar o respectivo id. */
    aux = aux->prox;
  
  // Retornar aux no final de tudo (nesse caso o id do usuario, se for encontrado).
  return aux;
  
}

/* Função que busca em uma lista ordenada o id de um amigo e o retorna por final. 
O que faciliará para inserir ordenamente na lista duplamente encadeada de amigos 
e fazer operações de busca a um amigo pra ver se ele realmente existe dentro de um 
usuario. */
ListaAmigos *buscaAmigos(ListaAmigos *amigos, int id){

  /* Cria uma variável aux do tipo ponteiro da estrutura ListaAmigos. Ela irá ser o nó
  cabeça da lista, pois recebe o próximo da lista amigos (fazendo com que a lista 
  nunca seja vazia e aponte sempre para o nó cabeça). */
  ListaAmigos *aux = amigos->prox;

  /* Enquanto a variável aux for diferente de NULL e o id for maior que o aux->id 
  iremos percorrer toda a lista em busca de encontrar o id. Como estamos bucando
  em uma lista já ordenada fica fácil encontrar. */
  while (aux != NULL && id > aux->id)
    /* Percorreremos aux (que aponta para o próximo da lista amigos) até que seja
    NULL e saia do while, porém só irá sair do while se, também, id for maior que
    aux->id e com isso quando sair do while irá retornar o respectivo id. */
    aux = aux->prox;

  // Retornar aux no final de tudo (nesse caso o id do amigo, se for encontrado).
  return aux;
  
}

/* Função que libera o espaço de memória que foi alocado anteriormente para uma
respectiva lista duplamente encadeada. */
void liberaLista(Usuario *usuario){

  /* Cria uma variável aux para percorrer a lista de usuários (inclusive o nó 
  cabeça). */
  Usuario *aux1 = usuario;

  //Percorre toda a lista de usuarios até que seja NULL e saia do while.
  while (aux1){

    //Crio uma variável 'removido' para armazenar o nó removido da lista.
    Usuario *removido = aux1;

    //Cria uma variável aux2 para percorrer a lista de amigos daquele usuario.
    ListaAmigos *aux2 = aux1->listaAmigos;
    aux1 = aux1->prox;

    /* Percorre toda a lista de amigos daquele usuário até que aux2 seja NULL e 
    saia do while. */
    while (aux2){

      // Crio uma variável 'removido1' para armazenar o nó da lista de amigos que será removido.
      ListaAmigos *removido1 = aux2;
      aux2 = aux2->prox;

      //Libera a memória alocada para aquele nó da lista de amigos.
      free(removido1);
    }
    //Libera a memória alocada para aquele usuário da lista de usuários.
    free(removido);
  }   
}

/* Função que insere ordenadamente o id, nome, idade e email (o que resultará em 
adicionar um novo usuário nesse lista) em uma lista duplamente encadeada de usuarios. */
void insereUsuarioOrd(Usuario *usuario, int id, char *nome, int idade, char *email){

  /* Cria uma variável novo que irá ser do tipo ponteiro de Usuario, e receberá 
  a função criaUsuario passando os parâmetros exigidos na função, isso resultará 
  na criação de um usuário (nó) na lista de usuários.*/
  Usuario *novo = criaUsuario(id, nome, idade, email);

  /* Cria uma variável aux que irá ser do tipo ponteiro de Usuario, ela receberá
  a função pegarUsuario, com isso ela irá receber o usuário e o id, retornando o
  id se existir esse id na lista de usuários. */
  Usuario *aux = pegarUsuario(usuario, id);

  /* Verifica se aux existe e se aux->id é igual ao id que passamos como parâmetro 
  para a função insereUsuarioOrd, se for igual isso quer dizer que esse id já
  existe na lista de usuários e portanto não podemos cadastrar um usuário com id
  já existente. */
  if (aux && aux->id == id){
    printf("Nao eh possivel cadastrar usuario com 'id' ja existente!\n\n");
  }

  /* Se a condição do 'if' acima não for verdade, isso é o id estiver livre para 
  ser cadastrado. */
  else{

    // Se aux não existir (aux == NULL, no caso a lista irá estar vazia) entramos nesse if.
    if (!aux){  
    /* Se usuario não tiver prox (no caso ele não tiver um próximo elemento, 
    nesse caso único elemento na lista), se essa condição for verdadeira ele 
    entra no if. */
    if (!usuario->prox){
      // Faz usuario->prox receber novo, nesse caso só tem um elemento nessa lista.
      usuario->prox = novo;
      /* Faz usuario->pred (antecessor) receber novo, como só tem um elemento na 
      lista, pred e prox apontarão para o mesmo elemento na lista. */
      usuario->pred = novo;
    }
    /* Se usuario tiver prox (no caso ele irá ter um próximo elemento, não irá 
    ser o único elemento na lista), se essa condição for verdadeira ele entra 
    no else. */ 
    else{ // Se entramos aqui teremos que realocar os ponteiros para receber o novo elemento.

      // Faz o ponteiro prox do usuario antecessor receber novo.
      usuario->pred->prox = novo;
      // Faz o antecessor de novo receber o antecessor de usuario.
      novo->pred = usuario->pred;
      // Por fim o antecessor de usuario receberá o novo.
      usuario->pred = novo;
    }
  }

  // Se aux existir (aux != NULL) entraremos no else do if do topo.
  else{
    // Faz com que o prox de novo (próximo elemento de novo) receber aux.
    novo->prox = aux;
    // Caso aux não tenha nenhum antecessor ele entrará no if abaixo (seja o primeiro da lista).
    if (!aux->pred)
      // Faz com que o prox de usuario (próximo elemento de usuario) receba novo.
      usuario->prox = novo;
    // Caso aux tenha um antecessor ele entrará no else do if de cima (não seja o primeiro da lista).
    else{
      // Faz o ponteiro antecessor de novo receba o ponteiro antecessor de aux.
      novo->pred = aux->pred;
      // Faz o ponteiro prox do antecessor de novo receber novo.
      novo->pred->prox = novo;
    }
    // Faz com que o ponteiro antecessor de aux receba novo.
    aux->pred = novo;
    }
  }
}

/* Função que insere ordenadamente o id (o que resultará em adicionar um novo 
amigo nesse lista de amigos que usuário contém) em uma lista duplamente encadeada 
de amigos. */
void insereAmigosOrd(ListaAmigos *amigos, int id){

  /* Cria uma variável novo que irá ser do tipo ponteiro de ListaAmigos, e receberá 
  a função criaListaAmigos passando os parâmetros exigidos na função, isso resultará 
  na criação de um amigo (nó) na lista de amigos.*/
  ListaAmigos *novo = criaListaAmigos(id);

  /* Cria uma variável aux que irá ser do tipo ponteiro de ListaAmigos, ela receberá
  a função buscaAmigos, com isso ela irá receber o amigo e o id, retornando o
  id se existir esse id na lista de amigos. */
  ListaAmigos *aux = buscaAmigos(amigos, id);

  // Se aux não existir (aux == NULL,no caso a lista irá estar vazia) entramos nesse if.
  if (!aux){
    /* Se amigos não tiver prox (no caso ele não tiver um próximo elemento, 
    nesse caso único elemento na lista), se essa condição for verdadeira ele 
    entra no if. */
    if (!amigos->prox){
      // Faz amigos->prox receber novo, nesse caso só tem um elemento nessa lista.
      amigos->prox = novo;
      /* Faz amigos->pred (antecessor) receber novo, como só tem um elemento na 
      lista, pred e prox apontarão para o mesmo elemento na lista. */
      amigos->pred = novo;
    }
    /* Se amigos tiver prox (no caso ele irá ter um próximo elemento, não irá 
    ser o único elemento na lista), se essa condição for verdadeira ele entra no 
    else. */ 
    else{ // Se entramos aqui teremos que realocar os ponteiros para receber o novo elemento.

      // Faz o ponteiro prox do amigo antecessor receber novo.
      amigos->pred->prox = novo;
      // Faz o antecessor de novo receber o antecessor de amigos.
      novo->pred = amigos->pred;
      // Por fim o antecessor de amigos receberá o novo.
      amigos->pred = novo;
    }
  }
  // Se aux existir (aux != NULL) entraremos no else do if do topo.
  else{
    // Faz com que o prox de novo (próximo elemento de novo) receber aux.
    novo->prox = aux;
    // Caso aux não tenha nenhum antecessor ele entrará no if abaixo (seja o primeiro da lista).
    if (!aux->pred)
      // Faz com que o prox de amigos (próximo elemento de amigos) receba novo.
      amigos->prox = novo;
    // Caso aux tenha um antecessor ele entrará no else do if de cima (não seja o primeiro da lista).
    else{
      // Faz o ponteiro antecessor de novo receba o ponteiro antecessor de aux.
      novo->pred = aux->pred;
      // Faz o ponteiro prox do antecessor de novo receber novo.
      novo->pred->prox = novo;
    }
  // Faz com que o ponteiro antecessor de aux receba novo.
  aux->pred = novo;
  }
}

/* Função que faz a busca de um usuário na lista de usuários. Ela busca um usuário
por id e retornar printando na tela suas informações (id, nome, idade, email e 
quem são seus amigos). */
void buscaUsuario(Usuario *usuario, int id){

  /* Cria uma variável aux que irá ser do tipo ponteiro de Usuario, ela receberá
  a função pegarUsuario, com isso ela irá receber o usuário e o id, retornando o
  id se existir esse id na lista de usuários. */
  Usuario *aux = pegarUsuario(usuario, id);
  // Cria uma variável aux2 do tipo ponteiro de ListaAmigos inicializada com NULL.
  ListaAmigos *aux2 = NULL;
  /* Cria uma variável var do tipo int que irá nos auxiliar em printar algumas 
  coisas dentro do while ou fora do while. */
  int var = 0;
  
  /* Se aux existir (aux != NULL) e se id que foi passado por parâmetro na função 
  for igual ao id que aux retornou ao fazer aux receber a função pegarUsuario, 
  ele entrará no if abaixo*/
  if (aux != NULL && id == aux->id){
    // Irá fazer o print de todas as informações que usuário.
    printf("id: %d\n", aux->id);
    printf("Nome: %s\n", aux->nome);
    printf("Idade: %d\n", aux->idade);
    printf("Email: %s\n", aux->email);
    /* Como aux2 é do tipo ListaAmigos teremos que inicalizar ela como nó cabeça 
    apontando para o prox de ListaAmigos de aux1. */
    aux2 = aux->listaAmigos->prox;

    // Enquanto aux2 existir iremos percorrer toda ListaAmigos que aux2 contém.
    while (aux2){

      // Se var for igual a zero ele realiza o print.
      if (var == 0) printf("Amigos desse usuario: \n");
      /* Enquanto estiver percorrendo todo aux2 ele irá printar o id dos amigos 
      de aux (já que aux2 contém a listaAmigos de aux). */
      printf("%d\n", aux2->id);
      // Faz aux2 ir pro próximo elemento (id) até ele ser NULL e sair do while.
      aux2 = aux2->prox;
      // Faz var receber 1 (apenas nos auxiliará para realizar prints estratégicos).
      var = 1;
    }
    /* Se var for igual a zero quer dizer que ele não entrou no while, logo a 
    listaAmigos desse usuário é vazia e ele realiza o print*/
    if (var == 0) printf("Esse usuario nao possui amigos!\n");
    printf("\n");
  }
  /* Caso aux seja igual a NULL e o id buscado por parâmetro na função for 
  diferente do id de aux->id quer dizer que esse usuário não foi encontrado na 
  lista de usuários, com isso ele entra no else e realiza o print. */
  else printf("Erro - O usuario nao foi encontrado\n");
}

/* Função que recebe a lista de usuários e seus id's e cadastra amizade entre 
esses usuários. */
void cadastraAmizade(Usuario *usuario, int id1, int id2){

  /* Cria uma variável aux1 que irá ser do tipo ponteiro de Usuario, ela receberá
  a função pegarUsuario, com isso ela irá receber o usuário e o id1, retornando o
  id se existir esse id na lista de usuários. */
  Usuario *aux1 = pegarUsuario(usuario, id1);
  /* Cria uma variável aux2 que irá ser do tipo ponteiro de Usuario, ela receberá
  a função pegarUsuario, com isso ela irá receber o usuário e o id2, retornando o
  id se existir esse id na lista de usuários. */
  Usuario *aux2 = pegarUsuario(usuario, id2);

  /* Se aux1 existir e aux2 existir e se ambos id's (aux1->id e aux2->id) 
  buscados com a função pegarUsuario forem iguais aos seus respectivos id's 
  (passados como parâmetro na função), ele entra nesse if. */
  if (aux1 != NULL && aux2 != NULL && id1 == aux1->id && id2 == aux2->id){
    /* Se id1 for igual a id2, neese caso se você tentar cadastrar uma amizade 
    com você mesmo ele entra nesse if e realiza o respectivo print. */
    if (id1 == id2){
      printf("Nao eh possivel cadastrar uma amizade com voce mesmo!\n\n");
    }
    // Caso id1 for diferente de id2 ele entra nesse else.
    else{
      /* Cria uma variável aux3 que irá ser do tipo ponteiro de ListaAmigos e ela
      irá receber a função buscaAmigos que irá retornar o id (se existir) do amigo
      buscado na lista de amigos de aux1. */
      ListaAmigos *aux3 = buscaAmigos(aux1->listaAmigos, id2);
    /* Se aux3 não existir ou se o id de aux3 for diferente do id2 passado por 
    parâmetro na função, entramos no if abaixo. */
    if (!aux3 || aux3->id != id2){
      /* Chamamos a função insereAmigosOrd para inserir o amigo que tem id2 na 
      lista de amigos de aux1. */
      insereAmigosOrd(aux1->listaAmigos, id2);

      /* Chamamos a função insereAmigosOrd para inserir o amigo que tem id1 na 
      lista de amigos de aux2. */
      insereAmigosOrd(aux2->listaAmigos, id1);
      // Realiza o print para mostrar que os usuários agora são amigos.
      printf("O usuario %s e %s agora sao amigos!\n\n", aux1->nome, aux2->nome);
    }
    /* Se a amizade já existir (nesse caso se o id passado já estiver na lista 
    de amigos), ele entra no else e realiza o print. */
    else printf("Amizade ja existe!\n\n");
    }
  }
  /* Caso aux seja igual a NULL e o id buscado por parâmetro na função for 
  diferente do id de aux1(e 2)->id quer dizer que esse usuário não foi encontrado na 
  lista de usuários, com isso ele entra no else e realiza o print. */
  else printf("Erro - O usuario nao foi encontrado\n\n");
}

/* Função que recebe a lista de usuários e respectivos id's (usuários), imprimindo 
os amigos em comum entre esses dois id's (usuários). */
void imprimeAmigosEmComum(Usuario *usuario, int id1, int id2){

  /* Cria uma variável usuario1 que irá ser do tipo ponteiro de Usuario, ela receberá
  a função pegarUsuario, com isso ela irá receber o usuário e o id1, retornando o
  id se existir esse id na lista de usuários. */
  Usuario *usuario1 = pegarUsuario(usuario, id1);
   /* Cria uma variável usuario2 que irá ser do tipo ponteiro de Usuario, ela receberá
  a função pegarUsuario, com isso ela irá receber o usuário e o id1, retornando o
  id se existir esse id na lista de usuários. */
  Usuario *usuario2 = pegarUsuario(usuario, id2);
  // Cria uma variável usuario3 do tipo ponteiro de Usuario inicializada com NULL.
  Usuario *usuario3 = NULL;
  // Cria uma variável aux1 do tipo ponteiro de ListaAmigos inicializada com NULL.
  ListaAmigos *aux1 = NULL;
  // Cria uma variável aux2 do tipo ponteiro de ListaAmigos inicializada com NULL.
  ListaAmigos *aux2 = NULL;
  /* Cria uma variável var do tipo int que irá nos auxiliar em printar algumas 
  coisas dentro do while ou fora do while. */
  int var = 0;

  /* Se usuario1 existir e usuario2 existir e se ambos id's (usuario1->id e usuario2->id) 
  buscados com a função pegarUsuario forem iguais aos seus respectivos id's 
  (passados como parâmetro na função) , ele entra nesse if. */
  if (usuario1 != NULL && usuario2 != NULL && id1 == usuario1->id && id2 == usuario2->id){
    // Faz aux1 receber o poteiro prox do nó cabeça (usuario1->listaAmigos).
    aux1 = usuario1->listaAmigos->prox;
    /* Se id1 for igual a id2, nesse caso se você tentar imprimir uma amizade 
    em comum com você mesmo ele entra nesse if e realiza o respectivo print. */
    if (id1 == id2){
      printf("Nao eh possivel listar amizades em comum com vc mesmo!\n\n");
    }
    // Caso id1 for diferente de id2 ele entra nesse else.
    else{
      // Enquanto aux1 existir iremos percorrer toda ListaAmigos que aux1 contém. 
      while (aux1){
      /* Faz aux2 receber a função buscaAmigos que irá retornar o id (se existir) do amigo
      buscado na lista de amigos de usuario2 */
      aux2 = buscaAmigos(usuario2->listaAmigos, aux1->id);
      /* Se aux2 existir (aux2 != NULL) e se o id da lista de amigos de aux2 for 
      igual ao id da lista de amigos de aux1 ele entrará no respectivo if. */
      if (aux2 != NULL && aux2->id == aux1->id){
        // Faz var receber 1 (apenas nos auxiliará para realizar prints estratégicos).
        var = 1;
        /*Faz com que usuario3 receba a função pegarUsuario, com isso ela irá 
        receber o usuário e o id da lista de amigos de aux1, retornando o id se 
        existir esse id na lista de usuários.*/
        usuario3 = pegarUsuario(usuario, aux1->id);
        /* Se usuario3 existir e se o id de usuario3 for igual ao id da lista de
       amigos de aux1 ele irá entrar no if e printar que existe amigos em comum. */
        if (usuario3 != NULL && usuario3->id == aux1->id){
          printf("%s eh amigo em comum de %s e %s!\n\n", usuario3->nome, usuario1->nome, usuario2->nome); 
        }
      }
      // Faz aux1 ir pro próximo elemento (id) até ele ser NULL e sair do while.
      aux1 = aux1->prox;
    }
      /* Se var for igual a zero quer dizer que ele não entrou no while, logo 
      esses dois id's passados como parâmentros na função (usuários) não possuem 
      amigos em comum. */
      if (var == 0){
        printf("Nao tem amigos em comum!\n\n");
      }
    }
  }
  /* Caso usuario1(e 2) seja igual a NULL e o id buscado por parâmetro na função for 
  diferente do id de usuario1(e 2)->id quer dizer que esse usuário não foi encontrado na 
  lista de usuários, com isso ele entra no else e realiza o print. */
  else printf("Erro - O usuario nao foi encontrado\n\n");
}

/* Função que recebe a lista de usuários e respectivos id's (usuários), e irá 
excluir a amizade entre esses usuários (fazendo a exclusão dos id's na lista de 
amigos desses usuários). */
void excluiAmizade(Usuario *usuario, int id1, int id2){

  /* Cria uma variável usuario1 que irá ser do tipo ponteiro de Usuario, ela receberá
  a função pegarUsuario, com isso ela irá receber o usuário e o id1, retornando o
  id se existir esse id na lista de usuários. */
  Usuario *usuario1 = pegarUsuario(usuario, id1);
  /* Cria uma variável usuario2 que irá ser do tipo ponteiro de Usuario, ela receberá
  a função pegarUsuario, com isso ela irá receber o usuário e o id1, retornando o
  id se existir esse id na lista de usuários. */
  Usuario *usuario2 = pegarUsuario(usuario, id2);
   
   /* Se usuario1 existir e usuario2 existir e se ambos id's (usuario1->id e usuario2->id) 
  buscados com a função pegarUsuario forem iguais aos seus respectivos id's 
  (passados como parâmetro na função) , ele entra nesse if. */
  if (usuario1 != NULL && usuario2 != NULL && id1 == usuario1->id && id2 == usuario2->id){
    /* Faz aux1 receber a função buscaAmigos que irá retornar o id (se existir) do amigo
    buscado na lista de amigos de usuario1 passando o id2, também, para verificar se
    esse id2 está nessa lista. */
    ListaAmigos *aux1 = buscaAmigos(usuario1->listaAmigos, id2);
    /* Faz aux2 receber a função buscaAmigos que irá retornar o id (se existir) do amigo
    buscado na lista de amigos de usuario1 passando o id1, também, para verificar se
    esse id1 está nessa lista. */
    ListaAmigos *aux2 = buscaAmigos(usuario2->listaAmigos, id1);
    /* Se id1 for igual a id2, nesse caso se você tentar excluir uma amizade 
   com você mesmo ele entra nesse if e realiza o respectivo print. */
    if (id1 == id2){
      printf("Nao eh possivel exluir uma amizade com vc mesmo, eh impossivel!\n\n");
    }
    // Caso id1 for diferente de id2 ele entra nesse else.
    else{
      /* Se aux1 existir e aux2 existir e se ambos id's (id1 e id2) forem 
      iguais aos seus respectivos id's (passado como parâmetro na função) buscados 
      com a função buscaAmigos, ele entra nesse if. */
      if (aux1 && aux1->id == id2 && aux2 && aux2->id == id1){
      /* Se o antecessor de aux1 existir, nesse caso se ele não for o primeiro da 
      lista eu entro no if. */
      if (aux1->pred != NULL){
        // Faz o ponteiro prox do antecessor de aux1 receber o próximo de aux1.
        aux1->pred->prox = aux1->prox;
      }
      // Caso o elemento seja o primeiro da lista ele entrará no else.
      else usuario1->listaAmigos->prox = aux1->prox; // Faz o ponteiro prox do nó cabeça (usuario1->listaAmigos) receber o próximo de aux1.
      /* Se o antecessor de aux2 existir, nesse caso se ele não for o primeiro da 
      lista eu entro no if. */
      if (aux2->pred != NULL){
        // Faz o ponteiro prox do antecessor de aux2 receber o próximo de aux2.
        aux2->pred->prox = aux2->prox;
      }
      // Caso o elemento seja o primeiro da lista ele entrará no else.
      else usuario2->listaAmigos->prox = aux2->prox; // Faz o ponteiro prox do nó cabeça (usuario2->listaAmigos) receber o próximo de aux2.
      /* Se o elemento próximo de aux1 existir, nesse caso ele não for o último
      elemento da lista eu entro no if. */
      if (aux1->prox != NULL){
        // Faz o ponteiro pred do próximo elemento de aux1 receber o elemento antecessor de aux1.
        aux1->prox->pred = aux1->pred;
      }
      // Caso o elemento seja o último da lista ele entrará no else.
      else usuario1->listaAmigos->pred = aux1->pred; // Faz o ponteiro pred do nó cabeça (usuario1->listaAmigos) receber o antecessor de aux1.
      /* Se o elemento próximo de aux2 existir, nesse caso ele não for o último
      elemento da lista eu entro no if. */
      if (aux2->prox != NULL){
        // Faz o ponteiro pred do próximo elemento de aux2 receber o elemento antecessor de aux2.
        aux2->prox->pred = aux2->pred;
      }
      // Caso o elemento seja o último da lista ele entrará no else.
      else usuario2->listaAmigos->pred = aux2->pred; // Faz o ponteiro pred do nó cabeça (usuario2->listaAmigos) receber o antecessor de aux2.
      // Realiza o print que os usuários não são mais amigos.
      printf("Os usuarios %s e %s nao sao mais amigos!\n\n", usuario1->nome, usuario2->nome);
      /* Como eu exclui esses usuários um da lista de amigos do outro eu preciso 
      liberar a memória que foi guardada para essa lista e que não existe mais. */ 
      free(aux1);
      free(aux2);
      }
      /* Se a amizade não existir (nesse caso se o id passado não estiver na lista 
      de amigos), ele entra no else e realiza o print. */ 
      else printf("Amizade nao existe!\n\n");
      }
    }
  /* Caso usuario1(e 2) seja igual a NULL e o id buscado por parâmetro na função for 
  diferente do id de usuario1(e 2)->id quer dizer que esse usuário não foi encontrado na 
  lista de usuários, com isso ele entra no else e realiza o print. */
  else printf("Erro - O usuario nao foi encontrado\n\n");
}

/* Função que recebe a lista de usuários e seu respectivo id (usuário), e irá 
excluir um usuário dessa lista (fazendo a exclusão de todas as informações do 
usuário assim como sua lista de amigos). */
void excluiUsuario(Usuario *usuario, int id){
  /* Cria uma variável usuario1 que irá ser do tipo ponteiro de Usuario, ela receberá
  a função pegarUsuario, com isso ela irá receber o usuário e o id, retornando o
  id se existir esse id na lista de usuários. */
  Usuario *usuario1 = pegarUsuario(usuario, id);
   // Cria uma variável aux do tipo ponteiro de ListaAmigos inicializada com NULL.
  ListaAmigos *aux = NULL;

  /* Verifica se usuario1 existe e se usuario1->id é igual ao id que passamos 
  como parâmetro para a função excluiUsuario, se for igual isso quer dizer que 
  esse id já existe na lista de usuários e portanto podemos excluir esse usuário 
  da lista de usuários. */
  if (usuario1 != NULL && usuario1->id == id){
    // Faz aux receber o poteiro prox do nó cabeça (usuario1->listaAmigos).
    aux = usuario1->listaAmigos->prox;
    // Enquanto aux existir iremos percorrer toda ListaAmigos que aux contém. 
    while (aux){
      /* Cria uma variável aux2 do tipo ponteiro de ListaAmigos que recebe o 
      ponteiro prox de aux. */
      ListaAmigos *aux2 = aux->prox;
      /* Como estaremos exlcuindo um usuário da lista temos que retirar as amizades
      que ele contém com outros usuários, por isso passamos a função excluiAmizade
      para retirar a amizade do usuário que queremos exlcuir também dos usuários que
      contém esse usuário (como amigo). */
      excluiAmizade(usuario, id, aux->id);
      // Faz aux receber aux2 para andarem junto dentro do while.
      aux = aux2;
    }
    /* Se o antecessor de usuario1 existir, nesse caso se ele não for o primeiro da 
    lista eu entro no if. */
    if (usuario1->pred != NULL){
      // Faz o ponteiro prox do antecessor de usuario1 receber o próximo de usuario1.
      usuario1->pred->prox = usuario1->prox;
    }
    // Caso o elemento seja o primeiro da lista ele entrará no else.
    else usuario->prox = usuario1->prox; // Faz o ponteiro prox do usuario receber o próximo de usuario1.
    /* Se o elemento próximo de usuario1 existir, nesse caso ele não for o último
      elemento da lista eu entro no if. */
    if (usuario1->prox != NULL){
      // Faz o ponteiro pred do próximo elemento de usuario1 receber o antecessor de usuario1.
      usuario1->prox->pred = usuario1->pred;
    }
    // Caso o elemento seja o último da lista ele entrará no else.
    else usuario->pred = usuario1->pred; // Faz o ponteiro pred do usuario receber o antecessor de usuario1.
    
    // Se tudo ocorrer corretamente ele realizar o print que o usuário foi excluido.
    printf("O usuario foi excluido com sucesso!\n");
    // Libera o espaço de memória onde contém o nó cabeça da lista de amigos
    free(usuario1->listaAmigos); 
    // Libera o espaço de memória onde foi armazenado a variável usuario1 que é do tipo struct usuario.
    free(usuario1);
  }

  /* Caso usuario1 seja igual a NULL e o id buscado por parâmetro na função for 
  diferente do id de usuario1->id quer dizer que esse usuário não foi encontrado na 
  lista de usuários, com isso ele entra no else e realiza o print. */
  else printf("Erro - O usuario nao foi encontrado\n\n");
}

/* Função responsável por apresentar um switch case com opções para utilizar as 
funções implementadas acima. */
void menu(Usuario *L,int op){
  // Criando as variáveis que serão lidas para executar as respectivas funções.
  // Tais variáveis possuem as informações do usuário (id, nome, idade, email).
  int id, id2, idade;
  char nome[50], email[50], enter;

  /* Faremos um switch case para solicitar a quem irá usar o programa a função 
  que deseja utilizar. */
  switch (op){
  case 1:
    /* Caso ele digite '1' irá ser realizado as devidas leituras e chamará a 
    função buscaUsuario. */
    printf("\nBuscando um usuario no sistema...\n");
    printf("Digite o 'id' do usuario que deseja buscar: ");
    scanf("%d", &id);
    buscaUsuario(L, id);
    printf("\n");
    break;

  case 2:
    /* Caso ele digite '2' irá ser realizado as devidas leituras e chamará a 
    função insereUsuarioOrd. */
    printf("\nCriando novo usuario...\n");
    printf("Digite o 'id' desse usuario: ");
    scanf("%d", &id);
    printf("Digite o nome do novo usuario: ");
    scanf("%c", &enter);
    scanf("%[^\n]", nome);
    printf("Digite a idade do novo usuario: ");
    scanf("%d", &idade);
    printf("Digite o email do novo usuario: ");
    scanf("%c", &enter);
    scanf("%[^\n]", email);
    insereUsuarioOrd(L, id, nome, idade, email);
    printf("\n");
    break;

  case 3:
    /* Caso ele digite '3' irá ser realizado as devidas leituras e chamará a 
    função excluiUsuario. */
    printf("\nExcluindo um usuario...\n");
    printf("Digite o 'id' do usuario que deseja excluir: ");
    scanf("%d", &id);
    excluiUsuario(L, id);
    printf("\n");
    break;

  case 4:
    /* Caso ele digite '4' irá ser realizado as devidas leituras e chamará a 
    função cadastraAmizade. */
    printf("\nCadastrando uma amizade...\n");
    printf("Digite o primeiro 'id' que deseja realizar o cadastro de amizade: ");
    scanf("%d", &id);
    printf("Digite o segundo 'id' que deseja realizar o cadastro de amizade: ");
    scanf("%d", &id2);
    cadastraAmizade(L, id, id2);
    printf("\n");
    break;

  case 5:
    /* Caso ele digite '5' irá ser realizado as devidas leituras e chamará a 
    função imprimeAmigosEmComum. */
    printf("\nListando amigos em comum...\n");
    printf("Digite o primeiro 'id' que deseja listar os amigos em comum: ");
    scanf("%d", &id);
    printf("Digite o segundo 'id' que deseja listar os amigos em comum: ");
    scanf("%d", &id2);
    imprimeAmigosEmComum(L, id, id2);
    printf("\n");
    break;  
  
  case 6:
    /* Caso ele digite '6' irá ser realizado as devidas leituras e chamará a 
    função excluiAmizade. */
    printf("\nExcluindo amizade...\n");
    printf("Digite o primeiro 'id' que deseja excluir a amizade: ");
    scanf("%d", &id);
    printf("Digite o segundo 'id' que deseja exlcuir a amizade: ");
    scanf("%d", &id2);
    excluiAmizade(L, id, id2);
    printf("\n");
    break;

  default:
    break;
  }
}

int main(){
  /* Cria uma lista L que irá ser do tipo struct Usuario, como estamos trabalhando 
  com nó cabeça temos que alocar um espaço na memória para essa lista usando a 
  ferramenta calloc. */
  Usuario *L =  (Usuario *)calloc(1, sizeof(Usuario));
  // Definimos a variável 'op' que irá ser lida pela função 'menu'.
  int op;

  // 'do while' para fazer um menu de opções repetidas vezes até que o usuário deseje sair dele.
  do{
  printf("1 - Buscar usuario: \n");
  printf("2 - Criar novo usuario: \n");
  printf("3 - Excluir usuario: \n");
  printf("4 - Cadastrar amizade: \n");
  printf("5 - Listar amigos em comum: \n");
  printf("6 - Excluir amizade: \n");
  printf("7 - Sair: \n");
  scanf("%d", &op);

  /* Caso op esteja entre 1 e 6 chamamos a função menu, caso contrário eu chamo
  novamente as opções até o usuário digitar uma opção válida.*/
  if (op >= 1 && op <= 6) menu(L, op);

  }while (op != 7); // Quando op for 7 eu saio do programa.
  
  /* Liberaremos a memória alocada para L através da função liberaLista (que 
  libera a memória de uma lista duplamente encadeada). */
  liberaLista(L);

  return 0;
}