#include <stdio.h>

#define DEF_NUM         1024

#define RM_UNSET(X)     (X & (X - 1))
#define RM_POS(X)       (RM_UNSET(X) ^ X)

void print_bits(int x);

int main()
{
    int num, temp;

    printf("Input:\t\t\t");
    print_bits(DEF_NUM);

    // Problem #1
    printf("Check pow of 2:\t\t%d\n", !RM_UNSET(DEF_NUM));

    // Problem #2, #3
    num = RM_POS(DEF_NUM);
    temp = 1;
    while(!(num & 0x01))
    {
        temp++;
        num >>= 1;
    }
    printf("Rm bit position:\t%d\n", temp);

    // Problem #4
    num = DEF_NUM;
    temp = 1;
    while(num)
    {
        num = RM_UNSET(num);
        temp = !temp;
    }

    if(temp)
    {
        printf("Parity is even\n");
    }
    else
    {
        printf("Parity is odd\n");
    }

    return 0;
}

void print_bits(int x)
{
    size_t i;
    int len = sizeof(int) * 8;
    int bit_str[len];

    for(i = 0; i < len; i++)
    {
        bit_str[i] = x & 0x01;
        x >>= 1;
    }

    for(i = 1; i <= len; i++)
    {
        printf("%d", bit_str[len - i]);
    }
    printf("\n");
}
