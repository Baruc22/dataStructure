#include <stdio.h>
#include "burbuja.h"


int main()
{
	int i,bur[30],n;
	printf("\n\tCANTIDAD DE DATOS>> ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n\tDATO NUMERO %d>> ",i+1);
		scanf("%d",&bur[i]);
	}

	burbuja(bur,n);

	printf("\n\tDATOS ORDENADOS \n");
	for(i=0;i<n;i++)
	{
		printf("\n");
		printf("\t%d\n",bur[i]);
	}
}
