#include<stdio.h>

int *denominations(int amount)
{
    int *arr[4];
    *arr[0] = amount / 2000;
    *arr[1] = (amount % 2000) / 500;
    *arr[2] = (amount % 500) / 200;
    *arr[3] = ((amount % 500) % 200) / 100;

    return *arr;
}

int main()
{
    int amount;
    scanf("%d", &amount);
    int *denoms[4];
    printf("%x\n", denoms);
    *denoms = denominations(amount);
    printf("2000: %d\n", *denoms[0]);
    printf("500: %d\n", *denoms[1]);
    printf("200: %d\n", *denoms[2]);
    printf("100: %d\n", *denoms[3]);
}