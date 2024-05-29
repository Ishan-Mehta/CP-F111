/**
 * Enums are user-defined datatypes that is primarily used to assign names to integers.
 * They are majorly used to improve code readability.
 * 
 * Syntax:
 *          enum enum_type{constant1, constant2, constant3, ....... };
 * By default; value of constant1 will be 0 and value of constant(x) will be value of constant(x-1) + 1
 * 
 * You can also change the default start from 0 to any other integer by assigning constant1 to some other integer.
 *      Example:
 *           enum enum_type{constant1 = 2, constant2, constant3, ....... };
 * 
 * You can perform arithmetic, relational, assignment operations on them.
*/


#include<stdio.h>

/*
typedef enum weekdays
{
    mon, tue, wed, thu, fri, sat, sun
}day;
*/

/*
typedef enum 
{
    mon = 1, tue, wed, thu, fri, sat, sun
}day;
*/

// /*
typedef enum 
{
    mon = 1, tue, wed, thu = 7, fri, sat, sun
}day;
// */

day tomorrow (day); //Function Declaration

int main()
{
    day d;

    printf("Enter today's day as an integer (starting with Monday as 1): ");
    scanf("%d", &d);
    
    printf("mon = %d\n", mon);
    printf("sat = %d\n", sat);

    if (d < sat)
    {
        printf("It's not the weekend. :( ");
        printf("%d more days to the weekend!\n", sat - d);
    }

    printf("Tomorrow is: %d\n", tomorrow(d));

    //enums can be used as array subscripts
    int earnings[5];
    for(int i = mon; i < sat; i++)
    {
        earnings[i] = 100;
    }
    printf("earnings[tue] = %d\n", earnings[tue]);

    return 0;
}

day tomorrow(day d) //Function Definition
{
    //enums can be used in relational and arithmetic operations
    return d == sun ? mon : d + 1;
}