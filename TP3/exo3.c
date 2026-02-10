#include <gtk/gtk.h>
#include "graphiques.h"
#include <math.h>

int
main()
{
    gr_init(512, 384);
    
    for (int i = 0; i < 800; i++)
    {
        gr_draw_point(x, 200*cos((x * M_PI * 2) / 800), 0,0,0);
    }
    

    gr_display();
    return 0;
}
