#include <stdlib.h>
#include <stdio.h>

#define Max 2

void CalcularDeterminante(float M[Max][Max], float *detM){
	float aux[Max];
	aux[0] = M[0][0] * M[1][1];
	aux[1] = M[0][1] * M[1][0];
	*detM = aux[0] - aux[1];
}
/*
	{ ax + by = b1
	{ mx + ny = b2
	
	D1 = [ a  b ]  ;  D2 = [ a  b1 ]	;	D3 = [ b1 b ]
		 [ m  n ]		   [ m  b2 ]			 [ b2 n ]
	
		 D2   			 D3
	Y1 = __		;	Y2 = __
		 D1				 D1
	
	Di != 0
	i = [ 1, 2, 3 ]
		 
	   |		 K ( numero qualquer != 0)
	se |	Yi = __  	[ Infinitas soluçoes ]  (*)
	   |		 0
		 
	   |		 0 
	se |	Yi = __  	[ Impossivel de determinar ]  (**)
	   |		 0
	   
	senao [ Possivel de determinar ]  (***)
	
	0 - (*)
	1 - (**)
	2 - (***)
*/
unsigned short int VerificarResultadoDeterminante(float M[Max][Max], float v[Max]){
	float D1[Max][Max] = { { M[0][0], M[0][1] }, { M[1][0], M[1][1] } };
	float D2[Max][Max] = { { M[0][0], v[0] }, { M[1][0], v[1] } };
	float D3[Max][Max] = { { v[0], M[0][1] }, { v[1], M[1][1] } };
	
	float det1, det2, det3;
	CalcularDeterminante(D1, &det1);
	CalcularDeterminante(D2, &det2);
	CalcularDeterminante(D3, &det3);
	
	if ((det2 != 0 || det3 != 0) && det1 == 0){
		printf("Infinitas soluçoes\n");
		return 0;
	}
	else if ((det2 == 0 || det3 == 0) && det1 == 0){
		printf("Impossivel de determinar\n");
		return 1;
	}
	else
		return 2;
}

void main()
{
	float A[Max][Max] = { {2, 4}, {8, 16} };
	float b[Max] = { 1, 4 };

	VerificarResultadoDeterminante(A, b);
	
	//================================================
	printf("\n\n\n");
	system("pause");
	system("cls");
}
