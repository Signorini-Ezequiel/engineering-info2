#include <stdio.h>
#include <stdlib.h>

struct xor_valores {
    char mensaje[50];
    int clave;
};

void endes(char mensaje[], int clave) {
    for (int i = 0; mensaje[i] != '\0'; i++) {
        mensaje[i] = (char)((int)mensaje[i] ^ clave);
    }
}

int main() {
    struct xor_valores mi_xor;

    printf("Ingrese una clave: ");
    scanf("%d", &mi_xor.clave);

    printf("Ingrese un mensaje: ");
    scanf(" %s", mi_xor.mensaje);

    endes(mi_xor.mensaje, mi_xor.clave);
    printf("El mensaje encriptado es: %s\n", mi_xor.mensaje);

    endes(mi_xor.mensaje, mi_xor.clave);
    printf("El mensaje des-encriptado es: %s\n", mi_xor.mensaje);
    
    return 0;
}