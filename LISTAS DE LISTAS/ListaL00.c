#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodol
{
	char nom[50];
	struct nodol *sig;
};

struct nodo
{
	char letra;
	struct nodo *sig;
	struct nodol *lista;
};

typedef struct nodo TNodo;
typedef struct nodo* TListas;
typedef struct nodol TNodol;
typedef struct nodol* TLista;


TListas inicializa()
{
	return NULL;
}

TNodo* creaNodo (char letra)
{
	TNodo *t;
	t=(TNodo*)malloc(sizeof(TNodo));
	if(t!=NULL)
	{
		t->letra=letra;
		t->sig=NULL;
		t->lista=NULL;
	}

	return t;
}

TNodol* creaNodol (char *nom)
{
	TNodol *t;
	t=(TNodol*)malloc(sizeof(TNodol));
	if (t!=NULL)
	{
		t->sig=NULL;
		strcpy(t->nom,nom);
	}
	return t;
}

int insertaNombre(TLista *l, char *nom)
{
	TLista t, ant, newp;
	newp=creaNodol(nom);
	if(newp==NULL)
	{
		return 0;
	}
	t=*l;
	while(t!=NULL && strcmp(t->nom,nom)<0)
	{
		ant=t;
		t=t->sig;
	}
	if(t==*l)
	{
		newp->sig=t;
		*l=newp;
	}
	else
	{
		newp->sig=t;
		ant->sig=newp;
	}
	return 1;
	
}

int insertaLetra (TListas *ll, char letra, char*nom)
{
	TListas ant, t, newp;
	newp=creaNodo(letra);
	if(newp==NULL)
	{
		return 0;
	}
	t=*ll;
	while(t!=NULL && letra>t->letra)
	{
		ant=t;
		t=t->sig;
	}
	if (t!=NULL && letra==t->letra)
	{
		insertaNombre(&(t->lista),nom);
	}
	else
	{
		if(*ll==t)
		{
			newp->sig=t;
			*ll=newp;
		}
		else
		{
			newp->sig=t;
			ant->sig=newp;
		}

		insertaNombre(&(newp->lista),nom);

	}
	return 1;
}

void imprimeLista(TListas ll)
{
	TNodo* tl;
	TNodol* tn;
	tl=ll;
	while(tl!=NULL){
	tn=tl->lista;
	printf("%c\n",tl->letra);
	while(tn!=NULL){
		printf("%s\n",tn->nom);
		tn=tn->sig;
		}
	tl=tl->sig;
	}
}

TListas eliminaNombre(TListas *ll,char*nom)
{
	TNodo*tl,*antl;
	TNodol*tn,*antn;
	tl=*ll;
	while(tl!=NULL)
	{
		tn=tl->lista;
		while(tn!=NULL && strcmp(tn->nom,nom)!=0)
		{
			antn=tn;
			tn=tn->sig;
		}
		if(tn==NULL)
		{
			antl=tl;
			tl=tl->sig;
		}
		else//encontró
		{
			if(tn->sig==NULL && tl->lista==tn)
			{
				antl->sig=tl->sig;
				free(tn);
				return *ll;
			}
			else{
			antn=tn->sig;
			free(tn);
			return *ll;
			}
		}

	}
}

int main ()
{
	TListas ll;
	char letra;
	char*nom;
	ll=inicializa();
	if(insertaLetra(&ll,'J',"Jose"))
		printf("Se insertó nombre\n");
	if(insertaLetra(&ll,'A',"Armando"))
		printf("Se insertó nombre\n");
	if(insertaLetra(&ll,'P',"Pedro"))
		printf("Se insertó nombre\n");
	if(insertaLetra(&ll,'R',"Roberto"))
		printf("Se insertó nombre\n");
	if(insertaLetra(&ll,'A',"Andres"))
		printf("Se insertó nombre\n");
	if(insertaLetra(&ll,'A',"Apolinar"))
		printf("Se insertó nombre\n");
	if(insertaLetra(&ll,'P',"Pablo"))
		printf("Se insertó nombre\n");
	if(insertaLetra(&ll,'V',"Vilma"))
		printf("Se insertó nombre\n");
	imprimeLista(ll);
	ll=eliminaNombre(&ll,"Vilma");
	imprimeLista(ll);
	return 0;

}


