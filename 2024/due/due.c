// #include <stdio.h>
// #include <string.h>
// #include <stdbool.h>
// #include <stdlib.h>

// int main()
// {

//     FILE *file = fopen("small.txt", "r");
//     char buffer[250];
//     int output = 0;

//     while (fgets(buffer, sizeof(buffer), file))
//     {
//         char *number;
//         number = strtok(buffer, " ");
//         int len = 0;
//         int num[15];
//         // poplazione array con dentro numeri
//         while (number != NULL)
//         {

//             if (number != NULL)
//                 num[len] = atoi(number);
//             number = strtok(NULL, " ");
//             len++;
//         }

//         num[len] = '\0';

//         // valutazione del primo elemento
//         int valueStrat = num[0] - num[1];
//         bool checkstart = true;
//         if (valueStrat <= 0)
//             checkstart = false;

//         int count = 0;

//         for (int i = 0; i < (len - 1); i++)
//         {
//             bool check = true;
//             int value = num[i] - num[i + 1];

//             if (value <= 0)
//             {
//                 check = false;
//             }
//             // controllo condizioni se sta nel range e se riepstta il primo pattern
//             if (((1 <= value && value <= 3) || (-1 >= value && value >= -3)) && (check == checkstart))
//             {
//                 count++;
//             }
//             else
//                 break;
//         }

//         if (count == len - 1)
//             output++;
//     }
//     printf(" valore è %i", output);
//     return 0;
// }

//--------------------------------
// SECONDA PARTE
//--------------------------------

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

bool checkFirstSign(int first, int second)
{
    int valueStrat = first - second;
    bool checkstart = true;
    if (valueStrat < 0)
        checkstart = false;

    return checkstart;
}

bool checkValue(int numeri[], int index, int length, bool checkStart)
{
    int value = 0;
    int checkFirst = 0;

    int second = 0;
    for (int i = 0; i < length - 1; i++)
    {
        if ((i == index - 1))
        {
            second += 2;
            value = numeri[i] - numeri[second];
            printf("numero :%i numero 2 : %i , risultato %i valore i %i valore second %i\n", numeri[i], numeri[second], value, i, second);
            i = second - 1;
        }
        else
        {
            second++;
            value = numeri[i] - numeri[second];
            printf("numero :%i numero 2 : %i , risultato %i valore i %i valore second %i\n", numeri[i], numeri[second], value, i, second);
        }

        bool check = true;

        if (value <= 0)
        {
            check = false;
        }
        // // controllo condizioni se sta nel range e se riepstta il primo pattern
        if (((1 <= value && value <= 3) || (-1 >= value && value >= -3)) && (check == checkStart))
        {
            checkFirst++;
        }
        else
        {
            break;
        }
    }
    printf("numero %i\n", checkFirst);
    return checkFirst == length - 2;
}

int main()
{

    FILE *file = fopen("small.txt", "r");
    char buffer[250];
    int output = 0;

    while (fgets(buffer, sizeof(buffer), file))
    {
        char *number;
        number = strtok(buffer, " ");
        int len = 0;
        int num[15];
        // poplazione array con dentro numeri
        while (number != NULL)
        {

            if (number != NULL)
                num[len] = atoi(number);
            number = strtok(NULL, " ");
            len++;
        }

        num[len] = '\0';

        // valutazione del primo elemento
        bool checkstart = checkFirstSign(num[0], num[1]);

        bool error = false;
        int count = 0;

        for (int i = 0; i < (len - 1); i++)
        {
            bool check = true;
            int value = num[i] - num[i + 1];

            if (value <= 0)
            {
                check = false;
            }

            if ((i == 0) && (value > 3 || value < -3) && (error == false))
            {
                checkstart = checkFirstSign(num[1], num[2]);
                error = true;
                count++;
                printf("fine o inizio %i\n", i);
                continue;
            }
            else if ((i == (len - 2)) && (value > 3 || value < -3) && (error == false))
            {
                count++;
                error = true;
                printf("%i sono fine\n", i);
                continue;
            }
            // controllo condizioni se sta nel range e se riepstta il primo pattern
            else if (((1 <= value && value <= 3) || (-1 >= value && value >= -3)) && (check == checkstart))
            {
                printf(" valore di  %i\n", value);
                count++;
            }
            else if ((error == false) && (checkValue(num, i, len, checkstart)))
            {
                // printf("valore da eliminare %i\n", i);
                count++;
                error = true;
            }
            else
            {
                break;
            }
        }
        if (count == len - 1)
            output++;
    }
    printf(" valore è %i", output);
    return 0;
}