#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void costruzioneCoppia(char *coppia, int index, char *buffer)
{
    int IndexNumber = 0;
    for (; IndexNumber < 5 ; IndexNumber++)
    {
        coppia[IndexNumber] = buffer[index + IndexNumber];
    }
    coppia[IndexNumber] = '\0'; // Termina la stringa
}

int main()
{
    FILE *file = fopen("small.txt", "r");

    if (file == NULL)
        return 0;

    char buffer[250];
    char combinazioni[250][6] = {0};
    bool changeSolution = false;
    int indexCombination = 0;
    int indexCoppie = 0;

    while (fgets(buffer, sizeof(buffer), file))
    {
        int indexDivisionString = 0;

        if (buffer[0] == 13)
        {
            changeSolution = true;
            printf("ora le combinazioni");
        }

        if (changeSolution)
        {
            char coppia[7] = {0}; // Array per salvare le coppie
            printf("combinazione %s\n", buffer);

            for (int i = 0; i < strlen(buffer) - 1; i += 3)
            {
                costruzioneCoppia(coppia, i, buffer);
                printf("Coppia generata: %s\n", coppia);
            }
        }
        else
        {
            buffer[2] = ',';
            strcpy(combinazioni[indexCombination], buffer);
            printf("combinazione: %s\n", combinazioni[indexCombination]);
            indexCombination++;
        }
    }

    return 0;
}