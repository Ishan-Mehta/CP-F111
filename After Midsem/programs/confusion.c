#include<stdio.h>


typedef int *** matrix[10][10][10];

int main()
{
    int **mat = (int **)malloc(30*(sizeof(int)));
    // int *x = (int*)malloc(sizeof(int[23]));
    printf("matrix size: %lu\n", sizeof(matrix));
    printf("int*** size: %lu\n", sizeof(int ***));
    // printf("x size: %lu\n", sizeof(x));
    // printf("*x size: %lu\n", sizeof(*x));
    // free(x);
    // x = NULL;

    printf("mat size: %lu\n", sizeof(mat));
    printf("int** size: %lu\n", sizeof(int **));
    printf("**mat size: %lu\n", sizeof(*mat));
    printf("mat: %p, *mat: %p\n", mat, *mat);
    printf("mat: %p, *mat: %p\n", mat, *mat);

    **mat = 5;

    int *x = 0x0;
    printf("*x: %d\n", *x);
    printf("**mat: %d\n", **mat);

    free(mat);
}