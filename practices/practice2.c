/*
	@author: Alfonso Ríos
	@description: This is the implementation about practice 2
	@version: v0.0.5
*/

#include "practice2.h"

void run(void){
	NODE *lang1, *lang2;

	printf("\n\nPractica 2 : Operaciones del lenguaje.\n\n");

	printf("\n\tLENGUAJE 1 :\n");
	lang1 = getLanguage(lang1);

	printf("\n\tLENGUAJE 2 :\n");
	lang2 = getLanguage(lang2);

	menu(lang1, lang2);
}

void menu(NODE * lang1, NODE * lang2){
	printf("\n\nSelecciona una opcion del menu\n");
	printf("1. Union de lenguajes\n");
	printf("2. Concatenacion de lenguajes\n");
	printf("3. Inversa de lenguajes\n");
	printf("4. Potencia de lenguajes\n");
	printf("5. Salir\n");
	int opc;
	printf("\nSelecciona una opcion : ");
	scanf("%i", &opc);

	switch(opc){
		case 1:
			p2_join(lang1, lang2);
		break;
		case 2:
			p2_concat(lang1, lang2);
		break;
		case 3:
			p2_inverse(lang1, lang2);
		break;
		case 4:
			//p2_pow(lang1, lang2);
		break;
		case 5:
			exit(0);
		break;
	}

	menu(lang1, lang2);
}

NODE * getLanguage(NODE *head){
	head = (NODE *) malloc(sizeof(NODE));
	char temp[SIZE_MAX];
	l_construct(head);
	int flag = 1;

	do{
		printf("\nEscriba una palabra de su lenguaje: ");
		str_input(temp);
		head = l_addFirst(head, temp);
		printf("\n\nOtra palabra ? S - 1/N - 0: ");
		scanf("%i", &flag);
	}while(flag == 1);

	return head;
}

int existLanguage(NODE *head, char string[]){
	NODE *temp;

	for (temp = head; temp != NULL; temp = temp->next)
	{
		if (str_cmpr(temp->string, string) == 1)
		{
			return 1;
		}
	}
	return 0;
}

void p2_join(NODE *lang1, NODE *lang2){
	NODE *lang3, *temp1, *temp2;
	lang3 = (NODE *) malloc(sizeof(NODE));
	l_construct(lang3);

	for (temp1 = lang1; temp1 != NULL; temp1 = temp1->next)
		if (existLanguage(lang3, temp1->string) == 0)
			lang3 = l_addFirst(lang3, temp1->string);

	for (temp2 = lang2; temp2 != NULL; temp2 = temp2->next)
		if (existLanguage(lang3, temp2->string) == 0)
			lang3 = l_addFirst(lang3, temp2->string);

	l_showAll(lang3);
}

void p2_concat(NODE *lang1, NODE *lang2){
	NODE *lang3, *temp1, *temp2;
	lang3 = (NODE *) malloc(sizeof(NODE));
	l_construct(lang3);

	printf("\nConcatenacion de L1L2\n");

	for (temp1 = lang1; temp1 != NULL; temp1 = temp1->next)
	{
		for (temp2 = lang2; temp2 != NULL; temp2 = temp2->next)
		{
			char array[SIZE_MAX];
			str_concat(temp1->string, temp2->string, array);
			l_addFirst(lang3, array);
		}
	}

	l_showAll(lang3);

	NODE *lang4, *temp3, *temp4;
	lang4 = (NODE *) malloc(sizeof(NODE));
	l_construct(lang4);

	printf("\nConcatenacion de L2L1\n");

	for (temp3 = lang2; temp3 != NULL; temp3 = temp3->next)
	{
		for (temp4 = lang1; temp4 != NULL; temp4 = temp4->next)
		{
			char array[SIZE_MAX];
			str_concat(temp3->string, temp4->string, array);
			l_addFirst(lang4, array);
		}
	}
	
	l_showAll(lang4);
}

void p2_inverse(NODE * lang1, NODE * lang2){
	NODE *lang3, *temp1, *temp2;
	lang3 = (NODE *) malloc(sizeof(NODE));
	l_construct(lang3);

	printf("\nInversa de lenguaje L1\n");
	for (temp1 = lang1; temp1 != NULL; temp1 = temp1->next)
	{
		char array[SIZE_MAX];
		str_current(temp1->string, array);
		l_addFirst(lang3, array);
	}
	l_showAll(lang3);

	NODE *lang4;
	lang4 = (NODE *) malloc(sizeof(NODE));
	l_construct(lang4);

	printf("\nInversa de lenguaje L2\n");
	for (temp2 = lang2; temp2 != NULL; temp2 = temp2->next)
	{
		char array[SIZE_MAX];
		str_current(temp2->string, array);
		l_addFirst(lang4, array);
	}
	l_showAll(lang4);
}
/*
void p2_pow(NODE * lang){
	int n;
	printf("\nSelecciona una potencia : ");
	scanf("%i", &n);
	if (n == 0)
	{
		printf("\n\nPotencia del lenguaje : e\n");
	}
	if (n > 0)
	{
		int i;
		for (i = 0; i < n; i++)
		{
			
		}
	}
	if (n < 0)
	{
		
	}
}
*/