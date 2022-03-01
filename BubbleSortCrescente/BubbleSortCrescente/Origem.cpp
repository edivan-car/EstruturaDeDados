#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int vet[]);

#define TAMANHOVETOR 10

int main()
{
	int vet[TAMANHOVETOR] = { 0 };
	srand(time(NULL)); // gera a semente aleatória

	// INSERÇÃO DE DADOS
	for (int i = 0; i < TAMANHOVETOR; i++) {
		vet[i] = rand() % 100; // gera valores aleatórios de 0 à 99
	}

	printf("VETOR NAO ORDENADO: \n");
	for (int i = 0; i < TAMANHOVETOR; i++) {
		printf("%d ", vet[i]);
	}

	BubbleSort(vet);

	printf("\nVETOR ORDENADO: \n");
	for (int i = 0; i < TAMANHOVETOR; i++) {
		printf("%d ", vet[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}

void BubbleSort(int vet[]) // ORDENAR O VETOR
{
	int aux;
	for (int n = 0; n <= TAMANHOVETOR; n++) {
		for (int i = 0; i < (TAMANHOVETOR - 1); i++) {
			if (vet[i] > vet[i + 1]) { // CRESCENTE para DECRESCENTE mudar > para <
				aux = vet[i];
				vet[i] = vet[i + 1];
				vet[i + 1] = aux;
			}
		}
	}
}