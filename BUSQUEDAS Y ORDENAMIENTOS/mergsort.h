#include <stdlib.h>

void mergsort(int a[], int b[], int ini, int fin);
void mezclar(int a[], int b[], int ini1, int fin1, int ini2, int fin2);

void mergsort(int a[], int b[], int ini, int fin)
{
	int mit, i;
	if (ini==fin) return;
	mit=(ini+fin)/2;
	mergsort(a,b,ini,mit);
	mergsort(a,b,mit+1,fin);
	mezclar(a,b,ini,mit,mit+1,fin);

	for (i=mit;i<=fin;++i)
	{
		a[i]=b[i];
	}

	return;
}

void mezclar(int a[], int b[], int ini1, int fin1, int ini2, int fin2)
{
	int i, j, k;
	i=ini1;
	for (j=ini1, k=ini2;j<=fin1 && k<=fin2;i++)
	{
		b[i]=(a[j]<a[k])?a[j++]:a[k++];
		while(j<=fin1)
		{
			b[i++]=a[j++];
		}
		while(k<=fin2)
		{
			b[i++]=a[k++];
		}
	}
}
