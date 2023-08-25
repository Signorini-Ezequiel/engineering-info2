#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;

// Funciones
void calc_max(int [], int, int *);
void calc_min(int [], int, int *);
void calc_total(int [], int, int *);

/*
Desarrolle un programa que declare e inicialice un vector de 5 valores aleatorios.
Luego, crear 3 funciones que permitan hallar el valor máximo, mínimo y la sumatoria
de ellos. Finalmente mostrar los resultados. Utilice punteros para realizar el ejercicio.
*/
int main() {
	srand(time(NULL));

	int v[5] = {0}, max = 0, min = 0, total = 0;

	for(int i=0; i<5; i++){
		if(0 == i){
			max = v[i];
			min = v[i];
		}
		v[i] = rand()% 5;
	}

	calc_max(v, 5, &max);
	calc_min(v, 5, &min);
	calc_total(v, 5, &total);

	printf("El valor maximo es: %d, el valor minimo es: %d, el total es: %d", max, min, total);

	return 0;
}

void calc_max(int v[], int n, int *p){
	for(int i=0; i<n; i++){
		if(*p < v[i]){
			*p = v[i];
		}
	}
}

void calc_min(int v[], int n, int *p){
	for(int i=0; i<n; i++){
		if(*p > v[i]){
			*p = v[i];
		}
	}
}

void calc_total(int v[], int n, int *p){
	for(int i=0; i<n; i++){
		*p += v[i];
	}
}