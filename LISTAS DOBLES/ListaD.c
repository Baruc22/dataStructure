//ListaD.c

#include <stdio.h>
#include "ListaD.h"

int main()
{
	TListaD *ld;
	int n;
	
	ld=Inicializa_Lista();
	if (ld==NULL)
	{
		printf("\n\tSE INICIALIZO LA LISTA\n");
	}
	
	n=Lista_Vacia(ld);
	
	if (n==1)
	{
		printf("\n\tLISTA VACIA\n");
	} 
	

	TNodoD *nodo;
	nodo=Crea_Nodo();
	if (nodo!=NULL)
	{
		printf("\n\tSE CREO NODO\n");
	}

	TNodoD *nodoXD;
	nodoXD=Crea_NodoDx(9);

	if(nodoXD!=NULL)
	{
		printf("\n\tSECREO NODO XD\n");
	}

	printf("\n\tEL NODO XD CONTIENE\n\n");

	printf("\t%d\n",nodoXD->info);

	printf("\n\tSE INSERTARON AL INICIO\n\n");

	ld=Inserta_Inicio(ld,22);
	ld=Inserta_Inicio(ld,17);
	ld=Inserta_Inicio(ld,10);
	Imprime_Lista(ld);

	printf("\n\tSE INSERTO AL FINAL\n\n");

	ld=Inserta_Fin(ld,45);
	ld=Inserta_Fin(ld,90);
	ld=Inserta_Fin(ld,100);
	Imprime_Lista(ld);

	printf("\n\tSE ELIMINA AL INICIO\n\n");

	ld=Elimina_Inicio(ld);
	Imprime_Lista(ld);

	printf("\n\tSE ELIMINA FIN\n\n");

	ld=Elimina_Fin(ld);
	Imprime_Lista(ld);

	printf("\n\tSE INSERTO DESPUES DE 17\n\n");

	ld=Inserta_Despues_y(ld,17,78);
	Imprime_Lista(ld);

	printf("\n\tSE INSERTO ANTES DE 45\n\n");

	ld=Inserta_Antes_y(ld,45,1);
	Imprime_Lista(ld);
	
	Busca_el_Elemento_x(ld,1);

	printf("\n\tSE ELIMINO EL ELEMENTO X\n\n");
	ld=Elimina_Elemento_x(ld,1);
	Imprime_Lista(ld);

}
