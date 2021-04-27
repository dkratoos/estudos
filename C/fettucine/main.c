#include <stdio.h>

int main(void) {
	int limite, primeiroTermo, segundoTermo, resultado;

	printf("Informe o primeiro e segundo termo e depois até qual termo deseja conhecer a sequência Fettuccine (No minimo 3).\n");
	scanf("%d", &primeiroTermo);
	scanf("%d", &segundoTermo);
	scanf("%d", &limite);

	while (limite < 3) {
		printf("Informe um limite valido (No minimo 3).\n");
		scanf("%d", &limite);
	}

	printf("Sequencia Fettuccine\n");
	printf("%d -> %d -> ", primeiroTermo, segundoTermo);

	for (int i = 0; i < limite - 2; i++) {
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