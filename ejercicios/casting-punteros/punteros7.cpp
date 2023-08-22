#include <iostream>
using namespace std;


/*
Desarrollar un programa que declare e inicialice un vector tipo char con el abecedario.
Luego mostrar en pantalla el abecedario en mayuscula y minuscula, utilizando punteros.
Nota: la función para pasar a mayúscula es toupper() y a minúsculas es tolower().
Ejemplo: cadena[i] = tolower(cadena[i]); En código ASCII A=65, a=97
*/
int main() {
	char v[27]={' '};
	
	int c=65;
	for(int i=0; i<26; i++){
		v[i]=c;
		c += 1;
		printf("%c", v[i]); // en mayuscula
	}
	
	
	printf("\n\n");
	
	for(int i=0; i<26; i++){
		v[i]=tolower(v[i]);
		printf("%c", v[i]); // en minuscula
	}
	
	return 0;
}

