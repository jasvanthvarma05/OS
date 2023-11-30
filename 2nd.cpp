#include <stdio.h>
#include <stdbool.h>
#include <limits>
struct Process {
    int processID;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
    bool completed;
};
// Function to find the process with the shortest remaining time
int findShortestProcess(struct Process processes[], int n, int currentTime) {
    int shortest = -1;
    int shortestTime = INT_MAX;
    for (int i = 0; i < n; ++i) {
        if (!processes[i].completed && processes[i].arrivalTime <= currentTime) {
            if (processes[i].remainingTime < shortestTime) {
                shortestTime = processes[i].remainingTime;
                shortest = i;
            }
        }
    }
    return shortest;
}
int main() {
    struct Process processes[] = {
        {1, 0, 5, 5, 0, 0, 0, false},
        {2, 1, 3, 3, 0, 0, 0, false},
        {3, 2, 3, 3, 0, 0, 0, false},
        {4, 4, 1, 1, 0, 0, 0, false}
    };
    int n = sizeof(processes) / sizeof(processes[0]);

    int currentTime = 0;
    int completed = 0;

    while (completed != n) {
        int shortestProcess = findShortestProcess(processes, n, currentTime);
        if (shortestProcess == -1) {
            currentTime++;
            continue;
        }

        processes[shortestProcess].remainingTime--;

        if (processes[shortestProcess].remainingTime == 0) {
            processes[shortestProcess].completed = true;
            completed++;
            processes[shortestProcess].completionTime = currentTime + 1;
            processes[shortestProcess].turnaroundTime = processes[shortestProcess].completionTime - processes[shortestProcess].arrivalTime;
            processes[shortestProcess].waitingTime = processes[shortestProcess].turnaroundTime - processes[shortestProcess].burstTime;
        }

        currentTime++;
    }

    // Calculate average waiting time and turnaround time
    float totalWaitingTime = 0, totalTurnaroundTime = 0;
    for (int i = 0; i < n; ++i) {
        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }
    float avgWaitingTime = totalWaitingTime / n;
    float avgTurnaroundTime = totalTurnaroundTime / n;

    printf("Average Waiting Time: %.2f ms\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f ms\n", avgTurnaroundTime);

}