#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void changePath(char path[])
{
    if (path[0] == '^')
        path[0] = '>';
    else if (path[0] == '>')
        path[0] = 'v';
    else if (path[0] == '<')
        path[0] = '^';
    else if (path[0] == 'v')
        path[0] = '<';
}

int main()
{
    FILE *file = fopen("small.txt", "r");
    char buffer[250];
    int place[400][3] = {0};
    int positionGuard[2] = {0, 0};
    char guard[] = {0};
    int index = 0;
    char object[] = "#";
    bool orizzontal = false;
    bool vertical = false;
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
                guard[0] = buffer[idxObject];
                positionGuard[0] = idxObject;
                positionGuard[1] = heigthMap;
                printf("%c --> %i in ascisse --> %i in ordinate\n", buffer[idxObject], positionGuard[0], positionGuard[1]);
            }
        }

        heigthMap++;
    }

    printf("\n");

    int output = 0;
    while ((positionGuard[0] > 0 && positionGuard[0] < (strlen(buffer) - 1)) && (positionGuard[1] > 0 && positionGuard[1] < heigthMap - 1))
    {

        for (int i = 0; i < index; i++)
        {
            // printf(" ququququq --> %i in ascisse --> %i in ordinate\n", place[i][0], place[i][1]);
            if (place[i][0] == positionGuard[0] - 1 && place[i][1] == positionGuard[1] && orizzontal)
            {
                printf("entro sinistra --> %i in ascisse --> %i in ordinate\n", positionGuard[0], positionGuard[1]);
                // printf("entro sinistra --> %i in ascisse --> %i in ordinate\n", place[i][0], place[i][1]);
                printf("sinistra\n");
                changePath(guard);
                break;
            }
            else if (place[i][0] == positionGuard[0] + 1 && place[i][1] == positionGuard[1] && orizzontal)
            {
                printf("entro destra --> %i in ascisse --> %i in ordinate\n", positionGuard[0], positionGuard[1]);
                printf("destra\n");
                changePath(guard);
                break;
            }
            else if (place[i][0] == positionGuard[0] && place[i][1] == positionGuard[1] - 1 && vertical)
            {
                printf("entro su --> %i in ascisse --> %i in ordinate\n", positionGuard[0], positionGuard[1]);
                printf("su\n");
                changePath(guard);
                break;
            }
            else if (place[i][0] == positionGuard[0] && place[i][1] == positionGuard[1] + 1 && vertical)
            {
                printf("entro giu --> %i in ascisse --> %i in ordinate\n", positionGuard[0], positionGuard[1]);
                printf("gius\n");
                changePath(guard);
                break;
            }
        }

        output++;
        if (guard[0] == '^')
        {
            vertical = true;
            orizzontal = false;
            positionGuard[1]--;
            printf("si va su\n");
        }
        else if (guard[0] == '>')
        {
            vertical = false;
            orizzontal = true;
            positionGuard[0]++;
            printf("si va destra\n");
        }
        else if (guard[0] == '<')
        {
            vertical = false;
            orizzontal = true;
            printf("si va sinistra\n");
            positionGuard[0]--;
        }
        else if (guard[0] == 'v')
        {
            vertical = true;
            orizzontal = false;
            printf("si va giu\n");
            positionGuard[1]++;
        }
        printf("DOPOO --> %i in ascisse --> %i in ordinate\n", positionGuard[0], positionGuard[1]);
        printf("output --> %i\n", output);
    }

    return 0;
}