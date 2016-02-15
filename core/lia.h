/*
	@author: Alfonso Ríos
	@description: This is the template about all the functions.
	@version: v0.0.3
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE_MAX 120

// Here is defined the type of data.
typedef char type;

// Here are defined the structs

typedef struct pile
{
	type data;
	struct pile *next;
}PILE;

// Here are declared the functions.

// Pile

void p_construct(PILE *p);
PILE * p_add(PILE *head, type data);
PILE * p_rm(PILE *head);
type p_getElement(PILE head);
void p_show(PILE head);

// Strings

int str_size(char string[]);
void str_input(char string[]);
void str_concat(char s1[], char s2[], char s3[]);
void str_current(char s1[], char s2[]);
void str_fixes(char s1[], char s2[], int size, int fix);
void str_subString(char s1[], char s2[], int prefix, int subfix);
void str_subSecuence(char s1[], char s2[], char s3[]);
int str_existIn(char character, char string[]);