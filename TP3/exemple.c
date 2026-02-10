#include <gtk/gtk.h>
#include "graphiques.h"

int
main()
{
    gr_init(512, 384);
    gr_draw_point(50, 50, 0, 0, 0);
    gr_draw_point(51, 50, 0, 0, 0);
    gr_draw_point(50, 51, 0, 0, 0);
    gr_draw_point(51, 51, 0, 0, 0);
    gr_draw_point(100, 50, 255, 0, 0);
    gr_draw_point(101, 50, 255, 0, 0);
    gr_draw_point(100, 51, 255, 0, 0);
    gr_draw_point(101, 51, 255, 0, 0);
    gr_display();
    return 0;
}
