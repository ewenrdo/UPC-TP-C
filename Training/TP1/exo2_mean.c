#include <stdio.h>

// Déclaration mémoire
int main(void);
unsigned int sum = 0;
unsigned int amount = 0;
unsigned int read;
// Implémentation

int main(void)
{
    do
    {
        printf("\nEntrez un entier : ");
        scanf("%u", &read);
        sum += read;
        ++amount;
    } while (read != 0);

    amount--; // car on a compté le 0

    printf("\nLa moyenne est : %lf", (double)sum / (double)(amount));

    return 0;
}
