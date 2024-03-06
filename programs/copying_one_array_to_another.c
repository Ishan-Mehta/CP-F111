#include<stdio.h>

int main()
{
    int nums[] ={2, 3, 5, 6, 2, 4, 56, 3};

    int *arr = nums;
    printf("%d: %p\n%d: %p\n", nums, &nums, arr, &arr);
    // 6422272: 0061FF00
    // 6422272: 0061FEFC
    
    printf("%d %d\n%d %d\n", sizeof(nums) ,sizeof(nums)/sizeof(nums[0]), sizeof(arr) ,sizeof(arr)/sizeof(arr[0]));
    // 32 8
    // 4 1
    
    for (int i = 0; i < 8; i++)
    {
        printf("nums[%d]: %d\t", i, nums[i]);
        printf("arr[%d]: %d\n", i, arr[i]);
    }
    // nums[0]: 2      arr[0]: 2
    // nums[1]: 3      arr[1]: 3
    // nums[2]: 5      arr[2]: 5
    // nums[3]: 6      arr[3]: 6
    // nums[4]: 2      arr[4]: 2
    // nums[5]: 4      arr[5]: 4
    // nums[6]: 56     arr[6]: 56
    // nums[7]: 3      arr[7]: 3
    
    return 0;
}