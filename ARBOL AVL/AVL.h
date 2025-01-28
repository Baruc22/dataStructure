#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int Tipo;

struct nodoAVL
{
	Tipo info;
	struct nodoAVL *izq;
	struct nodoAVL *der;
	int fb;
};

typedef struct nodoAVL TNodoAVL;
typedef struct nodoAVL* TAVL;

Tipo Altura(TAVL a);
TAVL Inicializa();
TAVL Crea_Nodo(Tipo x);
void FactoresBalanceo(TAVL *a);
TAVL Balancear(TAVL a);
TAVL Rota_Der (TAVL a);
TAVL Rota_Izq(TAVL a);
TAVL Rota_DerIzq (TAVL a);
TAVL Rota_IzqDer(TAVL a);
TAVL Inserta_AVL(TAVL a, Tipo x);
Tipo Maxi(TAVL a);
void PosOrden(TAVL a);
TAVL Elimina_Nodo(TAVL a, Tipo x);
void PreOrden(TAVL a);
int Menu();
int Existe_X(TAVL a, Tipo x);
Tipo Raiz (TAVL a);
int Arbin_Vacio(TAVL a);
TAVL Izquierda(TAVL a);
TAVL Derecha(TAVL a);
int Peso(TAVL a);
int Hojas(TAVL a);
int Num_Nodos(TAVL a, int n);



TAVL Inicializa()
{return NULL;}

TAVL Crea_Nodo(Tipo x)
{
	TAVL t;
	t=(TAVL)malloc(sizeof(TNodoAVL));
	if(t!=NULL)
	{
		t->info=x;
		t->izq=t->der=NULL;
		t->fb=0;
	}
	return t;
}

Tipo Altura(TAVL a)
{
	int i,j;
	if(a==NULL)return 0;
	i=Altura(a->izq);
	j=Altura(a->der);
	return i>j?(i+1):(j+1);
	
}

void FactoresBalanceo(TAVL *a)
{
	if(*a!=NULL)
	{
		(*a)->fb=Altura((*a)->izq)-Altura((*a)->der);
		FactoresBalanceo(&((*a)->izq));
		FactoresBalanceo(&((*a)->der));		
	}
}

TAVL Balancear(TAVL a)
{
	TAVL t;
	if (a->fb==2)
		if(a->izq->fb==1)
		{
			t=Rota_Der(a);
		}
		else
		{
			t=Rota_IzqDer(a);
		}
	else
	{
		if(a->der->fb==-1)
		{
			t=Rota_Izq(a);
		}
		else
		{
			t=Rota_DerIzq(a);
		}
		FactoresBalanceo(&t);
		return t;
	}
}

//ELIMINA

TAVL Elimina_Nodo(TAVL a, Tipo x)
{
	TAVL t;
	int i;
	if (a==NULL) return NULL;
	  if (a->info==x)
	  {
		if(a->izq==NULL)
		{
			t=a;
			a=t->der;
			free(t);
		}
		else if (a->der==NULL)
		{
			t=a;
			a=t->der;
			free(t);
		}
		else
		{
			i=Maxi(a->izq);
			a->info=i;
			a->izq=Elimina_Nodo(a->izq,i);
			a->fb=Altura(a->izq)-Altura(a->der);
			if(abs(a->fb)>1) a=Balancear(a);
		}
	  }
	else
	{
		if(x<a->info)
			a->izq=Elimina_Nodo(a->izq,x);
		else
		{
			a->der=Elimina_Nodo(a->der,x);
			a->fb=Altura(a->izq)-Altura(a->der);
			if (abs(a->fb)>1) a=Balancear(a);
		}
	}
	return a;
}

//ARBOLES BALANCEADOS POR ALTURA.

TAVL Rota_Der (TAVL a) //caso 3
{
	TAVL t;
	t=a->izq;
	a->izq=t->der;
	t->der=a;
	return t;
}

TAVL Rota_Izq(TAVL a)
{
	TAVL t;
	t=a->der;
	a->der=t->izq;
	t->izq=a;
	return t;
}

TAVL Rota_DerIzq (TAVL a) //caso 4
{
	a->der=Rota_Der(a->der);
	return Rota_Izq(a);
}

TAVL Rota_IzqDer(TAVL a) //caso 5
{
	a->izq=Rota_Izq(a->izq);
	return Rota_Der(a);
}

// INSERTA AVL

TAVL Inserta_AVL(TAVL a,Tipo x)
{
    if(a==NULL)
    {
        TAVL nuevo;
        nuevo=Crea_Nodo(x);
        return nuevo;
    }
    
    if(x<(a->info))
	{
		(a->izq)=Inserta_AVL((a->izq),x);
	}
    else
    {
        (a->der)=Inserta_AVL((a->der),x);
	}
    (a->fb)=(Altura(a->izq))-(Altura(a->der));
    if(abs(a->fb)>1)
	a=Balancear(a);
    return a;
}

//MAXIMO DEL 

Tipo Maxi(TAVL a)
{
	if( a->der==NULL)
	{
		return a->info;
	}
	else
	Maxi(a->der);
}

//RECORRE

void PosOrden(TAVL a)
{
	if (a!=NULL)
	{
		PosOrden(a->izq);
		PosOrden(a->der);
		printf("%d\n",a->info);
	}
}

void PreOrden(TAVL a)
{
	if(a!=NULL)
	{
		printf("\t%d\n",a->info);
		PreOrden(a->izq);
		PreOrden(a->der);	
	}
}

int Menu()
{
	int opc;
	do
	{
		printf("\n");
		printf("*********************************************");
		printf("\n");
		printf("\n\t>>> ** MENU DE OPERACIONES ** <<<");
		printf("\n");
		printf("\n\t1.-INSERTAR");
		printf("\n\t2.-IMPRIMIR");
		printf("\n\t3.-ELIMINAR");
		printf("\n\t4.-PESO");
		printf("\n\t5.-BUSCAR ELEMENTO");
		printf("\n\t6.-NUMERO DE HOJAS");
		printf("\n\t7.-NUMERO DE NODOS EN EL NIVEL QUE DESEA");
		printf("\n\t8.-SALIR");
		printf("\n");
		printf("\n*******************************************");
		printf("\n");
		printf("\n\tOPCION>> ");
		scanf("%d",&opc);
	}while(opc<1 || opc>8);

	return opc;
}

int Existe_X(TAVL a, Tipo x)
{
	if(Arbin_Vacio(a)) return 0;
	if(Raiz(a)==x) return 1;

	return Existe_X(Izquierda(a),x) || Existe_X(Derecha(a),x);
}

TAVL Izquierda(TAVL a)
{
	return a->izq;
}

TAVL Derecha(TAVL a)
{
	return a->der;
}

Tipo Raiz (TAVL a)
{
	return a->info;
}

int Arbin_Vacio(TAVL a)
{
	return a==NULL;
}

int Peso(TAVL a)
{
	if(a==NULL)
	{
		return 0;
	}
	return 1+Peso(a->izq)+Peso(a->der);
}

int Hojas(TAVL a)
{
	if (a==NULL) return 0;
	if (a->izq==NULL && a->der==NULL) return 1;
	return Hojas (a->izq)+ Hojas(a->der);
}

int Num_Nodos(TAVL a, int n)
{
	if (a==NULL) return 0;
	if (n==0) return 1;
	return Num_Nodos(a->izq,n-1)+Num_Nodos(a->der,n-1);
}