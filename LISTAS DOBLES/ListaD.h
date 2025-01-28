#include <stdio.h>
#include <stdlib.h>

typedef int tipo;

struct nodoD
{
	tipo info;
	struct nodoD *sig;
	struct nodoD *ant;
};

typedef struct nodoD TNodoD;
typedef TNodoD *TListaD;

TListaD* Inserta_Fin(TListaD *ld, tipo dato);
TListaD* Inserta_Inicio(TListaD *ld, tipo dato);
TListaD* Elimina_Fin(TListaD *ld);
TListaD* Inserta_Antes_y(TListaD *ld, tipo y, tipo dato);
TListaD* Inserta_Despues_y(TListaD *ld, tipo y, tipo dato);
TListaD* Elimina_Inicio(TListaD *ld);
TListaD* Elimina_Elemento_x(TListaD ld, tipo x);
void Busca_el_Elemento_x(TListaD *ld, tipo x);
void Imprime_Lista(TListaD *ld);
TListaD* Inicializa_Lista();
TNodoD* Crea_Nodo();
TNodoD* Crea_NodoDx (tipo x);

TNodoD* Crea_NodoDx (tipo x)
{
	TNodoD *t;
	t=(TNodoD*)malloc(sizeof(TNodoD));
	if (t!=NULL)
	{
		t->info=x;
		t->sig=t->ant=NULL;
	}
	return t;
}

TNodoD* Crea_Nodo()
{
	return (TNodoD*)malloc(sizeof(TNodoD));
} 

TListaD* Inicializa_Lista()
{
	return NULL;
}   

void Imprime_Lista(TListaD *ld)
{
	TNodoD *t;
	t=ld;
	while(t!=NULL)
	{
		printf("\t%d\n",t->info);
		t=t->sig;
	}
}

void Busca_el_Elemento_x(TListaD *ld, tipo x)
{
	int b=0;
	TNodoD *t;
	t=ld;
	while(t!=NULL)
	{
		if(t->info==x)
		{
			printf("\n\tELEMENTO ENCONTRADO\n\n");
			printf("\t%d\n\n",x);
			b=x;

		}
		t=t->sig;
	}
	if(b!=x)
	{
		printf("\n\tEL ELEMENTO NO SE ENCONTRO\n\n");
	}
}

TListaD* Elimina_Elemento_x(TListaD ld, tipo x)
{
	TNodoD *t, *antes;
	t=ld;
	while(t!=NULL)
	{
		if(t->info==x && t->sig==NULL)
		{
			free(t);
			return ld;
		}
		antes=t;
		t=t->sig;
		if(t->info==x)
		{
			antes->sig=t->sig;
			t->sig=antes;
			free(t);
			return ld;
		}

	}
	return ld;
}

TListaD* Elimina_Inicio(TListaD *ld)
{
	TNodoD *t, *desp;
	t=ld;
	if (t!=NULL)
	{
		ld=t->sig;
		desp=t->sig;
		desp->ant=NULL;
		free(t);

		return ld;
	}
	else
	{
		return ld;
	}
}

TListaD* Inserta_Despues_y(TListaD *ld, tipo y, tipo dato)
{
	TNodoD *t, *desp, *newp;
	newp=Crea_NodoDx(dato);
	t=ld;
	while(t!=NULL)
	{
		desp=t;
		desp=t->sig;
		if(t->info==y)
		{
			t->sig=newp;
			newp->sig=desp;
			newp->ant=t;
			desp->ant=newp;
			return ld;
		}
	}
	return ld;

}

TListaD* Inserta_Antes_y(TListaD *ld, tipo y, tipo dato)
{
	TNodoD *t, *desp, *newp;
	newp=Crea_NodoDx(dato);
	t=ld;
	while(t!=NULL)
	{
		desp=t;
		t=t->sig;
		if(t->info==y)
		{
			desp->sig=newp;
			newp->sig=t;
			newp->ant=desp;
			t->ant=newp;
			return ld;
		}
	}
	return ld;

}

TListaD* Elimina_Fin(TListaD *ld)
{
	TNodoD *t, *antes;
	t=ld;
	while(t->sig!=NULL)
	{
		antes=t;
		t=t->sig;
	}
	if (t->sig==NULL)
	{
		antes->sig=NULL;
		free(t);
		return ld;
	}

	return ld;
}

TListaD* Inserta_Inicio(TListaD *ld, tipo dato)
{
	TNodoD *newp;
	newp=Crea_Nodo();
	if (newp!=NULL)
	{
		newp->info=dato;
		newp->sig=ld;
		newp->ant=NULL;
		ld=newp;
		return ld;
	}
	else
	{
		return ld;
	}
} 

TListaD* Inserta_Fin(TListaD *ld, tipo dato)
{
	TNodoD *newp, *t;
	newp=Crea_Nodo();
	t=ld;
	if (newp!=NULL)
	{
		if(t!=NULL)
		{
			newp->info=dato;
			newp->sig=NULL;
			while(t->sig!=NULL)
			{
				t=t->sig;
			}
			t->sig=newp;
			newp->ant=t;
			return ld;
		}
		return ld;
	}
	else
	{
		return ld;
	}
}                                    

int Lista_Vacia(TListaD *ld)
{
	return ld==NULL;
}




int insertaAntes (TListaD *ld, tipo ref, tipo x)
{
	TNodoD *t,*ant,*newp;
	t=*ld;
	while(t!=NULL && ref!=t->info)
	{
		t=t->sig;
	}
	if (t==NULL) return 0;
	newp=Crea_NodoDx(x);
	if (t==*ld)
	{
		newp->sig=t;
		t->ant=newp;
		*ld=newp;
	}
	else
	{
		ant=t->ant;
		newp->sig=t;
		newp->ant=ant;
		t->ant=newp;
		ant->sig=newp;
	}
	return 1;
}

int el1minaDespues(TListaD *ld, tipo ref, tipo *x)
{
	TNodoD *t, *t1, *t2;
	t=*ld;
	while(t!=NULL && ref!=t->info)
	{
		t=t->sig;
	}
	if (t==NULL) return 0;
	if (t->sig==NULL) return 0;
	t1=t->sig;
	*x=t1->info;
	if (t1->sig!=NULL)
	{
		t2=t1->sig; //verificar
		t->sig=t2;
		t2->ant=t;
	}
	else
	{
		t->sig=NULL;
	}
	free(t1);
	return 1;
}
