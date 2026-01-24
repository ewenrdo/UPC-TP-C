#include <stdio.h>

int main(void)
{
    int ss_nbr;
    printf(">>> ");
    scanf("%d", &ss_nbr);

    while (ss_nbr >= 10)
    {
        ss_nbr /= 10;
    }

    // printf("Bonjour %s.", ss_nbr == 1 ? "Monsieur" : "Madame");
    printf("Bonjour%s.", ss_nbr == 1 ? " Monsieur" : ss_nbr == 2 ? " Madame" : "");
}