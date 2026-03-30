#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// retourne vrai si l’octet c apparaît dans le tableau f de longueur n
int member(char c, const char *f, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (f[i] == c)
            return 1;
    }

    return 0;
}

// affiche s en remplaçant par des * les octets qui ne sont pas dans le tableau f de longueur n
// renvoie le nombre de '*' renvoyé.
int partial_display(const char *s, const char *f, int n)
{
    int astx_count = 0;
    for (size_t i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ')
            putchar(' ');
        else if (member(s[i], f, n) == 1)
            printf("%c", s[i]);
        else
        {
            printf("*");
            astx_count++;
        }
    }
    return astx_count;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage : %s <mot>\n", argv[0]);
        return 1;
    }

    const char *s = argv[1];
    int attempts = 0;

    char *f = malloc((11 + strlen(s)) * sizeof(char));
    if (!f) return 1;

    int currentIdx = 0;
    int n_aster = strlen(s);

    while (n_aster != 0 && attempts < 10)
    {
        char c;
        printf("Entrez une lettre : ");
        scanf(" %c", &c); // espace avant %c pour ignorer \n

        f[currentIdx++] = c;
        attempts++;

        n_aster = partial_display(s, f, currentIdx);
        printf("\n");
    }

    free(f);

    if (n_aster == 0) {
        printf("Bravo ! Vous avez trouvé le mot.\n");
    } else {
        printf("Vous avez utilisé toutes vos tentatives.\n");
    }

    return 0;
}