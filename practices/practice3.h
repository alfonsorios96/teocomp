/*
	@author: Alfonso Ríos
	@description: This is the template about practice 1
	@version: v0.0.6
*/

int p3_existState(int array[], int size, int status);
void p3_addStates(int states[], int finals[], int *size1, int *size2);
void p3_showStates(int states[], int size);
NODE * p3_addRules(NODE *root);
void p3_showRules(NODE *root);
void p3_run(NODE *rule, int status[], int finalStatus[], int s_size, int fs_size);
void menu(NODE *rule, int status[], int finalStatus[], int s_size, int fs_size);
void run(void);