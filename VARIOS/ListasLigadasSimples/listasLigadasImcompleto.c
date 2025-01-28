//Listas ligadas (enlazadas o vinculadas)

#include <stdio.h>
#include <stdlib.h>

typedef int tipo;

struct nodos
{
	tipo info;
	struct nodos *sig;
};

typedef struct nodos tnodos;

typedef tnodos* tlista;

int recorreLista(tlista *l)
{
	tnodos *t, *newp;
	t=*l;
	t=(tnodos*)malloc(sizeof(tnodos));
	while(t!=NULL)
	{
		newp->info=t->info;
		newp=t;
		t=t->sig;
	}
}

int listaVacia(tnodos *l)
{
	return l==NULL;
}

tlista* inicializalista()
{
	return NULL;
}

int insertainicio (tnodos *l, tipo dato)
{
	tnodos newp;
	newp=(tnodos*)malloc(sizeof(tnodos));
	if (newp!=NULL)
	{
		newp->info=dato;
		wewp->sig=l;
		*l=newp;
		return 1;
	}
	else
	{
		return 0;
	}
}

int eliminainicio (tnodos *l, tipo *dato)
{
	tnodos *ptrt;
	ptrt=(*l);
	if (ptrt!=NULL)
	{
		*dato=(*l)->info;
		*l=(*l)->sig;
		free(ptrt);
		return 1;
	}
	return  0;
}

int insertafin (tlista *l, tipo x)
{
	tnodos *newp, 
	*temp=*l;
	newp=(tnodos*)malloc(sizeof(tnodos));

	if (newp!=NULL)
	{
		if (temp!=NULL)
		{
			newp->info=x;
			newp->sig=NULL;
			while(temp->sig!=NULL)
			{
				temp=temp->sig;
			}
			temp->sig=newp;
		}
		else
		{
			*l=newp;
		}
	}
}

int eliminafin (tlista *l, tipo *x)
{
	tnodos *t, *ant;
	if (x!==NULL)
	{
		return 0;
	}
	t=ant=*l;
	while(t->sig!=NULL)
	{
		ant=t;
		t=t->sig;
	}
	*x=t->info;
	if (*l==t)
	{
		*l=NULL;
	}
	else
	{
		ant->sig=NULL;
	}

	free(t);
	
	return 0;
}

int insertaorden(tlista *l, tipo x)
{
	tnodos *ant, *t, *newp;

	t=ant=*l;
	newp=(tnodos*)malloc(sizeof(tnodos));
	if (newp==NULL) return 0;
	newp->info=x;
	newp->sig=NULL;

	while(t!=NULL && t->info<x)
	{
		ant=t;
		t=t->sig;
	}
	if (t==*l)
	{
		newp->sig=t;
		*l=newp;
	}
	else
	{
		newp->sig=t;
		ant->sig=newp;
	}
	return 1;
}
