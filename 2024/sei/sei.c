//-----------------------------------
// PARTE UNO
//-----------------------------------

// #include <stdio.h>
// #include <stdbool.h>
// #include <string.h>
// #include <stdlib.h>
// #include <ctype.h>

// // funzione per cambiare sentiero
// void changePath(char path[])
// {
//     if (path[0] == '^')
//         path[0] = '>';
//     else if (path[0] == '>')
//         path[0] = 'v';
//     else if (path[0] == '<')
//         path[0] = '^';
//     else if (path[0] == 'v')
//         path[0] = '<';
// }

// int main()
// {
//     FILE *file = fopen("input.txt", "r");
//     if (!file)
//     {
//         perror("Failed to open file");
//         return 1;
//     }

//     char buffer[250];

//     int index = 0;
//     int place[1500][3] = {0}; // combinazioni

//     int positionGuard[2] = {0, 0}; // posizione guardia
//     char guard[2] = {0};           // segno guardia

//     char object[] = "#";

//     bool orizzontal = false;
//     bool vertical = false;

//     int heightMap = 0;

//     while (fgets(buffer, sizeof(buffer), file))
//     {
//         for (int idxObject = 0; idxObject < (strlen(buffer) - 1); idxObject++)
//         {
//             // salvataggio della posizione dell'oggetto
//             if (buffer[idxObject] == object[0])
//             {
//                 place[index][0] = idxObject;
//                 place[index][1] = heightMap;
//                 printf("%c --> %i in ascisse --> %i in ordinate\n", buffer[idxObject], place[index][0], place[index][1]);
//                 index++;
//             }
//             // salvataggio della posizione della guardia
//             else if (buffer[idxObject] == '^' || buffer[idxObject] == 'v' ||
//                      buffer[idxObject] == '>' || buffer[idxObject] == '<')
//             {
//                 guard[0] = buffer[idxObject];
//                 positionGuard[0] = idxObject;
//                 positionGuard[1] = heightMap;
//                 printf("%c --> %i in ascisse --> %i in ordinate\n", buffer[idxObject], positionGuard[0], positionGuard[1]);
//             }
//         }
//         heightMap++;
//     }

//     fclose(file);

//     printf("\n");

//     // posizione visistata
//     int visited[300][300] = {0};
//     visited[positionGuard[1]][positionGuard[0]] = 1;

//     int output = 0;

//     // ciclo fino a quando la guardia non esce dai suoi confini
//     while ((positionGuard[0] > 0 && positionGuard[0] < (strlen(buffer) - 1)) && (positionGuard[1] > 0 && positionGuard[1] < heightMap))
//     {

//         /*
//         ciclo per controllare se guardia ha raggiunto la posizione
//         messo un controllo anche orizzontal e vertical essendo che se la guardia va lateralmente deve controllare solo verticalmente e quindi
//         su asse delle ascisse
//         es. magari la guardia si sta muovendo verticalmente e quindi cambia l'asse delle ordinate
//         es. 8-3, 8-4, 8-5
//         ora fa i controlli e se controlla cambiando anche l'asse delle ascisse si rischierebbe di trovare una posizione che non centra
//         es 7-5 anche se si stava andando in verticale, e quindi per evitare questo messo un controllo in piu
//         questo controllo c'è anche per l'altro asse
//         */
//         for (int i = 0; i < index; i++)
//         {
//             if (orizzontal)
//             {
//                 if (place[i][0] == positionGuard[0] - 1 && place[i][1] == positionGuard[1])
//                 {
//                     printf("entro sinistra --> %i in ascisse --> %i in ordinate\n", positionGuard[0], positionGuard[1]);
//                     printf("sinistra\n");
//                     changePath(guard);
//                     break;
//                 }
//                 else if (place[i][0] == positionGuard[0] + 1 && place[i][1] == positionGuard[1])
//                 {
//                     printf("entro destra --> %i in ascisse --> %i in ordinate\n", positionGuard[0], positionGuard[1]);
//                     printf("destra\n");
//                     changePath(guard);
//                     break;
//                 }
//             }
//             else if (vertical)
//             {

