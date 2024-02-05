#include <stdio.h>


int main()
{
    printf("hi\n");
    //printf("%d\n", 3/0);
    sum_int(10, 21);

    printf("hatt\n");
}

void sum_int(int a, int b)
{
    printf("%d\n", a+b);
}