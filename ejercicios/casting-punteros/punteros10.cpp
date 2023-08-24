#include <iostream>
#include <stdio.h>
using namespace std;

/*
Realice un programa que permita cargar 10 números enteros en un vector.
Luego utilizando punteros calcule el promedio de ellos. Finalmente mostrar
todos los valores y su promedio utilizando punteros.
*/
int main() {
	int v[10]={0}, *p=NULL, total=0;
	p = v;
	
    for(int i=0; i<10; i++){
        printf("Ingrese el valor %d: ", i+1);
        scanf("%d", &v[i]);
    }
    
    total = *p + *(p+1) + *(p+2) + *(p+3) + *(p+4) + *(p+5) + *(p+6) + *(p+7) + *(p+8) + *(p+9);
	
    printf("\n\n");
	
    printf("Los valores son:");
    for(int i=0; i<10; i++){
        printf("%d ", v[i]);
    }
	printf("\n\nEl promedio es: %d", total/5);

	return 0;
}