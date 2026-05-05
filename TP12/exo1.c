#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct menu_entry
{
    char ch;           // touche que l'utilisateur a entrée
    void (*f)(void *); // fonction invquée par le menu
    void *closure;     // paramètre de cette fonction
};

void quit_program(void *notused)
{
    exit(0);
}

void x_cmd(void *notused) {
    printf("Vous avez appuyé sur la lettre x.\n");
}

void number_cmd(void *number) {
    printf("Vous avez appuyé sur le chiffre %s.\n", (char*) number);
}

const struct menu_entry menu_entries[] = {
    {'q', quit_program, NULL},
    {'1', number_cmd, "un"},
    {'2', number_cmd, "deux"},
    {'3', number_cmd, "trois"},
    {'4', number_cmd, "quatre"},
    {'5', number_cmd, "cinq"},
    {'6', number_cmd, "six"},
    {'7', number_cmd, "sept"},
    {'8', number_cmd, "huit"},
    {'9', number_cmd, "neuf"},
};

const int num_menu_entries = sizeof(menu_entries) / sizeof(menu_entries[0]);

int main()
{
    while (true)
    {
        int currentChar;
        currentChar = getc(stdin);
        if (currentChar == EOF)
        {
            printf("Error : End of file reached.");
            return 0;
        }
        char c = (char)currentChar;
        if (c == '\n' || c == ' ')
            continue;

        bool found = false;
        for (size_t i = 0; i < num_menu_entries; i++)
        {
            if (c == menu_entries[i].ch)
            {
                menu_entries[i].f(menu_entries[i].closure);
                found = true;
                break;
            }
        }
        if (!found)
            printf("Error : Unknown character '%c'.\n", c);
    }
    return 0;
}