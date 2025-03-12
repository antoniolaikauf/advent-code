#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *file = fopen("small.txt", "r");

    if (file == NULL)
        return 0;
    char buffer[250];
    
    bool changeSolution = false;
    while (fgets(buffer, sizeof(buffer), file))
    {

        if (buffer[0] == 13)
        {
            changeSolution = true;
            printf("ora le combinazioni");
        }

        if (changeSolution)
        {
            printf("%s\n", buffer);
        }
        else
        {
            printf("combinazione: %s\n", buffer);
        }
    }

    return 0;
}