#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

#define Max 3

unsigned short int e = 0;

void ProdutoVetorial(double v[Max], double e[Max], double aV[Max]);
double AreaVetor(double aV[Max]);
unsigned short int ValidarNumero(char arr[], int tam);
void IniciarValores(double A[Max], double E[Max]);
void IniciarVetores(double V[]);
void MostrarVetor(double V[], char msg[]);
double AplicarPrecisao(double num);

void main()
{
	double V[Max]; // = {1, 2, 3};
	double E[Max]; // = {3, 2, 1};
	double aV[Max];

	char continuar = 's';
	do
	{
		IniciarValores(V, E);
		//fazendo o produto vetorial entre V e E;
		ProdutoVetorial(V, E, aV);
		//Mostrando informacoes dos vetores.
		printf("\nPrecisao (E) informada pelo usuario: %hu\n\n", e);
		MostrarVetor(V, "Vetor V (Informado pelo usuario):");
		MostrarVetor(E, "\nVetor E (Informado pelo usuario):");
		MostrarVetor(aV, "\nVxE (Produto vetorial):");
		//Calculando a area do vetor
		printf("\n\nCalculo da area |VxE|: %.*lf (m)\n", e, AreaVetor(aV));

		printf("\n\nDeseja executar o programa novamente? (S/N): ");
		scanf(" %c", &continuar);
	} while (continuar == 's' || continuar == 'S');

	//================================================
	printf("\n\n\n");
	system("pause");
	system("cls");
}

void ProdutoVetorial(double v[Max], double e[Max], double aV[Max])
{
	aV[0] = (v[1] * e[2]) - (v[2] * e[1]);
	aV[1] = (v[2] * e[0]) - (v[0] * e[2]);
	aV[2] = (v[0] * e[1]) - (v[1] * e[0]);
}

double AreaVetor(double aV[Max])
{
	return sqrt(aV[0] * aV[0] + aV[1] * aV[1] + aV[2] * aV[2]);
}
/*
	0 - Nao eh um numero
	1 - eh um numero
*/
unsigned short int ValidarNumero(char arr[], int tam)
{
	unsigned short int qtdPontos = 0;
	for (unsigned int i = 0; i < tam; i++)
	{
		if (arr[i] == '\0')
		{
			arr[i] = (qtdPontos == 1) ? '0' : '\0';
			break;
		}
		if (arr[i] == '-' && i == 0)
			continue;

		if (arr[i] == '.')
		{
			qtdPontos++;
			if (qtdPontos > 1)
				return 0;

			if (isdigit(arr[i - 1]) && isdigit(arr[i + 1]))
				continue;
		}

		if (isdigit(arr[i]) != 1)
			return 0;
	}
	return 1;
}

void IniciarValores(double A[Max], double E[Max])
{
	double aux;
	char entrada[100];

	while (true)
	{
		system("cls");
		puts("\n"
			 "Informe um numero inteiro e positivo para a precisao (E)\n"
			 "Note que o numero eh referente a quantidade de casas decimais\n"
			 "Ex: 4 -> 3.1415, 1 -> 3.1, 0 -> 3\n"
			 "Valor: ");
		scanf("%s", entrada);
		if (ValidarNumero(entrada, sizeof(entrada) / sizeof(char) - 1))
		{
			e = atoi(entrada);
			break;
		}
	}

	printf("\n\n=-=-=-=-=-= Valores do vetor =-=-=-=-=-=\n");
	printf("-------------- Vetor V --------------\n");
	IniciarVetores(A);
	printf("-------------- Vetor E --------------\n");
	IniciarVetores(E);

	system("cls");
}

void IniciarVetores(double V[])
{
	char entrada[100];
	double aux;
	for (int i = 0; i < Max; i++)
	{
		printf("Informe o elemento (%c): ", 105 + i);
		while (true)
		{
			scanf("%s", entrada);
			if (ValidarNumero(entrada, sizeof(entrada) / sizeof(char) - 1))
			{
				aux = atof(entrada);
				V[i] = AplicarPrecisao(aux);
				break;
			}
			else
			{
				puts("Por favor informe um numero valido.\n"
					 "Caracteres especiais e expressoes nao sao permitidas.\n"
					 "Ex: 4, -3.55654, 0.\n"
					 "valor: ");
			}
		}
	}
}

void MostrarVetor(double V[], char msg[])
{
	printf("%s\n", msg);
	for (int i = 0; i < Max; i++)
	{
		printf("%.*lf%c\t", e, V[i], 105 + i);
	}
	printf("\n");
}

double AplicarPrecisao(double num)
{
	return floor(pow(10, e) * num) / pow(10, e);
}
