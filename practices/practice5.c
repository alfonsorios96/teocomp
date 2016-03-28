/*
	@author: Alfonso Ríos
	@description: This is the implementation about practice 5
	@version: v0.0.10
*/

#include "practice5.h"

void run(void){
	FD_AUTOMATA *automata = (FD_AUTOMATA *) malloc(sizeof(FD_AUTOMATA));
	fda_construct(automata);
	menu(automata);
}

void menu(FD_AUTOMATA *automata){
	printf("\n\nSelecciona una opcion del menu\n");
	printf("1. Leer el automata\n");
	printf("2. Ejecutar el automata\n");
	printf("3. Salir\n");
	int opc;
	printf("\nSelecciona una opcion : ");
	scanf("%i", &opc);

	switch(opc){
		case 1:
			remove("./files/output.txt");
			printf("Introduzca el nombre del archivo con extension : ");
			char array[SIZE_MAX];
			str_input(array);
			printf("\n");
			f_readAutomata(&automata, array);
			fda_convertToDeterminist(&automata);
		break;
		case 2:
			p4_run(automata);
		break;
		case 3:
			exit(0);
		break;
	}

	menu(automata);
}

void p4_run(FD_AUTOMATA * automata){
	char array[SIZE_MAX];
	int i;
	int state = automata->init;
	printf("\nIntroduce tu frase : ");
	str_input(array);

	f_output("\n---------------\n");
	char datatime[SIZE_MAX];
	getTime(datatime);
	f_output(datatime);
	f_output("\n\n");

	f_output("\nPalabra : ");
	f_output(array);
	f_output("\n");

	for (i = 0; i < str_size(array); i++)
	{
		state = fda_execute(automata, array[i], state);
	}

	if (fda_existState(automata->finals, automata->f_size, state) == 1){
		char string[] = "\nPertenece al lenguaje.\n";
		f_output(string);
	}
	else{
		char string[] = "\nNo pertenece al lenguaje.\n";
		f_output(string);
	} 

	printf("\n----- Se cargo el archivo output.txt ----\n");
	f_output("\n---------------\n");
}