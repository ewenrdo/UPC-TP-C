#include <stdio.h>

// Déclarations
signed long long f(signed long long);
signed long long g(signed long long);

// Implémentation

signed long long f(signed long long n)
{
    if (n == 1)
        return 2;
    else
    {
        return 2 * g(n - 1);
    }
}

signed long long g(signed long long n)
{
    if (n == 1)
        return 1;
    else
    {
        return 3 * f(n / 2);
    }
}

int main(void) {
    printf("f(%lld) = %lld", 20, f(20));
}
