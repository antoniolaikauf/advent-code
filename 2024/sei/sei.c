#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *file = fopen("input.txt", "r");
    char buffer[250];
    int place[250][3] = {0};
    int positionGuard[2] = {0, 0};
    char directionGuard[5] = {'^', 'v', '>', '<', '\0'};
    int guard = 0;
    int index = 0;
    int indexCount = 0;
    char object[] = "#";

    int heigthMap = 0;

    while (fgets(buffer, sizeof(buffer), file))
    {
        // printf("linea %s\n", buffer);
        for (int idxObject = 0; idxObject < (strlen(buffer) - 1); idxObject++)
        {
            if (buffer[idxObject] == object[0]) // Compare characters directly
            {
                place[index][0] = idxObject;
                place[index][1] = heigthMap;
                printf("%c --> %i in ascisse --> %i in ordinate\n", buffer[idxObject], place[index][0], place[index][1]);
                index++;
            }
            else if (buffer[idxObject] == '^' || buffer[idxObject] == 'v' ||
                     buffer[idxObject] == '>' || buffer[idxObject] == '<')
            {
                if (buffer[idxObject] == directionGuard[0])
                    guard = 0;
                else if (buffer[idxObject] == directionGuard[1])
                    guard = 1;
                else if (buffer[idxObject] == directionGuard[2])
                    guard = 2;
                else if (buffer[idxObject] == directionGuard[3])
                    guard = 3;

                positionGuard[0] = idxObject;
                positionGuard[1] = heigthMap;
                printf("%c --> %i in ascisse --> %i in ordinate\n", buffer[idxObject], positionGuard[0], positionGuard[1]);
            }
        }

        heigthMap++;
    }

    while ((positionGuard[0] > 0 && positionGuard[0] < (strlen(buffer) - 1)) && (positionGuard[1] > 0 && positionGuard[1] < heigthMap))
    {
        positionGuard[0]--;
        printf(" --> %i in ascisse --> %i in ordinate\n",  positionGuard[0], positionGuard[1]);
    }

    return 0;
}