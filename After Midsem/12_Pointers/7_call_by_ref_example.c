/*
Write a program which tells you how many 
2000/-, 500/-, 200/- and 100/- notes 
should be dispensed from an ATM machine?

A function should solve this 
such that main() can print the result.
*/

#include<stdio.h>

void dispense(int a, int *a20, int *a5, int *a2, int *a1)
{
    *a20 = a / 2000;
    a = a % 2000;
    *a5 = a/500;
    *a2 = (a%500)/200;
    a = a%500;
    *a1 = (a%200)/100;
}

int main()
{
    int amt;
    printf("Enter the amount: ");
    scanf("%d", &amt);
    int a2000, a500, a200, a100;
    dispense(amt, &a2000, &a500, &a200, &a100);
    printf("2000/- notes: %d\n", a2000);
    printf("500/- notes: %d\n", a500);
    printf("200/- notes: %d\n", a200);
    printf("100/- notes: %d\n", a100);
    return 0;
}