/*
NAME:- ABHISHIKTH BODA
COURSE:- ADSA
ASSIGNMENT NUMBER:- 12
DATE:- 15-11-2022
*/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

// Functions for Question 1
int max_of_two(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int knapsack_solution(int items, int cap, int w_arr[], int val_arr[])
{
    if (items == 0 || cap == 0)
    {
        return 0;
    }

    else if (w_arr[items - 1] > cap)
    {
        return knapsack_solution(items - 1, cap, w_arr, val_arr);
    }

    else
    {
        int element_1 = val_arr[items - 1] + knapsack_solution(items - 1, cap - w_arr[items - 1], w_arr, val_arr);
        int element_2 = knapsack_solution(items - 1, cap, w_arr, val_arr);
        return max_of_two(element_1, element_2);
    }
}

// Driver code for Question 1
void q1()
{

    int n;
    int capacity;

    printf("Enter the number of items:-\n");
    scanf("%d", &n);

    int weight_array[n];
    int value_array[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the %dth element of the weight array\n", i + 1);
        scanf("%d", &weight_array[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %dth element of the value array\n", i + 1);
        scanf("%d", &value_array[i]);
    }

    printf("Enter the capacity of the knapsack:-\n");
    scanf("%d", &capacity);

    int q1_ans = knapsack_solution(n, capacity, weight_array, value_array);
    printf("The maximum possible profit is %d", q1_ans);
}

// Functions for Question 2

#define INF 999

void floyd_warshall_sol(int adj[][4])
{
    int path[4][4];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            path[i][j] = adj[i][j];
        }
    }

    for (int k = 0; k < 4; k++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if ((path[i][k] + path[k][j]) < path[i][j])
                {
                    path[i][j] = path[i][k] + path[k][j];
                }
            }
        }
    }

    printf("The below matrix represents the shortest path between every pair of vertices.\n");

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (path[i][j] == INF)
            {
                printf("%7s", INF);
            }
            else
            {
                printf("%7d", path[i][j]);
            }
        }
        printf("\n");
    }
}

// Driver code for Question 2
void q2()
{
    int adj_matrix[4][4] = {{0, 8, INF, 1}, {INF, 0, 1, INF}, {4, INF, 0, INF}, {INF, 2, 9, 0}};

    floyd_warshall_sol(adj_matrix);
}

// Functions for Question 3
int coinChange(int *coins, int coinsSize, int amount)
{
    int *dp = (int *)malloc((amount + 1) * sizeof(int));
    for (int i = 0; i <= amount; i++)
    {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;

    for (int amt = 1; amt <= amount; amt++)
    {
        int minimal_coin_count = INT_MAX;
        for (int j = 0; j < coinsSize; j++)
        {
            if (amt >= coins[j])
            {
                if (minimal_coin_count > dp[amt - coins[j]])
                {
                    minimal_coin_count = dp[amt - coins[j]];
                }
            }
        }
        if (minimal_coin_count != INT_MAX)
        {
            dp[amt] = minimal_coin_count + 1;
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

// Driver code for Question 3
void q3()
{
    int coins[] = {1, 2, 5};
    int n = sizeof(coins) / sizeof(int);
    int amount = 11;
    printf("Fewer no.of coins required for amount is: %d\n", coinChange(coins, n, amount));
}

// Driver code
void main()
{
    printf("****************************\n\n");
    printf("NAME:- ABHISHIKTH BODA\nCOURSE:- ADSA\nASSIGNMENT NUMBER:- 12\nDATE:- 15-11-2022\n\n");
    printf("****************************\n\n");

    printf("****************************\n\n");
    printf("Question 1 \n\n");
    q1();
    printf("\n");
    printf("****************************\n\n");

    printf("****************************\n\n");
    printf("Question 2 \n\n");
    q2();
    printf("\n");
    printf("****************************\n\n");

    printf("****************************\n\n");
    printf("Question 3 \n\n");
    q3();
    printf("\n");
    printf("****************************\n\n");
}