#include <stdio.h>

// Déclaration mémoire
int main(void);
unsigned fact(unsigned);
unsigned int number;
void factPrint(unsigned);

// Implémentation

int main(void)
{
    printf("Choisissez un chiffre \n");
    printf(">> ");
    scanf("%u", &number);

    unsigned sum = 0;
    for (unsigned i = 1; i <= number; i++)
    {
        sum += i * i * i;
    }

    printf("La somme est des cubes de 1 à n est : %u.\n", sum);
    printf("%u! = %u.\n", number, fact(number));

    factPrint(number);

    return 0;
}

unsigned fact(unsigned n)
{
    if (n == 0)
        return 1;

    return n * fact(n - 1);
}

void factPrint(unsigned n)
{
    for (unsigned i = 1; i <= n; i++)
    {
        printf("%u! = %u\n", i,fact(i));
    }
    
}
