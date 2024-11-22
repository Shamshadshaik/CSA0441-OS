#include <stdio.h>

int main() {
    int n, m; 
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int allocation[n][m], max[n][m], available[m];
    int need[n][m], safeSequence[n], finish[n];

    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);

    printf("Enter the maximum matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter the available resources:\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &available[i]);

   
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - allocation[i][j];

     int count = 0;
while (count < n) {
    int found = 0;
    for (int i = 0; i < n && !finish[i]; i++) {
        int canAllocate = 1;
        for (int j = 0; j < m; j++)
            if (need[i][j] > available[j]) canAllocate = 0;

        if (canAllocate) {
            for (int j = 0; j < m; j++) 
			available[j] += allocation[i][j];
            safeSequence[count++] = i;
            finish[i] = found = 1;
        }
    }
    if (!found) return printf("Unsafe state.\n"), 0;
}
printf("Safe sequence: ");
for (int i = 0; i < n; i++) 
printf("P%d ", safeSequence[i]);
}
