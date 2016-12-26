#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT "data/input.txt"

double **input_mass(char*, int*);
void output_mass(double**, int);
double *gauss(double**, int);
void print_ans(double*, int);

int main()
{
    int i, N;
    double **A;

    A = input_mass(INPUT, &N);
    output_mass(A, N);

    print_ans(gauss(A, N), N);

    for(i = 0; i < N; i++)
        free(A[i]);
    free(A);

    return 0;
}

double **input_mass(char *filename, int *n)
{
    int i, j, N;
    double **A, buf;
    FILE *in;

    if(!(in = fopen(filename, "r")))
    {
        printf("Input ERROR!\n");
        return NULL;
    }

    N = 0;
    while(fscanf(in, "%lf", &buf) != EOF)
        N++;
    N = 0.5 * (sqrt(4 * N + 1) - 1);
    //printf("%d\n", N);
    *n = N;

    A = (double**)malloc((int)sizeof(double*) * N);
    for(i = 0; i < N; ++i)
        A[i] = (double*)malloc((int)sizeof(double) * N + 1);

    fseek(in, 0, SEEK_SET);
    for(i = 0; i < N; ++i)
        for(j = 0; j <= N; ++j)
            fscanf(in, "%lf", &A[i][j]);

    fclose(in);
    return A;
}

 void output_mass(double **A, int N)
{
     int i, j;

     for(i = 0; i < N; ++i)
    {
        for(j = 0; j < N; ++j)
            printf("%6.3lf ", A[i][j]);
        printf("| %6.3lf\n", A[i][j]);
    }
    printf("\n");
 }

double *gauss(double **A, int N)
{
    int i, j, k, maxrow;
    double MaxEl, tmp, c;
    double *x;

    x = (double*)malloc((int)sizeof(double) * N);

    for(i = 0; i < N; i++)
    {
        MaxEl = abs(A[i][i]);
        maxrow = i;

        for(j = i + 1; j < N; j++)
        {
            if(abs(A[j][i]) > MaxEl)
            {
                MaxEl = A[j][i];
                maxrow = j;
            }
        }

        for (j = i; j <= N; j++)
        {
            tmp = A[maxrow][j];
            A[maxrow][j] = A[i][j];
            A[i][j] = tmp;
        }

        for (k = i + 1; k < N; k++)
        {
            c = -A[k][i] / A[i][i];
            for (j = i; j < N + 1; j++)
            {
                if (i == j)
                {
                    A[k][j] = 0;
                }
                else
                {
                    A[k][j] += c * A[i][j];
                }
            }
        }
    }

    for (i = N - 1; i >= 0; i--)
    {
        x[i] = A[i][N] / A[i][i];
        for (k = i - 1; k >= 0; k--)
        {
            A[k][N] -= A[k][i] * x[i];
        }
    }

    //output(A);
    return x;
}

void print_ans(double *X, int N)
{
    int i;

    printf("X* = (");
    for(i = 0; i < N; ++i)
       printf("%6.3lf ", X[i]);
    printf("\b)\n");
}
