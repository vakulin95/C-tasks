#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEF_MASS_LEN    100
#define DEF_LB          0
#define DEF_UB          100

int main()
{
    int i, j;
    int sum, fl;
    int num_mass[DEF_MASS_LEN];

    srand(time(0));

    printf("Input mass:\n");
    for(i = 0; i < DEF_MASS_LEN; i++)
    {
        num_mass[i] = rand() % (DEF_UB - DEF_LB) + DEF_LB;
        printf("%5d\t", num_mass[i]);
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
            if(num_mass[i] + num_mass[j] == sum)
            {
                printf("%5d;\t%5d\n", num_mass[i], num_mass[j]);
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
