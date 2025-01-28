#include <stdio.h>
#include "mergsort.h"

int main()
{
	int i,a[30], b[30],fin,ini=0;
	printf("\n\tCANTIDAD DE DATOS>> ");
	scanf("%d",&fin);
	for(i=0;i<fin;i++)
	{
		printf("\n\tDATO NUMERO %d>> ",i+1);
		scanf("%d",&a[i]);
	}

	mergsort(a,b,ini,fin);

	printf("\n\tDATOS ORDENADOS \n");
	for(i=0;i<fin;i++)
	{
		printf("\n");
		printf("\t%d\n",a[i]);

	}
}

