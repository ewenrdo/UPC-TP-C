#include <gtk/gtk.h>
#include "graphiques.h"

int main()
{
    gr_init(512, 384);
    // Question 1
    for (int i = 0; i <= 100; i++)
    {
        gr_draw_point(100, 100+i, 0, 0, 0);
    }

    // Question 2
    for (int i = 0; i <= 100; i++)
    {
        gr_draw_point(100+i, 100, 255, 0, 0);
    }

    // Question 3
    for (int i = 0; i <= 100; i++)
    {
        gr_draw_point(100+i, 200+i, 0, 255, 0);
    }

    // Question 4
    for (int i = 0; i <= 100; i++)
    {
        gr_draw_point(200-i, 100+i, 235, 52, 222);
    }

    // Question 5
    int depart_x = 100;
    for (int i = 0; i < 200 ; i++) // largeur
    {
        int depart_y = 100;
        for (int j = 0; j < 150; j++) // hauteur
        {
            gr_draw_point(depart_x, depart_y, 230, 34, 83);
            depart_y++;
        }
        depart_x++;
        
    }

    // Question 

    gr_display();
    return 0;
}
