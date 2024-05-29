#include<stdio.h>
#include<stdlib.h>

void print_array(int *arr, int len)
{
    for(int i = 0; i < len; i++)
        printf("%d ", *(arr + i));
    printf("\n");    
}

int* get_input(int len)
{
    int *arr = calloc(len,sizeof(int));
    /*
        - calloc() allocates the memory and also initializes every byte in the allocated memory to 0.
        - calloc() takes two arguments:
            1. Number of blocks to be allocated. 
            2. Size of each block in bytes.
    */
    printf("After array declaration in function: \n");
    print_array(arr, len);
    for(int i = 0; i < len; i++)
        scanf("%d", &(*(arr+i)));
    return arr;    
}

int main()
{
    int len;
    printf("Enter number of elements: ");
    scanf("%d", &len);
    int *arr = get_input(len);
    printf("After returning array in main(): \n");
    print_array(arr, len);
    free(arr);
    printf("After freeing up array in main(): \n");
    print_array(arr, len);
    return 0;
}