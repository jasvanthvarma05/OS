#include <stdio.h>

#define P 4 // Number of processes
#define R 3 // Number of resources

int main() {
    // Define the claim matrix, allocation matrix, and resource vector
    int claim[P][R] = {{3, 2, 2}, {6, 1, 3}, {3, 1, 4}, {4, 2, 2}};
    int allocation[P][R] = {{1, 0, 0}, {6, 1, 2}, {2, 1, 1}, {0, 0, 2}};
    int resource[R] = {9, 3, 6};

    // Calculate the need matrix
    int need[P][R];
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need[i][j] = claim[i][j] - allocation[i][j];
        }
    }

    // Create arrays to track available resources and finished status of each process
    int available[R];
    int finish[P];
    for (int i = 0; i < R; i++) {
        available[i] = resource[i];
    }
    for (int i = 0; i < P; i++) {
        finish[i] = 0;
    }

    // Implement the safety algorithm
    int count = 0;
    while (count < P) {
        int found = 0;
        for (int i = 0; i < P; i++) {
            if (finish[i] == 0) {
                int j;
                for (j = 0; j < R; j++) {
                    if (need[i][j] > available[j]) {
                        break;
                    }
                }
                if (j == R) {
                    for (int k = 0; k < R; k++) {
                        available[k] += allocation[i][k];
                    }
                    finish[i] = 1;
                    found = 1;
                    count++;
                }
            }
        }
        if (found == 0) {
            break;
        }
    }

    // Check if the system is in a safe or unsafe state
    if (count == P) {
        printf("The system is in a safe state.\n");
    } else {
        printf("The system is in an unsafe state.\n");
    }
}
