#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int x,y;
	char cad[100];
	FILE *f;
	f=fopen ("archivo.txt","r");
	if (f==NULL)
	{
		printf ("no se pudo leer el archivo");
		return 0;
	}
	fgets (cad,100,f);
	fscanf (f,"%d %d",&x,&y);

	printf("***%s***\n",cad );
	printf("%d %d\n",x,y );
	
	return 0;
}
