#include <stdio.h>

#define NUM_PARTITIONS 6
#define NUM_PROCESSES 5

int main() {
    int memory_partitions[NUM_PARTITIONS] = {300, 600, 350, 200, 750, 125};
    int processes[NUM_PROCESSES] = {115, 500, 358, 200, 375};
    int allocation[NUM_PROCESSES] = {-1, -1, -1, -1, -1}; // -1 represents not allocated

    for (int i = 0; i < NUM_PROCESSES; ++i) {
        for (int j = 0; j < NUM_PARTITIONS; ++j) {
            if (memory_partitions[j] >= processes[i]) {
                allocation[i] = j;
                memory_partitions[j] -= processes[i];
                break;
            }
        }
    }

    printf("Process\t\tProcess Size\tAllocated Partition\n");
    for (int i = 0; i < NUM_PROCESSES; ++i) {
        printf("%d\t\t%d KB\t\t", i + 1, processes[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }

}
