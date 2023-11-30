#include <stdio.h>
#include <stdlib.h>

// Function to calculate absolute difference
int abs_diff(int a, int b) {
    return (a > b) ? (a - b) : (b - a);
}

void LOOK(int tracks[], int n, int head) {
    int total_head_movement = 0;
    int current_track, prev_track;
    int direction;

    // Sort the tracks for easier traversal (ascending order)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tracks[j] > tracks[j + 1]) {
                int temp = tracks[j];
                tracks[j] = tracks[j + 1];
                tracks[j + 1] = temp;
            }
        }
    }

    // Determine the direction of head movement
    if (head <= tracks[0]) {
        direction = -1; // Move towards smaller tracks
        current_track = tracks[0];
    } else if (head >= tracks[n - 1]) {
        direction = 1; // Move towards larger tracks
        current_track = tracks[n - 1];
    } else {
        // Find the closest track to the head position
        for (int i = 0; i < n; i++) {
            if (tracks[i] >= head) {
                current_track = tracks[i];
                break;
            }
        }
        direction = 1; // Move towards larger tracks
    }

    // Calculate total head movement
    for (int i = 0; i < n; i++) {
        total_head_movement += abs_diff(head, current_track);
        head = current_track;
        
        if (direction == 1) {
            current_track = tracks[i + 1];
        } else {
            current_track = tracks[n - i - 2];
        }
    }

    printf("Average head movement: %.2f\n", (float)total_head_movement / n);
}

int main() {
    int tracks[] = {55, 58, 60, 70, 18};
    int num_tracks = sizeof(tracks) / sizeof(tracks[0]);
    int initial_head_position = 50; // Change this to the starting head position

    LOOK(tracks, num_tracks, initial_head_position);

}
