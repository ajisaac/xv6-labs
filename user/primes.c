#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
    write(1, "hello world\n", 12);

    int p[36];
    int slots[36] = {0};

    // create all our pipes
    for (int i = 0; i < 36; i++, i++) {
        pipe(p + i);
    }

    // return childs pid
    int pid1 = fork();
    if (pid1 != 0) {

        // dup console out
        int fdup = dup(1)

        // I am parent
        close(1);
        dup(p[1]);
        slots[0] = 1;
        slots[1] = 1;
        slots[2] = 1;
        slots[3] = 1;
        for (int i = 2; i < 36; i++) {
            if (i % 2 != 0) {
                write(1, i, 1);
            }
        }
    } else {
        while (true) {

            // THE FIRST NUMBER WE WRITE TO CHILD TELLS IT ITS NUMBER
            // NOT USE SHARED MEMORY

            int pid_inner = fork(){}

        }
    }


    exit(0);
}
