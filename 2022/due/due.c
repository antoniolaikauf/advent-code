/*
aversario
A sasso
b carta
c forbici

io
z roccia
y carta
x forbici

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    FILE *file = fopen("small.txt", "r");
    if (file == NULL)
        return 0;

    int score;
    char buffer[250]; // capire come mai se metti 3 te ne fa di più di cicli
    int somma = 0;

    const char combinazioni[][3][5] = {
        // draw
        {
            "A Z",
            "B Y",
            "C X",
        },
        // loss
        {
            "A X",
            "B Z",
            "C Y",
        },
        // winn
        {"A Y",
         "B X",
         "C Z"}};

    int length = sizeof(combinazioni) / sizeof(combinazioni[0]);

    while (fgets(buffer, sizeof(buffer), file))
    {
        buffer[strcspn(buffer, "\n")] = 0;
        printf("Linea letta: %s\n", buffer);

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                // printf("%d", strcmp(buffer, combinazioni[i][j]) == 0);
                if (strcmp(buffer, combinazioni[i][j]) == 0)
                {
                    score += (i + 1) * 2;
                    printf("  %s\n", combinazioni[i][j]);
                }
            }
        }
    }
    printf("%d", score);
    return 0;
}

//== compara se i due puntatatori sono uguali e non il valore