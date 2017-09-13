#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node
{
    int d;
    Node *p;
};

Node *first(int);
void push(Node**, int);
int pop(Node**);
void write(Node*);

int main()
{
    int i = 0;

    Node *top = first(i);
    //write(top);

    for(i = 1; i < 20; i++)
        push(&top, i);
    write(top);
    for(i = 0; i < 5; i++)
        pop(&top);
    write(top);

    return 0;
}

Node *first(int d)
{
    Node *top = (Node*)malloc(sizeof(Node));

    top->d = d;
    top->p = NULL;

    return top;
}

void push(Node **top, int d)
{
    Node *pv = (Node*)malloc(sizeof(Node));

    pv->d = d;
    pv->p = *top;
    *top = pv;
}

int pop(Node **top)
{
    int Y = (*top)->d;
    Node *pv = *top;

    *top = (*top)->p;
    free(pv);

    return Y;
}

void write(Node *top)
{
    while(top)
    {
        printf("%d ", top->d);
        top = top->p;
    }
    printf("\n");
}
