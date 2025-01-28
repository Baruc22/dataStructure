#include <stdio.h>
#include <stdlib.h>
#include "STRUCTFUN.h"

int main()
{
	int opc,opc2,opc3;
	long int cod,Prof,i;
	REGISTRO reg,reg2;
	NODOPTR Dato,H;

	FILE *f;
	ARBOL A; /*DECLARACION DE LA VARIBLE PARA EL ARBOL BINARIO*/
	NODOPTR ColaP;/*DECLARACION DE LA VARIEBLE PARA LA COLA DE PRIORIDAD*/
	NODOPTR Tabla[TAM_TABLA];/*DECLARACION DEL ARREGLO PARA LA TABLA HASH*/
	Inicializa_Cola(&ColaP);/*INICIALIZA COLA DE PRIORIDAD*/
	Inicializa_Tabla(Tabla);/*INICIALIZA LA TABLA HASH*/
	Inicializa_Arbol(&A);/*INICIALIZA EL ARBOL*/

	f=fopen("pacientes.txt","r");

	while(fscanf(f,"%ld",&cod)!=EOF)/*LECTURA DEL ARCHIVO EN TODAS LAS ESTRUCTURAS*/
	{
		fscanf(f,"%s",&reg.nombre);
		fscanf(f,"%d",&reg.edad);
		fscanf(f,"%s",&reg.sexo);
		fscanf(f,"%s",&reg.enfermedad);
		fscanf(f,"%s",&reg.nacionalidad);

		Cola_Prioridad(&ColaP,cod,reg);
		Encadenamiento(Tabla,cod,reg);
		if(A==NULL)
			A=crearArbol(cod,reg);
		else
			insertarArbolBin(A,cod,reg);
	}
	
	fclose(f);

	do/*INICIO DE LAS ACCIONES DESEADAS PARA LAS TRES ESTRCUTURAS*/
	{
		opc=Menu();

		if(opc==1)
			Imp_Cola(ColaP);
		if(opc==2)
			Imprime_Hash(Tabla);

		switch(opc)
		{
			case 1:/*COLA DE PRIORIDAD LINEAL*/
			{
				do
				{
					opc2=Submenu();
					switch(opc2)
					{
						case 1:/*IMPRIME LA INFORMACION*/
						{
							Imp_Cola(ColaP);
							break;
						}
						case 2:/*BUSCA POR CLAVE*/
						{
							printf("\n\tCLAVE >> ");
							scanf("%ld",&cod);

							Dato=Buscar(ColaP,cod);

							if(Dato!=NULL)
							{
								printf("\n\t >>> PACIENTE ENCONTRADO <<<\n");
								Elimina(&ColaP,Dato);/*ELIMINA EL DATO SI ES ENCONTRADA LA CLAVE*/
							}
							else
							{
								printf("\n\t**********************************\n");
								printf("\t>>> NO SE ENCONTRO EL PACIENTE <<<\n");
								printf("\t**********************************\n");

								opc3=Menu2();

								if(opc3==1)/*INSERTA SI NO SE ENCONTRO LA CLAVE*/
								{
									printf("\n\tINGRESE LOS DATOS DEL PACIENTE\n\n");
									reg=Leer();

									Cola_Prioridad(&ColaP,cod,reg);
									
									printf("\n\t************************************\n");
									printf("\t>>> SE INSERTO UN NUEVO PACIENTE <<<\n");
									printf("\t************************************\n");
								}
							}

							break;
						}
					}
				}while(opc2!=3);/*FIN DE LAS ACCIONES DE LA COLA DE PRIORIDAD*/
				break;
			}

			case 2:/*TABLA HASH*/
			{
				do
				{
					opc2=Submenu();
					switch(opc2)
					{
						case 1:/*MOSTRAR INFORMACION*/
						{
							Imprime_Hash(Tabla);
							break;
						}
						case 2:/*BUSCA POR CLAVE*/
						{
							reg2.edad=0;
							printf("\n\tCLAVE >> ");
							scanf("%ld",&cod);
							H=Encadenamiento(Tabla,cod,reg2);
							if(H!=NULL)
							{
								printf("\n\t >>> PACIENTE ENCONTRADO <<<\n\n");
								printf("\tCLAVE >> %ld\n",H->clave);
								printf("\tNOMBRE >> %s\n",H->info.nombre);
								printf("\tEDAD >> %d\n",H->info.edad);
								printf("\tSEXO >> %s\n",H->info.sexo);
								printf("\tENFERMEDAD >> %s\n",H->info.enfermedad);
								printf("\tNACIONALIDAD >> %s\n",H->info.nacionalidad);

								Elimina_HASH(Tabla,H);/*ELIMINA EN CASO DE SER ENCONTRADA LA CLAVE*/
							}
							else
							{
								printf("\n\t**********************************\n");
								printf("\t>>> NO SE ENCONTRO EL PACIENTE <<<\n");
								printf("\t**********************************\n");

								opc3=Menu2();

								if(opc3==1)/*INSERTA SI NO FUE ENCONTRADA LA CLAVE*/
								{
									printf("\n\tINGRESE LOS DATOS DEL PACIENTE\n\n");
									reg2=Leer();
									Encadenamiento(Tabla,cod,reg2);
								
									printf("\n\t************************************\n");
									printf("\t>>> SE INSERTO UN NUEVO PACIENTE <<<\n");
									printf("\t************************************\n");
								}
							}

							break;
						}
					}

				}while(opc2!=3);
				break;/*FIN DE LAS ACCIONES DE LA TABLA HASH*/
			}

			case 3:/*ARBOL BINARIO*/
			{
				do
				{
					opc2=Submenu();
					switch(opc2)
					{

						case 1:/*IMPRIME LAS CLAVES USANDO LOS TRES TIPOS DE RECORRIDOS*/
						{
							printf("\n\tIMPRESION EN PRE-ORDEN DE LAS LLAVES \n\n");
							RecorrePre_Orden(A);
							printf("\n\n");
							printf("\n\tIMPRESION EN ORDEN DE LAS LLAVES  \n\n");
							Recorre_Orden(A);
							printf("\n\n");
							printf("\n\tIMPRESION EN POS-ORDEN DE LAS LLAVES \n\n");
							RecorrePos_Orden(A);
							printf("\n\n");
							break;
						}
						case 2:
						{
							printf("\n\tCLAVE >> ");
							scanf("%ld",&cod);
							busArbolBin(A,cod);/*BUSCA E INSERTA EN CASO DE NO ENCONTRAR LA CLAVE*/
							break;
						}
					}
				}while(opc2!=3);

				break;//FIN DE LAS ACCIONES DEL ARBOL BINARIO
			}

			case 4:/*SALIR Y LIBERAR TODO*/
			{
				Liberar_Col(&ColaP);
				Libera_HASH(Tabla);

				Prof=Profundidad_Arb(A);
				for(i=1;i<Prof;i++)
					Podar_Arb(A);
				free(A);
				A=NULL;
				break;
			}
		}
	}while(opc!=4);
	return 0;
}
