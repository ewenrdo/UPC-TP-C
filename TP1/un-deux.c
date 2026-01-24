#include <stdio.h>

// Implémentation
int main(void)
{

    unsigned answer;
    printf(">>> ");
    scanf("%u", &answer);

    switch (answer)
    {
    case 0:
        puts("aucun");
        break;
    case 1:
        puts("un");
        break;
    case 2:
        puts("deux");
        break;
    default:
        puts("plusieurs");
        break;
    }

    return 0;
}