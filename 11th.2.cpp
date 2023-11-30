#include <stdio.h>
#include <stdlib.h>

int abs_diff(int a, int b) {
    return (a > b) ? (a - b) : (b - a);
}

void CLOOK(int tracks[], int n, int head) {
    int total_head_movement = 0;

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

    // Find the index of head in the sorted track list
    int index;
    for (index = 0; index < n; index++) {
        if (tracks[index] >= head) {
            break;
        }
    }

    // Calculate total head movement in CLOOK
    for (int i = index; i < n; i++) {
        total_head_movement += abs_diff(head, tracks[i]);
        head = tracks[i];
    }

    // Head wraps around to the beginning of the track
    if (index != 0) {
        for (int i = 0; i < index; i++) {
            total_head_movement += abs_diff(head, tracks[i]);
            head = tracks[i];
        }
    }

    printf("Average head movement: %.2f\n", (float)total_head_movement / n);
}

int main() {
    int tracks[] = {55, 58, 60, 70, 18};
    int num_tracks = sizeof(tracks) / sizeof(tracks[0]);
    int initial_head_position = 50; // Change this to the starting head position

    CLOOK(tracks, num_tracks, initial_head_position);

}
