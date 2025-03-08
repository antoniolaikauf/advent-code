#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *file = fopen("small.txt", "r");

    char buffer[250];
    char orizontal[250][4];
    while (fgets(buffer, sizeof(buffer), file))
    {
        // printf("%c\n", buffer[0]);

        int basicIndex = 0;
        while (buffer[basicIndex] != '\0')
        {
            if (strncmp(&buffer[basicIndex], "XMAS", 4) == 0)
            {
                printf("trovata XMAS\n");
            }
            else if (strncmp(&buffer[basicIndex], "SAMX", 4) == 0)
            {
                printf("trovata SAMX\n");
            }
            basicIndex++;

            if (strncmp(&orizontal[basicIndex][4], "XMAS", 4) == 0)
            {
                printf("trovata XMAS in orizzontale\n");
            } 
            else if (strncmp(&orizontal[basicIndex][4], "SMAX", 4) == 0)
            {
                printf("trovata XMAS in orizzontale indietro\n");
            }
            
        }
    }

    return 0;
}