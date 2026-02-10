#include <gtk/gtk.h>
#include <complex.h>
#include "graphiques.h"

int mandelbrot(complex double c);

int main()
{
    gr_init(400, 400);

    for (int i = 0; i < 400; i++)
    { // Largeur du carré (200 pixels)
        for (int j = 0; j < 400; j++)
        { // Hauteur du carré (200 pixels)
            complex double z = (i - 200.0) / 100.0 + (j - 200.0) * I / 100;
            int rate = mandelbrot(z);
            int val = (int)((double)rate / 1000.0 * 255);

            int red = rate == -1 ? 0 : val;
            int green = rate == -1 ? 0 : val;
            int blue = rate == -1 ? 0 : 255 - val;

            gr_draw_point(i, j, red, green, blue); // Couleur (0, 34, 83) - une couleur bleue
        }
    }

    gr_display();
    return 0;
}

int mandelbrot(complex double c)
{
    complex double z = 0 + I * 0; // z0 = 0
    int n;

    for (n = 0; n < 1000; n++)
    {
        z = z * z + c; // z_{n+1} = z_n^2 + c
        if (creal(z) * creal(z) + cimag(z) * cimag(z) > 4)
        { // test de divergence
            return n;
        }
    }
    return -1; // pas de divergence après 1000 itérations
}
