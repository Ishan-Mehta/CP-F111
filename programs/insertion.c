#include <stdio.h>

void PrintArray(int arr[], int n)  //Function to print the array. Do not change this
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void SwapElements(int arr[], int ind1, int ind2)
{
    int temp = arr[ind1];
    arr[ind1] = arr[ind2];
    arr[ind2] = temp;
}

void ShiftElements(int arr[], int correct_index, int current_index)
{
    
}

/*int FindMaxElementIndex(int arr[], int n)
{
    int max = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[max])
            max = i;
    }

    return max;
}*/

int CheckCorrectIndex(int arr[], int n, int current_index)
{
    int correct_index = current_index;

    for (int i = current_index; i > 0; i--)
    {
        if (arr[current_index] < arr[i - 1])
            correct_index = i - 1;        
    }

    printf("%d %d : %d %d\n", current_index, correct_index, arr[current_index], arr[correct_index]);
    return correct_index;   
}

/* ----------------------------------------------------------------------------
 Implement Selection Sort on the array to sort in ascending order:

 1.Find the position of the maximum number.
 2.Swap it with the last element in the array.
 3.Then find the position of the second highest number and swap it with the second last element.
 4.Repeat this n times and the array will be sorted in ascending order.
-------------------------------------------------------------------------------*/

void InsertionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int correct_index = CheckCorrectIndex(arr, n, i);
        if (correct_index != i)
        {
            ShiftElements(arr, correct_index, i);
        }    
            //SwapElements(arr, correct_index, i);
    }
    
    PrintArray(arr,n); 
}

int main() //Do not change main
{
    int arr1[]={6,4,6,7,3,9,1,10,5,0};
    int arr2[]={10,9,8,7,6,5,4,3,2,1};

    InsertionSort(arr1,10);
    InsertionSort(arr2,10);

    return 0;
}