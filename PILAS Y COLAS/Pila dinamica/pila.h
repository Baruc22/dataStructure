//Pila dinamica
//pila.h

#include <stdio.h>
#include <stdlib.h>

typedef int tipo;
struct nodo
{
	tipo info;
	struct nodo *sig;
};

typedef struct nodo tnodo;
typedef tnodo *tpila;

tnodo* inicializapila();
int push (tnodo *p, tipo x);
int pop (tpila *p);
int pilavacia (tpila p);
tpila Crea_Nodo(tipo x);

tnodo* inicializapila()
{
	return NULL;
}

tpila Crea_Nodo(tipo x)
{
	tpila t;
	t=(tpila)malloc(sizeof(tnodo));
	if(t!=NULL)
	{
		t->info=x;
		t->sig=NULL;
	}
	return t;
}

int push (tnodo *p, tipo x)
{
	tpila t;
	t=Crea_Nodo(x);
	if (t!=NULL)
	{
		t->sig=p;
		t=p;
		return 1;
	}
	else
	{
		printf("\tMEMORIA INSUFIENTE\n");
		return 0;
	}
}

int pop (tpila *p)
{
	tpila t;
	t=*p;
	if (t!=NULL)
	{
		printf("%d\n",t->info);
		*p=t->sig;
		free(t);
		return 1;
	}
	else 
	{
		printf("\tLA PILA ESTA VACIA\n");
		return 0;
	}
}

int pilavacia (tpila p)
{
	return p==NULL;
}

