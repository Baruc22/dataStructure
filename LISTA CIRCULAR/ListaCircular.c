#include <stdio.h>
#include <string.h>
#include "ListaCircular.h"

int main()
{
	char *soldado[10]={"Carlos","David","Rafael","Herder","Baruc","Andres","Javier","Isaac","Beto","Pablo"};
	int k=3,i;
	TListaC lc=NULL;
	for(i=0;i<10;i++)
	{
		inserta(&lc,soldado[i]);
	}
	while(elimina(&lc,k));
}
