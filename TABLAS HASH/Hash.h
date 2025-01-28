#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodo
{
	char infinitivo[15];
	char pasado[15];
	char pasadop[15];
	char espanol[15];
	struct nodo *sig;
};

typedef struct nodo TNodo;
typedef struct nodo *TLista;

int Fhash(char *s, int sizeHash)//Funcion hash que devuelve un numero que buscara en el arreglo o tabla de datos.
{
	int i, suma=0;
	for(i=0;s[i]!='\0';i++)
	{
		suma+=s[i]*i;
	}

	return suma%sizeHash;
}

void Buscar(TLista tabla[], int hash)
{
	printf("\n************************************************\n");
	printf("\n\t*****CONSULTA*****\n");
	printf("\n\tESPANOL >> %s\n",tabla[hash]->espanol);
	printf("\n\tINFINITIVO >> %s\n",tabla[hash]->infinitivo);
	printf("\n\tPASADO >> %s\n",tabla[hash]->pasado);
	printf("\n\tPARTICIPIO >> %s\n",tabla[hash]->pasadop);
	printf("\n************************************************\n");
}

TLista Crea_Nodo (char *s1, char *s2, char *s3, char *s4)
{
	TLista t;
	t=(TLista)malloc(sizeof(TNodo));
	if (t!=NULL)
	{
		strcpy(t->espanol,s1);
		strcpy(t->infinitivo,s2);
		strcpy(t->pasado,s3);
		strcpy(t->pasadop,s4);
		t->sig=NULL;
	}
	return t;
}

int insertaEs(TLista tabla[], int sizeHash, char *s1, char *s2, char *s3, char *s4)
{
	TLista nuevo;
	int posicion;
	nuevo=Crea_Nodo(s1,s2,s3,s4);
	if (nuevo==NULL) return 0;
	posicion=Fhash(s1,sizeHash);
	nuevo->sig=tabla[posicion]; // definir tabla;
	tabla[posicion]=nuevo;
	return 1;
}

int insertaIn(TLista tabla[], int sizeHash, char *s1, char *s2, char *s3, char *s4)
{
	TLista nuevo;
	int posicion;
	nuevo=Crea_Nodo(s1,s2,s3,s4);
	if (nuevo==NULL) return 0;
	posicion=Fhash(s2,sizeHash);
	nuevo->sig=tabla[posicion]; // definir tabla;
	tabla[posicion]=nuevo;
	return 1;
}

int insertaPa(TLista tabla[], int sizeHash, char *s1, char *s2, char *s3, char *s4)
{
	TLista nuevo;
	int posicion;
	nuevo=Crea_Nodo(s1,s2,s3,s4);
	if (nuevo==NULL) return 0;
	posicion=Fhash(s3,sizeHash);
	nuevo->sig=tabla[posicion]; // definir tabla;
	tabla[posicion]=nuevo;
	return 1;
}

int insertaPar(TLista tabla[], int sizeHash, char *s1, char *s2, char *s3, char *s4)
{
	TLista nuevo;
	int posicion;
	nuevo=Crea_Nodo(s1,s2,s3,s4);
	if (nuevo==NULL) return 0;
	posicion=Fhash(s4,sizeHash);
	nuevo->sig=tabla[posicion]; // definir tabla;
	tabla[posicion]=nuevo;
	return 1;
}

void Inicializa(TLista tabla[])// debe inicializar todos los elementos de la tabla en NULL;
{
	int i;
	for (i=0;i<500;i++)
	{
		tabla[i]=NULL;
	}
}	

int Elimina(TLista Tabla[], int sizeHash, char *espanol)
{
	int posicion;
	TLista ant, t;
	posicion=Fhash(espanol,sizeHash);
	t=ant=Tabla[posicion];
	while(t!=NULL && strcmp(espanol,t->espanol)!=0)
	{
		ant=t;
		t=t->sig;
	}
	if (t==NULL) return 0;
	if(t==Tabla[posicion]) Tabla[posicion]=t->sig;
	else
	{
		ant->sig=t->sig;
		Tabla[posicion]=NULL;
		free(t);
		return 1;
	}
}
