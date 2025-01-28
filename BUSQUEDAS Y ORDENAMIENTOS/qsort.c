#include <stdio.h>
#include "qsort.h"


int main()
{
	int i,q[20],fin,ini=0;
	printf("\n\tCANTIDAD DE DATOS>> ");
	scanf("%d",&fin);
	for(i=0;i<fin;i++)
	{
		printf("\n\tDATO NUMERO %d>> ",i+1);
		scanf("%d",&q[i]);
	}

	sort(q,ini,fin);

	printf("\n\tDATOS ORDENADOS \n");
	for(i=0;i<fin;i++)
	{
		printf("\n");
		printf("\t%d\n",q[i]);
	}
}
