#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dato
{
	int dato1, dato2;
	char campo3 [30];
}DATO;

int main ()
{
	DATO x;
	DATO *ptr;

	ptr=&x;
	(*ptr).dato1=33;
	strcpy((*ptr).campo3,"HOLA");
  
  	printf("\n\n");
 	printf("\t%d\n",(*ptr).dato1);
 	printf("\t%s\n",(*ptr).campo3);
 	printf("\n\n"); 

 	return 0;
}