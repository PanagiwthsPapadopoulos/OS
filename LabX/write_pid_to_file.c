#include <stdio.h>
#include <unistd.h>

int main() {
    FILE *file = fopen("pids.txt", "a");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        fprintf(file, "Child PID: %d\n", getpid());
    } else if (pid > 0) {
        // Parent process
        fprintf(file, "Parent PID: %d\n", getpid());
    } else {
        perror("fork failed");
    }

    fclose(file);
    return 0;
}
