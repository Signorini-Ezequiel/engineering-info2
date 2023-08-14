#include <iostream>
using namespace std;

/* PUNTEROS
Escribir un programa que intercambie los valores enteros de a y b utilizando punteros
*/
int main() {
	int a=6, b=15, holder=0, *puna=&a, *punb=&b, *punh=&holder;
	printf("Los valores iniciales de a y b son: %d y %d \n", a, b);
	
	*punh=*puna;
	*puna=*punb;
	*punb=*punh;
	
	printf("Los valores finales de a y b son: %d y %d", a, b);
	return 0;
}

