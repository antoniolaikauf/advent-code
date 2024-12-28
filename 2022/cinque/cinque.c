#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

void removeChar(char *string, char charToRemoveLeft, char charToRemoveRight)
{

    int i, j = 0;
    int len = strlen(string);

    for (i = 0; i < len; i++)
    {
        if (string[i] != charToRemoveLeft && string[i] != charToRemoveRight)
        {
            string[j++] = string[i];
        }
    }
    string[j] = '\0';
}

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

void section(char b[], char one[], char two[], char three[])
{

    printf("mosse: %s\n", one);
}

int main()
{

    FILE *file = fopen("small.txt", "r");
    if (file == NULL)
        return 0;

    char buffer[250];
    char array1[6];
    char array2[6];
    char array3[6];
    bool mosse = false;

    while (fgets(buffer, sizeof(buffer), file))
    {
        trimwhitespace(buffer);
        if (buffer[0] == 13)
        {
            mosse = true;
            continue;
        }

        if (mosse)
        {
            printf("mosse: %s\n", buffer);
        }
        else
        {
            // removeChar(buffer, '[', ']');
            section(buffer, array1, array2, array3);
            // printf("stack: %c\n", buffer[1]);
        }
    }

    return 0;
}