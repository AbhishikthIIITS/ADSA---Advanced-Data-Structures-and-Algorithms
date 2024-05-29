/*
NAME:- ABHISHIKTH BODA
COURSE:- ADSA
ASSIGNMENT NUMBER:- 11
DATE:- 11-11-2022
*/

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>


//Functions for Question 1
void print_prim(int a1[], int g[9][9])
{

    int sum = 0;

    printf("  Edge        Weight\n\n");

    for (int i = 1; i < 9; i++)
    {
        printf("%c <-> %c  :-     %d\n", a1[i]+65, i+65, g[i][a1[i]]);

        sum += g[i][a1[i]];
    }

    printf("\nMinimum Cost using Prim's Algorithm %d \n", sum);
}

int find_min(int b[], bool r[])
{

    int minimum = INT_MAX;
    int minimum_index;

    for (int i = 0; i < 9; i++)
    {
        if (r[i] == false && b[i] < minimum)
        {
            minimum = b[i];
            minimum_index = i;
        }
    }

    return minimum_index;
}

void prim_spanning_tree(int a[9][9])
{

    int mst_array[9];
    int weight_array[9];
    bool mstSet_array[9];

    for (int i = 0; i < 9; i++)
    {

        weight_array[i] = INT_MAX;
        mstSet_array[i] = false;
    }

    weight_array[0] = 0;
    mst_array[0] = -1;

    for (int j = 0; j < 9; j++)
    {

        int min_vertex = find_min(weight_array, mstSet_array);

        mstSet_array[min_vertex] = true;

        for (int k = 0; k < 9; k++)
        {
            if (a[j][k] && mstSet_array[k] == false && a[j][k] < weight_array[k])
            {
                mst_array[k] = j;
                weight_array[k] = a[j][k];
            }
        }
    }

    print_prim(mst_array, a);
}

