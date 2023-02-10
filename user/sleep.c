#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
    if (argc < 2){
        fprintf(2, "Sleep requires an argument, ticks to sleep.\n");
        exit(1);
    }

    int i = atoi(argv[1]);

    fprintf(1, "Sleeping: %d.\n", i);
    sleep(i);

    return 0;
}
