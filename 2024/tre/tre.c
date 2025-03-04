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
            // controllo se la frase è mul
            if ((buffer[i - 1] == 'm') && (buffer[i] == 'u') && (buffer[i + 1] == 'l'))
            {
                /*
                    si inizia dal numero perchè se tanto non rispetta il pattern mul()
                    allora non è da contare questa sequenza
                */
                int indexMul = i + 3;
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
                
                while ((buffer[indexMul] != ')') && (buffer[indexMul] != 'm'))
                {
                    // controllo se numero
                    if (isdigit(buffer[indexMul]))
                    {
                        if (left == false)
                        {
                            printf("%c sono a sinista \n", buffer[indexMul]);
                            numberLeft[indexNumber] = buffer[indexMul];
                            indexNumber++;
                        }
                        else
                        {
                            printf("%c sono a destra \n", buffer[indexMul]);
                            numberRight[indexNumber] = buffer[indexMul];
                            indexNumber++;
                        }
                    }
                    // si cambia numero da destra a sinistra
                    else if (buffer[indexMul] == ',')
                    {
                        numberLeft[indexNumber] = '\0';
                        left = true;
                        indexNumber = 0;
                    }
                    // si rompe il ciclo essendo che è nullo
                    else if (isdigit(buffer[indexMul]) == false)
                    {
                        checkCorrectSequence = true;
                        printf("numero fake\n");
                        break;
                    }

                    indexMul++;
                }

                numberRight[indexNumber] = '\0';
                // se si ha trovato un valore nullo allora non si fa niente
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