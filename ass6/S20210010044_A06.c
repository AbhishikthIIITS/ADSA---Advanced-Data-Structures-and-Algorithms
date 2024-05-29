/*
    NAME:- ABHISHIKTH BODA
    COURSE:- ADSA
    ASSIGNMENT NUMBER:- 6
    DATE:- 27-09-2022
*/

#include <stdio.h>
#include <stdlib.h>

enum COLOR
{
    Red,
    Black
};

typedef struct red_black_tree_node
{
    int data;
    struct red_black_tree_node *right_ptr;
    struct red_black_tree_node *left_ptr;
    struct red_black_tree_node *parent;
    enum COLOR color;
} red_black_tree_node;

typedef struct red_black_tree
{
    red_black_tree_node *root;
    red_black_tree_node *NIL;
} red_black_tree;

red_black_tree_node *create_red_black_tree_node(int data)
{
    red_black_tree_node *n = malloc(sizeof(red_black_tree_node));
    n->left_ptr = NULL;
    n->right_ptr = NULL;
    n->parent = NULL;
    n->data = data;
    n->color = Red;

    return n;
}

red_black_tree *new_red_black_tree()
{
    red_black_tree *t = malloc(sizeof(red_black_tree));
    red_black_tree_node *nil_node = malloc(sizeof(red_black_tree_node));
    nil_node->left_ptr = NULL;
    nil_node->right_ptr = NULL;
    nil_node->parent = NULL;
    nil_node->color = Black;
    nil_node->data = 0;
    t->NIL = nil_node;
    t->root = t->NIL;

    return t;
}

void left_ptr_rotate(red_black_tree *t, red_black_tree_node *x)
{
    red_black_tree_node *y = x->right_ptr;
    x->right_ptr = y->left_ptr;
    if (y->left_ptr != t->NIL)
    {
        y->left_ptr->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == t->NIL)
    { 
        t->root = y;
    }
    else if (x == x->parent->left_ptr)
    { 
        x->parent->left_ptr = y;
    }
    else
    { 
        x->parent->right_ptr = y;
    }
    y->left_ptr = x;
    x->parent = y;
}

void right_ptr_rotate(red_black_tree *t, red_black_tree_node *x)
{
    red_black_tree_node *y = x->left_ptr;
    x->left_ptr = y->right_ptr;
    if (y->right_ptr != t->NIL)
    {
        y->right_ptr->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == t->NIL)
    { 
        t->root = y;
    }
    else if (x == x->parent->right_ptr)
    { 
        x->parent->right_ptr = y;
    }
    else
    { 
        x->parent->left_ptr = y;
    }
    y->right_ptr = x;
    x->parent = y;
}

void insertion_fixup(red_black_tree *t, red_black_tree_node *z)
{
    while (z->parent->color == Red)
    {
        if (z->parent == z->parent->parent->left_ptr)
        { 

            red_black_tree_node *y = z->parent->parent->right_ptr; 

            if (y->color == Red)
            {
                z->parent->color = Black;
                y->color = Black;
                z->parent->parent->color = Red;
                z = z->parent->parent;
            }
            else
            { 
                if (z == z->parent->right_ptr)
                {                 
                    z = z->parent;
                    left_ptr_rotate(t, z);
                }
                z->parent->color = Black;       
                z->parent->parent->color = Red; 
                right_ptr_rotate(t, z->parent->parent);
            }
        }
        else
        {                                           
            red_black_tree_node *y = z->parent->parent->left_ptr;

            if (y->color == Red)
            {
                z->parent->color = Black;
                y->color = Black;
                z->parent->parent->color = Red;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->left_ptr)
                {
                    z = z->parent; 
                    right_ptr_rotate(t, z);
                }
                z->parent->color = Black;       
                z->parent->parent->color = Red; 
                left_ptr_rotate(t, z->parent->parent);
            }
        }
    }
    t->root->color = Black;
}

