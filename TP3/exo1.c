#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NBC 10

// Déclaration
enum etat
{
    VALIDEE,
    ENCOURS,
    EXPIDEE
};
typedef enum etat Etat;

struct commande
{
    int num_com;
    int prix_exp; // frais de livraison
    int prix_prod;
    Etat etat_com;
};
typedef struct commande Commande;

Commande com_alea(int num);
void affiche_com(Commande c);

void affiche_exp(Commande t[], size_t taille);
int nbr_en_cours(Commande t[], size_t taille);
int cout_validees(Commande t[], size_t taille);

// Implémentation

void affiche_exp(Commande t[], size_t taille)
{
    for (size_t i = 0; i < taille; i++)
    {
        if (t[i].etat_com == EXPIDEE)
        {
            affiche_com(t[i]);
        }
    }
}

int nbr_en_cours(Commande t[], size_t taille)
{
    unsigned int res = 0;
    for (size_t i = 0; i < taille; i++)
    {
        if (t[i].etat_com == ENCOURS)
        {
            res++;
        }
    }
    return res;
}

int cout_validees(Commande t[], size_t taille)
{
    int totalCost = 0;
    for (size_t i = 0; i < taille; i++)
    {
        if (t[i].etat_com == VALIDEE)
        {
            totalCost += t[i].prix_exp;
        }
    }
    return totalCost;
}

void affiche_com(Commande c)
{
    puts("==============================");
    printf("Commande No_%u\n", c.num_com);
    printf("Frais de livraison : %ue\n", c.prix_exp);
    printf("Prix du produit : %ue\n", c.prix_prod);
    puts("");

    printf("Statut de la commande : ");
    switch (c.etat_com)
    {
    case 0:
        printf("RECEIVED");
        break;
    case 1:
        printf("PENDING");
        break;
    case 2:
        printf("SENT");
        break;
    default:
        printf("LOST");
        break;
    }
    puts("\n==============================");
}

Commande com_alea(int num)
{
    int prix_exp = 1 + rand() % 20;
    int prix_prod = 1 + rand() % 2000;
    Etat etat_com = rand() % 3;

    Commande res = {num, prix_exp, prix_prod, etat_com};
    return res;
}

// Tests
/*int main(void)
{

    // Générer la graine
    srand(time(NULL));

    Commande c1;
    c1.etat_com = ENCOURS;
    c1.num_com = 1;
    c1.prix_exp = 0;
    c1.prix_prod = 25;

    Commande c2 = {2, 1, 5, VALIDEE};
    // affiche_com(c1);
    // affiche_com(c2);

    // question 4
    Commande tab[NBC];
    for (size_t i = 0; i < NBC; i++)
    {
        tab[i] = com_alea((int)i);
    }
    affiche_exp(tab, NBC);
    
    printf("Nombre en cours : %d\n", nbr_en_cours(tab, NBC));
    printf("Coût des validées : %d\n", cout_validees(tab, NBC));
}*/

Commande change_prix(Commande c, int newPrice) {
    c.prix_prod = newPrice;
    return c;
}

void expedie_tout(Commande tab[], size_t n) {
    for (size_t i = 0; i < n; i++)
    {
        tab[i].etat_com = EXPIDEE;
    }
    
}

int main(void)
{
    Commande c = {.prix_prod = 100};
    // change_prix(c, 200);
    // On ne peut pas modifier comme cela, il faut une fonction qui renvoie une nouvelle commande
    c = change_prix(c, 200);

    printf("%d\n", c.prix_prod);
}