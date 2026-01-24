#include <stdio.h>

// Implémentation
int main(void)
{
    unsigned currentHour;
    unsigned currentMinutes;
    unsigned endHour;
    unsigned endMinutes;

    puts("HEURE puis MINUTES de fin de TP");
    printf(">>> ");
    scanf("%u", &endHour);
    printf(">>> ");
    scanf("%u", &endMinutes);

    puts("HEURE puis MINUTES actuelle");
    printf(">>> ");
    scanf("%u", &currentHour);
    printf(">>> ");
    scanf("%u", &currentMinutes);

    puts("==================");
    unsigned endMn = endHour * 60 + endMinutes;
    unsigned currentMn = currentHour * 60 + currentMinutes;

    unsigned minutesTillEnd = endMn - currentMn > 0 ? endMn - currentMn : 0; 

    printf("Minutes restantes : %u", minutesTillEnd);
}