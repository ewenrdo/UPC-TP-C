#include <gtk/gtk.h>
#include <complex.h>
#include "graphiques.h"

#define WIDTH 400
#define HEIGHT 400
#define MAX_ITER 2000

int mandelbrot(complex double c);

int main()
{
    gr_init(WIDTH, HEIGHT);

    // Paramètres de zoom et décalage
    double re_min = -2.0;
    double re_max = 1.0;
    double im_min = -1.5;
    double im_max = 1.5;

    double re_scale = (re_max - re_min) / WIDTH;
    double im_scale = (im_max - im_min) / HEIGHT;

    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            // Conversion pixel -> nombre complexe
            complex double c = (re_min + i * re_scale) + (im_min + j * im_scale) * I;
            int rate = mandelbrot(c);

            int red, green, blue;

            if (rate == -1) {
                // Point dans l'ensemble = noir
                red = green = blue = 0;
            } else {
                // Hors de l'ensemble = palette colorée selon le nombre d'itérations
                double t = (double)rate / MAX_ITER; // normalisation [0,1]
                red   = (int)(9*(1-t)*t*t*t*255);
                green = (int)(15*(1-t)*(1-t)*t*t*255);
                blue  = (int)(8.5*(1-t)*(1-t)*(1-t)*t*255);
            }

            gr_draw_point(i, j, red, green, blue);
        }
    }

    gr_display();
    return 0;
}

int mandelbrot(complex double c)
{
    complex double z = 0; // z0 = 0
    int n;

    for (n = 0; n < MAX_ITER; n++) {
        z = z*z + c;
        if (creal(z)*creal(z) + cimag(z)*cimag(z) > 4) {
            return n;  // divergence
        }
    }
    return -1;  // pas de divergence → point dans l'ensemble
}
