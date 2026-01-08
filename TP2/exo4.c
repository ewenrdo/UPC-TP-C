#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
typedef struct fraction Fraction;

// Déclaration
struct fraction
{
    long int num;
    long int den;
};

Fraction build(long int n, long int d);
bool eq_fraction(Fraction f, Fraction g);
bool is_int(Fraction f);
Fraction sum(Fraction f, Fraction g);
Fraction sub(Fraction f, Fraction g);
Fraction mul(Fraction f, Fraction g);
Fraction reduce(Fraction f);
long pgcd(long a, long b);
char* fractionToString(Fraction f); // HS

// Implémentation

Fraction build(long int n, long int d)
{
    assert(d != 0); // équivalent de throw, si la condition n'est pas respectée

    Fraction frac = {n, d};
    return frac;
}

bool eq_fraction(Fraction f, Fraction g)
{
    return (f.num * g.den == g.num * f.den); // deux fractions sont égales si ad=bc
}

bool is_int(Fraction f)
{
    return (f.num % f.den == 0);
}

Fraction sum(Fraction f, Fraction g)
{
    // On ne fera pas de processus de simplification
    long int num = f.num * g.den + f.den * g.num;
    long int den = f.den * g.den;

    Fraction result = {num, den};
    return result;
}

Fraction sub(Fraction f, Fraction g)
{
    // On ne fera pas de processus de simplification
    long int num = f.num * g.den - f.den * g.num;
    long int den = f.den * g.den;

    Fraction result = {num, den};
    return result;
}

Fraction mul(Fraction f, Fraction g)
{
    // On ne fera pas de processus de simplification
    long int num = f.num * g.num;
    long int den = f.den * g.den;

    Fraction result = {num, den};
    return result;
}

long pgcd(long a, long b)
{
    long x = a;
    long y = b;
    long r = 0;
    while (y != 0)
    {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

Fraction reduce(Fraction f)
{
    // Une fraction est réductible si pgcd(num, den) != 0.
    long int num = f.num;
    long int den = f.den;
    long gcd;
    gcd = pgcd(num, den);

    assert(gcd != 0);

    num = num / gcd;
    den = den / gcd;

    if (num < 0 && den < 0)
    {
        num *= -1;
        den *= -1;
    }
    else if (num > 0 && den < 0)
    {
        num *= -1;
        den *= -1;
    }

    Fraction res = {num, den};
    return res;
}

int main(void)
{
    Fraction ex_fractions[] = {
        build(1, 1),
        build(1, 2),
        build(2, 4),
        build(-9, 3),
        build(8, -20),
        build(-5, -1),
        build(1, -3),
    };

    for (size_t i = 0; i < 7; i++)
    {
        for (size_t j = 0; j < 7; j++)
        {
            printf("%s + %s = %s\n", fractionToString(ex_fractions[i]), fractionToString(ex_fractions[j]), fractionToString(sum(ex_fractions[i],ex_fractions[j])));
            printf("%s - %s = %s\n", fractionToString(ex_fractions[i]), fractionToString(ex_fractions[j]), fractionToString(sub(ex_fractions[i],ex_fractions[j])));
            printf("%s * %s = %s\n", fractionToString(ex_fractions[i]), fractionToString(ex_fractions[j]), fractionToString(mul(ex_fractions[i],ex_fractions[j])));
        }
        
    };
    

    
}


// Généré par IA (hors sujet)
char* fractionToString(Fraction f) {

    f = reduce(f);

    // + extra pour signe, '/' et '\0'
    char* buffer = malloc(32);
    if (!buffer) return NULL; // allocation failed
    snprintf(buffer, 32, "%ld/%ld", f.num, f.den);
    return buffer;
}