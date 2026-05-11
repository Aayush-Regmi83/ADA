#include <stdio.h>

// Function to find maximum of two numbers
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

// Function to solve 0/1 Knapsack using Bottom-Up DP
int knapsack(int W[], int P[], int n, int M)
{
    int V[n + 1][M + 1];

    // Build table V[][] in bottom-up manner
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            // Base condition
            if (i == 0 || j == 0)
            {
                V[i][j] = 0;
            }

            // If current item's weight is more than capacity
            else if (W[i - 1] > j)
            {
                V[i][j] = V[i - 1][j];
            }

            // Maximum of including or excluding the item
            else
            {
                V[i][j] = max(V[i - 1][j],
                              V[i - 1][j - W[i - 1]] + P[i - 1]);
            }
        }
    }

    return V[n][M];
}

int main()
{
    int n, M;

    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    int W[n], P[n];

    // Input weights
    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &W[i]);
    }

    // Input profits
    printf("Enter profits of items:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &P[i]);
    }

    // Input knapsack capacity
    printf("Enter knapsack capacity: ");
    scanf("%d", &M);

    // Function call
    int result = knapsack(W, P, n, M);

    // Output result
    printf("Maximum Profit = %d\n", result);

    return 0;
}