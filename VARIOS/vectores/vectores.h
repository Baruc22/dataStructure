
#include <stdio.h>

int menu();
int menu2();
void leer(float a[], float b[]);
void imprimir(float a[], float b[]);
void suma(float a[], float b[]);
float maximo(float a[]);
float minimo(float a[]);

int menu2()
{
	int opc;
	do
	 {
	 	printf("\t1> IMPRIMIR\n");
	 	printf("\t2> SUMA\n");
	 	printf("\t3> MAXIMO\n");
	 	printf("\t4> MINIMO\n");
	 	printf("\n");
	 	printf("\tOPCION > ");
	 	scanf("%d",&opc);
	 } while (opc<1 || opc>4);

 return opc;
}

int menu()
{
	int opc;
	do
	 {
	 	printf("\t1> LEER\n");
	 	printf("\t2> IMPRIMIR\n");
	 	printf("\t3> SUMA\n");
	 	printf("\t4> MAXIMO\n");
	 	printf("\t5> MINIMO\n");
	 	printf("\n");
	 	printf("\tOPCION > ");
	 	scanf("%d",&opc);
	 } while (opc<1 || opc>5);

	 return opc;
}

void leer(float a[], float b[])
{
	int i;
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
}

void imprimir(float a[], float b[])
{
	int i;
	printf("\n");
	printf("\t<< VECTORES >>\n");
	printf("\n");
	printf("\tVECTOR A\n");
	for (i=0;i<3;i++)
	{
		if (i==0)
		{
			printf("\tCOMPONENTE X > ");
			printf("%.3f\n",a[i]);
		}
		if (i==1)
		{
			printf("\tCOMPONENTE Y > ");
			printf("%.3f\n",a[i]);
		}
		if (i==2)
		{
			printf("\tCOMPONENTE Z > ");
			printf("%.3f\n",a[i]);
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
			printf("%.3f\n",b[i]);
		}
		if (i==1)
		{
			printf("\tCOMPONENTE Y > ");
			printf("%.3f\n",b[i]);
		}
		if (i==2)
		{
			printf("\tCOMPONENTE Z > ");
			printf("%.3f\n",b[i]);
		}
	}
}

void suma(float a[], float b[])
{
	int i;
	printf("\n");
	printf("\t<< SUMA >>\n");
	printf("\n");
	printf("\tVECTOR C=\n");
	printf("\n");
	for (i=0;i<3;i++)
	{
		if (i==0)
		{
			printf("\tCOMPONENTE X DEL VECTOR RESULTANTE > ");
			printf("%.3f\n",a[i]+b[i]);
		}
		if (i==1)
		{
			printf("\tCOMPONENTE Y DEL VECTOR RESULTANTE > ");
			printf("%.3f\n",a[i]+b[i]);
		}
		if (i==2)
		{
			printf("\tCOMPONENTE Z DEL VECTOR RESULTANTE > ");
			printf("%.3f\n",a[i]+b[i]);
		}
	}
}

float maximo(float a[])
{
	int i,j;
	float x=0;
	for (i=0,j=1;i<3,j<=2;i++,j++)
	{
		if (a[i]>a[j])
		{
			if(x<a[j])
			{
				x=a[i];
			}
		}
		if (x<a[j])
		{
			x=a[j];
		}
	}

	return x;
}

float minimo(float a[])
{
	int i,j;
	float x=0;
	for (i=0,j=1;i<3,j<=2;i++,j++)
	{
		if (a[i]<a[j])
		{
			if(x>=a[j])
			{
				x=a[i];
			}
		}
		if (x>a[j])
		{
			x=a[j];
		}
	}

	return x;
}
