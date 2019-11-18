#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
// constante que define o tamanho do vetor
#define Max 3
// Valor da precisao.
unsigned short int e = 0;

unsigned short int ValidarNumero(char arr[], int tam);
void IniciarValores(double A[Max], double E[Max]);
void IniciarVetores(double V[]);
void MostrarVetor(double V[], char msg[]);
double AplicarPrecisao(double num);

void main()
{
	char entrada[] = "x²-5x+6";
	
	char continuar = 's';
	do
	{
		char a[] = "x-1";
		char b[] = "x-3";
		
		char teste[20];
		
	} while (continuar == 's' || continuar == 'S');

	//================================================
	printf("\n\n\n");
	system("pause");
	system("cls");
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
