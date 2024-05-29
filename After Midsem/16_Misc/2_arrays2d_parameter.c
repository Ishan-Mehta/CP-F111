#include<stdio.h>
/*
// void display(int arr[2][3])
// void display(int arr[][3])
void display(int (*arr)[3])
{
    printf("\nDisplaying elements: \n");
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\nDisplaying elements by pointer notation: \n");
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d ", *(*(arr+i)+j));
        }
        printf("\n");
    }
}
*/
// /*
void display1(int *arr)
{
    printf("\nDisplaying elements by pointer notation: \n");
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d ", *(arr+3*i+j));
        }
        printf("\n");
    }
}
// */

int main()
{
    int arr[2][3] = {{1,2,3},{4,5,6}};
    //display(arr);
    display1(&arr[0][0]);
    return 0;
}