#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR "rite it intolist."

typedef struct list List;

struct list
{
    char x;
    List *next;
    List *prev;
};

List *init(char);
void add(List**, List**, char, char);
void end_add(List**, char);
void change(List*, char, char);
void remoove(List*, char);
void print(List*);

int main()
{
    int i;
    char M[] = STR;
    List *pbeg = init(M[0]);
    List *pend = pbeg;

    for(i = 1; i < (int)strlen(STR); i++)
        end_add(&pend, M[i]);
    print(pbeg);


    add(&pbeg, &pend, '!', '!');
    remoove(pbeg, '.');
    //remoove(pbeg, 't');
    print(pbeg);

    add(&pbeg, &pend, 'r', 'W');
    add(&pbeg, &pend, 'l', ' ');
    print(pbeg);

    change(pbeg, ' ', '_');
    print(pbeg);

    return 0;
}

List *init(char x)
{
    List *node = (List*)malloc(sizeof(List));

    node->x = x;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

void add(List **pbeg, List **pend, char key, char x)
{
    int flag = 0;
    List *node;
    List *temp = *pbeg;

    while(temp)
    {
        if(temp->x == key)
        {
            if(!temp->prev)
            {
                node = (List*)malloc(sizeof(List));

                node->x = x;
                node->next = (*pbeg);
                node->prev = NULL;
                (*pbeg)->prev = node;
                *pbeg = node;
            }
            else
            {
                node = (List*)malloc(sizeof(List));

                node->x = x;
                node->prev = temp->prev;
                node->next = temp;
                (temp->prev)->next = node;
                temp->prev = node;
                //print(*pbeg);
                //printf("%c\n", (temp->next)->x);
            }
            flag = 1;
            //temp = temp->next;
        }
        temp = temp->next;
    }

    if(!flag)
        end_add(&(*pend), x);
}

void end_add(List **pend, char x)
{
    List *node = (List*)malloc(sizeof(List));

    node->x = x;
    node->next = NULL;
    node->prev = *pend;
    (*pend)->next = node;
    *pend = node;
}

void change(List *pkey, char key, char x)
{
    while(pkey)
    {
        if(pkey->x == key)
            pkey->x = x;

        pkey = pkey->next;
    }
}

void remoove(List *pbeg, char key)
{
    List *pkey = pbeg;
    List *temp;

    while(pkey)
    {
        if(pkey->x == key)
        {
            temp = pkey->next;
                (pkey->prev)->next = pkey->next;
                (pkey->next)->prev = pkey->prev;
            free(pkey);
            pkey = temp;
            continue;
        }
        pkey = pkey->next;
    }
}

void print(List *pbeg)
{
    while(pbeg)
    {
        printf("%c", pbeg->x);
        pbeg = pbeg->next;
    }
    printf("\n");
}
