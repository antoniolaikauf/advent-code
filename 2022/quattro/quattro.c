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

char split_number(char f[])
{
    char numbers[2];
    for (int i = 0; i < strlen(f); i++)
    {
        if (f[i] == '-')
        {
            char *first_first = (char *)malloc((i + 1) * sizeof(char));
            char *first_second = (char *)malloc((strlen(f) - i) * sizeof(char));
            strncpy(first_first, f, i);
            strncpy(first_second, f + (i + 1), strlen(f) - i);
            numbers[0] = (int) *first_first;
            numbers[1] = (int) *first_second;
            printf(" primo %ld secondo %s\n", sizeof(first_first), first_second);
        }
    }
    return *numbers;
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
        for (int i = 0; i < strlen(buffer); i++)
        {
            if (buffer[i] == ',')
            {
                char *first = (char *)malloc((i + 1) * sizeof(char));
                char *second = (char *)malloc((strlen(buffer) - i) * sizeof(char));
                strncpy(first, buffer, i);
                strncpy(second, buffer + (1 + i), strlen(buffer) - i);
                first[i] = '\0';
                second[strlen(buffer) - i - 1] = '\0'; // Termina la stringa
                split_number(first);
                split_number(second);
                printf("prima parte %s, seconda parte %s\n", first, second);
                free(first); // Libera la memoria allocata
                free(second);
                break;
            }
        }
    }
    return 0;
}