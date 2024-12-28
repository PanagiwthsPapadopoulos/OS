#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2];
    char message[] = "Hello from parent!";
    char buffer[100];

    if (pipe(pipefd) == -1) {
        perror("pipe failed");
        return 1;
    }

    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        close(pipefd[1]);  // Close unused write end
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(pipefd[0]);
    } else if (pid > 0) {
        // Parent process
        close(pipefd[0]);  // Close unused read end
        write(pipefd[1], message, strlen(message) + 1);
        close(pipefd[1]);
    } else {
        perror("fork failed");
    }

    return 0;
}
