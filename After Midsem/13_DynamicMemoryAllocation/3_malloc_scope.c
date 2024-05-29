/*
THINGS TO NOTE :
      1. There are multiple programs running simultaneously on your machine.

      2. When your program is allocated memory, the system ensures that the
        memory allocated to you is currently not being used by other programs.

      3. Once your program is done using some memory, the system `deallocates'
        the above allocated memory.

      4. If your program attempts to access (read/write) memory that has not
       been allocated to your program, then the system interrupts your
       programs with "Segmentation Fault" error. 
       This memry is ften called stack memory.
*/

#include <stdio.h>
#include <stdlib.h> // Library for using malloc(), free()
typedef int * intPtr;

intPtr f()    // Same as int * f(void){.......}
{
  int x = 10;
  return &x;
  /*
  Address        Data      Variable Name     Type
 +----------+-----------+-----------------+-----------+
 +  1001    +    10     +       x         +  int
 +----------+-----------+-----------------+-----------+
  */
  // Addresses of local variables deallocated on exiting the scope.
}

intPtr g()
{
  int *x;
  x = (int*)malloc(sizeof(int));
  *x = 20;

  printf("x = %p, *x = %d\n", x, *x);
  return x;

  /*
  Address        Data      Variable Name     Type
  +----------+-----------+-----------------+-----------+
  +  1100    +    1200   +       x         +  int *
  +----------+-----------+-----------------+-----------+
  +  1200    +    20     +        ?        +  int
  +----------+-----------+-----------------+-----------+

  - The above function call to 'malloc' does the following:
        - Allocate a continuous region of 'sizeof(int)' bytes in heap memory
        - Return the start address of the allocated memory
  - The address returned is type cast to (int *) - can be done explicitly or implicitly.
  - The allocated memory has 'global scope', that is, it is not deallocated when you leave a local scope.

  - Addresses of local variables deallocated on exiting the scope,
    that is, after function call to 'g()', '1100' is freed.
    
  - Address allocated by malloc ('1200') remains even after the call to 'g()' 
  */
}

int main()
{
  // intPtr y = f();
  // printf("*y = %d\n",*y); // Could Result in segmentation fault

// /*
  intPtr z = g();
  printf("z = %p, *z = %d\n", z, *z);

  free(z);

  printf("z = %p, *z = %d\n", z, *z);
// */  
    /*
    - The function call 'free' deallocates the memory starting at an address.
    - Accessing deallocated memory leads to interruption.
    */
// /*
  z = NULL; //Good practice: saves NULL as the value of z, so that it stops pointing to the freed up space.
  printf("z = %p, ", z);
  printf("*z = %d\n", *z);
// */ 
  return 0;
}