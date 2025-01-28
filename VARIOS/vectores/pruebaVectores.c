 
#include <stdio.h>
#include "vectores.h"


int main()
{
	float a[3],b[3],ma,mi;
	int opc,i,m;
	printf("\n");
	printf("\tMENU DE OPCIONES\n");

	opc=menu();

	if (opc==1)
	{
	printf("\n");
	printf("\tVECTOR A\n");
	printf("\n");
	for (i=0;i<3;i++)
	{
		if (i==0)
		{
			printf("\tCOMPONENTE X > ");
			scanf("%f",&a[i]);
		}
		if (i==1)
		{
			printf("\tCOMPONENTE Y > ");
			scanf("%f",&a[i]);
		}
		if (i==2)
		{
			printf("\tCOMPONENTE Z > ");
			scanf("%f",&a[i]);
		}
	}
	}
	printf("\n");
	printf("\tVECTOR B\n");
	printf("\n");
	for (i=0;i<3;i++)
	{
		if (i==0)
		{
			printf("\tCOMPONENTE X > ");
			scanf("%f",&b[i]);
		}
		if (i==1)
		{
			printf("\tCOMPONENTE Y > ");
			scanf("%f",&b[i]);
		}
		if (i==2)
		{
			printf("\tCOMPONENTE Z > ");
			scanf("%f",&b[i]);
		}
	}

	printf("\n");
	opc=menu2();
	printf("\n");


 	switch(opc)
	 {
	 	case 1:
	 	{
	 		imprimir(a,b);
	 		break;
	 	}
	 	case 2:
	 	{
	 		suma(a,b);
	 		break;
	 	}
	 	case 3:
	 	{
	 		printf("\t1> MAXIMO DEL VECTOR A.\n");
	 		printf("\t2> MAXIMO DEL VECTOR B.\n");
	 		printf("\n");
	 		printf("\tOPCION >> ");
	 		scanf("%d",&m);
	 		if (m==1)
	 		{
	 			printf("\tRESULTADO >> ");
	 			ma=maximo(a);
	 			printf("%.3f\n",ma);
	 		}
	 		if (m==2)
	 		{
	 			printf("\tRESULTADO >> ");
	 			ma=maximo(b);
	 			printf("%.3f\n",ma);
	 		}
	 		break;
	 	}
	 	case 4:
	 	{
	 		printf("\t1> MINIMO DEL VECTOR A.\n");
	 		printf("\t2> MINIMO DEL VECTOR B.\n");
	 		printf("\n");
	 		printf("\tOPCION >> ");
	 		scanf("%d",&m);
	 		if (m==1)
	 		{
	 			printf("\tRESULTADO >> ");
	 			mi=minimo(a);
	 			printf("%.3f\n",mi);
	 		}
	 		if (m==2)
	 		{
	 			printf("\tRESULTADO >> ");
	 			mi=minimo(b);
	 			printf("%.3f\n",mi);
	 		}
	 		break;
	 	}
	}
return 0;
}
