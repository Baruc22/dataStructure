//recursividad indirecta

#include <stdlib.h>
#include <stdio.h>

void f1(int n);
void f2(int n);
void f3(int n);

void f1(int n)
{
	if (n==0)
	{
		printf("\n\tf1(0)\n");
	}
	else
	{
		f3(n-1);
		printf("\n\tf1(%d)\n",n);
	}
	return;
}

void f2(int n)
{
	if(n==0)
	{
		printf("\n\tf2(0)\n");
	}
	else
	{
		f1(n-1);
		printf("\n\tf2(%d)\n",n);
	}
	return;
}

void f3(int n)
{
	if(n==0)
	{
		printf("\n\tf3(0)\n");
	}
	else
	{
		f2(n-1);
		printf("\n\tf3(%d)\n",n);
	}
	return;
}

int main()
{
	int n;
	printf("\n\tNUMERO>>  ");
	scanf("%d",&n);
	f1(n);
	return 0;
}


