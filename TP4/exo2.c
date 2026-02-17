#include <stdio.h>
#include<assert.h>
#define N_MAX 100

int max(int *a, int n)
{
    int max = a[0];
    for (size_t i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

int max_pos(int *a, int n)
{
    int max = a[0];
    int max_i = 0;
    for (size_t i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            max_i = i;
        }
    }
    return max_i;
}

int main(void)
{
    int n = 0;

    scanf("%d", &n);
    assert(n <= N_MAX && n >= 0);

    int T[N_MAX];

    for (size_t i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);
        T[i] = value;
    }

    printf("%d", max(T, n));
}