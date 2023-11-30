#include <stdio.h>
#include <stdlib.h>

#define MAX_TRACKS 5

int abs_diff(int a, int b) {
    return (a > b) ? (a - b) : (b - a);
}

void cscan(int tracks[], int n, int initial_head) {
    int total_head_movement = 0;
    int current_head = initial_head;

    // Sort tracks in ascending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tracks[j] > tracks[j + 1]) {
                int temp = tracks[j];
                tracks[j] = tracks[j + 1];
                tracks[j + 1] = temp;
            }
        }
    }

    int index;
    for (index = 0; index < n; index++) {
        if (tracks[index] > initial_head)
            break;
    }

    // Moving in the right direction
    total_head_movement += abs_diff(current_head, tracks[index]);
    current_head = tracks[index];

    for (int i = index + 1; i < n; i++) {
        total_head_movement += abs_diff(current_head, tracks[i]);
        current_head = tracks[i];
    }

    // Moving to the beginning of the disk
    total_head_movement += abs_diff(current_head, 0);
    current_head = 0;

    // Moving in the right direction again to the previous maximum track
    for (int i = 0; i < index; i++) {
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

    cscan(tracks, num_tracks, initial_head);

}
