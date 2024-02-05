#include <stdio.h>

int main()
{
    int side, area;

    printf("lenght: ");
    scanf("%d", &side);

    area = side*side;

    printf("area of square with side %d is %d\n", side, area);
}