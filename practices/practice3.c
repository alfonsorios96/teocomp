/*
	@author: Alfonso Ríos
	@description: This is the implementation about practice 3
	@version: v0.0.6
*/

#include "practice3.h"

void run(void){
	NODE *rule = (NODE *) malloc(sizeof(NODE));
	int finalStatus[SIZE_MAX];
	int status[SIZE_MAX];
	int fs_size = 0;
	int s_size = 0;
	l_construct(rule);
	menu(rule, status, finalStatus, s_size, fs_size);
}

void menu(NODE *rule, int status[], int finalStatus[], int s_size, int fs_size){
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
			p3_addStates(status, finalStatus, &s_size, &fs_size);
			system("cls");
			rule = p3_addRules(rule);
			system("cls");
		break;
		case 2:
			p3_run(rule, status, finalStatus, s_size, fs_size);
		break;
		case 3:
			p3_showRules(rule);
		break;
		case 4:
			exit(0);
		break;
	}

	menu(rule, status, finalStatus, s_size, fs_size);
}

int p3_existState(int array[], int size, int status){
	int i;

	for (i = 0; i < size; i++)
	{
		if (array[i] == status)
			return 1;
	}

	return 0;
}

void p3_addStates(int states[], int finals[], int *size1, int *size2){
	int opc = 0;
	int i = 0;
	int j = 0;

	do{
		int state, final;

		printf("\nInserte estado : ");
		scanf("%i", &state);
		if (p3_existState(states, i, state) == 0){
			states[i] = state;
			i++;
		}
		printf("El estado es final ?\n");
		scanf("%i", &final);
		if (p3_existState(finals, j, state) == 0 && final == 1){
			finals[j] = state;
			j++;
		}

		*size1 = i;
		*size2 = j;
		printf("Desea ingresar otro estado ?\n");
		scanf("%i", &opc);
	}while(opc == 1);
}

void p3_showStates(int states[], int size){
	int i;
	printf("\nSize = %i\n", size);
	for (i = 0; i < size; i++)
	{
		printf("%i,", states[i]);
	}
}

NODE * p3_addRules(NODE *root){
	int opc = 0;

	do{
		root = da_addRule(root);
		printf("Desea ingresar otra funcion ?\n");
		scanf("%i", &opc);
	}while(opc == 1);

	return root;
}

int getState(NODE *rule, char data, int status){
	NODE *temp = NULL;

	for (temp = rule; temp != NULL; temp = temp->next)
		if (data == temp->dat && status == temp->status){
			return temp->s_next;
		}
	return status;
}

void p3_run(NODE *rule, int status[], int finalStatus[], int s_size, int fs_size){
	char array[SIZE_MAX];
	int i;
	int state = 0;
	printf("\nIntroduce tu frase : ");
	str_input(array);

	for (i = 0; i < str_size(array); i++)
	{
		printf("\nEstatus '%i' en caracter '%c'", state, array[i]);
		state = getState(rule, array[i], state);
	}

	if (p3_existState(finalStatus, fs_size, state) == 1)
		printf("\nPertenece al lenguaje :D\n");
	else 
		printf("\nNo pertenece al lenguaje :P\n");
}

void p3_showRules(NODE *root){
	NODE * temp = NULL;

	for (temp = root; temp != NULL; temp = temp->next)
	{
		printf("%i con %c -> %i\n", temp->status, temp->dat, temp->s_next);
	}
}