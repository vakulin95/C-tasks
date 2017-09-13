#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NOBJ 5

int write(int*);
int swap(int*, int*);
int sort(int*, int, int);

int main()
{
    int i;
    int *M;

    srand(time(0));

    M = (int*)calloc(NOBJ, sizeof(int));

    for(i = 0; i < NOBJ; i++)
        M[i] = 1 + rand() % 20;

    printf("Mass before sorting:\n");
    write(M);
    printf("\n");

    sort(M, 0, NOBJ - 1);
    printf("\nMass after sorting:\n");
    write(M);

    return 0;
}

int write(int *x)
{
    int i;
    for(i = 0; i < NOBJ; i++)
        printf("%3d", *(x + i));
    printf("\n");

    return 0;
}

int swap(int *x1, int *x2)
{
    int temp = *x1;

    if(x1 != x2)
    {
        *x1 = *x2;
        *x2 = temp;
        return 0;
    }
    else
        return 1;
}

int sort(int *x, int l, int r)
{
    int i, last;

    write(x);

    if(l >= r)
        return 1;

    swap(x + l, x + (l + r) / 2);
    last = l;

    for(i = l + 1; i <= r; i++)
        if(x[i] < x[l])
            swap(x + (++last), x + i);

    swap(x + l, x + last);

    sort(x, l, last - 1);
    sort(x, last + 1, r);

    return 0;
}
