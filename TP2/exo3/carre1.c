#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    // Print row
    for (int i = 0; i < n; i++)
        // Build line
        for (int j = 0; j < n; j++)
        {
            printf("*");
            if (j == n - 1)
                printf("\n");
        }
}