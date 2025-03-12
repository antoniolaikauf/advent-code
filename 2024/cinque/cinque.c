#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *trimwhitespace(char *str)
{
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str))
        str++;

    if (*str == 0) // All spaces?
        return str;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end))
        end--;

    // Write new null terminator character
    end[1] = '\0';

    return str;
}

// si mettono i caratteri delle coppie 
void costruzioneCoppia(char *coppia, int index, char *buffer)
{
    int IndexNumber = 0;
    for (; IndexNumber < 5; IndexNumber++)
    {
        coppia[IndexNumber] = buffer[index + IndexNumber];
    }
    coppia[IndexNumber] = '\0'; // Termina la stringa
}

int main()
{
    FILE *file = fopen("input.txt", "r");

    if (file == NULL)
        return 0;

    char buffer[500];
    char combinazioni[2000][6] = {0};
    bool changeSolution = false;
    int indexCombination = 0;
    int indexCoppie = 0;
    int output = 0;

    while (fgets(buffer, sizeof(buffer), file))
    {
        trimwhitespace(buffer);

        if (changeSolution)
        {
            int check = 0;
            char coppia[6] = {0}; // Array per salvare le coppie
            printf("combinazione %s\n", buffer);

            for (int i = 0; i < strlen(buffer) - 1; i += 3)
            {
                // creazione coppia 
                costruzioneCoppia(coppia, i, buffer);

                // se coppia diversa da 4 allora non è una coppia 
                if (strlen(coppia) == 4)
                    break;
                
                // ciclo su l'array delle combinazioni per vedere se la coppia è presente 
                for (int indexCheck = 0; indexCheck < indexCombination; indexCheck++)
                {
                    if (strcmp(coppia, combinazioni[indexCheck]) == 0)
                    {
                        check++;
                        printf("sono uguale %s -> %s\n", coppia, combinazioni[indexCheck]);
                        // printf("Coppia generata: %s\n", coppia);
                        printf("buffer %s:                         %i\n", buffer, strcmp(coppia, combinazioni[indexCheck]) == 0);
                    }
                }
            }
            // si controlla se le coppie esistono nelle possibili combinazioni 
            if ((int)(strlen(buffer) / 3) == check)
            {
                char number[3] = {buffer[(strlen(buffer) / 2) - 1], buffer[(strlen(buffer) / 2)], '\0'};
                output += atoi(number);
                printf("%s\n\n", number);
            }
        }
        else
        {
            // si cambia il parametro | con , per rendere il più possibile uguale alla sequenza 
            buffer[2] = ',';
            // copiato la combinazione 
            strcpy(combinazioni[indexCombination], buffer);
            printf("combinazione: %s\n", combinazioni[indexCombination]);
            indexCombination++;
        }
        // si inizia a contollare le sequenze 
        if (buffer[0] == 13)
        {
            
            changeSolution = true;
            printf("ora le combinazioni");
        }
    }

    printf("%i\n", output);
    return 0;
}
