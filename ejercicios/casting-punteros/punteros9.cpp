#include <iostream>
using namespace std;

void pares(int *v){
	printf("Pares\n");
	for(int i=0; i<10; i++){
		if(0 != i%2){
			printf("%d ", v[i]);
		}
	}
}

void impares(int *v){
	printf("Impares\n");
	for(int i=0; i<10; i++){
		if(0 == i%2){
			printf("%d ", v[i]);
		}
	}
}

/*
Se tiene un vector de 10 elementos con valores num�ricos enteros . Luego crear
una funci�n que muestre los valores que est�n en posiciones impares, y otra
funci�n con las posiciones pares
*/
int main(int argc, char *argv[]) {
	int v[10]={4,5,7,2,5,8,3,5,8,2};
	
	pares(v);
	printf("\n\n");
	impares(v);
	
	return 0;
}

