#include <stdio.h>
#include <stdbool.h>

#define NUM_PROCESSES 3
#define NUM_RESOURCES 3

bool isSafe(int available[], int max[][NUM_RESOURCES], int allocation[][NUM_RESOURCES], int need[][NUM_RESOURCES]) {
    bool finish[NUM_PROCESSES] = { false };
    int work[NUM_RESOURCES];
    for (int i = 0; i < NUM_RESOURCES; ++i) {
        work[i] = available[i];
    }

    int count = 0;
    while (count < NUM_PROCESSES) {
        bool found = false;
        for (int i = 0; i < NUM_PROCESSES; ++i) {
            if (!finish[i]) {
                bool canProcess = true;
                for (int j = 0; j < NUM_RESOURCES; ++j) {
                    if (need[i][j] > work[j]) {
                        canProcess = false;
                        break;
                    }
                }

                if (canProcess) {
                    for (int j = 0; j < NUM_RESOURCES; ++j) {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = true;
                    count++;
                    found = true;
                }
            }
        }
        if (!found) {
            break;
        }
    }

    for (int i = 0; i < NUM_PROCESSES; ++i) {
        if (!finish[i]) {
            return false; // Deadlock detected
        }
    }
    return true; // System is in a safe state
}

int main() {
    int max[NUM_PROCESSES][NUM_RESOURCES] = {
        {3, 6, 8},
        {4, 3, 3},
        {3, 4, 4}
    };

    int allocation[NUM_PROCESSES][NUM_RESOURCES] = {
        {3, 3, 3},
        {2, 0, 3},
        {1, 2, 4}
    };

    int available[NUM_RESOURCES] = {1, 2, 0};

    int need[NUM_PROCESSES][NUM_RESOURCES];
    for (int i = 0; i < NUM_PROCESSES; ++i) {
        for (int j = 0; j < NUM_RESOURCES; ++j) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    if (isSafe(available, max, allocation, need)) {
        printf("System is in a safe state.\n");
    } else {
        printf("System is in a deadlock state.\n");
        printf("Processes in deadlock: ");
        for (int i = 0; i < NUM_PROCESSES; ++i) {
            if (need[i][0] != 0 || need[i][1] != 0 || need[i][2] != 0) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }

}