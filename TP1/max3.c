#include <stdio.h>
#include <limits.h>

// Implémentation

int main(void) {
    int max = INT_MIN;
    for (size_t i = 0; i < 3; i++)
    {
        int tmp;
        printf(">>> ");
        scanf("%d", &tmp);
        if(tmp > max) max = tmp;
    }

    printf("L'entier le plus grand que vous ayez entré est : %d", max);

}