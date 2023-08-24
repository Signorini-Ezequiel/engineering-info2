#include <iostream>
using namespace std;


/*
Desarrolle un programa que declare e inicialice un vector de 5 valores (4.5,8,2.3,1.1,3).
Luego, se pide que calcule y muestre la sumatoria y el promedio. Utilice punteros para
realizar el ejercicio.
*/
int main() {
	float v[5]={4.5, 8, 2.3, 1.1, 3}, *p, total=0;
	p = v;
	total = *p+*(p+1)+*(p+2)+*(p+3)+*(p+4);
	
	printf("La sumatoria de valores da: %f \n", total);
	printf("El promedio de valores da: %f", total/5);
	
	return 0;
}

