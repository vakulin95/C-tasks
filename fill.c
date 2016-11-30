//Заполнение input.txt

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INPUT "data/input.txt"
#define N 10

int input(void);

int main()
{

    input();

    printf("finish!\n");
    return 0;
}

int input(void)
{
    int i;
    double f;
    FILE *in;

    srand(time(0));

    if(!(in = fopen(INPUT, "w")))
    {
        printf("ERROR: input(double*)!\n");
        return 0;
    }

    for(i = 0; i < N; i++)
        fprintf(in, "%2.3lf\n", (rand() % 100) / 10.0);

    fclose(in);
    return 1;
}
