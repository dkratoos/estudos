#include <stdio.h>

int progressaoGeometrica (int primeiroTermo, int razao, int limite) {
	int resultado = primeiroTermo;
	printf("Progressao Geometrica\n");
	printf("%d -> ", primeiroTermo);

	for (int i = 0; i < limite; i++) {
		resultado = resultado * razao;
		printf("%d -> ", resultado);
	}

	return 0;
}

int sequenciaFibonacci (int limite) {
	int primeiroTermo = 0, segundoTermo = 1, resultado;
	printf("Sequencia Fibonacci\n");
	printf("%d -> %d -> ", primeiroTermo, segundoTermo);

	for (int i = 0; i < limite; i++) {
		resultado = primeiroTermo + segundoTermo;
		printf("%d -> ", resultado);
		primeiroTermo = segundoTermo, segundoTermo = resultado;
	}

	return 0;
}

int sequenciaFettuccine (int primeiroTermo, int segundoTermo, int limite) {
	int resultado;
	printf("Sequencia Fettuccine\n");
	printf("%d -> %d -> ", primeiroTermo, segundoTermo);

	for (int i = 0; i < limite; i++) {
		if ((i + 3) % 2 == 0) {
			resultado = segundoTermo - primeiroTermo;
		} else {
			resultado = primeiroTermo + segundoTermo;			
		}
		printf("%d -> ", resultado);
		primeiroTermo = segundoTermo, segundoTermo = resultado;
	}

	return 0;
}

int main() {
	int operacao, index, primeiroTermo, razao, limite, segundoTermo;

	printf("Informe a operacao que deseja:\n1) Progressao Geometrica\n2) Sequencia Fibonacci\n3) Sequencia Fettuccine\n4) Sair\n");
	scanf("%d", &operacao);
	
	while (operacao != 4) {
		switch (operacao) {
			case 1:
				printf("Informe o primeiro termo, a razão e até que termo deseja ver a PG (No minimo 3).\n");
				scanf("%d", &primeiroTermo);
				scanf("%d", &razao);
				scanf("%d", &limite);

				if (limite < 3) {
					printf("Limite da PG menor que 3, tente novamente.");
					break;
				}

				progressaoGeometrica(primeiroTermo, razao, limite);
				break;
			case 2:
				printf("Informe até qual termo deseja conhecer a sequência Fibonacci (No minimo 3).\n");
				scanf("%d", &limite);

				if (limite < 3) {
					printf("Limite da Sequencia Fibonacci menor que 3, tente novamente.");
					break;
				}

				sequenciaFibonacci(limite);
				break;
			case 3:
				printf("Informe o primeiro e segundo termo e depois até qual termo deseja conhecer a sequência Fettuccine (No minimo 3).\n");
				scanf("%d", &primeiroTermo);
				scanf("%d", &segundoTermo);
				scanf("%d", &limite);

				if (limite < 3) {
					printf("Limite da Sequencia Fettuccine menor que 3, tente novamente.");
					break;
				}

				sequenciaFettuccine(primeiroTermo, segundoTermo, limite);
				break;
		}

		printf("\n<--------------------------->\n");
		printf("Informe a operacao que deseja:\n1) Progressao Geometrica\n2) Sequencia Fibonacci\n3) Sequencia Fettuccine\n4) Sair\n");
		scanf("%d", &operacao);
	}
	
	printf("Bye\n");
	return 0;
}