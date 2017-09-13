#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NOBJ 20
#define SKEY 1

int write(int*);
int swap(int*, int*);
int sort(int*, int, int);
int search(int*, int);

int main()
{
    int i, resi;
    int *M;

    srand(time(0));

    M = (int*)calloc(NOBJ, sizeof(int));

    for(i = 0; i < NOBJ; i++)
        M[i] = rand() % 100000;

    printf("Mass before sorting:\n");
    write(M);

    sort(M, 0, NOBJ - 1);

    printf("Mass after sorting:\n");
    write(M);

    //printf("Serching M[%d] = %d\n", SKEY, M[SKEY]);
    printf("Serching %d\n", M[SKEY] + 1);
    printf("\nResult of searching:\n");
    resi = search(M, M[SKEY] + 1);
    printf("Index: %d\nValue: %d\n", resi, M[resi]);

    return 0;
}

int write(int *x)
{
    int i;

    for(i = 0; i < NOBJ; i++)
        printf("%d ", x[i]);
    printf("\n");

    return 0;
}

int swap(int *x1, int *x2)
{
    if(x1 != x2)
    {
        int temp;

        temp = *x1;
        *x1 = *x2;
        *x2 = temp;

        return 0;
    }
    else
        return 1;
}

int sort(int *x, int l, int r)
{
    int i, j;
    int min;

    for(i = l; i < r; i++)
    {
        min = i;
        for(j = i + 1; j <= r; j++)
            if(x[j] < x[min])
                min = j;
        swap(x + min, x + i);
    }

    return 0;
}

int search(int *x, int key)
{
    int low, high, mid;
    int steps = 0;

    low = 0;
    high = NOBJ - 1;

    while(low <= high)
    {
        mid = (low + high) / 2;
        printf("low = %d\nhigh = %d\nmid = %d\n\n", low, high, mid);

        if(key < x[mid])
            high = mid - 1;
        else if(key > x[mid])
            low = mid + 1;
        else
        {
            printf("Number of steps: %d\n", steps);
            return mid;
        }
        steps++;
    }

    printf("No searched element!\n");
    printf("Number of steps: %d\n", steps);
    return -1;
}
