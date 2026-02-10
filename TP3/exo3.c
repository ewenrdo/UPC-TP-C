#include <gtk/gtk.h>
#include "graphiques.h"
#include <math.h>

int
main()
{
    gr_init(800, 400);
    
    for (int x = 0; x < 800; x++)
    {
        gr_draw_point(x, 200 + 200*cos((x * M_PI * 2) / 800), 0,0,0);
    }
    

    gr_display();
    return 0;
}
