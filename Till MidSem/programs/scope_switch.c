#include<stdio.h>

int main()
{
    int i = 1;
    int x = 5;
    x = 4;

    if (3 > 2)
    {
        int i = 4;
        x = 3;
    }
    
    switch (i)
    {
    case 2 ... 9:
        printf("allowed\n");
        break;
    
    default:
    printf("nope\n");
        break;
    }
    
    return 0;
}