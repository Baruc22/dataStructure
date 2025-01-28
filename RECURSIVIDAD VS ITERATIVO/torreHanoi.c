//Hanoi iterativo
#include<stdio.h>
#include "pilah.h"
void hanoi(int n,int ori,int des,int aux)
{
	Tpila p;
	int b=1, t;
	p=inicializapila();
	while(n>0 && b==1)
	{
		while(n>1)
		{
			push(&p,n,ori,des,aux);
			n--;
			t=des;
			des=aux;
			aux=t;
		}
		printf("\n\tMueve de %d a %d\n",ori,des);
		b=0;
		if(!pilavacia(p))
		{
			pop(&p,&n,&ori,&des,&aux);
			printf("\n\tMueve de %d a %d\n",ori,des);
			n--;
			t=ori;
			ori=aux;
			aux=t;
			b=t;
		}

	}
}
int main()
{
	int n;
	printf("\n\tNUMERO DE DISCOS>> ");
	scanf("%d",&n);
	hanoi(n,1,3,2);
	return 0;
}
