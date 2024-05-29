#include<stdio.h>

void swap(int *a, int *b)//pointer variables as function arguments
{
	int temp;
	temp = *a; //deferencing pointer variable 'a'
	*a = *b;
	*b = temp;
    printf("Inside swap(): x = %d, y = %d\n", *a, *b);
}

int main()
{
	int x = 10, y = 20;

	printf("Before swap(): x = %d, y = %d\n", x, y);

	swap(&x, &y);//function parameters are the addresses of the variables

	printf("After swap(): x = %d, y = %d\n", x, y);

	return 0;
}