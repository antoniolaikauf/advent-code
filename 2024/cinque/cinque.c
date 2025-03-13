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
//     FILE *file = fopen("input.txt", "r");

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
//                 if (strlen(coppia) == 4)
//                     break;

//                 // ciclo su l'array delle combinazioni per vedere se la coppia è presente
//                 for (int indexCheck = 0; indexCheck < indexCombination; indexCheck++)
//                 {
//                     if (strcmp(coppia, combinazioni[indexCheck]) == 0)
//                     {
//                         check++;
//                         printf("sono uguale %s -> %s\n", coppia, combinazioni[indexCheck]);
//                         // printf("Coppia generata: %s\n", coppia);
//                         printf("buffer %s:                         %i\n", buffer, strcmp(coppia, combinazioni[indexCheck]) == 0);
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

//------------------------------
// PARTE DUE sbagliata 
//------------------------------

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
    FILE *file = fopen("small.txt", "r");

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
                if (strlen(coppia) != 5)
                {
                    break;
                }

                // ciclo su l'array delle combinazioni per vedere se la coppia è presente
                for (int indexCheck = 0; indexCheck < indexCombination; indexCheck++)
                {

                    if (strcmp(coppia, combinazioni[indexCheck]) == 0)
                    {
                        check++;
                        // printf("Coppia generata: %s\n", coppia);
                        printf("buffer %s:                         %i\n", buffer, strcmp(coppia, combinazioni[indexCheck]) == 0);
                    }
                    else
                    {
                        bool trovata = false;
                        for (int indexLeft = 0; indexLeft < (indexCombination - 1); indexLeft++)
                        {
                            if (trovata)
                            {
                                break;
                            }
                            char valoreLeft[5] = {0};
                            strcpy(valoreLeft, combinazioni[indexLeft]);
                            printf("lato destro: %s\n", valoreLeft);
                            char latoDestro[5] = {0};
                            for (int j = 0; j < (indexCombination - 1); j++)
                            {
                                if (i + 6 < strlen(buffer))
                                {
                                    latoDestro[0] = valoreLeft[3];
                                    latoDestro[1] = valoreLeft[4];
                                    latoDestro[2] = ',';
                                    latoDestro[3] = buffer[i + 6];
                                    latoDestro[4] = buffer[i + 7];
                                    latoDestro[5] = '\0';
                                    // printf("lato destro: %s\n", latoDestro);
                                }

                                if ((strcmp(latoDestro, combinazioni[indexCheck]) == 0))
                                {
                                    trovata = true;
                                    printf("TROVATA LA COPPIA\n");
                                    printf("coppia sinistra %s   coppia detsra %s\n", valoreLeft, latoDestro);
                                    break;
                                }
                            }
                        }
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
            else
            {
                printf("buffer sbagliato %s\n", buffer);
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


/*
61,13,29

prima bisognerebbe controllare se se 61,13 esiste allora è 13 29 da aggiornare 

allora devi fare un ciclo for per trovare tutte le combinazioni con 29 una volta trovate devi verificare che 61 e il nuovo numero esiste 
se esiste hai trovato la combinazione giusta 

*/