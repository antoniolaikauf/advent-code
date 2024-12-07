#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    FILE *file = fopen("input.txt", "r");
    if (file == NULL)
    {
        printf("file non trovato");
        return 0;
    }
    else
    {
        // buffer è dove viene salvato il file
        int calories = 0;
        int number;
        int indice = 0;
        int length = 250;
        int calories_elf[length];
        char buffer[100]; // spazio per leggere la riga del file
        while (fgets(buffer, sizeof(buffer), file))
        {
            // printf("%s", buffer);
            if (sscanf(buffer, "%d", &number) == 1)
            {
                calories += number;
                // printf("Hai inserito: %d\n", number);
            }
            else
            {
                calories_elf[indice] = calories;
                indice++;
                calories = 0;
                // printf("Input non valido: '%s'", buffer);
            }
        }
        int max = 0;
        for (int i = 0; i < length; i++)
        {
            // printf("%d\n", calories_elf[i]);
            if (max < calories_elf[i])
            {
                max = calories_elf[i];
                printf("%d\n", max);
            }
        }

        printf("attuale: %d\n", max);
    }

    return 0;
}