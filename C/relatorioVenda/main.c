#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  int codigo;
  int validade;
  int quantidade;
  float preco;
  char descricao[25];
} Produto;

int qtdProdutos = 5;

int relatorioVencido (Produto *listaProdutos) {
 	for (int i = 0; i < qtdProdutos; i++) {
		if (listaProdutos[i].validade < 2020) {
			printf("Produto %s - Validade: %d -> Quantidade: %d -> Preço: %.2f\n", listaProdutos[i].descricao, listaProdutos[i].validade, listaProdutos[i].quantidade, listaProdutos[i].preco);
		}
	}

	return 0;
}

int relatorioValorMenor (Produto *listaProdutos, int valor) {
 	for (int i = 0; i < qtdProdutos; i++) {
		if (listaProdutos[i].preco < valor) {
			printf("Produto %s - Validade: %d -> Quantidade: %d -> Preço: %.2f\n", listaProdutos[i].descricao, listaProdutos[i].validade, listaProdutos[i].quantidade, listaProdutos[i].preco);
		}
	}

	return 0;
}

int relatorioCompleto (Produto *listaProdutos) {
 	for (int i = 0; i < qtdProdutos; i++) {
		printf("Produto %s - Validade: %d -> Quantidade: %d -> Preço: %.2f\n", listaProdutos[i].descricao, listaProdutos[i].validade, listaProdutos[i].quantidade, listaProdutos[i].preco);
	}

	return 0;
}

int relatorioValorTotal (Produto *listaProdutos) {
 	for (int i = 0; i < qtdProdutos; i++) {
		printf("Produto %s - Quantidade: %d -> Preço: %.2f -> Preço Total do produto: %.2f\n", listaProdutos[i].descricao, listaProdutos[i].quantidade, listaProdutos[i].preco, listaProdutos[i].preco * listaProdutos[i].quantidade);
	}

	return 0;
}

int cadastrar (Produto *listaProdutos) {
	// Incrementa Contador de produtos
	qtdProdutos++;

	// Aloca posi�es no ponteiro de produtos de acordo com a quantidade do contador
	listaProdutos = (Produto*) realloc(listaProdutos, qtdProdutos*sizeof(Produto));
	
	listaProdutos[qtdProdutos - 1].codigo = qtdProdutos;

	printf("Informe a descricao do produto\n");
	scanf("%s", listaProdutos[qtdProdutos - 1].descricao);

	printf("Informe a validade do produto\n");
	scanf("%d", &listaProdutos[qtdProdutos - 1].validade);

	printf("Informe a quantidade do produto\n");
	scanf("%d", &listaProdutos[qtdProdutos - 1].quantidade);
	while (listaProdutos[qtdProdutos - 1].quantidade <= 0) {
		printf("Quantidade precisa ser maior que 0, por favor, informe a quantidade novamente\n");
		scanf("%d", &listaProdutos[qtdProdutos - 1].quantidade);
	}

	printf("Informe o preco do produto\n");
	scanf("%f", &listaProdutos[qtdProdutos - 1].preco);
	while (listaProdutos[qtdProdutos - 1].preco <= 0) {
		printf("Preço precisa ser maior que 0, por favor, informe a preço novamente\n");
		scanf("%f", &listaProdutos[qtdProdutos - 1].preco);
	}

	printf("Produto %s cadastrado com sucesso!\n", listaProdutos[qtdProdutos - 1].descricao);

	relatorioValorTotal(listaProdutos);
	return 0;
}

int main(void) {
  Produto *listaProdutos = (Produto*) malloc(sizeof(Produto) * 5);

	listaProdutos[0].codigo = 1;
	listaProdutos[0].validade = 2019;
	listaProdutos[0].quantidade = 3;
	listaProdutos[0].preco = 2.50;
	strcpy(listaProdutos[0].descricao, "pacote de pão");

	listaProdutos[1].codigo = 2;
	listaProdutos[1].validade = 2020;
	listaProdutos[1].quantidade = 5;
	listaProdutos[1].preco = 3.50;
	strcpy(listaProdutos[1].descricao, "duzia de ovos");

	listaProdutos[2].codigo = 3;
	listaProdutos[2].validade = 2018;
	listaProdutos[2].quantidade = 10;
	listaProdutos[2].preco = 12;
	strcpy(listaProdutos[2].descricao, "massa de bolo");

	listaProdutos[3].codigo = 4;
	listaProdutos[3].validade = 2002;
	listaProdutos[3].quantidade = 1;
	listaProdutos[3].preco = 2.50;
	strcpy(listaProdutos[3].descricao, "farinha de trigo");

	listaProdutos[4].codigo = 5;
	listaProdutos[4].validade = 2021;
	listaProdutos[4].quantidade = 11;
	listaProdutos[4].preco = 15;
	strcpy(listaProdutos[4].descricao, "kilo de queijo");

	int operacao;
	float valor;
	
	printf("Informe a operacao que deseja:\n1) Cadastrar\n2) Relatório dos produtos vencidos\n3) Relatório por valor inferior\n4) Relatório completo\n5) Relatório com valor total\n6) Sair\n");
	scanf("%d", &operacao);
	
	while (operacao != 6) {
		switch (operacao) {
			case 1:
				cadastrar(listaProdutos);
				break;
			case 2:
				relatorioVencido(listaProdutos);
				break;
			case 3:
				printf("Informe um valor para ser usado no relatório\n");
				scanf("%f", &valor);

				relatorioValorMenor(listaProdutos, valor);
				break;
			case 4:
				relatorioCompleto(listaProdutos);
				break;
			case 5:
				relatorioValorTotal(listaProdutos);
				break;
		}

		printf("<--------------------------->\n");
		printf("Informe a operacao que deseja:\n1) Cadastrar\n2) Relatório dos produtos vencidos\n3) Relatório por valor inferior\n4) Relatório completo\n5) Relatório com valor total\n6) Sair\n");
		scanf("%d", &operacao);
	}

	printf("Bye Bye\n");
	free(listaProdutos);

  return 0;
}