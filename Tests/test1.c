#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[16];
    int i = 0;

    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    if (out == NULL)
    {
        fclose(in);
        return 1;
    }

    while (1)
    {
        int c = getc(in);
        if (c == EOF)
            break;

        if (c == ';')
        {
            buffer[i] = '\0';
        
            int score = 0;
            sscanf(buffer, "%d", &score);
            printf("Score : %d\n", score);
            if (score >= 80)
            {
                fprintf(out, "Victoire avec %d points !\n", score);
                fclose(in);
                fclose(out);
                return 0;
            }
            i = 0;
        }
        else
        {
            buffer[i] = (char)c;
            i++;
        }
    }
    

    printf("%s\n", buffer);
    fprintf(out, "Défaite...\n");
    fclose(in);
    fclose(out);

    return 0;
}