//--------------------------------
// PRIMA PARTE
//--------------------------------

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *file = fopen("input.txt", "r");
    char buffer[20000];
    int output = 0;

    bool checkCorrectSequence = false;

    while (fgets(buffer, sizeof(buffer), file))
    {
        int i = 1;
        while (buffer[i] != '\0')
        {
            // printf("indietro %c mezzo %c avanti %c\n", buffer[i - 1], buffer[i], buffer[i + 1]);
            
            if ((buffer[i - 1] == 'm') && (buffer[i] == 'u') && (buffer[i + 1] == 'l'))
            {
                int j = i + 3;
                bool left = false;
                int indexNumber = 0;
                char numberLeft[20] = {0};
                char numberRight[20] = {0};
                while ((buffer[j] != ')') && (buffer[j] != 'm'))
                {
                    if (isdigit(buffer[j]) && (left == false))
                    {
                        printf("%c sono a sinista \n", buffer[j]);
                        numberLeft[indexNumber] = buffer[j];
                        indexNumber++;
                    }
                    else if (isdigit(buffer[j]) && left)
                    {
                        printf("%c sono a destra \n", buffer[j]);
                        numberRight[indexNumber] = buffer[j];
                        indexNumber++;
                    }
                    else if (buffer[j] == ',')
                    {
                        numberLeft[indexNumber] = '\0';
                        left = true;
                        indexNumber = 0;
                    }
                    else if (isdigit(buffer[j]) == false)
                    {
                        checkCorrectSequence = true;
                        printf("numero fake\n");
                        break;
                    }

                    j++;
                }
                numberRight[indexNumber] = '\0';

                if (checkCorrectSequence == false)
                {
                    printf("numero sinistra %s numero a denstra %s\n", numberLeft, numberRight);
                    output += atoi(numberRight) * atoi(numberLeft);
                }
                checkCorrectSequence = false;
            }
            i++;
        }
    }
    printf("valore: %i", output);

    fclose(file);
    return 0;
}