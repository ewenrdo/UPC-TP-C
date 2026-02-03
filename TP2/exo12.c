#include <stdio.h>

long long int fib_r(int n)
{
    if (n <= 1)
        return 1;
    return fib_r(n - 1) + fib_r(n - 2);
}

long long int fib_i(int n)
{
    if(n <= 0) return 0;
    long long int previous = 0;
    long long int last = 1;
    for (unsigned i = 1; i < n; i++)
    {
        long long int tmp = previous;
        previous = last;
        last = tmp + last;
    }
    
    return last;   
}

int main(void) {
    printf("%lld", fib_i(9999));
}