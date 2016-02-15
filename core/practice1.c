/*
	@author: Alfonso Ríos
	@description: This is the implementation about practice 1
	@version: v0.0.3
*/

#include "practice1.h"

void run(void){
	char string1[SIZE_MAX];
	char string2[SIZE_MAX];

	printf("\n\nPractica 1 : Manejo de cadenas.\n\n");
	printf("Introduce la primer cadena : \n");
	str_input(string1);

	printf("\n\nIntroduce la segunda cadena cadena : \n");
	str_input(string2);

	menu(string1, string2);
}

void menu(char string1[], char string2[]){
	printf("\n\nSelecciona una opcion del menu\n");
	printf("1. Concatenacion de cadenas\n");
	printf("2. Prefijos de cadenas\n");
	printf("3. Subfijos de cadenas\n");
	printf("4. Subcadena\n");
	printf("5. Subsecuencia\n");
	printf("6. Invertir cadenas\n");
	printf("7. Potencia de cadenas\n");
	printf("8. Salir\n");
	int opc;
	printf("\nSelecciona una opcion : ");
	scanf("%i", &opc);

	switch(opc){
		case 1:
			p1_concat(string1, string2);
		break;
		case 2:
			p1_prefix(string1, string2);
		break;
		case 3:
			p1_subfix(string1, string2);
		break;
		case 4:
			p1_substring(string1, string2);
		break;
		case 5:
			p1_subsecuence(string1, string2);
		break;
		case 6:
			p1_inverse(string1, string2);
		break;
		case 7:
		break;
		case 8:
			exit(0);
		break;
	}

	menu(string1, string2);
}

void p1_concat(char string1[], char string2[]){
	char concatArray1[SIZE_MAX];
	char concatArray2[SIZE_MAX];
	str_concat(string1, string2, concatArray1);

	printf("La concatenacion de '%s' y '%s' es : '%s'\n\n", string1, string2, concatArray1);
	printf("\nLa concatenacion de '%s' y '%s' es : '%s'\n", string2, string1, concatArray2);
}

void p1_prefix(char string1[], char string2[]){
	char prefixArray1[SIZE_MAX];
	char prefixArray2[SIZE_MAX];
	int fixes;

	printf("Cuantos caracteres de prefijo quieres : ");
	scanf("%i", &fixes);

	str_fixes(string1, prefixArray1, fixes, 1);
	str_fixes(string2, prefixArray2, fixes, 1);

	printf("El prefijo de %d de '%s' es : '%s'\n\n", fixes , string1, prefixArray1);
	printf("El prefijo de %d de '%s' es : '%s'\n\n", fixes , string2, prefixArray2);
}

void p1_subfix(char string1[], char string2[]){
	char subfixArray1[SIZE_MAX];
	char subfixArray2[SIZE_MAX];
	int fixes;

	printf("Cuantos caracteres de subfijo quieres : ");
	scanf("%i", &fixes);

	str_fixes(string1, subfixArray1, fixes, 2);
	str_fixes(string2, subfixArray2, fixes, 2);

	printf("El prefijo de %d de '%s' es : '%s'n\n", fixes , string1, subfixArray1);
	printf("El prefijo de %d de '%s' es : '%s'\n\n", fixes , string2, subfixArray2);
}

void p1_substring(char string1[], char string2[]){
	char substringArray1[SIZE_MAX];
	char substringArray2[SIZE_MAX];
	int prefixSize, subfixSize;

	printf("Cuantos caracteres de prefijo quieres quitar: ");
	scanf("%i", &prefixSize);

	printf("Cuantos caracteres de subfijo quieres quitar: ");
	scanf("%i", &subfixSize);

	str_subString(string1, substringArray1, prefixSize, subfixSize);
	str_subString(string2, substringArray2, prefixSize, subfixSize);

	printf("\n\nLa subcadena de '%s' es : '%s'\n", string1, substringArray1);
	printf("La subcadena de '%s' es : '%s'\n\n", string2, substringArray2);
}

void p1_subsecuence(char string1[], char string2[]){
	char abcArray1[SIZE_MAX];
	char abcArray2[SIZE_MAX];
	char input[SIZE_MAX];
	int i = 0, k = 0;

	printf("\nIntroduce una cadena sin separacion : ");
	str_input(input);

	for (i = 0; i < str_size(string1); i++)
	{
		if(str_existIn(string1[i], input) == 0){
			abcArray1[k] = string1[i];
			k++;
		}
	}
	abcArray1[k] = '\0';
	k = 0;

	for (i = 0; i < str_size(string2); i++)
	{
		if(str_existIn(string2[i], input) == 0){
			abcArray2[k] = string2[i];
			k++;
		}
	}
	abcArray2[k] = '\0';

	printf("La subsecuencia de la cadena %s es : %s\n", string1, abcArray1);
	printf("La subsecuencia de la cadena %s es : %s\n", string2, abcArray2);
}

void p1_inverse(char string1[], char string2[]){
	char inverseArray1[SIZE_MAX];
	char inverseArray2[SIZE_MAX];

	str_current(string1, inverseArray1);
	str_current(string2, inverseArray2);

	printf("\n\nLa cadena inversa de '%s' es : '%s'\n", string1, inverseArray1);
	printf("La cadena inversa de '%s' es : '%s'\n\n", string2, inverseArray2);
}