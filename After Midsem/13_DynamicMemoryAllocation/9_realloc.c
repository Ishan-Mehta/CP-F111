/*
Using realloc function, we can resize the memory area 
which is already created by malloc or calloc.

Syntax:
realloc(ptr, new size);

    ptr - the name of the pointer variable which needs to be resized.
    new size - the new size of the memory area. It can be smaller or bigger than the actual size.
*/

#include<stdio.h>
#include<stdlib.h>

/*
//To resize to smaller memory
int main()
{
    int *ptr;
    ptr = malloc(10 * sizeof(int));
    //realloc memory size to store only 5 integers
    ptr = realloc(ptr, 5 * sizeof(int));

    return 0;
}
*/

// /*
//To resize to a larger memory
int main()
{
        
    int *ptr,i;

    //allocating memory for only 1 integer
    ptr = malloc(sizeof(int));

    ptr[0] = 1;

    //realloc memory size to store 3 integers
    ptr = realloc(ptr, 3 * sizeof(int));

    //If it is possible it will simply resize the memory.

    //Otherwise, realloc will create the new block of memory with the larger size
    //and copy the old data to that newly allocated memory and 
    //then it will deallocate the old memory area.

    ptr[1] = 2;
    ptr[2] = 3;

    //printing values
    for(i = 0; i < 3; i++)
          printf("%d\n",ptr[i]);

    return 0;
}
// */