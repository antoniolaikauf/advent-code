#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cstdlib>

void divisione_parola(char parola[], int len, char **s1, char **s2)
{
    int left = len / 2;
    int rigth = len - left;
    *s1 = (char *)malloc(sizeof(char) * left + 1);
    *s2 = (char *)malloc(sizeof(char) * rigth + 1);
    strncpy(*s1, parola, left);
    strncpy(*s2, parola + left, rigth);
}

int controllo_presenza(char lettera, char lettere[])
{
    for (int y = 0; y < sizeof(lettere); y++)
    {
        if (lettera == lettere[y])
        {
            return 0;
            break;
        }
    }

    return 1;
}

int main()
{
    FILE *file = fopen("small.txt", "r");
    if (file == NULL)
        return 0;

    char buffer[250];
    while (fgets(buffer, sizeof(buffer), file))
    {
        // printf("%s", buffer);
        buffer[strcspn(buffer, "\n")] = 0;
        int length = strlen(buffer);
        char *first, *second;
        divisione_parola(buffer, length, &first, &second);

        printf("sono la  %s\n", second);
        printf("sono la  %s\n", first);

        char lettere[52];
        int index = 0;
        for (int i = 0; i < length / 2; i++)
        {
            for (int x = 0; x < length / 2; x++)
            {
                if (first[i] == second[x] && controllo_presenza(first[i], lettere))
                {
                    lettere[index] = first[i];
                    printf("sono dentro        %s\n", first);
                    index++;
                }
            }
        }
    }
    return 0;
}