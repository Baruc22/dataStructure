#include <stdio.h>
#include "Hash.h"
int main()
{
	TLista Tabla[500];
	int band=0,opc,n;
	char verbo[15],es[15],in[15],pa[15],par[15];
	Inicializa(Tabla);

	insertaEs(Tabla,500,"comer","eat","ate","eaten"); //1
	insertaIn(Tabla,500,"comer","eat","ate","eaten");
	insertaPa(Tabla,500,"comer","eat","ate","eaten");
	insertaPar(Tabla,500,"comer","eat","ate","eaten");

	insertaEs(Tabla,500,"jugar","play","played","played"); //2
	insertaIn(Tabla,500,"jugar","play","played","played");
	insertaPa(Tabla,500,"jugar","play","played","played");
	insertaPar(Tabla,500,"jugar","play","played","played");

	insertaEs(Tabla,500,"bailar","dance","danced","danced"); //3
	insertaIn(Tabla,500,"bailar","dance","danced","danced");
	insertaPa(Tabla,500,"bailar","dance","danced","danced");
	insertaPar(Tabla,500,"bailar","dance","danced","danced");
	
	insertaEs(Tabla,500,"hablar","speak","spoke","spoken"); //4
	insertaIn(Tabla,500,"hablar","speak","spoke","spoken");
	insertaPa(Tabla,500,"hablar","speak","spoke","spoken");
	insertaPar(Tabla,500,"hablar","speak","spoke","spoken");

	insertaEs(Tabla,500,"hacer","do","did","done"); //5
	insertaIn(Tabla,500,"hacer","do","did","done");
	insertaPa(Tabla,500,"hacer","do","did","done");
	insertaPar(Tabla,500,"hacer","do","did","done");

	insertaEs(Tabla,500,"correr","run","ran","run"); //6
	insertaIn(Tabla,500,"correr","run","ran","run");
	insertaPa(Tabla,500,"correr","run","ran","run");
	insertaPar(Tabla,500,"correr","run","ran","run");

	insertaEs(Tabla,500,"caminar","walk","walked","walked"); //7
	insertaIn(Tabla,500,"caminar","walk","walked","walked");
	insertaPa(Tabla,500,"caminar","walk","walked","walked");
	insertaPar(Tabla,500,"caminar","walk","walked","walked");

	insertaEs(Tabla,500,"llamar","call","called","called"); //8
	insertaIn(Tabla,500,"llamar","call","called","called");
	insertaPa(Tabla,500,"llamar","call","called","called");
	insertaPar(Tabla,500,"llamar","call","called","called");

	insertaEs(Tabla,500,"dormir","sleep","slept","slept"); //9
	insertaIn(Tabla,500,"dormir","sleep","slept","slept");
	insertaPa(Tabla,500,"dormir","sleep","slept","slept");
	insertaPar(Tabla,500,"dormir","sleep","slept","slept");

	insertaEs(Tabla,500,"ir","go","went","gone"); //10
	insertaIn(Tabla,500,"ir","go","went","gone");
	insertaPa(Tabla,500,"ir","go","went","gone");
	insertaPar(Tabla,500,"ir","go","went","gone");

	insertaEs(Tabla,500,"tener","have","had","had"); //11
	insertaIn(Tabla,500,"tener","have","had","had");
	insertaPa(Tabla,500,"tener","have","had","had");
	insertaPar(Tabla,500,"tener","have","had","had");
	
	insertaEs(Tabla,500,"ayudar","help","helped","helped"); //12
	insertaIn(Tabla,500,"ayudar","help","helped","helped");
	insertaPa(Tabla,500,"ayudar","help","helped","helped");
	insertaPar(Tabla,500,"ayudar","help","helped","helped");

	insertaEs(Tabla,500,"estudiar","study","studied","studied"); //13
	insertaIn(Tabla,500,"estudiar","study","studied","studied");
	insertaPa(Tabla,500,"estudiar","study","studied","studied");
	insertaPar(Tabla,500,"estudiar","study","studied","studied");

	insertaEs(Tabla,500,"escuchar","listen","listened","listened"); //14
	insertaIn(Tabla,500,"escuchar","listen","listened","listened");
	insertaPa(Tabla,500,"escuchar","listen","listened","listened");
	insertaPar(Tabla,500,"escuchar","listen","listened","listened");

	insertaEs(Tabla,500,"leer","read","read","read"); //15
	insertaIn(Tabla,500,"leer","read","read","read");
	insertaPa(Tabla,500,"leer","read","read","read");
	insertaPar(Tabla,500,"leer","read","read","read");

	insertaEs(Tabla,500,"escribir","write","wrote","written"); //16
	insertaIn(Tabla,500,"escribir","write","wrote","written");
	insertaPa(Tabla,500,"escribir","write","wrote","written");
	insertaPar(Tabla,500,"escribir","write","wrote","written");

	insertaEs(Tabla,500,"dibujar","draw","drew","drawn"); //17
	insertaIn(Tabla,500,"dibujar","draw","drew","drawn");
	insertaPa(Tabla,500,"dibujar","draw","drew","drawn");
	insertaPar(Tabla,500,"dibujar","draw","drew","drawn"); 	

	insertaEs(Tabla,500,"amar","love","loved","loved"); //18
	insertaIn(Tabla,500,"amar","love","loved","loved");
	insertaPa(Tabla,500,"amar","love","loved","loved");
	insertaPar(Tabla,500,"amar","love","loved","loved");

	insertaEs(Tabla,500,"cantar","sing","sang","sung"); //19
	insertaIn(Tabla,500,"cantar","sing","sang","sung");
	insertaPa(Tabla,500,"cantar","sing","sang","sung");
	insertaPar(Tabla,500,"cantar","sing","sang","sung");

	insertaEs(Tabla,500,"cocinar","cook","cooked","cooked"); //20
	insertaIn(Tabla,500,"cocinar","cook","cooked","cooked");
	insertaPa(Tabla,500,"cocinar","cook","cooked","cooked");
	insertaPar(Tabla,500,"cocinar","cook","cooked","cooked");

	printf("\n\t**DICCIONARIO ESPANOL-INGLES**\n");
	
	while(band==0)
	{
		printf("\n************************************************\n");
		printf("\n\tElija la accion que desea realizar\n");
		printf("\n\t1.- CONSULTAR\n");
		printf("\n\t2.- ELIMINAR\n");
		printf("\n\t3.- AGREGAR\n");
		printf("\n\t4.-SALIR\n");
		printf("\n\tOPCION >> " );
		scanf("%d",&opc);
		printf("\n************************************************\n");

		if (opc==1)
		{
			printf("\n\tVERBO >> ");
			scanf("%s",verbo);
			n=Fhash(verbo,500);
			if(Tabla[n]==NULL)
			{
				printf("\n\t*** >> NO EXISTE << *** \n");
			}
			else
			{
				Buscar(Tabla,n);
				printf("\n");
			}

		}

		if (opc==2)
		{
			printf("\n\tESCRIBA EL VERBO EN ESPANOL\n");
			printf("\n\tVERBO >> ");
			scanf("%s",verbo);
			n=Fhash(verbo,500);
			if(Tabla[n]==NULL)
			{
				printf("\n\t*** >> NO EXISTE << *** \n");
			}
			else
			{
				Elimina(Tabla,500,verbo);
				printf("\n");
			}

		}

		if (opc==3)
		{
			printf("\n\t***VERBO PARA AGREGAR***\n");
			printf("\n\tVERBO EN ESPANOL >> ");
			scanf("%s",es);
			printf("\n\tVERBO EN INFINITIVO >> ");
			scanf("%s",in);
			printf("\n\tVERBO EN PASADO >> ");
			scanf("%s",pa);
			printf("\n\tVERBO EN PARTICIPIO >> ");
			scanf("%s",par);
			n=Fhash(es,500);
			if(Tabla[n]==NULL)
			{
				insertaEs(Tabla,500,es,in,pa,par);
				insertaIn(Tabla,500,es,in,pa,par);
				insertaPa(Tabla,500,es,in,pa,par);
				insertaPar(Tabla,500,es,in,pa,par);
			}
			else
			{
				printf("\n\t>> NO SE PUDO INSERTAR <<\n");
			}
		}

		if (opc==4)
		{
			band=17;
		}

	}

	return 0;
}
