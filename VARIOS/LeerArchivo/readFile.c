#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int x,y;
	char cad[20];
	FILE *f;
	f=fopen("archivo.txt","r");
	if(f==NULL)
	{
		printf("\n\tNo se pudo leer el archivo\n");
		return 0;
	}
	fgets(cad,50,f);
	printf("\n\t%s\n",cad);
	fscanf(f,"%d %d",&x,&y);
	printf("\n\t%d %d\n",x,y);
}