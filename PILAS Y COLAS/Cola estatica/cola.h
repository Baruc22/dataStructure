//cola.h
#include <stdio.h>
#include <stdlib.h>

typedef int tipo;
typedef struct
{
	int frente, atras, size;
	tipo *vector;
} tcola;

void inicializacola(tcola *q, int tam);
int colavacia(tcola q);
int colallena(tcola q);
void insertacola(tcola *q, tipo x);
int eliminacola(tcola *q, tipo *x);
void liberacola(tcola *q);

void inicializacola(tcola *q, int tam)
{
	q->size=tam>1?tam:5;
	q->frente=q->atras=-1;
	q->vector=(tipo*)malloc(sizeof(tipo)*q->size);
}

void insertacola(tcola *q, tipo x)
{
	if (colallena(*q)==1)
	{
		printf("la cola esta llena\n");
	}
	else
	{
		q->atras=(q->atras==q->size-1)?0:q->atras+1;
		q->vector[q->atras]=x;
	}

	if (q->frente==-1)
	{
		q->frente=0;
	}
}

int colavacia(tcola q)
{
	//regresa 1 si esta vacia.
	//regresa 0 o NULL si no esta vacia.
	return q.frente==-1;
}

int colallena(tcola q)
{
	//regresa 1 si esta llena.
	//regresa 0 o NULL si no esta llena.
	return (q.atras+1==q.frente) || (q.frente==0 && q.atras==q.size-1);
}

int eliminacola(tcola *q, tipo *x)
{
	if (colavacia(*q)==1)
	{
		printf("la cola esta vacia\n");
	}
	else
	{
		*x=q->vector[q->frente];
	}
	if (q->frente==q->atras)
	{
		q->frente=q->atras=-1;
	}
	q->frente=(q->frente==q->size-1)?0:q->frente+1;
}
