#include <stdio.h>
#include <stdlib.h>
#include "listasLigada.h"

int main ()
{
	int n,i,x,y,z,r;
	tlista b;
	b=Inicializa_Lista();

//.......... INSERTA .............

	printf("\n\tNUMERO DE DATOS >> ");
	scanf("%d",&n);
	printf("\n");

	for(i=0;i<n;i++)
	{
		printf("\n\tDATO A INSERTAR >> ");
		scanf("%d",&x);
		Inserta_Orden(&b,x);
	}

	printf("\n");
	printf("\n\tLO QUE HAY EN LA LISTA\n");
	printf("\n");

	Imprime_Lista(b);

	printf("\n");

	//y=referencia
	//z=dato a insertar
	printf("\n\tREFERENCIA PARA INSETAR >> ");
	scanf("%d",&y);
	printf("\n");
	printf("\n\tDATO NUEVO A INSERTAR >> ");
	scanf("%d",&z);

	b=Inserta_Despues_y(b,y,z);

	printf("\n");

	Imprime_Lista(b);

	//................ ELIMINA ..................

	//r=referencia
	printf("\n\tREFERENCIA PARA ELIMINAR >> ");
	scanf("%d",&r);

	printf("\n\tFUNICION 1\n");

	b=Elimina_Antes_de_y(b,r);

	printf("\n");

	Imprime_Lista(b);

	printf("\n\tFUNICION 2\n");
	
	b=Eliminar_Ant_y(b,r);

	printf("\n");

	Imprime_Lista(b);
}
