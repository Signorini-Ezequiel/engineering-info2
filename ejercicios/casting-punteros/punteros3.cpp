#include <iostream>
using namespace std;

/* PUNTEROS
Escribir un programa que declare una variable llamada a, un puntero del tipo de la variable creada,
inicialice la variable e inicialice el puntero para que apunte a la variable creada. Luego que imprima
por pantalla: la direccion de memoria de la variable, el valor que almacena la variable, el valor
del puntero y el valor al que apunta el puntero.
*/
int main() {
	int a=15, *puntero=0;
	puntero=&a;
	
	printf("variable \n");
	printf("La direccion de memoria de a es: %d \nsu valor es: %d", &a, a);
	
	printf("\npuntero \n");
	printf("La direccion de memoria del puntero es: %d \nsu valor es: %d", puntero, *puntero);
	return 0;
}

