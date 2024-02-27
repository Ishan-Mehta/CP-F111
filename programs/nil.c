#include <stdio.h>
#include <math.h>

int count(int n){
    int cunt;
    if (n>0)
    return cunt = 1 + count(n/10);
    else
    return 0;
}

int main(){
    int n;
    printf("Enter a Number\n");
    scanf("%d",&n);
    printf("The number of digits are %d",count (n));

}