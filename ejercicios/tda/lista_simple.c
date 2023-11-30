#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int dato;
    struct nodo *siguiente;
};

typedef struct nodo nodo_t;


void push(nodo_t **head){
    int dato=0;
    printf("Ingrese un dato: ");
    scanf("%d", &dato);

    nodo_t *nodo_nuevo = NULL;
    nodo_nuevo = (nodo_t*) malloc(sizeof(nodo_t));
    if(NULL == nodo_nuevo){
        printf("Error al crear nodos");
        exit(1);
    }

    nodo_nuevo->dato = dato;
    nodo_nuevo->siguiente = NULL;

    if(NULL == *head){
        *head = nodo_nuevo;
    }else{
        nodo_t *temp= *head;
        if(NULL == temp){
            printf("Error al crear nodos");
            exit(1);
        }

        while(NULL != temp->siguiente){
            temp=temp->siguiente;
        }
        temp->siguiente=nodo_nuevo;
    }
    
}

void pop(nodo_t **head){
    if(NULL == *head){
        printf("Lista vacia\n");
    }else{
        nodo_t *current = *head;
        nodo_t *prev = NULL;

        if(NULL == current->siguiente){
            free(current);
            *head=NULL;
        }else{
            while(NULL != current->siguiente){
                prev=current;
                current=current->siguiente;
            }
            free(current);
            prev->siguiente=NULL;
        }
    }
}

void print(nodo_t *head){
    nodo_t *temp;
    temp=head;
    while(NULL != temp){
        printf("%d   ", temp->dato);
        temp=temp->siguiente;
    }
    printf("\n\n");
}

int main(void){
    nodo_t *head=NULL;
    int opcion=0;

    do{
        printf("Ingrese una opcion del menu: \n1-push \n2-pop \n3-print\n4-salir");
        printf("\n\nOpcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            push(&head);
            break;
        case 2:
            pop(&head);
            break;
        case 3:
            print(head);
            break;
        case 4:
            printf("Saliendo del programa, espere un momento...\n");
            while(NULL != head){
                pop(&head);
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