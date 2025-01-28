#include <stdlib.h>

int busca(int a[],int n, int key)
{
	if(n==0)
	{
		return -1;
	}
	if (a[n-1]==key)
	{
		return n-1;
	}
	return busca(a,n-1,key);
}