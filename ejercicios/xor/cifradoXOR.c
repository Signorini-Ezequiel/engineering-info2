#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char message[100];
    char key[10] = "hola";

    printf("Ingrese el mensaje a encriptar: ");
    scanf("%s", message);

    int messageLen = strlen(message);
    int keyLen = strlen(key);

    for (int i = 0; i < messageLen; i++) {
        message[i] = message[i] ^ key[i % keyLen];
    }

    printf("Mensaje encriptado: %s\n", message);

    for (int i = 0; i < messageLen; i++) {
        message[i] = message[i] ^ key[i % keyLen];
    }

    printf("Mensaje desencriptado: %s\n", message);

    return 0;
}