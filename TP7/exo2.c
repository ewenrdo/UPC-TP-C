#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// bribes de l'exo1
struct slice
{
    int *a;
    int len; // nombre d'éléments du slice
    int cap; // taille de l'allocation du champ 'a' en unités de la taille d'un élément
};
typedef struct slice Slice;
int extend(Slice *s);
Slice *new_slice(int cap)
{
    Slice *res = malloc(sizeof(Slice));
    if (res == NULL)
        return NULL;

    res->len = 0;
    res->cap = cap;

    res->a = malloc(cap * sizeof(int));
    if (res->a == NULL)
    {
        free(res);
        return NULL;
    }

    return res;
}

void destroy_slice(Slice *s)
{
    free(s->a);
    free(s);
}

int snoc(Slice *s, int v)
{
    if (s->len == s->cap && extend(s) == -1)
    {
        return -1;
    }

    *(s->a + s->len) = v;
    s->len = s->len + 1;
    return 1;
}

Slice *read_slice()
{
    Slice *res = new_slice(10);
    bool pos = true;
    while (pos)
    {
        int tmp;
        scanf("%d", &tmp);
        if (tmp >= 0)
        {
            if (snoc(res, tmp) == -1)
            {
                destroy_slice(res);
                return NULL;
            }
        }
        else
        {
            pos = false;
        }
    }

    return res;
}

int extend(struct slice *s)
{
    int n = (s->cap > 0) ? 2 * (s->cap) : 4;

    // Crée le tableau de taille n
    int *tab = malloc(n * sizeof(int));
    if (tab == NULL)
    {
        return -1;
    }

    // Copie les valeurs du slice
    for (size_t i = 0; i < s->len; i++)
    {
        tab[i] = *(s->a + i);
    }

    free(s->a);
    s->a = tab;
    s->cap = n;

    return 1;
}

// exercice 2
int empty(Slice *s);
int push(Slice *s, int v); // renvoie 1 si succès, -1 sinon.
int pop(Slice *s);         // appelle abort si appelé sur une pile vide

int empty(Slice *s)
{
    return s->len == 0;
}

int pop(Slice *s)
{
    if (empty(s))
        abort();

    int tmp = s->a[s->len - 1];

    s->len = s->len - 1;
    return tmp; // on regarde à l'élément on a supprimé
}

int push(Slice *s, int v)
{
    return snoc(s, v);
}

int main()
{
    Slice *stack = new_slice(4);
    if (!stack)
    {
        puts("Erreur allocation pile");
        return 1;
    }

    while (true)
    {
        int tmp = getchar();

        if (tmp >= '0' && tmp <= '9')
        {
            // c'est un chiffre, on empile sa valeur
            int valeur = tmp - '0';
            if (push(stack, valeur) == -1)
            {
                puts("Erreur allocation lors du push");
                destroy_slice(stack);
                return 1;
            }
        }
        else if (tmp == '.')
        {
            if (empty(stack))
            {
                puts("La pile est vide.");
            }
            else
            {
                int elt = pop(stack);
                printf("(unstacked) %d\n", elt);
            }
        }
        else if (tmp == ' ' || tmp == '\n')
        {
            // ne rien faire
        }
        else if (tmp == 'q')
        {
            destroy_slice(stack);
            break;
        }
        else if (tmp == '+')
        {
            if (stack->len < 2)
            {
                puts("Erreur : pas assez d'opérandes pour '+'");
                continue;
            }
            int val2 = pop(stack);
            int val1 = pop(stack);
            push(stack, val1 + val2);
        }
        else if (tmp == '-')
        {
            if (stack->len < 2)
            {
                puts("Erreur : pas assez d'opérandes pour '-'");
                continue;
            }
            int val2 = pop(stack);
            int val1 = pop(stack);
            push(stack, val1 - val2);
        }
        else if (tmp == '*')
        {
            if (stack->len < 2)
            {
                puts("Erreur : pas assez d'opérandes pour '*'");
                continue;
            }
            int val2 = pop(stack);
            int val1 = pop(stack);

            push(stack, val1 * val2);
        }
        else if (tmp == '/')
        {
            if (stack->len < 2)
            {
                puts("Erreur : pas assez d'opérandes pour '/'");
                continue;
            }
            int val2 = pop(stack);
            int val1 = pop(stack);
            if (val2 == 0)
            {
                puts("Erreur : on ne peut pas diviser par zéro");
                continue;
            }else {
            push(stack, val1 / val2);}
        }
        else
        {
            puts("Undefined control sequence");
        }
    }
}