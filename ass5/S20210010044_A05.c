/*
    NAME:- ABHISHIKTH BODA
    COURSE:- ADSA
    ASSIGNMENT NUMBER:- 5
    DATE:- 20-09-2022
*/
#include <stdio.h>
#include <stdlib.h>
struct Node_q1
{
    int data;
    struct Node_q1 *left_to_node;
    struct Node_q1 *right_to_node;
    int tree_height;
};
int find_max_val(int i, int j);
int tree_height(struct Node_q1 *k)
{
    if (k == NULL)
        return 0;
    return k->tree_height;
}
int find_max_val(int i, int j)
{
    return (i > j) ? i : j;
}
struct Node_q1 *newNode(int data)
{
    struct Node_q1 *node = (struct Node_q1 *)
        malloc(sizeof(struct Node_q1));
    node->data = data;
    node->left_to_node = NULL;
    node->right_to_node = NULL;
    node->tree_height = 1;
    return (node);
}
struct Node_q1 *rRotate(struct Node_q1 *b)
{
    struct Node_q1 *a = b->left_to_node;
    struct Node_q1 *T2 = a->right_to_node;
    a->right_to_node = b;
    b->left_to_node = T2;
    b->tree_height = find_max_val(tree_height(b->left_to_node), tree_height(b->right_to_node)) + 1;
    a->tree_height = find_max_val(tree_height(a->left_to_node), tree_height(a->right_to_node)) + 1;
    return a;
}
struct Node_q1 *lRotate(struct Node_q1 *a)
{
    struct Node_q1 *b = a->right_to_node;
    struct Node_q1 *T2 = b->left_to_node;
    b->left_to_node = a;
    a->right_to_node = T2;
    a->tree_height = find_max_val(tree_height(a->left_to_node), tree_height(a->right_to_node)) + 1;
    b->tree_height = find_max_val(tree_height(b->left_to_node), tree_height(b->right_to_node)) + 1;
    return b;
}
int getBalance(struct Node_q1 *k)
{
    if (k == NULL)
        return 0;
    return tree_height(k->left_to_node) - tree_height(k->right_to_node);
}
struct Node_q1 *insertion_into_avl_tree(struct Node_q1 *node, int data)
{
    if (node == NULL)
        return (newNode(data));
    if (data < node->data)
        node->left_to_node = insertion_into_avl_tree(node->left_to_node, data);
    else if (data > node->data)
        node->right_to_node = insertion_into_avl_tree(node->right_to_node, data);
    else
        return node;
    node->tree_height = 1 + find_max_val(tree_height(node->left_to_node), tree_height(node->right_to_node));
    int balance = getBalance(node);
    if (balance > 1 && data < node->left_to_node->data)
    {
        printf("Rotation performed is:- left left\n");
        return rRotate(node);
    }

