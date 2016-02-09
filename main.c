#include "core/lia.c"

int main(int argc, char const *argv[])
{
	PILE *head = (PILE *) malloc(sizeof (PILE));
	p_construct(head);
	head = p_add(head, 'i');
	head = p_add(head, 'h');
	head = p_add(head, 'g');
	p_rm(head);
	head = p_add(head, 'f');
	head = p_add(head, 'e');
	head = p_add(head, 'd');
	head = p_add(head, 'c');
	p_rm(head);
	head = p_add(head, 'b');
	head = p_add(head, 'a');
	p_show(*head);
	return 0;
}