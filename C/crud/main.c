#include <stdio.h>
#define MAX 10

struct Lista{
  int tamanho;
  int elementos[MAX];
};
typedef struct Lista Lista; // cria apelido para um tipo

int inserir(int valor, int index, Lista* lista){
  if(lista->tamanho == MAX)
    return 1; // indica erro de espaço
  if(index<0 || index>lista->tamanho)
    return 2; // indica erro de indice
  int i = lista->tamanho;
  while(i!=index){
    // empurra os valores
    lista->elementos[i] = lista->elementos[i-1];
    i--;
  }
  lista->elementos[i] = valor;
  lista->tamanho++;
  return 0; // sucesso da inserção
}

int busca(int valor, Lista* lista) {
	int indice = -1;
  // retorna o índice, na lista, onde se encontra o arranjo
  // ou retorna -1, para simboliza que o valor não foi encontra
	for (int i = 0; i <= lista->tamanho; i++) {
		if (lista->elementos[i] == valor) {
			return i;
		}
	}
	return indice;
}

void apaga(int valor, Lista* lista) {
	int j = 0;
	for (int i; i <= lista->tamanho; i++) {
		if (valor == lista->elementos[i]) {
			j++;
		} else {
			lista->elementos[i-j] = lista->elementos[i];
		}
	}
  lista->tamanho = lista->tamanho - j;
}

void initLista(Lista* lista){
  lista->tamanho=0;
}

void printLista(Lista* lista){
  printf("\n------------------------\n");
  int i;
  for(i=0; i<MAX ;i++ ){
    if(i<lista->tamanho)
      printf("%d-",lista->elementos[i]);
    else
      printf("@-");
  }
  printf("\n------------------------\n\n");
}


int main(void) {
  Lista* lista1 = (Lista*) malloc(sizeof(Lista));
  initLista(lista1);
  printLista(lista1);

  int resultado;

  resultado = inserir(5, 0, lista1);
  resultado = inserir(8, 1, lista1);
  resultado = inserir(9, 2, lista1);
  resultado = inserir(11, 3, lista1);
  resultado = inserir(15, 4, lista1);
  resultado = inserir(22, 5, lista1);
  resultado = inserir(31, 6, lista1);
  printf("Resultado = %d\n",resultado);
  printLista(lista1);
	
	// int numero;
	// printf("Informe um número para ser buscado na lista\n");
	// scanf("%d", &numero);
  // int indice = busca(numero, lista1);

	// if(indice < 0) {
	// 	printf("Indice não encontrado");
	// } else {
	// 	printf("Indice -> %d", indice);
	// }
	
	int numero;
	printf("Informe um número para ser removido da lista\n");
	scanf("%d", &numero);

  apaga(numero, lista1);
  printLista(lista1);

  return 0;
}