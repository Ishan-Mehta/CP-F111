#include <stdio.h>

int num_of_digits(int n)
{
    if (n == 0)
        return 0;
    
    return 1 + num_of_digits(n / 10);
}

int main()
{
    int n;
    scanf("%d", &n);

    printf("%d\n", num_of_digits(n));
    return 0;
}