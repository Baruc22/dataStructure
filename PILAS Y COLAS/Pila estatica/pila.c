#include <stdio.h>
#include "pila.h"

int main()
{
	int x;
	Tpila p;
	inicializapila(&p,3);
	push(&p,1);
	push(&p,2);
	push(&p,3);
	push(&p,4); //error

	if (pilallena(p))
	{
		printf("la pila esta llena\n");
	}

	x=pop(&p);
	if (x!=-1)
	{
		printf("%d\n",x);
	}
	else
		printf("pila vacia\n");

	x=pop(&p);
	if (x!=-1)
	{
		printf("%d\n",x);
	}
	else
		printf("pila vacia\n");

	x=pop(&p);
	if (x!=-1)
	{
		printf("%d\n",x);
	}
	else
		printf("pila vacia\n");
		
	if (pilavacia(p)!=0)
	{
		printf("pila vacia\n");
	}
	

	push(&p,5);
	
	x=elementotope(p);
	if (x!=-1)
	{
		printf("%d\n",x);
	}
	else
		printf("pila vacia\n");
		
	x=pop(&p);
	if (x!=-1)
	{
		printf("%d\n",x);
	}
	else
		printf("pila vacia\n");
		
	if (pilavacia(p)==1)
	{
		printf("pila vacia\n");
	}

}
