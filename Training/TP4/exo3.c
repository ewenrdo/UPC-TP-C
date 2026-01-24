#include <stdio.h>
#include <limits.h>

// Déclaration
size_t nbr_occ(int *t, size_t nbr, int v);
void nbr_occ_op(int *t, size_t nbr, int v, size_t *pnv);
void min_max_op(int *t, size_t nbr, int *pmin, int *pmax);

// Implémentation
size_t nbr_occ(int *t, size_t nbr, int v)
{
    size_t res = 0;
    for (size_t i = 0; i < nbr; i++)
    {
        if (t[i] == v)
        {
            res++;
        }
    }

    return res;
}

void nbr_occ_op(int *t, size_t nbr, int v, size_t *pnv)
{
    size_t res = 0;
    for (size_t i = 0; i < nbr; i++)
    {
        if (t[i] == v)
        {
            res++;
        }
    }

    *pnv = res;
}

void min_max_op(int *t, size_t nbr, int *pmin, int *pmax)
{
    *pmin = t[0];
    *pmax = t[0];
    for (size_t i = 1; i < nbr; i++)
    {
        if (t[i] > *pmax)
            *pmax = t[i];
        if (t[i] < *pmin)
            *pmin = t[i];
    }
}

int main(void) {
    int tab[5] = {-1,2,4,6,2};
    
    printf("%lld\n", nbr_occ(tab, 5, 2)); // deux occurence
    printf("%lld\n", nbr_occ(tab, 5, 0)); // aucune occurence

    size_t nbr_occ;
    nbr_occ_op(tab, 5, -1, &nbr_occ);
    printf("%lld\n", nbr_occ); // une occurence

    int pmax;
    int pmin;
    min_max_op(tab, 5, &pmin, &pmax);
    printf("max : %d\n", pmax);
    printf("max : %d", pmin);
}