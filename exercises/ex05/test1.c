/*
Remember to compile rand.c along with test1.c using:
gcc rand.c test1.c -o test1

Plot using:
./test1 | python check_uniform.py
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rand.h"

int main (int argc, char *argv[])
{
    int i;
    double x;

    srandom (time (NULL));

    // for (i=0; i<10000; i++) {
    //     x = random_float();
    //     printf ("%lf\n", x);
    // }

    for (i=0; i<10000; i++) {
        x = my_random_double();
        printf ("%lf\n", x);
    }
}
