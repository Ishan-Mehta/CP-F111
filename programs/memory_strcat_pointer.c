#include<stdio.h>
#include<string.h>

int main()
{
    char cp1[8] = "arrays";
    char cp2[10] = "strings";

    printf("%d, %d, pointer (cp1): %p, %p\n", cp1, &cp1, cp1, &cp1);
    printf("%d, %d, pointer (cp2): %p\n", cp2, &cp2, cp2);

    printf("pointer: %p\n", *cp1);
    printf("pointer: %p\n", *cp2);

    printf("STRCAT DONE");

    strcat(cp2, cp1);
    printf("%s, %s\n", cp1, cp2);

    printf("%d, %d, pointer: %p\n", cp1, &cp1, cp1);
    printf("%d, %d, pointer: %p\n", cp2, &cp2, cp2);

    for (int i = 0; cp1[i] != '\0'; i++)
    {
        printf("cp1: %d: %c, pointer: %p\n", &cp1[i], cp1[i], *cp1);
    }
    
    for (int i = 0; cp2[i] != '\0'; i++)
    {
        printf("cp2: %d: %c\n", &cp2[i], cp2[i]);
    }
    
}