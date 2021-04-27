#include <iostream>
#include <cstdlib>
#include <time.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

//método quicksort -  START
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int partition (int* vector, int low, int high) {
	int pivot = vector[high];
	int i = (low - 1);  

	for (int j = low; j <= high- 1; j++) {
		if (vector[j] <= pivot) {
			i++;
			swap(vector[i], vector[j]);
		}
	}

	swap(vector[i + 1], vector[high]);
	return (i + 1);
}

void ordenaQuick(int *vector, int low, int high) {
	if (low < high) {
		int pi = partition(vector, low, high);

		ordenaQuick(vector, low, pi - 1);
		ordenaQuick(vector, pi + 1, high);
	}
}
//end QUICKSORT

void randomVector (int tamanho,int* vector) {
	for (int i=0;i<tamanho;i++) {
		vector[i] = rand() % (tamanho * 10) + 1;
		cout << "Posição " << i << " valor= " << vector[i] << endl;
	}
}

int IsIn (int chave, int *vetor, int tamanho){
	auto start = high_resolution_clock::now();

	int posicao = -1;

	for (int i = 0; i < tamanho; i++) {
		if (chave == vetor[i]) {
			posicao = i;
		}
	}

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);
	cout << "Tempo de duração da f(x): " << duration.count() << " nanoseconds" << endl;

	return posicao;
}

int IsBinario (int chave, int* vector, int tamanho) {
	auto start = high_resolution_clock::now();

	int inicio = 0, fim = tamanho - 1;

	while (inicio <= fim) {
		int m = inicio + (fim - inicio) / 2;

		if (vector[m] == chave) {
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<nanoseconds>(stop - start);
			
			cout << "Tempo de duração da f(x): " << duration.count() << " nanoseconds" << endl;
			return m;
		}

		if (vector[m] < chave) { inicio = m + 1; }
	
		else { fim = m - 1; }
	}

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Tempo de duração da f(x): " << duration.count() << " nanoseconds" << endl;

	return -1;
}

int IsBinarioRecursivo (int chave, int* vector, int inicio, int fim) { 
	if (fim >= inicio) {
		int mid = fim + (inicio - fim) / 2;

		if (vector[mid] == chave) { return mid; }

		if (vector[mid] > chave) { return IsBinarioRecursivo(chave, vector, inicio,mid-1); }

		return IsBinarioRecursivo(chave, vector, mid + 1, fim);
	}

	return -1;
}

void print(int* vector, int tamanho){
	cout << "---- VETOR ORDENADO -----" << endl;
	for(int i=0;i<tamanho;i++){
		cout << "Posição " << i << " valor= " << vector[i] << endl;
	}
}

int main(int argc,char *argv[]){
	int tamanho, number, posicao, operacao;

	cout << "Digite o tamanho do vetor (Minimo 100)." << endl;
	cin >> tamanho;

	while (tamanho < 100) { 
		cout << "Tamanho menor que 100, por favor insira um valor maior." << endl; 
		cin >> tamanho;
	}

	//criar vetor com valores random
	int vetor[tamanho];

	cout << "\nInforme a operacao que deseja:\n1) Listar\n2) Ordenar\n3) Buscar\n4) Busca binaria\n5) Busca binaria recursiva\n6)sair\n";
	cin >> operacao;

	while (operacao != 6) {
		if (operacao == 1) {
			print(vetor, tamanho);		
		}
		if (operacao == 2) {
			ordenaQuick(vetor, 0, tamanho-1);
			cout << "\nVetor ordenado" << endl;
		}
		if (operacao == 3) {
			cout << "\nDigite o número que deseja encontrar" << endl;
			cin >> number;

			posicao = IsIn(number, vetor, tamanho);
			cout << "Sua posição é: " << posicao << endl;
		}
		if (operacao == 4) {
			cout << "\nDigite o número que deseja encontrar" << endl;
			cin >> number;

			posicao=IsBinario(number, vetor, tamanho);
			cout << "Sua posição é: "<< posicao << endl;
		}
		if (operacao == 5) {
			cout << "\nDigite o número que deseja encontrar" << endl;
			cin >> number;

			auto start = high_resolution_clock::now();

			posicao = IsBinarioRecursivo(number, vetor, 0, tamanho-1);

			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<nanoseconds>(stop - start);
			cout << "Tempo de duração da f(x): " << duration.count() << " nanoseconds" << endl;

			cout << "Sua posição é: " << posicao << endl;
		}

		cout << "\nInforme a operacao que deseja:\n1) Listar\n2) Ordenar\n3) Buscar\n4) Busca binaria\n5) Busca binaria recursiva\n6)sair\n";
		cin >> operacao;
	}

	cout << "Bye\n";
}
