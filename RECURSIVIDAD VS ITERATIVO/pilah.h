#include <stdio.h>
#include <stdlib.h>
typedef int tipo;
struct nodo
{
	tipo n;
	tipo ori;
	tipo des;
	tipo aux;
	struct nodo *sig;
};
typedef struct nodo TNodo;
typedef TNodo* Tpila;
Tpila inicializapila()
{
	return NULL;
}
int push(Tpila*p,tipo x,tipo ori,tipo des,tipo aux)
{
	TNodo *t;
	t=(TNodo*)malloc(sizeof(TNodo));
	if(t!=NULL)
	{
		t->n=x;
		t->ori=ori;
		t->des=des;
		t->aux=aux;
		t->sig=*p;
		*p=t;
		return 1;
	}
	else 
		printf("Memoria insuficiente.\n");
	return 0;

}
int pop(Tpila* p, tipo*x,tipo*ori, tipo *des, tipo *aux)
{
	TNodo *t;
	if(*p!=NULL)
	{
		t=*p;
		*p=t->sig;
		*x=t->n;
		*ori=t->ori;
		*des=t->des;
		*aux=t->aux;
		free(t);
		return 1;
	}
	else 
		printf("Pila llena\n");
	return 0;
}
int pilavacia(Tpila p){
	return p==NULL;
}
