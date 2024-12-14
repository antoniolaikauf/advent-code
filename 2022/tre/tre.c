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
}

int main()
{
    FILE *file = fopen("small.txt", "r");
    if (file == NULL)
        return 0;

    char buffer[250];
    while (fgets(buffer, sizeof(buffer), file))
    {
        printf("%s", buffer);
        buffer[strcspn(buffer, "\n")] = 0;
        int length = strlen(buffer);
        char *first, *second;
        divisione_parola(buffer, length, &first, &second);
    }
    return 0;
}