//pila dinamica
//2pila.c

#include <stdio.h>
#include "pila.h"

int main()
{
	tnodo *p;
	int temp;
	p=inicializapila();
	if (pilavacia(p))
	{
		if (push(p,5))
		{
			printf("guardo %d\n",5);
		}
		if (push(p,10))
		{
			printf("guardo %d\n",10);
		}
		if (pop(&p))
		{
			printf("elimino");
		}
		if (pop(&p))
		{
			printf("elimino");
		}
		if(pilavacia(p))
		{
			printf("la pila esta vacia\n");
		}	
	}
}
