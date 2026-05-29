
#include <stdio.h>

#define MAX 20
#define INF 9999

int parent[MAX];

/* Find function */
int find(int i) {
    while(parent[i])
        i = parent[i];

    return i;
}

/* Union function */
int uni(int i, int j) {

    if(i != j) {
        parent[j] = i;
        return 1;
    }

    return 0;
}

int main() {

    int cost[MAX][MAX];
    int n, i, j;

    int min, minCost = 0;

    int a, b, u, v;

    int edges = 1;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {

            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("\nEdges in Minimum Spanning Tree:\n");

    while(edges < n) {

        min = INF;

        /* Find minimum edge */
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {

                if(cost[i][j] < min) {

                    min = cost[i][j];

                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        /* Avoid cycle */
        if(uni(u, v)) {

            printf("%d --> %d  Cost = %d\n", a, b, min);

            minCost += min;

            edges++;
        }

        cost[a][b] = cost[b][a] = INF;
    }

    printf("\nMinimum Cost = %d\n", minCost);

    return 0;
}
