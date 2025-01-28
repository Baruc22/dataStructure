#include <stdio.h>

int main ()
{
	int y,n,x=10;
	printf("\n\n");
	printf("\tVALOR>> ");
	scanf("%d",&n);
	printf("\n");
	printf("\t%d ",n);
	printf("ES MENOR QOE 10");
	
	//Uso del operador ternario.
	y=n<x?1:2;
	//1=verdadero
	//2=falso
	
	if (y==1)
	{
		printf("\n\n");
		printf("\tVERDADERO\n");
		printf("\n");
	}
	else
	{
		printf("\n\n");
		printf("\tFALSO\n");
		printf("\n");
	}
	return 0;
}
