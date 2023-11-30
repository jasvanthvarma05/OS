#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // for INT_MAX

#define MAX_TRACKS 5

int abs_diff(int a, int b) {
    return (a > b) ? (a - b) : (b - a);
}

int findClosestTrack(int tracks[], int n, int current_head, int visited[]) {
    int min_distance = INT_MAX;
    int closest_track;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && abs_diff(current_head, tracks[i]) < min_distance) {
            min_distance = abs_diff(current_head, tracks[i]);
            closest_track = i;
        }
    }

    return closest_track;
}

void sstf(int tracks[], int n, int initial_head) {
    int total_head_movement = 0;
    int current_head = initial_head;
    int visited[MAX_TRACKS] = {0};

    for (int i = 0; i < n; i++) {
        int closest = findClosestTrack(tracks, n, current_head, visited);
        visited[closest] = 1;
        total_head_movement += abs_diff(current_head, tracks[closest]);
        current_head = tracks[closest];
    }

    printf("Total Head Movement: %d\n", total_head_movement);
    printf("Average Head Movement: %.2f\n", (float)total_head_movement / n);
}

int main() {
    int tracks[MAX_TRACKS] = { 55, 58, 60, 70, 18 };
    int num_tracks = 5;
    int initial_head = 50; // Initial head position

    sstf(tracks, num_tracks, initial_head);

}
