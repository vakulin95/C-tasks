#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEF_ARR_LEN     30      // Array length
#define DEF_LB          0       // Min value in array
#define DEF_UB          100      // Max value in array

void sort_int(int *arr);
void sort_rec(int *arr, int fl);
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
    sort_rec(array, 1);

    print_arr(array);

    printf("Array sorting result: %d\n", check(array));

    return 0;
}

void sort_int(int *arr)
{
    size_t i;
    int fl = 1;

    while(fl)
    {
        fl = 0;
        for(i = DEF_ARR_LEN - 1; i > 0; i--)
        {
            if(arr[i] < arr[i - 1])
            {
                swap(arr + i, arr + i - 1);
                fl = 1;
            }
        }
    }

}

void sort_rec(int *arr, int fl)
{
    size_t i;

    if(fl)
    {
        fl = 0;

        for(i = DEF_ARR_LEN - 1; i > 0; i--)
        {
            if(arr[i] < arr[i - 1])
            {
                swap(arr + i, arr + i - 1);
                fl = 1;
            }
        }

        sort_rec(arr, fl);
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
