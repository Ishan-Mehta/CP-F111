#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

bool what_do_i_do(char *s)
{
    while (!isdigit(*s) && *s != '\0')
        s++;
    return isdigit(*s);
}

int main()
{
    char s[20];
    printf("Enter a string: ");
    scanf("%s", s);
    printf("%d\n", what_do_i_do(s));
    return 0;
}

//Check if there is a digit in the string or not.