#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT1 "data/input1.txt"
#define INPUT2 "data/input2.txt"
#define STR_LEN 1000

char **input_text(char*, int*);
int solve(char**, int, char**, int);

int main()
{
    char **F1, **F2;
    int N1, N2;

    F1 = input_text(INPUT1, &N1);
    F2 = input_text(INPUT2, &N2);

    printf("\nAnswer: ");
    if(solve(F1, N1, F2, N2))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}

char **input_text(char *filename, int *N)
{
    int i, strn;
    char in_buf[STR_LEN], **T;
    FILE *in;

    if(!(in = fopen(filename, "r")))
    {
        printf("Input ERROR!\n");
        return NULL;
    }

    strn = 0;
    while(fgets(in_buf, STR_LEN, in))
        if(strcmp(in_buf, "\n"))
            strn++;
    fseek(in, 0, SEEK_SET);
    //printf("%d\n", strn);

    T = (char**)malloc((int)sizeof(char*) * strn);
    for(i = 0; i < strn; i++)
        T[i] = (char*)malloc(STR_LEN);

    for(i = 0; i < strn; i++)
        if(!(strcmp(fgets(T[i], STR_LEN, in), "\n")))
            i--;

    //for(i = 0; i < strn; i++)
        //printf("%s", T[i]);

    *N = strn;
    return T;
}

int solve(char **F1, int N1, char **F2, int N2)
{
    int i, j, *cont, rep_num1, rep_num2;

    cont = (int*)calloc((int)sizeof(int), N2);

    for(i = 0; i < N1; i++)
    {
        rep_num1 = 1;
        for(j = 0; j < N1; j++)
        {
            if(i == j)
                continue;
            if(!(strcmp(F1[i], F1[j])))
                rep_num1++;
        }

        rep_num2 = 0;
        for(j = 0; j < N2; j++)
        {
            if(!(strcmp(F1[i], F2[j])))
            {
                rep_num2++;
                cont[j]++;
            }
        }
        //printf("%d %d\n", rep_num1, rep_num2);

        if(rep_num1 > rep_num2)
            return 0;
    }
    // for(i = 0; i < N2; i++)
    //     printf("%d\n", cont[i]);

    for(i = 0; i < N2; i++)
        if(!cont[i])
            return 0;

    return 1;
}
