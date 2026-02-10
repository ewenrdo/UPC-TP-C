/* Written by Juliusz Chroboczek. */

#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <complex.h>
#include <unistd.h>
#include <gtk/gtk.h>

static GtkWidget* window = NULL;
static GtkWidget* canvas = NULL;
static cairo_surface_t *surface = NULL;

gboolean
draw_callback(GtkWidget *widget, cairo_t *cr, gpointer data)
{
    cairo_set_source_surface(cr, surface, 0, 0);
    cairo_paint(cr);
    return FALSE;
}

gboolean
configure_callback(GtkWidget *widget, cairo_t *cr, gpointer data)
{
    cairo_surface_t *new_surface;

    new_surface =
        gdk_window_create_similar_surface(
            gtk_widget_get_window(widget),
            CAIRO_CONTENT_COLOR,
            gtk_widget_get_allocated_width(widget),
            gtk_widget_get_allocated_height(widget));
    cr = cairo_create(new_surface);
    cairo_set_source_rgb(cr, 1, 1, 1);
    cairo_paint(cr);
    if(surface) {
        cairo_set_source_surface(cr, surface, 0, 0);
        cairo_paint(cr);
        cairo_surface_destroy(surface);
    }
    cairo_destroy(cr);
    surface = new_surface;

    return TRUE;
}

int
gr_init(int width, int height)
{
    gtk_init(0, NULL);

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), width, height);

    canvas = gtk_drawing_area_new();
    gtk_container_add(GTK_CONTAINER(window), canvas);

    g_signal_connect(window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    g_signal_connect(canvas, "draw", G_CALLBACK(draw_callback), NULL);
    g_signal_connect(canvas,"configure-event",
                     G_CALLBACK(configure_callback), NULL);
    gtk_widget_show_all(window);
    return 1;
}

int
gr_draw_point(int x, int y, int r, int g, int b)
{
    cairo_t *cr;

    cr = cairo_create(surface);
    cairo_set_source_rgb(cr, r / 255.0, g / 255.0, b / 255.0);
    cairo_rectangle(cr, (double)x, (double)y, 1.0, 1.0);
    cairo_fill(cr);
    cairo_destroy(cr);
    return 1;
}

int
gr_display()
{
    gtk_main();
    return 1;
}
