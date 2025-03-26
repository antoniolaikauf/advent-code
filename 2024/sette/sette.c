#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *file = fopen("small.txt", "r");

    if (file == NULL)
        return 0;

    char buffer[250];
    while (fgets(buffer, sizeof(buffer), file))
    {
        printf("%s\n", buffer);
    }
}