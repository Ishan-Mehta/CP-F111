#include<stdio.h>

int sum_arr(int arr[5], int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += *(arr + i);
    }

    return sum;    
}

int main()
{
    int arr[5] = {10, 20, 30, 40 ,50};
    printf("Sum:\t%d\n", sum_arr(arr, 5));
}