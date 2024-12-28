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

// void section(char b[], char one[], char two[], char three[])
// {
//     while (b[i] != '\0')
//     {
//         if (b[i] != 13 && b[i] != '[' && b[i] != ']' && b[i] != 32)
//         {
//             if (i % 3 == 1) // Assegna a "one" (ad esempio ogni 3° carattere)
//             {
//                 one[idx_one++] = b[i];
//             }
//             else if (i % 3 == 2) // Assegna a "two"
//             {
//                 two[idx_two++] = b[i];
//             }
//             else // Assegna a "three"
//             {
//                 three[idx_three++] = b[i];
//             }
//         }
//         i++;
//     }
// }

int main()
{

    FILE *file = fopen("small.txt", "r");
    if (file == NULL)
        return 0;

    char buffer[250];
    char array1[50];
    char array2[50];
    char array3[50];
    bool mosse = false;
    int idx_one = 0, idx_two = 0, idx_three = 0;
    while (fgets(buffer, sizeof(buffer), file))
    {

        if (buffer[0] == '1' || buffer[0] == 13)
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
            int i = 0;
            while (buffer[i] != '\0')
            {
                if (buffer[i] != 13 && buffer[i] != '[' && buffer[i] != ']' && buffer[i] != 32 && buffer[i] != '1' && buffer[i] != '2' && buffer[i] != '3')
                {
                    if (i % 3 == 1) // Assegna a "one"
                    {
                        array1[idx_one++] = buffer[i];
                    }
                    else if (i % 3 == 2) // Assegna a "two"
                    {
                        array2[idx_two++] = buffer[i];
                    }
                    else // Assegna a "three"
                    {
                        array3[idx_three++] = buffer[i];
                    }
                }
                i++;
            }
        }
    }

    printf("stack: %s\n", array1);
    printf("stack: %s\n", array2);
    printf("stack: %s\n", array3);
    return 0;
}