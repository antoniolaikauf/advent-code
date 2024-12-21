#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
// funzione per rimuovere lo spazio che non si vede
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
    while (fgets(buffer, sizeof(buffer), file))
    {
        trimwhitespace(buffer);
        printf("%s\n", buffer);
    }
    return 0;
}