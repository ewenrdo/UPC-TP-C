#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ROT13 : retourne dest si succès, NULL si dest trop petit
char *rot13(char *dest, size_t dsize, const char *src) {
    if (dsize == 0) return NULL; // pas d'espace pour '\0'

    size_t len = strlen(src);
    if (len + 1 > dsize) {
        return NULL; // buffer trop petit
    }

    for (size_t i = 0; i < len; i++) {
        char c = src[i];

        if (c >= 'a' && c <= 'z') {
            dest[i] = ((c - 'a' + 13) % 26) + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            dest[i] = ((c - 'A' + 13) % 26) + 'A';
        } else {
            dest[i] = c; // autres caractères inchangés
        }
    }

    dest[len] = '\0';
    return dest;
}

int main(int nbr_args, char *args[]) {
    for (int i = 1; i < nbr_args; i++) { // on ignore args[0]
        size_t len = strlen(args[i]);
        char *buffer = malloc(len + 1); // suffisamment grand pour l'argument
        if (!buffer) {
            fprintf(stderr, "Erreur d'allocation\n");
            return 1;
        }

        if (rot13(buffer, len + 1, args[i])) {
            printf("%s ", buffer);
        } else {
            printf("[BUFFER TROP PETIT] ");
        }

        free(buffer);
    }
    printf("\n");
    return 0;
}