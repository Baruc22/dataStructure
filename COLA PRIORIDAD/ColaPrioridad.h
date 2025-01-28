#include <stdlib.h>
#include <stdio.h>
typedef int Tipo;
struct nodoP{
	Tipo inf;
	int prioridad;
	struct nodo *sig;
};
typedef struct nodoP TNodoP;
typedef struct{
	TNodoP *frente;
}TColaP;
void inicializa(TColaP *v){
	v->frente=NULL;
}
int colavacia(TColaP v){
	return v.frente==NULL;
}
int  insertar(TColaP *v, Tipo n, int prio){
	TNodoP *nuevo=(TNodoP *)malloc(sizeof(TNodoP));
	TNodoP *t, *ant;
	t=ant=v->frente;
	if(nuevo!=NULL){
		nuevo->inf=n;
		nuevo->prioridad=prio;
		nuevo->sig=NULL;
		while(t!=NULL && t->prioridad<=prio){
			ant=t;
			t=t->sig;
		}	
		if(v->frente==t){
			nuevo->sig=v->frente;
			v->frente=nuevo;
		}
		else{
			nuevo->sig=t;
			ant->sig=nuevo;
		}
		return 1;
	}
	printf("ERROR -Pila llena, memoria insuficiente\n");
	return 0;
}
int eliminar(TColaP *v, Tipo *n){
	if(!colavacia(*v)){
		*n=v->frente->inf;
		v->frente=v->frente->sig;
		return 1;
	}
	return 0;
}
void imprimircola(TColaP v){
	Tipo n;
	while(!colavacia(v)){
		eliminar(&v, &n);
		printf("%d\n", n);
	}
}
