// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>
// #include <stdlib.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define lenght_alfabeto 52
void divisione_parola(char parola[], int len, char **s1, char **s2)
{
    int left = len / 2;
    int right = len - left;
    // più 1 essendo che bisogna mettere il carattere di fine \0
    *s1 = (char *)malloc(sizeof(char) * (left + 1));
    *s2 = (char *)malloc(sizeof(char) * (right + 1));

    strncpy(*s1, parola, left);
    (*s1)[left] = '\0';

    strncpy(*s2, parola + left, right);

    (*s2)[right] = '\0';
}

int controllo_presenza(char lettera, char lettere[], int len)
{
    for (int y = 0; y < len; y++)
    {
        if (lettera == lettere[y])
        {
            return 0;
            break;
        }
    }

    return 1;
}

// Funzione per calcolare il punteggio della lettera
int calcolo(char lettera)
{
    if (isupper(lettera))
    {
        return lettera - 'A' + 27;
    }
    else if (islower(lettera))
    {
        return lettera - 'a' + 1;
    }
    return 0;
}

// // funzione per rimuovere lo spazio che non si vede
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
    FILE *file = fopen("input.txt", "r");
    if (file == NULL)
        return 0;

    char buffer[250];
    int somma = 0;
    while (fgets(buffer, sizeof(buffer), file))
    {
        // printf("%s", buffer);
        // buffer[strcspn(buffer, "\n")] = 0;
        trimwhitespace(buffer);
        int length = strlen(buffer);
        char *first, *second;
        divisione_parola(buffer, length, &first, &second);

        printf("sono la  %s\n", first);
        printf("sono la  %s\n", second);

        char lettere[lenght_alfabeto];
        int index = 0;
        for (int i = 0; i < length / 2; i++)
        {
            for (int x = 0; x < length / 2; x++)
            {
                // indice cosi evito di controllare tutto l'array ma solo fino all'ultima lettera messa
                if (first[i] == second[x] && controllo_presenza(first[i], lettere, index))
                {
                    lettere[index] = first[i];
                    somma += calcolo(first[i]);
                    printf("sono dentro%d        %d\n", i, x);
                    index++;
                    break;
                }
            }
        }
        // Libero la memoria allocata
        free(first);
        free(second);
        printf("somma: %d\n", somma);
    }
    return 0;
}
