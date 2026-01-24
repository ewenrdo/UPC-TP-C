#include <stdio.h>
#include <stdlib.h>
int main()
{
    unsigned *p = NULL;
    unsigned d = *p;
    printf("Valeur de d : %u\n", d);

    return EXIT_SUCCESS;
}