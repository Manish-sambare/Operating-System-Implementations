#include <stdio.h>
#include <stdbool.h>

#define MAX_P 10
#define MAX_R 10

int main() {
    int p, r; // p = #processes, r = #resources
    int alloc[MAX_P][MAX_R], max[MAX_P][MAX_R], need[MAX_P][MAX_R];
    int avail[MAX_R];
    int done[MAX_P] = {0};
    int seq[MAX_P]; // Safe sequence
    int cnt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &p);
    printf("Enter number of resource types: ");
    scanf("%d", &r);

    // Allocation matrix
    printf("Enter Allocation Matrix (%d x %d):\n", p, r);
    for (int i = 0; i < p; i++)
        for (int j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);

    // Max matrix
    printf("Enter Max Matrix (%d x %d):\n", p, r);
    for (int i = 0; i < p; i++)
        for (int j = 0; j < r; j++)
            scanf("%d", &max[i][j]);

    // Available resources
    printf("Enter Available Resources (%d values):\n", r);
    for (int j = 0; j < r; j++)
        scanf("%d", &avail[j]);

    // Calculate Need = Max - Alloc
    for (int i = 0; i < p; i++)
        for (int j = 0; j < r; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Banker's Algorithm
    while (cnt < p) {
        bool found = false;

        for (int i = 0; i < p; i++) {
            if (!done[i]) {
                bool canRun = true;

                for (int j = 0; j < r; j++) {
                    if (need[i][j] > avail[j]) {
                        canRun = false;
                        break;
                    }
                }

                if (canRun) {
                    for (int j = 0; j < r; j++)
                        avail[j] += alloc[i][j];

                    seq[cnt++] = i;
                    done[i] = 1;
                    found = true;
                }
            }
        }

        if (!found) {
            printf("\nSystem is in an UNSAFE state. Deadlock may happen.\n");
            return 1;
        }
    }

    printf("\nSystem is in a SAFE state.\nSafe Sequence: ");
    for (int i = 0; i < p; i++)
        printf("P%d ", seq[i]);
    printf("\n");

    return 0;
}
