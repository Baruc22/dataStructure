//cola dinamica
//2cola.h

#include <stdio.h>
#include <stdlib.h>

typedef int tipo;

struct nodo
{
	tipo info;
	struct nodo *sig;
};

typedef struct nodo tnodo;

typedef struct 
{
	tnodo *frente;
	tnodo *atras;
}tcola;

void inicializacola(tcola *q)
{
	q->frente=q->atras=NULL;
}

int insertacola(tcola *q, tipo x)
{
	tnodo *t;
	t=(tnodo*)malloc(sizeof(tnodo));
	if (t!=NULL)
	{
		t->info=x;
		t->sig=NULL;
		if (q->atras==NULL)
		{
			q->atras=q->frente=t;
		}
		else
		{
			q->atras->sig=t;
			q->atras=t;
		}
		return 1; //exito
	}
	else
	{
		printf("memoria insufiente\n");
		return 0; //error
	}
}

int eliminacola (tcola *q, tipo *x)
{
	tnodo *t;
	if (q->atras!=NULL)
	{
		t=q->frente;
		q->frente=t->sig;
		*x=t->info;
		free(t);
		if (q->frente==NULL)
		{
			q->atras=NULL;
		}
		return 1;
	}
	else 
	{
		printf("cola vacia\n");
		return 0;
	}
}
