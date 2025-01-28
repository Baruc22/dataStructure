#include <stdio.h>
#include <stdlib.h>

void burbuja(int bur[], int n);

void burbuja(int bur[], int n)
{
	int aux, i, k, j, b=1;
	for(j=1;j<n && b==1;j++)
	{
		b=0;
		for(i=0;i<n-j;i++)
		{
			if(bur[i]>bur[i+1])
			{
				aux=bur[i];
				bur[i]=bur[i+1];
				bur[i+1]=aux;
				b=1;
			}
		}
	}
}
