#include <iostream>
using namespace std;

void minuscula(char *);
void mayuscula(char *);


/*
Desarrollar el ejercicio anterior con funciones. Crear una función que pase los
valores a mayúsculas y una función que pase los valores a minúsculas. Desarrollar
un programa que declare e inicialice un vector tipo char con el abecedario. Luego
mostrar en pantalla el abecedario en mayuscula y minuscula,  utilizando punteros.
Nota: la función para pasar a mayúscula es toupper() y a minúsculas es tolower().
Ejemplo: cadena[i] = tolower(cadena[i]); En código ASCII A=65

*/
int main() {
	char v[27]={' '};
	
	// doy valores iniciales (en mayuscula en este caso)
	int c=65;
	for(int i=0; i<26; i++){
		v[i]=c;
		c += 1;
	}
	
	printf("Abecedario original: \n");
	for(int i=0; i<26; i++){
		printf("%c", v[i]);
	}
	
	printf("\n\n");
	
	printf("Abecedario convertido a minuscula: \n");
	minuscula(v);
	for(int i=0; i<26; i++){
		printf("%c", v[i]);
	}
	printf("\n\n");
	
	printf("Abecedario convertido a mayuscula: \n");
	mayuscula(v);
	for(int i=0; i<26; i++){
		printf("%c", v[i]);
	}
	printf("\n\n");
	
	return 0;
}

void minuscula(char *v){
	for(int i=0; i<26; i++){
		v[i]=tolower(v[i]);
	}
}
void mayuscula(char *v){
	for(int i=0; i<26; i++){
		v[i]=toupper(v[i]);
	}
}
