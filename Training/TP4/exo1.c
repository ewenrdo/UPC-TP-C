#include <stdio.h>

void swap(int *p, int *q)
{
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

int main(void)
{
    // Question 1
    int x, y;
    x = 5;
    y = 6;
    printf("(avant) x: %d, y: %d\n", x, y);
    swap(&x, &y);
    printf("(après) x: %d, y: %d\n", x, y);

    // Question 2
    int t[3] = {1, 2, 3};

    printf("(avant) t[0]: %d, t[2]: %d\n", t[0], t[1]);
    swap(&t[0], &t[2]);
    printf("(après) t[0]: %d, t[2]: %d\n", t[0], t[2]);
}