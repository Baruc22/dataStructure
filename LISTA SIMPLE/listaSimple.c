
#include <stdio.h>
#include "listaSimple.h"

int main()
{
	tlista l, l2;

	l2=Inicializa_Lista();

	l=Inicializa_Lista();

	if(Lista_Vacia(l)==1)
	{
		printf("\n");
		printf("\tLA LISTA ESTA VACIA");
	}
	
	l=Inserta_Inicio(l,9);
	l=Inserta_Inicio(l,4);
	l=Inserta_Fin(l,3);
	l=Inserta_Inicio(l,5);
	l=Inserta_Fin(l,2);
	printf("\n\n");
	Imprime_Lista(l);
	printf("\n");
	if(Busca_Elemento(l,5)==1)
	{
		printf("\tSI ENCONTRO EL ELEMENTO\n");
		printf("\n");
	}
	if(Elimina_Elemento_x(l,4)==1)
	{
		printf("\tELIMINO EL VALOR 4\n");
		printf("\n");
	}


	Libera_Lista(l);

	l=Inicializa_Lista();

	if(Lista_Vacia(l)==1)
	{
		printf("\tLA LISTA ESTA VACIA\n");
		printf("\n");
	}

	l=Inserta_Inicio(l,10);
	l=Inserta_Fin(l,22);
	l=Inserta_Inicio(l,99);
	l=Inserta_Fin(l,23);
	l=Inserta_Inicio(l,45);

	Imprime_Lista(l);

	l=Elimina_Inicio(l);

	printf("\tSE ELIMINO EL PRIMER ELEMENTO\n\n");

	Imprime_Lista(l);
	
	printf("\tSE ELIMINO EL ULTIMO ELEMENTO\n\n");

	l=Elimina_Fin(l);

	Imprime_Lista(l);
	
	l=Inserta_Antes_y(l,10,30);
	
	printf("\tSE INSERTO 30 ANTES DE 10\n\n");
	
	Imprime_Lista(l);
	
	l=Elimina_Antes_de_y(l,22);

	printf("\tSE ELIMINO 10 ANTES DE 22\n\n");
	
	Imprime_Lista(l);
	
	l=Inserta_Despues_y(l,99,100);

	printf("\tSE INSERTO 100 DESPUES DE 99\n\n");
	
	Imprime_Lista(l);

	l=Inserta_Fin(l,234);
	l=Inserta_Inicio(l,0);
	l=Inserta_Fin(l,2004);

	printf("\tSE INSERTARON MAS VALORES\n\n");

	Imprime_Lista(l);

	l=Elimina_Despues_de_y(l,22);

	printf("\tSE ELIMINO 234 DESPUES DE 22\n\n");
	
	Imprime_Lista(l);

	l2=Inserta_Inicio(l2,78);
	l2=Inserta_Fin(l2,29);
	l2=Inserta_Inicio(l2,17);
	l2=Inserta_Fin(l2,18);
	l2=Inserta_Inicio(l2,222);

	printf("\tNUEVA LISTA\n\n");

	Imprime_Lista(l2);

}
