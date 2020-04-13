/* Example code for Exercises in C.

Copyright 2016 Allen B. Downey
License: MIT License https://opensource.org/licenses/MIT

*/

/*
1. Check whether the parent and child processes share the same global, heap, and
stack segments
global: define an int outside of main. I guess check if it has the same address between children
heap: dynamic memory. Print address of something that you malloced?
stack: local variables. Define an int inside a function, check if it has same address between children?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/types.h>
#include <wait.h>


// errno is an external global variable that contains
// error information
extern int errno;
// global variable declared in erno.h
// externs it is declared here but defined somewhere else

//define a global variable to check globals
int globalVar = 12;

// get_seconds returns the number of seconds since the
// beginning of the day, with microsecond precision
double get_seconds() {
  // if you call get seconds, do something, then do something else
    struct timeval tv[1]; // local variable, array of time value structures
    // tv needs to be a time value
    gettimeofday(tv, NULL); //gets "wall clock time"
    // returns seconds and microseconds as a fraction
    return tv->tv_sec + tv->tv_usec / 1e6;
}


void child_code(int i)
{
    sleep(i);
    printf("Hello from child %d.\n", i);
}

// main takes two parameters: argc is the number of command-line
// arguments; argv is an array of strings containing the command
// line arguments
int main(int argc, char *argv[])
{
    int status;
    pid_t pid;
    double start, stop;
    int i, num_children;

    // define a local variable to check stack
    int localVar = 3;

    // dynamically allocate memory to check heap
    int *dynamic = malloc(sizeof(int));

    // the first command-line argument is the name of the executable.
    // if there is a second, it is the number of children to create.
    if (argc == 2) { // if command line has 2 arguments
        num_children = atoi(argv[1]); // take 2nd parameter, convert to integer
        // tells how many children should be created
    } else { //default is one child
        num_children = 1;
    }

    // get the start time
    start = get_seconds();

    for (i=0; i<num_children; i++) {

        // create a child process
        printf("Creating child %d.\n", i);
        pid = fork();

        /* check for an error */
        if (pid == -1) {
            fprintf(stderr, "fork failed: %s\n", strerror(errno));
            perror(argv[0]);
            exit(1);
        }

        /* see if we're the parent or the child */
        if (pid == 0) { //if 0, that means it is a child
            child_code(i);
            exit(i);
        }
    }

    /* parent continues */
    printf("Hello from the parent.\n");

    for (i=0; i<num_children; i++) { // run loop once for each child
        pid = wait(&status); //waits for child process to exit, gets process id
        // of child process, and status is stored

        if (pid == -1) {
            fprintf(stderr, "wait failed: %s\n", strerror(errno));
            perror(argv[0]);
            exit(1);
        }

        // check the exit status of the child
        status = WEXITSTATUS(status);
        // prints process id of child process, value that it returned
        printf("Child %d exited with error code %d.\n", pid, status);

        // check global variables addresses against each other
        // the addresses of the global variables seem to match
        printf("Address of global variable: %p\n", &globalVar);

        // check malloced memory addresses
        printf("Address of dynamic variable: %p\n", &dynamic);

        // check local variable addresses
        printf("Address of local variable: %p\n", &localVar);
    }
    // compute the elapsed time
    stop = get_seconds();
    printf("Elapsed time = %f seconds.\n", stop - start);

    exit(0);
}
