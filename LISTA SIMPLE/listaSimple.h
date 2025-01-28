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

int Busca_Elemento(tlista l, tipo x);
int Elimina_Elemento_x(tlista l, tipo x);
tlista Inserta_Antes_y(tlista l, tipo y, tipo dato);
tlista Inserta_Despues_y (tlista l, tipo y, tipo dato);
void Libera_Lista(tlista l);
int Lista_Vacia(tlista l);
tlista Inicializa_Lista();
tlista Inserta_Inicio (tlista l, tipo dato);
tlista Elimina_Antes_de_y(tlista l, tipo y);
tlista Elimina_Despues_de_y(tlista l, tipo y);
tlista Elimina_Inicio (tlista l);
void Imprime_Lista(tlista l);
tnodos* Crea_Nodo(tnodos *t);
//tlista* Copia_Lista(tlista *l);
int Listas_Iguales(tlista *l, tlista *ll);
tlista Inserta_Fin (tlista l, tipo x);
tlista Elimina_Fin (tlista l);
int Inserta_Orden(tlista *l, tipo x);

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

int Busca_Elemento(tlista l, tipo x)
{
	tnodos *t;
	t=l;
	while (t!=NULL)
	{
		if (t->info==x)
		{
			return 1;
		}
		t=t->sig;
	}
	return 0;
}

int Elimina_Elemento_x(tlista l, tipo x)
{
	tnodos *t, *ant;
	ant=l;
	t=ant->sig;
	while (t!=NULL)
	{
		if (t->info==x)
		{
			ant=t->sig;
			free(t);
			return 1;
		}
		ant=t;
		t=t->sig;
	}
	return 0; //no lo encontro
	
}

tlista Inserta_Antes_y(tlista l, tipo y, tipo dato)
{
	tnodos *ant, *t, *newp;
	newp=(tnodos*)malloc(sizeof(tnodos));
	t=l;
	newp->sig=NULL;
	newp->info=dato;
	while(t!=NULL)
	{
		ant=t;
		t=t->sig;
		if (t->info==y)
		{
			ant->sig=newp;
			newp->sig=t;
			return l;
		}
	}
	return l;
}

tlista Inserta_Despues_y (tlista l, tipo y, tipo dato)
{
	tnodos *ant, *t, *newp;
	newp=(tnodos*)malloc(sizeof(tnodos));
	t=l;
	newp->sig=NULL;
	newp->info=dato;
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

void Libera_Lista(tlista l)
{
	free(l);	
}

int Lista_Vacia(tlista l)
{
	return l==NULL;
}

tlista Inicializa_Lista()
{
	return NULL;
}

tlista Inserta_Inicio (tlista l, tipo dato)
{
	tlista newp;
	newp=(tnodos*)malloc(sizeof(tnodos));
	if (newp!=NULL)
	{
		newp->info=dato;
		newp->sig=l;
		l=newp;
		return l;
	}
	else
	{
		return l;
	}
}

tlista Elimina_Antes_de_y(tlista l, tipo y)
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

tlista Elimina_Despues_de_y(tlista l, tipo y)
{
	tnodos *t,*ant,*desp;
	t=l;
	while (t!=NULL)
	{
		ant=t;
		t=t->sig;
		desp=t->sig;

		if (ant->info==y)
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

tlista Elimina_Inicio (tlista l)
{
	tnodos *t;
	t=l;
	if (t!=NULL)
	{
		l=t->sig;
		free(t);
		return l;
	}
	else
	{
		return  l;
	}
}

tnodos* Crea_Nodo(tnodos *t)
{
	tnodos *newp;
	newp=(tnodos*)malloc(sizeof(tnodos));
	newp->info=t->info;
	return newp;
}

//tlista Copia_Lista(tlista *l)
//{
	//tnodos *t, *b, *newp;
	//tlista *p;
	//p=Inicializa_Lista();
	//b=*p;
	//t=*l;
	//while (t!=NULL)
	//{
		//newp=Crea_Nodo(t);
		//b->sig=newp;
		//newp=b;
		//t=t->sig;
	//}
	//return p;
//}

int Listas_Iguales(tlista *l, tlista *ll)
{
	tnodos *tl, *tll;
	tl=*l;
	tll=*ll; 
	while(tl!=NULL)
	{
		if (tl->info==tll->info)
		{
			tl=tl->sig;
			tll=tll->sig;
		}
		else
		{
			return 0;
		}
	}
	if(tl==NULL && tll==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

tlista Inserta_Fin (tlista l, tipo x)
{
	tnodos *newp, *temp;
	temp=l;
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
			return l;
		}
		else
		{
			l=newp;
			return l;
		}
	}
}

tlista Elimina_Fin (tlista l)
{
	tnodos *t, *ant;
	t=l;
	while(t->sig!=NULL)
	{
		ant=t;
		t=t->sig;
	}
	if (t->sig==NULL)
	{
		ant->sig=NULL;
		free(t);
		return l;
	}
	return 0;
}

int Inserta_Orden(tlista *l, tipo x)
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
