#include<stdio.h>

int x = 3; 

int test(int x)
{
    printf("1st: Inside test(): x = %d\n", x);
    x = 2;
    printf("2nd: Inside test(): x = %d\n", x);
    return x;
}

int main()
{
    int x = 45;
    printf("1st: Inside main(): x = %d\n", x);
    x = test(x);
    printf("2nd: Inside main(): x = %d\n", x);

    return 0;
}