#include<stdio.h>

void display(int arr[2][3])
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


    printf("\nDisplaying element addresses: \n");
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%p ", &arr[i][j]);
        }
        printf("\n");
    }

    printf("\narr = %p\n", arr);
    printf("arr + 1 = %p\n", arr + 1);

    printf("\nDisplaying row addresses: \n");
    for(int i = 0; i < 2; i++)
        printf("arr[%d] = %p\n", i, &arr[i]);

    printf("\nDisplaying elements: \n");
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d ", *(*(arr+i)+j));
            //OR 
            //printf("%d ", *(arr[i]+j));
        }
        printf("\n");
    }
}

int main()
{
    int arr[2][3] = {{1,2,3},{4,5,6}};
    display(arr);
    return 0;
}