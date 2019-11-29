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
void IniciarValores();
double AplicarPrecisao(double num);
void IniciarValoresIndices(double *i, char msg[100]);

double CalcularDelta(double a, double b, double c)
{
	return ((b*b) - (4*a*c));
}

void ProcurarRaizes(double a, double b, double delta, double S[2])
{
	S[0] = (-b + sqrt(delta))/(2.0*a);
	S[1] = (-b - sqrt(delta))/(2.0*a);
}

void main()
{
	double a, b, c;
	double S[2]; //Chi
	double delta;
	
	char continuar = 's';
	
	do
	{
		IniciarValores();
		IniciarValoresIndices(&a, "Informe o valor de \'a\': ");
		IniciarValoresIndices(&b, "Informe o valor de \'b\': ");
		IniciarValoresIndices(&c, "Informe o valor de \'c\': ");
		
		if(a == 0)
		{
			puts("\n============================================\n"
				 "=     O valor de \'a\' nao pode ser nulo.    =\n"
				 "= Por favor, informe os valores novamente. =\n"
				 "============================================");
			fflush(stdin);
			scanf("%lf", &c);
			system("cls");
			continue;
		}
		
		if((int)b % (int)a== 0 && (int)c % (int)a == 0)
		{
			delta = CalcularDelta(a, b, c);
			ProcurarRaizes(a, b, delta, S);
			//printf("%lf\n", delta);
			printf("%lf|%lf", S[0], S[1]);
			
			if(a*(S[1]+S[0]) == b && a*(S[1]*S[0]) == c)
			{
				printf("Logo, S¹ (%.*lf) e S² (%.*lf) sao as raizes do Polinomio.", e, S[0], S[1]);
			}
		}
		else
		{
			printf("Nao eh possivel fazer a simplificacao por %.*lf.\n", e, a);
		}
		
		printf("\n\nDeseja executar o programa novamente? (S/N): ");
		fflush(stdin);
		scanf("%c", &continuar);
		
	} while (continuar == 's' || continuar == 'S');

	//=============================================
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

void IniciarValores()
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

	system("cls");
}

void IniciarValoresIndices(double *i, char msg[100])
{
	printf("%s", msg);
	char entrada[100];
	
	while (true)
	{
		scanf("%s", entrada);
		if (ValidarNumero(entrada, sizeof(entrada) / sizeof(char) - 1))
		{
			*i = AplicarPrecisao(atoi(entrada));
			break;
		}
		else
		{
			puts("Por favor informe um numero valido.\n"
			 "Caracteres especiais e expressoes nao sao permitidas.\n"
			 "Ex: 4, -3.55654, 0\n"
			 "valor: ");
		}
	}
}

double AplicarPrecisao(double num)
{
	return floor(pow(10, e) * num) / pow(10, e);
}
