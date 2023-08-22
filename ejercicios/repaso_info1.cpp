#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;

void generar(int [10][4]);
int verificar(int [10][4], int, int *, int *, int *);

#define ALUMNOS 5
/*
Desarrolle un programa para una academia de musica que permita gestionar la inscripcion de alumnos a los cursos de guitarra de los diferentes niveles.
Algunas consideraciones:

niveles: principiantes (1), intermedios (2) y avanzados (3).  
Cupo maximo de 5 alumnos (por curso)
Los costos de matriculacion y mensuales de cada curso: $3000 principiantes, $4000 intermedios y $5000 avanzados. 
si tiene promocion: descuento del 10% en su matricula.

Declare e inicialice a cero un arreglo 10x4
Luego crear una funcion para generar las inscripciones, teniendo en cuenta lo siguiente: 
La columna numero de inscripcion: numeros consecutivos empezando por 1.
La columna nivel del curso:       numeros aleatorios entre 1 y 3. Luego debe revisar que haya cupo suficiente para ese nivel, si no hay cupo se anula (se verifica en la funcion verificar)
La columna promocion:             numeros aleatorios entre el 0 y 1. El cero es que no tiene promocion y 1 es que si tiene promocion.
La columna monto total: 		  calcular el monto de la inscripcion segun el nivel y si tiene promocion.  

menu se repite hasta que el usuario indique s de salir con las siguientes funciones: 
Mostrar todas las inscripciones por nivel.
Mostrar la cantidad de alumnos por cada nivel.
Calcular la recaudacion de la academia de musica.
*/

int main() {
	srand(time(NULL));
	int inscripcion[10][4] = {0};
	
	generar(inscripcion[10][]);
	return 0;
}


void generar(int inscripcion[10][4]){
	int disponible = 0, basico = 0, medio = 0, avanzado = 0;
	for(int i = 1; i <= 10; i++){
		// numero de inscripcion
		inscripcion[i][0] = i;
		
		// nivel del curso
		inscripcion[i][1] = rand() %3+1;
		
		// promocion
		inscripcion[i][2] = rand() %1;
		
		// monto total
		// valor de la matricula
		switch(inscripcion[i][1]){
		case 1: // nivel 1
			inscripcion[i][3] += 3000;
			break;
		case 2: // nivel 2
			inscripcion[i][3] += 4000;
			break;
		case 3: // nivel 3
			inscripcion[i][3] += 5000;
			break;
		}
		// descuento
		if(1 == inscripcion[i][2]){
			inscripcion[i][3] -= inscripcion[i][3]*10/100; // le resto el 10%
		}
		
		// verifico si esta vacante
		disponible = verificar(inscripcion[10][], i, &basico, &medio, &avanzado);
		if(0 == disponible){
			inscripcion[i] = {0};
		}
	}
}


int verificar(int inscripcion[10][4], int n, int * basico, int * medio, int * avanzado){
	int nivel = inscripcion[n][1]; // nivel de curso (ultimo valor)
	if(1 == nivel){
		if (ALUMNOS > *basico){
			return 1; // esta disponible
		} else{
			return 0; // no esta disponible
		}
	} else {
		if(2 == nivel){
			if (ALUMNOS > *medio){
				return 1; // esta disponible
			} else{
				return 0; // no esta disponible
			}
		} else{
			if (ALUMNOS > *avanzado){
				return 1; // esta disponible
			} else{
				return 0; // no esta disponible
			}
		}
	}
}
