#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        exit(EXIT_SUCCESS);
    } else {
        printf("Parent Process: PID = %d, Created Child PID = %d\n", getpid(), pid);
    }

    return 0;
}
