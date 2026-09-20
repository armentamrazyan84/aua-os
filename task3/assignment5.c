#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fix_zombie = 0;
    if (argc > 1 && argv[1][0] == '1') {
        fix_zombie = 1;
    }

    pid_t pid = fork();

    if (pid == 0) {
        printf("Child (PID: %d) exiting immediately...\n", getpid());
        exit(0);
    } else {
        if (!fix_zombie) {
            printf("Parent (PID: %d) sleeping for 15s without waiting. Check `ps aux | grep Z`...\n", getpid());
            sleep(15);
        } else {
            printf("Parent (PID: %d) waiting for child (PID: %d)...\n", getpid(), pid);
            wait(NULL);
            printf("Child reaped successfully. No zombie created.\n");
        }
    }

    return 0;
}
