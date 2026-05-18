#include <stdio.h>
#include <stdlib.h>

/**
 * OBJECTIF : IMPLEMENTER UN "SUPER TABLEAU PASCAL" (= slice)
 */

struct array
{
    int *p;
    int cap;
    int length;
};
typedef struct array sliceArray;

void freeArray(sliceArray *tab)
{
    if (tab == NULL)
        return;
    if (tab->p != NULL)
        free(tab->p);

    free(tab);
}

sliceArray *newSlice(int defaultSize)
{
    sliceArray *res = malloc(sizeof(sliceArray));
    if (res == NULL)
        return NULL;

    int *p = malloc(sizeof(int) * defaultSize);
    if (p == NULL)
    {
        freeArray(res);
        return;
    }

    res->p = p;
    res->cap = defaultSize;
    res->length = 0;
    return res;
}

sliceArray *resize(sliceArray *tab)
{
    int *newPointer = NULL;
    if (tab->length < tab->cap / 2)
    {
        newPointer = realloc(tab->p, (tab->cap / 2) * sizeof(int));
        if (newPointer == NULL)
            return;
        tab->p = newPointer;
        tab->cap /= 2;
    }
    else if (tab->length >= tab->cap - 1)
    {
        newPointer = realloc(tab->p, (tab->cap * 2) * sizeof(int));
        if (newPointer == NULL)
            return;
        tab->p = newPointer;
        tab->cap *= 2;
    }
    else
    {
        fprintf(stderr, "No resize needed.\n");
        return;
    }
}

int append(sliceArray *tab, int elt) {
    if (tab->length == tab->cap - 1) {
        int initSize = tab->cap;
        resize(tab);
        if(initSize == tab->cap) return 1;
    }

    tab->p[tab->length] = elt;
    tab->length++; 
    
}

int main()
{
    printf("Hello, world!\n");
}