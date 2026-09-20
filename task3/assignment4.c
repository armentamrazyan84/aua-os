#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t c1 = fork();
    if (c1 == 0) {
        printf("Child 1 (PID: %d) exiting normally with code 0\n", getpid());
        exit(0);
    }

    pid_t c2 = fork();
    if (c2 == 0) {
        printf("Child 2 (PID: %d) exiting with error code 5\n", getpid());
        exit(5);
    }

    pid_t children[2] = {c1, c2};
    for (int i = 0; i < 2; i++) {
        int status;
        waitpid(children[i], &status, 0);

        if (WIFEXITED(status)) {
            int code = WEXITSTATUS(status);
            if (code == 0) {
                printf("Child PID %d exited normally (Status: %d)\n", children[i], code);
            } else {
                printf("Child PID %d exited with an ERROR (Status: %d)\n", children[i], code);
            }
        }
    }

    return 0;
}
