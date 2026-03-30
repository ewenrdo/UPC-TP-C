#include <stdio.h>
#include <stdlib.h>

struct node
{
    int v;
    struct node *left;
    struct node *right;
};
void free_tree(struct node *n);

struct node *mknode(int x, struct node *left, struct node *right)
{
    struct node *res = malloc(sizeof(struct node));
    if (res == NULL)
    {
        return NULL;
    }

    res->v = x;
    res->left = left;
    res->right = right;
    return res;
}

struct node *perfect_tree(int h)
{
    if (h == 0)
        return NULL;
    struct node *node = mknode(1, NULL, NULL);
    if (node == NULL)
    {
        return NULL;
    }

    if (h == 1)
    {
        return node;
    }

    struct node *gauche = perfect_tree(h - 1);
    if (gauche == NULL)
    {
        free(node);

        return NULL;
    }
    struct node *droite = perfect_tree(h - 1);
    if (droite == NULL)
    {
        free(node);
        free_tree(gauche);
        return NULL;
    }
    node->left = gauche;
    node->right = droite;

    return node;
}

void print_infix(struct node *node)
{
    if (node == NULL)
        return;

    print_infix(node->left);
    printf("%d", node->v);
    print_infix(node->right);
}

void free_tree(struct node *n)
{

    if (n == NULL)
        return;
    free_tree(n->left);
    free_tree(n->right);
    free(n);
}

// ------------------------------- //
//       Début de l'EXO 2          //
// ------------------------------- //

int find(int i, struct node *abr)
{
    struct node *next = abr;
    while (next != NULL)
    {
        if (next->v == i)
            return 1;
        else if (next->v < i)
            next = next->right;
        else
            next = next->left;
    }
    return 0;
}

struct node *insert(int i, struct node *abr)
{
    if (abr == NULL)
    {
        struct node *newNode = mknode(i, NULL, NULL);
        if (newNode == NULL)
            return NULL;
        return newNode;
    }
    if (abr->v < i)
    {
        if (abr->right == NULL)
        {
            struct node *newNode = mknode(i, NULL, NULL);
            if (newNode == NULL)
                return NULL;
            abr->right = newNode;
        }
        else
        {
            if (insert(i, abr->right) == NULL)
                return NULL;
        }
    }
    else // abr->v >= i
    {    // convention : si c'est =, on fait comme si ça doit aller à gauche.
        if (abr->left == NULL)
        {
            struct node *newNode = mknode(i, NULL, NULL);
            if (newNode == NULL)
                return NULL;
            abr->left = newNode;
        }
        else
        {
            if (insert(i, abr->left) == NULL)
                return NULL;
        }
    }

    return abr; // la racine n'est jamais changée
}

int main(void)
{
    struct node *abr = NULL;

    while (1)
    {
        int tmp;
        printf("> ");
        scanf("%d", &tmp);
        struct node* tmp_abr = insert(tmp, abr);
        if (tmp_abr == NULL)
        {
            free_tree(abr);
            return 1;
        }
        abr = tmp_abr;

        printf("Parcours infixe : ");
        print_infix(abr);
        printf("\n");
    }

    free_tree(abr);
}