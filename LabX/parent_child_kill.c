#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void signal_handler(int sig) {
    printf("Signal %d received by child process.\n", sig);
    exit(0);
}

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        signal(SIGUSR1, signal_handler);  // Set up signal handler
        while (1) {
            pause();  // Wait for signal
        }
    } else if (pid > 0) {
        // Parent process
        sleep(1);  // Give child time to set up
        printf("Parent sending SIGUSR1 to child process %d\n", pid);
        kill(pid, SIGUSR1);  // Send signal to child
    } else {
        perror("fork failed");
    }

    return 0;
}
