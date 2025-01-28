#include "ColaPrioridad.h"
#define tam 5
main(){
	TColaP q;
	int i=0, prio;
	Tipo x;
	inicializa(&q);
	for(;i<tam;i++){
		printf("\nIngresa la info (int): ");
		scanf("%d", &x);
		printf("\nIngrese la preoridad: ");
		scanf("%d", &prio);
		insertar(&q, x, prio);
	}
	printf("\n\nImprimiendo la cola: \n");
	while(!colavacia(q)){
		eliminar(&q, &x);
		printf("%d\n", x);
	}
	
}
