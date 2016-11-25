#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT "data/input.txt"
#define OUTPUT "data/out.txt"

double *input_arr(char*, int*);
void print_arr(double*, int);
double *solve(double*, int, int*);
void out(char*, double*, int);

int main()
{
    int n, newl;
    double *X, *S;

    X = input_arr(INPUT, &n);
    print_arr(X, n);
    S = solve(X, n, &newl);
    print_arr(S, newl);
    out(OUTPUT, S, newl);

    return 0;
}

double *input_arr(char *filename, int *n)
{
    int i, j, N;
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
        printf("%5.2lf ", X[i]);
    printf("\n");
}

double *solve(double *X, int N, int *outl)
{
    int i, L, lo, hi, mid, newL, k;
    int *P, *M;
    double *S;

    P = (int*)calloc((int)sizeof(int), N);
    M = (int*)calloc((int)sizeof(int), (N + 1));

    L = 0;
    for(i = 0; i < N; i++)
    {
        lo = 1;
        hi = L;
        while(lo <= hi)
        {
            mid = ceil((lo + hi) / 2);
            if(X[M[mid]] > X[i]) //
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

    S = (double*)malloc((int)sizeof(double) * L);

    k = M[L];
    for(i = L - 1; i >= 0; i--)
    {
        S[i] = X[k];
        k = P[k];
    }
    *outl = L;

    return S;
}

void out(char *filename, double *X, int n)
{
    int i;
    FILE *out;

    if(!(out = fopen(filename, "w")))
    {
        printf("Input ERROR!\n");
        return;
    }

    for (i = 0; i < n; i++)
        fprintf(out, "%5.2lf\n", X[i]);

    fclose(out);
}
