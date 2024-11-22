#include <stdio.h>

struct Process { int id, priority, burstTime; };

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n], temp;
    for (int i = 0; i < n; i++) {
        printf("Enter priority and burst time for P%d: ", i + 1);
        p[i] = (struct Process){i + 1};
        scanf("%d %d", &p[i].priority, &p[i].burstTime);
    }

    for (int i = 0; i < n; i++)  
        for (int j = i + 1; j < n; j++)
            if (p[i].priority < p[j].priority)
                temp = p[i], p[i] = p[j], p[j] = temp;

    printf("\nExecution Order:\n");
    for (int i = 0; i < n; i++)
        printf("P%d (Priority: %d, Burst: %d)\n", p[i].id, p[i].priority, p[i].burstTime);

    return 0;
}

