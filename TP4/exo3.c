#include <stdio.h>
#include <assert.h>
#define N_MAX 200
int prime(int n)
{
    if (n <= 1)
    {
        return 0;
    }
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void fillArray(int *a, int n)
{
    for (size_t i = 0; i <= n; i++)
    {
        a[i] = 1;
    }
}

int main(void)
{
    int sup;
    scanf("%d", &sup);

    assert(sup >= 0 && sup <= N_MAX);
    int T[N_MAX+1];
    fillArray(T, sup);

    for (size_t i = 2; i <= sup; i++)
    {
        if (T[i] == 1) {
            for (size_t j = 2*i; j <= sup; j+=i)
            {
                T[j] = 0;
            }
            
        }
    }

}

/*
int main(void) {
    int sup;
    scanf("%d", &sup);

    int amount=0;
    for (size_t i = 2; i < sup; i++)
    {
        if(prime(i)) ++amount;
    }

    printf("Entre %d et %d il y a %d nombres premiers", 0, sup, amount);

}*/