#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

#define tamanho 3

struct candidato {
    int numero;
    string sigla;
    string nome;
} candidatos[tamanho];

void listar(candidato* candidatos){
	for(int i=0;i<tamanho;i++){
		cout << "Candidato -> " << candidatos[i].nome << " - " << candidatos[i].numero << "|" << candidatos[i].sigla << endl;
	}
}

candidato findCandidato(int numero) {
	candidato cand;
	cand.nome = "falso";

	bool flag;

	for(int i=0;i<tamanho;i++){
		if (candidatos[i].numero == numero) {
			cand = candidatos[i];
		}
	}

	if (cand.nome == "falso") {
		cout << "\nCandidato não existente, por favor informe outro número.\n" << endl;
	}

	return cand;
}

bool votar(int numero) {
	candidato cand = findCandidato(numero);
	char operacao;

	if (cand.nome == "falso") { return false; }

	cout << "\nTem certeza que deseja votar no candidato: " << cand.nome << "|" << cand.sigla << "? S/N" << endl;
	cin >> operacao;

	if (operacao == 'S') {
		return true;
	}

	return false;
}

int main(int argc,char *argv[]){
	int operacao, voto;
	bool votou;

	candidatos[0].numero = 17;
	candidatos[0].sigla = "PCDOB";
	candidatos[0].nome = "Éneias";
	candidatos[1].numero = 13;
	candidatos[1].sigla = "PT";
	candidatos[1].nome = "Poste";
	candidatos[2].numero = 22;
	candidatos[2].sigla = "PSL";
	candidatos[2].nome = "Laranja";
	
	cout << "\nInforme a operacao que deseja:\n1) Listar candidatos\n2) Enviar voto\n3) Sair\n\n";
	cin >> operacao;

	while (operacao != 3) {
		cout << "\n" << endl;

		if (operacao == 1) {
			listar(candidatos);
		}

		if (operacao == 2) {
			votou = false;

			while (votou == false) {
				cout << "Informe o número do candidato que você deseja votar." << endl;
				cin >> voto;
				votou = votar(voto);
			}

			cout << "\nVoto computado, obrigado." << endl;
		}
	
		cout << "\nInforme a operacao que deseja:\n1) Listar candidatos\n2) Enviar voto\n3) Sair\n\n";
		cin >> operacao;
	}

	cout << "Bye\n";
}
