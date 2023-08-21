#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;

#define ALUMNOS 5

void generar(int [][4]);
int verificar(int [][4], int, int *, int *, int *);

/*
Desarrolle un programa para una academia de musica que permita gestionar la inscripcion de
alumnos a los cursos de guitarra de los diferentes niveles.
Algunas consideraciones:

niveles: principiantes (1), intermedios (2) y avanzados (3).  
cupo maximo de 5 alumnos (por curso)
costos de matriculacion y mensuales de cada curso: $3000 principiantes, $4000 intermedios y $5000 avanzados. 
si tiene promocion: descuento del 10% en su matricula.

Declare e inicialice a cero un arreglo 10x4
Luego crear una funcion para generar las inscripciones, teniendo en cuenta lo siguiente: (contenido de columnas)
numero de inscripcion: consecutivos empezando por 1.
nivel del curso:       aleatorios entre 1 y 3. Luego debe revisar que haya cupo suficientepara ese nivel, si no hay cupo se anula (se verifica en la funcion verificar)
promocion:             aleatorios entre 0 y 1. El cero es que no tiene promocion y 1 es que si tiene promocion
monto total: 		  calcular el monto de la inscripcion segun el nivel y si tiene promocion

menu se repite hasta que el usuario indique "s" de salir con las siguientes funciones: 
Mostrar todas las inscripciones por nivel.
Mostrar la cantidad de alumnos por cada nivel.
Calcular la recaudacion de la academia de musica.
*/

int main() {
	srand(time(NULL));
	int inscripcion[10][4] = {0}, contador_mostrar = 0, alumnos_1=0, alumnos_2=0, alumnos_3=0, recaudacion=0;
	char orden = ' ';
	
	generar(inscripcion);

	printf("\n Bienvenido/a al gestor de tu academia \n");

	do
	{
		printf("\n----------------------------------------");
		printf("\n a: Mostrar las inscripciones por nivel \n b: Mostrar la cantidad de alumnos por nivel \n c: Calcular la recaudacion de la academia \n s: salir\n");
		printf("----------------------------------------\n\n");
		printf("Que desea?: ");
		scanf(" %c", &orden);

		switch (orden)
		{
		// ---------------------------------------------------------------------------------------------
		case 'a': // Mostrar inscripciones
			printf("\nNivel 1\n");
			for(int i=0; i<10; i++){
				// si estaba vacante cuando se genero
				if(0 != inscripcion[i][0]){
					if(1 == inscripcion[i][1]){
						printf("- numero: %d, promociona: %d, monto: %d \n", inscripcion[i][0], inscripcion[i][2], inscripcion[i][3]);
					} else{
						contador_mostrar = i;
						break;
					}
				}
			}

			printf("\nNivel 2\n");
			for(int i=contador_mostrar; i<10; i++){
				if(2 == inscripcion[i][1]){
					printf("- numero: %d, promociona: %d, monto: %d \n", inscripcion[i][0], inscripcion[i][2], inscripcion[i][3]);
				}else{
					contador_mostrar = i;
				}
			}

			printf("\nNivel 3\n");
			for(int i=contador_mostrar; i<10; i++){
				if(3 == inscripcion[i][1]){
					printf("- numero: %d, promociona: %d, monto: %d \n", inscripcion[i][0], inscripcion[i][2], inscripcion[i][3]);
				}
			}
			break;

		// ---------------------------------------------------------------------------------------------
		case 'b': // mostrar la cantidad de alumnos por nivel
			// si es la primera vez que se ejecuta la opcion
			if(0==alumnos_1 && 0==alumnos_2 && 0==alumnos_3){
				for(int i=0; i<10; i++){
					if(1 == inscripcion[i][1]){
						alumnos_1 += 1;
					}else{
						if(2 == inscripcion[i][1]){
							alumnos_2 += 1;
						}else{
							alumnos_3 += 1;
						}
					}
				}
			}

			printf("Hay: \n - %d alumnos en el nivel 1 \n - %d alumnos en el nivel 2 \n - %d alumnos en el nivel 3\n", alumnos_1, alumnos_2, alumnos_3);
			break;

		// ---------------------------------------------------------------------------------------------
		case 'c': // calcular la recaudacion
			for(int i=contador_mostrar; i<10; i++){
				recaudacion += inscripcion[i][3]; // no suma adecuadamente (suma solo del nivel 3)
			}
			printf("La recaudacion total es de: %d", recaudacion);
			break;

		// ---------------------------------------------------------------------------------------------
		case 's':
			printf("Fin del programa\n");
			break;
			
		// ---------------------------------------------------------------------------------------------
		default:
			printf("Opcion desconocida\n");
			break;
		}
	} while ('s' != orden);
	

	return 0;
}


void generar(int inscripcion[10][4]){
	int basico = 0, medio = 0, avanzado = 0, correcto = 0;
	for(int i = 0; i < 10; i++){
		// numero de inscripcion
		inscripcion[i][0] = i;
		
		// nivel del curso
		inscripcion[i][1] = rand() %3+1;
		
		// promocion
		inscripcion[i][2] = rand() %2+0;
		
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
		correcto = verificar(inscripcion, i, &basico, &medio, &avanzado);
		if(0 == correcto){
			for(int j=0; j<4; j++){
				inscripcion[i][j] = 0;
			}
		}
	}

	// ordeno las inscripciones por nivel
	int switcher[4];
	for(int i=0; i<9; i++){ // corroboro hasta el anteultimo
		if(inscripcion[i][1] > inscripcion[i+1][1]){
				for(int j=0; j< 4; j++) {
					switcher[j] = inscripcion[i][j];
					inscripcion[i][j] = inscripcion[i+1][j];
					inscripcion[i+1][j] = switcher[j];
				}
			}
	}
}


int verificar(int inscripcion[10][4], int n, int * basico, int * medio, int * avanzado){
	if(1 == inscripcion[n][1]){
		if (ALUMNOS > *basico){
			*basico += 1;
			return 1; // esta disponible
		} else{
			return 0; // no esta disponible
		}
	} else {
		if(2 == inscripcion[n][1]){
			if (ALUMNOS > *medio){
				*medio += 1;
				return 1; // esta disponible
			} else{
				return 0; // no esta disponible
			}
		} else{
			if (ALUMNOS > *avanzado){
				*avanzado += 1;
				return 1; // esta disponible
			} else{
				return 0; // no esta disponible
			}
		}
	}
}