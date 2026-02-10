#include <gtk/gtk.h>
#include "graphiques.h"

void drawSpectrum();
void drawSpectrumSquare();

int
main()
{
    gr_init(512, 384);
    drawSpectrum();
    gr_display();
    return 0;
}

void drawSpectrum() {
    for (int x = 0; x < 256; x++)
    {
        gr_draw_point(x,100,x,0,255-x);
    }
}
void drawSpectrumSquare() {
    int depart_x = 100;  // Position de départ en x
    int depart_y = 100;  // Position de départ en y

    for (int i = 0; i < 200; i++) {  // Largeur du carré (200 pixels)
        for (int j = 0; j < 200; j++) {  // Hauteur du carré (200 pixels)
            gr_draw_point(depart_x + i, depart_y + j, i, j, 0);  // Couleur (0, 34, 83) - une couleur bleue
        }
    }
}
