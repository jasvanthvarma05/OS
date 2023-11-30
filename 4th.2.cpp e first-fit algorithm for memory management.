#include <stdio.h>

#define MAX_PARTITIONS 4
#define MAX_PROCESSES 5

void firstFit(int partitions[], int n, int processes[], int m) {
    int allocation[MAX_PROCESSES];
  
    for (int i = 0; i < m; i++) {
        allocation[i] = -1;
        
        for (int j = 0; j < n; j++) {
            if (partitions[j] >= processes[i]) {
                allocation[i] = j;
                partitions[j] -= processes[i];
                break;
            }
        }
    }
  
    printf("Process No.\tProcess Size\tPartition No.\n");
    for (int i = 0; i < m; i++) {
        printf("%d\t\t%d\t\t", i + 1, processes[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main() {
    int partitions[MAX_PARTITIONS] = {40, 10, 30, 60};
    int processes[MAX_PROCESSES] = {100, 50, 30, 120, 35};
    
    firstFit(partitions, MAX_PARTITIONS, processes, MAX_PROCESSES);
    
}
