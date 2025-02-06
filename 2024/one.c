#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

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

    char left[400];
    char right[400];
    int index = 0;

    while (fgets(buffer, sizeof(buffer), file))
    {
        char *numLeft;
        char *numRight;

        numLeft = strtok(buffer, "  ");
        numRight = strtok(NULL, "");

        left[index] = *numLeft;
        right[index] = *numRight;
        index++;

        printf("numero a sinistra: %s\n", numLeft);
        printf("numero a destra: %s\n", numRight);
    }

    left[index] = '\0';
    right[index] = '\0';

    return 0;
}