//                 if (place[i][0] == positionGuard[0] && place[i][1] == positionGuard[1] - 1)
//                 {
//                     printf("entro su --> %i in ascisse --> %i in ordinate\n", positionGuard[0], positionGuard[1]);
//                     printf("su\n");
//                     changePath(guard);
//                     break;
//                 }
//                 else if (place[i][0] == positionGuard[0] && place[i][1] == positionGuard[1] + 1)
//                 {
//                     printf("entro giu --> %i in ascisse --> %i in ordinate\n", positionGuard[0], positionGuard[1]);
//                     printf("gius\n");
//                     changePath(guard);
//                     break;
//                 }
//             }
//         }
//         /*
//         qua si modificano le variabili vertical e orizontal cosi che se si va orizzontalmente si controlla solo
//         le condizioni (sopra citate) con positionGuard[0] + 1 e -1 che sarebbe l'asse orizontale,
//         se si andasse verticalmente si controllerebbe le condizioni con positionGuard[1] + 1 e -1
//         essendo che si deve prevedere se la guardia farebbe quella mossa incontrerebbe un ostacolo se si si cambia direzzione se no si continua
//         */

//         // si diminuisce essendo che si sale
//         if (guard[0] == '^')
//         {
//             vertical = true;
//             orizzontal = false;
//             positionGuard[1]--;
//             printf("si va su\n");
//         }
//         // si aumenta essendo che si va a destra
//         else if (guard[0] == '>')
//         {
//             vertical = false;
//             orizzontal = true;
//             positionGuard[0]++;
//             printf("si va destra\n");
//         }
//         // si dimnuisce essendo che va a sinistra
//         else if (guard[0] == '<')
//         {
//             vertical = false;
//             orizzontal = true;
//             printf("si va sinistra\n");
//             positionGuard[0]--;
//         }
//         // si aumenta essendo che si scende
//         else if (guard[0] == 'v')
//         {
//             vertical = true;
//             orizzontal = false;
//             printf("si va giu\n");
//             positionGuard[1]++;
//         }

//         // si controlla che la guardia non abbia gia percorso le cordinate
//         if (visited[positionGuard[1]][positionGuard[0]] != 1)
//         {
//             output++;
//         }

//         visited[positionGuard[1]][positionGuard[0]] = 1; // si setta la cordinata della guardia per far vedere che è gia passata
//         printf("DOPOO --> %i in ascisse --> %i in ordinate\n", positionGuard[0], positionGuard[1]);
//     }

//     printf("output --> %i\n", output);
//     return 0;
// }

//---------------------------------------
// PARTE DUE
//---------------------------------------

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MATRIX 100
// funzione per cambiare sentiero
void changePath(char path[])
{
    if (path[0] == '^')
        path[0] = '>';
    else if (path[0] == '>')
        path[0] = 'v';
    else if (path[0] == '<')
        path[0] = '^';
    else if (path[0] == 'v')
        path[0] = '<';
}

/*
qua si modificano le variabili vertical e orizontal cosi che se si va orizzontalmente si controlla solo
le condizioni (sopra citate) con positionGuard[0] + 1 e -1 che sarebbe l'asse orizontale,
se si andasse verticalmente si controllerebbe le condizioni con positionGuard[1] + 1 e -1
essendo che si deve prevedere se la guardia farebbe quella mossa incontrerebbe un ostacolo se si si cambia direzzione se no si continua
*/

// si diminuisce essendo che si sale

void position(char guardia[], int posizione[], bool *verticale, bool *orizzonatle)
{

    if (guardia[0] == '^')
    {
        *verticale = true;
        *orizzonatle = false;
        posizione[1]--;
    }
    // si aumenta essendo che si va a destra
    else if (guardia[0] == '>')
    {
        *verticale = false;
        *orizzonatle = true;
        posizione[0]++;
        // printf("si va destra\n");
    }
    // si dimnuisce essendo che va a sinistra
    else if (guardia[0] == '<')
    {
        *verticale = false;
        *orizzonatle = true;
        // printf("si va sinistra\n");
        posizione[0]--;
    }
    // si aumenta essendo che si scende
    else if (guardia[0] == 'v')
    {
        *verticale = true;
        *orizzonatle = false;
        // printf("si va giu\n");
        posizione[1]++;
    }
}

