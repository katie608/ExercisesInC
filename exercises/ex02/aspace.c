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
    void *p = malloc(128);
    char *s = "Hello, World";
    void *p2 = malloc(256);
    int local = 12;
    void *p3 = malloc(2);
    void *p4 = malloc(2);

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("p points to %p\n", p);
    printf ("s points to %p\n", s);
    printf ("p2 points to %p\n", p2);
    printf ("local points to %p\n", local);
    printf ("p3 points to %p\n", p3);
    printf ("p4 points to %p\n", p4);

    return 0;
}


/*
The Address Space
  3. See jpg in this directory for sketch
  4. Yes, another call to malloc makes the stack grow upwards
  5. Local has a smaller address
  6. I used a size of 2, and google says there is 0x20
    space between them

*/
