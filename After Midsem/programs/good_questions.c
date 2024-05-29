#include<stdio.h>
#include<stdlib.h>

// /*
//What is the output?
void test (char *str)
{
    
    printf ("%c", *str ) ;
    if (* str == 'C')
        return ;
    if (*str >= 'A' && *str <= 'Z')
        test(str + 2) ;
    else
        test(++str ) ;
    printf ("%c" , *str ) ;
}
int main ()
{
    char str [] = "ProgRamInC";
    test(str) ;
    return 0;
}
// */