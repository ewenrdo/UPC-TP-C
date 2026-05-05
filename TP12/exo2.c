#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define PI 3.14159265358979323846
// Question 1 : Le polymorphisme apparait dans la méthode totalSurface, car elle considère tous les Retangle et Circle comme des Figure (elles ont donc deux types).

struct figure;
struct figure_trait
{
    double (*surface)(struct figure *o);
};
struct figure
{
    void *fields;               // champs de l'objet
    struct figure_trait *trait; // méthodes de l'objet
};

// Rectangle
double rectangle_surface(struct figure *o);
struct rectangle_fields
{
    double x, y, width, height;
};
struct figure_trait rectangle_trait = {
    rectangle_surface,
};

double rectangle_surface(struct figure *o)
{
    struct rectangle_fields *fields = o->fields;
    return fields->height * fields->width;
}

struct figure *new_rectangle(double x, double y, double width, double height)
{
    struct rectangle_fields *fields = malloc(sizeof(struct rectangle_fields));
    if (fields == NULL)
    {
        return NULL;
    }

    fields->height = height;
    fields->width = width;
    fields->x = x;
    fields->y = y;

    struct figure *res = malloc(sizeof(struct figure));
    if (res == NULL)
    {
        free(fields);
        return NULL;
    }

    res->fields = (void *)fields;
    res->trait = &rectangle_trait;
    return res;
}

// Circle
double circle_surface(struct figure *o);
struct circle_fields
{
    double x, y, radius;
};
struct figure_trait circle_trait = {
    circle_surface,
};

double circle_surface(struct figure *o)
{
    struct circle_fields *fields = o->fields;
    return PI * fields->radius * fields->radius;
}

struct figure *new_circle(double x, double y, double radius)
{
    struct circle_fields *fields = malloc(sizeof(struct circle_fields));
    if (fields == NULL)
    {
        return NULL;
    }

    fields->radius = radius;
    fields->x = x;
    fields->y = y;

    struct figure *res = malloc(sizeof(struct figure));
    if (res == NULL)
    {
        free(fields);
        return NULL;
    }

    res->fields = (void *)fields;
    res->trait = &circle_trait;
    return res;
}

// Surface

double total_surface(struct figure **fs, size_t size)
{
    double res = 0;
    for (size_t i = 0; i < size; i++)
    {
        res += fs[i]->trait->surface(fs[i]);
    }
    return res;
}

void free_figure(struct figure *f) {
    if(f == NULL) return;
    free(f->fields);
    free(f);
}

int main()
{
    struct figure *fs[3];
    fs[0] = new_rectangle(0, 0, 100, 100);
    fs[1] = new_rectangle(10, 10, 120, 120);
    fs[2] = new_circle(10, 10, 100);
    printf("%lf\n", total_surface(fs, 3));

    for (size_t i = 0; i < 3; i++)
    {
        free_figure(fs[i]);
    }
    
    return 0;
}