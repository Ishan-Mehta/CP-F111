#include<stdio.h>

int fibo(int n, char direction)
{
    if (n < 1)
        return 0;
    if (n == 1)
    {
        if (direction == 'L')
            printf("1 ");
        return 1;
    }    
    
    int sum = fibo(n - 1, (direction == 'L')? 'L': 'R') + fibo(n - 2, 'R');
    if (direction == 'L')
        printf("%d ", sum);
    
    return sum; 
}

int main()
{
    int n;
    scanf("%d", &n);
    int fibo_number = fibo(n, 'L');
    printf("\n");
    // printf("%d\n", fibo(n));
}