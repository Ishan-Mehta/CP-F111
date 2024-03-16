#include<stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};

    printf("%u\t%u\t%u\t%u\n", arr, arr+1, &arr+1, &arr);
}