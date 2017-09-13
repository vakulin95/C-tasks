#include <stdio.h>

int main()
{
    int i;

    for(i = 300; i >= 0; i -= 20)
        printf("%3d %6.1f\n", i, (5.0/9.0)*(i - 32));

    return 0;
}
