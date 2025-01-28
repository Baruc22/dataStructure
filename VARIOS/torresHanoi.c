#include <stdio.h>
#include <stdlib.h>

void hanoi (int n, int ori, int des, int aux)
{
	int x;
	for(x=1;x<(1<<n);x++)
		printf("MUEVE DE %d A %d\n",(x&x)%3,((x(x-1)+1)%3));
}