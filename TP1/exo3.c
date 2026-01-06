#include <stdio.h>

// Déclaration
#define N 8;
int getFlightTimeForSyracuseN(unsigned int);
int main(void);

// Implémentation
int main(void)
{
    unsigned int u_0 = N;

    for (unsigned i = 1; i <= u_0; i++)
    {
        printf("%u : %u\n",i,getFlightTimeForSyracuseN(i));
    }
    

    return 0;
}

int getFlightTimeForSyracuseN(unsigned int n)
{
    unsigned int v_n = n;
    unsigned int flight_time = 0;

    while (v_n != 1)
    {
        if (v_n % 2 == 0)
        {
            v_n = v_n / 2;
        }
        else
        {
            v_n = 3 * v_n + 1;
        }

        flight_time++;
    }

    return flight_time;

}