    if (balance < -1 && data > node->right_to_node->data)
    {
        printf("Rotation performed is:- right right\n");
        return lRotate(node);
    }
    if (balance > 1 && data > node->left_to_node->data)
    {
        node->left_to_node = lRotate(node->left_to_node);
        printf("Rotation performed is:- left right\n");
        return rRotate(node);
    }
    if (balance < -1 && data < node->right_to_node->data)
    {
        node->right_to_node = rRotate(node->right_to_node);
        printf("Rotation performed is:- right left\n");
        return lRotate(node);
    }
    return node;
}
struct Node_q1 *minValueNode(struct Node_q1 *node)
{
    struct Node_q1 *current = node;
    while (current->left_to_node != NULL)
        current = current->left_to_node;
    return current;
}
void inOrder(struct Node_q1 *rootnode)
{
    if (rootnode != NULL)
    {
        inOrder(rootnode->left_to_node);
        printf("%d ", rootnode->data);
        inOrder(rootnode->right_to_node);
    }
}
struct Node_q1 *join_avl(struct Node_q1 *root1, struct Node_q1 *root2)
{
    int k = root2->data;
    if (root1 == NULL)
    {
        return root2;
    }
    else
    {
        if (root1->data > k)
        {
            root1->left_to_node = join_avl(root1->left_to_node, root2);
        }
        else if (root1->data < k)
        {
            root1->right_to_node = join_avl(root1->right_to_node, root2);
        }
        else
        {
            return root1;
        }
    }
    root1->tree_height = tree_height(root1);
    int balance = getBalance(root1);
    if (balance > 1 && k < root1->left_to_node->data)
    {
        printf("LL rotation\n");
        return rRotate(root1);
    }
    if (balance > 1 && k > root1->left_to_node->data)
    {
        root1->left_to_node = lRotate(root1->left_to_node);
        printf("LR rotation\n");
        return rRotate(root1);
    }
    if (balance < -1 && k > root1->right_to_node->data)
    {
        printf("RR rotation\n");
        return rRotate(root1);
    }
    if (balance < -1 && k < root1->right_to_node->data)
    {
        root1->right_to_node = rRotate(root1->right_to_node);
        printf("RL rotation\n");
        return lRotate(root1);
    }
    return root1;
}
void q1()
{
    struct Node_q1 *rootnode1 = NULL;
    printf("****************************\n");
    rootnode1 = insertion_into_avl_tree(rootnode1, 13);
    rootnode1 = insertion_into_avl_tree(rootnode1, 24);
    rootnode1 = insertion_into_avl_tree(rootnode1, 52);
    rootnode1 = insertion_into_avl_tree(rootnode1, 37);
    rootnode1 = insertion_into_avl_tree(rootnode1, 44);

    printf("****************************\n");
    printf("inorder traversal of the constructed AVL tree T1 is\n");
    inOrder(rootnode1);
    printf("\n\n");

    printf("****************************\n");
    struct Node_q1 *rootnode2 = NULL;
    rootnode2 = insertion_into_avl_tree(rootnode2, 111);
    rootnode2 = insertion_into_avl_tree(rootnode2, 92);
    rootnode2 = insertion_into_avl_tree(rootnode2, 87);
    rootnode2 = insertion_into_avl_tree(rootnode2, 70);
    rootnode2 = insertion_into_avl_tree(rootnode2, 213);
    printf("****************************\n");
    printf("inorder traversal of the constructed AVL tree T2 is\n");
    inOrder(rootnode2);
    printf("\n\n");

    printf("****************************\n");
    printf("inorder traversal of merged AVL tree is\n");
    rootnode1 = join_avl(rootnode1, rootnode2);
    inOrder(rootnode1);
    printf("\n");
    printf("****************************\n");
}

struct node
{
    int value;
    char colour_of_node;
    struct node *parent_pointer;
    struct node *right_pointer;
    struct node *left_pointer;
};

struct node *root = NULL;

struct node *red_black_tree(struct node *head, struct node *temporary)
{
    if (head == NULL)
    {
        return temporary;
    }

    if (temporary->value < head->value)
    {
        head->left_pointer = red_black_tree(head->left_pointer, temporary);
        head->left_pointer->parent_pointer = head;
    }
    else if (temporary->value > head->value)
    {
        head->right_pointer = red_black_tree(head->right_pointer, temporary);
        head->right_pointer->parent_pointer = head;
    }

    return head;
}

void clock_wise_rotation(struct node *temporary)
{
    struct node *left = temporary->left_pointer;
    temporary->left_pointer = left->right_pointer;
    if (temporary->left_pointer)
    {
        temporary->left_pointer->parent_pointer = temporary;
    }
    left->parent_pointer = temporary->parent_pointer;
    if (!temporary->parent_pointer)
    {
        root = left;
    }
    else if (temporary == temporary->parent_pointer->left_pointer)
        temporary->parent_pointer->left_pointer = left;
    else
        temporary->parent_pointer->right_pointer = left;
    left->right_pointer = temporary;
    temporary->parent_pointer = left;
}

void anti_clock_wise_rotation(struct node *temporary)
{
    struct node *right = temporary->right_pointer;
    temporary->right_pointer = right->left_pointer;
    if (temporary->right_pointer)
        temporary->right_pointer->parent_pointer = temporary;
    right->parent_pointer = temporary->parent_pointer;
    if (!temporary->parent_pointer)
        root = right;
    else if (temporary == temporary->parent_pointer->left_pointer)
        temporary->parent_pointer->left_pointer = right;
    else
        temporary->parent_pointer->right_pointer = right;
    right->left_pointer = temporary;
    temporary->parent_pointer = right;
}

void pre_order_traversal_of_the_tree(struct node *head)
{
    if (head == NULL)
    {
        return;
    }
    printf("%d ", head->value);
    pre_order_traversal_of_the_tree(head->left_pointer);
    pre_order_traversal_of_the_tree(head->right_pointer);
}

