#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int is_int(int numebr)
{
    return 1;
}

int main()
{
    FILE *file = fopen("small.txt", "r");
    if (file == NULL)
    {
        printf("file non trovato");
        return 0;
    }
    else
    {
        char buffer[100]; // spazio per leggere la riga del file
        // buffer è dove viene salvato il file
        int calories = 0;
        int number;
        while (fgets(buffer, sizeof(buffer), file))
        {
            printf("%s", buffer);

            if (is_int(buffer))
            {
                printf("jfjfjffffffffffffffj");
            }
            else
            {
                printf("jfjjfj");
            }
        }
        // printf("%d\n", calories);
    }

    return 0;
}