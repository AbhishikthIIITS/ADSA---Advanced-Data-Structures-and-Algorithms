#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Functions for Question 1

int paranthesis()
{
    char str[100];
    int n, count;
    printf("Enter your string\n");
    scanf(" %s", str);
    n = strlen(str);
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 40)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (str[j] == 41)
                {
                    count = 1;
                }
                else
                    count = 0;
            }
        }
        else if (str[i] == 91)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (str[j] == 93)
                {
                    count = 1;
                }
                else
                    count = 0;
            }
        }
        else if (str[i] == 123)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (str[j] == 125)
                {
                    count = 1;
                }
                else
                    count = 0;
            }
        }
    }
    if (count == 1)
        printf("True\n");
    else
        printf("False\n");
    return 0;
}

// Functions for question 2

struct node
{
    int data;
    struct node *next;
};

struct node *concatenation(struct node *ll_1, struct node *ll_2)
{
    if (ll_1 != NULL && ll_2 != NULL)
    {
        if (ll_1->next == NULL)
        {
            ll_1->next = ll_2;
        }
        else
        {
            concatenation(ll_1->next, ll_2);
        }
    }
    else
    {
        printf("Either ll_1 or ll_2 is NULL\n");
    }
    return ll_1;
}

void show_node(struct node *head)
{
    if (head == NULL)
    {
        printf("\n");
    }
    else
    {
        printf("%d ", head->data);
        show_node(head->next);
    }
}

int conc()
{
    struct node *prev, *ll_1, *ll_2, *c, *ptr;
    int n, i, m;
    printf("Enter number of elements in Linked list 1: \n");
    scanf("%d", &m);
    ll_1 = NULL;
    printf("Elements of Linked List 1 are: \n");
    for (i = 0; i < m; i++)
    {
        ptr = malloc(sizeof(struct node));
        scanf("%d", &ptr->data);
        ptr->next = NULL;
        if (ll_1 == NULL)
        {
            ll_1 = ptr;
        }
        else
        {
            prev->next = ptr;
        }
        prev = ptr;
    }
    printf("Enter number of elements in Linked list 2: \n");
    scanf("%d", &n);
    ll_2 = NULL;
    printf("Elements of Linked List 2 are: \n");
    for (i = 0; i < n; i++)
    {
        ptr = malloc(sizeof(struct node));
        scanf("%d", &ptr->data);
        ptr->next = NULL;
        if (ll_2 == NULL)
        {
            ll_2 = ptr;
        }
        else
        {
            prev->next = ptr;
        }
        prev = ptr;
    }
    concatenation(ll_1, ll_2);
    c = NULL;
    for (i = 0; i < m + n; i++)
    {
        ptr = malloc(sizeof(struct node));
        ptr->data = ll_1->data;
        ll_1 = ll_1->next;
        ptr->next = NULL;
        if (c == NULL)
            c = ptr;
        else
            prev->next = ptr;
        prev = ptr;
    }
    printf("Linked List after Concatenation: \n");
    show_node(c);
}

//Function for Question 3

int disc_ordering(){
    int n;
	printf("Enter the number of disks: \n");
    scanf("%d",&n);
    int q;
    int temp[100001]={0};
    int size=n,min=n;
    for(int i=0;i<n;i++){
        scanf("%d",&q);
        temp[q] = q;
        if(q == min){
            while(temp[size]){
                printf("%d ",temp[size]);
                size--;
            }
        }
        min=size;
        printf("\n");
    }
    return 0;
}

//Functions for Question 4

int apple_sort()
{
    int n, i, j;
    long long int a[10000], temp;
    long long int sum1 = 0, med, median, ans = 0;
    printf("Enter number of boys\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the number of apples with %d th boy\n: ", i+1);
        scanf("%lld", &a[i]);
        sum1 += a[i];
    }
    med = sum1 / n;
    for (i = 0; i < n; i++)
    {
        a[i] -= med;
    }
    for (i = 1; i < n; i++)
    {
        a[i] += a[i - 1];
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    if (n % 2 != 0)
    {
        median = a[n / 2];
    }
    else
    {
        median = (a[n / 2] + a[n / 2 - 1]) / 2;
    }
    for (i = 0; i < n; i++)
    {
        a[i] -= median;
        if (a[i] < 0)
        {
            a[i] *= -1;
        }
        ans += a[i];
    }
    printf("Minimal number of steps to make each boy have the same number of apples is\n");
    printf("%lld\n", ans);
    return 0;
}

int main()
{
    printf("Question 1\n");
    paranthesis();
    printf("Question 1 executed successfully\n\n");
    printf("Question 2\n");
    conc();
    printf("Question 2 executed successfully\n\n");
    printf("Question 3\n");
    disc_ordering();
    printf("Question 3 executed successfully\n\n");
    printf("Question 4\n");
    apple_sort();
    printf("Question 4 executed successfully\n\n");
}