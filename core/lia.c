/*
	@author: Alfonso Ríos
	@created: February 2nd, 2016
	@description: This is the core about all the functions.
	@version: v0.0.1
*/

#include "lia.h"

// The pile is a struct FI-FO (First in - First out)

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