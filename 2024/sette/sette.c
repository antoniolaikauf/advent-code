#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *file = fopen("small.txt", "r");

    if (file == NULL)
        return 0;

    char buffer[250];
    int result = 0;
    int output = 0;

    while (fgets(buffer, sizeof(buffer), file))
    {
        int equation[250] = {0};

        char *token = strtok(buffer, ":");
        result = atoi(token);
        int indexNumber = 0;

        token = strtok(NULL, " "); // Get next token before the loop

        while (token != NULL)
        {
            equation[indexNumber] = atoi(token); // Move this before next strtok
            // printf("%i\n", equation[indexNumber]);
            indexNumber++;
            token = strtok(NULL, " "); // Get next token
        }

        int resultAdd = 0;
        int resultProd = 1;

        for (int i = 0; i < indexNumber; i++)
        {
            resultAdd += equation[i];
            resultProd *= equation[i];
        }

        if (resultAdd > result || resultProd > result)
        {
            for (int i = 0; i < indexNumber; i++)
            {
                int numberTry = i == 0 ? 0 : 1;
                int number = equation[i];
                bool correct = false;
                for (int y = 0; y < indexNumber; y++)
                {
                    if (equation[y] == number)
                    {
                        numberTry += equation[y];
                        // printf("output: %i\n", numberTry);
                    }
                    else
                    {
                        numberTry *= equation[y];
                        // printf("output: %i\n", numberTry);
                    }

                    if (numberTry == result)
                    {
                        correct = true;
                        output += numberTry;
                        printf("output: %i\n", output);
                    }
                }
                if (correct)
                    break;
            }
            printf("obbiettivo è %i il risultato addizione è: %i il risulato prodotto è:%i \n", result, resultAdd, resultProd);
        }
    }
}