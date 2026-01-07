#include <stdio.h>
#include <stddef.h>

// Déclaration
void somme(int T[], int S[], size_t n);
void inverse(int T[], size_t n);
void permute(int T[], size_t n);
void permuteLeft(int T[], size_t n);
void printArray(int[], size_t);

// Implémentation

void somme(int T[], int S[], size_t n)
{
    // S[i] = T[0]+...+T[i]
    for (size_t i = 0; i < n; i++)
    {
        int sum = 0;
        for (size_t j = 0; j <= i; j++)
        {
            sum += T[j];
        }
        S[i] = sum;
    }

    printArray(S, n);
}

// Fonction avec un décalage vers la gauche (j'avais mal lu le sujet)
void permuteLeft(int T[], size_t n)
{
    int fstvalue = T[0];
    for (size_t i = 0; i < n; i++)
    {
        int tmp = T[i];
        T[i] = T[(i+1)%n];
    }
    T[n-1] = fstvalue;
}

void permute(int T[], size_t n)
{
    int lastValue = T[n-1];    
    for (size_t i = n; i > 0; i--)
    {
        int tmp = T[i];
        T[i] = T[i-1];
    }
    T[0] = lastValue;
}

// Fonction pour inverser le tableau
void inverse(int T[], size_t n)
{
    for (size_t i = 0; i < n / 2; i++)
    {
        int tmp = T[i];
        T[i] = T[n - i - 1];
        T[n - i - 1] = tmp;
    }
}

int T[] = {1, 2, 3, 4};
int U[7] = {1, 2, 3, 4, 5, 6, 7};
int S[5];
int SU[7];
int main(void)
{
    permute(T, 4);
    printArray(T, 4);
    return 0;
}

// Utilitaire

void printArray(int T[], size_t n)
{
    puts("Tableau :");
    for (size_t i = 0; i < n; i++)
    {
        printf("T[%zu] = %d\n", i, T[i]);
    }
    puts("--------------------");
}