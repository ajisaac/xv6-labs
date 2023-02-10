#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

/*
 Write a program that uses UNIX system calls to ''ping-pong'' a byte between two processes over a pair of pipes, one for
 each direction. The parent should send a byte to the child; the child should print "<pid>: received ping", where <pid>
 is its process ID, write the byte on the pipe to the parent, and exit; the parent should read the byte from the child,
 print "<pid>: received pong", and exit. Your solution should be in the file user/pingpong.c.
 */
int main(int argc, char *argv[]) {

    // creates 2 pipes
    // each process gets an in and an out from pipes
    // parent sends byte on pipe
    // child reads byte outloud
    // child sends byte back
    // parent reads byte

    char c[1];
    c[0] = 'c';
    int p[2]; // p[0] is read, p[1] is write
    int p2[2]; // p2[0] is read, p2[1] is write

    pipe(p);
    pipe(p2);

    int pid = fork();
    if (pid == 0) {

        // read from parent thru pipe
        close(0);
        dup(p[0]);
        read(0, &c, 1);

        // write to console fd
        fprintf(1, "%d: received ping\n", pid);

        // change write to pipe, write to parent
        close(1);
        dup(p2[1]);
        write(1, &c, 1);

    } else {

        c[0] = 'b';
        // dup the console out fd
        int fdup = dup(1);

        // send ping to child through pipe
        close(1);
        dup(p[1]);
        write(1, &c, 1);

        // read pong from child
        close(0);
        dup(p2[0]);
        read(0, &c, 1);

        fprintf(fdup, "%d: received pong\n", pid);
    }
    exit(0);
}