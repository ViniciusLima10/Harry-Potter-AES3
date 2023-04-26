#include "./headers/manipulaArquivos.h"





void inputFile(char *fileName){
    int x, y, Testes, LIN, COL;
    FILE *file;
    file = fopen(fileName, "r");

    int **matriz;

    if(file == NULL){
        printf("Couldn't open file!\n");
        return;
    }

    fscanf(file, "%d", &Testes);
    printf("%d\n", Testes);
    for (int t = 0; t < Testes; t++){
        fscanf(file, "%d %d", &LIN, &COL);
        printf("%d %d\n", LIN, COL);
        matriz = malloc (LIN * sizeof (int*)) ;
        matriz[0] = malloc (LIN * COL * sizeof (int)) ;
    // percorre a matriz

    // ajusta os demais ponteiros de linhas (i > 0)
        for (int i=1; i < LIN; i++){
            matriz[i] = matriz[0] + i * COL ;
        }

        for (int l =0; l < LIN; l++){
        for (int c =0; c < COL; c++){
            int aux;
            fscanf(file, "%d", &aux);
            matriz[l][c] = aux ;
            printf("%d ", aux);
        }
            printf("\n");
        }

        free (matriz[0]) ;
        free (matriz) ;

    }
    fclose(file);
};