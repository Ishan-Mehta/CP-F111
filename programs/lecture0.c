#include <stdio.h>


int main ()
{
    char c1, c2, c3;
    
    scanf("%c", &c1);
    getchar();
    scanf("%c", &c2);
    getchar();
    getchar();
    scanf("%c", &c3);

    printf("%c\n%c\n%c\n", c3, c2, c1);

    return 0;
}

