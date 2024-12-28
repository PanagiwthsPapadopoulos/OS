#include <stdio.h>
#include <unistd.h>

int main() {
    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            printf("Child process with PID: %d\n", getpid());
            return 0;  // Child exits after printing
        } else if (pid > 0) {
            // Parent process continues
            printf("Parent process with PID: %d created child PID: %d\n", getpid(), pid);
        } else {
            perror("fork failed");
        }
    }
    return 0;
}
