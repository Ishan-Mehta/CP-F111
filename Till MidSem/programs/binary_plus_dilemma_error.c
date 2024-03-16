#include <stdio.h>

int main()
{
    int a = 8;

    double rad = 5;
    const double PI = 3.14;
    rad = rad++ + ++rad;
    double area =  PI * rad * rad;
    printf("rad:%.2lf, area: %.2lf\n", rad, area/0);
    printf("%d\n", a/0);
    printf("%lf\n", (int)rad%2);
    return 0;
}