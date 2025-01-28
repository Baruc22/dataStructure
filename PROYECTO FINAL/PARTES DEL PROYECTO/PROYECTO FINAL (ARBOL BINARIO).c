#include <stdio.h>
#include <stdlib.h>

struct paciente//ESTRUCTURA DE COLA PRIORIDAD
{
	char nombre[20];
	int edad;
	char sexo[10];
	char enfermedad[20];
	char nacionalidad[20];
};

typedef struct paciente REGISTRO;

struct NodoArb
{
	long int clave;    
	REGISTRO info;
	struct NodoArb *der;
	struct NodoArb *izq;
};

/*AGREGAR ESTA NUEVA ESTRUCTURA (TENER CUIDADO CON LA REDEFINICION)
CAMBIAR TODAS LAS DEFINICIONES DE "NODOPTR" DE ESTA PARTE, CON LA NUEVA REDEFINICION DE LA ESTRUCTURA*/

typedef struct NodoArb *ARBOL;

void Inicializa_Arbol(ARBOL *A);
void busArbolBin(ARBOL raiz,long int key);
void insertarArbolBin(ARBOL raiz,long int key, REGISTRO res);
ARBOL crearHijoIzq(ARBOL p,long int key, REGISTRO res);
ARBOL crearHijoDer(ARBOL p,long int key, REGISTRO res);
ARBOL crearArbol(long int key, REGISTRO res);
void RecorrePre_Orden(ARBOL raiz);
void Recorre_Orden(ARBOL raiz);
void RecorrePos_Orden(ARBOL raiz);
void Podar_Arb(ARBOL a);
int Profundidad_Arb(ARBOL a);
int Menu();
int Menu2();



int main()
{
	ARBOL A;
	int opc,Prof,i;
	long int cod;
	REGISTRO res;
	FILE *f;
	Inicializa_Arbol(&A);
	do
	{
		opc=Menu();

		switch(opc)
		{
			case 1:
			{
				f=fopen("prueba.txt","r");
				while(fscanf(f,"%ld",&cod)!=EOF)
				{
					fscanf(f,"%s",&res.nombre);
					fscanf(f,"%d",&res.edad);
					fscanf(f,"%s",&res.sexo);
					fscanf(f,"%s",&res.enfermedad);
					fscanf(f,"%s",&res.nacionalidad);

					if(A==NULL)
					{
						A=crearArbol(cod,res);
					}
					else
						insertarArbolBin(A,cod,res);
				}

				fclose(f);
				
				break;
			}

			case 2:
			{
				printf("\n\tCLAVE >> ");
				scanf("%ld",&cod);
				busArbolBin(A,cod);
				break;
			}

			case 3:
			{
				Prof=Profundidad_Arb(A);
				for(i=1;i<Prof;i++)
					Podar_Arb(A);
				free(A);
				A=NULL;
				break;	
			}

			case 4:
			{
				printf("\n\tRECORRIDO EN PRE-ORDEN >> ");
				RecorrePre_Orden(A);
				printf("\n\tRECORRIDO EN ORDEN >> ");
				Recorre_Orden(A);
				printf("\n\tRECORRIDO EN POS-ORDEN >> ");
				RecorrePos_Orden(A);
				printf("\n");

				break;
			}
		}
	}while(opc!=5);

	return 0;
}

void busArbolBin(ARBOL raiz,long int key)
{
	ARBOL p,q;
	p=q=raiz;
	REGISTRO res;
	int opc;
	while(key!=p->clave && q!=NULL)
	{
		p=q;
		if(key<p->clave)
			q=p->izq;
		else
			q=p->der;
	}
	if(key==p->clave)
	{
		printf("\n\t >>> PACIENTE ENCONTRADO <<<\n\n");

		printf("\tCLAVE >> %ld\n",p->clave);
		printf("\tNOMBRE >> %s\n",p->info.nombre);
		printf("\tEDAD >> %d\n",p->info.edad);
		printf("\tSEXO >> %s\n",p->info.sexo);
		printf("\tENFERMEDAD >> %s\n",p->info.enfermedad);
		printf("\tNACIONALIDAD >> %s\n",p->info.nacionalidad);
		printf("\n");

		return;
	}
		
	printf("\n\t>>> NO SE ENCONTRO EL PACIENTE <<<\n");
	opc=Menu2();
	if(opc==1)
	{
		printf("\n\tINGRESE LOS DATOS DEL PACIENTE\n\n");
		printf("\tNOMBRE >> ");
		scanf("%s",res.nombre);
		printf("\tEDAD >> ");
		scanf("%d",&res.edad);
		printf("\tSEXO >> ");
		scanf("%s",res.sexo);
		printf("\tENFERMEDAD >> ");
		scanf("%s",res.enfermedad);
		printf("\tNACIONALIDAD >> ");
		scanf("%s",res.nacionalidad);
		if(key<p->clave)
			crearHijoIzq(p,key,res);
		else
			crearHijoDer(p,key,res);
	}

}

