#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node
{
    int d;
    Node *next;
};

Node *first(int);
void add(Node**, int);
int del(Node**);
void write(Node*);

int main()
{
    int i = 0;
    Node *pbeg;
    Node *pend;

    printf("add element: %d\n", i);
    pbeg = first(i);
    pend = pbeg;
    write(pbeg);
    for(i = 1; i < 10; i++)
    {
        printf("add element: %d\n", i);
        add(&pend, i);
        write(pbeg);
    }
    printf("\n");

    for(i = 0; i < 9; ++i, write(pbeg))
        printf("delete element: %d\n", del(&pbeg));

    return 0;
}

Node *first(int d)
{
    Node *pv = (Node*)malloc(sizeof(Node));

    pv->d = d;
    pv->next = NULL;

    return pv;
}

void add(Node **pend, int d)
{
    Node *pv = (Node*)malloc(sizeof(Node));

    pv->d = d;
    pv->next = NULL;
    (*pend)->next = pv;
    *pend = pv;
}

int del(Node **pbeg)
{
    int Y;
    Node *pv = *pbeg;

    Y = pv->d;
    *pbeg = (*pbeg)->next;
    free(pv);

    return Y;
}

void write(Node *pbeg)
{
    while(pbeg)
    {
        printf("%d ", pbeg->d);
        pbeg = pbeg->next;
    }
    printf("\n");
}
