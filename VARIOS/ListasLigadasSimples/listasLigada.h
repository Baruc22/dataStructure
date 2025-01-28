#include <stdio.h>
#include <stdlib.h>

typedef int Tipo;

struct nodos
{
	Tipo info;
	struct nodos *sig;
};

typedef struct nodos tnodos;

typedef tnodos* tlista;

int Inserta_Orden(tlista *l, Tipo x);
tlista Crea_Nodo (Tipo x);
tlista Inserta_Des_x(tlista b, Tipo y, Tipo x);
tlista Inicializa_Lista();
void Imprime_Lista(tlista l);
tlista Inserta_Despues_y (tlista l, Tipo y, Tipo dato);
tlista Eliminar_Ant_y(tlista b, Tipo y);
tlista Elimina_Antes_de_y(tlista l, Tipo y);

void Imprime_Lista(tlista l)
{
	tnodos *t;
	t=l;
	while (t!=NULL)
	{
		printf("\t%d\n",t->info);
		t=t->sig;
	}
	printf("\n");
}

int Inserta_Orden(tlista *l, Tipo x)
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

tlista Crea_Nodo (Tipo x)
{
	tlista t;
	t=(tlista)malloc(sizeof(tnodos));
	if(t!=NULL)
	{
		t->info=x;
		t->sig=NULL;
	}
	return t;
}

//y=referencia
//x=dato a insertar

tlista Inserta_Des_x(tlista b, Tipo y, Tipo x)
{
	tlista t, newl, ant;
	newl=Crea_Nodo(x);
	t=b;
	if(t!=NULL)
	{
		while(t->info!=y && t->sig!=NULL)
		{
			ant=t;
			t=t->sig;
		}
		if(t->sig==NULL) 
		{
			printf("\n\tNO LO ENCONTRO\n");
			return b;
		}
		if(t->sig!=NULL)
		{
			newl->sig=t;
			ant->sig=newl;
			return b;
		} 
		t->sig=newl;
		return b;
	}
	printf("\nNO HAY DATOS\n");
}

//y=referencia
//dato=lo que se inserta
tlista Inserta_Despues_y (tlista l, Tipo y, Tipo dato)
{
	tnodos *ant, *t, *newp;
	newp=Crea_Nodo(dato);
	t=l;
	while(t!=NULL)
	{
		ant=t;
		t=t->sig;
		if (ant->info==y)
		{
			ant->sig=newp;
			newp->sig=t;
			return l;
		}
	}
	return l;
}

tlista Inicializa_Lista()
{
	return NULL;
}

//y=referencia

tlista Eliminar_Ant_y(tlista b, Tipo y)
{
	tlista t, ant, ref;
	t=b;
	ref=b;
	while(t->sig!=NULL)
	{
		if(ref->info!=y)
		{
			ref=ref->sig;
			if(ref->info==y && t==ant)
			{
				b=ref;
				free(t);
				return b;
			}
			if(ref->info==y)
			{
				ant->sig=ref;
				free(t);
				return b;
			}
			ant=t;
			t=t->sig;
		}
		else
		{
			return b;
		}
	}
	return b;
}

tlista Elimina_Antes_de_y(tlista l, Tipo y)
{
	tnodos *t,*ant,*desp;
	t=l;
	while (t!=NULL)
	{
		ant=t;
		t=t->sig;
		desp=t->sig;
	
		if (desp->info==y)
		{
			ant->sig=desp;
			free(t);
			return l;
		}
		if(desp->sig==NULL)
		{
			return l;
		}
	}
	return l;
}
