#include <stdio.h>
#include <stdlib.h>
#define TAM_TABLA 35

struct paciente
{
	char nombre[20];
	int edad;
	char sexo[10];
	char enfermedad[20];
	char nacionalidad[20];
};

typedef struct paciente REGISTRO;

struct nodo
{
	long int clave;
	REGISTRO info;
	struct nodo *sig;
};

typedef struct nodo *NODOPTR;

struct NodoArb
{
	long int clave;    
	REGISTRO info;
	struct NodoArb *der;
	struct NodoArb *izq;
};

typedef struct NodoArb *ARBOL;

/*FUNCIONES PARA LA COLA DE PRIORIDAD*/
void Cola_Prioridad(NODOPTR *g, long int k, REGISTRO reg);
NODOPTR Crea_Nodo(int long k, REGISTRO reg);
void Inicializa_Cola(NODOPTR *g);
void Imp_Cola(NODOPTR g);
int Sub_Col(NODOPTR a, NODOPTR b);
NODOPTR Buscar(NODOPTR g, int long k);
void Elimina(NODOPTR *g, NODOPTR a);
int Long_Col(NODOPTR c);
void Liberar_Col(NODOPTR *col);

/*FUNCIONES DE LA TABLA HASH*/
void Inicializa_Tabla(NODOPTR T[]);
int HASH(long int key);
NODOPTR Encadenamiento(NODOPTR T[], int long k, REGISTRO R);
void Imprime_Hash(NODOPTR g[]);
void Elimina_HASH(NODOPTR T[], NODOPTR x);
void Libera_HASH(NODOPTR T[]);

/*FUNCIONES DEL ARBOL BINARIO*/
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

/*FUNCIONES COMPLEMENTARIAS*/
int Menu();
int Menu2();
int Submenu();
REGISTRO Leer();

/*FUNCIONES DE COLA DE PRIORIDAD*/
NODOPTR Crea_Nodo(int long k, REGISTRO reg)
{
	NODOPTR nodo;
	nodo=(NODOPTR)malloc(sizeof(struct nodo));

	if(nodo!=NULL)
	{
		nodo->clave=k;
		nodo->info=reg;
		nodo->sig=NULL;
	}

	return nodo;
}

void Cola_Prioridad(NODOPTR *g, long int k, REGISTRO reg)
{
	NODOPTR q,p,nodo;
	p=q=*g;

	nodo=Crea_Nodo(k,reg);

	if(q==NULL || k<=q->clave)
	{
		nodo->sig=*g;
		*g=nodo;
		return;
	}
	while(q->sig!=NULL)
	{
		p=q;
		q=q->sig;
		if(k<q->clave)
		{
			nodo->sig=q;
			p->sig=nodo;
			return;
		}
	}
	if(k<q->clave)
	{
		nodo->sig=q;
		p->sig=nodo;
		return;
	}
	else
		q->sig=nodo;
	return;
}

void Inicializa_Cola(NODOPTR *g)
{
	*g=NULL;
}


void Imp_Cola(NODOPTR g)
{
	NODOPTR aux;
	int i=0;
	aux=g;

	if(aux==NULL)
	{
		printf("\n\t <<< NO EXISTEN DATOS >>> \n\n");
		return;
	}
	printf("\n\t******* INFORMACION *******\n\n");
	while(aux!=NULL)
	{
		printf("\tCLAVE >> %ld\n",aux->clave);
		printf("\tNOMBRE >> %s\n",aux->info.nombre);
		printf("\tEDAD >> %d\n",aux->info.edad);
		printf("\tSEXO >> %s\n",aux->info.sexo);
		printf("\tENFERMEDAD >> %s\n",aux->info.enfermedad);
		printf("\tNACIONALIDAD >> %s\n",aux->info.nacionalidad);
		printf("\n");

		aux=aux->sig;

	}
	printf("\t***************************\n");

	return;
}

