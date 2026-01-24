#include <stdio.h>

// Déclaration
size_t occ(int *t, size_t nbr, int v);

// Implémentation

size_t occ(int *t, size_t nbr, int v)
{
    for (size_t i = 0; i < nbr; i++)
    {
        if (t[i] == v)
        {
            return i;
        }
    }

    return nbr;
}

int *occ_ptr(int *t, size_t nbr, int v)
{
    for (size_t i = 0; i < nbr; i++)
    {
        if (t[i] == v)
        {
            return t+i;
        }
    }

    return NULL;
}

int main(void)
{
    int t[5] = {1, 2, 3, 4, 5};
    printf("%lld\n", occ(t, 5, 5));
    printf("%p", occ_ptr(t, 5, 5));
}