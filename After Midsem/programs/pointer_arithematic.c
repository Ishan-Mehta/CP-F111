#include<stdio.h>


int main()
{
    int *x1, *x2;
    char *c1, *c2;

    int x = 255;
    char c = 'A';
    x1 = &x;
    c1 = &c;

    printf("x1: %p, c1: %p\n", x1, c1);
    printf("x1: %d, c1: %c\n", *x1, *c1);

    c2 = c1 + 1;

    printf("x2: %p, c2: %p\n", x2, c2);
    printf("x2: %d, c2: %c\n", *x2, *c2);

    printf("x1: %p, c1: %p\n", x1, c1);
    printf("x1: %d, c1: %c\n", *x1, *c1);
}
