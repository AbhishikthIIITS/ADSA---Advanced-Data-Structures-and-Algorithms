#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
    int h;
};

struct node *createNode(int val){
    struct node *node = (struct node*)malloc(sizeof(struct node));
    node->data = val;
    node->left = node->right = NULL;
    node->h = 0;
    return node;
}

int height(struct node *n){
    if(n == NULL){
        return -1;
    }
    else{
        int l_height = height(n->left);
        int r_height = height(n->right);

        if(l_height>r_height){
            return 1+l_height;
        } 
        else return 1+r_height;
    }
}

int balance(struct node *n){
    if(n == NULL){
    return 0;
    }
    else return (height(n->left) - height(n->right));
}

struct node *clockwise(struct node *n){
    struct node *n1 = n->left;
    struct node *n_sub = n1->right;

    n1->right = n;
    n->left = n_sub;

    n->h = height(n);
    n1->h = height(n1);

    return n1;
}

int max(int a,int b){
    if(a>b){
        return a;
    }
    else return b;
}

struct node *anticlockwise(struct node *n){
    struct node *n1 = n->right;
    struct node *n_sub = n1->left;

    n1->left = n;
    n->right = n_sub;

    n->h = height(n);
    n1->h = height(n1);

    return n1;
}

struct node *insert(int val,struct node *n){
    if(n == NULL){
        return createNode(val);
    }
    else if(val < n->data){
        n->left = insert(val,n->left);
    }
    else if(val > n->data){
        n->right  = insert(val,n->right);
    }
    else return n;

    n->h = height(n);

    int bal = balance(n);

    if(bal>1 && val < n->left->data){
        printf("LL rotation\n");
        return clockwise(n);
    }

    else if(bal > 1 && val>n->left->data){
        printf("LR rotation\n");
        n->left = anticlockwise(n->left);
        return clockwise(n);
    }

    else if(bal < -1 && val> n->right->data){
        printf("RR rotation\n");
        return anticlockwise(n);
    }

    else if(bal<-1 && val<n->left->data){
        printf("RL rotation\n");
        n->right = clockwise(n->right);
        return anticlockwise(n);
    }

    return n;
}

void inorder(struct node *n){
    
    if(n != NULL){
        inorder(n->left);
        printf("%d ", n->data);
        inorder(n->right);
    }
}

struct node * newVal(struct node* n)
{
    struct node* p = n;
    while (p->left != NULL)
        p = p->left;
 
    return p;
}
 

struct node* deleteNode(struct node* n, int val)
{
    if (n == NULL){
        return n;
    }
    if ( val < n->data ){
        n->left = deleteNode(n->left, val);
    }
    else if( val > n->data ){
        n->right = deleteNode(n->right, val);
    }
    else
    {
        if( (n->left == NULL) || (n->right == NULL) )
        {
            struct node *temp = n->left ? n->left :n->right;
 
            if (temp == NULL)
            {
                temp = n;
                n = NULL;
            }
            else{
                *n = *temp;
            }
            free(temp);
        }
        else
        {
            struct node* temp = newVal(n->right);
            n->data = temp->data;
            n->right = deleteNode(n->right, temp->data);
        }
    }
 
    if (n == NULL){
      return n;
    }
    n->h = 1 + max(height(n->left),height(n->right));
 
    int bal = balance(n);
 
    if (bal > 1 && balance(n->left) >= 0){
        return clockwise(n);
    } 
    if (bal > 1 && balance(n->left) < 0)
    {
        n->left =  anticlockwise(n->left);
        return clockwise(n);
    }
 
    if (bal < -1 && balance(n->right) <= 0)
        return anticlockwise(n);
 
    if (bal < -1 && balance(n->right) > 0)
    {
        n->right = clockwise(n->right);
        return anticlockwise(n);
    }
 
    return n;
}

int main(){
    printf("NAME:- ABHISHIKTH BODA\nCOURSE:- ADSA\nASSIGNMENT NUMBER:- 4\nDATE:- 06-09-2022\n\n");
    printf("Question 1 \n");
    
    printf("Rotations performed are:- \n");
    struct node* head = NULL;

    head = insert(12,head);
    head = insert(14,head);
    head = insert(15,head);
    head = insert(17,head);
    head = insert(3,head);
    head = insert(4,head);
    head = insert(9,head);
    head = insert(10,head);
    head = insert(20,head);

    

    printf("Inorder traversal of the tree is:- \n");
    inorder(head);
    printf("\n");
    
    printf("Question 1 executed successfully\n\n");
    
    
    printf("Question 2\n");
    for(int i = 0;i<9;i++){
        head = deleteNode(head,head->data);
        
        printf("Inorder traversal of the tree is:- \n");
        inorder(head);
        printf("\n");
    }
    
    printf("Question 2 executed successfully\n\n");

    return 0;
}
