#include<stdio.h>

void test();

int main()
{
    int x = 1;
    printf("1st: x = %d\n", x);

    if (x == 1)
    {
        x = 2;
        int y = 1;
        printf("2nd: x = %d, y = %d\n", x, y);
    }
    test();
    printf("3rd: x = %d\n", x);
    //printf("3rd: x = %d, y = %d\n", x, y);
    return 0;
}

void test()
{
    int x;
    printf("x = %d\n", x);
}