/*
	@author: Alfonso Ríos
	@description: This is the core about all the functions.
	@version: v0.0.10
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

void getTime(char string[]){
	time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    strftime(string,128,"%d/%m/%y %H:%M:%S",tlocal);
}

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

void f_writeDelta(int state, char data, int s_next){
	FILE *file;
 	
 	file = fopen ("./files/output.txt", "a" );
 	
 	fprintf(file, "q%i + '%c' -> q%i\n", state, data, s_next);
 	
 	fclose ( file );
}

void fda_delta_construct(DELTA * delta){
	delta->state = 0;
	delta->s_next = 0;
	delta->data = '\0';
	delta->prev = NULL;
	delta->next = NULL;
}

DELTA * fda_addDelta(DELTA * head, char data, int state, int next){
	if (head->data == '\0')
	{
		head->data = data;
		head->state = state;
		head->s_next = next;
		return head;
	}else{
		DELTA *new = (DELTA *) malloc(sizeof(DELTA));
		fda_delta_construct(new);
		new->data = data;
		new->state = state;
		new->s_next = next;
		new->next = head;
		head->prev = new;
		return new;
	}
}

int fda_existDelta(DELTA *head, char data, int state, int next){
	DELTA *temp;

	for (temp = head; temp != NULL; temp = temp->next)
	{
		if (temp->data == data && temp->state == state && temp->s_next == next)
		{
			return 1;
		}
	}

	return 0;
}

void fda_rmDelta(FD_AUTOMATA ** automata, char data, int state, int next){
	DELTA *temp;

	for (temp = (*automata)->head; temp != NULL; temp = temp->next)
	{
		if (temp->data == data && temp->state == state && temp->s_next == next)
		{
			DELTA *aux = temp;
			if (aux->prev != NULL)
			{
				temp = aux->prev;
				temp->next = aux->next;
			}
			if (aux->next != NULL)
			{
				temp = aux->next;
				temp->prev = aux->prev;
			}
		}
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
	automata->language[0] = '\0';
	automata->states[0] = 0;
	automata->size = 0;
	automata->finals[0] = 0;
	automata->f_size = 0;
	automata->init = 0;
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

		printf("\nInserte estado: ");
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

int fda_setFinalStates(FD_AUTOMATA * automata){
	int i = 0;
	int opc = 0;

	for (i = 0; i < SIZE_MAX; i++)
		automata->finals[i] = 0;
	i = 0;

	do{
		int state;

		printf("\nInserte estado final: ");
		scanf("%i", &state);
		if (fda_existState(automata->finals, i, state) == 0){
			automata->finals[i] = state;
			i++;
		}

		printf("Desea ingresar otro estado ?\n");
		scanf("%i", &opc);
	}while(opc == 1);

	return i;
}

FD_AUTOMATA * fda_create(FD_AUTOMATA * automata){
	automata->size = fda_setStates(automata);
	automata->f_size = fda_setFinalStates(automata);
	int opc = 0;

	do{
		automata = fda_createDeltas(automata);
		printf("Desea ingresar otra funcion ?\n");
		scanf("%i", &opc);
	}while(opc == 1);

	return automata;
}

int fda_execute(FD_AUTOMATA * automata, char data, int state){
	DELTA *temp = NULL;

	for (temp = automata->head; temp != NULL; temp = temp->next)
		if (data == temp->data && state == temp->state){
			f_writeDelta(temp->state, temp->data, temp->s_next);
			return temp->s_next;
		}
	return state;
}

void fda_showDeltas(FD_AUTOMATA * automata){
	DELTA *temp = NULL;
	for (temp = automata->head; temp != NULL; temp = temp->next)
	{
		printf("q%i + '%c' -> q%i\n", temp->state, temp->data, temp->s_next);
	}
}

int fda_isNotDeterminist(FD_AUTOMATA * automata){
	DELTA *temp, *aux;
	int flag = 0;

	for (temp = automata->head; temp != NULL; temp = temp->next)
	{
		flag = 0;
		for (aux = automata->head; aux != NULL; aux = aux->next)
		{
			if (temp->state == aux->state && temp->data == aux->data)
			{
				flag++;
			}
		}
		if (flag > 1)
		{
			break;
		}
	}
	if (flag > 1)
	{
		return 1;
	}else{
		return 0;
	}
}

void fda_ambiguo_construct(AMBIGUO *head){
	head->state = -1;
	head->data = '\0';
	head->states[0] = -1;
	head->alias = -1;
	head->prev = NULL;
	head->next = NULL;
}

int sizeArray(int array[]){
	int i = 0;

	if (array[0] == 0)
	{
		return i;
	}

	while(array[i] != -1){
		i++;
	}

	return i;
}

void showArray(int array[], int count){
	int i;

	for (i = 0; i < count; i++)
	{
		printf("%i,", array[i]);
	}

	printf("\n");
}

void cpyArray(int from[], int to[]){
	int count = sizeArray(from);
	int i;
	for (i = 0; i < count; i++)
	{
		to[i] = from[i];
	}
	to[i] = -1;
}

int existInArray(int array[], int state){
	int i;
	for (i = 0; i < sizeArray(array); i++)
	{
		if (array[i] == state)
		{
			return 1;
		}
	}
	return 0;
}

int newState(int array[], int size){
	int i;
	int new = 0;
	for (i = 0; i < size; i++)
	{
		if (array[i] > new)
		{
			new = array[i];
		}
	}
	return new + 1;
}

void addState(int array[], int *size, int state){
	array[*size] = state;
	(*size)++; 
}

void newFinals(int alias, int states[], int finals[], int size, int *f_size){
	int i,j;
	int flag = 0;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < *f_size; j++)
		{
			if (states[i] == finals[j])
			{
				finals[*f_size] = alias;
				(*f_size)++;
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			break;
		}		
	}
}

AMBIGUO * fda_addAmbiguo(AMBIGUO * head, int states[], int finals[], int *size, int *f_size, int state, char data, int array[]){
	if (head->data == '\0')
	{
		head->data = data;
		head->state = state;
		int alias = newState(states, *size);
		head->alias = alias;
		addState(states, size, alias);
		newFinals(head->alias, array, finals, sizeArray(array), f_size);
		cpyArray(array, head->states);
		return head;
	}else{
		AMBIGUO *new = (AMBIGUO *) malloc(sizeof(AMBIGUO));
		fda_ambiguo_construct(new);
		new->data = data;
		new->state = state;
		int alias = newState(states, *size);
		head->alias = alias;
		addState(states, size, alias);
		newFinals(new->alias, array, finals, sizeArray(array), f_size);
		cpyArray(array, new->states);
		new->next = head;
		head->prev = new;
		return new;
	}
}

void refillArray(DELTA *head, int array[], int state, char data){
	DELTA *temp;
	int k = 0;

	for (temp = head; temp != NULL; temp = temp->next)
	{
		if (temp->data == data && temp->state == state)
		{
			array[k] = temp->s_next;
			k++;
		}
	}
	array[k] = -1;
}

void deleteOldDeltas(AMBIGUO *helper, FD_AUTOMATA **automata){
	int count = sizeArray(helper->states);
	int i;

	for (i = 0; i < count; i++)
	{
		fda_rmDelta(automata, helper->data, helper->state, helper->states[i]);
	}
}

void createNewDeltas(AMBIGUO *helper, FD_AUTOMATA **automata){
	AMBIGUO *temp;
	for (temp = helper; temp != NULL; temp = temp->next)
	{
		deleteOldDeltas(temp, automata);
		if (fda_existDelta((*automata)->head, temp->data, temp->state, temp->alias) == 0)
		{
			(*automata)->head = fda_addDelta((*automata)->head, temp->data, temp->state, temp->alias);
		}
	}
}

int cmp_arrays(int array1[], int array2[]){
	int size = sizeArray(array1);
	int count = sizeArray(array2);

	if (size != count)
	{
		return 0;
	}else{
		int i;

		for (i = 0; i < size; i++)
		{
			if (array1[i] != array2[i])
			{
				return 0;
			}
		}

		return 1;
	}
}

int getAlias(AMBIGUO *helper, int array[]){
	AMBIGUO *temp;

	for (temp = helper; temp != NULL; temp = temp->next)
	{
		if (cmp_arrays(array, temp->states) == 1)
		{
			return temp->alias;
		}
	}

	return -1;
}

void getColateralStates(AMBIGUO *helper, DELTA *head, int array[]){
	printf("Debugger : %i\n", sizeArray(array));
	DELTA *temp;
	int i = 0;

	for (temp = head; temp != NULL; temp = temp->next)
	{
		int j;
		int count = sizeArray(helper->states);

		for (j = 0; j < count; j++)
		{
			if (helper->states[j] == temp->state && temp->data == helper->data && existInArray(array, temp->s_next) == 0)
			{
				array[i] = temp->s_next;
				i++;
			}
		}
		array[i] = -1;
	}
}

void createColateralDeltas(AMBIGUO *helper, FD_AUTOMATA **automata){
	AMBIGUO *temp;

	for (temp = helper; temp != NULL; temp = temp->next)
	{
		int size = str_size((*automata)->language);
		int i;

		int array[SIZE_MAX];
		for (i = 0; i < size; i++)
		{
			getColateralStates(temp, (*automata)->head, array);
			int alias = getAlias(helper, array);
			if (alias != -1 && fda_existDelta((*automata)->head, temp->data, temp->alias, alias) == 0)
			{
				(*automata)->head = fda_addDelta((*automata)->head, temp->data, temp->alias, alias);
			}else{
				int count = sizeArray(array);
				int j;

				for (j = 0; j < count; j++)
				{
					if (fda_existDelta((*automata)->head, temp->data, temp->alias, array[j]) == 0)
					{
						(*automata)->head = fda_addDelta((*automata)->head, temp->data, temp->alias, array[j]);
					}
				}
			}
		}
	}
}

void fda_convertToDeterminist(FD_AUTOMATA ** automata){

	AMBIGUO * helper = NULL;
	helper = (AMBIGUO *) malloc(sizeof(AMBIGUO));
	fda_ambiguo_construct(helper);
	DELTA *temp, *aux;
	int array[SIZE_MAX];
	int flag;

	for (temp = (*automata)->head; temp != NULL; temp = temp->next)
	{
		flag = 0;
		for (aux = (*automata)->head; aux != NULL; aux = aux->next)
		{
			if (temp->state == aux->state && temp->data == aux->data)
			{
				flag++;
			}
		}
		if (flag > 1)
		{
			refillArray((*automata)->head, array, temp->state, temp->data);
			helper = fda_addAmbiguo(helper, (*automata)->states, (*automata)->finals, &((*automata)->size), &((*automata)->f_size), temp->state, temp->data, array);
			break;
		}
	}

	printf("\n---------------\n");

	fda_showDeltas(*automata);

	printf("\n---------------\n");
	
	deleteOldDeltas(helper, automata);

	printf("\n---------------\n");

	fda_showDeltas(*automata);

	createNewDeltas(helper, automata);

	printf("\n---------------\n");

	fda_showDeltas(*automata);

	createColateralDeltas(helper, automata);

	printf("\n---------------\n");

	fda_showDeltas(*automata);
	
}

/*
	-----------  FILES  ----------------
	
*/

