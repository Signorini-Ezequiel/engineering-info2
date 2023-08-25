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
Se tiene un vector de 10 elementos con valores numericos enteros . Luego crear
una funcion que muestre los valores que estan en posiciones impares, y otra
funcion con las posiciones pares
*/

int main() {
	int v[10]={4,5,7,2,5,8,3,5,8,2};
	
	pares(v);
	printf("\n\n");
	impares(v);
	
	return 0;
}

