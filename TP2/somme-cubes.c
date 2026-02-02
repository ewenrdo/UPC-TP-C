#include <stdio.h>

unsigned unsigned_pow(int m, int n);  // prototype

int main(void)
{
    unsigned n;
    scanf("%u", &n);

    unsigned cube_sum = 0;
    for (unsigned i = 1; i <= n; i++)
    {
        cube_sum += unsigned_pow(i,3);
    }
    printf("%u", cube_sum);
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
