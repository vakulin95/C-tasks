#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEF_ARR_LEN     20      // Array length
#define DEF_LB          0       // Min value in array
#define DEF_UB          100      // Max value in array

void sort_int(int *arr);
void sort_rec(int *arr, int start);
void print_arr(int *arr);
void swap(int *x1, int *x2);
int check(int *arr);

int main()
{
    int i, j, temp, min;
    int array[DEF_ARR_LEN];

    srand(time(0));

    for(i = 0; i < DEF_ARR_LEN; i++)
    {
        array[i] = rand() % (DEF_UB + DEF_LB) - DEF_LB;
    }

    print_arr(array);

    // sort_int(array);
    sort_rec(array, DEF_ARR_LEN);

    print_arr(array);

    printf("Array sorting result: %d\n", check(array));

    return 0;
}

void sort_int(int *arr)
{
    size_t i, j;
    int min, temp;

    for(i = 0; i < DEF_ARR_LEN - 1; i++)
    {
        min = i;
        for(j = i + 1; j < DEF_ARR_LEN; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }

        swap(arr + i, arr + min);
    }
}

void sort_rec(int *arr, int len)
{
    size_t i;
    int min, temp;

    min = 0;
    for(i = 1; i < len; i++)
    {
        if(arr[i] < arr[min])
        {
            min = i;
        }
    }

    swap(arr, arr + min);

    if(len > 1)
    {
        sort_rec(arr + 1, len - 1);
    }

    return;
}

void print_arr(int *arr)
{
    size_t i;

    for(i = 0; i < DEF_ARR_LEN; i++)
    {
        printf("%3d", arr[i]);
    }
    printf("\n");
}

void swap(int *x1, int *x2)
{
    int t;

    t = *x1;
    *x1 = *x2;
    *x2 = t;
}

int check(int *arr)
{
    size_t i;
    int Y = 1;

    for(i = 1; i < DEF_ARR_LEN; i++)
    {
        if(arr[i] < arr[i - 1])
        {
            Y = 0;
            break;
        }
    }

    return Y;
}
