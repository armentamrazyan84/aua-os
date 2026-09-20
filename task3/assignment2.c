#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int status;

    pid_t child1 = fork();
    if (child1 < 0) {
        perror("fork 1 failed");
        exit(EXIT_FAILURE);
    } else if (child1 == 0) {
        printf("Child 1 (PID: %d) starting and sleeping...\n", getpid());
        sleep(2);
        printf("Child 1 exiting with status 10\n");
        exit(10);
    }

    pid_t child2 = fork();
    if (child2 < 0) {
        perror("fork 2 failed");
        exit(EXIT_FAILURE);
    } else if (child2 == 0) {
        printf("Child 2 (PID: %d) starting...\n", getpid());
        sleep(1);
        printf("Child 2 exiting with status 20\n");
        exit(20);
    }

    printf("Parent waiting specifically for Child 2 (PID: %d)...\n", child2);
    waitpid(child2, &status, 0);
    if (WIFEXITED(status)) {
        printf("Parent: Child 2 terminated with exit status %d\n", WEXITSTATUS(status));
    }

    printf("Parent waiting for Child 1...\n");
    wait(&status);
    if (WIFEXITED(status)) {
        printf("Parent: Remaining child terminated with exit status %d\n", WEXITSTATUS(status));
    }

    return 0;
}
