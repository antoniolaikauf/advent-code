#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LENGTH 6

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

int main()
{

    FILE *file = fopen("small.txt", "r");
    if (file == NULL)
        return 0;

    char buffer[250];
    char array1[MAX_LENGTH];
    char array2[MAX_LENGTH];
    char array3[MAX_LENGTH];
    bool mosse = false;
    int idx_one = 0, idx_two = 0, idx_three = 0;
    while (fgets(buffer, sizeof(buffer), file))
    {

        if (buffer[0] == 13)
        {
            mosse = true;
            continue;
        }
        if (!mosse)
        {

            int i = 0;
            while (buffer[i] != '\0')
            {
                if (buffer[i] != 13 && buffer[i] != '[' && buffer[i] != ']' && buffer[i] != 32 && buffer[i] != '1' && buffer[i] != '2' && buffer[i] != '3')
                {
                    if (i == 1) // Assegna a "one"
                    {
                        array1[idx_one++] = buffer[i];
                    }
                    else if (i == 5) // Assegna a "two"
                    {
                        array2[idx_two++] = buffer[i];
                    }
                    else if (i == 9) // Assegna a "three"
                    {
                        array3[idx_three++] = buffer[i];
                    }
                }
                i++;
            }
        }
        else
        {
            char *token;
            token = strtok(buffer, " ");
            char arrayMove[4] = {0};

            int index = 0;
            int i = 0;
            while (token != NULL)
            {
                if (i % 2 == 1)
                {
                    arrayMove[index] = *token;
                    index++;
                }
                i++;
                token = strtok(NULL, " ");
            }
            arrayMove[index] = '\0';
            printf("mosse: %s\n", arrayMove);
        }
    }
    printf("stack: %s\n", array1);
    printf("stack: %s\n", array2);
    printf("stack: %s\n", array3);
    return 0;
}