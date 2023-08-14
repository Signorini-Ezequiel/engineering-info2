#include <iostream>
using namespace std;

/* CASTEO
Cargar las 3 notas de un alumno como valores enteros. Luego mostrar el promedio
teniendo en cuenta si tiene parte decimal.*/
int main() {
	int n1=0, n2=0, n3=0;
	scanf("%d", &n1);
	scanf("%d", &n2);
	scanf("%d", &n3);
	
	float resultado = (float)(n1+n2+n3)/3;
	
	printf("El promedio de notas es: %.2 f", resultado);
	return 0;
}