void insert(red_black_tree *t, red_black_tree_node *z)
{
    red_black_tree_node *y = t->NIL;
    red_black_tree_node *temp = t->root;

    while (temp != t->NIL)
    {
        y = temp;
        if (z->data < temp->data)
            temp = temp->left_ptr;
        else
            temp = temp->right_ptr;
    }
    z->parent = y;

    if (y == t->NIL)
    { 
        t->root = z;
    }
    else if (z->data < y->data) 
        y->left_ptr = z;
    else
        y->right_ptr = z;

    z->right_ptr = t->NIL;
    z->left_ptr = t->NIL;

    insertion_fixup(t, z);
}

void rb_transplant(red_black_tree *t, red_black_tree_node *u, red_black_tree_node *v)
{
    if (u->parent == t->NIL)
        t->root = v;
    else if (u == u->parent->left_ptr)
        u->parent->left_ptr = v;
    else
        u->parent->right_ptr = v;
    v->parent = u->parent;
}

red_black_tree_node *minimum(red_black_tree *t, red_black_tree_node *x)
{
    while (x->left_ptr != t->NIL)
        x = x->left_ptr;
    return x;
}

void rb_delete_fixup(red_black_tree *t, red_black_tree_node *x)
{
    while (x != t->root && x->color == Black)
    {
        if (x == x->parent->left_ptr)
        {
            red_black_tree_node *w = x->parent->right_ptr;
            if (w->color == Red)
            {
                w->color = Black;
                x->parent->color = Red;
                left_ptr_rotate(t, x->parent);
                w = x->parent->right_ptr;
            }
            if (w->left_ptr->color == Black && w->right_ptr->color == Black)
            {
                w->color = Red;
                x = x->parent;
            }
            else
            {
                if (w->right_ptr->color == Black)
                {
                    w->left_ptr->color = Black;
                    w->color = Red;
                    right_ptr_rotate(t, w);
                    w = x->parent->right_ptr;
                }
                w->color = x->parent->color;
                x->parent->color = Black;
                w->right_ptr->color = Black;
                left_ptr_rotate(t, x->parent);
                x = t->root;
            }
        }
        else
        {
            red_black_tree_node *w = x->parent->left_ptr;
            if (w->color == Red)
            {
                w->color = Black;
                x->parent->color = Red;
                right_ptr_rotate(t, x->parent);
                w = x->parent->left_ptr;
            }
            if (w->right_ptr->color == Black && w->left_ptr->color == Black)
            {
                w->color = Red;
                x = x->parent;
            }
            else
            {
                if (w->left_ptr->color == Black)
                {
                    w->right_ptr->color = Black;
                    w->color = Red;
                    left_ptr_rotate(t, w);
                    w = x->parent->left_ptr;
                }
                w->color = x->parent->color;
                x->parent->color = Black;
                w->left_ptr->color = Black;
                right_ptr_rotate(t, x->parent);
                x = t->root;
            }
        }
    }
    x->color = Black;
}

void rb_delete(red_black_tree *t, red_black_tree_node *z)
{
    red_black_tree_node *y = z;
    red_black_tree_node *x;
    enum COLOR y_orignal_color = y->color;
    if (z->left_ptr == t->NIL)
    {
        x = z->right_ptr;
        rb_transplant(t, z, z->right_ptr);
    }
    else if (z->right_ptr == t->NIL)
    {
        x = z->left_ptr;
        rb_transplant(t, z, z->left_ptr);
    }
    else
    {
        y = minimum(t, z->right_ptr);
        y_orignal_color = y->color;
        x = y->right_ptr;
        if (y->parent == z)
        {
            x->parent = z;
        }
        else
        {
            rb_transplant(t, y, y->right_ptr);
            y->right_ptr = z->right_ptr;
            y->right_ptr->parent = y;
        }
        rb_transplant(t, z, y);
        y->left_ptr = z->left_ptr;
        y->left_ptr->parent = y;
        y->color = z->color;
    }
    if (y_orignal_color == Black)
        rb_delete_fixup(t, x);
}

