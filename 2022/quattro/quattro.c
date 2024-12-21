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
    char fisrt_first[3];
    char fisrt_second[3];
    for (int i = 0; i < strlen(f); i++)
    {
        if (f[i] == '-')
        {
            strncpy(fisrt_first, f, i);
            strncpy(fisrt_second, f + (i + 1), strlen(f) - i);
            // numbers[0] = fisrt_first;
            // numbers[1] = fisrt_second;
            printf(" primo %s secondo %s\n", fisrt_first, fisrt_second);
        }
    }
    // return numbers;
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
                // split_number(first);
                // split_number(second);
                printf("prima parte %s, seconda parte %s\n", first, second);
                free(first); // Libera la memoria allocata
                free(second);
                break;
            }
        }
    }
    return 0;
}