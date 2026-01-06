#include <stdio.h>

// Déclaration mémoire
int main(void);
unsigned v; // entier non signé

// Implémentation
int main(void)
{
    printf("Hello world !\n");
    printf(">> ");
    scanf("%u", &v);
    printf("v vaut : %u", v);
}