#include <stdio.h>

#define MAX 100

typedef struct {
    int id;
    int at;  // Arrival Time
    int bt;  // Burst Time
    int wt;  // Waiting Time
    int tat; // Turnaround Time
} Process;

void getInput(Process pr[], int *n) {
    printf("Enter number of processes: ");
    scanf("%d", n);

    for (int i = 0; i < *n; i++) {
        pr[i].id = i + 1;
        printf("Enter Arrival Time for P%d: ", pr[i].id);
        scanf("%d", &pr[i].at);
        printf("Enter Burst Time for P%d: ", pr[i].id);
        scanf("%d", &pr[i].bt);
    }
}

void sortByArrival(Process pr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (pr[j].at > pr[j+1].at) {
                Process temp = pr[j];
                pr[j] = pr[j+1];
                pr[j+1] = temp;
            }
}

void fcfs(Process pr[], int n) {
    sortByArrival(pr, n);

    pr[0].wt = 0;
    pr[0].tat = pr[0].bt;

    for (int i = 1; i < n; i++) {
        int end_prev = pr[i-1].at + pr[i-1].bt + pr[i-1].wt;

        if (end_prev > pr[i].at)
            pr[i].wt = end_prev - pr[i].at;
        else
            pr[i].wt = 0;

        pr[i].tat = pr[i].wt + pr[i].bt;
    }

    printf("\nPID\tAT\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", pr[i].id, pr[i].at, pr[i].bt, pr[i].wt, pr[i].tat);
    }

    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += pr[i].wt;
        total_tat += pr[i].tat;
    }

    printf("\nAvg Waiting Time: %.2f", total_wt / n);
    printf("\nAvg Turnaround Time: %.2f\n", total_tat / n);
}

int main() {
    Process pr[MAX];
    int n = 0, ch;

    while (1) {
        printf("\n--- FCFS CPU Scheduler ---\n");
        printf("1. Input Process Data\n");
        printf("2. Run FCFS Scheduling\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            getInput(pr, &n);
            break;
        case 2:
            if (n > 0)
                fcfs(pr, n);
            else
                printf("Please input process data first!\n");
            break;
        case 3:
            printf("Bye!\n");
            return 0;
        default:
            printf("Wrong choice. Try again.\n");
        }
    }
}
