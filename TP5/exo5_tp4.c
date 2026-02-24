#include <stdio.h>
#include <math.h>

double e(int n) {
    return pow((1.0+1.0/n),n);
}

int main(void) {
    for (int i = 1; i < 101; i++)
    {
        printf("An %d : %f zl\n",i,e(i));
    }
    
    // On a clairement la convergence (plutôt rapide) vers e
}