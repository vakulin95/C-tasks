//Реализация дерева из учебника Павловской
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NOBJ 10

typedef struct node Node;

struct node
{
    int d;
    Node *left;
    Node *right;
};

Node *first(int);
Node *search_insert(Node*, int);
void print_tree(Node*, int);

int main()
{
    int i;
    int tree[NOBJ];
    Node *root;

    srand(time(0));

    for(i = 0; i < NOBJ; ++i)
        printf("%d ", tree[i] = rand() % 100);
    printf("\n");

    root = first(tree[0]);
    for(i = 0; i < NOBJ; ++i)
        search_insert(root, tree[i]);

    print_tree(root, 0);

    return 0;
}

Node *first(int d)
{
    Node *pv = (Node*)malloc(sizeof(Node));

    pv->d = d;
    pv->left = NULL;
    pv->right = NULL;

    return pv;
}

Node *search_insert(Node *root, int d)
{
    Node *pv = root, *prev;
    int found = 0;

    while(pv && !found)
    {
        prev = pv;

        if(d == pv->d)
            found = 1;
        else if(d < pv->d)
            pv = pv->left;
        else
            pv = pv->right;
    }
    if(found)
        return pv;

    Node *pnew = (Node*)malloc(sizeof(Node));
    pnew->d = d;
    pnew->left = NULL;
    pnew->right = NULL;
    if(d < prev->d)
        prev->left = pnew;
    else
        prev->right = pnew;

    return pnew;
}

void print_tree(Node *p, int level)
{
    int i;

    if(p)
    {
        print_tree(p->left, level + 1);

        for(i = 0; i < level; ++i)
            printf("\t");
        printf("%d\n", p->d);

        print_tree(p->right, level + 1);
    }
}
