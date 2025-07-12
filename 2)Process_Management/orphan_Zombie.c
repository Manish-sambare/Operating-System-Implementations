#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Sort array in ascending order
void sortAsc(int a[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (a[j] > a[j+1]) {
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
}

// Sort array in descending order
void sortDesc(int a[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (a[j] < a[j+1]) {
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
}

int main() {
    int a[] = {5, 2, 8, 1, 9};
    int n = sizeof(a) / sizeof(a[0]);

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork fail");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        printf("\n[Child] PID: %d | PPID: %d\n", getpid(), getppid());
        sortDesc(a, n);
        printf("[Child] Desc Order: ");
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");

        // Orphan process demo
        sleep(5);
        printf("[Child - Orphan] New parent PID: %d\n", getppid());
    }
    else {
        // Parent process
        printf("\n[Parent] PID: %d | Child PID: %d\n", getpid(), pid);
        sortAsc(a, n);
        printf("[Parent] Asc Order: ");
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");

        // Zombie process demo
        sleep(2);
        printf("[Parent - Zombie] Run 'ps -l' to check zombie status\n");
    }

    return 0;
}
