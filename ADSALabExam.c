/*
NAME:- ABHISHIKTH BODA
ROLL NUMBER:- S20210010044
COURSE:- ADSA
END LAB EXAM
DATE:- 06-12-2022
*/


#include <stdio.h>

//Functions for question 1
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void merge_sort(int n, int a[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
    //Initially I had done this question with merge sort.
    //but I was getting an error 
    //and wasn't able to solve it.
    //So I solved this using bubbble sort.

}

void q1_solve(int wanted_no_of_tickets, int no_of_tickets, int price[])
{
    int answer = 0;
    int iterator = no_of_tickets - wanted_no_of_tickets;
    for (int i = no_of_tickets - 1; i > iterator - 1; i--)
    {
        answer = answer + price[i];
    }
    printf("\nThe amount required for buying %d tickets is %d\n", wanted_no_of_tickets, answer);
}


//Driver code for question 1
void q1()
{
    int n, q;
    printf("Enter the number of lottery tickets\n");
    scanf("%d", &n);

    printf("Enter the number of queries\n");
    scanf("%d", &q);
    int price[n];
    int score[n];
    int query[q];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the price of %dth lottery ticket\n", i + 1);
        scanf("%d", &price[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter the score of %dth lottery ticket\n", i + 1);
        scanf("%d", &score[i]);
    }

    for (int i = 0; i < q; i++)
    {
        printf("Enter the %dth number of lottery ticket wants to be purchased\n", i + 1);
        scanf("%d", &query[i]);
    }

    merge_sort(n, price);
    merge_sort(n, score);

    for (int i = 0; i < q; i++)
    {
        q1_solve(query[i], n, price);
    }
}


//Functions for question 2
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

int mile_constraint;

int billboard_dp(int boards, int tot_dist, int d_arr[], int rev_arr[])
{
    if (boards == 0 || tot_dist == 0)
    {
        return 0;
    }

    else if (d_arr[boards - 1] > tot_dist)
    {
        return billboard_dp(boards - 1, tot_dist, d_arr, rev_arr);
    }

    else
    {
        int element_1 = rev_arr[boards - 1] + billboard_dp(boards - 1, tot_dist - mile_constraint, d_arr, rev_arr);
        int element_2 = billboard_dp(boards - 1, tot_dist, d_arr, rev_arr);
        return max_of_two(element_1, element_2);
    }
}

//Driver code for question2
void q2()
{

    int n;
    int highway_distance;

    printf("Enter the number of billboards:-\n");
    scanf("%d", &n);

    int distance_array[n];
    int revenue_array[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the %dth element of the distance array\n", i + 1);
        scanf("%d", &distance_array[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %dth element of the revenue array\n", i + 1);
        scanf("%d", &revenue_array[i]);
    }

    printf("Enter the total distance of the highway:-\n");
    scanf("%d", &highway_distance);

    printf("Enter the distance constraint of the highway:-\n");
    scanf("%d", &mile_constraint);

    int q2_ans = billboard_dp(n, highway_distance, distance_array, revenue_array);
    printf("\nThe maximum possible revenue is %d\n", q2_ans);
}


//Driver code
void main()
{
    printf("\n****************************");
    printf("\n****************************\n\n");
    printf("NAME:- ABHISHIKTH BODA\nROLL NUMBER:- S20210010044\nCOURSE:- ADSA\nEND LAB EXAM\nDATE:- 06-12-2022\n\n");
    printf("****************************\n");

    printf("****************************\n\n");
    printf("Question 1:- \n");
    printf("Finding money required to buy lottery tickets:- \n");
    printf("Using merge sort\n\n");
    q1();
    printf("\n\n");
    printf("****************************\n");

    printf("****************************\n\n");
    printf("Question 2:- \n");
    printf("Finding maximum revenue for placing billboards on a highway:- \n");
    printf("Using dynamic programming\n\n");
    q2();
    printf("\n");
    printf("****************************\n");
    printf("****************************\n\n");
    printf("Program executed successfully\n");
}