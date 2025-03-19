#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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

// si mettono i caratteri delle coppie
void costruzioneCoppia(char *coppia, int index, char *buffer)
{
    int IndexNumber = 0;
    for (; IndexNumber < 5; IndexNumber++)
    {
        coppia[IndexNumber] = buffer[index + IndexNumber];
    }
    coppia[IndexNumber] = '\0'; // Termina la stringa
}

int main()
{
    FILE *file = fopen("input.txt", "r");

    if (file == NULL)
        return 0;

    char buffer[500];
    char combinazioni[2000][6] = {0};
    bool changeSolution = false;
    int indexCombination = 0;
    int indexCoppie = 0;
    int output = 0;

    while (fgets(buffer, sizeof(buffer), file))
    {
        trimwhitespace(buffer);

        if (changeSolution)
        {
            int check = 0;
            char coppia[6] = {0}; // Array per salvare le coppie
            printf("combinazione %s\n", buffer);

            for (int i = 0; i < strlen(buffer) - 1; i += 3)
            {
                // creazione coppia
                costruzioneCoppia(coppia, i, buffer);

                // se coppia diversa da 4 allora non è una coppia
                if (strlen(coppia) == 4)
                    break;

                // ciclo su l'array delle combinazioni per vedere se la coppia è presente
                for (int indexCheck = 0; indexCheck < indexCombination; indexCheck++)
                {
                    if (strcmp(coppia, combinazioni[indexCheck]) == 0)
                    {
                        check++;
                        printf("sono uguale %s -> %s\n", coppia, combinazioni[indexCheck]);
                        // printf("Coppia generata: %s\n", coppia);
                        printf("buffer %s:                         %i\n", buffer, strcmp(coppia, combinazioni[indexCheck]) == 0);
                    }
                }
            }
            // si controlla se le coppie esistono nelle possibili combinazioni
            if ((int)(strlen(buffer) / 3) == check)
            {
                char number[3] = {buffer[(strlen(buffer) / 2) - 1], buffer[(strlen(buffer) / 2)], '\0'};
                output += atoi(number);
                printf("%s\n\n", number);
            }
        }
        else
        {
            // si cambia il parametro | con , per rendere il più possibile uguale alla sequenza
            buffer[2] = ',';
            // copiato la combinazione
            strcpy(combinazioni[indexCombination], buffer);
            printf("combinazione: %s\n", combinazioni[indexCombination]);
            indexCombination++;
        }
        // si inizia a contollare le sequenze
        if (buffer[0] == 13)
        {

            changeSolution = true;
            printf("ora le combinazioni");
        }
    }

    printf("%i\n", output);
    return 0;
}

//------------------------------
// PARTE DUE sbagliata
//------------------------------


// #include <stdio.h>
// #include <stdbool.h>
// #include <string.h>
// #include <stdlib.h>
// #include <ctype.h>

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

// // si mettono i caratteri delle coppie
// void costruzioneCoppia(char *coppia, int index, char *buffer)
// {
//     int IndexNumber = 0;
//     for (; IndexNumber < 5; IndexNumber++)
//     {
//         coppia[IndexNumber] = buffer[index + IndexNumber];
//     }
//     coppia[IndexNumber] = '\0'; // Termina la stringa
// }

// int main()
// {
//     FILE *file = fopen("small.txt", "r");

//     if (file == NULL)
//         return 0;

//     char buffer[500];
//     char combinazioni[2000][6] = {0};
//     bool changeSolution = false;
//     int indexCombination = 0;
//     int indexCoppie = 0;
//     int output = 0;

//     while (fgets(buffer, sizeof(buffer), file))
//     {
//         trimwhitespace(buffer);

//         if (changeSolution)
//         {
//             int check = 0;
//             char coppia[6] = {0}; // Array per salvare le coppie
//             printf("combinazione %s\n", buffer);

//             for (int i = 0; i < strlen(buffer) - 1; i += 3)
//             {
//                 // creazione coppia
//                 costruzioneCoppia(coppia, i, buffer);

//                 // se coppia diversa da 4 allora non è una coppia
//                 if (strlen(coppia) != 5)
//                 {
//                     break;
//                 }

//                 bool checkCoppia = false;
//                 // ciclo su l'array delle combinazioni per vedere se la coppia è presente
//                 for (int indexCheck = 0; indexCheck < indexCombination; indexCheck++)
//                 {

//                     if ((strcmp(coppia, combinazioni[indexCheck]) == 0))
//                     {
//                         checkCoppia = true;
//                         check++;
//                         // printf("Coppia generata: %s\n", coppia);
//                         printf("buffer %s:                         %i\n", buffer, strcmp(coppia, combinazioni[indexCheck]) == 0);
//                     }
//                 }

//                 // si trova la coppia sbagliata
//                 if (checkCoppia == false)
//                 {
//                     char value1[6] = {coppia[0], coppia[1], ',', ' ', ' ', '\0'};
//                     char value2[6] = {' ', ' ', ',', coppia[3], coppia[4], '\0'};
//                     for (int j = 0; j < indexCombination; j++)
//                     {
//                         value1[3] = combinazioni[j][3];
//                         value1[4] = combinazioni[j][4];
//                         value2[0] = combinazioni[j][0];
//                         value2[1] = combinazioni[j][1];

//                         for (int h = 0; h < indexCombination; h++)
//                         {

//                             if (strcmp(value1, combinazioni[h]) == 0)
//                             {
//                                 printf("coppia  sinistra %s\n", value1);
//                                 break;
//                             }
//                             else if ((strcmp(value2, combinazioni[h]) == 0))
//                             {
//                                 printf("coppia  value 2 %s\n", value2);
//                                 break;
//                             }
//                         }
//                         char coppiaToCheck[6] = {coppia[0], coppia[1], ',', value2[0], value2[1], '\0'};
//                         // printf("coppia            %c%c%c%c\n", coppiaToCheck[0], coppiaToCheck[1], coppiaToCheck[3], coppiaToCheck[4]);
//                         for (int u = 0; u < indexCombination; u++)
//                         {
//                             if (strcmp(coppiaToCheck, combinazioni[u]) == 0)
//                             {
//                                 break;
//                             }
//                         }

//                         // combinazioni[j];
//                     }
//                 }
//             }
//             // si controlla se le coppie esistono nelle possibili combinazioni
//             if ((int)(strlen(buffer) / 3) == check)
//             {
//                 char number[3] = {buffer[(strlen(buffer) / 2) - 1], buffer[(strlen(buffer) / 2)], '\0'};
//                 output += atoi(number);
//                 printf("%s\n\n", number);
//             }
//             else
//             {
//                 printf("buffer sbagliato %s\n", buffer);
//             }
//         }
//         else
//         {
//             // si cambia il parametro | con , per rendere il più possibile uguale alla sequenza
//             buffer[2] = ',';
//             // copiato la combinazione
//             strcpy(combinazioni[indexCombination], buffer);
//             printf("combinazione: %s\n", combinazioni[indexCombination]);
//             indexCombination++;
//         }
//         // si inizia a contollare le sequenze
//         if (buffer[0] == 13)
//         {

//             changeSolution = true;
//             printf("ora le combinazioni");
//         }
//     }

//     printf("%i\n", output);
//     return 0;
// }
/*
61,13,29

prima bisognerebbe controllare se se 61,13 esiste allora è 13 29 da aggiornare

allora devi fare un ciclo for per trovare tutte le combinazioni con 29
ps non è detto che una parte della coppia sia corretta 
una volta trovate devi verificare che 61 e il nuovo numero esiste
se esiste hai trovato la combinazione giusta

*/