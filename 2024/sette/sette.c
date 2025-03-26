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

    while (fgets(buffer, sizeof(buffer), file))
    {
        int equation[250] = {0};

        char *token = strtok(buffer, ":");
        result = atoi(token);
        int indexNumber = 0;

        token = strtok(NULL, " ");

        while (token != NULL)
        {
            equation[indexNumber] = atoi(token);
            indexNumber++;
            token = strtok(NULL, " ");
        }

        for (int i = 0; i < indexNumber; i++)
        {
            printf("il numero è: %i\n", equation[indexNumber]);
        }
    }
}