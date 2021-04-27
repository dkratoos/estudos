#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isVogal (char letra) {
	if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') {
		return true;
	}

	return false;
}

bool isOutraPalavra (char letra) {
	if (letra == '\n') {
		return true;
	}

	return false;
}

int main() {
	int quantidadeString, numeroVogais = 0, numeroPalavras = 0;
	bool isSpace = false;

	printf("Informa a quantidade de string que deseja digitar\n");
	scanf("%d", &quantidadeString);

	char strings[quantidadeString][50], temp;
	scanf("%c", &temp);

	for (int i = 0; i < quantidadeString; i++) {
		printf("Informe a string %d\n", i+1);

		fgets(&strings[i][0], 50, stdin);
	}

	char *resultado = malloc(sizeof(char)* (quantidadeString * 50));

	for (int i = 0; i < quantidadeString; i++) {
		strcat(resultado, &strings[i][0]);
	}

	for (int i = 0; i < strlen(resultado); i++) {
		if (resultado[i] == ' ') {
			isSpace = true;
		} else {
			if (isVogal(resultado[i])) {
				numeroVogais++;
			}

			if (isOutraPalavra(resultado[i]) || isSpace == true) {
				numeroPalavras++, isSpace = false;
			}
		}
	}

	int tamanhoStringResultado = strlen(resultado) - 1*quantidadeString;

	printf("\nConteudo da String resultado: %s\nTamanho da String resultado: %d\nQuantidade de Vogais: %d\nQuantidade de Palavras: %d\n", resultado, tamanhoStringResultado, numeroVogais, numeroPalavras);

	for (int i = 0; i < quantidadeString; i++) {
		int tamanhoString = strlen(&strings[i][0]) - 1;
		printf("tamanho %d - %s", tamanhoString, &strings[i][0]);
	}

	free(resultado);
	printf("Bye\n");
	return 0;
}