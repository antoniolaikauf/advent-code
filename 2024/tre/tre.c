//--------------------------------
// PRIMA PARTE
//--------------------------------

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
    FILE *file = fopen("small.txt", "r");
    char buffer[250];

    while (fgets(buffer, sizeof(buffer), file))
    {
        printf("Valore è %s\n", buffer);
    }

    fclose(file);
    return 0;
}