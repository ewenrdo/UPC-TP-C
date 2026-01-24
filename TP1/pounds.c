#include <stdio.h>

struct moneybag
{
    unsigned pounds;
    unsigned shillings;
    unsigned pence;
};
typedef struct moneybag MoneyBag;
void printMoneyBag(MoneyBag moneybag);

/*
ancien système : 1 £ = 20s (shilling s)
1 sol = 12d (pence)
1 d (pence) = 4 f (farthings)
1 gn (guinea) = 1£ + 1s
*/

int poundsToShilling(int pounds)
{
    return 20 * pounds;
}
int shillingToPence(int shilling)
{
    return 12 * shilling;
}
int penceToFarthings(int pence)
{
    return 4 * pence;
}


int main(void)
{
    // Question 1
    MoneyBag argent1, argent2, finalBag;

    printf("Pounds: ");
    scanf("%u", &argent1.pounds);
    printf("Shillings: ");
    scanf("%u", &argent1.shillings);
    printf("Pence: ");
    scanf("%u", &argent1.pence);

    printf("Pounds: ");
    scanf("%u", &argent2.pounds);
    printf("Shillings: ");
    scanf("%u", &argent2.shillings);
    printf("Pence: ");
    scanf("%u", &argent2.pence);
    
    // On fait l'addition...
    finalBag.pounds = argent1.pounds + argent2.pounds;
    finalBag.shillings = argent1.shillings + argent2.shillings;
    finalBag.pence = argent1.pence + argent2.pence;

    // Maintenant, on doit traiter...
    // Contraintes :
    // Max 11 pence et 19 shillings

    finalBag.shillings += finalBag.pence / 12;
    finalBag.pence %= 12;
    
    finalBag.pounds += finalBag.shillings / 20;
    finalBag.shillings %= 20;

    printMoneyBag(finalBag);
}

void printMoneyBag(MoneyBag moneybag) {
    printf("%u pounds %u shillings %u pence", moneybag.pounds, moneybag.shillings, moneybag.pence);
}

