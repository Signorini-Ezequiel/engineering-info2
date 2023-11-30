#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int dato;
    struct nodo*siguiente;
};
typedef struct nodo nodo_t;

void push(nodo_t **stackptr){
    nodo_t *nodo_nuevo=NULL;
    nodo_nuevo=(nodo_t*)malloc(sizeof(nodo_t));
    if(NULL == nodo_nuevo){
        printf("Error al crear el nodo");
        exit(1);
    }
    int dato=0;

    printf("Ingrese un dato: ");
    scanf("%d", &dato);

    nodo_nuevo->dato=dato;
    nodo_nuevo->siguiente=*stackptr; // el siguiente del actual es el ultimo que figura
    *stackptr=nodo_nuevo; // ahora el ultimo es el nuevo
    printf("\n\n");
}

void pop(nodo_t **stackptr){
    if(NULL == *stackptr){
        printf("La lista esta vacia\n");
        return;
    }else{
        nodo_t *temp=*stackptr;
        *stackptr=(*stackptr)->siguiente;
        free(temp);
    }
    printf("\n\n");
}

void print(nodo_t *stackptr){
    nodo_t *temp=stackptr;
    while(NULL!=temp){
        printf("%d  ", temp->dato);
        temp=temp->siguiente;
    }
    printf("\n\n");
}


int main(void){
    nodo_t *stackptr=NULL;

    int opcion=0;

    do{
        printf("Ingrese una opcion del menu: \n1-push \n2-pop \n3-print\n4-salir");
        printf("\n\nOpcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            push(&stackptr);
            break;
        case 2:
            pop(&stackptr);
            break;
        case 3:
            print(stackptr);
            break;
        case 4:
            printf("Saliendo del programa, espere un momento...\n");
            while(NULL != stackptr){
                pop(&stackptr);
            }
            printf("Proceso terminado");
            break;
        default:
            printf("La opcion ingresada es incorrecta");
            break;
        }
    }while(4 != opcion);

    return 0;
}