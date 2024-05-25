/*
NAME:- ABHISHIKTH BODA
COURSE:- ADSA
ASSIGNMENT NUMBER:- 13
DATE:- 22-11-2022
*/


#include <stdio.h>
#include <String.h>

int matrix[125][125];
char String1[125] = "TTCTACGGGGGGAGACCTTTACGAATCACACCGGTCTTCTTTGTTCTAGCCGCTCTTTTTCATCAGTTGCAGCTAGTGCATAATTGCTCACAAACGTATC";
char String2[125] = "TCTACGGGGGGCGTCATTACGGAATCCACACAGGTCGTTATGTTCATCTGTCTCTTTTCACAGTTGCGGCTTGTGCATAATGCTCACGAACGTATC";
char b[150][150];

void find_common_seq()
{
    int l1 = strlen(String1);
    int l2 = strlen(String2);

    for (int i = 0; i <= l1; i++)
    {
        matrix[i][0] = 0;
    }
    for (int i = 0; i <= l2; i++)
    {
        matrix[0][i] = 0;
    }

    for (int i = 1; i <= l1; i++)
    {
        for (int j = 1; j <= l2; j++)
        {
            if (String1[i - 1] == String2[j - 1])
            {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            }
            else if (matrix[i - 1][j] >= matrix[i][j - 1])
            {
                matrix[i][j] = matrix[i - 1][j];
            }
            else
            {
                matrix[i][j] = matrix[i][j - 1];
            }
        }
    }

    int key = matrix[l1][l2];
    printf("Length the longest common subsequence is %d", key);
}

void q1()
{
    find_common_seq();
}



#define A 0
#define B 1
#define C 2
#define MAX_NODES 1000
#define O 1000000000

int n;
int e;
int cap[MAX_NODES][MAX_NODES];
int flow[MAX_NODES][MAX_NODES];
int color[MAX_NODES];
int pred[MAX_NODES];

int min(int x, int y) {
  return x < y ? x : y;
}

int head, tail;
int q[MAX_NODES + 2];

void enqueue(int x) {
  q[tail] = x;
  tail++;
  color[x] = B;
}

int dequeue() {
  int x = q[head];
  head++;
  color[x] = C;
  return x;
}

int bfs(int start, int target) {
  int u, v;
  for (u = 0; u < n; u++) {
    color[u] = A;
  }
  head = tail = 0;
  enqueue(start);
  pred[start] = -1;
  while (head != tail) {
    u = dequeue();
    for (v = 0; v < n; v++) {
      if (color[v] == A && cap[u][v] - flow[u][v] > 0) {
        enqueue(v);
        pred[v] = u;
      }
    }
  }
  return color[target] == C;
}

int find_max_flow(int source, int sink) {
  int i, j, u;
  int max_flow = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      flow[i][j] = 0;
    }
  }

  while (bfs(source, sink)) {
    int increment = O;
    for (u = n - 1; pred[u] >= 0; u = pred[u]) {
      increment = min(increment, cap[pred[u]][u] - flow[pred[u]][u]);
    }
    for (u = n - 1; pred[u] >= 0; u = pred[u]) {
      flow[pred[u]][u] += increment;
      flow[u][pred[u]] -= increment;
    }
    max_flow += increment;
  }
  return max_flow;
}

void q2() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cap[i][j] = 0;
    }
  }
  n = 6;
  e = 7;

  cap[0][1] = 16;
  cap[0][3] = 13;
  cap[1][2] = 12;
  cap[1][3] = 10;
  cap[2][3] = 9;
  cap[2][5] = 20;
  cap[3][1] = 4;
  cap[3][4] = 14;
  cap[4][2] = 7;
  cap[4][5] = 4;

  int s = 0, t = 5;
  printf("Max Flow: %d\n", find_max_flow(s, t));
}


void main(){
    printf("\n****************************\n\n");
    printf("NAME:- ABHISHIKTH BODA\nCOURSE:- ADSA\nASSIGNMENT NUMBER:- 13\nDATE:- 22-11-2022\n\n");
    printf("****************************\n\n");

    printf("****************************\n\n");
    printf("Question 1:- \n");
    printf("Finding length of longest common subsequence:- \n\n");
    q1();
    printf("\n\n");
    printf("****************************\n\n");

    printf("****************************\n\n");
    printf("Question 2:- \n");
    printf("Finding maximum flow of the given graph:- \n\n");
    q2();
    printf("\n");
    printf("****************************\n\n");
}