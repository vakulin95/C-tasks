#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "data/input.txt"
#define W_LEN 100

int input_str(char*, char***, int*, char***, int*);

int main()
{
    char **M1, **M2;
    int i, N1, N2;

    if(input_str(INPUT, &M1, &N1, &M2, &N2))
        return 1;

    for(i = 0; i < N1; i++)
        printf("%s\n", M1[i]);
    printf("\n");
    for(i = 0; i < N2; i++)
        printf("%s\n", M2[i]);

    return 0;
}

int input_str(char *filename, char ***m1, int *n1, char ***m2, int *n2)
{
    int i, j, strn1, strn2;
    char **M1, **M2, temp;
    FILE *in;

    if(!(in = fopen(filename, "r")))
    {
        printf("Input ERROR!\n");
        return 1;
    }

    //Подсчет слов в первой строке
    temp = fgetc(in);
    strn1 = 1;
    while(temp != '\n')
    {
        if(temp == ' ')
            strn1++;
        temp = fgetc(in);
    }
    //printf("%d\n", strn1);

    //Подсчет слов во второй строке
    temp = fgetc(in);
    strn2 = 1;
    while(temp != EOF)
    {
        if(temp == ' ')
            strn2++;
        temp = fgetc(in);
    }
    //printf("%d\n", strn2);
    fseek(in, 0, SEEK_SET);

    M1 = (char**)malloc((int)sizeof(char*) * strn1);
    for(i = 0; i < strn1; i++)
        M1[i] = (char*)malloc(W_LEN);

    M2 = (char**)malloc((int)sizeof(char*) * strn2);
    for(i = 0; i < strn2; i++)
        M2[i] = (char*)malloc(W_LEN);

    // Первая строка в массиве
    temp = fgetc(in);
    i = 0;
    j = 0;
    while(temp != '\n')
    {
        if(temp != ' ')
        {
            M1[i][j] = temp;
            j++;
        }
        else
        {
            j = 0;
            i++;
        }
        temp = fgetc(in);
    }

    //Вторая строка в массиве
    temp = fgetc(in);
    i = 0;
    j = 0;
    while(temp != EOF && temp != '\n')
    {
        if(temp != ' ')
        {
            M2[i][j] = temp;
            j++;
        }
        else
        {
            //printf("%s\n", M2[i]);
            j = 0;
            i++;
        }
        temp = fgetc(in);
    }
    //printf("%s\n", M2[i]);
    //printf("%d\n", strn2);

    fclose(in);

    (*m1) = M1;
    (*n1) = strn1;

    (*m2) = M2;
    (*n2) = strn2;
    return 0;
}
