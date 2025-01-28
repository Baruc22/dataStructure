#include <stdio.h>
#include <stdlib.h>
#include "sumaImpresionRecursividad.h"

int main()
{
	int n,i,j=0, a[20];
	char s[50];
	printf("\n\tNUMEROS A SUMAR>> ");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		printf("\n\tNUMERO>> ");
		scanf("%d",&a[i]);
	}

	printf("\n\tCADENA>> ");

	scanf("%s",s);

	printf("\n\tSUMA>> %d\n",sumatoria(a,n));
	
	printf ("\n\tIMPRECION DE CADENA DE FORMA RECURSIVA>> ");
	imprimir(s,j);
}
