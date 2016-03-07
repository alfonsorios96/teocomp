/*
	@author: Alfonso Ríos
	@description: This is the template about all the functions.
	@version: v0.0.6
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE_MAX 1200

// Here is defined the type of data.
typedef char type;

// Here are defined the structs

typedef struct pile
{
	type data;
	struct pile *next;
}PILE;

typedef struct list
{
	int status, s_next;
	char dat;
	type string[SIZE_MAX];
	struct list *prev, *next;
}NODE;

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
void str_pow(char s1[], char s2[], int n);
void str_cpy(char s1[], char s2[]);
int str_cmpr(char s1[], char s2[]);

// List

void l_construct(NODE *root);
int l_size(NODE *head);
NODE * l_addFirst(NODE *head, char string[]);
NODE * l_addLast(NODE *head, char string[]);
void l_showAll(NODE *head);

// Automatas
	// Determinist
NODE * da_addRule(NODE *root);