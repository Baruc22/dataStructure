//pila.h
#include <stdio.h>
#include <stdlib.h>
 
typedef struct pila
{
	int tope;
	int size;
	int *vector;
}Tpila;

void inicializapila(Tpila *p, int tam);
int pilavacia(Tpila p);
int pilallena(Tpila p);
void push(Tpila *p, int x);
int pop(Tpila *p);
int elementotope(Tpila p);
void imprimepila(Tpila p);

void inicializapila(Tpila *p, int tam)
{
	p->tope=-1;
	p->size=tam>1?tam:5;
	p->vector=(int*)malloc(sizeof(int)*p->size);
}

void push (Tpila *p, int x)
{
	if (pilallena(*p)==0)
	{
		p->vector[++(p->tope)]=x;
	}
	else
	{
		printf("pila llena\n");
	}
}

int pop (Tpila *p)
{
	if (pilavacia(*p)==0)
		return p->vector[p->tope--];
	else
	{
		return -1;
	}
}

int elementotope(Tpila p)
{
	if(pilavacia(p)==0)
		return p.vector[p.tope];
	else
	{
		return -1;
	}
}

int pilavacia(Tpila p)
{
	//regresa 1 si esta vacia.
	//regresa NULL o 0 si no esta vacia.
	return p.tope==-1;
}

int pilallena(Tpila p)
{
	//regresa 1 si esta llena.
	//regresa NULL o 0 si no esta llena.
	return p.tope==(p.size-1);
}



void imprimepila(Tpila p)
{
	while(pilavacia(p)!=1)
		printf("%d\n",p.vector[p.tope--]);
}
