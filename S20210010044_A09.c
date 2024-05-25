/*
NAME:- ABHISHIKTH BODA
COURSE:- ADSA
ASSIGNMENT NUMBER:- 9
DATE:- 25-10-2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int N;
int visit[100];
int Adjacency_Matrix[100][100];
int Count = 0;

// Implementing queue functionalities
int queue[1000];
int front = -1, rear = -1;

int pop()
{
    return queue[front++];
}

void push(int tempInt)
{
    if (front == -1)
    {
        front = 0, rear = 0;
        queue[0] = tempInt;
    }
    else
    {
        queue[++rear] = tempInt;
    }
}

int isEmpty()
{
    if (front > rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Question 2a
void DFS(int k)
{
    visit[k] = 1;
    Count++;
    printf("%d ", k);
    for (int i = 1; i <= N; i++)
    {
        if (Adjacency_Matrix[k][i] && !visit[i])
        {
            DFS(i);
        }
    }
}

// Question 2b
void IsConnected()
{
    if (Count == N)
    {
        printf("\n\nIt's a Connected Graph.\n\n");
    }
    else
    {
        printf("\n\nThis Graph is Not Connected.\n\n");
    }
}

// Question 1
void Read_Graph()
{
    scanf("%d", &N);
    while (1)
    {
        int src, dest;
        scanf("%d %d", &src, &dest);
        if (src == 0 && dest == 0)
        {
            break;
        }

        Adjacency_Matrix[src][dest] = 1;
        Adjacency_Matrix[dest][src] = 1;
    }
}

// Question 3
void BFS()
{
    int distance[100];
    memset(visit, 0, sizeof(visit));
    for (int i = 1; i <= N; i++)
    {
        distance[i] = INT_MAX;
    }

    visit[1] = 1;
    distance[1] = 0;

    push(1);

    while (!isEmpty())
    {
        int popped = pop();
        printf("%i ", popped);
        for (int i = 1; i <= N; i++)
        {
            if (Adjacency_Matrix[i][popped] && !visit[i])
            {
                visit[i] = 1;
                distance[i] = distance[popped] + 1;
                push(i);
            }
        }
    }

    printf("\n\nDistances From Node 1:\n\n");
    for (int i = 1; i <= N; i++)
    {
        printf("1 ---> %i = ", i);
        if (distance[i] == INT_MAX)
        {
            printf("There is no possible path between the vertices 1 and %i \n", i);
        }
        else
        {
            printf("%d\n", distance[i]);
        }
    }
}

void main()
{
    printf("****************************\n\n");
    printf("NAME:- ABHISHIKTH BODA\nCOURSE:- ADSA\nASSIGNMENT NUMBER:- 9\nDATE:- 25-10-2022\n\n");
    printf("****************************\n");

    memset(Adjacency_Matrix, 0, sizeof(Adjacency_Matrix));
    memset(visit, 0, sizeof(visit));

    printf("****************************\n\n");
    printf("Question 1 \n");
    printf("Calling Read_Graph function\n");
    Read_Graph();
    printf("\n\nGraph is created.\n\n");
    printf("****************************\n");

    printf("****************************\n\n");
    printf("Question 2 a\n");
    printf("Calling DFS function\n\n");
    printf("DFS result of the given graph is: ");
    DFS(1);

    printf("\n\n");

    printf("Question 2 b\n");
    printf("Calling isConnected function\n");
    printf("\nChecking the connection state of the graph: ");
    IsConnected();
    printf("****************************\n");

    printf("****************************\n\n");
    printf("Question 3\n");
    printf("Calling BFS function\n");
    printf("BFS result of the given graph is: ");
    BFS();
    printf("\n");
    printf("****************************\n");
}