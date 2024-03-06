#include<stdio.h>

void takeInputArray(int arr[], int size)
{
    //arr = {6,4,6,7,3,9,1,10,5,0};
}

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

void MergeSort(int arr[], int size)
{
    printf("Unsorted Array: ");
    PrintArray(arr, size);

    if (size == 1)
        return;
    if (size == 2)
    {
        if (arr[0] > arr[1])
            SwapElements(arr, 0, 1);
        PrintArray(arr, 2);
        return;
    }

    int smaller_size = (size + 1) / 2;
    MergeSort(arr, smaller_size);
    MergeSort(arr + smaller_size, size - smaller_size);

    for (int i = smaller_size; i < size; i++)
    {
        int correct_index = CheckCorrectIndex(arr, i);
        ShiftElements(arr, i, correct_index, i);
    }
    
    printf("Sorted Array: ");
    PrintArray(arr,size); 
}

int main()
{
    int size = 10;
    //printf("Enter the size of the array: ");
    int arr[] = {6,4,6,7,3,9,1,10,5,0};
    //takeInputArray(arr, size);
    printf("Length of the array: %d/%d = %d == %d\n", sizeof(arr), sizeof(arr[0]), sizeof(arr)/sizeof(arr[0]), size);
    
    MergeSort(arr, size);
}