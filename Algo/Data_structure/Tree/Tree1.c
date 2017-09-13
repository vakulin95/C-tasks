//Реализаця обхода бинарного дерева поиска в глубину
#include <stdio.h>
#include <stdlib.h>

typedef struct tree Tree;

struct tree
{
    int x;
    Tree *left;
    Tree *right;
};

Tree *init(int);
void add(Tree*, int);
void write(Tree*, int);
void pre_oder_write(Tree*);
void sym_oder_write(Tree*);
void post_oder_write(Tree*);
void func(Tree*);

int main()
{
    int i;
    int M[] = {10, 4, 8, 23, 45, 71, 3, 11, 5}; // 10

    Tree *root = init(M[0]);

    for(i = 1; i < 9; i++)
        add(root, M[i]);

    write(root, 0);

    printf("Pre oder write: \t");
    pre_oder_write(root);
    printf("\n");

    printf("Symmetric oder write: \t");
    sym_oder_write(root);
    printf("\n");

    printf("Post oder write: \t");
    post_oder_write(root);
    printf("\n");

    return 0;
}

Tree *init(int x)
{
    Tree *node = (Tree*)malloc(sizeof(Tree));

    node->x = x;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void add(Tree *root, int x)
{
    Tree *node = init(x);
    Tree *prev;

    while(root)
    {
        prev = root;
        if(x >= root->x)
            root = root->right;
        else if(x < root->x)
            root = root->left;
    }

    (x >= prev->x) ? (prev->right = node) : (prev->left = node);
}

void write(Tree *root, int level)
{
    int i;

    if(root)
    {
        write(root->right, level + 1);

        for(i = 0; i < level; i++)
            printf("\t");
        printf("%d\n", root->x);

        write(root->left, level + 1);
    }
}

void pre_oder_write(Tree *root)
{
    if(root)
    {
        func(root);
        pre_oder_write(root->left);
        pre_oder_write(root->right);
    }
}

void sym_oder_write(Tree *root)
{
    if(root)
    {
        sym_oder_write(root->left);
        func(root);
        sym_oder_write(root->right);
    }
}

void post_oder_write(Tree *root)
{
    if(root)
    {
        post_oder_write(root->left);
        post_oder_write(root->right);
        func(root);
    }
}

void func(Tree *x)
{
    printf("%d ", x->x);
}
