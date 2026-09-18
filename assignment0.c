#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t p1, p2, p3;

    p1 = fork();
    if (p1 < 0) {
        perror("fork 1 failed");
        exit(EXIT_FAILURE);
    }

    p2 = fork();
    if (p2 < 0) {
        perror("fork 2 failed");
        exit(EXIT_FAILURE);
    }

    p3 = fork();
    if (p3 < 0) {
        perror("fork 3 failed");
        exit(EXIT_FAILURE);
    }

    printf("Process PID: %d, Parent PID: %d\n", getpid(), getppid());

    while (wait(NULL) > 0);

    return 0;
}
