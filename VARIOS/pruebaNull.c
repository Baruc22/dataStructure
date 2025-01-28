#include <stdio.h>
#include <stdlib.h>

int error()
{
	int x=2;
	return x==2;
}

int main()
{
	int e,x=3;
	if (x==3)
	{
		e=error();
		printf("%d",e);
		if (e!=NULL)
		{
			printf("\n\n");
			printf("\tEXITO\n");
			printf("\n");
		}
	}
	return 0;
}
