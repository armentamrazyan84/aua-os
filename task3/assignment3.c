#include <stdio.h>
#include <stdlib.h>

void cleanup_one(void) {
    printf("Cleanup Handler 1 executed.\n");
}

void cleanup_two(void) {
    printf("Cleanup Handler 2 executed.\n");
}

int main() {
    if (atexit(cleanup_one) != 0 || atexit(cleanup_two) != 0) {
        fprintf(stderr, "Failed to register exit functions\n");
        return EXIT_FAILURE;
    }

    printf("Program running. Calling exit()...\n");
    exit(0);
}
