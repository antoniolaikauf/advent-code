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

void scaleArray(char array[], char value, int index)
{
    if (index < 4)
        array[index] = value;
    else
    {
        int i = 1;
        for (; i < 4; i++)
        {
            array[i - 1] = array[i];
        }

        array[i - 1] = value;
        array[i] = '\0';
    }
}

int main()
{

    FILE *file = fopen("small.txt", "r");

    char buffer[250];
    char orizontal[250][5] = {0};
    int verticalIndex = 0;
    int indexVertical = 0;
    while (fgets(buffer, sizeof(buffer), file))
    {
        // printf("%c\n", buffer[0]);
        trimwhitespace(buffer);

        int basicIndex = 0;

        while (buffer[basicIndex] != '\0')
        {

            scaleArray(orizontal[basicIndex], buffer[basicIndex], verticalIndex);

            if (strncmp(&buffer[basicIndex], "XMAS", 4) == 0)
            {
                printf("trovata XMAS\n");
            }
            else if (strncmp(&buffer[basicIndex], "SAMX", 4) == 0)
            {
                printf("trovata SAMX\n");
            }
            else if (strncmp(&orizontal[basicIndex][0], "XMAS", 4) == 0)
            {
                printf("%s\n\n", orizontal[basicIndex]);
                printf("trovata XMAS in orizzontale\n");
            }
            else if (strncmp(&orizontal[basicIndex][0], "SAMX", 4) == 0)
            {
                printf("%s\n\n", orizontal[basicIndex]);
                printf("trovata XMAS in orizzontale indietro\n");
            }

            printf("primo indice %s\n", orizontal[basicIndex]);
            basicIndex++;
        }

        verticalIndex++;
    }

    for (int i = 0; i < 5; i++)
    {
        // orizontal[i][4] = '\0';
        // printf("qua veritcal %s\n", orizontal[i]);
    }

    return 0;
}