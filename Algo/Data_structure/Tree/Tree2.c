//Реализация обхода бинарного дерева в ширину
#include <stdio.h>
#include <stdlib.h>

typedef struct tree Tree;
typedef struct queue Queue;

struct tree
{
    int x;
    Tree *left;
    Tree *right;
};

struct queue
{
    Tree *x;
    Queue *next;
};

Tree *init_tree(int);
void add_tree(Tree*, int);
void write_tree(Tree*, int);

Queue *init_queue(Tree*);
void add_queue(Queue**, Tree*);
Tree *del_queue(Queue**);
void write_queue(Queue*);

void bypassing_wide(Tree*);

void func(Tree*);

int main()
{
    int i;
    int M[] = {10, 4, 8, 23, 45, 71, 3, 11, 5}; // 9    

    Tree *root = init_tree(M[0]);

    for(i = 1; i < 9; i++)
        add_tree(root, M[i]);

    write_tree(root, 0);
    bypassing_wide(root);

    return 0;
}

Tree *init_tree(int x)
{
    Tree *node = (Tree*)malloc(sizeof(Tree));

    node->x = x;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void add_tree(Tree *root, int x)
{
    Tree *node = init_tree(x);
    Tree *prev;

    while(root)
    {
        prev = root;
        if(x >= root->x)
            root = root->right;
        else if(x < root->x)
            root = root->left;
    }

    if(x >= prev->x)
        prev->right = node;
    else
        prev->left = node;
}

void write_tree(Tree *root, int level)
{
    int i;

    if(root)
    {
        write_tree(root->right, level + 1);

        for(i = 0; i < level; i++)
            printf("\t");
        printf("%d\n", root->x);

        write_tree(root->left, level + 1);
    }
}


Queue *init_queue(Tree *root)
{
    Queue *node = (Queue*)malloc(sizeof(Queue));

    node->x = root;
    node->next = NULL;

    return node;
}

void add_queue(Queue **pend, Tree *x)
{
    Queue *node = init_queue(x);

    (*pend)->next = node;
    *pend = node;
}

Tree *del_queue(Queue **pbeg)
{
    Tree *Y;
    Queue *node = *pbeg;

    Y = (*pbeg)->x;
    if((*pbeg)->next)
    {
        *pbeg = (*pbeg)->next;
    }
    free(node);

    return Y;
}

void write_queue(Queue *pbeg)
{
    while(pbeg)
    {
        printf("%d ", (pbeg->x)->x);
        pbeg = pbeg->next;
    }
    printf("\n");
}

void bypassing_wide(Tree *root)
{
    int size = 1;
    Queue *pbeg = init_queue(root);
    Queue *pend = pbeg;
    Tree *node;

    while(size)
    {
        node = del_queue(&pbeg);
        size--;
        func(node);

        if(node->right)
        {
            add_queue(&pend, node->right);
            size++;
        }
        if(node->left)
        {
            add_queue(&pend, node->left);
            size++;
        }
    }
}

void func(Tree *root)
{
    // printf("Tree node with value %d has been processed!\n", root->x);
    printf("%d\n", root->x);
}



















//
