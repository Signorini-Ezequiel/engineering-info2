#include <iostream>
#include <stdio.h>
using namespace std;

void menu();
void mostrar_saldos(int [], int);
int calc_promedio(int [], int);
void menores_promedio(int [], int, int);
void mayores_promedio(int [], int, int);
int calc_total(int [], int);

/*
Se desea cargar en un vector los saldos de proveedores. La cantidad de saldos
es ingresada por el usuario (maximo 10). La carga finaliza con un saldo menor
o igual a cero. Ademas, desarrolle las siguientes funciones para mostrar:

a. Cantidad de saldos cargados.
b. Promedio de saldos.
c. Cantidad de saldos menores al promedio.
d. Cantidad de saldos mayores al promedio.
e. Calcular cuanto fue lo recaudado en el mes.

Cada item es una funcion. Para recorrer el vector utilice punteros.
*/
int main() {
	int v[10] = {0}, val_cargados = 0, promedio = -1, total = -1;
    char opcion = ' ';

    for(int i=0; i<10; i++){
        printf("Ingrese el saldo %d: ", i+1);
        scanf("%d", &v[i]);
        if(0 >= v[i]){
            v[i] = 0;
            break; // termina la carga con un valor menor o igual a 0
        } else{
            val_cargados += 1;
        }
    }

    do
    {
	    menu();

        printf("\nElija una opcion: \n");
        scanf(" %c", &opcion);

        switch (opcion)
        {
        // Cantidad de saldos cargados
        case 'a':
            mostrar_saldos(v, val_cargados);
            break;

        // Promedio de saldos
        case 'b':
            if(0 > promedio){
                promedio = calc_promedio(v, val_cargados);
            } else {
                printf("El promedio es: %d", promedio);
            }
            break;

        // Cantidad de saldos menores al promedio.
        case 'c':
            menores_promedio(v, val_cargados, promedio);
            break;
        
        // Cantidad de saldos mayores al promedio.
        case 'd':
            mayores_promedio(v, val_cargados, promedio);
            break;
        
        // Calcular cuanto fue lo recaudado en el mes.
        case 'e':
            if(0 > total){
                total = calc_total(v, val_cargados);
            }
            printf("El total recaudado es: %d", total);
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

void mostrar_saldos(int v[], int max){
    printf("\n\n");
    
    for(int i=0; i<max; i++){
        printf("El saldo %d es de: $%d \n", i, v[i]);
    }
    
    printf("\n\n");
}

int calc_promedio(int v[], int max){
    int promedio = 0;

    for(int i=0; i<max; i++){
        promedio += v[i];
    }
    promedio = promedio/max;

    printf("El promedio es: %d \n", promedio);

    return promedio;
}

void menores_promedio(int v[], int max, int promedio){
    if(0 > promedio){
        promedio = calc_promedio(v, max);
    }

    for(int i=0; i<max; i++){
        if(promedio > v[i]){
            printf("El valor %d es menor al promedio", i);
        }
    }
}

void mayores_promedio(int v[], int max, int promedio){
    if(0 > promedio){
        promedio = calc_promedio(v, max);
    }

    for(int i=0; i<max; i++){
        if(promedio < v[i]){
            printf("El valor %d es mayor al promedio", i);
        }
    }
}

int total(int v[], int max){
    int total = 0;

    for(int i=0; i<max; i++){
        total += v[i];
    }

    return total;
}