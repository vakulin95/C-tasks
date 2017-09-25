#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_NODES        20
#define RAND_LOW            30
#define RAND_HIGH           80
#define DEF_KEY             47

typedef struct tree Tree;

struct tree
{
    int x;
    Tree *left;
    Tree *right;
};

Tree *init(int x);
Tree *add(Tree *root, int x);
Tree *search(Tree *root, int key);
void print_tree(Tree *root, int level);

int main()
{
    int i;
    Tree *quora = init((RAND_HIGH - RAND_LOW) / 2 + RAND_LOW);
    Tree *node;

    srand(time(0));

    for(i = 0; i < NUM_OF_NODES; i++)
    {
        add(quora, rand() % (RAND_HIGH - RAND_LOW) + RAND_LOW);
    }

    print_tree(quora, 0);

    printf("\n-----------------------------------------------\n");

    node = search(quora, DEF_KEY);

    if(node)
    {
        printf("Key is:\t%d\nFounded node:\t%d\n", DEF_KEY, node->x);

        if(DEF_KEY > node->x)
        {
            printf("Key is right node of the parent node\n");
        }
        else if(DEF_KEY < node->x)
        {
            printf("Key is left node of the parent node\n");
        }
        else
        {
            printf("Key is root of the parent node\n");
        }
    }
    else
    {
        printf("No such node in the tree!\n");
    }

    printf("-----------------------------------------------\n");

    return 0;
}

Tree *init(int x)
{
    Tree *node = (Tree*)malloc(sizeof(Tree));

    node->x = x;
    node->right = NULL;
    node->left = NULL;

    return node;
}

Tree *add(Tree *root, int x)
{
    Tree *node = init(x);
    Tree *prev;

    while(root)
    {
        prev = root;

        if(x < root->x)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    if(x < prev->x)
    {
        prev->left = node;
    }
    else
    {
        prev->right = node;
    }

    return node;
}

Tree *search(Tree *root, int key)
{
    int found;

    found = 0;
    while(root)
    {
        if((root->right) && key == (root->right)->x)
        {
            found = 1;
            break;
        }
        else if((root->left) && key == (root->left)->x)
        {
            found = 1;
            break;
        }
        else if(key == root->x)
        {
            found = 1;
            break;
        }
        else if((root->right) && key > root->x)
        {
            root = root->right;
        }
        else if((root->left) && key < root->x)
        {
            root = root->left;
        }
        else
        {
            root = NULL;
            break;
        }
    }

    return root;
}

void print_tree(Tree *root, int level)
{
    int i;

    if(root)
    {
        print_tree(root->left, level + 1);

        for (i = 0; i < level; i++)
        {
            printf("\t");
        }
        printf("%d\n", root->x);

        print_tree(root->right, level + 1);
    }

}
