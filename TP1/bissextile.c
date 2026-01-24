#include <stdio.h>
#include <stdbool.h>
// divisble par 4 mais pas par 100 OU divisible par 400

int main(void) {

    unsigned year;
    scanf("%u", &year);

    bool isBissextile = false;
    if(year % 4 == 0 && year % 100 != 0) isBissextile = true;
    else if(year % 400 == 0) isBissextile = true;

    puts(isBissextile ? "Votre année est bissextile" : "Votre année est ordinaire");

    return 0;
}