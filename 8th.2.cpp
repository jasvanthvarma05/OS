#include <stdio.h>
#include <stdlib.h>

#define MAX_TRACKS 5

int abs_diff(int a, int b) {
    return (a > b) ? (a - b) : (b - a);
}

void scan(int tracks[], int n, int initial_head, char direction) {
    int total_head_movement = 0;
    int current_head = initial_head;

    if (direction == 'L') { // Left direction
        int min_track = 0;
        for (int i = 0; i < n; i++) {
            if (tracks[i] < initial_head && tracks[i] > tracks[min_track]) {
                min_track = i;
            }
        }

        total_head_movement = abs_diff(initial_head, 0);
        current_head = 0;

        for (int i = min_track; i >= 0; i--) {
            total_head_movement += abs_diff(current_head, tracks[i]);
            current_head = tracks[i];
        }

        total_head_movement += tracks[min_track];
        current_head = tracks[min_track];

        for (int i = min_track + 1; i < n; i++) {
            total_head_movement += abs_diff(current_head, tracks[i]);
            current_head = tracks[i];
        }
    } else if (direction == 'R') { // Right direction
        int max_track = 0;
        for (int i = 0; i < n; i++) {
            if (tracks[i] > initial_head && tracks[i] < tracks[max_track]) {
                max_track = i;
            }
        }

        total_head_movement = abs_diff(initial_head, 99);
        current_head = 99;

        for (int i = max_track; i < n; i++) {
            total_head_movement += abs_diff(current_head, tracks[i]);
            current_head = tracks[i];
        }

        total_head_movement += abs_diff(current_head, 99);
        current_head = 99;

        for (int i = max_track - 1; i >= 0; i--) {
            total_head_movement += abs_diff(current_head, tracks[i]);
            current_head = tracks[i];
        }
    }

    printf("Total Head Movement: %d\n", total_head_movement);
    printf("Average Head Movement: %.2f\n", (float)total_head_movement / n);
}

int main() {
    int tracks[MAX_TRACKS] = { 55, 58, 60, 70, 18 };
    int num_tracks = 5;
    int initial_head = 50; // Initial head position
    char direction = 'L'; // Direction ('L' for left, 'R' for right)

    scan(tracks, num_tracks, initial_head, direction);

}
