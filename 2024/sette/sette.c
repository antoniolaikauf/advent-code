#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *file = fopen("input.txt", "r");

    if (file == NULL)
        return 0;

    char buffer[250];
    int result = 0;
    int output = 0;

    while (fgets(buffer, sizeof(buffer), file))
    {
        int equation[250] = {0};

        char *token = strtok(buffer, ":");
        // risultato da ottenere
        result = atoi(token);
        int indexNumber = 0;

        token = strtok(NULL, " ");

        while (token != NULL)
        {
            // valori per la equazione
            equation[indexNumber] = atoi(token);
            token = strtok(NULL, " ");
            indexNumber++;
        }

        // slot per inserire i + o -
        int op_count = indexNumber - 1;
        // tutte le combinazioni possibili sarebbero 2 ^ op_count essendo che per ogni spazio o c'è * o +
        int total_combinations = 1 << op_count;

        // ciclo su tutte le combinazioni
        for (int i = 0; i < total_combinations; i++)
        {
            int temp = i;
            // array che conterra la combinazione
            char combinations[20];

            /*
            questo ciclo che crea le combinazioni si basa sul modulo

            es 81 40 27 ci possono essere 4 combinazioni
            0 % 2 sarà sempre 0 e quindi false e metterà ++
            1 % 2 sarà 1 e dopo si divide e divintera 0 % 2 e quindi la composizione sarà *+
            2 % 2 sarà 0 e dopo si divide e sarà 1 % 2 e quindi composizione sarà +*
            3 % 2 sarà 1 e dopo si divide e sarà 1 % 2 e quindi composizione sarà **
            in questo modo si hanno tutte le composizioni
            */
            for (int j = 0; j < op_count; j++)
            {
                combinations[j] = (temp % 2) ? '*' : '+';
                temp /= 2;
            }
            combinations[op_count] = '\0';

            int indexNumber = 0;
            int tryNumber = equation[indexNumber];

            // ciclo per fare le operazioni
            for (int j = 0; j < op_count; j++)
            {

                if (combinations[j] == '*')
                    tryNumber *= equation[indexNumber + 1];
                else
                    tryNumber += equation[indexNumber + 1];

                indexNumber++;
            }

            if (tryNumber == result)
            {
                output += tryNumber;
                break;
            }
        }
    }
    printf("output = %i\n", output);
}


// 1291527431
// 28730327770375