/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

/*
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
  /* makes an array with size of SIZE
  prints array
  iterates through array, sets all elements to 42
  returns array
  */
    int i;
    int array[SIZE];

    // see what happens when you take out the frame added by the print statments
    // printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
    return array; // can't return array here
}

void bar() {
  /* makes an array of size SIZE
  prints array
  iterates through array, set each element of array to its index
  */
    int i;
    int array[SIZE];

    // see what happens when you take out the frame added by the print statments
    // printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

int main()
{
    int i;
    // initialize array with foo function
    int *array = foo();
    // calls bar but does not assign it to anything
    bar();

    // iterates through array, prints each element
    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}


/*
Stack Allocated Data
  1. This program first calles foo(), which:
        makes an array with size of SIZE
        prints array
        iterates through array, sets all elements to 42
        returns array
      Then it calls bar() which:
        makes an array of size SIZE
        prints array
        iterates through array, set each element of array to its index
      Then it iterates through the array and prints each value

  2. The warning is:
        function returns address of local variable [-Wreturn-local-addr]
     It means that a local variable is used outside of it's "locality" (function),
     which means it can't be accessed. When the function stops running, its
     local memory is cleared so it is not helpful to return a pointer to that
     variable since the pointer will then point to nothing.
  3. The same error occurs because foo is still returning a pointer to the
     locally define array

*/
