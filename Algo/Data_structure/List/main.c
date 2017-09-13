#include <stdio.h>
#include "list.h"

int main()
{
    int i;

    scanf("%d", &i);
    struct Node *pbeg = first(i);
    struct Node *pend = pbeg;

    while(1)
    {
        scanf("%d", &i);
        add_sort(&pbeg, &pend, i);
        write(pbeg);
    }

    // for(i = 1; i <= 10; i++)
    //     add(&pend, i);
    // write(pbeg);
    //
    // mremove(&pbeg, &pend, 5);
    // write(pbeg);
    // insert(pbeg, &pend, 0, 100);
    // write(pbeg);
    // finsert(&pbeg, 25);
    // write(pbeg);

    return 0;
}
