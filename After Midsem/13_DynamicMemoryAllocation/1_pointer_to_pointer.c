#include<stdio.h>

int main()
{
	char c = 'E';

	char *cp = &c; //Pointer to a character
	char **cpp = &cp; //Pointer to a pointer to a character


	printf("Address of c: &c = %p, cp = %p, *cpp = %p\n", &c, cp, *cpp);

	//Print the value
	printf("Value of c: c = %c, *cp = %c, **cpp = %c\n", c, *cp, **cpp);


	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	//Similarly you can have a Chain of Pointers

	char ***cppp = &cpp; //Pointer to a pointer to a pointer to a character

	printf("Address of c: &c = %p, **cppp = %p\n", &c, **cppp);

	//Print the value
	printf("Value of c: c = %c, ***cppp = %c\n", c, ***cppp);

	return 0;
}