void inorder(red_black_tree *t, red_black_tree_node *n)
{
    if (n != t->NIL)
    {
        inorder(t, n->left_ptr);
        printf("%d ", n->data);
        inorder(t, n->right_ptr);
    }

}

int q1()
{
    red_black_tree *t = new_red_black_tree();

    red_black_tree_node *a, *b, *c, *d, *e, *f;
    a = create_red_black_tree_node(41);
    b = create_red_black_tree_node(38);
    c = create_red_black_tree_node(31);
    d = create_red_black_tree_node(12);
    e = create_red_black_tree_node(19);
    f = create_red_black_tree_node(8);

    insert(t, a);
    insert(t, b);
    insert(t, c);
    insert(t, d);
    insert(t, e);
    insert(t, f);

    printf("Inorder traversal of the tree:- ");
    inorder(t, t->root);
    printf("\n");
    rb_delete(t, f);
    printf("Inorder traversal of the tree after deleting 8:- ");
    inorder(t, t->root);
    printf("\n");
    rb_delete(t, e);
    printf("Inorder traversal of the tree after deleting 12:- ");
    inorder(t, t->root);
    printf("\n");
    rb_delete(t, d);
    printf("Inorder traversal of the tree after deleting 19:- ");
    inorder(t, t->root);
    printf("\n");
    rb_delete(t, c);
    printf("Inorder traversal of the tree after deleting 31:- ");
    inorder(t, t->root);
    printf("\n");
    rb_delete(t, b);
    printf("Inorder traversal of the tree after deleting 38:- ");
    inorder(t, t->root);
    printf("\n");
    rb_delete(t, a);
    printf("Inorder traversal of the tree after deleting 41:- ");
    inorder(t, t->root);
    printf("\n");
    return 0;
}


struct bst
{
    struct bst *left;
    struct bst *right;
    int data;
};


void insert_bst(struct bst **root, int data)
{
    struct bst *temp = (struct bst *)malloc(sizeof(struct bst));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    struct bst *t = *root;

    if (*root == NULL)
    {
        *root = temp;
        return;
    }
    if (data < t->data)
        insert_bst(&(t->left), data);
    else
        insert_bst(&(t->right), data);
}

void inorder_traversal(struct bst *root)
{
    if (root != NULL)
    {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

void find_ancestor(struct bst *root, int key)
{
    if(root == NULL){ 
    return;
    }

     if(key > root->data){
        printf("%d ", root->data);
        find_ancestor(root->right, key);  
    }
    else if(key < root->data){
        printf("%d ", root->data);
        find_ancestor(root->left, key);
    }
}
int q2()
{
    struct bst *root = NULL;
    int i, n, data;
    printf("enter no. of elements\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &data);
        insert_bst(&root, data);
    }
    printf("Inorder traversal of the tree:- ");
    inorder_traversal(root);
    printf("\n");

    int key;
    printf("enter value of element whose ansector we need\n");
    scanf("%d", &key);
    printf("\n");
    printf("Ancestors of %d are:- ", key);
    find_ancestor(root, key);
}

int main()
{
    printf("****************************\n");
    printf("****************************\n\n");
    printf("NAME:- ABHISHIKTH BODA\n");
    printf("COURSE:- ADSA\n");
    printf("ASSIGNMENT NUMBER:- 6\n");
    printf("DATE:- 27-09-2022\n\n");
    printf("****************************\n");
    printf("****************************\n\n");
    printf("Question 1 \n");
    q1();
    printf("\n");

    printf("Question 1 executed successfully\n\n");
    printf("****************************\n");
    printf("****************************\n\n");
    printf("Question 2\n");
    q2();

    printf("\n");

    printf("Question 2 executed successfully\n\n");
    printf("****************************\n");
    printf("****************************\n\n");
    return 0;
}