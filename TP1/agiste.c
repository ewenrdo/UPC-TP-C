#include <stdio.h>

int main(void)
{
    int birthyear;
    printf("Entrez votre année de naissance :\n>>> ");
    scanf("%d", &birthyear);
    
    printf("Age atteint cette année : %d", 2026 - birthyear);
}