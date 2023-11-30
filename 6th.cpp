#include <stdio.h>

struct Process {
    int burstTime;
    int priority;
    int waitingTime;
    int turnaroundTime;
};

void sortProcessesByPriority(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (processes[j].priority > processes[j + 1].priority) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Define the processes
    struct Process processes[] = {
        {30, 2, 0, 0},
        {5, 1, 0, 0},
        {12, 3, 0, 0}
    };

    // Sort processes by priority
    sortProcessesByPriority(processes, n);

    // Calculate waiting time and turnaround time based on priority
    int currentTime = 0;
    for (int i = 0; i < n; ++i) {
        processes[i].waitingTime = currentTime;
        currentTime += processes[i].burstTime;
        processes[i].turnaroundTime = currentTime;
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
