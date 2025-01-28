//prueba de flecha definita

#include <stdio.h>
#include <stdlib.h>

typedef struct dato
{
	int dato1;
	char dato2 [30];
} DATO;

int main ()
{
	DATO *ptr;
	ptr->dato1=22;

	printf("\n\n");
	printf("\t%d\n",ptr->dato1);
	printf("\n");
}
