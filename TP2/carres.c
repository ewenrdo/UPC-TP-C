#include <stdio.h>

unsigned unsigned_pow(int m, int n);  // prototype

int main(void)
{
    for (unsigned i = 1; i <= 10; i++)
    {
        printf("%u\n", unsigned_pow(i, 2));
    }
}

unsigned unsigned_pow(int m, int n)
{
    if (n == 0)
        return 1;

    unsigned tmp = unsigned_pow(m, n / 2);
    tmp = tmp * tmp;

    if (n % 2 == 0)
        return tmp;
    else
        return m * tmp;
}
