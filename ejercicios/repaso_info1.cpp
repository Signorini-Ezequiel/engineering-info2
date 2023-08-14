#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;

void generar(int [10][4]);
int verificar(int [10][4], int, int *, int *, int *);

#define ALUMNOS 5
/*
Desarrolle un programa para una academia de m�sica que permita gestionar la inscripci�n de alumnos a los cursos de guitarra de los diferentes niveles.
Algunas consideraciones:

niveles: principiantes (1), intermedios (2) y avanzados (3).  
Cupo m�ximo de 5 alumnos (por curso)
Los costos de matriculaci�n y mensuales de cada curso: $3000 principiantes, $4000 intermedios y $5000 avanzados. 
si tiene promocion: descuento del 10% en su matr�cula.

Declare e inicialice a cero un arreglo 10x4
Luego crear una funci�n para generar las inscripciones, teniendo en cuenta lo siguiente: 
La columna n�mero de inscripci�n: n�meros consecutivos empezando por 1.
La columna nivel del curso:       n�meros aleatorios entre 1 y 3. Luego debe revisar que haya cupo suficiente para ese nivel, si no hay cupo se anula (se verifica en la funcion verificar)
La columna promoci�n:             n�meros aleatorios entre el 0 y 1. El cero es que no tiene promoci�n y 1 es que si tiene promoci�n.
La columna monto total: 		  calcular el monto de la inscripci�n seg�n el nivel y si tiene promoci�n.  

men� se repite hasta que el usuario indique s de salir con las siguientes funciones: 
Mostrar todas las inscripciones por nivel.
Mostrar la cantidad de alumnos por cada nivel.
Calcular la recaudaci�n de la academia de m�sica.
*/

int main() {
	srand(time(NULL));
	int inscripcion[10][4] = {0};
	
	generar(inscripcion[10][4]);
	return 0;
}


void generar(int inscripcion[10][4]){
	int disponible = 0, basico = 0, medio = 0, avanzado = 0, correcto = 0;
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
		correcto = verificar(inscripcion[10][4], i, &basico, &medio, &avanzado);
		if(0 == correcto){
			inscripcion[i] = {0};
		}
	}
}


int verificar(int inscripcion[10][4], int n, int * basico, int * medio, int * avanzado){
	int nivel = inscripcion[n][1]; // nivel de curso ultimo valor
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
