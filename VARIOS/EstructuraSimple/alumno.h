
#include <stdio.h>
#include <stdlib.h>

typedef struct alumno
{
	char nombre[20];
	char apellidop[20];
	char apellidom[20];
	char maricula[15];
	int edad;
	float beca;
} ALUMNO;

ALUMNO leeralum (ALUMNO a, int clave);
int menu();
void imprimirporclave(ALUMNO alum[], int clave);
void imprimirtodo(ALUMNO alum[]);

int menu()
{
	int opc;
	do
	{
		printf("\n");
		printf("\t1> INSERTAR ALUMNO\n");
		printf("\t2> IMPRIMIR POR CLAVE\n");
		printf("\t3> IMPRIMIR TODO\n");
		printf("\t4> BORRAR POR CLAVE\n");
		printf("\t5> SALIR\n");
		printf("\n");
		printf("\tOPCION > ");
		scanf("%d",&opc);
	} while(opc<1 || opc>5);	

	return opc;
}

ALUMNO leeralum (ALUMNO a, int clave)
{
	printf("\tCLAVE > %d\n",clave);
	printf("\tNOMBRE > ");
	scanf("%s",a.nombre);
	printf("\tAPELLIDO PATERNO > ");
	scanf("%s",a.apellidop);
	printf("\tAPELLIDO MATERNO > ");
	scanf("%s",a.apellidom);
	printf("\tMATRICULA > ");
	scanf("%s",a.maricula);
	printf("\tEDAD > ");
	scanf("%d",&a.edad);
	printf("\tBECA > ");
	scanf("%f",&a.beca);

	return a;
}

void imprimirporclave (ALUMNO alum[], int clave)
{
	printf("\tCLAVE > %d\n",clave);
	printf("\tNOMBRE > %s\n",alum[clave].nombre);
	printf("\tAPELLIDO PATERNO > %s\n",alum[clave].apellidop);
	printf("\tAPELLIDO MATERNO > %s\n",alum[clave].apellidom);
	printf("\tMATRICULA > %s\n",alum[clave].maricula);
	printf("\tEDAD > %d\n",alum[clave].edad);
	printf("\tBECA > %.3f\n",alum[clave].beca);
	printf("\n");
}

void imprimirtodo (ALUMNO alum[])
{
	int i;
	for(i=0;i<40;i++)
	{
		if (alum[i].edad!=0)
		{
			printf("\n");
			printf("\tCLAVE %d\n> ",i+1);
			printf("\tNOMBRE > %s\n",alum[i].nombre);
			printf("\tAPELLIDO PATERNO > %s\n",alum[i].apellidop);
			printf("\tAPELLIDO MATERNO > %s\n",alum[i].apellidom);
			printf("\tMATRICULA > %s\n",alum[i].maricula);
			printf("\tEDAD > %d\n",alum[i].edad);
			printf("\tBECA > %.3f\n",alum[i].beca);
			printf("\n");
		}
	}
}
