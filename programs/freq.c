#include<stdio.h>


int HighestFrequency(int arr[], int n)
{
    int max_count = 0;
    /* SHORTER METHOD PENDING 
    int distinct_numbers[n], num_of_distinct = 0;
    
    for (int i = 0; i < n; i++)
    {
        int number_exists = 0, count = 1;
        for (int j = 0; i < num_of_distinct; i++)
        {
            if (arr[i] == arr[j])
            {
                number_exists = 1;
                count++;
            }
        }
        if (count > max_count)
            max_count = count;
        if (!number_exists)
        {
            distinct_numbers[num_of_distinct] = arr[i];
            num_of_distinct++;
        }
    }*/

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = i; j < n; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }
        if (count > max_count)
            max_count = count;        
    }
    
    return max_count;
}


int main()
{
    int arr1[]={6,4,6,7,3,9,1,10,5,0};
    int arr2[]={10,9,8,7,6,5,4,3,2,1};

    printf("For arr1 : %d\n", HighestFrequency(arr1, 10));
    printf("For arr2 : %d\n", HighestFrequency(arr2, 10));
    return 0;
}