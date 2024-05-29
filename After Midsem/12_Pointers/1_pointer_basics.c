#include<stdio.h>

int main()
{	
	//We initialize and declare 3 variables of 3 different types
	int i = 32;
	char c = 'A';
	double d = 12.3;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	//Printing the sizeof each variable
	printf("Size of int i = %d\n", (int)sizeof(i)); //prints size of int
	printf("Size of char c = %d\n", (int)sizeof(c)); //print size of char
	printf("Size of double d = %d\n", (int)sizeof(d)); //prints size of double
	printf("--------------------------------------\n");

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	//Printing the address of each variable
	printf("Address of int i = %p\n", &i);
	printf("Address of char c = %p\n", &c);
	printf("Address of double d = %p\n", &d);
	printf("--------------------------------------\n");

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	//Declaring Pointer variables to store addresses of each variable
	//Pointers to Basic Types
	int *ip; //Pointer to a variable of type int (Type = 'POINTER TO INT')
			 // Can also be written as: int* ip; OR int * ip;
	
	char *cp; //Pointer to a variable of type char (Type = 'POINTER TO CHAR')
	double *dp; //Pointer to a variable of type double (Type = 'POINTER TO DOUBLE')

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	

	//Printing the Address of Pointer Variables
	printf("Address of int *ip = %p\n", &ip);
	printf("Address of char *cp = %p\n", &cp);
	printf("Address of double *dp = %p\n", &dp);
	printf("--------------------------------------\n");

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	//Printing the sizeof each pointer variable
	printf("Size of int *ip = %d\n", (int)sizeof(ip)); //prints size of pointer
	printf("Size of char *cp = %d\n", (int)sizeof(cp)); //print size of pointer
	printf("Size of double *dp = %d\n", (int)sizeof(dp)); //prints size of pointer
	printf("--------------------------------------\n");

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	//REFERENCING
	//Initializing the Pointer Variable
	// '&' is Reference Operator
	// '&' is an operator that given a variable of type T, 
						//returns its address of type T*.
	ip = &i;
	cp = &c;
	dp = &d;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	

	//Printing the value of Pointer Variables
	printf("Value of int *ip = %p\n", ip);
	printf("Value of char *cp = %p\n", cp);
	printf("Value of double *dp = %p\n", dp);
	printf("--------------------------------------\n");

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	

	//DEREFERENCING
	//Deferencing the Pointer Variable
	// '*' is Dereference Operator
	// '*' is an operator that given a variable p to type *T,
          				//returns the value of type T at address stored in p.
	int vi = *ip;
	char vc = *cp;
	double vd = *dp;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	
    
	//Printing the value of deferenced Pointer Variables
	//Notice the change in format specifiers
	//%p = printing memory addresses
	printf("Deferenced Value of int *ip = %d\n", *ip);
	printf("Deferenced Value of char *cp = %c\n", *cp);
	printf("Deferenced Value of double *dp = %lf\n", *dp);
	printf("--------------------------------------\n");

	printf("Value of vi = %d\n", vi);
	printf("Value of vc = %c\n", vc);
	printf("Value of vd = %lf\n", vd);
	printf("--------------------------------------\n");

	return 0;
}