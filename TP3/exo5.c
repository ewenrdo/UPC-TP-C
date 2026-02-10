#include <gtk/gtk.h>
#include "graphiques.h"
#include <math.h>

int main(void) {

    gr_init(800, 400);

    int center_x = 400; // Centre de l'écran en x
    int center_y = 200; // Centre de l'écran en y
    int radius = 100;   // Rayon du cercle

    // On va utiliser les coordonnées polaires
    for (double theta = 0; theta < 2*M_PI; theta +=0.01) {
        int x = center_x + radius * cos(theta); // Calcul de la coordonnée x
        int y = center_y + radius * sin(theta); // Calcul de la coordonnée y
        gr_draw_point(x, y, 0, 0, 255); // Dessiner le point en bleu
    }

    gr_display();
    return 0;
}