#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void QuickSort(int vet[], int p, int u);
int particao(int vet[], int p, int u);
void troca(int vet[], int i, int j);

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

	QuickSort(vet, 0, TAMANHOVETOR - 1);

	printf("\nVETOR ORDENADO: \n");
	for (int i = 0; i < TAMANHOVETOR; i++) {
		printf("%d ", vet[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}

void QuickSort(int vet[], int p, int u) // ORDENAR O VETOR
{
	int m; // recebe o valor de comparação
	if (p < u) {
		m = particao(vet, p, u);
		QuickSort(vet, p, m); // esquerdo
		QuickSort(vet, m + 1, u); // direito
	}
}

int particao(int vet[], int p, int u) {
	int pivo, pivo_pos, i, j;

	pivo_pos = (p + u)/2; // posição do meio
	pivo = vet[pivo_pos]; // recebe o valor armazenado na posição do vetor

	i = p - 1;
	j = u + 1;

	while (i < j)
	{
		do // testa o lado direito
		{
			j--;
		} while (vet[j] > pivo);
		do // testa o lado esquerto
		{
			i++;
		} while (vet[i] < pivo);
		if (i < j)
			troca(vet, i, j);
	}
	return j;
}

void troca(int vet[], int i, int j)
{
	int aux;
	aux = vet[i];
	vet[i] = vet[j];
	vet[j] = aux;
}