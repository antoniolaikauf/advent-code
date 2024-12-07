#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define length 250

void rimozione_elemento(int element, int arr[])
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == element)
            arr[i] = 0;
    }
}

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
                printf("%d\n", calories);
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
                // printf("%d\n", max);
            }
        }

        printf("attuale: %d\n", max);


        //-----------------------------------------------------------------
        //seconda parte
        //-----------------------------------------------------------------


        int top_three[3];
        int index_top_three = 0;
        while (index_top_three < 3)
        {
            int max_top_three = 0;
            for (int i = 0; i < length; i++)
            {
                if (max_top_three < calories_elf[i])
                {
                    max_top_three = calories_elf[i];
                    top_three[index_top_three] = max_top_three;
                }
            }
            // trasformo elemento massimo in 0 in calories
            rimozione_elemento(max_top_three, calories_elf);
            index_top_three++;
        }
        // somma top 3 caloria
        int sum = 0;
        for (int i = 0; i < 3; i++)
        {
            printf("%d\n", top_three[i]);
            sum += top_three[i];
        }
        printf("%d\n", sum);
    }

    return 0;
}