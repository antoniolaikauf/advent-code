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

    char source[] = "Hello, World!";
    char destination[6]; // Adjust the size based on the part you want to extract

    // Copy the first 5 characters from source to destination
    strncpy(destination, source, 5);

    // Ensure the destination string is null-terminated
    destination[5] = '\0';

    FILE *file = fopen("small.txt", "r");
    if (file == NULL)
        return 0;
    char buffer[250];
    while (fgets(buffer, sizeof(buffer), file))
    {
        trimwhitespace(buffer);
        // printf("%s\n", buffer);
        char first[5];
        char second[5];
        for (int i = 0; i < strlen(buffer); i++)
        {
            if (buffer[i] == ',')
            {
                strncpy(first, buffer, i);
                strncpy(second, buffer + (1 + i), strlen(buffer) - i);
                first[4] = '\0';
                second[4] = '\0';
                break;
            }
        }
        printf("prima parte %s, seconda parte %s\n", first, second);
    }
    return 0;
}