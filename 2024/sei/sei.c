#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file = fopen("input.txt", "r");
    char buffer[250];
    while (fgets(buffer, sizeof(buffer), file))
    {
        printf("linea %s", buffer);
    }

    return 0;
}