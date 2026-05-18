#include <stdio.h>
#include <stdlib.h>

// Prototypes
void afficher_page(int k, char *s);
char *mettre_en_page(int k, char *s);

// k = 1 : abcde\nf\ng\nh\n (fini tjrs pas \n)
// renvoie : "ab\ncd\ne\nf\ng\nh\n"
int get_needed_lenght(int k, char *s)
{

    int reqLength = 1; // pour le '\0'
    // 1. Calcul de la taille requise
    size_t i = 0;
    int cur = -2; // valeur qui va disparaitre
    int charSinceNL = 0;
    while (cur != EOF && cur != '\0')
    {
        cur = s[i];
        if (cur == '\0')
            break;
        if (cur == '\n')
        {
            charSinceNL = 0;
            reqLength++; // il sera quand même dedans
            i++;
            continue;
        }
        // Sinon, on a que des "vrais" caractères
        reqLength++;
        if (charSinceNL == k + 1)
        {
            reqLength++;
            charSinceNL = 0; // le caractère + le \n qui suit
        }
        charSinceNL++;
        i++;
    }

    return reqLength;
}
char *mettre_en_page(int k, char *s)
{
    int needed_chars = get_needed_lenght(k, s);
    if (needed_chars == 0)
        return NULL;

    char *res = malloc(needed_chars * sizeof(char));
    if (res == NULL)
        return NULL;

    size_t i = 0;
    size_t lastIndex = 0;
    int charSinceNL = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '\n')
        {
            res[lastIndex] = '\n';
            lastIndex++;
            i++;
            charSinceNL = 0;
            continue; // passer au caractère suivant de s
        }
        if (charSinceNL == k + 1)
        {
            res[lastIndex] = '\n';
            lastIndex++;
            charSinceNL = 0;
            continue;
        }
        res[lastIndex] = s[i];
        i++;
        lastIndex++;
        charSinceNL++;
    }

    res[lastIndex] = '\0'; // bien terminer la chaîne !

    return res;
}

int main()
{
    // 📝 Notre texte de test
    char *texte = "abcde\nfg\nh\n";
    int k = 1;

    printf("--- Test de afficher_page (k=%d) ---\n", k);
    afficher_page(k, texte);

    printf("Needed : %d\n", get_needed_lenght(k, texte));
        printf("\n--- Test de mettre_en_page (k=%d) ---\n", k);
        char *resultat = mettre_en_page(k, texte);

        if (resultat != NULL) {
            // On affiche le résultat obtenu pour vérifier s'il est correct
            printf("%s", resultat);

            // ⚠️ Très important : libérer la mémoire allouée par malloc dans mettre_en_page
            free(resultat);
        } else {
            printf("Erreur : l'allocation a échoué.\n");
        }

    return 0;
}

void afficher_page(int k, char *s)
{
    int col = 0; // Compteur pour suivre la position sur la ligne actuelle

    for (int i = 0; s[i] != '\0'; i++)
    {
        // Cas 1 : On rencontre un retour à la ligne déjà présent dans le texte
        if (s[i] == '\n')
        {
            putchar('\n');
            col = 0; // On recommence une nouvelle ligne
        }
        else
        {
            // Cas 2 : La ligne est trop longue (on a déjà écrit k+1 caractères)
            if (col > k)
            {
                putchar('\n');
                col = 0;
            }

            // On affiche le caractère actuel
            putchar(s[i]);
            col++;
        }
    }
}