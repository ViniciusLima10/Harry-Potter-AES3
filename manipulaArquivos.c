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
        int resultado;
        //int buscaEmProfundidade(int **matriz, int **visited, int LIN, int COL, int i, int j, int minNum, int sum, int minNumAbsoluto) {
        resultado = buscaEmProfundidade(matriz, visited, LIN, COL, 0, 0, 1, 0, 9999);
        printf("%d \n", resultado);
        free (matriz[0]) ;
        free (matriz) ;
        free (visited[0]) ;
        free (visited) ;
    }
    fclose(file);
};