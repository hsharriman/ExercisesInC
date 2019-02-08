/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

int main ()
{
    int var2 = 5;
    int var3 = 10;
    void *p = malloc(256);
    void *pp = malloc(256);
    void *x = malloc(2);
    void *xx = malloc(30);
    char *s = "Hello, World";

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("Address of var3 is %p\n", &var3);
    printf ("p points to %p\n", x);
    printf ("pp points to %p\n", xx);
    printf ("s points to %p\n", s);

    return 0;
}
