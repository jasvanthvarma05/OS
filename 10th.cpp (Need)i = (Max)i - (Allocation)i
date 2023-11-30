#include <stdio.h>

#define P 5 // Number of processes
#define R 3 // Number of resources

int main() {
    int allocation[P][R] = {
        {1, 1, 2},
        {2, 1, 2},
        {3, 0, 1},
        {0, 2, 0},
        {1, 1, 2}
    };

    int max[P][R] = {
        {5, 4, 4},
        {4, 3, 3},
        {9, 1, 3},
        {8, 6, 4},
        {2, 2, 3}
    };

    int available[R] = {3, 2, 1}; // Available resources of type A, B, C

    // Calculate the need matrix
    int need[P][R];
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Display the need matrix
    printf("Need Matrix:\n");
    for (int i = 0; i < P; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < R; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    return 0;
}
