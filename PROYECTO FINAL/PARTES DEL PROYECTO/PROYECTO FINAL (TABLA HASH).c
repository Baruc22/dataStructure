#include <stdio.h>
#include <stdlib.h>
#define TAM_TABLA 100

struct paciente//ESTRUCTURA DE COLA PRIORIDAD
{
	char nombre[20];
	int edad;
	char sexo[10];
	char enfermedad[20];
	char nacionalidad[20];
};

typedef struct paciente REGISTRO;

struct nodo//ESTRUCTURA DE COLA PRIORIDAD
{
	long int clave;
	REGISTRO info;
	struct nodo *sig;
};

typedef struct nodo *NODOPTR;

int Menu();
int Menu2();

NODOPTR Crea_Nodo(int long k, REGISTRO reg);
void Inicializa_Tabla(NODOPTR T[]);
int HASH(long int key);
NODOPTR Encadenamiento(NODOPTR T[], int long k, REGISTRO R);
REGISTRO Leer();
void Imprime_Hash(NODOPTR g[]);
void Elimina_HASH(NODOPTR T[], NODOPTR x);
void Liberar_Col(NODOPTR *col);
int Long_Col(NODOPTR c);
void Libera_HASH(NODOPTR T[]);

int main()
{
	NODOPTR Tabla[TAM_TABLA],H;
	int opc,opc2;
	long int cod;
	REGISTRO reg,reg2;
	FILE *f;

	Inicializa_Tabla(Tabla);
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
					fscanf(f,"%s",&reg.nombre);
					fscanf(f,"%d",&reg.edad);
					fscanf(f,"%s",&reg.sexo);
					fscanf(f,"%s",&reg.enfermedad);
					fscanf(f,"%s",&reg.nacionalidad);

					Encadenamiento(Tabla,cod,reg);
				}

				fclose(f);

				break;
			}

			case 2:
			{
				reg2.edad=0;
				printf("\n\tLLAVE >> ");
				scanf("%ld",&cod);
				H=Encadenamiento(Tabla,cod,reg2);
				if(H!=NULL)
				{
					printf("\n\t >>> PACIENTE ENCONTRADO <<<\n");

					printf("\tCLAVE >> %ld\n",H->clave);
					printf("\tNOMBRE >> %s\n",H->info.nombre);
					printf("\tEDAD >> %d\n",H->info.edad);
					printf("\tSEXO >> %s\n",H->info.sexo);
					printf("\tENFERMEDAD >> %s\n",H->info.enfermedad);
					printf("\tNACIONALIDAD >> %s\n",H->info.nacionalidad);

					Elimina_HASH(Tabla,H);
				}
				else
				{
					printf("\n\t>>> NO SE ENCONTRO EL PACIENTE <<<\n");

					opc2=Menu2();

					if(opc2==1)
					{
						printf("\n\tINGRESE LOS DATOS DEL PACIENTE\n\n");
						reg2=Leer();
						Encadenamiento(Tabla,cod,reg2);

					}
				}
				break;
			}

			case 3:
			{
				Libera_HASH(Tabla);
				break;
			}

			case 4:
			{
				Imprime_Hash(Tabla);
				break;
			}
		}

	}while(opc!=5);
}

int Menu()
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

void Inicializa_Tabla(NODOPTR T[])
{
	NODOPTR new;
	REGISTRO reg;
	int i,k=-1;

	for(i=0;i<TAM_TABLA;i++)
	{
		T[i]=NULL;
		new=Crea_Nodo(k,reg);
		T[i]=new;
	}

	return;
}

NODOPTR Crea_Nodo(int long k, REGISTRO reg)//FUNCION DE COLA PRIORIDAD
{
	NODOPTR new;
	new=(NODOPTR)malloc(sizeof(struct nodo));

	if(new!=NULL)
	{
		new->clave=k;
		new->info=reg;
		new->sig=NULL;
	}

	return new;
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
	return (k=(int)key%TAM_TABLA);
}

REGISTRO Leer()//FUNCION DE COLA PRIORIDAD
{
	REGISTRO new;

	printf("\tNOMBRE >> ");
	scanf("%s",new.nombre);
	printf("\tEDAD >> ");
	scanf("%d",&new.edad);
	printf("\tSEXO >> ");
	scanf("%s",new.sexo);
	printf("\tENFERMEDAD >> ");
	scanf("%s",new.enfermedad);
	printf("\tNACIONALIDAD >> ");
	scanf("%s",new.nacionalidad);

	return new;
}

void Imprime_Hash(NODOPTR g[])
{
	int i;
	NODOPTR aux;
	printf("\n\t******* INFORMACION DE LA TABLA *******\n\n");
	for (i=0;i<TAM_TABLA;i++)
	{
		aux=g[i];
		aux=aux->sig;
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
	}
	printf("\t***************************************");
	return;
}


void Elimina_HASH(NODOPTR T[], NODOPTR x)
{
	int i;
	NODOPTR aux,p;
	for(i=0;i<TAM_TABLA;i++)
	{
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

void Liberar_Col(NODOPTR *col)//FUNCION DE COLA PRIORIDAD
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

int Long_Col(NODOPTR c)//FUNCION DE COLA PRIORIDAD
{
	NODOPTR aux;
	int i;
	aux=c;
	for(i=0;aux!=NULL;i++)
		aux=aux->sig;

	return i;
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