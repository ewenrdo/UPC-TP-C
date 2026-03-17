#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct slice
{
    int *a;
    int len; // nombre d'éléments du slice
    int cap; // taille de l'allocation du champ 'a' en unités de la taille d'un élément
};
typedef struct slice Slice;
int extend(Slice *s);
Slice *new_slice(int cap)
{
    Slice *res = malloc(sizeof(Slice));
    if (res == NULL)
        return NULL;

    res->len = 0;
    res->cap = cap;

    res->a = malloc(cap * sizeof(int));
    if (res->a == NULL)
    {
        free(res);
        return NULL;
    }
    return res;
}

void destroy_slice(Slice *s)
{
    free(s->a);
    free(s);
}

// ajoute un élément de valeur v à la fin d’un slice. Cette fonction retournera 1 si elle réussit,
// et -1 s’il n’y a plus de place dans le slice
int snoc(Slice *s, int v)
{
    if (s->len == s->cap)
    {
        return -1;
    }

    *(s->a + s->len) = v;
    s->len = s->len + 1;
    return 1;
}

int snocBis(Slice *s, int v)
{
    if (s->len == s->cap && extend(s) == -1)
    {
        return -1;
    }

    *(s->a + s->len) = v;
    s->len = s->len + 1;
    return 1;
}

Slice *read_slice()
{
    Slice *res = new_slice(10);
    bool pos = true;
    while (pos)
    {
        int tmp;
        scanf("%d", &tmp);
        if (tmp >= 0)
        {
            if (snoc(res, tmp) == -1)
            {
                destroy_slice(res);
                return NULL;
            }
        }
        else
        {
            pos = false;
        }
    }

    return res;
}

int extend(struct slice *s)
{
    int n = (s->cap > 0) ? 2 * (s->cap) : 4;

    // Crée le tableau de taille n
    int *tab = malloc(n * sizeof(int));
    if(tab == NULL) {
        return -1;
    }

    // Copie les valeurs du slice
    for (size_t i = 0; i < s->len; i++)
    {
        tab[i] = *(s->a + i);
    }

    free(s->a);
    s->a = tab;
    s->cap = n;

    return 1;
}