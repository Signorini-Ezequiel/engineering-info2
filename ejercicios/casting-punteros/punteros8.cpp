#include <iostream>
using namespace std;

void minuscula(char *);
void mayuscula(char *);


/*
Desarrollar el ejercicio anterior con funciones. Crear una funci�n que pase los
valores a may�sculas y una funci�n que pase los valores a min�sculas. Desarrollar
un programa que declare e inicialice un vector tipo char con el abecedario. Luego
mostrar en pantalla el abecedario en mayuscula y minuscula,  utilizando punteros.
Nota: la funci�n para pasar a may�scula es toupper() y a min�sculas es tolower().
Ejemplo: cadena[i] = tolower(cadena[i]); En c�digo ASCII A=65

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
