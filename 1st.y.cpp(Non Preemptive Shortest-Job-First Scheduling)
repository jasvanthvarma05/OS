#include <stdio.h>

struct Process {
    int id;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
};

void swap(struct Process *a, struct Process *b) {
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

void sortByBurstTime(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burstTime > processes[j + 1].burstTime) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

void calculateTimes(struct Process processes[], int n) {
    processes[0].waitingTime = 0;
    processes[0].turnaroundTime = processes[0].burstTime;

    for (int i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i - 1].turnaroundTime;
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    }
}

void printResults(struct Process processes[], int n) {
    float totalWaitingTime = 0, totalTurnaroundTime = 0;

    for (int i = 0; i < n; i++) {

        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }

    float avgWaitingTime = totalWaitingTime / n;
    float avgTurnaroundTime = totalTurnaroundTime / n;

    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
}

int main() {
    struct Process processes[] = {
        {1, 6, 0, 0},
        {2, 8, 0, 0},
        {3, 7, 0, 0},
        {4, 3, 0, 0}
    };
    int n = sizeof(processes) / sizeof(processes[0]);

    sortByBurstTime(processes, n);
    calculateTimes(processes, n);
    printResults(processes, n);

    return 0;
}
