#include <stdio.h>

void menu ()
{
	printf ("1) Dar de alta un alumno\n");
	printf ("2) Mostrar alumno por matricula\n");
	printf ("3) Eliminar un alumno por matricula\n");
	printf ("4) Modificar un alumno por matricula\n");
	printf ("5) Mostrar todos los alumnos\n");
	printf ("6) Salir\n");
}

int dameop ()
{
	int opc;
	do 
	{
		menu ();
		scanf ("%d", &opc);
	} while (opc<1 || opc>6 );
	return opc;
}

int main ()
{
	int opc;
	opc=dameop ();	
	printf ("%d",opc);
}
