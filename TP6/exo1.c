#include <stdio.h>
#include <stdlib.h>

int a;
void f()
{
    int j;
    printf("&j: %p\n", &j);
}

int main()
{
    int i;
    int *p;
    p = malloc(sizeof(int));

    if (p == NULL)
    {
        fprintf(stderr, "Échec d'allocation\n");
        exit(2);
    }
    f();
    printf("&a: %p, &i: %p, p: %p\n", &a, &i, p);
    free(p);
    return 0;
}

/*

1.

&j: 00000023313FFC2C
&a: 00007FF7008590A0, &i: 00000023313FFC64, p: 00000210C42CF010

On crée dans ce sens :
1. a : 7FF7008590A0
2. i : 23313FFC64
3. p : 210C42CF010
4. appel de f()
5. création de j : 7FF7008590A0

La pile a l'air de croitre vers le bas. (avec une différence de zone entre variables locales et globales)

2. La pile est en haut de la mémoire virtuelle, tandis que le tas est contigu à la zone des données.

*/