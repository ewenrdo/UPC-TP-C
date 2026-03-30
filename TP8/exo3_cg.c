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
char *choose_random_word(void) {
    FILE *file = fopen("/usr/share/dict/words", "r");
    if (!file) {
        perror("Impossible d'ouvrir /usr/share/dict/words");
        exit(1);
    }

    // On compte d’abord le nombre de mots
    int word_count = 0;
    char buffer[128];
    while (fgets(buffer, sizeof(buffer), file))
        word_count++;

    if (word_count == 0) {
        fprintf(stderr, "Fichier vide\n");
        exit(1);
    }

    // Choisir un indice aléatoire
    srand(time(NULL));
    int target_index = rand() % word_count;

    // Revenir au début du fichier
    fseek(file, 0, SEEK_SET);

    // Lire le mot à l'indice choisi
    int idx = 0;
    char *word = NULL;
    while (fgets(buffer, sizeof(buffer), file)) {
        if (idx == target_index) {
            buffer[strcspn(buffer, "\n")] = '\0'; // enlever le '\n'
            word = malloc(strlen(buffer) + 1);
            strcpy(word, buffer);
            break;
        }
        idx++;
    }

    fclose(file);
    return word;
}
int main(void) {
    char *s = choose_random_word();
    printf("Bienvenue au jeu du pendu !\n");

    int max_attempts = 10;
    char *guesses = malloc(max_attempts * sizeof(char));
    int currentIdx = 0;

    int n_aster = strlen(s);
    while (n_aster != 0 && currentIdx < max_attempts) {
        printf("\nMot : ");
        n_aster = partial_display(s, guesses, currentIdx);
        printf("\nTentative %d/%d, entrez une lettre : ", currentIdx + 1, max_attempts);

        char c;
        scanf(" %c", &c); // ignore les espaces et '\n'
        guesses[currentIdx++] = c;
    }

    if (n_aster == 0) {
        printf("\nFélicitations ! Vous avez trouvé le mot '%s'\n", s);
    } else {
        printf("\nDommage ! Le mot était '%s'\n", s);
    }

    free(s);
    free(guesses);
    return 0;
}