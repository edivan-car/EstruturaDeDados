#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int BuscaSequencial(int vet[], int buscado);

#define TAMANHOVETOR 10

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int buscado, achou;
	int vet[TAMANHOVETOR] = { 0 };

	srand(time(NULL));

	// INSER��O DE DADOS
	for (int i = 0; i < TAMANHOVETOR; i++)
		vet[i] = rand() % 1000;

	printf("VETRO GERADO:\n");
	for (int i = 0; i < TAMANHOVETOR; i++)
	{
		printf("%d\n", vet[i]);
	}

	printf("Selecione um valor para busca: \n");
	scanf_s("%d", &buscado);

	achou = BuscaSequencial(vet, buscado);
	if (achou == -1)
		printf("Valor n�o encontrado.");
	else
		printf("Valor encontrado na posi��o %d. \n", achou);

	system("pause");
	return 0;
}

int BuscaSequencial(int vet[], int buscado)
{
	int achou, i;
	achou = 0;
	i = 0;

	while ((i <= TAMANHOVETOR) && (achou == 0))
	{
		if (vet[i] == buscado)
			achou = 1;
		else
			i++;
	}
	if (achou == 0)
		return -1;
	else
		return i + 1;
}