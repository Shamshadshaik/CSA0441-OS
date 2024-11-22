#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, seek_time = 0;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    int requests[n];

    printf("Enter the disk requests: ");
    for (int i = 0; i < n; i++) scanf("%d", &requests[i]);

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Head movement: %d", head);
    for (int i = 0; i < n; i++) {
        seek_time += abs(requests[i] - head);
        printf(" -> %d", requests[i]);
        head = requests[i];
    }

    printf("\nTotal seek time: %d\n", seek_time);
    return 0;
}

