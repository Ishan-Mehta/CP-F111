#include<stdio.h>
#include<stdlib.h>

int** allocate(int rows, int cols)
{
    int ** m = malloc(rows*sizeof(int*));
    for(int i = 0; i < rows; i++)
    {
        m[i] = calloc(cols, sizeof(int)); //OR *(m+i)
        for(int j = 0; j < cols; j++)
        {
            printf("Enter array[%d][%d]: ", i, j);
            scanf("%d", &(*(*(m+i)+j))); // OR scanf("%d", &m[i][j]);
        }
    }
    return m;
}

void display(int** m, int rows, int cols)
{
    printf("\nDisplaying elements: \n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%d ", *(*(m+i)+j));
            //OR 
            //printf("%d ", *(m[i]+j));
        }
        printf("\n");
    }
}

void release_memory(int **m, int rows, int cols)
{
    for(int i = 0; i < rows; i++)
        free(m[i]);
    free(m);
    printf("Heap Memory Freed\n");
}

int main()
{
    int r, c;
    printf("Enter the number of rows and columns:\n");
    scanf("%d", &r);
    scanf("%d", &c);
    int** m = allocate(r,c);
    display(m, r, c);
    release_memory(m, r, c);
    return 0;
}