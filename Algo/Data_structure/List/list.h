#ifndef __LIST_H__
#define __LIST_H__

typedef struct Node tNode;

struct Node
{
    int d;
    struct Node *next;
    struct Node *prev;
};

struct Node *first(int);
struct Node *insert(struct Node*, struct Node**, int, int);
struct Node *finsert(struct Node**, int);
struct Node *find(struct Node*, int);
void add(struct Node**, int);
void add_sort(struct Node**, struct Node**, int);
int mremove(struct Node**, struct Node**, int);
int write(struct Node*);

#endif
