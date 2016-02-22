/*
	@author: Alfonso Ríos
	@description: This is the method main.
	@version: v0.0.4
*/

#include "core/lia.c"

int main(int argc, char const *argv[])
{
	NODE *head = (NODE *) malloc(sizeof(NODE));
	l_construct(head);
	head = l_addFirst(head, "1");

	return 0;
}

// λ