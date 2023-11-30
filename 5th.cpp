#include <stdio.h>

struct Process {
    int burstTime;
    int remainingTime;
    int waitingTime;
    int turnaroundTime;
};

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    // Define the processes
    struct Process processes[] = {
        {24, 0, 0, 0},
        {3, 0, 0, 0},
        {3, 0, 0, 0}
    };
    int n = sizeof(processes) / sizeof(processes[0]);
    int quantum = 4;

    // Initialize remaining times
    for (int i = 0; i < n; ++i) {
        processes[i].remainingTime = processes[i].burstTime;
    }

    // Calculate waiting time and turnaround time using Round Robin
    int currentTime = 0;
    int completed = 0;
    while (completed != n) {
        for (int i = 0; i < n; ++i) {
            if (processes[i].remainingTime > 0) {
                int executeTime = min(quantum, processes[i].remainingTime);
                processes[i].remainingTime -= executeTime;
                currentTime += executeTime;

                if (processes[i].remainingTime == 0) {
                    completed++;
                    processes[i].turnaroundTime = currentTime;
                    processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
                }
            }
        }
    }

    // Calculate total waiting time and total turnaround time
    float totalWaitingTime = 0, totalTurnaroundTime = 0;
    for (int i = 0; i < n; ++i) {
        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }

    float avgWaitingTime = totalWaitingTime / n;
    float avgTurnaroundTime = totalTurnaroundTime / n;

    printf("Average Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);

}
