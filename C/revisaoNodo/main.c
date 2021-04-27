#include <stdio.h>
#include <stdlib.h>

/* A ESTRUTURA QUE REPRESENTA O ELO DA CORRENTE ----------- */
struct Nodo{
  int info; // informaÃ§Ã£o armazenada pela lista
  struct Nodo* prox;
};
typedef struct Nodo Nodo;

/* A ESTRUTURA QUE REPRESENTA A CORRENTE ------------------- */
struct Lista{
  int tamanho; // armazena a qtd. de nodos na lista
  Nodo* cabeca; // aponta para o primeiro nodo da lista
};
typedef struct Lista Lista;

/* OPERAÃ‡Ã•ES ----------------------------------------------- */
void initNodo(Nodo* nodo, int valor){ // construtor do Nodo
  nodo->info = valor;
  nodo->prox = 0;
}

void initLista(Lista* lista){
  lista->tamanho = 0; // a princÃ­pio, a lista estÃ¡ vazia
  lista->cabeca = 0; // uma lista vazia nÃ£o aponta para nada
}

int inserir(Lista* lista, int index, int valor){
    if(index < 0 || index > lista->tamanho)
        return 2; // erro de indice
    
    
    Nodo* novo = malloc(sizeof(Nodo));
    initNodo(novo, valor);
    
    if(index == 0){ // inserÃ§Ã£o na cabeÃ§a (cenÃ¡rio 1)
        novo->prox = lista->cabeca;
        lista->cabeca = novo;
    }else{ // inserÃ§Ã£o acontece nas posiÃ§Ãµes 1 atÃ© (n-1) (cenario 2)
        Nodo* pont = lista->cabeca;
        int i=0;
        
        while(i!=index-1){ // garante que "pont" atinja a sua posiÃ§Ã£o devida
            pont = pont->prox;
            i++;
        }
        
        novo->prox = pont->prox;
        pont->prox = novo;
    }
    lista->tamanho++; // recebeu mais um elemento
    return 0; // sucesso da operaÃ§Ã£o de inserÃ§Ã£o
}

Nodo* busca(int valor, Lista* lista){
  Nodo* pont = lista->cabeca;
  int i;
  for(i = 0; i<lista->tamanho; i++){
    if(valor == pont->info)
      return pont; // encontrou e retorna o end. do nodo
    pont = pont->prox; // navega para o proximo nodo
  }
  return 0;
}

int remover(int index, Lista* lista){
  if(lista->tamanho == 0)
    return 1; // erro de espaco
  if(index<0 || index>=lista->tamanho)
    return 2; // erro de indice
 
  if(index == 0){ // cenario 1 (remoÃ§Ã£o na pos. 0)
    Nodo* temp = lista->cabeca;
    lista->cabeca = lista->cabeca->prox;
    free(temp);
  }else{ // cenario 2 (remoÃ§Ã£o nas pos. 1 atÃ© n-1)
    Nodo* temp;
    Nodo* pont = lista->cabeca;
    int i = 0;
    while(i<index-1){ // navega os apontadores atÃ© a pos. index-1
      pont = pont->prox;
      i++;
    }
    temp = pont->prox;
    pont->prox = pont->prox->prox;
    free(temp);
  }
  lista->tamanho--;
  return 0; // sucesso da remoÃ§Ã£o
}

void printLista(Lista* lista){
    int i;
    Nodo* pont = lista->cabeca;
    printf("--------------------\n");
    for(i=0;i<lista->tamanho;i++){
        printf("%d-",pont->info);
        pont = pont->prox;
    }
    printf("\n--------------------\n");
}

/* PROGRAMA ------------------------------------------------ */
int main(void) {
  Lista * lista1 = malloc(sizeof(Lista));
  initLista(lista1);
  printLista(lista1);
  inserir(lista1, 0, 7);
  inserir(lista1, 0, 14);
  inserir(lista1, 0, 2);
  inserir(lista1, 0, 8);
  

  while(1){
    printLista(lista1);
    printf("\nDigite o indice da remocao:");
    int index;
    scanf("%d",&index);

    int resultado = remover(index, lista1);
    switch(resultado){
      case 0: printf("\nValor removido com sucesso!\n"); break;
      case 1: printf("\nLista vazia! Nao pode remover!\n"); break;
      case 2: printf("\nIndice invalido para a remocao!\n"); break;
    }
  }

  return 0; //
}