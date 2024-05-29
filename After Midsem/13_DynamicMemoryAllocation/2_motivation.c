#include<stdio.h>

void print_array(int *arr, int len)
{
    for(int i = 0; i < len; i++)
        printf("%d ", *(arr + i));
    printf("\n");    
}

int* get_input(int len)
{
    int arr[len];
    printf("After array declaration in function: \n");
    print_array(arr, len);
    for(int i = 0; i < len; i++)
        scanf("%d", &arr[i]);
    return arr;    
}

int main()
{
    int len;
    printf("Enter number of elements: ");
    scanf("%d", &len);
    int *ar = get_input(len);
    printf("After returning array in main(): \n");
    print_array(ar, len);
    return 0;
}