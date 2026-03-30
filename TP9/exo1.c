#include <stdio.h>
#include <stdlib.h>

struct node
{
    int v;
    struct node *left;
    struct node *right;
};
void free_tree(struct node *t);
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

void free_tree(struct node *n) {

    if(n == NULL) return;
    free_tree(n->left);
    free_tree(n->right);
    free(n);
}