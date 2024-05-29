#include<stdio.h>
#include<stdlib.h>


int main()
{
    int *pt = malloc(sizeof(int)*2);

    pt[0] = 23;
    pt[1] = 43;

    printf("%d %d %d\n", pt[0], pt[1], pt[2]);

    free(pt);
    printf("%d %d %d\n", pt[0], pt[1], pt[2]);

}