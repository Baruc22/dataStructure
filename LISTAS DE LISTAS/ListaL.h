#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodol
{
	char nom[50];
	struct nodol *sig;
};

struct nodo
{
	char letra;
	struct nodo *sig;
	struct nodol *lista;
};

typedef struct nodo TNodo;
typedef struct nodo* TListas;
typedef struct nodol TNodol;
typedef struct nodol* TLista;


TListas inicializa()
{
	return NULL;
}

TNodo* creaNodo (char letra)
{
	TNodo *t;
	t=(TNodo*)malloc(sizeof(TNodo));
	if(t!=NULL)
	{
		t->letra=letra;
		t->sig=NULL;
		t->lista=NULL;
	}

	return t;
}

TNodol* creaNodol (char *nom)
{
	TNodol *t;
	t=(TNodol*)malloc(sizeof(TNodol));
	if (t!=NULL)
	{
		t->sig=NULL;
		strcpy(t->nom,nom); // t->nom = al destino y nom = la cadena de origen.
	}
	return t;
}

int Menu()
{
	int opc;
	do
	{
		printf("\n\t1.- INSERTAR");
		printf("\n\t2.- ELIMINAR");
		printf("\n\t3.- IMPRIMIR");
		printf("\n\t4.- SALIR");
		printf("\n");
		printf("\n\tOPCION >> ");
		scanf("%d",&opc);
	}while(opc<1 || opc>4);

	return opc;
}

int insertaNombre(TLista *l, char *nom)
{
	TLista t, ant, newp;
	newp=creaNodol(nom);
	if(newp==NULL)
	{
		return 0;
	}
	t=*l;
	while(t!=NULL && strcmp(t->nom,nom)<0) //retorna 0 si las 2 cadenas son iguales, si s1 es mayor que s2 entonces retorna un valor mayor que 0 y si s1 es menor que s2 retorna un valor menor que 0.
	{
		ant=t;
		t=t->sig;
	}
	if(t==*l)
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

int Inserta (TListas *ll, char letra, char*nom)
{
	TListas ant, t, newp;
	newp=creaNodo(letra);
	if(newp==NULL)
	{
		return 0;
	}
	t=*ll;
	while(t!=NULL && letra>t->letra)
	{
		ant=t;
		t=t->sig;
	}
	if (t!=NULL && letra==t->letra)
	{
		insertaNombre(&(t->lista),nom);
	}
	else
	{
		if(*ll==t)
		{
			newp->sig=t;
			*ll=newp;
		}
		else
		{
			newp->sig=t;
			ant->sig=newp;
		}

		insertaNombre(&(newp->lista),nom);

	}
	return 1;
}

void Imprime(TListas ll)
{
	TNodo* tl;
	TNodol* tn;
	tl=ll;
	while(tl!=NULL)
	{
	tn=tl->lista;
	printf("\t>>%c\n",tl->letra);
		while(tn!=NULL)
		{
			printf("\t%s\n",tn->nom);
			tn=tn->sig;
		}
	printf("\n");
	tl=tl->sig;
	}
}

TListas Eliminar(TListas *ll, char*nom)
{
	TListas tl,antl;
	TLista tn,antn;
	tl=*ll;
	while(tl!=NULL)
	{
		tn=tl->lista;
		while(tn!=NULL && strcmp(tn->nom,nom)!=0)
		{
			antn=tn;
			tn=tn->sig;
		}
		if(tn==NULL)
		{
			antl=tl;
			tl=tl->sig;
		}
		else//encontró
		{
			if(tn->sig==NULL && tl->lista==tn)
			{
				antl->sig=tl->sig;
				free(tl);
				return *ll;
			}
			else
			{
				antn=tn->sig;
				free(tn);
				return *ll;
			}
		}

	}
}