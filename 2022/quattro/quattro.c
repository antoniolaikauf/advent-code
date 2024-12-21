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

int split_number(char f[], int result[])
{
    for (int i = 0; i < strlen(f); i++)
    {
        if (f[i] == '-')
        {
            char *first_first = (char *)malloc((i + 1) * sizeof(char));
            char *first_second = (char *)malloc((strlen(f) - i) * sizeof(char));
            strncpy(first_first, f, i);
            strncpy(first_second, f + (i + 1), strlen(f) - i);
            result[0] = atoi(first_first);
            result[1] = atoi(first_second);

            printf("Primo numero: %d, Secondo numero: %d\n", result[0], result[1]);
            free(first_first);
            free(first_second);
        }
    }
    return 0;
}


int check(int first[], int second[])
{
    if ((second[0] >= first[0] && second[1] <= first[1]) ||
        (first[0] >= second[0] && first[1] <= second[1]))
    {
        printf("%d                    , %d\n", first[0], first[1]);
        printf("%d                    , %d\n", second[0], second[1]);
        return 1;
    }
    return 0;
}

int main()
{
    FILE *file = fopen("input.txt", "r");
    if (file == NULL)
        return 0;
    char buffer[250];
    int somma = 0;
    while (fgets(buffer, sizeof(buffer), file))
    {
        trimwhitespace(buffer);
        for (int i = 0; i < strlen(buffer); i++)
        {
            if (buffer[i] == ',')
            {
                int numbers_first[2];
                int numbers_second[2];

                char *first = (char *)malloc((i + 1) * sizeof(char));
                char *second = (char *)malloc((strlen(buffer) - i) * sizeof(char));
                strncpy(first, buffer, i);
                strncpy(second, buffer + (1 + i), strlen(buffer) - i);
                first[i] = '\0';
                second[strlen(buffer) - i - 1] = '\0'; // Termina la stringa

                split_number(first, numbers_first);
                split_number(second, numbers_second);

                somma += check(numbers_first, numbers_second);

                // printf("prima parte %s, seconda parte %s\n", first, second);
                free(first); // Libera la memoria allocata
                free(second);
                break;
            }
        }
    }
    printf("somma :%d \n", somma);
    return 0;
}