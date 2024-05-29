#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* right;
    struct node* left;
};

struct node * createnode(int data){
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->right = NULL;
    n->left = NULL;
    return n;
}

static int count_internal = 0;
static int count_external = 0;

void check(struct node* p){
    if((p->right == NULL) && (p->left == NULL)){
        count_external++;
    }
    else count_internal++;
}
int q1(){
    struct node *a = createnode(10);
    struct node *a1 = createnode(20);
    struct node *a2 = createnode(50);
    struct node *a3 = createnode(30);
    struct node *a4 = createnode(60);
    struct node *a5 = createnode(80);
    struct node *a6 = createnode(35);
    struct node *a7 = createnode(45);
    struct node *a8 = createnode(77);
    struct node *a9 = createnode(90);
    struct node *a10 = createnode(95);
    struct node *a11 = createnode(98);
    struct node *a12 = createnode(67);
    struct node *a13 = createnode(88);
    
    a->left = a1;
    a->right = a2;
    a->left->left = a3;
    a->left->right = a4;
    a->right->left = a5;
    a->right->right = a6;
    a->left->left->left = a7;
    a->left->left->right = a8;
    a->left->right->left = a9;
    a->left->right->right = a10;
    a->right->left->left = a11;
    a->right->left->right = a12;
    a->right->right->left = a13;

    check(a);
    check(a1);
    check(a2);
    check(a3);
    check(a4);
    check(a5);
    check(a6);
    check(a7);
    check(a8);
    check(a9);
    check(a10);
    check(a11);
    check(a12);
    check(a13);

    printf("Number of internal nodes is %d\n Number of external nodes is %d\n", count_internal,count_external);
}


int findMax(int n,int a[n]){
    int max = a[0];
    for(int i=1;i<n;i++){
        if(a[i]>max){
            max = a[i];
        }
    }
    return max;
}

void count_sort(int n, int a[n],int p){
    
    int out[n+1];
    
    int count[10];
    for(int i = 0;i<10;i++){
        count[i]=0;
    }

    for (int i = 0; i < n; i++)
    {
        count[(a[i]/p)%10]++;
    }

    for(int i = 1;i<10;i++){
        count[i]+=count[i-1];
    }
    for(int i = n-1;i>=0;i--){
        out[count[(a[i]/p)%10]-1]=a[i];
        count[(a[i]/p)%10]--;
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = out[i];
    }
    
}

void radix(int n,int a[n]){
    int p = findMax(n,a);
    for(int i = 1;(p/i)>0;i*=10){
        count_sort(n,a,i);
    }
}

void printarray(int n,int a[n]){
    for(int i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int q2(){
    int n;
    int a[n];
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    for(int i = 0;i<n;i++){
        scanf("%d", &a[i]);
    }
    printf("Elements before sorting\n");
    printarray(n,a);
    radix(n,a);
    printf("Elements after sorting\n");
    printarray(n,a);
}

struct node *insert(struct node *node,int data){
    if(node == NULL){
        return createnode(data);
    }
    else if(data < node->data){
        node->left = insert(node->left,data);
    }
    else node->right = insert(node->right,data);
    return node;
}

void inorder(struct node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int q3(){
    struct node *root = NULL;
    root = insert(root,5);
    root = insert(root,3);
    root = insert(root,2);
    root = insert(root,4);
    root = insert(root,1);
    root = insert(root,10);
    root = insert(root,7);
    root = insert(root,11);
    root = insert(root,6);
    root = insert(root,9);
    root = insert(root,8);
    root = insert(root,12);
    //QUESTION 3a
    printf("Inorder traversal\n");
    inorder(root);
    printf("\n");
    
}

int main(){
    printf("Question 1\n");
    q1();
    printf("Question 1 executed successfully\n\n");
    printf("Question 2\n");
    q2();
    printf("Question 2 executed successfully\n\n");
    printf("Question 3\n");
    q3();
    printf("Question 3 executed successfully\n\n");
    return 0;
}