/* Example code for Exercises in C.

Copyright 2016 Allen B. Downey
License: MIT License https://opensource.org/licenses/MIT

*/
/*2. It appears as though each child process received a copy of the global, stack,
and heap segments. When a child process is initialized, the values of the variables
created in the parent process are the same in the child process and the parent process.
However, when the child MODIFIES any of these variables (in the stack, heap, or global
segments), these changes are not communicated to the parent process. Additionally, each
child process cannot see changes that another child process makes to the variables in the
stack, global, or heap segments.

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
int testGlob = 1;


// get_seconds returns the number of seconds since the
// beginning of the day, with microsecond precision
double get_seconds() {
    struct timeval tv[1];

    gettimeofday(tv, NULL);
    return tv->tv_sec + tv->tv_usec / 1e6;
}


void child_code(int i)
{
    sleep(i);
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
    int* testHeap = malloc(sizeof(int));
    *testHeap = 2;
    int testStack = 20;

    // the first command-line argument is the name of the executable.
    // if there is a second, it is the number of children to create.
    if (argc == 2) {
        num_children = atoi(argv[1]);
    } else {
        num_children = 1;
    }

    // get the start time
    start = get_seconds();

    for (i=0; i<num_children; i++) {

        // create a child process
        // printf("Creating child %d.\n", i);
        pid = fork();

        /* check for an error */
        if (pid == -1) {
            fprintf(stderr, "fork failed: %s\n", strerror(errno));
            perror(argv[0]);
            exit(1);
        }

        /* see if we're the parent or the child */
        if (pid == 0) {
          //If we get here, then this is the child process
            printf("before changing, child %d, testStack = %d, stack addr %p.\n", i, testStack, &testStack);
            testStack = 40 + i;
            printf("for child %d, testStack = %d, address = %p.\n\n", i, testStack, &testStack);

            printf("before changing, child %d, testHeap = %d, address = %p.\n", i, *testHeap, testHeap);
            *testHeap = 10 + i;
            printf("for child %d, value of testHeap = %d, address = %p\n\n", i, *testHeap, testHeap);

            printf("before changing, child %d, testGlob = %d, address = %p.\n", i, testGlob, &testGlob);
            testGlob = 100 + i;
            printf("for child %d, val of testGlob = %d, address = %p\n\n", i, testGlob, &testGlob);
            child_code(i);
            exit(i);
        }
    }

    /* parent continues */
    // printf("Hello from the parent.\n");

    for (i=0; i<num_children; i++) {
        pid = wait(&status);

        if (pid == -1) {
            fprintf(stderr, "wait failed: %s\n", strerror(errno));
            perror(argv[0]);
            exit(1);
        }

        // check the exit status of the child
        status = WEXITSTATUS(status);
        printf("Child %d exited with error code %d.\n", pid, status);
    }
    printf("for parent, testStack = %d, address = %p\n", testStack, &testStack);
    printf("for parent, testHeap = %d, address = %p\n", *testHeap, testHeap);
    printf("for parent, testGlob = %d, address = %p\n", testGlob, &testGlob);
    // compute the elapsed time
    stop = get_seconds();
    printf("Elapsed time = %f seconds.\n", stop - start);

    exit(0);
}
