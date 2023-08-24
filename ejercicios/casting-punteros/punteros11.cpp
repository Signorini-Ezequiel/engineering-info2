#include <iostream>
#include <stdio.h>
using namespace std;

void menu();

/*
Se desea cargar en un vector los saldos de proveedores. La cantidad de saldos
es ingresada por el usuario (máximo 10). La carga finaliza con un saldo menor
o igual a cero. Además, desarrolle las siguientes funciones para mostrar:

a. Cantidad de saldos cargados.
b. Promedio de saldos.
c. Cantidad de saldos menores al promedio.
d. Cantidad de saldos mayores al promedio.
e. Calcular cuánto fue lo recaudado en el mes.

Cada ítem es una función. Para recorrer el vector utilice punteros.
*/
int main() {
	int v[10] = {0};
    char opcion = ' ';

    for(int i=0; i<10; i++){
        printf("Ingrese el saldo %d: ", i+1);
        scanf("%d", &v[i]);
        if(0 >= v[i]){
            break; // termina la carga con un valor menor o igual a 0
        }
    }

    /*
    a. Cantidad de saldos cargados.
    b. Promedio de saldos.
    c. Cantidad de saldos menores al promedio.
    d. Cantidad de saldos mayores al promedio.
    e. Calcular cuánto fue lo recaudado en el mes.
    */
    do
    {
	    menu();

        printf("\nElija una opcion: \n");
        scanf(" %c", &opcion);

        switch (opcion)
        {
        // Cantidad de saldos cargados.
        case 'a':
            
            break;

        // 
        case 'b':
            
            break;
        
        default:
            printf("La opcion ingresada no esta disponible");
            break;
        }
        
    } while ('s' != opcion);
    
    
	return 0;
}

void menu(){
    printf("\n--------------------------------------------\n");
    printf("Menu\n");
    printf("a: Cantidad de saldos cargados\n");
    printf("b: Promedio de saldos\n");
    printf("c: Cantidad de saldos menores al promedio\n");
    printf("d: Cantidad de saldos mayores al promedio\n");
    printf("e: Calcular cuánto fue lo recaudado en el mes\n");
    printf("\n--------------------------------------------\n");
}