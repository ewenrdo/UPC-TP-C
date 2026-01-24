#include <stdio.h>

int main(void)
{

    int first_number;
    int second_number;

    printf(">>> ");
    scanf("%d", &first_number);

    printf(">>> ");
    scanf("%d", &second_number);

    printf("Nombre maximum : %d.\n", (first_number > second_number ? first_number : second_number));
    printf("Nombre minimum : %d.\n", (first_number > second_number ? second_number : first_number));

    return 0;
}