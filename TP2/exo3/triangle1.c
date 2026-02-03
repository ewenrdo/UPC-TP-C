#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    // Print row
    for (int i = 0; i <= n; i++)
        // Build line
        for (int j = 0; j < i; j++) {
            printf(j == i -1 ? "*\n" : "*");
        }
}
