#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    FILE *file = fopen("small.txt", "r");
    if (file == NULL)
        return 0;

    char buffer[250];
    while (fgets(buffer, sizeof(buffer), file))
    {
        printf("%s", buffer);
    }
    return 0;
}