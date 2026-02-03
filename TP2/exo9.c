#include <stdio.h>

int chiffres(int n);

int chiffres(int n) {
    if(n >= -9 && n <= 9) return 1;
    return 1 + chiffres(n/10);
}

int main(void) {
    printf("Chiffres de 1 %d\n", chiffres(1));
    printf("Chiffres de 13 %d\n", chiffres(13));
    printf("Chiffres de 0 %d\n", chiffres(0));
    printf("Chiffres de 667 %d\n", chiffres(667));
}