//Driver code for Question 1
void q1()
{

    int matrix[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, {4, 0, 8, 0, 0, 0, 0, 11, 0}, {0, 8, 0, 7, 0, 4, 0, 0, 2}, {0, 0, 7, 0, 9, 14, 0, 0, 0}, {0, 0, 0, 9, 0, 10, 0, 0, 0}, {0, 0, 4, 14, 10, 0, 2, 0, 0}, {0, 0, 0, 0, 0, 2, 0, 1, 6}, {8, 11, 0, 0, 0, 0, 1, 0, 7}, {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    prim_spanning_tree(matrix);
}



#define size_1 9

//Functions for Question 2
int mst_array_1[size_1];

int find(int i)
{
	while (mst_array_1[i] != i)
		i = mst_array_1[i];
	return i;
}

void union1(int i, int j)
{
	int a = find(i);
	int b = find(j);
	mst_array_1[a] = b;
}

void kruskal_spanning_tree(int cost[][size_1])
{
	int mincost = 0;
	for (int i = 0; i < size_1; i++)
		mst_array_1[i] = i;

	int count = 0;
    printf("  Edge        Weight\n\n");
	while (count < size_1 - 1) {
		int min = 1000, a = -1, b = -1;
		for (int i = 0; i < size_1; i++) {
			for (int j = 0; j < size_1; j++) {
				if (find(i) != find(j) && cost[i][j] < min) {
					min = cost[i][j];
					a = i;
					b = j;
				}
			}
		}

		union1(a, b);
		printf("%c <-> %c  :-     %d\n", a+65, b+65, min);
        count++,
		mincost += min;
	}
	printf("\nMinimum Cost using Kruskal's Algorithm %d \n", mincost);
}

//Driver code for Question 2
void q2()
{
	int graph[size_1][size_1] = {{1000, 4, 1000, 1000, 1000, 1000, 1000, 8, 1000},
									{4, 1000 ,8, 1000, 1000, 1000, 1000, 11, 1000},
									{1000, 8, 1000, 7, 1000, 4, 1000, 1000, 2},
									{1000, 1000, 7, 1000, 9, 14, 1000, 1000, 1000},
									{1000, 1000, 1000, 9, 1000, 10, 1000, 1000, 1000},
									{1000, 1000, 4, 14, 10, 1000, 2, 1000, 1000},
									{1000, 1000, 1000, 1000, 1000, 2, 1000, 1, 6},
									{8, 11, 1000, 1000, 1000, 1000, 1, 1000, 7},
									{1000, 1000, 2, 1000, 1000, 1000, 6, 7, 1000}};

	kruskal_spanning_tree(graph);

}

//Functions for Question 3
void prims_reasons(){
    printf("\nPRIM'S ALGORITM\n\n");
    printf("Let's start from vertice A\n");
    printf("edge (A,B) accepted since it has minimum value among the adjacent edges\n");
    printf("edge (B,C) accepted since it has minimum value among the adjacent edges\n");
    printf("edge (C,D) accepted since it has minimum value among the adjacent edges\n");
    printf("edge (D,E) accepted since it has minimum value among the adjacent edges\n");
    printf("edge (C,F) accepted since it has minimum value among the adjacent edges\n");
    printf("edge (F,G) accepted since it has minimum value among the adjacent edges\n");
    printf("edge (G,H) accepted since it has minimum value among the adjacent edges\n");
    printf("edge (C,I) accepted since it has minimum value among the adjacent edges\n");
    printf("edge (A,H) rejected since it does not have minimum value among the adjacent edges\n");
    printf("edge (B,H) rejected since it does not have minimum value among the adjacent edges\n");
    printf("edge (H,I) rejected since it does not have minimum value among the adjacent edges\n");
    printf("edge (I,G) rejected since it does not have minimum value among the adjacent edges\n");
    printf("edge (F,D) rejected since it does not have minimum value among the adjacent edges\n");
    printf("edge (F,E) rejected since it does not have minimum value among the adjacent edges\n");
}


void kruskals_reasons(){
    printf("\nKRUSKAL'S ALGORITM\n\n");
    printf("Let's start from edges with length 1\n");
    printf("edge (H,G) accepted since it has 1 and it does not form a cycle in the current tree\n");
    printf("There are no more edges with weight 1\n");
    printf("Now check edges with length 2\n");
    printf("edge (F,G) accepted since it has 2 and it does not form a cycle in the current tree\n");
    printf("edge (C,I) accepted since it has 2 and it does not form a cycle in the current tree\n");
    printf("There are no more edges with weight 2\n");
    printf("Now check edges with length 3\n");
    printf("There are no more edges with weight 3\n");
    printf("Now check edges with length 4\n");
    printf("edge (F,C) accepted since it has 4 and it does not form a cycle in the current tree\n");
    printf("edge (A,B) accepted since it has 4 and it does not form a cycle in the current tree\n");
    printf("There are no more edges with weight 4\n");
    printf("Now check edges with length 5\n");
    printf("There are no more edges with weight 5\n");
    printf("Now check edges with length 6\n");
    printf("edge (I,G) rejected since it has 6 and it forms a cycle in the current tree\n");
    printf("There are no more edges with weight 6\n");
    printf("Now check edges with length 7\n");
    printf("edge (C,D) accepted since it has 7 and it does not form a cycle in the current tree\n");
    printf("edge (I,H) rejected since it has 7 and it forms a cycle in the current tree\n");
    printf("There are no more edges with weight 7\n");
    printf("Now check edges with length 8\n");
    printf("edge (A,H) accepted since it has 8 and it does not form a cycle in the current tree\n");
    printf("edge (B,C) rejected since it has 8 and it forms a cycle in the current tree\n");
    printf("There are no more edges with weight 8\n");
    printf("Now check edges with length 9\n");
    printf("edge (D,E) accepted since it has 9 and it does not form a cycle in the current tree\n");
    printf("There are no more edges with weight 9\n");
    printf("Now check edges with length 10\n");
    printf("edge (E,F) rejected since it has 10 and it forms a cycle in the current tree\n");
    printf("There are no more edges with weight 10\n");
    printf("Now check edges with length 11\n");
    printf("edge (B,H) rejected since it has 11 and it forms a cycle in the current tree\n");
    printf("There are no more edges with weight 11\n");
    printf("Now check edges with length 12\n");
    printf("There are no more edges with weight 12\n");
    printf("Now check edges with length 13\n");
    printf("There are no more edges with weight 13\n");
    printf("Now check edges with length 14\n");
    printf("edge (D,F) rejected since it has 14 and it forms a cycle in the current tree\n");
    printf("There are no more edges with weight 14\n");
    printf("There are no more edges in the graph\n");
}

//Driver code for Question 3
void q3(){
    prims_reasons();
    kruskals_reasons();
}


//Driver code
void main()
{
    printf("****************************\n\n");
    printf("NAME:- ABHISHIKTH BODA\nCOURSE:- ADSA\nASSIGNMENT NUMBER:- 10\nDATE:- 01-11-2022\n\n");
    printf("****************************\n\n");

    printf("****************************\n\n");
    printf("Question 1 \n\n");
    printf("Minimum Spanning tree produced using Prim's Algoritm is:- \n\n");
    q1();
    printf("\n");
    printf("****************************\n\n");

    printf("****************************\n\n");
    printf("Question 2 \n\n");
    printf("Minimum Spanning tree produced using Kruskal’s Algoritm is:- \n\n");
    q2();
    printf("\n");
    printf("****************************\n\n");

    printf("****************************\n\n");
    printf("Question 3 \n\n");
    printf("Explanation of the algorithm\n\n");
    q3();
    printf("\n");
    printf("****************************\n\n");
}