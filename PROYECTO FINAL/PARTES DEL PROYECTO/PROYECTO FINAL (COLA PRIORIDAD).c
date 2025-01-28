#include <stdio.h>
#include <stdlib.h>

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

int Menu();
int Menu2();
void Cola_Prioridad(NODOPTR *g, long int k, REGISTRO reg);
NODOPTR Crea_Nodo(int long k, REGISTRO reg);
void Inicializa_Cola(NODOPTR *g);
void Imp_Cola(NODOPTR g);
int Sub_Col(NODOPTR a, NODOPTR b);
NODOPTR Buscar(NODOPTR g, int long k);
void Elimina(NODOPTR *g, NODOPTR a);
REGISTRO Leer();
int Long_Col(NODOPTR c);
void Liberar_Col(NODOPTR *col);

int main()
{
	NODOPTR ColaP,Dato;
	REGISTRO reg;
	long int cod;
	int opc,opc2;
	FILE *f;
	Inicializa_Cola(&ColaP);

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

					Cola_Prioridad(&ColaP,cod,reg);
				}

				fclose(f);
				break;
			}

			case 2:
			{
				printf("\n\tLLAVE >> ");
				scanf("%ld",&cod);

				Dato=Buscar(ColaP,cod);

				if(Dato!=NULL)
				{
					printf("\n\t >>> PACIENTE ENCONTRADO <<<\n");
					Elimina(&ColaP,Dato);
				}
				else
				{
					printf("\n\t>>> NO SE ENCONTRO EL PACIENTE <<<\n");

					opc2=Menu2();

					if(opc2==1)
					{
						printf("\n\tINGRESE LOS DATOS DEL PACIENTE\n\n");
						reg=Leer();

						Cola_Prioridad(&ColaP,cod,reg);
					}
				}

				break;
			}

			case 3:
			{
				
				Liberar_Col(&ColaP);
				break;
			}

			case 4:
			{
				Imp_Cola(ColaP);
				break;
			}
		}
	}while(opc!=5);

	return 0;
}

NODOPTR Crea_Nodo(int long k, REGISTRO reg)
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

void Cola_Prioridad(NODOPTR *g, long int k, REGISTRO reg)
{
	NODOPTR q,p,new;
	p=q=*g;

	new=Crea_Nodo(k,reg);

	if(q==NULL || k<=q->clave)
	{
		new->sig=*g;
		*g=new;
		return;
	}
	while(q->sig!=NULL)
	{
		p=q;
		q=q->sig;
		if(k<q->clave)
		{
			new->sig=q;
			p->sig=new;
			return;
		}
	}
	if(k<q->clave)
	{
		new->sig=q;
		p->sig=new;
		return;
	}
	else
		q->sig=new;
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
		printf("\n\t <<< NO EXISTEN DATOS >>> \n");
		return;
	}
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

REGISTRO Leer()
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
	}while(opc<1 || opc>2);

	return opc;
}