NODOPTR Buscar(NODOPTR g, int long k)
{
	NODOPTR linf,lsup,aux;
	int mid,i;
	aux=linf=lsup=g;

	if(linf==NULL)
		return linf;

	while(lsup->sig!=NULL)
		lsup=lsup->sig;

	while(linf->sig!=lsup)
	{
		mid=Sub_Col(linf,lsup)/2;
		aux=linf;

		for(i=1;i<=mid;i++)
			aux=aux->sig;

		if(k==aux->clave)
			return aux;
		if(k<aux->clave)
			lsup=aux;
		if(k>aux->clave)
			linf=aux;
	}
	if(k==lsup->clave)
		return lsup;
	if(k==linf->clave)
		return linf;
	else
		return NULL;
	


}


int Sub_Col(NODOPTR a, NODOPTR b)
{
	NODOPTR aux;
	int i=1;
	aux=a;

	while(aux!=b)
	{
		i++;
		aux=aux->sig;
	}
	return i;
}


void Elimina(NODOPTR *g, NODOPTR a)
{
	NODOPTR aux,p;
	aux=*g;

	if(aux==a)
	{
		p=aux->sig;
		(*g)->sig=p->sig;
		aux->sig=NULL;
		Imp_Cola(aux);
		free(aux);
		return;
	}
	while(aux!=a)
	{
		p=aux;
		aux=aux->sig;
	}
	if(aux->sig==NULL)
	{
		p->sig=NULL;
		Imp_Cola(aux);
		free(aux);
		return;
	}
	else
	{
		p->sig=aux->sig;
		aux->sig=NULL;
		Imp_Cola(aux);
		free(aux);
		return;
	}
}


int Long_Col(NODOPTR c)
{
	NODOPTR aux;
	int i;
	aux=c;
	for(i=0;aux!=NULL;i++)
		aux=aux->sig;

	return i;
}


void Liberar_Col(NODOPTR *col)
{
	NODOPTR p,q;
	int i,j;

	if((*col)==NULL)
		return;

	j=Long_Col(*col);

	for(i=0;i<=j;i++)
	{
		p=q=*col;
		while(q->sig!=NULL)
		{
			p=q;
			q=q->sig;
		}
		if(p==q)
		{
			free(q);
			*col=NULL;
			return;
		}
		free(q);
		p->sig=NULL;
	}
}
/*FIN DE LAS FUNCIONES DE COLA DE PRIORIDAD*/

/*FUNCIONES DE LA TABLA HASH*/
void Inicializa_Tabla(NODOPTR T[])
{
	NODOPTR nodo;
	REGISTRO reg;
	int i,k=-1;

	for(i=0;i<TAM_TABLA;i++)
	{
		T[i]=NULL;
		nodo=Crea_Nodo(k,reg);
		T[i]=nodo;
	}

	return;
}

NODOPTR Encadenamiento(NODOPTR T[], int long k, REGISTRO R)
{
	NODOPTR p,s;
	int i;
	i=HASH(k);

	p=T[i];
	while(p->sig!=NULL && p->clave!=k)
		p=p->sig;
	if(p->clave==k)
		return p;
	if(R.edad!=0)
	{
		s=Crea_Nodo(k,R);
		p->sig=s;
		return s;
	}
	else
		return NULL;
}

int HASH(long int key)
{
	int k;
	return (k=(int)key%100);
}

void Imprime_Hash(NODOPTR g[])
{
	int i,r=0;
	NODOPTR aux;
	printf("\n\t******* INFORMACION *******\n\n");
	for (i=0;i<TAM_TABLA;i++)
	{
		aux=g[i];
		aux=aux->sig;
		while(aux!=NULL)
		{
			if(r==0){
				printf("\t\tDIA %d \n\n",i);
				r=1;
			}
			printf("\tCLAVE >> %ld\n",aux->clave);
			printf("\tNOMBRE >> %s\n",aux->info.nombre);
			printf("\tEDAD >> %d\n",aux->info.edad);
			printf("\tSEXO >> %s\n",aux->info.sexo);
			printf("\tENFERMEDAD >> %s\n",aux->info.enfermedad);
			printf("\tNACIONALIDAD >> %s\n",aux->info.nacionalidad);
			printf("\n");

			aux=aux->sig;
		}
		r=0;
	}
	printf("\t*****************************\n");
	return;
}


