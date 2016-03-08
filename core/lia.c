/*
	@author: Alfonso Ríos
	@description: This is the core about all the functions.
	@version: v0.0.7
*/

#include "lia.h"

/*
	-----------    PILE ----------------
	The pile is a struct FI-FO (First in - First out)
*/


// Here is defined the construct method.
void p_construct(PILE *p){
	p->next = NULL;
}

// Here is defined the method to add an element to the pile.
PILE * p_add(PILE *head, type data){
	PILE *n = (PILE *) malloc(sizeof (PILE));
	p_construct(n);
	n->data = data;
	n->next = head;
	return n;
}

// Here is defined the method to remove an element to the pile.
PILE * p_rm(PILE *head){
	head->data = head->next->data;
	head->next = head->next->next;
	return head;
}

// Here is defined the method to show the head element.
type p_getElement(PILE head){
	return head.data;
}

// Here is defined the method to show all elements.
void p_show(PILE head){
	PILE *pointer = &head;

    while (pointer->next != NULL){
    	printf("\t%c\n", pointer->data);
    	pointer = pointer->next;
    }
}

/*
	-----------    STRING ----------------
	Strings are defined as an array of characters 
	or a pointer to a portion of memory containing 
	ASCII characters.
*/

// Here is defined the method to get the size of array char
int str_size(char string[]){
	int size = 0;
	while (string[size] != '\0')
		size++;
	return size;
}

// Here is defined the method to get a array char of user.
void str_input(char string[]){
	fflush(stdin);
	fgets (string, SIZE_MAX, stdin);
	string[str_size(string) - 1] = '\0';
}

// Here is defined the method to join two strings.
void str_concat(char s1[], char s2[], char s3[]){
	int i = 0;
	int s1_size = str_size(s1);
	int s2_size = str_size(s2);

	for (i = 0; i < s1_size; i++) {
		s3[i] = s1[i];
	}

	for (i = 0; i < s2_size; i++) {
		s3[s1_size + i] = s2[i];
	}

	s3[s1_size + s2_size] = '\0';
}

// Here is defined the method to get an inverse of string.
void str_current(char s1[], char s2[]){
	int s1_size = str_size(s1);
	int i = 0;
	for (i = 0; i < s1_size; i++){
		s2[i] = s1[s1_size - i - 1];
	}
	s2[s1_size] = '\0';
}

// Here is defined the method to get a prefix or sufix.
// Prefix - 1 && Sufix - 2
void str_fixes(char s1[], char s2[], int size, int fix){
	int i = 0;
	for (i = 0; i < str_size(s1); i++)
	{
		if (i < size)
		{
			switch (fix){
				case 1:
					s2[i] = s1[i];
				break;
				case 2:
					s2[i] = s1[str_size(s1) - size + i];
				break;
			}
		}
	}
	s2[size] = '\0';
}

// Here is defined the method to get a substring.
void str_subString(char s1[], char s2[], int prefix, int subfix){
	int i = 0;
	for (i = 0; i < str_size(s1); i++)
	{
		if (i < str_size(s1) - (prefix + subfix))
		{
			s2[i] = s1[prefix + i];
		}
	}
	s2[str_size(s1) - (prefix + subfix)] = '\0';
}

// Here is defined the method to get a subsecuence.
void str_subSecuence(char s1[], char s2[], char s3[]){
	int i,j;
	int k = 0;
	for (i = 0; i < str_size(s1); i++)
	{
		int flag = -1;
		for (j = 0; j < str_size(s2); j++)
		{
			if (s1[i] == s2[j])
				flag = j;
		}
		if (flag == -1){
			s3[k] = s1[i];
			k++;
		}
	}
	s3[k + 1] = '\0';
}

// Here is define the function to match a char.
int str_existIn(char character, char string[]){
	int i = 0;
	for (i = 0; i < str_size(string); i++)
	{
		if (string[i] == character)
		{
			return 1;
		}
	}
	return 0;
}

// Here is define the function to loop concat.
void str_pow(char s1[], char s2[], int n){
	int i = 0, j = 0, k = 0;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < str_size(s1); j++)
		{
			s2[k] = s1[j];
			k++;
		}
	}

	s2[k] = '\0';
}

// Here is defined the function to copy a string.
void str_cpy(char s1[], char s2[]){
	int i = 0;
	for (i = 0; i < str_size(s1); i++)
	{
		s2[i] = s1[i];
	}
	s2[i] = '\0';
}

int str_cmpr(char s1[], char s2[]){
	int i;
	if (str_size(s1) == str_size(s2))
	{
		for (i = 0; i < str_size(s1); i++)
		{
			if (s1[i] != s2[i])
			{
				return 0;
			}
		}
		return 1;
	}else{
		return 0;
	}
}

/*
	-----------    LIST ----------------
	This is a kind of struct. You can move
	bidirectional.
*/

