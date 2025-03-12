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
    char vertical[250][5] = {0};
    char diagonalTLBR[250][5] = {0};
    char diagonalTRBl[250][5] = {0};
    int verticalIndex = 0;
    int indexVertical = 0;
    int indexLast = 0;
    int diagonalIndexTLBR = 0;
    int diagonalIndexTRBl = 0;
    int output = 0;

    while (fgets(buffer, sizeof(buffer), file))
    {
        trimwhitespace(buffer);

        int basicIndex = 0;

        if (vertical[0][0] == false)
        {
            int len = strlen(buffer);
            indexLast = len - 1;
            diagonalIndexTRBl = indexLast;
        }

        while (buffer[basicIndex] != '\0')
        {

            // if (basicIndex < (indexLast - 3))
            // {
            if ((diagonalIndexTRBl - basicIndex) >= 0)
            {
                // printf("qua diagonale        %c e qua valore in %i \n", buffer[(diagonalIndexTRBl - basicIndex)], (diagonalIndexTRBl - basicIndex));
                // scaleArray(diagonalTRBl[ + basicIndex], buffer[(diagonalIndexTRBl - basicIndex)], verticalIndex);
                printf("diagonale top right  %s  altro elemento %c\n", diagonalTRBl[basicIndex], buffer[(diagonalIndexTRBl - basicIndex)]);
            }
            if ((diagonalIndexTLBR + basicIndex) <= indexLast)
            {
                // printf("qua diagonale        %c e qua valore in %i \n", buffer[(diagonalIndexTLBR + basicIndex)], diagonalIndexTLBR);
                // scaleArray(diagonalTLBR[basicIndex], buffer[(diagonalIndexTLBR + basicIndex)], verticalIndex);
            }
            // }

            scaleArray(vertical[basicIndex], buffer[basicIndex], verticalIndex);

            if (strncmp(&buffer[basicIndex], "XMAS", 4) == 0)
            {
                output++;
                printf("trovata oriz XMAS\n");
            }
            if (strncmp(&buffer[basicIndex], "SAMX", 4) == 0)
            {
                output++;
                printf("trovata oriz SAMX\n");
            }
            if (strncmp(&vertical[basicIndex][0], "XMAS", 4) == 0)
            {
                output++;
                printf("trovata XMAS in verticale %s\n", vertical[basicIndex]);
            }
            if (strncmp(&vertical[basicIndex][0], "SAMX", 4) == 0)
            {
                output++;
                printf("trovata SAMX in verticale %s\n", vertical[basicIndex]);
            }
            if (strncmp(&diagonalTLBR[basicIndex][0], "XMAS", 4) == 0)
            {
                output++;
                printf("trovata XMAS in diagonale top LEFT bottom RIGHT %s\n", diagonalTLBR[basicIndex]);
            }
            if (strncmp(&diagonalTLBR[basicIndex][0], "SAMX", 4) == 0)
            {
                output++;
                printf("trovata XMAS in diagonale top LEFT bottom RIGHT  %s\n", diagonalTLBR[basicIndex]);
            }
            if (strncmp(&diagonalTRBl[basicIndex][0], "XMAS", 4) == 0)
            {
                output++;
                printf("trovata XMAS in diagonale top RIGHT bottom LEFT %s\n", diagonalTRBl[basicIndex]);
            }
            if (strncmp(&diagonalTRBl[basicIndex][0], "SAMX", 4) == 0)
            {
                output++;
                printf("trovata SAMX in diagonale top RIGHT bottom LEFT  %s\n", diagonalTRBl[basicIndex]);
            }

            // printf("primo indice %s\n", vertical[basicIndex]);
            basicIndex++;
        }

        printf("\n");
        diagonalIndexTLBR++;
        diagonalIndexTRBl--;
        verticalIndex++;
    }
    printf("risultato finale %i", output);

    return 0;
}

/*
nelle diagonali ogni elemento dovrebbe partire un array


*/