void Elimina_HASH(NODOPTR T[], NODOPTR x)
{
	int i;
	NODOPTR aux,p;
	i=HASH(x->clave);

	aux=T[i];
	p=T[i];
	aux=aux->sig;
	while(aux!=x && aux!=NULL)
	{
		p=aux;
		aux=aux->sig;
	}
	if(aux==x && aux->sig==NULL)
	{
		free(aux);
		p->sig=NULL;
		return;
	}
	if(aux==x)
	{
		p->sig=aux->sig;
		free(aux);
		return;
	}

	return;
}

void Libera_HASH(NODOPTR T[])
{
	NODOPTR aux;
	int i;
	for(i=0;i<TAM_TABLA;i++)
	{
		aux=T[i];
		Liberar_Col(&aux);
	}
}
/*FIN DE LAS FUNCIONES DE LA TABLA HASH*/

/*FUNCIONES DEL ARBOL*/

void Inicializa_Arbol(ARBOL *A)
{
	*A=NULL;
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
		
	printf("\n\t**********************************\n");
	printf("\t>>> NO SE ENCONTRO EL PACIENTE <<<\n");
	printf("\t**********************************\n");

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
		printf("\n\t************************************\n");
		printf("\t>>> SE INSERTO UN NUEVO PACIENTE <<<\n");
		printf("\t************************************\n");
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


void RecorrePre_Orden(ARBOL raiz)
{
	if(raiz!=NULL)
	{
		printf(" |\t%d\t|",raiz->clave);
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
		printf(" |\t%d\t|",raiz->clave);
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
		printf(" |\t%d\t|",raiz->clave);
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
/*FIN DE LAS FUNCIONES DEL ARBOL*/

/*FUNCIONES COMPLEMENTARIAS*/
REGISTRO Leer()
{
	REGISTRO reg;

	printf("\tNOMBRE >> ");
	scanf("%s",reg.nombre);
	printf("\tEDAD >> ");
	scanf("%d",&reg.edad);
	printf("\tSEXO >> ");
	scanf("%s",reg.sexo);
	printf("\tENFERMEDAD >> ");
	scanf("%s",reg.enfermedad);
	printf("\tNACIONALIDAD >> ");
	scanf("%s",reg.nacionalidad);

	return reg;
}

int Menu()
{
	int opc;
	do
	{	printf("\n\t _________________________________\n");
		printf("\t|\t\tMENU\t\t  |");
		printf("\n\t|                                 |");
		printf("\n\t| opcion 1: COLA DE PRIORIDAD \t  |");
		printf("\n\t| opcion 2: TABLA HASH \t\t  |");
		printf("\n\t| opcion 3: ARBOL BINARIO \t  |");
		printf("\n\t| opcion 4: SALIR \t\t  |\n");
		printf("\t|_________________________________| \n");
		printf("\n\t Elija una opcion:  ");
		scanf("%d",&opc);
		if(opc>4 || opc<1)
		{
			printf("\n\t>>ERROR: INTRODUZCA UN NUMERO VALIDO<<\n");
		}
	}while(opc<1 || opc>4);

	return opc;
}

int Menu2()
{
	int opc;
	printf("\n\tDESEA INSERTAR DATOS CON ESTA CLAVE\n");
	do
	{
		printf("\n\t1.-INSERTAR");
		printf("\n\t2.-OMITIR\n");
		printf("\n\tOPCION >> ");
		scanf("%d",&opc);
		if(opc>2 || opc<1)
		{
			printf("\n\t>>ERROR: INTRODUZCA UN NUMERO VALIDO<<\n");
		}
	}while(opc<1 || opc>2);

	return opc;
}

int Submenu()
{
	int opc;
	do
	{
		printf("\n\t _________________________");
		printf("\n\t|\t ACCIONES \t  |");
		printf("\n\t|                         |");
		printf("\n\t| Opcion 1: IMPRESION \t  |");
		printf("\n\t| Opcion 2: BUSCAR \t  |");
		printf("\n\t| Opcion 3: SALIR \t  |");
		printf("\n\t|_________________________|\n");
		printf("\n\t Elija una opcion: ");
		scanf("%d",&opc);
		if(opc>3 || opc<1)
		{
			printf("\n\t>>ERROR: INTRODUZCA UN NUMERO VALIDO<<\n");
		}
	}while(opc<1 || opc>3);
	return opc;
}
