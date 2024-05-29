/*
# include <stdio.h>
void fun(int *ptr)
{
    *ptr = 30;
}
 
int main()
{
  int y = 20;
  fun(&y);
  printf("%d\n", y);
 
  return 0;
}
*/

/*
#include <stdio.h>
 
int main()
{
    int *ptr;
    int x;
 
    ptr = &x;
    *ptr = 0;
 
    printf(" x = %d\n", x);
    printf(" *ptr = %d\n", *ptr);
 
    *ptr += 5;
    printf(" x  = %d\n", x);
    printf(" *ptr = %d\n", *ptr);
 
    (*ptr)++;
    printf(" x = %d\n", x);
    printf(" *ptr = %d\n", *ptr);
 
    return 0;
}
*/

/*
#include <stdio.h>
 
int main()
{
    int arri[] = {1, 2 ,3};
    int *ptri = arri;
 
    char arrc[] = {1, 2 ,3};
    char *ptrc = arrc;
 
    printf("sizeof arri[] = %d\n", (int)sizeof(arri));
    printf("sizeof ptri = %d\n", (int)sizeof(ptri));
 
    printf("sizeof arrc[] = %d\n", (int)sizeof(arrc));
    printf("sizeof ptrc = %d\n", (int)sizeof(ptrc));
 
    return 0;
}
*/

/*
#include <stdio.h>
 
int main()
{
    double arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
    double *ptr1 = &arr[0];
    double *ptr2;
    ptr2 = ptr1 + 3;
 
    printf("%lf\n", *ptr2);
    printf("%d\n", (int)(ptr2 - ptr1));
 
   return 0;
}
*/

/*
#include<stdio.h>
int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60};
    int *ptr1 = arr;
    int *ptr2 = arr + 5;
    printf("Number of elements between two pointer are: %d\n", 
                                (int)(ptr2 - ptr1));
    printf("Number of bytes between two pointers are: %d\n",  
                              (int)((char*)ptr2 - (char*)ptr1));
    return 0;
}
*/

/*
#include<stdio.h>
int main()
{
 char *ptr = "CPisFUN";
 printf("%c\n", *&*&*ptr);
 return 0;
}
*/

/*
#include<stdio.h> 
void f(int *p, int *q) 
{ 
    p = q; 
    *p = 2; 
} 
 
int main() 
{ 
    int i = 0, j = 1;
    f(&i, &j); 
    printf("%d %d\n", i, j); 
    return 0; 
}
*/

/*
#include<stdio.h>
 
void swap (char *x, char *y)
{
    char *t = x;
    x = y;
    y = t;
}
 
int main()
{
    char *x = "CPisFun";
    char *y = "PointersAreBetter";
    char *t;
    swap(x, y);
    printf("(%s, %s)", x, y);
    t = x;
    x = y;
    y = t;
    printf("\n(%s, %s)\n", x, y);
    return 0;
}
*/

/*
#include <stdio.h>
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int *p = arr;
    ++*p;
    printf("%d\n", *p);
    p += 2;
    printf("%d\n", *p);
    return 0;
}
*/

/*
#include<stdio.h>
void mystery(int *ptra, int *ptrb) 
{
   int *temp;
   temp = ptrb;
   ptrb = ptra;
   ptra = temp;
}
int main() 
{
    int a=2016, b=0, c=4, d=42;
    mystery(&a, &b);
    printf("%d\n", a);
    if (a < c)
       mystery(&c, &a);
    printf("%d\n", a);
    mystery(&a, &d);
    printf("%d\n", a);
}
*/

/*
#include<stdio.h>

void f(int* p, int m)
{
    m = m + 5;
    *p = *p + m;
    return;
}
void main()
{
    int i=5, j=10;
    f(&i, j);
    printf("%d\n", i+j);
}
*/

/*
#include<stdio.h>
void printxy(int x, int y)
{
    int *ptr;
    x = 0;
    ptr = &x;
    y = *ptr;
    *ptr = 1;
    printf("%d,%d\n", x, y);
}
int main()
{
    printxy(1,1);
    return 0;
}
*/

/*
#include<stdio.h>
int main()
{
    char g[] = "CPisTheBest";
    printf("%s\n", g + g[6] - g[8]);
    return 0;
}
*/

/*
#include<stdio.h> 
int main() 
{ 
   int x = 1, z[2] = {10, 11}; 
   int *p; 
   p = &x; 
   *p = 10; 
   p = &z[1]; 
   *(&z[0] + 1) += 3; 
   printf("%d, %d, %d\n", x, z[0], z[1]); 
   return 0; 
}
*/