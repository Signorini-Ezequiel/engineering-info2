#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;

// Funciones
void mostrar(int [][3], int);

/*
Desarrolle un programa que declare e inicialice un arreglo de 2x3 con valores aleatorios.
Luego mostrar los valores. Utilice punteros para realizar el ejercicio
*/
int main() {
	srand(time(NULL));

	int m[2][3] = {0};
	
	for(int i=0; i<2; i++){
		for(int j=0; j<3; j++){
			m[i][j] = rand()% 9;
		}
	}

	mostrar(m, 2);

	return 0;
}

void mostrar(int m[][3], int row){
	for(int i=0; i<row; i++){
		for(int j=0; j<3; j++){
			printf("%d ", m[i][j]);
		}
	}
}