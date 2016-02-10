/*
	@author: Alfonso Ríos
	@created: February 2nd, 2016
	@description: This is the method main.
	@version: v0.0.2
*/

#include "core/lia.c"

int main(int argc, char const *argv[])
{
	// String 1
	char s1[SIZE_MAX];
	// String 2
	char s2[SIZE_MAX];
	// String 1 concat String 2
	char s3[SIZE_MAX];
	// Current
	char s4[SIZE_MAX];
	// Prefix
	char s5[SIZE_MAX];
	// Subfix
	char s6[SIZE_MAX];
	// Substring
	char s7[SIZE_MAX];
	// String 3
	char s8[SIZE_MAX];
	// Subsecuence
	char s9[SIZE_MAX];
/*
	printf ("Put the first string: ");
	str_input(s1);

	printf("Size 1 : %d\n\n", str_size(s1));

	printf ("Put the second string: ");
	str_input(s2);

	printf("Size 2 : %d\n\n", str_size(s2));
	str_concat(s1, s2, s3);
	printf("%s\n", s3);
	printf("Size 3 : %d\n\n", str_size(s3));
	str_current(s3,s4);
	printf("Inverse : %s\n\n", s4);
	int fixes;
	printf("How much characteres do you want?\n");
	scanf("%d", &fixes);
	str_fixes(s3,s5,fixes,1);
	str_fixes(s3,s6,fixes,2);
	printf("Prefix : %s\n\n", s5);
	printf("Subfix : %s\n\n", s6);
	int prefix;
	printf("How much characteres prefix do you want?\n");
	scanf("%d", &prefix);
	int subfix;
	printf("How much characteres subfix do you want?\n");
	scanf("%d", &subfix);
	str_subString(s3,s7,prefix,subfix);
	printf("Substring : %s\n\n", s7);
*/
	printf ("Put the third string: ");
	str_input(s8);
	char token[] = {'a','o','\0'};
	str_subSecuence(s8, token, s9);
	printf("\n\nSubsecuence : %s\n\n", s9);
	return 0;
}