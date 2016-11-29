#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "data/input.txt"
#define W_LEN 100

int input_str(char*, char***, int*, char***, int*);
int combinationUtil(char *arr[], char *data[], char *str, int start, int end, int index, int r);
int solve(char**, int, char**, int);
int permute(char *a[], char *str, int l, int r);

int main()
{
    char **M1, **M2, **data;
    int i, N1, N2, r;

    if(input_str(INPUT, &M1, &N1, &M2, &N2))
        return 1;

    if(!solve(M1, N1, M2, N2))
        printf("No such words!\n");

    return 0;
}

int input_str(char *filename, char ***m1, int *n1, char ***m2, int *n2)
{
    int i, j, strn1, strn2, f;
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

    //number of words in str 2
    temp = fgetc(in);
    strn2 = 1;
    f = 1;
    while(temp != EOF && temp != '\n')
    {
        if(temp == ' ' && f == 1)
        {
            strn2++;
            f = 0;
        }
        temp = fgetc(in);
        if((temp == EOF || temp == '\n') && f == 0)
        {
            strn2--;
            break;
        }
        if(temp != ' ')
            f = 1;
    }
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
            j = 0;
            i++;
        }
        temp = fgetc(in);
    }

    fclose(in);

    (*m1) = M1;
    (*n1) = strn1;

    (*m2) = M2;
    (*n2) = strn2;
    return 0;
}

int combinationUtil(char *arr[], char *data[], char *str, int start, int end, int index, int r)
{
    /* arr[]  ---> Input Array
       data[] ---> Temporary array to store current combination
       start & end ---> Staring and Ending indexes in arr[]
       index  ---> Current index in data[]
       r ---> Size of a combination to be printed */

    int i, n1, n2, Y;
    char *buff;

    // Current combination is ready to be checked
    if (index == r)
    {
        buff = (char*)malloc(W_LEN * 32);
        strcpy(buff, "");
        for (int j = 0; j < r; j++)
            buff = strcat(buff, data[j]);

        n1 = strlen(buff);
        n2 = strlen(str);

        if(n1 == n2)
        {
            // printf("\n-------------\n");
            // for (int j = 0; j < r; j++)
            //      printf("%s ", data[j]);
            // printf("\n-------------\n");

            if(permute(data, str, 0, r - 1))
            {
                free(buff);
                return 1;
            }
        }

        free(buff);
        return 0;
    }

    // replace index with all possible elements. The condition
    // "end-i+1 >= r-index" makes sure that including one element
    // at index will make a combination with remaining elements
    // at remaining positions
    for (i = start; i <= end && end - i + 1 >= r - index; i++)
    {
        strcpy(data[index], arr[i]);
        Y = combinationUtil(arr, data, str, i + 1, end, index + 1, r);
    }

    return Y;
}

int solve(char **M1, int N1, char **M2, int N2)
{
    int i, j, k, en, r, control;
    char **ENT, **data;
    control = 1;

    printf("Words in line 1:\n");
    for(i = 0; i < N1; i++)
        printf("%s\n", M1[i]);
    printf("\n");
    printf("Words in line 2:\n");
    for(i = 0; i < N2; i++)
        printf("%s\n", M2[i]);
    printf("\n");

    for(i = 0; i < N2; i++) //loop for M2
    {
        en = 0;
        for(j = 0; j < N1; j++) // loop for M1
        {
            if(strstr(M2[i], M1[j]))
                en++;
        }
        if(!en)
        {
            printf("word: %s\n", M2[i]);
            return 1;
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

        // for(j = 0; j < en; j++)
        //     printf("%s\n", ENT[j]);
        // printf("\n");

        for(r = 1; r <= en; r++)
        {
            data = (char**)malloc((int)sizeof(char*) * r);
            for(j = 0; j < r; j++)
                data[j] = (char*)malloc(W_LEN);

            control = combinationUtil(ENT, data, M2[i], 0, en - 1, 0, r);
            if(control)
            {
                for(j = 0; j < r; j++)
                    free(data[j]);
                free(data);
                break;
            }

            for(j = 0; j < r; j++)
                free(data[j]);
            free(data);
        }
        if(!control)
        {
            for(j = 0; j < en; j++)
                free(ENT[j]);
            free(ENT);
            printf("word: %s\n", M2[i]);
            return 1;
        }

        for(j = 0; j < en; j++)
            free(ENT[j]);
        free(ENT);
    }

    return 0;
}

int permute(char *a[], char *str, int l, int r)
{
    /* Function to print permutations of string
       This function takes three parameters:
       1. String
       2. Starting index of the string
       3. Ending index of the string. */
   int i, j, n;
   char temp[W_LEN];
   char *buff;

   if (l == r)
   {
       buff = (char*)malloc(W_LEN * 32);
       strcpy(buff, "");
        for(j = 0; j <= r; j++)
            buff = strcat(buff, a[j]);

        if(!strcmp(buff, str))
        {
            free(buff);
            return 1;
        }

        free(buff);
   }
   else
   {
       for (i = l; i <= r; i++)
       {
        strcpy(temp, a[l]);
        strcpy(a[l], a[i]);
        strcpy(a[i], temp);

        if(permute(a, str, l + 1, r))
            return 1;

        strcpy(temp, a[l]);
        strcpy(a[l], a[i]);
        strcpy(a[i], temp);
       }
   }

   return 0;
}
