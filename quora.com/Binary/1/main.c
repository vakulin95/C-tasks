#include <stdio.h>

#define PART1(X)        (X) & 1
#define PART2(X, Y)     (X) * (Y)
#define PART3(X)        -~X
#define PART4(X, Y)     (X) ^ (Y)

int print_bin(int x);

int main()
{
    int x, y;

    printf("\n----------------------------------------\n");
    printf("PART 1\n");
    printf("Input:\t");
    scanf("%d", &x);

    if(PART1(x))
    {
        printf("Integer is odd!\n");
    }
    else
    {
        printf("Integer is even!\n");
    }

    printf("\n----------------------------------------\n");

    printf("PART 2\n");
    printf("Input:\t");
    scanf("%d %d", &x, &y);
    if(PART2(x, y) > 0)
    {
        printf("Integers have the same signs\n");
    }
    else
    {
        printf("Integers have the opposite signs\n");
    }

    printf("\n----------------------------------------\n");

    printf("PART 3\n");
    printf("Input:\t");
    scanf("%d", &x);
    printf("Output:\t%d\n", PART3(x));

    printf("\n----------------------------------------\n");

    printf("PART 4\n");
    printf("Input:\t");
    scanf("%d %d", &x, &y);

    if(x != y)
    {
        x = PART4(x, y);
        y = PART4(x, y);
        x = PART4(x, y);
    }

    printf("Output:\t%d %d\n", x, y);

    printf("\n----------------------------------------\n");

    return 0;
}

int print_bin(int x)
{
    while(x)
    {
        printf("%d", x & 0x01);
        x >>= 1;
    }
    printf("\n");

    return 0;
}
