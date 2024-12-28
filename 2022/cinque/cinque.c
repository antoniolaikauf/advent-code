#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LENGTH_STACK 56
#define MAX_LENGTH 10

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

void reverseArray(char arr[], int length)
{
    int start = 0;
    int end = length - 1;
    char temp;

    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void move(char From[], char Too[], int arrayMove[])
{
    int indexFrom = strlen(From) - 1;
    int indexToo = strlen(Too);
    for (int i = 0; i < arrayMove[0]; i++)
    {
        Too[indexToo] = From[indexFrom];
        From[indexFrom] = '\0';
        indexFrom--;
        indexToo++;
    }

    Too[indexToo] = '\0';       
    // From[indexFrom + 1] = '\0'; 
}

int main()
{

    FILE *file = fopen("input.txt", "r");
    if (file == NULL)
        return 0;

    char buffer[250];
    char array[MAX_LENGTH][MAX_LENGTH_STACK];
    bool mosse, reverse = false;
    int idx_one = 0, idx_two = 0, idx_three = 0, idx_four = 0, idx_five = 0, idx_six = 0, idx_seven = 0, idx_eight = 0, idx_nine = 0;
    while (fgets(buffer, sizeof(buffer), file))
    {

        if (buffer[0] == 13)
        {
            mosse = true;
            continue;
        }
        if (!mosse)
        {

            int i = 0;
            while (buffer[i] != '\0')
            {

                if (buffer[i] != 13 && buffer[i] != '[' && buffer[i] != ']' && buffer[i] != 32 && buffer[i] != '1' && buffer[i] != '2' && buffer[i] != '3')
                {
                    if (i == 1) // Assegna a "one"
                        array[0][idx_one++] = buffer[i];
                    else if (i == 5) // Assegna a "two"
                        array[1][idx_two++] = buffer[i];
                    else if (i == 9) // Assegna a "three"
                        array[2][idx_three++] = buffer[i];
                    else if (i == 13) // Assegna a "three"
                        array[3][idx_four++] = buffer[i];
                    else if (i == 17) // Assegna a "three"
                        array[4][idx_five++] = buffer[i];
                    else if (i == 21) // Assegna a "three"
                        array[5][idx_six++] = buffer[i];
                    else if (i == 25) // Assegna a "three"
                        array[6][idx_seven++] = buffer[i];
                    else if (i == 29) // Assegna a "three"
                        array[7][idx_eight++] = buffer[i];
                    else if (i == 33) // Assegna a "three"
                        array[8][idx_nine++] = buffer[i];
                }
                i++;
            }
            array[0][idx_one] = '\0';
            array[1][idx_two] = '\0';
            array[2][idx_three] = '\0';
            array[3][idx_four] = '\0';
            array[4][idx_five] = '\0';
            array[5][idx_six] = '\0';
            array[6][idx_seven] = '\0';
            array[7][idx_eight] = '\0';
            array[8][idx_nine] = '\0';
        }
        else
        {
            if (!reverse)
            {
                for (int i = 0; i < MAX_LENGTH; i++)
                {
                    reverseArray(array[i], strlen(array[i]));
                }
            }
            reverse = true;
            char *token;
            token = strtok(buffer, " ");
            int arrayMove[4] = {0};

            int index = 0;
            int i = 0;
            while (token != NULL)
            {
                if (i % 2 == 1)
                {
                    arrayMove[index++] = atoi(token);
                }
                i++;
                token = strtok(NULL, " ");
            }
            arrayMove[index] = '\0';
            move(array[arrayMove[1] - 1], array[arrayMove[2] - 1], arrayMove);
            for (int i = 0; i < MAX_LENGTH - 1; i++)
            {
                printf("stack: %s\n", array[i]);
            }
            printf("\n\n");
        }
    }

    char result[MAX_LENGTH];
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        if (array[i][strlen(array[i]) - 1] != '\0')
            result[i] = array[i][strlen(array[i]) - 1];
    }
    printf("stack: %s\n", result);

    return 0;
}
