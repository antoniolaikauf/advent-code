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
    char arra1[6];
    char arra2[6];
    char arra3[6];
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
            printf("stack: %s\n", buffer);
        }
    }

    return 0;
}