// Here is defined the method to construct a row struct
void f_row_construct(ROW *row){
	row->row = 0;
	row->data[0] = '\0';
	row->prev = NULL;
	row->next = NULL;
}

// Here is defined the method to get the numbers of rows of a file
int f_row_size(ROW *head){
	ROW *temp;
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

// Here is defined the method to add a row struct from file.
ROW * f_addRow(ROW *head, char string[]){
	if (str_size(head->data) == 0)
	{
		str_cpy(string, head->data);
		head->row = 1;

		return head;
	}else{
		ROW *new = (ROW *) malloc(sizeof(ROW));
		f_row_construct(new);
		str_cpy(string, new->data);
		new->row = head->row + 1;
		new->prev = head;
		head->next = new;

		return new;
	}
}

// Here is defined the method to get a file
ROW * f_input(ROW *head, char array[]){
	FILE *file;

	char path[SIZE_MAX];
	str_concat("./files/", array, path);
 
 	file = fopen(path,"r");
 	
 	if (file == NULL)
 		exit(1);
 	
 	while (feof(file) == 0)
 	{
 		char string[SIZE_MAX];
 		fgets(string,SIZE_MAX,file);
 		head = f_addRow(head, string);
 	}

    fclose(file);
    return head;
}

void f_output(char string[]){
	FILE *file;
 	
 	file = fopen ("./files/output.txt", "a" );
 	
 	fputs( string, file );
 	
 	fclose ( file );
}

// Here is defined the method to show all rows of a file
void f_showRows(ROW *head){
	ROW *temp;

	for (temp = head; temp != NULL; temp = temp->prev)
			printf("%i - %s\n", temp->row, temp->data);

	printf("\n");
}

// Here is defined the method read the alphabeto from file
void f_readAlphabeto(ROW *head, char language[]){
	ROW *temp;
	int j = 0;

	for (temp = head; temp != NULL; temp = temp->prev){
		if (temp->row == 2)
		{
			int size = str_size(temp->data);
			int i;

			for (i = 0; i < size; i++){
				if (temp->data[i] != ',' && (int) temp->data[i] != 10)
				{
					language[j] = temp->data[i];
					j++;
				}
			}

			language[j] = '\0';
		}else{
			continue;
		}
	}
}

// Here is defined the method read the states from file
void f_readStates(ROW *head, int states[], int *tam){
	ROW *temp;
	int j = 0;

	for (temp = head; temp != NULL; temp = temp->prev){
		if (temp->row == 1)
		{
			int size = str_size(temp->data);
			int i;

			for (i = 0; i < size; i++){
				if (temp->data[i] != ',' && (int) temp->data[i] != 10)
				{
					states[j] = (int) temp->data[i] - 48;
					j++;
				}
			}

			*tam = j;
		}else{
			continue;
		}
	}
}

// Here is defined the method read the final states from file
void f_readFinalStates(ROW *head, int states[], int *tam){
	ROW *temp;
	int j = 0;

	for (temp = head; temp != NULL; temp = temp->prev){
		if (temp->row == 4)
		{
			int size = str_size(temp->data);
			int i;

			for (i = 0; i < size; i++){
				if (temp->data[i] != ',' && (int) temp->data[i] != 10)
				{
					states[j] = (int) temp->data[i] - 48;
					j++;
				}
			}

			*tam = j;
		}else{
			continue;
		}
	}
}

// Here is defined the method read the deltas functions from file
void f_readDeltas(ROW *head, FD_AUTOMATA ** automata){
	ROW *temp;
	int flag = 0;

	for (temp = head; temp != NULL; temp = temp->prev)
	{
		if (temp->row > 4)
		{
			char data = '\0';
			int state = -1, s_next = -1;
			int size = str_size(temp->data);
			int i;

			for (i = 0; i < size; i++)
			{
				if (temp->data[i] != ',')
				{
					flag++;

					if (flag == 1)
					{
						state = (int) temp->data[i] - 48;
					}
					if (flag == 2)
					{
						data = temp->data[i];
					}
					if (flag == 3)
					{
						s_next = (int) temp->data[i] - 48;
					}
					if (flag == 4)
					{
						flag = 0;
						if (data != '\0' && state != -1 && fda_existDelta((*automata)->head, data, state, s_next) == 0)
						{
							(*automata)->head = fda_addDelta((*automata)->head, data, state, s_next);
						}
					}
				}
			}
		}else{
			continue;
		}
	}
}

void f_readInit(ROW *head, FD_AUTOMATA ** automata){
	ROW *temp;

	for (temp = head; temp != NULL; temp = temp->prev)
	{
		if (temp->row == 3)
		{
			(*automata)->init = (int) temp->data[0] - 48;
		}
	}
}

void f_readAutomata(FD_AUTOMATA ** automata, char array[]){
	free(*automata);
	*automata = (FD_AUTOMATA *) malloc(sizeof(FD_AUTOMATA));
	ROW * file = (ROW *) malloc(sizeof(ROW));
	f_row_construct(file);
	file = f_input(file, array);
	int count = 0;
	f_readAlphabeto(file, (*automata)->language);
	f_readInit(file, automata);
	f_readDeltas(file, automata);
	f_readStates(file, (*automata)->states, &count);
	(*automata)->size = count;
	f_readFinalStates(file, (*automata)->finals, &count);
	(*automata)->f_size = count;	
}