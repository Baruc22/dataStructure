#include <stdio.h>
#include <stdlib.h>

typedef int Tipo;

struct nodo
{
	Tipo info;
	struct nodo *izq;
	struct nodo *der;
};

typedef struct nodo NodoArbin;
typedef struct nodo *TArbin;

TArbin Inicializa_Arbin();
TArbin Crea_Nodo (Tipo dato);
Tipo Raiz (TArbin a);
TArbin Izquierda(TArbin a);
TArbin Derecha(TArbin a);
int Arbin_Vacio(TArbin a);
int Peso(TArbin a);
int Existe_X(TArbin a, Tipo x);
int Hojas(TArbin a);
int Contar(TArbin a, Tipo dato);
int Num_Nodos(TArbin a, int n);
int Arb_Iguales (TArbin a, TArbin b);
Tipo Maxi(TArbin a);
void PosOrden(TArbin a);
int Inserta_Arbin(TArbin *a, Tipo x);
void PreOrden(TArbin a);
TArbin EliminarA(TArbin a, Tipo x);
int EliminarB(TArbin *a, int x);
//REVISAR
void PodarA(TArbin *a);
void PodarB(TArbin *a);

TArbin Inicializa_Arbin()
{
	return NULL;
}

TArbin Crea_Nodo (Tipo dato)
{
	TArbin t;
	t=(TArbin)malloc(sizeof(NodoArbin));
	if(t!=NULL)
	{
		t->info=dato;
		t->izq=t->der=NULL;
	}
	return t;
}

// FUNCIONES DE APOYO....................

Tipo Raiz (TArbin a)
{
	return a->info;
}

TArbin Izquierda(TArbin a)
{
	return a->izq;
}

TArbin Derecha(TArbin a)
{
	return a->der;
}

int Arbin_Vacio(TArbin a)
{
	return a==NULL;
}

//.........................

//PESO DEL ARBOL.

int Peso(TArbin a)
{
	if(a==NULL)
	{
		return 0;
	}
	return 1+Peso(a->izq)+Peso(a->der);
}

//EL ELEMENTO X ESTA O NO

int Existe_X(TArbin a, Tipo x)
{
	if(Arbin_Vacio(a)) return 0;
	if(Raiz(a)==x) return 1;

	return Existe_X(Izquierda(a),x) || Existe_X(Derecha(a),x);
}

//NUMERO DE HOJAS

int Hojas(TArbin a)
{
	if (a==NULL) return 0;
	if (a->izq==NULL && a->der==NULL) return 1;
	return Hojas (a->izq)+ Hojas(a->der);
}

//CONTAR EL ELEMENTO X

int Contar(TArbin a, Tipo dato)
{
	if(Arbin_Vacio(a)) return 0;
	if(a->info==dato)
	{
		return 1+Contar(a->izq,dato)+Contar(a->der,dato);
	}
	return Contar(a->izq,dato)+Contar(a->der,dato);
}

// CONTAR LOS NODOS EN EL NIVEL N

int Num_Nodos(TArbin a, int n)
{
	if (a==NULL) return 0;
	if (n==0) return 1;
	return Num_Nodos(a->izq,n-1)+Num_Nodos(a->der,n-1);
}

// DOS ARBOLES SON IGUALES

int Arb_Iguales (TArbin a, TArbin b)
{
	if (a==NULL && b==NULL) return 1;
	if (a==NULL || b==NULL) return 0;
	if (a->info!=b->info) return 0;
	return Arb_Iguales(a->izq,b->izq) && Arb_Iguales(a->der, b->der);
}

// RECORRIDOS

void PosOrden(TArbin a)
{
	if (a!=NULL)
	{
		PosOrden(a->izq);
		PosOrden(a->der);
		printf("\t%d\n",a->info);
	}
}

void PreOrden(TArbin a)
{
	if(a!=NULL)
	{
		printf("\t%d\n",a->info);
		PreOrden(a->izq);
		PreOrden(a->der);	
	}
}

// INSERTA EN ORDEN

