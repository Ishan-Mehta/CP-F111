#include <stdio.h>
int main()
{
    long int n = 123456789;
 
    printf("While printing ");
    printf(", the value returned by printf() is : %d", printf("heloo %ld", n));

    char a[100], b[100], c[100];
 
    // scanf() with one input
    printf("\n First scanf() returns : %d",
                            scanf("%s", a));
 
    // scanf() with two inputs
    printf("\n Second scanf() returns : %d",
                       scanf("%s%s", a, b));
 
    // scanf() with three inputs
    printf("\n Third scanf() returns : %d", 
                  scanf("%s%s%s", a, b, c));
 
    return 0;
}