#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NOBJ 10

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
        M[i] = rand() % 10;

    printf("Mass before sorting:\n");
    write(M);

    long t1 = clock();
    sort(M, 0, NOBJ - 1);
    long t2 = clock();

    printf("Mass after sorting:\n");
    write(M);

    printf("\ntime: %f\n", (double)(t2 - t1) / CLOCKS_PER_SEC);
    free(M);
    return 0;
}

int write(int *x)
{
    int i;

    for(i = 0; i < NOBJ; i++)
        printf("mass[%d] = %d\n", i, *(x + i));

    return 0;
}

int swap(int *x1, int *x2)
{
    int temp = *x1;

    *x1 = *x2;
    *x2 = temp;

    return 0;
}

//Функция принимает массив и индексы правого и левого концов его сортируемого участка
//Сортировка по возрастанию
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
        swap(&x[i], &x[min]);
    }

    return 0;
}
