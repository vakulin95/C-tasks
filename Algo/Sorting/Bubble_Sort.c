#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NOBJ 5

int write(int*);
int sort(int*, int, int);

int main()
{
    int i;
    int *M;

    srand(time(0));

    M = (int*)calloc(NOBJ, sizeof(int));

    for(i = 0; i < NOBJ; i++)
        M[i] = rand() % 20;

    printf("Mass before sorting:\n");
    write(M);
    printf("\n\n");

    sort(M, 0, NOBJ - 1);
    printf("\nMass after sorting:\n");
    write(M);
    printf("\n\n");

    return 0;
}

int write(int *x)
{
    int i;

    for(i = 0; i < NOBJ; i++)
        printf("%3d ", *(x + i));

    return 0;
}

int sort(int *x, int l, int r)
{
    int i, j, temp, f;

    f = 1;
    while(f)
    {
        f = 0;
        for(j = r; j >= l; j--)
        {
            if(x[j] < x[j - 1])
            {
                temp = x[j];
                x[j] = x[j - 1];
                x[j - 1] = temp;
                f = 1;
            }
            //write(x);
            //printf("\n");
        }

    }

    return 0;
}
