/* Un premier programme simple*/
#include <stdio.h>
#include <stdlib.h>

/* Déclarer les fonctions avant de les utiliser (leur prototype) */
int main(void);
int testMemorySize(void);

/*Programme principal*/
int main(void)
{
    int x = 12;
    for (unsigned i = 0; i < 10; ++i)
    {
        printf("i vaut %u et x vaut %d\n", i, x);
        x += 3;
    }

    puts("Deuxième partie du code"); // équivalent println, mais ne permet pas d'avoir des expressions dedans

    testMemorySize();

    return EXIT_SUCCESS;
}

int testMemorySize(void) {
    signed int x = 0;

    x-=1;
    printf("Taille en mémoire de x est %llu\n",sizeof(x));


    return EXIT_SUCCESS;
}