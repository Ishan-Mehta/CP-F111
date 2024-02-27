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

int SwapAdjacentElements(int arr[], int n)
{
    int swapped = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            SwapElements(arr, i, i + 1);
            swapped = 1;
        }
    }
    PrintArray(arr, n);
    
    return swapped;
}

void ShiftElements(int arr[], int n, int correct_index, int current_index)
{
    int number_to_replace = arr[current_index];

    for (int i = current_index; i > correct_index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[correct_index] = number_to_replace;

    PrintArray(arr, n);    
}

int FindMaxElementIndex(int arr[], int n)
{
    int max = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[max])
            max = i;
    }

    return max;
}

int CheckCorrectIndex(int arr[], int current_index)
{
    int correct_index = current_index;

    for (int i = current_index; i > 0; i--)
    {
        if (arr[current_index] < arr[i - 1])
            correct_index = i - 1;        
    }

    return correct_index;   
}

/* ----------------------------------------------------------------------------
 Bubble Sort:
 Helper functions:
    * int SwapAdjacentElements(int arr[], int n)
    * void SwapElements(int arr[], int ind1, int ind2)
    * void PrintArray(int arr[], int n)    
 ------------------------------------------------------------------------------*/
void BubbleSort(int arr[], int n)
{
    printf("Unsorted Array: ");
    PrintArray(arr, n);
    
    for (int i = 0; i < n; i++)
    {
        if (!SwapAdjacentElements(arr, n - i))
            break;
    }

    printf("Sorted Array: ");
    PrintArray(arr,n);
}

/* ----------------------------------------------------------------------------
 Selection Sort:
 1.Find the position of the maximum number.
 2.Swap it with the last element in the array.
 3.Then find the position of the second highest number and swap it with the second last element.
 4.Repeat this n times and the array will be sorted in ascending order.
 Helper functions:
    * int FindMaxElementIndex(int arr[], int n)
    * void SwapElements(int arr[], int ind1, int ind2)
    * void PrintArray(int arr[], int n)
-------------------------------------------------------------------------------*/
void SelectionSort(int arr[], int n)
{
    printf("Unsorted Array: ");
    PrintArray(arr, n);
    
    for (int i = 0; i < n; i++)
    {
        int index_of_max = FindMaxElementIndex(arr, n - i);
        if (index_of_max != n - (i + 1))    
        {
            SwapElements(arr, index_of_max, n - (i + 1));
            PrintArray(arr, n);
        }
    }

    printf("Sorted Array: ");
    PrintArray(arr,n); 
}

/* ------------------------------------------------------------------------------
 Insertion Sort:
 Helper functions:
    * int CheckCorrectIndex(int arr[], int current_index)
    * void ShiftElements(int arr[], int n, int correct_index, int current_index)
    * void PrintArray(int arr[], int n)
---------------------------------------------------------------------------------*/
void InsertionSort(int arr[], int n)
{
    printf("Unsorted Array: ");
    PrintArray(arr, n);

    for (int i = 0; i < n; i++)
    {
        int correct_index = CheckCorrectIndex(arr, i);
        if (correct_index != i)
            ShiftElements(arr, n, correct_index, i);
    }
    printf("Sorted Array: ");
    PrintArray(arr,n); 
}

int main() //Do not change main
{
    int arr1[]={6,4,6,7,3,9,1,10,5,0};
    int arr2[]={10,9,8,7,6,5,4,3,2,1};

    int option;
    do
    {
        printf("Enter 1 for Bubble Sort, 2 for Selection Sort and 3 for Insertion Sort\n");
        scanf("%d", &option);
    }
    while (option < 1 || option > 3);
    
    
    switch (option)
    {
    case 1:
        BubbleSort(arr1, 10);
        BubbleSort(arr2, 10);
        break;
    
    case 2:
        SelectionSort(arr1, 10);
        SelectionSort(arr2, 10);
        break;
    
    case 3:
        InsertionSort(arr1,10);
        InsertionSort(arr2,10);
        break;
    
    default:
        printf("Incorrect Option!\n");
        break;
    }

    return 0;
}