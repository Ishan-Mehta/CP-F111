#include<stdio.h>

int main()
{
	int *x1, *x2; 
	char *y1, *y2;

	int x = 5;
	x1 = &x;

	printf("x1 = %p\n", x1);

	char y = 'A';
	y1 = &y;

	printf("y1 = %p\n", y1);
    
    x2=x1+1; 
    y2=y1+1;
    
    /*
        - incrementing the pointer x1 increments x1 by sizeof(int)
        - incrementing the pointer y1 increments y1 by sizeof(char)


        Let us consider ptr is a pointer has data type “T” and “i” is the constant with which it is added.
        addr( ptr + i ) =  addr( ptr ) + ( sizeof( T ) * i );
    */

    printf("sizeof(int) = %d, x1 = %p, x2 = x1+1 = %p, x1+2 = %p \n", (int)sizeof(int),x1,x1+1,x1+2);
    printf("After addition: y1 = %p, y2 = y1 + 1 = %p \n", y1, y2);

    //Multiplication and Division NOT ALLOWED
    //Only arithmetic operations allowed are: +, -, ++, -- 
    x2 = x2 - 2;
    y2 = y2 - 2;
	printf("After subtraction: x2 = x2-2 = %p, y2 = y2-2 = %p \n", x2, y2);

	//Comparison is only allowed between pointers pointing to the same type (==, !=, <, <=, >, >=)

	printf("Comparison: x2 == x1 %d, y1 >= y2 %d\n", x2 == x1, y1 >= y2);//Just for an example: you should always compare pointers which point to the same type.
    
	return 0;
}