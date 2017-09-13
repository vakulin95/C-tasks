#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//Создать первый узел списка и вернуть указатель на него
struct Node *first(int d)
{
    struct Node *pv = (struct Node*)malloc(sizeof(struct Node));

    pv->d = d;
    pv->next = NULL;
    pv->prev = NULL;

    return pv;
}

//Вставка нового элемента списка после элемента с ключем key
struct Node *insert(struct Node *pbeg, struct Node **pend, int key, int d)
{
    struct Node *pv = (struct Node*)malloc(sizeof(struct Node));
    struct Node *pkey = find(pbeg, key);

    if(pkey)
    {
        pv->d = d;
        pv->prev = pkey;
        pv->next = pkey->next;
        pkey->next = pv;
        if(pkey != *pend)
            (pkey->next)->prev = pv;
        else
            *pend = pv;

        return pv;
    }

    return NULL;
}

//Вставка элемента в начало списка
struct Node *finsert(struct Node **pbeg, int d)
{
    struct Node *pv = (struct Node*)malloc(sizeof(struct Node));

    pv->d = d;
    pv->next = *pbeg;
    pv->prev = NULL;
    (*pbeg)->prev = pv;
    *pbeg = pv;
}

//Найти элемент списка по ключу
struct Node *find(struct Node *pbeg, int d)
{
    struct Node *pv = pbeg;

    while(pv)
    {
        if(pv->d == d)
            break;

        pv = pv->next;
    }

    return pv;
}

//Добавление элемента в конец списка
void add(struct Node **pend, int d)
{
    struct Node *pv = (struct Node*)malloc(sizeof(struct Node));

    pv->d = d;
    pv->next = NULL;
    pv->prev = *pend;
    //printf("%d %d\n", pv->d, (*pend)->d);
    (*pend)->next = pv; //Обращение к указателю на следующий элемент в
                        //последнем элементе списка и присваивание ему указателя на добавленный элемент
    *pend = pv;
}

//Формирование упорядоченного списка
void add_sort(struct Node **pbeg, struct Node **pend, int d)
{
    struct Node *pv = (struct Node*)malloc(sizeof(struct Node));
    pv->d = d;

    struct Node *pt = *pbeg;
    while(pt)
    {
        if(d < pt->d)
        {
            pv->next = pt;
            if(pt == *pbeg)
            {
                pv->prev = NULL;
                *pbeg = pv;
            }
            else
            {
                pv->prev = pt->prev;
                (pt->prev)->next = pv;
            }
            pt->prev = pv;
            return;
        }
        pt = pt->next;
    }

    pv->next = NULL;
    pv->prev = *pend;
    (*pend)->next = pv;
    *pend = pv;
}

//Удалить элемент списка с заданным ключем
int mremove(struct Node **pbeg, struct Node **pend, int d)
{
    struct Node *pkey;

    if(pkey = find(*pbeg, d))
    {
        if(pkey == *pbeg)
        {
            *pbeg = (*pbeg)->next;
            (*pbeg)->prev = NULL;
        }
        else if(pkey == *pend)
        {
            *pend = (*pend)->prev;
            (*pend)->next = NULL;
        }
        else
        {
            (pkey->prev)->next = pkey->next;
            (pkey->next)->prev = pkey->prev;
        }
        free(pkey);
        return 1;
    }

    return 0;
}


//Печать списка на экран
int write(struct Node *pbeg)
{
    struct Node *pv = pbeg;

    while(pv)
    {
        printf("%d ", pv->d);
        pv = pv->next;
    }
    printf("\n");

    return 0;
}
