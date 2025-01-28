#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct nodo
{
	char nombre[30];
	struct nodo *sig;
};

typedef struct nodo TNodo;

typedef TNodo* TListaC;

TNodo* Crea_Nodo (char *nom);
int inserta(TListaC *lc, char *nom);
int elimina(TListaC *lc, int k);

TNodo* Crea_Nodo (char *nom)
{
	TNodo *t;
	t=(TNodo*)malloc(sizeof(TNodo));
	if (t!=NULL)
	{
		t->sig=NULL;
		strcpy(t->nombre,nom);
	}
	return t;
}

int inserta(TListaC *lc, char *nom)
{
	TListaC newp;
	newp=Crea_Nodo(nom);
	if(newp==NULL)
	{
		return 0;
	}
	if(*lc==NULL)
	{
		*lc=newp;
		newp->sig=newp;
	}
	else
	{
		newp->sig=(*lc)->sig;
		(*lc)->sig=newp;
	}
	return 1;
}

int elimina(TListaC *lc, int k)
{
	TListaC ant, t;
	int i=0;
	if ((*lc)->sig==*lc)
	{
		printf("\n\tTRAIDOR>> %s\n",(*lc)->nombre);
		return 0;
	}
	else
	{
		t=*lc;
		while(i<k)
		{
			ant=t;
			t=t->sig;
			i++;
		}
		ant->sig=t->sig;
		*lc=t->sig;
		printf("\n\tSOLDADO ELIMINADO>> %s\n",t->nombre);
		free(t);
		return 1;
	}
}
