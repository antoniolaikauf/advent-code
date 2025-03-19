#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *file = fopen("input.txt", "r");
    char buffer[250];
    int place[250] = {0};
    int positionGuard = 0;
    char directionGuard[5] = {'^', 'v', '>', '<', '\0'};
    int index = 0;
    int indexCount = 0;
    char object[] = "#";

    while (fgets(buffer, sizeof(buffer), file))
    {
        printf("linea %s", buffer);
        for (int idxObject = 0; idxObject < (strlen(buffer) - 1); idxObject++)
        {
            if (buffer[idxObject] == object[0]) // Compare characters directly
            {
                place[index] = indexCount + idxObject;
                printf("%c --> %i\n", buffer[idxObject], place[index]);
                index++;
            }
            else if ((buffer[idxObject] != object[0]) && (buffer[idxObject] != 46))
            {
                positionGuard = indexCount + idxObject;
                printf("guardia %c --> %i\n", buffer[idxObject], positionGuard);
            }
        }
        indexCount += strlen(buffer);
    }

    for (int i = 0; i < index; i++)
    {
        printf("%i posizione\n", place[i]);
    }

    return 0;
}