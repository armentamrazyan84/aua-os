#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;

    pid1 = fork();
    if (pid1 < 0) {
        perror("fork 1 failed");
        exit(EXIT_FAILURE);
    } else if (pid1 == 0) {
        execl("/bin/ls", "ls", NULL);
        perror("execl ls failed");
        exit(EXIT_FAILURE);
    }

    pid2 = fork();
    if (pid2 < 0) {
        perror("fork 2 failed");
        exit(EXIT_FAILURE);
    } else if (pid2 == 0) {
        execl("/bin/date", "date", NULL);
        perror("execl date failed");
        exit(EXIT_FAILURE);
    }

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    printf("Parent process done\n");

    return 0;
}
