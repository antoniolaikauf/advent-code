#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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

int main()
{
    FILE *file = fopen("input.txt", "r");
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

    char object[] = "#";

    bool orizzontal = false;
    bool vertical = false;

    int heightMap = 0;

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
                positionGuard[0] = idxObject;
                positionGuard[1] = heightMap;
                printf("%c --> %i in ascisse --> %i in ordinate\n", buffer[idxObject], positionGuard[0], positionGuard[1]);
            }
        }
        heightMap++;
    }

    fclose(file);

    printf("\n");

    // posizione visistata
    int visited[300][300] = {0};
    visited[positionGuard[1]][positionGuard[0]] = 1;

    int output = 0;

    // ciclo fino a quando la guardia non esce dai suoi confini
    while ((positionGuard[0] > 0 && positionGuard[0] < (strlen(buffer) - 1)) && (positionGuard[1] > 0 && positionGuard[1] < heightMap))
    {

        /*
        ciclo per controllare se guardia ha raggiunto la posizione
        messo un controllo anche orizzontal e vertical essendo che se la guardia va lateralmente deve controllare solo verticalmente e quindi
        su asse delle ascisse
        es. magari la guardia si sta muovendo verticalmente e quindi cambia l'asse delle ordinate
        es. 8-3, 8-4, 8-5
        ora fa i controlli e se controlla cambiando anche l'asse delle ascisse si rischierebbe di trovare una posizione che non centra
        es 7-5 anche se si stava andando in verticale, e quindi per evitare questo messo un controllo in piu
        questo controllo c'è anche per l'altro asse
        */
        for (int i = 0; i < index; i++)
        {
            if (orizzontal)
            {
                if (place[i][0] == positionGuard[0] - 1 && place[i][1] == positionGuard[1])
                {
                    printf("entro sinistra --> %i in ascisse --> %i in ordinate\n", positionGuard[0], positionGuard[1]);
                    printf("sinistra\n");
                    changePath(guard);
                    break;
                }
                else if (place[i][0] == positionGuard[0] + 1 && place[i][1] == positionGuard[1])
                {
                    printf("entro destra --> %i in ascisse --> %i in ordinate\n", positionGuard[0], positionGuard[1]);
                    printf("destra\n");
                    changePath(guard);
                    break;
                }
            }
            else if (vertical)
            {

                if (place[i][0] == positionGuard[0] && place[i][1] == positionGuard[1] - 1)
                {
                    printf("entro su --> %i in ascisse --> %i in ordinate\n", positionGuard[0], positionGuard[1]);
                    printf("su\n");
                    changePath(guard);
                    break;
                }
                else if (place[i][0] == positionGuard[0] && place[i][1] == positionGuard[1] + 1)
                {
                    printf("entro giu --> %i in ascisse --> %i in ordinate\n", positionGuard[0], positionGuard[1]);
                    printf("gius\n");
                    changePath(guard);
                    break;
                }
            }
        }
        /*
        qua si modificano le variabili vertical e orizontal cosi che se si va orizzontalmente si controlla solo
        le condizioni (sopra citate) con positionGuard[0] + 1 e -1 che sarebbe l'asse orizontale,
        se si andasse verticalmente si controllerebbe le condizioni con positionGuard[1] + 1 e -1
        essendo che si deve prevedere se la guardia farebbe quella mossa incontrerebbe un ostacolo se si si cambia direzzione se no si continua
        */

        // si diminuisce essendo che si sale
        if (guard[0] == '^')
        {
            vertical = true;
            orizzontal = false;
            positionGuard[1]--;
            printf("si va su\n");
        }
        // si aumenta essendo che si va a destra
        else if (guard[0] == '>')
        {
            vertical = false;
            orizzontal = true;
            positionGuard[0]++;
            printf("si va destra\n");
        }
        // si dimnuisce essendo che va a sinistra
        else if (guard[0] == '<')
        {
            vertical = false;
            orizzontal = true;
            printf("si va sinistra\n");
            positionGuard[0]--;
        }
        // si aumenta essendo che si scende
        else if (guard[0] == 'v')
        {
            vertical = true;
            orizzontal = false;
            printf("si va giu\n");
            positionGuard[1]++;
        }

        // si controlla che la guardia non abbia gia percorso le cordinate
        if (visited[positionGuard[1]][positionGuard[0]] != 1)
        {
            output++;
        }

        visited[positionGuard[1]][positionGuard[0]] = 1; // si setta la cordinata della guardia per far vedere che è gia passata
        printf("DOPOO --> %i in ascisse --> %i in ordinate\n", positionGuard[0], positionGuard[1]);
    }

    printf("output --> %i\n", output);
    return 0;
}