#include <stdio.h>
#include "ListaL.h"
int main ()
{
	TListas ll;
	char letra;
	char nom[15],nome[15];
	ll=inicializa();
	int band=1,opc;

	do
	{
		opc=Menu();

		switch(opc)
		{
			case 1:
			{
				printf("\n\t ***** INSERTAR *****\n");
				printf("\n\tNombre >> ");
				scanf("%s",nom);
				printf("\n\tPrimera Letra >> ");
				scanf("%c",letra);
				if(Inserta(&ll,letra,nom))
				{
					printf("\n\tSE INSERTO");
				}
				else
				{
					printf("\n\tNO SE PUDO INSERTAR");
				}
				break;
			}
			case 2:
			{
				printf("\n\t XXXXX ELIMINAR XXXXXX\n");
				printf("\n\tNombre >> ");
				scnaf("%s",nome);
				ll=Eliminar(&ll,nome);
				break;
			}
			case 3:
			{
				printf("\n\t ///// IMPRIMIR ////\n");
				printf("\n\tDatos >> ");
				printf("\n\t");
				Imprime(ll);
			}
			case 4:
			{
				band=0;
				break;
			}
		}
	}while(band!=1);

	return 0;

}