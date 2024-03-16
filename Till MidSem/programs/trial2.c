#include<stdio.h>
#include<string.h>

int main()
{
    char str3[5];
    scanf("%[^\n]s", str3);
    printf("%s\n", str3);
    printf("%d\n", strlen(str3));
}