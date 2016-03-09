/*
	@author: Alfonso Ríos
	@description: This is the main method.
	@version: v0.0.8
*/

#include "core/lia.c"

int main(int argc, char const *argv[])
{
	ROW * file = (ROW *) malloc(sizeof(ROW));
	f_row_construct(file);
	file = f_input(file);
	f_showRows(file);
	return 0;
}

// λ