void insertarArbolBin(ARBOL raiz,long int key, REGISTRO res)
{
	ARBOL p,q;
	p=q=raiz;
	while(q!=NULL)
	{
		p=q;
		if(key<p->clave)
			q=p->izq;
		else
			q=p->der;
	}
	if(key<p->clave)
		crearHijoIzq(p,key,res);
	else
		crearHijoDer(p,key,res);
}

ARBOL crearHijoIzq(ARBOL p,long int key, REGISTRO res)
{
	if(p==NULL)
		printf("Creacion invalida\n");
	else if(p->izq!=NULL)
		printf("Insercion invalida\n");
	else
		p->izq=crearArbol(key,res);
}

ARBOL crearHijoDer(ARBOL p,long int key, REGISTRO res)
{
	if(p==NULL)
		printf("Creacion invalida\n");
	else if(p->der!=NULL)
		printf("Insercion invalida\n");
	else
		p->der=crearArbol(key,res);
}

ARBOL crearArbol(long int key, REGISTRO res)
{
	ARBOL n;
	n=(ARBOL)malloc(sizeof(struct NodoArb));

	n->clave=key;
	n->info=res;
	n->izq=NULL;
	n->der=NULL;
	return n;
}


int Menu()//FUNCION DE COLA PRIORIDAD
{
	int opc;
	do
	{
		printf("\n\t1.-LEER");
		printf("\n\t2.-BUSCAR");
		printf("\n\t3.-LIBERAR");
		printf("\n\t4.-IMPRIMIR");
		printf("\n\t5.-SALIR\n");
		printf("\n\tOPCION >> ");
		scanf("%d",&opc);
	}while(opc<1 || opc>5);

	return opc;
}

int Menu2()//FUNCION DE COLA PRIORIDAD
{
	int opc;
	printf("\n\tDESEA INSERTAR DATOS CON ESTA CLAVE\n");
	do
	{
		printf("\n\t1.-INSERTAR");
		printf("\n\t2.-OMITIR\n");
		printf("\n\tOPCION >> ");
		scanf("%d",&opc);
	}while(opc<1 || opc>2);

	return opc;
}


void RecorrePre_Orden(ARBOL raiz)
{
	if(raiz!=NULL)
	{
		printf(" |%d|",raiz->clave);
		RecorrePre_Orden(raiz->izq);
		RecorrePre_Orden(raiz->der);
	}

	return;
}

void Recorre_Orden(ARBOL raiz)
{
	if(raiz!=NULL)
	{
		Recorre_Orden(raiz->izq);
		printf(" |%d|",raiz->clave);
		Recorre_Orden(raiz->der);
	}

	return;
}

void RecorrePos_Orden(ARBOL raiz)
{
	if(raiz!=NULL)
	{
		RecorrePos_Orden(raiz->izq);
		RecorrePos_Orden(raiz->der);
		printf(" |%d|",raiz->clave);
	}

	return;
}

void Podar_Arb(ARBOL a)
{
	ARBOL b,c;
	if(a!=NULL)
	{
		b=a->izq;
		c=a->der;
		if(b!=NULL)
		{
			if(b->izq==NULL && b->der==NULL)
			{
				free(b);
				a->izq=NULL;
			}
		}
		if(c!=NULL)
		{
			if(c->izq==NULL && c->der==NULL)
			{
				free(c);
				a->der=NULL;
			}
		}
		Podar_Arb(a->izq);
		Podar_Arb(a->der);
	}
	return;
}

int Profundidad_Arb(ARBOL a)
{
	int i,j;
	if(a==NULL)
		return 0;
	i=1+Profundidad_Arb(a->izq);
	j=1+Profundidad_Arb(a->der);

	return (i>j)?i:j;
}

void Inicializa_Arbol(ARBOL *A)
{
	*A=NULL;
}