#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char* nom;
    int age;
    char* tel;
};
typedef struct contact Contact;

int main()
{
    char alice[] = "Alice,25,0601020304";
    //char stefan[] = "Stefan,12,0658743620";
    //char ewen[] = "Ewen,20,0656753983";

    // Cas 1
    char* nom = malloc(sizeof(char) * 640);
    int age = -1;
    char* tel = malloc(sizeof(char) * 100);
    sscanf(alice, "%[^,],%d,%s", nom, &age, tel);

    Contact* aliceCard = malloc(sizeof(Contact));
    aliceCard->nom = nom;
    aliceCard->tel = tel;
    aliceCard->age = age;

    char* buf = malloc(sizeof(char) * 100);
    snprintf(buf, 100 * sizeof(char), "[%s] - %d ans (Tel: %s)", aliceCard->nom, aliceCard->age, aliceCard->tel);
    printf("%s\n", buf);
    
    free(nom);
    free(tel);
    free(aliceCard);
    free(buf);
    return 0;
    
}