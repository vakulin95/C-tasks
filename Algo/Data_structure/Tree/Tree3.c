// Поиск в бинарных деревьях
#include <stdio.h>
#include <stdlib.h>

typedef struct tree Tree;

struct tree
{
    char x;
    Tree *left;
    Tree *right;
};

Tree *init(char);
void sort_add(Tree*, char);
void write(Tree*, int);
Tree *search(Tree*, char);
void loop_search(Tree*, char*);

int main()
{
    int i;
    char M[] = {10, 4, 8, 23, 45, 71, 4, 3, 11, 5}; // 10
    Tree *root = init(*M);

    for(i = 1; i < 10; ++i)
        sort_add(root, *(M + i));
    write(root, 0);

    loop_search(root, M);

    return 0;
}

Tree *init(char x)
{
    Tree *node = (Tree*)malloc(sizeof(Tree));

    node->x = x;
    node->left = NULL;
    node->right = NULL;
}

void sort_add(Tree *root, char x)
{
    Tree *node = init(x);
    Tree *prev;

    while(root)
    {
        prev = root;

        if(x == root->x)
            return;

        if(x > root->x)
            root = root->right;
        else
            root = root->left;
    }

    if(x > prev->x)
        prev->right = node;
    else
        prev->left = node;

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

Tree *search(Tree *root, char key)
{
    while(root)
    {
        if(key == root->x)
            return root;
        if(key > root->x)
            root = root->right;
        else
            root = root->left;
    }

    return NULL;
}

void loop_search(Tree *root, char *M)
{
    int i;
    char key;
    Tree *node;

    for(i = 0; i < 11; ++i)
    {
        if(i < 10)
            key = M[i];
        else
            key = 0;

        node = search(root, key);
        if(node)
            printf("Key %d was found!\n", node->x);
        else
            printf("There no element whith key %d in the tree!\n", key);
    }
}












//
