/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

    //printf("foo %p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];

    //printf("bar %p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
        printf("main %d\n", array[i]);
    }

    return 0;
}

/* 1. foo() allocates memory for an array of size 5. Then it prints the address to
the allocated memory, sets each value in the array to 42 and (in theory) returns
 the result. bar() also initializes an array with size 5. Then it fills each
 spot in the array with i (0, 1, 2, 3, 4) and returns nothing. main() allocates
 memory for a pointer called array, which should theoretically point to the same
 array that foo()'s returned pointer points to (the array of 42's). If the
 program was running properly, it would print the values of array from foo() (so
42 would be printed 5 times).
2.When compiling, I get a warning from foo(): "function returns address of local
 variable" which means that once the function completes, the address of the
 local variable is no longer correct and could lead to issues later on due to
 the fact that the variable is stored in the stack.

 3. When running the code, the program successfully prints the addresses of the
 arrays created in foo() and bar(). Then it throws a Segmentation fault and
 crashes. This is due to the fact that main() tried to iterated through the
 values returned by foo(), which were local, stored in the stack, and discarded
 when foo() completed. So, when main() tries to iterate through the values a
 seg fault is thrown because it is trying to access memory that it should not
 have access to.

 4. If the print statements are commented out, then the same errors are returned,
 and the only difference is that the addresses from foo() and bar() are not
 printed.
*/
