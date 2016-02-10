/*
	@author: Alfonso Ríos
	@created: February 2nd, 2016
	@description: This is the core about all the functions.
	@version: v0.0.2
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