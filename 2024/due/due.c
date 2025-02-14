#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{

    FILE *file = fopen("input.txt", "r");
    char buffer[250];
    int output = 0;

    while (fgets(buffer, sizeof(buffer), file))
    {
        char *number;
        number = strtok(buffer, " ");
        int len = 0;
        int num[15];
        // poplazione array con dentro numeri 
        while (number != NULL)
        {

            if (number != NULL)
                num[len] = atoi(number);
            number = strtok(NULL, " ");
            len++;
        }

        num[len] = '\0';

        // valutazione del primo elemento 
        int valueStrat = num[0] - num[1];
        bool checkstart = true;
        if (valueStrat <= 0)
            checkstart = false;

        int count = 0;

        for (int i = 0; i < (len - 1); i++)
        {
            bool check = true;
            int value = num[i] - num[i + 1];

            if (value <= 0)
            {
                check = false;
            }
            // controllo condizioni se sta nel range e se riepstta il primo pattern 
            if (((1 <= value && value <= 3) || (-1 >= value && value >= -3)) && (check == checkstart))
            {
                count++;
            }
            else
                break;
        }

        if (count == len - 1)
            output++;
    }
    printf(" valore è %i", output);
    return 0;
}