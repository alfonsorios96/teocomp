/*
	@author: Alfonso Ríos
	@description: This is the template about all the functions.
	@version: v0.0.7
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

typedef struct delta
{
	int state, s_next;
	char data;
	struct delta *prev, *next;
}DELTA;

typedef struct fd_automata
{
	char language[SIZE_MAX];
	int states[SIZE_MAX];	//states
	int size;
	int finals[SIZE_MAX];	//Final states
	int f_size;
	int init;
	struct delta *head;
}FD_AUTOMATA;

typedef struct row
{
	int row;
	char data[SIZE_MAX];
	struct row *prev, *next;
}ROW;