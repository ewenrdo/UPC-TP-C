#include <stdio.h>

unsigned syracuse(int m);

int main(void) {

    int k;
    if (scanf("%d", &k) != 1 || k < 1)
    {
        printf("Entrée invalide\n");
        return 1;
    }

    unsigned n_max = 1;
    unsigned syr_n_max = syracuse(1);

    for (unsigned i = 2; i <= (unsigned)k; i++)
    {
        unsigned currentSyr = syracuse(i);
        if (currentSyr > syr_n_max)
        {
            syr_n_max = currentSyr;
            n_max = i;
        }
    }

    printf("n avec temps de vol maximal = %u (temps de vol = %u)\n", n_max, syr_n_max);
    return 0;
}

// unsafe sur les int
unsigned syracuse(int m)
{
    int res = m;
    unsigned flight_time = 0;

    while (res != 1)
    {
        flight_time++;
        if (res % 2 == 0)
        {
            res = res / 2;
        }
        else
        {
            res = 3 * res + 1;
        }
    }

    return flight_time;
}