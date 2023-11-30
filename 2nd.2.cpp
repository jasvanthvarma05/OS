#include <stdio.h>

#define MAX_PARTITIONS 6
#define MAX_PROCESSES 5

void bestFit(int partitions[], int n, int processes[], int m) {
    int allocation[MAX_PROCESSES];
  
    for (int i = 0; i < m; i++) {
        allocation[i] = -1;
        
        int bestIdx = -1;
        for (int j = 0; j < n; j++) {
            if (partitions[j] >= processes[i]) {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (partitions[bestIdx] > partitions[j])
                    bestIdx = j;
            }
        }
        
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            partitions[bestIdx] -= processes[i];
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
    int partitions[MAX_PARTITIONS] = {300, 600, 350, 200, 750, 125};
    int processes[MAX_PROCESSES] = {115, 500, 358, 200, 375};
    
    bestFit(partitions, MAX_PARTITIONS, processes, MAX_PROCESSES);
    
}
