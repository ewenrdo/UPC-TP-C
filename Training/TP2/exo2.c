#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#define SUP 100

// Déclarations
unsigned int sup = SUP;
void initialisation(bool T[], size_t n);
void remplissage(bool T[], size_t n);
void affichNbPremier(bool T[], size_t n);
void printBoolArray(bool T[], size_t n);
bool prime[SUP];

// Implémentation

void initialisation(bool T[], size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        T[i] = true;
    }
}
void remplissage(bool T[], size_t n)
{
    T[0] = false; // 1 n'est pas premier

    for (size_t i = 0; i < n; i++)
    {
        if (T[i] == false)
        {
            continue; // on passe au suivant
        }

        for (size_t j = i + 1; j < n; j++) // j = i+1 car sinon on aurait toujours j % i = 0 (et donc on aurait aucun nombre premier)
        {
            if ((j + 1) % (i + 1) == 0)
            { // si j est multiple de i, on le retire
                T[j] = false;
            }
        }
    }
}

void affichNbPremier(bool T[], size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        if (T[i] == true)
        {
            printf("%llu est premier\n", ((unsigned long long)i) + 1);
        }
    }
}

int main(void)
{
    initialisation(prime, sup);
    printBoolArray(prime, sup);
    remplissage(prime, sup);
    affichNbPremier(prime, sup);
}

// Utilitaires

void printBoolArray(bool T[], size_t n)
{
    puts("Tableau :");
    for (size_t i = 0; i < n; i++)
    {
        printf("T[%llu] = %d\n", (unsigned long long)i, T[i]);
    }
    puts("--------------------");
}

void printArray(int T[], size_t n)
{
    puts("Tableau :");
    for (size_t i = 0; i < n; i++)
    {
        printf("T[%llu] = %d\n", (unsigned long long)i, T[i]);
    }
    puts("--------------------");
}