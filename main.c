#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "data/input.txt"
#define W_LEN 100

int input_str(char*, char***, int*, char***, int*);
void combinationUtil(char *arr[], char *data[], int start, int end, int index, int r);
int solve(char**, int, char**, int);

int main()
{
    char **M1, **M2, **data;
    int i, N1, N2, r;

    if(input_str(INPUT, &M1, &N1, &M2, &N2))
        return 1;

    for(i = 0; i < N1; i++)
        printf("%s\n", M1[i]);
    printf("\n");
    for(i = 0; i < N2; i++)
        printf("%s\n", M2[i]);
    printf("\n");

    solve(M1, N1, M2, N2);

    // r = 1;
    // data = (char**)malloc((int)sizeof(char*) * r);
    // for(i = 0; i < r; i++)
    //     data[i] = (char*)malloc(W_LEN);
    //
    // combinationUtil(M1, data, 0, N1 - 1, 0, r);

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

    //number of words in str 1
    temp = fgetc(in);
    strn1 = 1;
    while(temp != '\n')
    {
        if(temp == ' ')
            strn1++;
        temp = fgetc(in);
    }
    //printf("%d\n", strn1);

    //number of words in str 2
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

    // string 1 to array
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

    //string 2 to array
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

/* arr[]  ---> Input Array
   data[] ---> Temporary array to store current combination
   start & end ---> Staring and Ending indexes in arr[]
   index  ---> Current index in data[]
   r ---> Size of a combination to be printed */
void combinationUtil(char *arr[], char *data[], int start, int end, int index, int r)
{
    int i;

    // Current combination is ready to be printed, print it
    if (index == r)
    {
        for (int j = 0; j < r; j++)
            printf("%s ", data[j]);
        printf("\n");
        return;
    }

    // replace index with all possible elements. The condition
    // "end-i+1 >= r-index" makes sure that including one element
    // at index will make a combination with remaining elements
    // at remaining positions
    for (i = start; i <= end && end - i + 1 >= r - index; i++)
    {
        strcpy(data[index], arr[i]);
        combinationUtil(arr, data, i + 1, end, index + 1, r);
    }
}

int solve(char **M1, int N1, char **M2, int N2)
{
    int i, j, k, en;
    char **ENT;

    for(i = 0; i < N2; i++) //loop for M2
    {
        en = 0;
        for(j = 0; j < N1; j++) // loop for M1
        {
            if(strstr(M2[i], M1[j]))
                en++;
        }

        ENT = (char**)malloc((int)sizeof(char*) * en);
        for(j = 0; j < en; j++)
             ENT[j] = (char*)malloc(W_LEN);

        k = 0;
        for(j = 0; j < N1; j++) // loop for M1
        {
            if(strstr(M2[i], M1[j]))
            {
                strcpy(ENT[k], M1[j]);
                k++;
            }
        }

        //for(j = 0; j < en; j++)
            //printf("%s\n", ENT[j]);
        //printf("\n");

        for(j = 0; j < en; j++)
            free(ENT[j]);
        free(ENT);
    }

    return 0;
}
