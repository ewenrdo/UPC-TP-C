#include <stdio.h>
#define N 100

struct polynome
{
    int degre;
    int coefs[N]; // coefs[0] + coefs[1] * X + ... + coefs[N]*X^N
};
typedef struct polynome Polynome;

// Déclaration

int eval(Polynome p, int X)
{
    int res = 0;
    int X_power = 1; // X^0

    for (int i = 0; i <= p.degre; i++)
    {
        res += p.coefs[i] * X_power;
        X_power *= X;
    }

    return res;
}

void print_poly(Polynome p)
{
    int first = 1; // savoir si on doit mettre " + "
    for (int i = p.degre; i >= 0; i--)
    {
        int c = p.coefs[i];
        if (c != 0)
        {
            if (!first)
            {
                printf(" + ");
            }
            first = 0;

            if (i == 0)
            {
                printf("%d", c);
            }
            else if (i == 1)
            {
                printf("%dX", c);
            }
            else
            {
                printf("%dX^%d", c, i);
            }
        }
    }
    printf("\n");
}

Polynome derive(Polynome p)
{
    Polynome p_der = p;

    if (p.degre == 0)
    {
        Polynome nul;
        nul.degre = 0;
        nul.coefs[0] = 0;
    }

    for (size_t i = 1; i <= p_der.degre; i++)
    {
        p_der.coefs[i - 1] = i * p_der.coefs[i];
    }
    p_der.degre--;

    return p_der;
}

Polynome add(Polynome p1, Polynome p2)
{
    int p_deg = (p1.degre >= p2.degre ? p1.degre : p2.degre);
    int coefs[N];

    Polynome p_res;
    p_res.degre = p_deg;

    for (size_t i = 0; i <= p_deg; i++)
    {
        p_res.coefs[i] = (i > p1.degre ? 0 : p1.coefs[i]) + (i > p2.degre ? 0 : p2.coefs[i]);
    }

    return p_res;
}

// Implémentation

int main(void)
{
    Polynome p;
    p.degre = 3;
    p.coefs[0] = 1;
    p.coefs[1] = 4;
    p.coefs[2] = 0;
    p.coefs[3] = 3;

    printf("%d\n", eval(p, -1));
    print_poly(p);

    Polynome der = derive(p);
    print_poly(der);
}
