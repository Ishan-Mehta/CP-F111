/*
//Basics of command line arguments

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("Number of arguments: %d\n", argc);

	for(int i = 0; i < argc; i++)
		printf("Argument %d = %s\n", i, argv[i]);

	return 0;
}
*/

// /*
//Write a program that takes one or more real numbers as command line arguments and prints their mean

#include<stdio.h>
#include<stdlib.h>
int main(int argc, char **argv)
{
    double sum = 0;
    if(argc == 1)
    {
        fprintf(stderr, "Usage: %s <real_number_1> <real_number_2> ...\n", argv[0]);
        return 1;
    }
    for(int i = 1; i < argc; i++)
        sum = sum + atof(argv[i]);
    printf("Mean = %.1lf\n", (sum/(argc - 1)));
    return 0;    
}

// */