void post_order_traversal_of_the_tree(struct node *head)
{
    if (head == NULL)
    {
        return;
    }
    post_order_traversal_of_the_tree(head->left_pointer);
    post_order_traversal_of_the_tree(head->right_pointer);
    printf("%d ", head->value);
}

void recolourization_and_rearrangement(struct node *root, struct node *pt)
{
    struct node *pointer_to_parent = NULL;
    struct node *pointer_to_grandparent = NULL;

    while ((pt != root) && (pt->colour_of_node != 'b') && (pt->parent_pointer->colour_of_node == 'r'))
    {
        pointer_to_parent = pt->parent_pointer;
        pointer_to_grandparent = pt->parent_pointer->parent_pointer;

        if (pointer_to_parent == pointer_to_grandparent->left_pointer)
        {

            struct node *pointer_to_uncle = pointer_to_grandparent->right_pointer;

            if (pointer_to_uncle != NULL && pointer_to_uncle->colour_of_node == 'r')
            {
                pointer_to_grandparent->colour_of_node = 'r';
                pointer_to_parent->colour_of_node = 'b';
                pointer_to_uncle->colour_of_node = 'b';
                pt = pointer_to_grandparent;
            }

            else
            {

                if (pt == pointer_to_parent->right_pointer)
                {
                    anti_clock_wise_rotation(pointer_to_parent);
                    pt = pointer_to_parent;
                    pointer_to_parent = pt->parent_pointer;
                }

                clock_wise_rotation(pointer_to_grandparent);
                char t = pointer_to_parent->colour_of_node;
                pointer_to_parent->colour_of_node = pointer_to_grandparent->colour_of_node;
                pointer_to_grandparent->colour_of_node = t;
                pt = pointer_to_parent;
            }
        }

        else
        {
            struct node *pointer_to_uncle = pointer_to_grandparent->left_pointer;
            if ((pointer_to_uncle != NULL) && (pointer_to_uncle->colour_of_node == 'r'))
            {
                pointer_to_grandparent->colour_of_node = 'r';
                pointer_to_parent->colour_of_node = 'b';
                pointer_to_uncle->colour_of_node = 'b';
                pt = pointer_to_grandparent;
            }
            else
            {
                if (pt == pointer_to_parent->left_pointer)
                {
                    clock_wise_rotation(pointer_to_parent);
                    pt = pointer_to_parent;
                    pointer_to_parent = pt->parent_pointer;
                }
                anti_clock_wise_rotation(pointer_to_grandparent);
                char t = pointer_to_parent->colour_of_node;
                pointer_to_parent->colour_of_node = pointer_to_grandparent->colour_of_node;
                pointer_to_grandparent->colour_of_node = t;
                pt = pointer_to_parent;
            }
        }
    }

    root->colour_of_node = 'b';
}

void in_order_traversal_of_the_tree(struct node *head)
{
    if (head == NULL)
    {
        return;
    }
    in_order_traversal_of_the_tree(head->left_pointer);
    printf("%d ", head->value);
    in_order_traversal_of_the_tree(head->right_pointer);
}

void q2()
{
    int array[6] = {41, 38, 31, 12, 19, 8};

    for (int i = 0; i < 6; i++)
    {
        struct node *temporary = (struct node *)malloc(sizeof(struct node));
        temporary->right_pointer = NULL;
        temporary->left_pointer = NULL;
        temporary->parent_pointer = NULL;
        temporary->value = array[i];
        temporary->colour_of_node = 'r';
        root = red_black_tree(root, temporary);
        recolourization_and_rearrangement(root, temporary);
    }

    printf("Inorder Traversal of Created Tree\n");
    in_order_traversal_of_the_tree(root);
}

int main()
{
    printf("****************************\n");
    printf("NAME:- ABHISHIKTH BODA\nCOURSE:- ADSA\nASSIGNMENT NUMBER:- 5\nDATE:- 20-09-2022\n\n");
    printf("****************************\n");
    printf("Question 1 \n");
    q1();
    printf("\n");

    printf("Question 1 executed successfully\n\n");
    printf("****************************\n");
    printf("Question 2\n");
    q2();

    printf("\n");

    printf("Question 2 executed successfully\n\n");
    printf("****************************\n");
    return 0;
}