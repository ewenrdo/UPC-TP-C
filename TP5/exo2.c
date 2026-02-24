#include <stdio.h>
#include <math.h>
#include "notes.h" // permet d'utiliser les variables déclarées dans notes.c

int main(void)
{

    puts("------------------------");
    puts("|  NUMERO  |   NOTE    |");
    for (size_t i = 0; i < nombre_notes; i++)
    {
        printf("|   %d   |   %.2f   |\n", notes[i].numero, floor(notes[i].note * 100) / 100);
    }
    puts("------------------------");

    // Calcul de la moyenne des notes
    double sum = 0;
    for (size_t i = 0; i < nombre_notes; i++)
    {
        sum += notes[i].note;
    }
    sum /= nombre_notes;
    printf("Mean grade : %.2f\n", sum);

    // Meilleurs étudiants
    int maxGrade = notes[0].note;
    for (size_t i = 0; i < nombre_notes; i++)
    {
        if (notes[i].note > maxGrade)
        {
            maxGrade = notes[i].note;
        }
    }

    printf("Best students : ");
    for (size_t i = 0; i < nombre_notes; i++)
    {
        if (notes[i].note == maxGrade)
        {
            printf("%d ", notes[i].numero);
        }
    }
    printf("\n");

    // Afficher les notes par intervales [2k, 2k+2[
    /*
    Implémentation :
    - Créer un tableau où T[i] correspond à l'intervale [2k, 2k+2[ et T[10] = out of range
    - Print le tableau
    */

    int deciles[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (size_t i = 0; i < nombre_notes; i++)
    {
        int kMin = 0;
        if (notes[i].note < 0 || notes[i].note > 20)
            kMin = 10;
        else
        {
            kMin = (int)floor(notes[i].note / 2);
            if (kMin == 10)
                kMin = 9; // mettre le 20 dans k = 9
        }
        deciles[kMin] = deciles[kMin] + 1;
    }

    puts("------------------------");
    puts("|  PALIER  |   NOMBRE  |");
    for (size_t i = 0; i < 11; i++)
    {
        printf("|    > %lld   |     %d     |\n", 2 * i, deciles[i]);
    }
    puts("------------------------");

    return 0;
}