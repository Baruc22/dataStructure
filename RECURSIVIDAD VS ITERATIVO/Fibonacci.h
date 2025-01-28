#include <stdio.h>
#include <stdlib.h>

int Fibo_Itera(int n)
{
	int FN_2=0, FN_1=1, FN, i;
	FN=n;
	for(i=0;i<n-1;i++)
	{
		FN=FN_2+FN_1;
		FN_2=FN_1;
		FN_1=FN;
	}
	return FN;
}

int Fibo_Recur(int n)
{
	if (n==0) return 0;
	if(n==1) return 1;
	else
		return Fibo_Recur(n-2)+Fibo_Recur(n-1);
}
