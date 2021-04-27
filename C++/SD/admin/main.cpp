#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

#define tamanho 3

struct candidato {
    int numero;
    string sigla;
    string nome;
		int qtdVotos;
} candidatos[tamanho];

void listar(candidato* candidatos){
	for (int i=0; i<tamanho; i++) {
		cout << "Candidato -> " << candidatos[i].nome << " - " << candidatos[i].numero << "|" << candidatos[i].sigla << " - " << candidatos[i].qtdVotos << "Votos." << endl;
	}
}

int main(int argc,char *argv[]){
	int operacao, voto;
	bool votou;

	candidatos[0].numero = 17;
	candidatos[0].sigla = "PCDOB";
	candidatos[0].nome = "Éneias";
	candidatos[0].qtdVotos = 0;
	candidatos[1].numero = 13;
	candidatos[1].sigla = "PT";
	candidatos[1].nome = "Poste";
	candidatos[1].qtdVotos = 0;
	candidatos[2].numero = 22;
	candidatos[2].sigla = "PSL";
	candidatos[2].nome = "Laranja";
	candidatos[2].qtdVotos = 0;
	
	cout << "\nInforme a operacao que deseja:\n1) Listar candidatos\n2) Sair\n\n";
	cin >> operacao;

	while (operacao != 2) {
		cout << "\n" << endl;

		if (operacao == 1) {
			listar(candidatos);
		}
	
		cout << "\nInforme a operacao que deseja:\n1) Listar candidatos\n2) Sair\n\n";
		cin >> operacao;
	}

	cout << "Bye\n";
}