void l_construct(NODE *root){
	root->string[0] = '\0';	
	root->prev = NULL;
	root->next = NULL;
}

int l_size(NODE *head){
	NODE *temp;
	int size = 0;

	if (head->next != NULL)
	{
		for (temp = head; temp != NULL; temp = temp->next)
			size++;
	}else{
		for (temp = head; temp != NULL; temp = temp->prev)
			size++;
	}
	return size;
}

NODE * l_addFirst(NODE *head, char string[]){
	if (str_size(head->string) == 0)
	{
		str_cpy(string, head->string);
		return head;
	}else{
		NODE *temp;
		for (temp = head; temp->prev != NULL; temp = temp->prev)
		{
			/* code */
		}
		NODE *new = (NODE *) malloc(sizeof(NODE));
		l_construct(new);
		str_cpy(string, new->string);
		new->next = temp;
		temp->prev = new;
		return new;
	}
}

NODE * l_addLast(NODE *head, char string[]){
	if (str_size(head->string) == 0)
	{
		str_cpy(string, head->string);
		return head;
	}else{
		NODE *temp;
		for (temp = head; temp->next != NULL; temp = temp->next)
		{
			/* code */
		}
		NODE *new = (NODE *) malloc(sizeof(NODE));
		l_construct(new);
		str_cpy(string, new->string);
		new->prev = temp;
		temp->next = new;
		return new;
	}
}

void l_showAll(NODE *head){
	NODE *temp;

	if (head->next != NULL)
	{
		for (temp = head; temp != NULL; temp = temp->next)
			printf("%s, ", temp->string);
	}else{
		for (temp = head; temp != NULL; temp = temp->prev)
			printf("%s, ", temp->string);
	}
	printf("\n");
}

/*
	-----------    FD AUTOMATA ----------------
	
*/

void fda_delta_construct(DELTA * delta){
	delta->state = 0;
	delta->s_next = 0;
	delta->data = '\0';
	delta->prev = NULL;
	delta->next = NULL;
}

DELTA * fda_addDelta(DELTA * head, char data, int state, int next){
	if (data == '\0')
	{
		head->data = data;
		head->state = state;
		head->s_next = next;
		return head;
	}else{
		DELTA *temp;
		for (temp = head; temp->prev != NULL; temp = temp->prev)
		{
			/* code */
		}
		DELTA *new = (DELTA *) malloc(sizeof(DELTA));
		fda_delta_construct(new);
		new->data = data;
		new->state = state;
		new->s_next = next;
		new->next = temp;
		temp->prev = new;
		return new;
	}
}

FD_AUTOMATA * fda_createDeltas(FD_AUTOMATA * automata){
	type string[SIZE_MAX];
	int state, s_next;

	printf("\nEstatus actual : ");
	scanf("%i", &state);
	printf("\nCaracter a recibir : ");
	str_input(string);
	printf("\nEstatus siguiente : ");
	scanf("%i", &s_next);

	automata->head = fda_addDelta(automata->head, string[0], state, s_next);

	return automata;
}

void fda_construct(FD_AUTOMATA * automata){
	automata->states[0] = 0;
	automata->size = 0;
	automata->head = (DELTA *) malloc(sizeof(DELTA));
	fda_delta_construct(automata->head);
}

int fda_existState(int states[], int size, int state){
	int i;

	for (i = 0; i < size; i++)
		if (states[i] == state)
			return 1;
	return 0;
}

int fda_setStates(FD_AUTOMATA * automata){
	int i = 0;
	int opc = 0;

	for (i = 0; i < SIZE_MAX; i++)
		automata->states[i] = 0;
	i = 0;

	do{
		int state;

		printf("\nInserte estado final: ");
		scanf("%i", &state);
		if (fda_existState(automata->states, i, state) == 0){
			automata->states[i] = state;
			i++;
		}

		printf("Desea ingresar otro estado ?\n");
		scanf("%i", &opc);
	}while(opc == 1);

	return i;
}

FD_AUTOMATA * fda_create(FD_AUTOMATA * automata){
	automata->size = fda_setStates(automata);
	int opc = 0;

	do{
		automata = fda_createDeltas(automata);
		printf("Desea ingresar otra funcion ?\n");
		scanf("%i", &opc);
	}while(opc == 1);

	return automata;
}

int fda_execute(FD_AUTOMATA * automata, char data, int state){
	FD_AUTOMATA *temp = NULL;

	for (temp = automata->head; temp != NULL; temp = temp->next)
		if (data == temp->data && state == temp->state){
			return temp->s_next;
		}
	return state;
}

void fda_showDeltas(FD_AUTOMATA * automata){
	DELTA *temp = NULL;
	for (temp = automata->head; temp != NULL; temp = temp->next)
	{
		printf("Estado %i con caracter %c pasa al estado %i\n", temp->state, temp->data, temp->s_next);
	}
}