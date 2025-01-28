#include <stdlib.h>

int busca_bin_recursivo(int a[], int ini, int fin, int key)
{
	int mit;
	if (ini>fin)
	{
		return -1;
	}
	mit=(ini+fin)/2;
	if (a[mit]==key)
	{
		return mit;
	}
	if (key<a[mit])
	{
		return busca_bin_recursivo(a,ini,mit-1,key);
	}
	return busca_bin_recursivo(a,mit+1,fin,key);
}

int busca_bin_iterativo(int a[],int ini, int fin, int key)
{
	int mit;
	while(ini<=fin)
	{
		mit=(ini+fin)/2;
		if(a[mit]==key)
		{
			return mit;
		}
		else
		{
			ini=mit+1;
		}
	}
	return -1;
}