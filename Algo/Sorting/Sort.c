#include <stdio.h>
#include <stdlib.h>

int print(int*, int);
void swap(int*, int*);
void ins(int*, int);
void bub(int*, int);

int main()
{
    int i, size;
    int *X;

    printf("Input mass size please: ");
    scanf("%d", &size);

    X = (int*)calloc(size, sizeof(int));
    for(i = 0; i < size; ++i)
        scanf("%d", X + i);
    print(X, size);

    ins(X, size);
    print(X, size);

    return 0;
}

int print(int *X, int size)
{
    int i;

    for(i = 0; i < size; ++i)
        printf("%d ", *(X + i));
        printf("\n");

    return 0;
}

void swap(int *x1, int *x2)
{
    int temp;

    temp = *x1;
    *x1 = *x2;
    *x2 = temp;
}

void ins(int *X, int size)
{
    int i, j;
    int min;

    for(i = 0; i < size - 1; ++i)
    {
        min = i;
        for(j = i + 1; j < size; ++j)
            if(*(X + j) < *(X + min))
                min = j;
        swap(X + i, X + min);
    }
}

void bub(int *X, int size)
{
    int i, j;

    for(i = 0; i < size; ++i)
    {
        for(j = size - 1; j > i; --j)
        {
            if(X[j] < X[j - 1])
                swap(X + j, X + (j - 1));
        }
    }
}
