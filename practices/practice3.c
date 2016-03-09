/*
	@author: Alfonso Ríos
	@description: This is the implementation about practice 3
	@version: v0.0.7
*/

#include "practice3.h"

void run(void){
	FD_AUTOMATA *automata = (FD_AUTOMATA *) malloc(sizeof(FD_AUTOMATA));
	fda_construct(automata);
	menu(automata);
}

void menu(FD_AUTOMATA *automata){
	printf("\n\nSelecciona una opcion del menu\n");
	printf("1. Crear el automata\n");
	printf("2. Ejecutar el automata\n");
	printf("3. Mostrar automata\n");
	printf("4. Salir\n");
	int opc;
	printf("\nSelecciona una opcion : ");
	scanf("%i", &opc);

	switch(opc){
		case 1:
			automata = fda_create(automata);
		break;
		case 2:
			p3_run(automata);
		break;
		case 3:
			fda_showDeltas(automata);
		break;
		case 4:
			exit(0);
		break;
	}

	menu(automata);
}

void p3_run(FD_AUTOMATA * automata){
	char array[SIZE_MAX];
	int i;
	int state = 0;
	printf("\nIntroduce tu frase : ");
	str_input(array);

	for (i = 0; i < str_size(array); i++)
	{
		printf("\nEstado '%i' en caracter '%c'", state, array[i]);
		state = fda_execute(automata, array[i], state);
	}

	printf("\nEstatus '%i'", state);

	if (fda_existState(automata->states, automata->size, state) == 1)
		printf("\nPertenece al lenguaje :D\n");
	else 
		printf("\nNo pertenece al lenguaje :P\n");
}