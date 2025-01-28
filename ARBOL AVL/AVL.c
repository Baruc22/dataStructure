#include <stdio.h>
#include "AVL.h"

int main()
{
	TAVL a;
	int band=1,opc,n,i,x,p,d,h,nn,ni,dato;
	a=Inicializa();

	while(band==1)
	{
		opc=Menu();

		if(opc==1)
		{
			printf("\n\tNUMERO DE DATOS>> ");
			scanf("%d",&n);
			printf("\n");
			for(i=0;i<n;i++)
			{
				printf("\n\tDATO NUMERO %d>> ",i+1);
				scanf("%d",&dato);
				a=Inserta_AVL(a,dato);
			}
		}

		if(opc==2)
		{
			printf("\n");
			PreOrden(a);
		}

		if(opc==3)
		{
			printf("\n\tDATO QUE DESEA ELIMIBAR >> ");
			scanf("%d",&x);
			a=Elimina_Nodo(a,x);
			if(Existe_X(a,x))
			{
				printf("\n\t>>> NO SE PUDO ELIMINAR <<< ");
			}
			else
			{
				printf("\n\t>>> SE ELIMINO EL DATO <<<");
			}
		}

		if(opc==4)
		{
			printf("\n");
			p=Peso(a);
			printf("\tEL PESO DEL ARBOL ES >> %d\n",p);
		}

		if(opc==5)
		{
			printf("\n");
			printf("\n\tDATO QUE DESEA BUSCAR >> ");
			scanf("%d",&d);
			if(Existe_X(a,d))
			{
				printf("\n");
				printf("\tENCONTRO EL DATO >> %d\n",d);
			}
			else
			{
				printf("\n");
				printf("\n\t>>> NO ENCONTRO EL DATO <<<");
			}
		}

		if(opc==6)
		{
			printf("\n");
			h=Hojas(a);
			printf("\tNUMERO DE HOJAS >> %d\n",h);
		}

		if(opc==7)
		{
			printf("\n");
			printf("\n\tNIVEL >> ");
			scanf("%d",&ni);
			nn=Num_Nodos(a,ni);
			printf("\n\tNUMERO DE NODOS >> %d\n",nn);
		}

		if(opc==8)
		{
			band=0;
		}

		printf("\n");
	}
	
	return 0;
}
