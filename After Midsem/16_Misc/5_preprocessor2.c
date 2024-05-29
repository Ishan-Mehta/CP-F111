/**
 * #ifdef is a preprocessor directive used for conditional compilation
 * The preprocessor checks if the mentioned macro exists before including the 
 * next code in the process of compilation.
 * The define can be provided during the compilation command using -D flag.
*/


/*
//Example 1
#include<stdio.h>
// #define DEBUG 0
int max(int x, int y) 
{ 
    return x > y ? x : y; 
}

int greatest_of_3(int x, int y, int z) 
{
    x = max(x, y);
    #ifdef DEBUG
        printf("Value of x is %d\n", x);
    #endif
    x = max(x, z);
    #ifdef DEBUG
        printf("Value of x is %d\n", x);
        printf("Value of DEBUG: %d\n", DEBUG);
    #endif
    return x;
}

int main() 
{
    int m3 = greatest_of_3(10, 20, 30);
    printf("Largest = %d\n", m3);
    return 0;
}
*/

// /*
//Example 2
#include <stdio.h>
// #define NUMBER 1
int main()
{
    #ifdef NUMBER
        printf("NUMBER = %d\n", NUMBER);
    #else
        printf("NUMBER is not provided.\n");
    #endif

    printf("This is just an example.\n");

    #ifndef NUMBER
        printf("NUMBER is not provided.\n");
    #else
        printf("NUMBER = %d\n", NUMBER);
    #endif
    
    return 0;
}
// */