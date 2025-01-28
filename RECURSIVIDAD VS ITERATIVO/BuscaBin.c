#include <stdio.h>
#include "BuscaBin.h"

int main()
{
	int a[50],n,i,key;
	printf("\n\tCANTIDAD DE NUMEROS>> ");
	scanf("%d",&n);
	printf("\n\tNUMERO A BUSCAR>> ");
	scanf("%d",&key);
	for (i=1;i<=n;i++)
	{
		printf("\n\tNUMERO>> ");
		scanf("%d",&a[i]);
	}

	printf("\n\tENCONTRO (recursivo)>> %d\n",busca_bin_recursivo(a,1,n,key));

	printf("\n\tENCONTRO (iterativo)>> %d\n",busca_bin_iterativo(a,1,n,key));
}