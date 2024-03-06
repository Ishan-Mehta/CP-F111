#include<stdio.h>

int SecondMinimum(int arr[], int n)
{
    int min = arr[0], min2 = arr[1];
    for (int i = 0; i < n; i++)
    {
        if (min > arr[i])
        {
            min2 = min;
            min = arr[i];
        }
    }
    
    return min2;
}

int main()
{
    int arr[] = {0,1,7,786,0,2,5,32};
    int second_min = SecondMinimum(arr, 8);

    printf("%d\n", second_min);
}