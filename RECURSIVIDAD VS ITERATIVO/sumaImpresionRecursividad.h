#include <stdio.h>
#include <stdlib.h>

int sumatoria(int a[], int n)
{
	if (n==1) 
	{
		return a[0];
	}
	else
		return a[n-1]+sumatoria(a,n-1);
}

void imprimir(char s[], int j)
{
	if(s[j]=='\0') return;
	printf("%c ",s[j]);
	imprimir(s,j+1);
	return;
}
