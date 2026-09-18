#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        execl("/usr/bin/grep", "grep", "main", "test.txt", NULL);
        execl("/bin/grep", "grep", "main", "test.txt", NULL);
        perror("execl failed");
        exit(EXIT_FAILURE);
    } else {
        wait(NULL);
        printf("Parent process completed\n");
    }

    return 0;
}
