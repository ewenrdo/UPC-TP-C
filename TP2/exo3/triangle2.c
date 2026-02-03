#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    // Print row
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < n - i)
                printf(" ");
            else
                printf("*");
        }
        printf("\n");
    }
}
