#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
// constante que define o tamanho da matriz/vetor
#define Max 2
// Valor da precisao.
unsigned short int e = 0;

void MostrarMatriz(double M[Max][Max]);
void MostrarVetor(double V[], int size);
void MultiplicarMatrizPorVetor(double A[Max][Max], double vetor[Max], double saida[Max]);
double AplicarPrecisao(double num);
unsigned short int VerificarMatrizNula(double A[Max][Max]);
double CalcularDeterminante(double M[Max][Max]);
unsigned short int VerificarResultadoDeterminante(double M[Max][Max], double v[Max]);
void CalcularInversaA(double A[Max][Max], double _A[Max][Max], double detA);
void IniciarValores(double A[Max][Max], double b[Max]);
unsigned short int ValidarNumero(char arr[Max], int tam);
unsigned short int VerificarVetorIgual(double V1[], double V2[]);

int main()
{
    // matriz informada pelo usuario
    double A[Max][Max]; // = { { 1, 2 },  { 3, 4 } };
    // matriz inversa da matriz informada pelo usuario
    double _A[Max][Max];
    // vetor informado pelo usuario.
    double b[Max]; // = { 1, 2 };
    // solucao do sistema linear
    double X[Max];
    // vetor resultante da multiplicacao de A por X
    double AX[Max];

    // variavel guarda a opcao escolhida pelo usuario para continuar ou nao a
    // execucao do programa.
    char continuar = 's';
    do
    {
        system("cls");
        // iniciando os valores da matriz e vetor
        IniciarValores(A, b);
        // verificando se o determinante eh nulo.
        if (VerificarResultadoDeterminante(A, b) == 2)
        {
            // calculando determinante da matriz A.
            double detA = CalcularDeterminante(A);

            // mostrando dados informados pelo usuario.
            printf("\nMatriz A: \n");
            MostrarMatriz(A);
            printf("\nVetor b: \n");
            MostrarVetor(b, Max);
            // mostrando o valor do determinante.
            printf("\nDeterminante de A: %.*f\n", e, detA);
            // Calculando inversa da matriz A e mostrando o seu valor.
            CalcularInversaA(A, _A, detA);
            printf("\nMatriz inversa A: \n");
            MostrarMatriz(_A);
            // Calculando a solusao do sistema linear e mostrando o seu valor.
            printf("\nVetor X: \n");
            MultiplicarMatrizPorVetor(_A, b, X);
            MostrarVetor(X, Max);
            MultiplicarMatrizPorVetor(A, X, AX);
            if (VerificarVetorIgual(AX, b))
                puts("\n\nPortanto, X eh a solucao do sistema linear.");
            else
                puts("\n\nLogo, X nao eh a solucao do sistema linear.");
        }
        printf("\n\nDeseja executar o programa novamente? (S/N): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    //================================================
    printf("\n\n\n");
    system("pause");
    system("cls");

    return 0;
}
/*
    0 - Nao sao iguais
    1 - sao iguais.
*/
unsigned short int VerificarVetorIgual(double V1[], double V2[])
{
    for (unsigned int i = 0; i < Max; i++)
    {
        if (V1[i] != V2[i])
            return 0;
    }
    return 1;
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
            arr[i] = '0';
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

void IniciarValores(double A[Max][Max], double b[Max])
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

    printf("\n=-=-=-=-=-= Valores da matriz =-=-=-=-=-=\n");
    for (int i = 0; i < Max; i++)
    {
        for (int j = 0; j < Max; j++)
        {
            printf("Informe o elemento (%i,%i): ", i, j);
            while (true)
            {
                scanf("%s", entrada);
                if (ValidarNumero(entrada, sizeof(entrada) / sizeof(char) - 1))
                {
                    aux = atof(entrada);
                    A[i][j] = AplicarPrecisao(aux);
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

    printf("\n\n=-=-=-=-=-= Valores do vetor =-=-=-=-=-=\n");
    for (int i = 0; i < Max; i++)
    {
        printf("Informe o elemento (%i): ", i);
        while (true)
        {
            scanf("%s", entrada);
            if (ValidarNumero(entrada, sizeof(entrada) / sizeof(char) - 1))
            {
                aux = atof(entrada);
                b[i] = AplicarPrecisao(aux);
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
    system("cls");
}

void MostrarMatriz(double M[Max][Max])
{
    for (int i = 0; i < Max; i++)
    {
        MostrarVetor(M[i], Max);
        puts("\n");
    }
}

void MostrarVetor(double V[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%.*lf\t", e, V[i]);
    }
}

void MultiplicarMatrizPorVetor(double A[Max][Max], double vetor[Max], double saida[Max])
{
    double aux[Max];

    for (int i = 0; i < Max; i++)
    {
        for (int j = 0; j < Max; j++)
        {
            aux[j] = A[i][j] * vetor[j];
        }
        saida[i] = aux[0] + aux[1];
    }
}

double AplicarPrecisao(double num)
{
    return floor(pow(10, e) * num) / pow(10, e);
}

unsigned short int VerificarMatrizNula(double A[Max][Max])
{
    for (int i = 0; i < Max; i++)
    {
        for (int j = 0; j < Max; j++)
        {
            if (A[i][j] != 0)
            {
                return 0;
            }
        }
    }

    return 1;
}

double CalcularDeterminante(double M[Max][Max])
{
    return M[0][0] * M[1][1] - M[0][1] * M[1][0];
}

/*
    { ax + by = b1
    { mx + ny = b2

    D1 = [ a  b ]  ;  D2 = [ a  b1 ]    ;    D3 = [ b1 b ]
         [ m  n ]          [ m  b2 ]              [ b2 n ]

         D2                  D3
    Y1 = __        ;    Y2 = __
         D1                  D1

    Di != 0
    i = [ 1, 2, 3 ]

             |         K ( numero qualquer != 0)
          se |    Yi = __      [ Infinitas solucoes ]  (*)
             |         0

             |         0
    senao se |    Yi = __      [ Impossivel de determinar ]  (**)
             |         0

       senao     [ Possivel de determinar ]  (***)

    0 - (*)
    1 - (**)
    2 - (***)
    -1 - Matriz nula
*/
unsigned short int VerificarResultadoDeterminante(double M[Max][Max], double v[Max])
{
    if (VerificarMatrizNula(M) == 1)
    {
        printf("====================================\n");
        printf("=     Matriz informada eh nula     =\n");
        printf("====================================\n\n");

        return -1;
    }

    double D1[Max][Max] = {{M[0][0], M[0][1]}, {M[1][0], M[1][1]}};
    double D2[Max][Max] = {{M[0][0], v[0]}, {M[1][0], v[1]}};
    double D3[Max][Max] = {{v[0], M[0][1]}, {v[1], M[1][1]}};

    double det1 = CalcularDeterminante(D1);
    double det2 = CalcularDeterminante(D2);
    double det3 = CalcularDeterminante(D3);

    if ((det2 != 0 || det3 != 0) && det1 == 0)
    {
        printf("====================================\n");
        printf("=        Infinitas Solucoes        =\n");
        printf("====================================\n\n");

        return 0;
    }
    else if ((det2 == 0 || det3 == 0) && det1 == 0)
    {
        printf("====================================\n");
        printf("=     Impossivel de Determinar     =\n");
        printf("====================================\n\n");

        return 1;
    }
    else
    {
        return 2;
    }
}

void CalcularInversaA(double A[Max][Max], double _A[Max][Max], double detA)
{
    double aux[Max][Max];

    for (int i = 0; i < Max; i++)
    {
        for (int j = 0; j < Max; j++)
        {
            if (i == j)
                aux[i][j] = (i == 0) ? A[i + 1][j + 1] : A[i - 1][j - 1];
            else
                aux[i][j] = A[i][j] * -1;
        }
    }
    // fazendo a multiplicacao do determinante pela matriz inversa.
    for (int i = 0; i < Max; i++)
    {
        for (int j = 0; j < Max; j++)
        {
            _A[i][j] = aux[i][j] * (1.0 / detA);
        }
    }
}
