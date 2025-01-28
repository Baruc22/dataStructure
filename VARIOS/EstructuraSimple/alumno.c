
#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"

int main()
{
	ALUMNO alum[42]={0};
	ALUMNO b={"","","","",0,0};
	ALUMNO x,a;
	int clave,i,opc0=1,opc=0,bo=1;

	for(;opc!=5;)
	{
		opc=menu();
	if (opc==1)
	{
		for (i=0;i<40,opc0==1;i++)
		{
			printf("\n");
			printf("\tCLAVE >> ");
			scanf("%d",&clave);
			printf("\n");

			if (clave<40)
			{
				x=leeralum(a,clave);
				alum[clave-1]=x;
				
				printf("\n");
				printf("\t1> SEGUIR LEYENDO\n");
	   			printf("\t2> DEJAR DE LEER\n");
	   			printf("\n");
	    		printf("\tOPCION > ");
	    		scanf("%d",&opc0);
			}
			else
			{
				printf("\n");
				printf("\tLA CLAVE NO ESTA DENTRO DEL RANGO DE ALUMNOS\n");
				printf("\n");
				printf("\t\tVERIFIQUE\n");
			}
		}
	}

	if (opc==2)
	{
		printf("\n");
		printf("\tCLAVE >> ");
		scanf("%d",&clave);
		printf("\n");	

		imprimirporclave(alum,clave-1);
	}

	if (opc==3)
	{
		imprimirtodo(alum);
	}
	else if (opc==5)
	{
		return 0;
	}

	if(opc==4)
	{
		for (i=0;i<40,bo==1;i++)
		{
			printf("\n");
			printf("\tCLAVE >> ");
			scanf("%d",&clave);
			printf("\n");

			if (clave<40)
			{
				alum[clave-1]=b;
				bo=2;
			}
			else
			{
				printf("\tLA CLAVE NO ESTA DENTRO DEL RANGO DE ALUMNOS O NO EXISTE UN ALUMNO CON ESA CLAVE\n");
				printf("\n");
				printf("\t\tVERIFIQUE\n");
			}
		}
	}
	}
	return 0;
}
