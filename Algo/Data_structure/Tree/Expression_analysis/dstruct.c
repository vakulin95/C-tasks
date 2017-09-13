#include "dstruct.h"

Tree *init(char x)
{
    Tree *node = (Tree*)malloc(sizeof(Tree));

    node->x = x;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int priority(char c)
{
    switch(c)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }

    return 100;
}

Tree* make_tree(char *Expr, int first, int last)
{
    int MinPrt, i, k, prt;
    Tree *node = (Tree*)malloc(sizeof(Tree));

    if ( first == last )
    {
        node->x = Expr[first];
        node->left = NULL;
        node->right = NULL;

        return node;
    }

    MinPrt = 100;
    for ( i = first; i <= last; i ++ )
    {
        prt = priority( Expr[i] );
        if ( prt <= MinPrt )
        {
            MinPrt = prt;
            k = i;
        }
    }

    node->x = Expr[k]; // внутренняя вершина (операция)
    node->left = make_tree(Expr,first,k-1); // рекурсивно строим
    node->right = make_tree(Expr,k+1,last); // поддеревья

    return node;
}

void print(Tree *root, int level)
{
    int i;

    if(root)
    {
        print(root->right, level + 1);

        for(i = 0; i < level; i++)
            printf("\t");
        printf("%c\n", root->x);

        print(root->left, level + 1);
    }
}

Stack *init_stack(int x)
{
    Stack *node = (Stack*)malloc(sizeof(Stack));

    node->x = x;
    node->prev = NULL;

    return node;
}

void push(Stack **top, int x)
{
    Stack *node = (Stack*)malloc(sizeof(Stack));

    node->x = x;

    if(*top)
        node->prev = *top;
    else
        node->prev = NULL;

    *top = node;
}

int pop(Stack **top)
{
    if(*top)
    {
        int Y = (*top)->x;
        Stack *temp = *top;

        *top = (*top)->prev;
        free(temp);

        return Y;
    }

    printf("No elements into stack!\n");
    return 0;
}

void print_stack(Stack *top)
{
    while(top)
    {
        printf("%d ", top->x);
        top = top->prev;
    }
    printf("\n");
}

void calc(Tree *root, Stack **top)
{
    int a, b, Y;

    if(root)
    {
        calc(root->left, &(*top));
        calc(root->right, &(*top));

        if(root->x >= '0' && root->x <= '9')
            push(&(*top), (root->x) - '0');
        else
        {
            a = pop(&(*top));
            b = pop(&(*top));
            switch(root->x)
            {
                case '+':
                    push(&(*top), (b + a));
                    break;
                case '-':
                    push(&(*top), (b - a));
                    break;
                case '*':
                    push(&(*top), (b * a));
                    break;
                case '/':
                    push(&(*top), (b / a));
                    break;
                default:
                    printf("ERROR! Invalid operation into expression!\n");
                    break;
            }
        }
        print_stack(*top);
    }
    return;
}
