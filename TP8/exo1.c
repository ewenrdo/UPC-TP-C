#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int palindrome(const char *s);

int main(void)
{
    char *string = malloc(101 * sizeof(char));
    if (string == NULL) return 1;

    scanf("%100s", string);
    if(strlen(string) > 100) {
        puts("ERREUR : String plus long que 100");
        free(string);
        return 1;
    }
    printf("'%s' est un palindrome ? --> %d\n", string, palindrome(string));
    free(string);
}

// Ne fonctionne pas pour comparer é et e, mais ok pour é et é. (eg. été = true, éte = false)
int palindrome(const char *s)
{
    size_t length = strlen(s);

    for (size_t i = 0; i < length; i++)
    {
        if (s[i] != s[length - i - 1])
            return 0;
    }

    return 1;
}