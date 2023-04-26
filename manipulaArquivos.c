#include "./headers/manipulaArquivos.h"





void inputFile(char *fileName){
    int x, y, Testes, LIN, COL;
    FILE *file;
    file = fopen(fileName, "r");

    int **matriz;
    int **visited;

    if(file == NULL){
        printf("Couldn't open file!\n");
        return;
    }

    fscanf(file, "%d", &Testes);
    for (int t = 0; t < Testes; t++){
        fscanf(file, "%d %d", &LIN, &COL);
        matriz = malloc (LIN * sizeof (int*)) ;
        matriz[0] = malloc (LIN * COL * sizeof (int)) ;
        visited = malloc (LIN * sizeof (int*)) ;
        visited[0] = malloc (LIN * COL * sizeof (int)) ;
    // percorre a matriz

    // ajusta os demais ponteiros de linhas (i > 0)
        for (int i=1; i < LIN; i++){
            matriz[i] = matriz[0] + i * COL ;
            visited[i] = visited[0] + i * COL ;
        }
        for (int l =0; l < LIN; l++){
        for (int c =0; c < COL; c++){
            int aux;
            fscanf(file, "%d", &aux);
            matriz[l][c] = aux ;
            visited[l][c] = 0;

        }
        }
        for (int l =0; l < LIN; l++){
        for (int c =0; c < COL; c++){

            printf("%d ", visited[l][c]);
        }
        printf("\n");
        }
        printf("\n");
        free (matriz[0]) ;
        free (matriz) ;
        free (visited[0]) ;
        free (visited) ;
    }
    fclose(file);
};