#include <iostream>
#include <math.h>
using namespace std;

char menu();

/* PUNTEROS
Escribir un programa que solicite dos numeros y luego una de las operaciones del
menu de opciones:
a. sumar
b. restar
c. multiplicar
d. dividir dos numeros
e. elevar a una potencia
f. calcular la raiz cuadrada de un numero.

Luego mostrar el resultado y preguntar si desea realizar otra operacion o terminar el programa.
Utilizar punteros para el calculo de las operaciones. Libreria: #include <math.h>
*/
int main() {
	int a = 0, b = 0;
	int *pa = &a, *pb = &b;
	char opcion = ' ';
	
	printf("Ingrese un numero: ");
	scanf("%d", &a);
	printf("Ingrese otro numero: ");
	scanf("%d", &b);
	
	do
	{
		opcion = menu();
	
		switch(opcion){
		// sumar
		case 'a':
			printf("El resultado es: %d", *pa + *pb);
			break;
		// restar
		case 'b':
			printf("El resultado es: %d", *pa - *pb);
			break;
		// multiplicar
		case 'c':
			printf("El resultado es: %d", (*pa) * (*pb));
			break;
		// dividir
		case 'd':
			printf("El resultado es: %d", *pa / *pb);
			break;
		// potencia
		case 'e':
			printf("El resultado es: %d base: %d expo: %d", pow(*pa, *pb), *pa, *pb);
			break;
		// raiz
		case 'f':
			printf("El resultado es:\n a: %d\n b: %d", sqrt(*pa), sqrt(*pb));
			break;
		// salir
		case 's':
			break; // evita que lo tome como opcion desconocida
		default:
			printf("Opcion desconocida");
			break;
		}
	} while ('s' != opcion);
	
	return 0;
}


char menu(){
	char opcion = ' ';
	printf("\n--------------------------------------------------\n");
	printf("Opciones:\n");
	printf("a: sumar \n");
	printf("b: restar \n");
	printf("c: multiplicar \n");
	printf("d: dividir \n");
	printf("e: elevar a una potencia (segundo numero) \n");
	printf("f: calcular la raiz cuadrada de los numeros \n");
	printf("s: salir\n");
	printf("--------------------------------------------------\n\n");
	
	printf("Elija una opcion: ");
	scanf(" %c", &opcion);
	return opcion;
}