int Inserta_Arbin(TArbin *a, Tipo x)
{
	TArbin t;
	if(*a==NULL)
	{
		t=Crea_Nodo(x);
		if(t==NULL) return 0;
		*a=t;
		return 1;
	}
	if(x<(*a)->info)
		return Inserta_Arbin(&((*a)->izq),x);
	return Inserta_Arbin(&((*a)->der),x);
}

// ELIMINA

TArbin EliminarA(TArbin a, Tipo x)
{
	TArbin t;
	if(a==NULL) return NULL;
	if(x<a->info)
		a->izq=EliminarA(a->izq,x);
	if(x>a->info)
		a->der=EliminarA(a->der,x);
	else
	{
		if(a->izq==NULL && a->der==NULL)
		{
			free(a);
			return NULL;
		}
		if(a->izq==NULL)
		{
			t=a;
			free(a);
			return t->der;
		}
		if(a->der==NULL)
		{
			t=a;
			free(a);
			return t->izq;
		}
		a->info=Maxi(a->izq);
		a->izq=EliminarA(a->izq,x);
	}
	return a;
}

int EliminarB(TArbin *a, int x)
{
	TArbin t;
	int dato;
	if(*a==NULL) return 0;
	if((*a)->info==x)
	{
		if((*a)->izq==NULL)
		{
			t=*a;
			*a=t->der;
			free(t);
			return 1;
		}
		if((*a)->der==NULL)
		{
			t=*a;
			*a=t->izq;
			free(t);
			return 1;
		}
		dato=Maxi((*a)->izq);
		(*a)->info=dato;
		return EliminarB(a,x);

	}
}

//REGRESA EL VALOR MAXIMO DEL ARBOL

Tipo Maxi(TArbin a)
{
	if( a->der==NULL)
	{
		return a->info;
	}
	else
	Maxi(a->der);
}

//MENU DE OPCIONES

int Menu()
{
	int opc;
	do
	{
		printf("\n");
		printf("\n\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&");
		printf("\n\t*           1.- INSERTAR                                    *");
		printf("\n\t*           2.- ELIMINAR                                    *");
		printf("\n\t*           3.- IMPRIMIR                                    *");
		printf("\n\t*           4.- PESO DEL ARBOL                              *");
		printf("\n\t*           5.- BUSCAR UN ELEMENTO                          *");
		printf("\n\t*           6.- NUMERO DE HOJAS                             *");
		printf("\n\t*           7.- NUMERO DE HOJAS EN EL NIVEL QUE DESEA       *");
		printf("\n\t*           8.- ALTURA DEL ARBOL                            *");
		printf("\n\t*           9.- PODAR                                       *");
		printf("\n\t*           10.- SALIR                                      *");
		printf("\n\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&");
		printf("\n");
		printf("\n\tOPCION >> ");
		scanf("%d",&opc);
	} while(opc<1 || opc>10);

	return opc;
}

int Altura(TArbin a)
{
	int i,j;
	if(a==NULL)return 0;
	i=Altura(a->izq);
	j=Altura(a->der);
	return i>j?(i+1):(j+1);
	
}

void PodarA(TArbin *a)
{
	if(*a!=NULL)
	{
		if((*a)->izq==NULL && (*a)->der==NULL)
		{
			free(*a);
			*a=NULL;
		}
		PodarA(&((*a)->izq));
		PodarA(&((*a)->der));
	}
}

void PodarB(TArbin *a)
{
	if(*a!=NULL)
	{
		PodarB(&((*a)->izq));
		PodarB(&((*a)->der));
	}
}

// Niveles(TArbin a) //....................PENDIENTE
//{
//	TArbin t;
//	TCola q;
//
//	q=inicializacola();
//	if(a!=NULL)
//	{
//		insertacola(&q,a);
//		while(!colavacia(q))
//		{
//			eliminacola(&q,&t);
//			printf("%d \n",t->info);
//			if(t->izq!=NULL)
//				insertacola(&q,t->izq);
//			if(t->der!=NULL)
//				insertacola(&q,t->der);
//		}
//	}
//
