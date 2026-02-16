#include <stdio.h>

struct fract {
    long long int num, den;
};

typedef struct fract Fraction;

void print(Fraction x) {
    printf("%lld / %lld", x.num, x.den);
}

int pgcd(long long int a, long long int b) {
    long long int rest = a % b;

    while (rest != 0) {
        a = b;
        b = rest;
        rest = a % b;
    }
    return b;
}

Fraction canonique(Fraction x) {
    int gcd = pgcd(x.num, x.den);
    Fraction res = {x.num/gcd, x.den/gcd};
    
    if(res.den < 0) {
        res.num *= -1;
        res.den *= -1;
    }

    return res;
}

Fraction add(Fraction x, Fraction y) {
    Fraction res;
    res.num = x.num * y.den + y.num * x.den;
    res.den = x.den * y.den;
    return canonique(res);
}

Fraction div(Fraction x, Fraction y) {
    Fraction res;
    res.num = x.num * y.den;
    res.den = x.den * y.num;

    return canonique(res);
}

int main(void){
    printf("%d", pgcd(24,12));
}

