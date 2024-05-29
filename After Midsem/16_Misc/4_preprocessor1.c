/**
 * #include, #define are preprocessor directives
 * #define FILENAME_MAX 1024 ----> is NOT a CONST
 * CONST are handled by compiler, can be type checked, ends with a semicolon
 * #define Macros are handled by a preprocessor, does not end with a semicolon
*/

/*
//Example 1

#include <stdio.h>
#define ARNAB 65.0
#define abc 97
const int LUCKY = 13;
int main()
{
    printf("ARNAB is %.1lf %d\n", ARNAB, ARNAB); //---> be careful with types
    printf("abc is %d %c %.1lf\n", abc, abc, abc);
    // int abc = 10; //---->Will be wrong
    printf("LUCKY is %d\n", LUCKY);
    // LUCKY = 20;//----> Will be wrong
    return 0;
}
*/

// /*
//Example 2 -- can have functions as macros. arguments are not checked for datatypes
#include <stdio.h>
#define FUNCTION(x) ++x
int main()
{
    char* str = "CP is the best!";
    int n = 20;
    printf("%s\n", FUNCTION(str));
    printf("%d\n", FUNCTION(n));
    return 0;
}
// */

/*
//Example 3
#include <stdio.h>
#define square(x) x * x
int main()
{
    int test = 25 / square(5);
    printf("%d", test);
    return 0;
}
*/