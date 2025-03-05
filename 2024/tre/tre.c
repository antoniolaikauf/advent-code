// //--------------------------------
// // PRIMA PARTE
// //--------------------------------

// #include <stdio.h>
// #include <string.h>
// #include <stdbool.h>
// #include <stdlib.h>
// #include <ctype.h>

// int main()
// {
//     FILE *file = fopen("small.txt", "r");
//     char buffer[20000];
//     int output = 0;

//     bool checkCorrectSequence = false;

//     while (fgets(buffer, sizeof(buffer), file))
//     {
//         int i = 1;
//         while (buffer[i] != '\0')
//         {
//             // printf("indietro %c mezzo %c avanti %c\n", buffer[i - 1], buffer[i], buffer[i + 1]);
//             // controllo se la frase è mul
//             if ((buffer[i - 1] == 'm') && (buffer[i] == 'u') && (buffer[i + 1] == 'l'))
//             {
//                 /*
//                     si inizia dal numero perchè se tanto non rispetta il pattern mul()
//                     allora non è da contare questa sequenza
//                 */
//                 int indexMul = i + 3;
//                 /*
//                 left serve per cambiare numero da destra asinistra
//                 indexNumber serve per inserire il numero nell'array numberLeft e numberRight
//                 */
//                 bool left = false;
//                 int indexNumber = 0;
//                 char numberLeft[20] = {0};
//                 char numberRight[20] = {0};
//                 /*
//                  ciclo finche o non trovo ) o m essendoc he sono i due parametri principali da controllare
//                 m per mul e ) per mul(num,num)
//                 */

//                 while ((buffer[indexMul] != ')') && (buffer[indexMul] != 'm'))
//                 {
//                     // controllo se numero
//                     if (isdigit(buffer[indexMul]))
//                     {
//                         if (left == false)
//                         {
//                             printf("%c sono a sinista \n", buffer[indexMul]);
//                             numberLeft[indexNumber] = buffer[indexMul];
//                             indexNumber++;
//                         }
//                         else
//                         {
//                             printf("%c sono a destra \n", buffer[indexMul]);
//                             numberRight[indexNumber] = buffer[indexMul];
//                             indexNumber++;
//                         }
//                     }
//                     // si cambia numero da destra a sinistra
//                     else if (buffer[indexMul] == ',')
//                     {
//                         numberLeft[indexNumber] = '\0';
//                         left = true;
//                         indexNumber = 0;
//                     }
//                     // si rompe il ciclo essendo che è nullo
//                     else if (isdigit(buffer[indexMul]) == false)
//                     {
//                         checkCorrectSequence = true;
//                         printf("numero fake\n");
//                         break;
//                     }

//                     indexMul++;
//                 }

//                 numberRight[indexNumber] = '\0';
//                 // se si ha trovato un valore nullo allora non si fa niente
//                 if (checkCorrectSequence == false)
//                 {
//                     printf("numero sinistra %s numero a denstra %s\n", numberLeft, numberRight);
//                     output += atoi(numberRight) * atoi(numberLeft);
//                 }

//                 checkCorrectSequence = false;
//             }
//             i++;
//         }
//     }
//     printf("valore: %i", output);

//     fclose(file);
//     return 0;
// }

//-----------------------------------
// PARTE DUE
//-----------------------------------

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

int checkValue(int index, char value[])
{
    bool checkCorrectSequence = false;
    /*
    left serve per cambiare numero da destra asinistra
    indexNumber serve per inserire il numero nell'array numberLeft e numberRight
    */
    bool left = false;
    int indexNumber = 0;
    char numberLeft[20] = {0};
    char numberRight[20] = {0};
    /*
     ciclo finche o non trovo ) o m essendoc he sono i due parametri principali da controllare
    m per mul e ) per mul(num,num)
    */

    while ((value[index] != ')') && (value[index] != 'm'))
    {
        // controllo se numero
        if (isdigit(value[index]))
        {
            if (left == false)
            {
                printf("%c sono a sinista \n", value[index]);
                numberLeft[indexNumber] = value[index];
                indexNumber++;
            }
            else
            {
                printf("%c sono a destra \n", value[index]);
                numberRight[indexNumber] = value[index];
                indexNumber++;
            }
        }
        // si cambia numero da destra a sinistra
        else if (value[index] == ',')
        {
            numberLeft[indexNumber] = '\0';
            left = true;
            indexNumber = 0;
        }
        // si rompe il ciclo essendo che è nullo
        else if (isdigit(value[index]) == false)
        {
            checkCorrectSequence = true;
            printf("numero fake\n");
            break;
        }

        index++;
    }

    numberRight[indexNumber] = '\0';
    // se si ha trovato un valore nullo allora non si fa niente
    if (checkCorrectSequence == false)
    {
        printf("numero sinistra %s numero a denstra %s\n", numberLeft, numberRight);
        return atoi(numberRight) * atoi(numberLeft);
    }

    return 0;
}

int main()
{
    FILE *file = fopen("input.txt", "r");
    char buffer[30000];
    int output = 0;

    bool checkCorrectSequence = false;

    while (fgets(buffer, sizeof(buffer), file))
    {
        int i = 1;
        bool checkMul = false;
        while (buffer[i] != '\0')
        {
            // printf("indietro %c mezzo %c avanti %c\n", buffer[i - 1], buffer[i], buffer[i + 1]);
            // controllo se la frase è mul  don't()
            if (buffer[i - 1] == 'd' && buffer[i] == 'o' && buffer[i + 1] == '(' && buffer[i + 2] == ')')
            {
                checkMul = false;

                printf("sono dentro con il doooo\n");
                int j = i;
                while (buffer[j] != '\0')
                {
                    // printf("indietro %c mezzo %c avanti %c\n", buffer[i - 1], buffer[i], buffer[i + 1]);
                    if (buffer[j - 1] == 'd' && buffer[j] == 'o' && buffer[j + 1] == 'n' && buffer[j + 2] == '\'' && buffer[j + 3] == 't' && buffer[j + 4] == '(' && buffer[j + 5] == ')')
                    {
                        printf("sono fake\n\n");
                        checkMul = true;
                        break;
                    }
                    // controllo se la frase è mul
                    else if ((buffer[j - 1] == 'm') && (buffer[j] == 'u') && (buffer[j + 1] == 'l'))
                    {
                        /*
                            si inizia dal numero perchè se tanto non rispetta il pattern mul()
                            allora non è da contare questa sequenza
                        */
                        int indexMul = j + 3;
                        output += checkValue(indexMul, buffer);
                        break;
                    }
                    j++;
                }
                i = j;
            }
            else if (buffer[i - 1] == 'd' && buffer[i] == 'o' && buffer[i + 1] == 'n' && buffer[i + 2] == '\'' && buffer[i + 3] == 't' && buffer[i + 4] == '(' && buffer[i + 5] == ')')
            {
                checkMul = true;
                printf("check %i\n", checkMul);
                printf("sono dentro con il doooon't\n");
            }
            else if ((buffer[i - 1] == 'm') && (buffer[i] == 'u') && (buffer[i + 1] == 'l') && (checkMul == false))
            {
                printf("check %i\n", checkMul);
                /*

                    si inizia dal numero perchè se tanto non rispetta il pattern mul()
                    allora non è da contare questa sequenza
                */
                int indexMul = i + 3;
                output += checkValue(indexMul, buffer);
                i = indexMul;
            }
            i++;
        }
    }
    printf("valore: %i", output);

    fclose(file);
    return 0;
}
