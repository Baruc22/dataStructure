#include <stdlib.h>
#include <stdio.h>

void intercambia(int a[], int x, int y);
void sort (int a[], int ini, int fin);

void sort (int a[], int ini, int fin)
{
	int i, j;
	if (ini>=fin)
	{
		return;
	}
	j=ini;
	for (i=ini+1;i<=fin;i++)
		if (a[i]<a[ini])
			intercambia(a,++j,i);
		intercambia(a,j,ini);
		sort(a,ini,j-1);
		sort(a,j+1,fin);
}

void intercambia(int a[], int x, int y)
{
	int t;
	t=a[x];
	a[x]=a[y];
	a[y]=t;
}