void move(int indice, bool verticale, bool orizzontale, int posto[][3], int posizione[], char guardia[])
{
    for (int i = 0; i < indice; i++)
    {
        if (orizzontale)
        {
            if (posto[i][0] == posizione[0] - 1 && posto[i][1] == posizione[1])
            {
                // printf("entro sinistra --> %i in ascisse --> %i in ordinate\n", posizione[0], posizione[1]);
                changePath(guardia);
                // printf("%c sinistra\n", guardia[0]);
                break;
            }
            else if (posto[i][0] == posizione[0] + 1 && posto[i][1] == posizione[1])
            {
                // printf("entro destra --> %i in ascisse --> %i in ordinate\n", posizione[0], posizione[1]);
                changePath(guardia);
                // printf("%c destra\n", guardia[0]);
                break;
            }
        }
        else if (verticale)
        {

            if (posto[i][0] == posizione[0] && posto[i][1] == posizione[1] - 1)
            {
                // printf("entro su --> %i in ascisse --> %i in ordinate\n", posizione[0], posizione[1]);
                changePath(guardia);
                // printf("%c suu\n", guardia[0]);
                break;
            }
            else if (posto[i][0] == posizione[0] && posto[i][1] == posizione[1] + 1)
            {
                // printf("entro giu --> %i in ascisse --> %i in ordinate\n", posizione[0], posizione[1]);
                changePath(guardia);
                // printf("%c gius\n", guardia[0]);
                break;
            }
        }
    }
}

bool check(int positionGuardX, int positionGuardY, int positionGuardX2, int positionGuardY2, bool verticale, bool orizzonatele)
{

    // printf("guardia posizione--> %i in ascisse --> %i in ordinate\n", positionGuardX, positionGuardY);
    // printf("guardia posizione seconda --> %i in ascisse --> %i in ordinate\n", positionGuardX2, positionGuardY2);
    // 4 -6 4 -5 orizzontale
    // if (orizzonatele)
    // {
        if (positionGuardX == positionGuardX2 - 1 && positionGuardY == positionGuardY2)
        {
            printf("sinistra\n");
            return true;
        }
        else if (positionGuardX == positionGuardX2 - 1 && positionGuardY == positionGuardY2)
        {
            printf("destra\n");
            return true;
        }
    // }
    // else if (verticale)
    // {

        if (positionGuardX == positionGuardX2 && positionGuardY == positionGuardY2 - 1)
        {
            printf("su\n");
            return true;
        }
        else if (positionGuardX == positionGuardX2 && positionGuardY == positionGuardY2 + 1)
        {
            printf("giu\n");

            return true;
        }
    // }

    return false;
}

