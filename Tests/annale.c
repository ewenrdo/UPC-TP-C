/*
Écrire une fonction char *couper(char *s, int pos, int nbr). Cette fonction doit allouer,
construire, puis renvoyer l’adresse de départ d’une nouvelle chaîne contenant tous les caractères de s dans
l’ordre où ils apparaissent dans s, sauf ceux dont les positions sont comprises entre pos et pos + (nbr-1)
inclus.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *copier(char *s, int pos, int nbr) {
    int len_s = strlen(s);
    int abs_nbr = (nbr < 0) ? -nbr : nbr;
    
    // On alloue la taille demandée + 1 pour le '\0'
    char *res = malloc(sizeof(char) * (abs_nbr + 1));
    if (res == NULL) return NULL;

    int curseur = 0;
    int direction = (nbr >= 0) ? 1 : -1;

    for (int i = 0; i < abs_nbr; i++) {
        // Calcul de la position théorique dans s
        int p = pos + (i * direction);
        
        // On ne copie que si la position existe réellement dans s
        if (p >= 0 && p < len_s) {
            res[curseur] = s[p];
            curseur++;
        }
    }

    res[curseur] = '\0'; // Toujours terminer la chaîne !
    
    return res;
}
char *couper(char *s, int pos, int nbr) {
    // 1. On récupère les deux morceaux proprement
    char *part1 = copier(s, 0, pos);
    char *part2 = copier(s, pos + nbr, strlen(s));

    if (part1 == NULL || part2 == NULL) return NULL;

    // 2. On calcule la taille nécessaire pour le résultat final
    int len1 = strlen(part1);
    int len2 = strlen(part2);
    char *res = malloc(sizeof(char) * (len1 + len2 + 1));

    if (res == NULL) return NULL;

    // 3. On assemble les morceaux dans le nouveau bloc
    // On copie la partie 1
    for (int i = 0; i < len1; i++) {
        res[i] = part1[i];
    }

    // On ajoute la partie 2 à la suite
    for (int i = 0; i < len2; i++) {
        res[len1 + i] = part2[i];
    }

    // 4. On n'oublie pas le caractère de fin !
    res[len1 + len2] = '\0';

    // 5. CRUCIAL : On libère la mémoire des morceaux temporaires
    free(part1);
    free(part2);

    return res;
}

int main() {
    char *s = "abcde";
    
    // Tests basés sur tes exemples
    printf("Test 1 (2, 2)  : %s\n", copier(s, 2, 2));   // "cd"
    printf("Test 2 (2, -3) : %s\n", copier(s, 2, -3));  // "cba" (attention: l'énoncé dit "abc" ?)
    printf("Test 3 (2, 5)  : %s\n", copier(s, 2, 5));   // "cde"
    printf("Test 4 (-2, 4) : %s\n", copier(s, -2, 4));  // "ab"
    
    printf("Rés couper : %s\n", couper(s, 1, 2));
    return 0;
}