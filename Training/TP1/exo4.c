#include <stdio.h>
#include <stdbool.h>

// Déclaration
int main(void);
unsigned retourne(unsigned n);
unsigned sommeChiffre(unsigned n);
bool estNarcissique(unsigned n);
void afficheNarcissique(unsigned n);
unsigned retourne4(unsigned n);

// Implémentation
unsigned retourne(unsigned n)
{
    unsigned size = 0;
    if (n == 0)
    {
        return 1;
    }

    while (n != 0)
    {
        n /= 10;
        size++;
    }
    return size;
}

unsigned sommeChiffre(unsigned n)
{
    unsigned sum = 0;

    while (n != 0)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

bool estNarcissique(unsigned n)
{
    unsigned originalNumber = n;
    unsigned cubeSum = 0;

    while (n != 0)
    {
        cubeSum += (n % 10) * (n % 10) * (n % 10);
        n /= 10;
    }

    return (cubeSum == originalNumber);
}

void afficheNarcissique(unsigned n)
{
    for (unsigned i = 0; i <= n; i++)
    {
        if (estNarcissique(i))
        {
            printf("[Nar] %u\n", i);
        }
    }
}

unsigned retourne4(unsigned n)
{
    unsigned int revertedNumber = 0;

    while (n != 0)
    {
        unsigned int digit = n % 10;
        revertedNumber = revertedNumber * 10 + digit;
        n /= 10;
    }

    return revertedNumber;
}

// Test
int main(void)
{
    printf("Taille de 314 : %u\n", retourne(314));
    printf("Somme des chiffres de 42 : %u\n", sommeChiffre(42));
    printf("153 est-il narcissique ? : %s\n", estNarcissique(153) ? "true" : "false");
    printf("42 est-il narcissique ? : %s\n", estNarcissique(42) ? "true" : "false");
    afficheNarcissique(1000);
    printf("42 inversé : %u\n", retourne4(42));
    return 0;
}