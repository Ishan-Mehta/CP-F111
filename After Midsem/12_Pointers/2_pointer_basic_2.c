#include<stdio.h>

int main()
{
	int d = 100;
	int *e1, *e2;

	e1=&d;
	e2=e1;

	printf("%d %d\n",*e1, *e2);

	return 0;
}