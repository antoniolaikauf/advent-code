//-------------------------
// parte uno
//-------------------------

// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include <limits.h>

// #define length 1000

// char *trimwhitespace(char *str)
// {
//     char *end;

//     // Trim leading space
//     while (isspace((unsigned char)*str))
//         str++;

//     if (*str == 0) // All spaces?
//         return str;

//     // Trim trailing space
//     end = str + strlen(str) - 1;
//     while (end > str && isspace((unsigned char)*end))
//         end--;

//     // Write new null terminator character
//     end[1] = '\0';

//     return str;
// }

// int check(int left[], int right[], int len)
// {
//     // inizializzazione primi numeri
//     int leftLow = left[0];
//     int rightLow = right[0];
//     int indexLeft = 0;
//     int indexRight = 0;

//     // controllo per numero più piccolo
//     for (int i = 1; i < len; i++)
//     {
//         if (leftLow > left[i])
//         {
//             leftLow = left[i];
//             indexLeft = i;
//         }

//         if (rightLow > right[i])
//         {
//             rightLow = right[i];
//             indexRight = i;
//         }
//     }
//     // impostazione dell'indice del numero più piccolo al massimo cosi che non si prenda più
//     left[indexLeft] = INT_MAX;
//     right[indexRight] = INT_MAX;

//     printf("numero più basso : %i altro numero più basso %i\n", rightLow, leftLow);
//     return abs(rightLow - leftLow);
// }

// int main()
// {

//     FILE *file = fopen("input.txt", "r");

//     if (file == NULL)
//         return 0;

//     char buffer[250];

//     int left[length];
//     int right[length];
//     int index = 0;
//     int count = 0;

//     while (fgets(buffer, sizeof(buffer), file))
//     {
//         char *numLeft;
//         char *numRight;

//         numLeft = strtok(buffer, " ");
//         numRight = strtok(NULL, " ");

//         left[index] = atoi(numLeft);
//         right[index] = atoi(numRight);

//         printf("numero a sinistra: %i\n", left[index]);
//         printf("numero a destra: %i\n", right[index]);

//         index++;
//     }

//     for (int i = 0; i < index; i++)
//     {
//         count += check(left, right, index);
//         printf("valore %i\n", count);
//     }

//     return 0;
// }

//---------------------------------
// parte due
//---------------------------------

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define length 1000

char *trimwhitespace(char *str)
{
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str))
        str++;

    if (*str == 0) // All spaces?
        return str;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end))
        end--;

    // Write new null terminator character
    end[1] = '\0';

    return str;
}

int check(int left, int right[], int len)
{
    int occurrences = 0;
    for (int i = 0; i < len; i++)
    {
        if (left == right[i])
            occurrences++;
    }

    return occurrences * left;
}

int main()
{

    FILE *file = fopen("input.txt", "r");

    if (file == NULL)
        return 0;

    char buffer[250];

    int left[length];
    int right[length];
    int index = 0;
    int count = 0;

    while (fgets(buffer, sizeof(buffer), file))
    {
        char *numLeft;
        char *numRight;

        numLeft = strtok(buffer, " ");
        numRight = strtok(NULL, " ");

        left[index] = atoi(numLeft);
        right[index] = atoi(numRight);

        printf("numero a sinistra: %i\n", left[index]);
        printf("numero a destra: %i\n", right[index]);

        index++;
    }

    for (int i = 0; i < index; i++)
    {
        count += check(left[i], right, index);
    }
    printf("valore %i\n", count);

    return 0;
}