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
        int calories = 0;
        int number;
        int indice = 0;
        int length = 250;
        int calories_elf[length];
        char buffer[100];
        // buffer è dove verra salvata la linea del file e legge fino a 100 caratteri 
        while (fgets(buffer, sizeof(buffer), file)) // legge ogni riga fino a 100 caratteri 
        {
            if (sscanf(buffer, "%d", &number) == 1) // check number 
            {
                calories += number;
            }
            else
            {
                calories_elf[indice] = calories;
                indice++;
                calories = 0;
            }
        }

        int max = 0;

        for (int i = 0; i < length; i++)
        {
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