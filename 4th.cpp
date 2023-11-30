#include <stdio.h>

struct Process {
    int burstTime;
    int waitingTime;
    int turnaroundTime;
};

int main() {
    // Define the processes
    struct Process processes[] = {
        {10, 0, 0},
        {15, 0, 0},
        {25, 0, 0}
    };
    int n = sizeof(processes) / sizeof(processes[0]);

    // Calculate waiting time and turnaround time
    int currentTime = 0;
    float totalWaitingTime = 0, totalTurnaroundTime = 0;
    for (int i = 0; i < n; ++i) {
        if (currentTime < processes[i].burstTime) {
            processes[i].waitingTime = 0;
            currentTime = processes[i].burstTime;
        } else {
            processes[i].waitingTime = currentTime;
            currentTime += processes[i].burstTime;
        }

        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;

        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;

        printf("Process %d - Waiting Time: %d, Turnaround Time: %d\n", i + 1, processes[i].waitingTime, processes[i].turnaroundTime);
    }

    float avgWaitingTime = totalWaitingTime / n;
    float avgTurnaroundTime = totalTurnaroundTime / n;

    printf("Average Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);

}
