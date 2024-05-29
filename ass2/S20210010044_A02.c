/*
    NAME:- ABHISHIKTH BODA
    COURSE:- ADSA
    ASSIGNMENT NUMBER:- 2
    DATE:- 23-08-2022
*/

#include <stdio.h>

// Functions used
void swap(int *a, int *b)
{
    // Function to swap two elements
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void insertion(int n, int a[])
{
    // Function to sort elements through insertion sort.
    int temp, j;
    for (int i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while (a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

void print_array(int n, int a[])
{
    // Function to print element of an array
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

// Main function for question 1
int q1()
{
    // Insertion sort takes fewer time so we are implementing through it.
    int n;
    int a[n];
    printf("Enter the number of book\n");
    scanf("%d", &n);
    printf("Enter the ID of books to be sorted\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    insertion(n, a);
    printf("IDs of books after sorting\n");
    print_array(n, a);
}

void bubble_sort(int n, int a[])
{
    // Function to bubble sort the elements
    int swap_count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        // Loop will run till i<n-1 since there are n-1 passes.
        for (int j = 0; j < n - i - 1; j++)
        {
            // Loop will run till j<n-i-1 since there will in n-i-1 comparisions in each pass
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
                swap_count++;
                // By incrementing swap count we will get the number of swap by the end of sorting
            }
            // One complete iteration of this loop indicates completion of a pass
        }
    }
    printf("No of swaps performed is %d\n", swap_count);
}
// Main function for Question 2
int q2()
{
    int n;
    int a[n];

    printf("Enter the number of elements\n");
    scanf("%d", &n);
    printf("Enter the elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    bubble_sort(n, a);
}
// Main function for Question 3
int q3()
{
    int t, n, x;
    int a[n];
    int count_same = 0;
    int count_x;
    printf("Enter the number of testcases\n");
    scanf("%d", &t);
    while (t--)
    {
        printf("Enter the number of elements in array and number of distinct integers\n");
        scanf("%d %d", &n, &x);
        printf("Enter the %d elements\n", n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n - i; j++)
            {
                if (a[i] == a[j])
                {
                    count_same++;
                }
            }
        }
        count_x = n - count_same;
        if (count_x > x)
        {
            printf("Average\n");
        }
        else if (count_x = x)
        {
            printf("Good\n");
        }
        else
        {
            printf("Bad\n");
        }
    }
}

void q4_sort(int n, int a[])
{
    // Function for sorting elements
    int swap_count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
                swap_count++;
            }
        }
    }
}

void solve(int k, int a[], int n)
{
    // Function for solving question 4
    int sum = 0;
    int soln[k];
    for (int i = 0; i < k; i++)
    {
        soln[i] = a[n - i - 1];
    }
    for (int i = 0; i < k; i++)
    {
        sum += soln[i];
    }
    printf("Answer is %d\n", sum);
}

// Main function for Question 4
int q4()
{

    int n, k;
    int a[n];

    printf("Enter the number of elements and value of k\n");
    scanf("%d %d", &n, &k);
    printf("Enter the elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    q4_sort(n, a);
    solve(k, a, n);
}

// Driver Code
int main()
{
    printf("Question 1\n");
    q1();
    printf("Question 1 executed successfully\n\n");
    printf("Question 2\n");
    q2();
    printf("Question 2 executed successfully\n\n");
    printf("Question 3\n");
    q3();
    printf("Question 3 executed successfully\n\n");
    printf("Question 4\n");
    q4();
    printf("Question 4 executed successfully\n\n");
    return 0;
}