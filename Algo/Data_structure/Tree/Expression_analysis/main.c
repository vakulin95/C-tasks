// Вычисление арифмтических выражений с помощью бинарных деревьев
#include "dstruct.h"

int main()
{
    Stack *top = NULL;
    Tree *root = make_tree(STR, 0, (int)strlen(STR) - 1);
    print(root, 0);

    printf("Stack evolution:\n");
    calc(root, &top);
    printf("\nAnswer: %d\n", pop(&top));

    return 0;
}
