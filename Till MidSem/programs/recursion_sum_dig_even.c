#include<stdio.h>

int is_even(int n)
{
    return n % 2 == 0;
}

int is_sum_of_digits_even(int n)
{
    if (n / 10 == 0)
        return is_even(n);
    
    int last_digit = n % 10;
    if (is_even(last_digit))
        return is_sum_of_digits_even(n / 10);
    else
        return !is_sum_of_digits_even(n / 10);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", is_sum_of_digits_even(n));
}