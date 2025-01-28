//prueba de cola
//cola.c

#include <stdio.h>
#include "cola.h"

int main ()
{
	tcola q;
	int x;

	inicializacola(&q,3);
	insertacola(&q,10);
	insertacola(&q,15);
	insertacola(&q,5);
	insertacola(&q,20); //error

	
	eliminacola(&q,&x);
	printf("%d\n",x);

	eliminacola(&q,&x);
	printf("%d\n",x);

	eliminacola(&q,&x);
	printf("%d\n",x);

	if (colavacia(q)==1)
	{
		printf("cola vacia\n");
	}
	
	return 0;
}
