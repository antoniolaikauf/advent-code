
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// funzione per rimuovere lo spazio che non si vede
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

// int main()
// {
//     FILE *file = fopen("small.txt", "r");
//     if (file == NULL)
//         return 0;

//     int score = 0;
//     char buffer[250];
//     /*
//       se si mette una lunghezza minore di quella
//      della riga del file da leggere, il rimanente verrà letto dopo e quindi ci saranno più cicli
//      */
//     int somma = 0;

//     /*
// aversario
// A sasso
// b carta
// c forbici

// io
// x roccia
// y carta
// z forbici
// */

//     const char combinazioni[][3][5] = {
//         // loss me
//         {
//             "B X",
//             "C Y",
//             "A Z",
//         },
//         // draw
//         {
//             "A X",
//             "B Y",
//             "C Z",
//         },
//         // win me
//         {
//             "C X",
//             "A Y",
//             "B Z",
//         },
//     };

//     int count = 0;
//     while (fgets(buffer, sizeof(buffer), file))
//     {
//         buffer[strcspn(buffer, "\n")] = 0; // Rimuovere /n
//         trimwhitespace(buffer);            // rimuovere spazi vuoti che non si vedono
//         printf("Linea letta: '%s'\n", buffer);

//         for (int i = 0; i < 3; i++)
//         {
//             for (int j = 0; j < 3; j++)
//             {
//                 if (strcmp(buffer, combinazioni[i][j]) == 0)
//                 {
//                     switch (i)
//                     {
//                     case 0:
//                         // se entra in primo array persa
//                         score = 0;
//                         break;
//                     case 1:
//                         // se entra in secondo array pareggiata
//                         score = 3;
//                         break;
//                     case 2:
//                         // se entra in terzo array vinta
//                         score = 6;
//                         break;
//                     default:
//                         break;
//                     }
//                     //(j + 1) sarebbe rock + 1 papaer + 2 forbici + 3
//                     // e quindi si mette in array in ordine cosi da fare questa implementazone
//                     somma += score + (j + 1);
//                 }
//             }
//         }
//     }
//     printf("Score totale: %d\n", somma);
//     fclose(file);

//     return 0;
// }

//== compara se i due puntatatori sono uguali e non il valore

//---------------------------------
// SECONDA PARTE
//---------------------------------

int scelta_mossa(int mossa)
{
    switch (mossa)
    {
    case 0:
        return 3;
        break;
    case 1:
        return 1;
        break;
    case 2:
        return 2;
        break;
    }
    return 0;
}

int main()
{
    FILE *file = fopen("input.txt", "r");
    if (file == NULL)
        return 0;

    int score = 0;
    char buffer[250];
    /*
      se si mette una lunghezza minore di quella
     della riga del file da leggere, il rimanente verrà letto dopo e quindi ci saranno più cicli
     */
    int count = 0;
    int somma = 0;

    // aversario
    // A sasso
    // b carta
    // c forbici

    // io
    // x roccia
    // y carta
    // z forbici
    // */
    /*
    parte due stare attenti alle combinazioni dentro array (il loro ordine )
    */
    const char combinazioni[][3][5] = {
        // loss me
        {
            "A X",
            "B X",
            "C X",
        },
        // draw
        {
            "C Y",
            "A Y",
            "B Y",
        },
        // win me
        {
            "B Z",
            "C Z",
            "A Z",
        },
    };

    while (fgets(buffer, sizeof(buffer), file))
    {
        buffer[strcspn(buffer, "\n")] = 0; // Rimuovere /n
        trimwhitespace(buffer);            // rimuovere spazi vuoti che non si vedono
        printf("Linea letta: '%s'\n", buffer);

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (strcmp(buffer, combinazioni[i][j]) == 0)
                {
                    switch (i)
                    {
                    case 0:
                        // se entra in primo array persa
                        score = 0;
                        break;
                    case 1:
                        // se entra in secondo array pareggiata
                        score = 3;
                        break;
                    case 2:
                        // se entra in terzo array vinta
                        score = 6;
                        break;
                    default:
                        break;
                    }
                    //(j + 1) sarebbe rock + 1 papaer + 2 forbici + 3
                    // e quindi si mette in array in ordine cosi da fare questa implementazone
                    somma += score + scelta_mossa(j);
                    printf("%d\n", somma);
                }
            }
        }
    }
    printf("Score totale: %d\n", somma);
    fclose(file);

    return 0;
}