int main()
{
    FILE *file = fopen("small.txt", "r");
    if (!file)
    {
        perror("Failed to open file");
        return 1;
    }

    char buffer[250];

    int index = 0;
    int place[1500][3] = {0}; // combinazioni

    int positionGuard[2] = {0, 0}; // posizione guardia
    char guard[2] = {0};           // segno guardia
    int stratPositionGuard[2] = {0, 0};
    int secondPositionGuard[2] = {0, 0};
    char startGuard[2] = {0}; // seconda posizione della guardia

    char object[] = "#";

    bool orizzontal = false;
    bool vertical = false;

    int heightMap = 0;
    int idxObject = 0;

    while (fgets(buffer, sizeof(buffer), file))
    {
        for (int idxObject = 0; idxObject < (strlen(buffer) - 1); idxObject++)
        {
            // salvataggio della posizione dell'oggetto
            if (buffer[idxObject] == object[0])
            {
                place[index][0] = idxObject;
                place[index][1] = heightMap;
                printf("%c --> %i in ascisse --> %i in ordinate\n", buffer[idxObject], place[index][0], place[index][1]);
                index++;
            }
            // salvataggio della posizione della guardia
            else if (buffer[idxObject] == '^' || buffer[idxObject] == 'v' ||
                     buffer[idxObject] == '>' || buffer[idxObject] == '<')
            {
                guard[0] = buffer[idxObject];
                startGuard[0] = buffer[idxObject];
                positionGuard[0] = idxObject;
                positionGuard[1] = heightMap;

                stratPositionGuard[0] = idxObject;
                stratPositionGuard[1] = heightMap;

                if (buffer[idxObject] == '^')
                {
                    secondPositionGuard[0] = idxObject;
                    secondPositionGuard[1] = heightMap - 1;
                }
                else if (buffer[idxObject] == '>')
                {
                    secondPositionGuard[0] = idxObject + 1;
                    secondPositionGuard[1] = heightMap;
                }
                else if (buffer[idxObject] == '<')
                {
                    secondPositionGuard[0] = idxObject - 1;
                    secondPositionGuard[1] = heightMap;
                }
                else if (buffer[idxObject] == 'v')
                {
                    secondPositionGuard[0] = idxObject;
                    secondPositionGuard[1] = heightMap + 1;
                }
                // printf("guardia seonda posizione  %c --> %i in ascisse --> %i in ordinate\n", buffer[idxObject], secondPositionGuard[0], secondPositionGuard[1]);
            }
        }
        heightMap++;
    }

    fclose(file);

    printf("\n");

    // posizione visistata
    int visited[MATRIX][MATRIX] = {0};
    visited[positionGuard[1]][positionGuard[0]] = 1;

    int output = 0;

    // ciclo fino a quando la guardia non esce dai suoi confini
    while ((positionGuard[0] > 0 && positionGuard[0] < (strlen(buffer) - 1)) && (positionGuard[1] > 0 && positionGuard[1] < heightMap))
    {

        move(index, vertical, orizzontal, place, positionGuard, guard);

        position(guard, positionGuard, &vertical, &orizzontal);

        output++;
        // si controlla che la guardia non abbia gia percorso le cordinate

        visited[positionGuard[1]][positionGuard[0]] = 1; // si setta la cordinata della guardia per far vedere che è gia passata
        // printf("DOPOO --> %i in ascisse --> %i in ordinate\n", positionGuard[0], positionGuard[1]);
    }

    int doppioni = 0;
    for (int idxtr = 0; idxtr < output; idxtr++)
    {
        int row = heightMap;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < strlen(buffer); j++)
            {
                if (visited[i][j] == 1)
                {
                    place[index + 1][0] = i;
                    place[index + 1][1] = j;
                    guard[0] = startGuard[0];

                    positionGuard[0] = stratPositionGuard[0];
                    positionGuard[1] = stratPositionGuard[1];

                    bool orizzontal = false;
                    bool vertical = false;

                    while ((positionGuard[0] > 0 && positionGuard[0] < (strlen(buffer) - 1)) && (positionGuard[1] > 0 && positionGuard[1] < heightMap))
                    {

                        move(index, vertical, orizzontal, place, positionGuard, guard);
                        position(guard, positionGuard, &vertical, &orizzontal);

                        if (stratPositionGuard[0] == positionGuard[0] && stratPositionGuard[1] == positionGuard[1])
                        {

                            // bisognerebbe calcolare anche la sua prossima direzzione essendo che il if sopra controlla se l'attuale posizione è arrivata
                            // al punto da dove è partita la guardia ma non è abbastanza bisogna vedere se la sua prossima mossa sarebbe stata la sua seconda mossa
                            // e quindi anche controllare la sua direzione ^ v > <

                            // non so come fare questa parte di controllare dove deve andare la guardia e confrontare che la sua mossa successiva è quella della 
                            // startGuard cosi che oltre a confrontare che la guardia è arrivata al suo punto di partenza confronta anche la sua mossa successiva che 
                            // con le cordinate è abbastanza facile ma con le ^ v > < 
                            // if (guard[0] == '<')
                            // {
                            //     vertical = true;
                            //     orizzontal = false;
                            // }
                            // // // si aumenta essendo che si va a destra
                            // // else if (guard[0] == '>')
                            // // {
                            // //     vertical = false;
                            // //     orizzontal = true;
                            // //     // printf("si va destra\n");
                            // // }
                            // // // si dimnuisce essendo che va a sinistra
                            // // else if (guard[0] == '^')
                            // // {
                            // //     vertical = false;
                            // //     orizzontal = true;
                            // //     // printf("si va sinistra\n");
                            // // }
                            // // // si aumenta essendo che si scende
                            // // else if (guard[0] == 'v')
                            // // {
                            // //     vertical = true;
                            // //     orizzontal = false;
                            // //     // printf("si va giu\n");
                            // // }

                            printf("asse--> %i in ascisse --> %i in ordinate --> verso %c\n", orizzontal, vertical, guard[0]);
                            if (check(positionGuard[0], positionGuard[1], secondPositionGuard[0], secondPositionGuard[1], vertical, orizzontal))
                            {
                                printf("guardia posizione--> %i in ascisse --> %i in ordinate\n", positionGuard[0], positionGuard[1]);
                                printf("guardia posizione seconda --> %i in ascisse --> %i in ordinate\n", secondPositionGuard[0], secondPositionGuard[1]);
                                doppioni++;
                                break;
                            }
                        }

                        // si controlla che la guardia non abbia gia percorso le cordinate
                    }
                }
            }
        }
    }
    printf("doppioni --> %i\n", doppioni);
    return 0;
}

// NON FINITO