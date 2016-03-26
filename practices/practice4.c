/*
	@author: Alfonso Ríos
	@description: This is the implementation about practice 4
	@version: v0.0.9
*/

#include "practice4.h"

void run(void){
	FD_AUTOMATA *automata = (FD_AUTOMATA *) malloc(sizeof(FD_AUTOMATA));
	fda_construct(automata);
	menu(automata);
}

void menu(FD_AUTOMATA *automata){
	printf("\n\nSelecciona una opcion del menu\n");
	printf("1. Leer el automata\n");
	printf("2. Ejecutar el automata\n");
	printf("3. Mostrar automata\n");
	printf("4. Eliminar delta\n");
	printf("5. Salir\n");
	int opc;
	printf("\nSelecciona una opcion : ");
	scanf("%i", &opc);

	switch(opc){
		case 1:
			f_readAutomata(&automata);
		break;
		case 2:
			p4_run(automata);
		break;
		case 3:
			fda_showDeltas(automata);
		break;
		case 4:
			fda_rmDelta(&automata, '1', 4, 2);
		break;
		case 5:
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

	for (i = 0; i < str_size(array); i++)
	{
		printf("\nEstado '%i' en caracter '%c'", state, array[i]);
		state = fda_execute(automata, array[i], state);
	}

	printf("\nEstatus '%i'", state);

	if (fda_existState(automata->finals, automata->f_size, state) == 1)
		printf("\nPertenece al lenguaje :D\n");
	else 
		printf("\nNo pertenece al lenguaje :P\n");
}