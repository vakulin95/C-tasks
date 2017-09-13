#ifndef __DSTRUCT_H__
#define __DSTRUCT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR "3+9+5/2-6*2" // 2

typedef struct tree Tree;
typedef struct stack Stack;

struct tree
{
    char x;
    Tree *left;
    Tree *right;
};

struct stack
{
    int x;
    Stack *prev;
};

Tree *init(char);
int priority(char);
Tree* make_tree(char*, int, int);
void print(Tree*, int);

Stack *init_stack(int);
void push(Stack**, int);
int pop(Stack**);
void print_stack(Stack*);

void calc(Tree*, Stack**);

#endif
