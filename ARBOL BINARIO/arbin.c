#include <stdio.h>
#include "arbin.h"

int main()
{
	TArbin a;
	int band=1,x,opc,opc2;
	a=Inicializa_Arbin();

	while(band==1)
	{
		opc=Menu();

		if(opc==1)
		{
			printf("\n");
			printf("\n\t >>>INSERTAR<<<");
			printf("\n");
			printf("\n\t DATO >> ");
			scanf("%d",&x);

			Inserta_Arbin(&a,x);

			printf("\n");
			printf("\n\tDESEA SEGUIR");
			printf("\n");
			printf("\n\tSi > 1 <    No > 0 < ");
			printf("\n");
			printf("\n\tOPCION >> ");
			scanf("%d",&opc2);

			if(opc2==0)
			{
				band=0;
			}
		}

		if(opc==2)
		{
			printf("\n");
			printf("\n\t>>>ELIMINAR<<\n");
			printf("\n");
			printf("\n\tDATO A ELIMINAR >> ");
			scanf("%d",&x);
			a=EliminarA(a,x);

			printf("\n");
			printf("\n\tDESEA SEGUIR");
			printf("\n");
			printf("\n\tSi > 1 <    No > 0 < ");
			printf("\n");
			printf("\n\tOPCION >> ");
			scanf("%d",&opc2);

			if(opc2==0)
			{
				band=0;
			}
		}

		if(opc==3)
		{
			printf("\n");
			printf("\n\tDATOS DEL ARBOL\n");
			printf("\n");
			if(a!=NULL)
			{
				PreOrden(a);
			}
			else
			{
				printf("\n\t ++++++++++++++++");
				printf("\n\t + NO HAY DATOS +");
				printf("\n\t ++++++++++++++++");
			}

			printf("\n");
			printf("\n\tDESEA SEGUIR");
			printf("\n");
			printf("\n\tSi > 1 <    No > 0 < ");
			printf("\n");
			printf("\n\tOPCION >> ");
			scanf("%d",&opc2);

			if(opc2==0)
			{
				band=0;
			}
		}

		if(opc==4)
		{
			printf("\n");
			printf("\n\tPESO\n");
			printf("\n");

			printf("\t%d\n",Peso(a));

			printf("\n");
			printf("\n\tDESEA SEGUIR");
			printf("\n");
			printf("\n\tSi > 1 <    No > 0 < ");
			printf("\n");
			printf("\n\tOPCION >> ");
			scanf("%d",&opc2);

			if(opc2==0)
			{
				band=0;
			}
		
		}

		if(opc==5)
		{
			printf("\n");
			printf("\n\tBUSCAR EL ELEMENTO\n");
			printf("\n");
			printf("\n\tELEMENTO A BUSCAR >> ");
			scanf("%d",&x);

			if(Existe_X(a,x))
			{
				printf("\n\t* SE ENCONTRO EL ELEMENTO *\n");
			}
			else
			{
				printf("\n\t* NO SE ENCONTRO EL ELEMENTO *\n");
			}

			printf("\n");
			printf("\n\tDESEA SEGUIR");
			printf("\n");
			printf("\n\tSi > 1 <    No > 0 < ");
			printf("\n");
			printf("\n\tOPCION >> ");
			scanf("%d",&opc2);

			if(opc2==0)
			{
				band=0;
			}
		}

		if(opc==6)
		{
			printf("\n");
			printf("\n\tNUMERO DE HOJAS\n");
			printf("\n");
			printf("\t%d\n",Hojas(a));

			printf("\n");
			printf("\n\tDESEA SEGUIR");
			printf("\n");
			printf("\n\tSi > 1 <    No > 0 < ");
			printf("\n");
			printf("\n\tOPCION >> ");
			scanf("%d",&opc2);

			if(opc2==0)
			{
				band=0;
			}
		}

		if(opc==7)
		{
			printf("\n");
			printf("\n\tNUMERO DE HOJAS EN EL NIVEL QUE DESEA\n");
			printf("\n");
			printf("\n\tNIVEL NUMERO >> ");
			scanf("%d",&x);

			printf("\n");
			printf("\t%d\n",Num_Nodos(a,x));

			printf("\n");
			printf("\n\tDESEA SEGUIR");
			printf("\n");
			printf("\n\tSi > 1 <    No > 0 < ");
			printf("\n");
			printf("\n\tOPCION >> ");
			scanf("%d",&opc2);

			if(opc2==0)
			{
				band=0;
			}
		}

		if(opc==8)
		{
			printf("\n");
			printf("\n\tALTURA\n");
			printf("\n");
			printf("\t%d\n",Altura(a));

			printf("\n");
			printf("\n\tDESEA SEGUIR");
			printf("\n");
			printf("\n\tSi > 1 <    No > 0 < ");
			printf("\n");
			printf("\n\tOPCION >> ");
			scanf("%d",&opc2);

			if(opc2==0)
			{
				band=0;
			}
		}

		if(opc==9)
		{
			printf("\n");
			printf("\n\tPODAR\n");
			printf("\n");
			PodarA(&a);
			printf("\n\t****************");
			printf("\n\t* ARBOL PODADO *");
			printf("\n\t****************");

			printf("\n");
			printf("\n\tDESEA SEGUIR");
			printf("\n");
			printf("\n\tSi > 1 <    No > 0 < ");
			printf("\n");
			printf("\n\tOPCION >> ");
			scanf("%d",&opc2);

			if(opc2==0)
			{
				band=0;
			}
		}

		if(opc==10)
		{
			band=0;
		}

	}

}
