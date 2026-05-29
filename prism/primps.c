
#include <stdio.h>

#define INF 9999
#define MAX 20

int main() {

    int n, i, j;

    int cost[MAX][MAX];

    int visited[MAX] = {0};

    int min, minCost = 0;
    int a, b, u, v;

    int edges = 1;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {

            scanf("%d", &cost[i][j]);

            /* Replace 0 with INF except diagonal */
            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    visited[0] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while(edges < n) {

        min = INF;

        for(i = 0; i < n; i++) {

            if(visited[i]) {

                for(j = 0; j < n; j++) {

                    if(!visited[j] && cost[i][j] < min) {

                        min = cost[i][j];

                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        printf("%d --> %d  Cost = %d\n", a, b, min);

        minCost += min;

        visited[b] = 1;

        edges++;
    }

    printf("\nMinimum Cost = %d\n", minCost);

    return 0;
}
