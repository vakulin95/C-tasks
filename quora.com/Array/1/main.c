#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEF_MASS_LEN    100     // Array length
#define DEF_LB          0       // Min value in array
#define DEF_UB          100     // Max value in array

int main()
{
    int i, j;
    int sum, fl;
    int num_arr[DEF_MASS_LEN];

    srand(time(0));

    printf("Input arr:\n");
    for(i = 0; i < DEF_MASS_LEN; i++)
    {
        num_arr[i] = rand() % (DEF_UB - DEF_LB) + DEF_LB;
        printf("%5d\t", num_arr[i]);
        if(!((i + 1) % 5))
            printf("\n");
    }

    printf("\nInput sum value:\t");
    scanf("%d", &sum);

    printf("\nAnswer:\n");
    for(i = 0, fl = 0; i < DEF_MASS_LEN - 1; i++)
    {
        for(j = i + 1; j < DEF_MASS_LEN; j++)
        {
            if(num_arr[i] + num_arr[j] == sum)
            {
                printf("%5d;\t%5d\n", num_arr[i], num_arr[j]);
                fl = 1;
            }
        }
    }

    if(!fl)
    {
        printf("No such values in the input!\n");
    }

    return 0;
}
