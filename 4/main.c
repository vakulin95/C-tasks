#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT "data/input.dat"
#define OUTPUT "data/out.dat"

double *input_arr(char*, int*);
void print_arr(double*, int);
double *solve(double*, int, int*, int**, int);
void out(char*, double*, int*, int);

int main()
{
    int n, newl_inc, newl_dec, *O_inc, *O_dec;
    double *X, *S_inc, *S_dec;

    X = input_arr(INPUT, &n);
    print_arr(X, n);

    S_inc = solve(X, n, &newl_inc, &O_inc, 1);
    S_dec = solve(X, n, &newl_dec, &O_dec, 0);

    printf("\nSolution for increasing sequence:\n");
    print_arr(S_inc, newl_inc);
    printf("\nSolution for decreasing sequence:\n");
    print_arr(S_dec, newl_dec);

    if(newl_inc > newl_dec)
    {
        printf("\nAnswer: %d\n", n - newl_inc);
        out(OUTPUT, S_inc, O_inc, newl_inc);
    }
    else
    {
        printf("\nAnswer: %d\n", n - newl_dec);
        out(OUTPUT, S_dec, O_dec, newl_dec);
    }

    out(INPUT, X, NULL, n);

    return 0;
}

double *input_arr(char *filename, int *n)
{
    int i, N;
    double *A, buf;
    FILE *in;

    if(!(in = fopen(filename, "r")))
    {
        printf("Input ERROR!\n");
        return NULL;
    }

    N = 0;
    while(fscanf(in, "%lf", &buf) != EOF)
        N++;
    //printf("%d\n", N);
    *n = N;

    A = (double*)malloc((int)sizeof(double) * N);

    fseek(in, 0, SEEK_SET);
    for(i = 0; i < N; ++i)
            fscanf(in, "%lf", &A[i]);

    fclose(in);
    return A;
}

void print_arr(double *X, int n)
{
    int i;

    for(i = 0; i < n; i++)
        printf("%.2lf ", X[i]);
    printf("\n");
}

double *solve(double *X, int N, int *outl, int **O, int cas)
{
    int i, L, lo, hi, mid, newL, k;
    int *P, *M;
    double *S;

    P = (int*)calloc((int)sizeof(int), N);
    M = (int*)calloc((int)sizeof(int), (N + 1));

    L = 0;
    if(cas)
    {
        for(i = 0; i < N; i++)
        {
            lo = 1;
            hi = L;
            while(lo <= hi)
            {
                mid = ceil((lo + hi) / 2);
                if(X[M[mid]] <= X[i]) //
                    lo = mid + 1;
                else
                    hi = mid - 1;

            }

            newL = lo;

            P[i] = M[newL - 1];
            M[newL] = i;

            if(newL > L)
                L = newL;
        }
    }
    else
    {
        for(i = 0; i < N; i++)
        {
            lo = 1;
            hi = L;
            while(lo <= hi)
            {
                mid = ceil((lo + hi) / 2);
                if(X[M[mid]] >= X[i]) //
                    lo = mid + 1;
                else
                    hi = mid - 1;

            }

            newL = lo;

            P[i] = M[newL - 1];
            M[newL] = i;

            if(newL > L)
                L = newL;
        }
    }


    S = (double*)malloc((int)sizeof(double) * L);
    *O = (int*)malloc((int)sizeof(int) * L);

    k = M[L];
    for(i = L - 1; i >= 0; i--)
    {
        (*O)[i] = k;
        //printf("%d\n", O[i]);
        S[i] = X[k];
        k = P[k];
    }
    *outl = L;

    return S;
}

void out(char *filename, double *X, int *O, int n)
{
    int i;
    FILE *out;

    if(!(out = fopen(filename, "w")))
    {
        printf("Output ERROR!\n");
        return;
    }

    if(O)
        for (i = 0; i < n; i++)
            fprintf(out, "%d %.2lf\n", O[i], X[i]);
    else
        for (i = 0; i < n; i++)
            fprintf(out, "%.2lf\n", X[i]);

    fclose(out);
}
