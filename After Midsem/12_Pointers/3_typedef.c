/*
typedef is used to provide existing datatypes with a new name.

Syntax: typedef existing_name alias_name;
*/

#include<stdio.h>

int main(void)
{

	typedef char A;
	A x = 'A';

	typedef int B;
	B y = 10;

    // Aliasing pointers
    typedef B* Integer_pointer;
    Integer_pointer z;  // int *z;

    B a = 5;
    z = &a;

	printf("x = %c, y = %d\n", x, y);
    
    printf("Address of a = z = %p\n", z);


    //How to typedef an array?

    typedef int List[5];
	List arr = {5,3,10,12,6};

	for(int i = 0; i<5; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0; 
}