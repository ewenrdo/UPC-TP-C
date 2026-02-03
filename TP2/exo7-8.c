#include <stdio.h>
int max(int x, int y);
int max3(int x, int y, int z);

int main(void)
{
    //printf("%d\n", max(-2, 3));
    //printf("%d\n", max3(-2, 7, 3));

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        if(premier(i) == 1) printf("%d\n", i);
    }
    
}

int max(int x, int y) {
    return x > y ? x : y;
}

int max3(int x, int y, int z) {
    return max(x,y) > z ? max(x,y) : z;
}

int premier(int n) {
    if(n <= 1) return 0;
    for (int i = 2; i < n; i++)
    {
        if(n % i == 0) return 0;
    }
    return 1;
}