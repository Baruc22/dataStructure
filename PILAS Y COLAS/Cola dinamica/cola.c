
//cola dinamica
//2cola.c

#include <stdio.h>
#include "cola.h"

int main ()
{
	tcola q;
	int x;

	inicializacola(&q);
	insertacola(&q,5);
	insertacola(&q,9);
	insertacola(&q,8);
	

	
	eliminacola(&q,&x);
	printf("%d\n",x);

	eliminacola(&q,&x);
	printf("%d\n",x);

	eliminacola(&q,&x);
	printf("%d\n",x);

	
	return 0;
}
