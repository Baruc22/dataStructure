#include <stdio.h>
#include "Fibonacci.h"

int main()
{
	printf("\n\tFIBONACCI DE>> 4");
	printf("\n");
	printf("\tRESULTADO DE LA FUNCION ITERATIVA>> %d", Fibo_Itera(4));
	printf("\n");
	printf("\tRESULTADO DE LA FUNCION RECURSIVA>> %d", Fibo_Recur(4));

	printf("\n\tFIBONACCI DE>> 1");
	printf("\n");
	printf("\tRESULTADO DE LA FUNCION ITERATIVA>> %d", Fibo_Itera(1));
	printf("\n");
	printf("\tRESULTADO DE LA FUNCION RECURSIVA>> %d", Fibo_Recur(1));

	printf("\n\tFIBONACCI DE>> 5");
	printf("\n");
	printf("\tRESULTADO DE LA FUNCION ITERATIVA>> %d", Fibo_Itera(5));
	printf("\n");
	printf("\tRESULTADO DE LA FUNCION RECURSIVA>> %d", Fibo_Recur(5));

	printf("\n\tFIBONACCI DE>> 10");
	printf("\n");
	printf("\tRESULTADO DE LA FUNCION ITERATIVA>> %d", Fibo_Itera(10));
	printf("\n");
	printf("\tRESULTADO DE LA FUNCION RECURSIVA>> %d", Fibo_Recur(10));

	printf("\n\tFIBONACCI DE>> 7");
	printf("\n");
	printf("\tRESULTADO DE LA FUNCION ITERATIVA>> %d", Fibo_Itera(7));
	printf("\n");
	printf("\tRESULTADO DE LA FUNCION RECURSIVA>> %d", Fibo_Recur(7));
}
