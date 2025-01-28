#include <stdio.h>
#include "busquedaSecuencial.h"

int main()
{
	int a[30],n,key,i;
	printf("\n\tCANTIDAD DE NUMEROS>> ");
	scanf("%d",&n);
	printf("\n\tNUMERO A BUSCAR>> ");
	scanf("%d",&key);
	for (i=1;i<=n;i++)
	{
		printf("\n\tNUMERO %d >> ", i);
		scanf("%d",&a[i]);
	}

	printf("\n\tENCONTRO EN LA POSICION >> %d\n",busca(a,n,key));
}
