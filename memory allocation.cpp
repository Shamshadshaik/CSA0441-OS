#include <stdio.h>

int main() {
    int blockSize[] = {100, 500, 200, 300, 600}, processSize[] = {212, 417, 112, 426};
    int m = 5, n = 4, allocation[4] = {-1, -1, -1, -1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("Process\tSize\tBlock\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%s\n", i + 1, processSize[i], allocation[i] != -1 ? "Allocated" : "Not Allocated");
    }

    return 0;
}

