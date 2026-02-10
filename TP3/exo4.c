#include <gtk/gtk.h>
#include "graphiques.h"
#include <math.h>

unsigned syracuse(int m);

int main()
{
    gr_init(800, 400);  
    
    unsigned max_steps = 0; 

    // Pour mettre à l'échelle
    for (int n = 1; n <= 200; n++) {
        unsigned steps = syracuse(n);
        if (steps > max_steps) {
            max_steps = steps;  // Trouver le nombre maximum d'étapes
        }
    }

    for (int n = 1; n <= 200; n++) {
        unsigned steps = syracuse(n);

        // Normalisation de y pour qu'il reste dans l'intervalle [0, 400]
        int y = (int)((float)steps / max_steps * 400);

        gr_draw_point(n, 400 - y, 0, 0, 0);  // 400 - y pour que les petites valeurs soient en bas
    }

    gr_display();  
    return 0;
}

// Fonction pour calculer le nombre d'étapes de la séquence de Syracuse pour un nombre donné
unsigned syracuse(int m)
{
    int res = m;
    unsigned flight_time = 0;

    while (res != 1)  // La séquence s'arrête lorsqu'on atteint 1
    {
        flight_time++;  // Incrémentation du nombre d'étapes
        if (res % 2 == 0)
        {
            res = res / 2;  // Si m est pair, on divise par 2
        }
        else
        {
            res = 3 * res + 1;  // Si m est impair, on applique la formule 3m + 1
        }
    }

    return flight_time;  // Retourne le nombre d'étapes avant d'atteindre 1
}

unsigned syracuse(int m)
{
    int res = m;
    unsigned flight_time = 0;

    while (res != 1)
    {
        flight_time++;
        if (res % 2 == 0)
        {
            res = res / 2;
        }
        else
        {
            res = 3 * res + 1;
        }
    }

    return flight_time;
}