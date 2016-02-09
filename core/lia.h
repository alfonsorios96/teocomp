/*
	@author: Alfonso Ríos
	@created: February 2nd, 2016
	@description: This is the template about all the functions.
	@version: v0.0.1
*/

#include <stdio.h>
#include <stdlib.h>

// Here is defined the type of data.
typedef char type;

// Here are defined the structs

typedef struct pile
{
	type data;
	struct pile *next;
}PILE;

// Here are declared the functions.

void p_construct(PILE *p);
PILE * p_add(PILE *head, type data);
PILE * p_rm(PILE *head);
type p_getElement(PILE head);
void p_show(PILE head);