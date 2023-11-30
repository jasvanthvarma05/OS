#include <stdio.h>
#include <stdlib.h>

#define MAX_TRACKS 5

int abs_diff(int a, int b) {
    return (a > b) ? (a - b) : (b - a);
}

void fcfs(int tracks[], int n, int initial_head) {
    int total_head_movement = 0;
    int current_head = initial_head;

    for (int i = 0; i < n; i++) {
        total_head_movement += abs_diff(current_head, tracks[i]);
        current_head = tracks[i];
    }

    printf("Total Head Movement: %d\n", total_head_movement);
    printf("Average Head Movement: %.2f\n", (float)total_head_movement / n);
}

int main() {
    int tracks[MAX_TRACKS] = { 55, 58, 60, 70, 18 };
    int num_tracks = 5;
    int initial_head = 50; // Initial head position

    fcfs(tracks, num_tracks, initial_head);

}
