#include <stdio.h>

#define DEF_NUM             11
#define DEF_K               2
#define OFF_K_BIT(X, K)     X & (~(1 << (K - 1)))
#define ON_K_BIT(X, K)      X | (1 << (K - 1))
#define CHECK_K_BIT(X, K)   X & (1 << (K - 1))
#define TOOGLE_K_BIT(X, K)  X ^ (1 << (K - 1))

void print_bits(int x);

int main()
{
    int i;

    printf("Input:\t\t\t");
    print_bits(DEF_NUM);

    printf("OFF %d-th bit:\t\t", DEF_K);
    print_bits(OFF_K_BIT(DEF_NUM, DEF_K));

    printf("ON %d-th bit:\t\t", DEF_K);
    print_bits(ON_K_BIT(DEF_NUM, DEF_K));

    printf("Check %d-th bit:\t\t", DEF_K);
    if(CHECK_K_BIT(DEF_NUM, DEF_K))
    {
        printf("%d-th bit is set\n", DEF_K);
    }
    else
    {
        printf("%d-th bit is unset\n", DEF_K);
    }

    printf("TOOGLE %d-th bit:\t", DEF_K);
    print_bits(TOOGLE_K_BIT(DEF_NUM, DEF_K));

    return 0;
}

void print_bits(int x)
{
    printf("%d", x & 0x01);
    while(x)
    {
        x >>= 1;
        printf("%d", x & 0x01);

    }
    printf("\n");
}
