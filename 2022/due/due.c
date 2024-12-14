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

int main()
{
    FILE *file = fopen("small.txt", "r");
    if (file == NULL)
        return 0;

    int score;
    char buffer[250];
    // array due dimensioni 
    const char combinazioni[][5] = {
        "A Y",
        "A X",
        "A Z",
        "B Y",
        "B X",
        "B Z",
        "C Y",
        "C X",
        "C Z"};

    int length = sizeof(combinazioni) / sizeof(combinazioni[0]);

    for (int i = 0; i < length; i++)
    {
        printf("%s\n", combinazioni[i]);
    }

    while (fgets(buffer, sizeof(buffer), file))
    {
        printf("%s", buffer);
    }
    return 0;
}