#include<stdio.h>

void print_array(int *nums, int length)
{
    for (int i = 0; i < length; ++i)
        printf("%d ", nums[i]);//Can also write as   printf("%d ", *(nums + i));
    printf("\n");
}

void print_cumulative_sum(int *nums, int length)
{
    for (int i = 1; i < length; ++i)
        nums[i] += nums[i - 1];
    print_array(nums, length);
}

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    printf("Array elements are: ");
    print_array(arr, 5);//Can also write as   print_array(&arr[0], 5);
    printf("Cumulative sum array: ");
    print_cumulative_sum(arr, 5);
    return 0;
}