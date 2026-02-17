#include <stdio.h>

double eval(double x, double *a, int n) {
    double x_k = 1;
    double res = 0;

    for (int k = 0; k < n; k++)
    {
        res += a[k] * x_k;
        x_k *= x;
    }
    
    return res;
}

/*
def horner(P, x) :
    res = 0
    for coeff in P[::-1] : # effectue un parcours du tableau à l'envers
        res = res * x + coeff
    return res
*/
double horner(double x, int *a, int n) {
    double res = a[n];
    for (int i = n - 1; i >= 0; i--) {
        res = res * x + a[i];
    }
    return res;
}
