#include<stdio.h>
#include<string.h>

char *reverse(char *inp)
{
    printf(": current inp: %s, ", inp);
    int len = strlen(inp);
    printf("length: %d\n", len);

    // printf("Before swapping: 1st char: %c, last char: %c\n", inp[0], inp[len - 1]);

    char c_tmp = inp[0];
    inp[0] = inp[len - 1];
    inp[len - 1] = c_tmp;

    // printf("After swapping: 1st char: %c, last char: %c\n", inp[0], inp[len - 1]);

    if (len <= 2)
        return inp;

    char shorten[len - 1];
    strncpy(shorten, inp+1, len-2);
    shorten[len - 2] = '\0';
    // printf("\tshorten after strncpy() & null termination: %s\n", shorten);

    char *shortened = reverse(shorten);

    // printf("inp before strncpy(): %s\n", inp);
    strncpy(inp+1, shortened, len - 2);
    printf("current inp rev: %s\n", inp);

    return inp;
}

int main() // int c, char ** args
{
    char s[100];
    scanf("%s", s);
    printf("%lu", &*s);
    char *rev = reverse(s); // reverse(args[1]);

    printf("%s %s\n", s, rev);
}