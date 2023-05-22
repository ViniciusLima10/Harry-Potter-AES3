#include "./headers/manipulaArquivos.h"



void outputFile(int numeroDeTabuleiros, int *resultados) {

    FILE *file; // ponteiro para arquivo
    file = fopen("saida.txt", "w"); // abre o arquivo em modo de escrita
    
    if (file == NULL) { // verifica se o arquivo foi aberto corretamente
        printf("Couldn't open the output file!\n");
        return;
    }
    for(int i = 0; i < numeroDeTabuleiros; i++){
       fprintf(file, "%d\n", resultados[i]); // escreve o valor de maiorSequencia no arquivo
    }
    fclose(file); // fecha o arquivo
}

void inputFile(char *fileName, int estrategia) {
    int x, y, Testes, LIN, COL;
    FILE *file;
    file = fopen(fileName, "r");

    int *resultados;

    int **matriz;
    int **visited;

    if (file == NULL) {
        printf("Couldn't open file!\n");
        return;
    }

    fscanf(file, "%d", &Testes);
    resultados = malloc(Testes * sizeof(int));
    for (int t = 0; t < Testes; t++) {
        fscanf(file, "%d %d", &LIN, &COL);
        matriz = malloc(LIN * sizeof(int *));
        matriz[0] = malloc(LIN * COL * sizeof(int));
        visited = malloc(LIN * sizeof(int *));
        visited[0] = malloc(LIN * COL * sizeof(int));

        // Percorre a matriz

        // Ajusta os demais ponteiros de linhas (i > 0)
        for (int i = 1; i < LIN; i++) {
            matriz[i] = matriz[0] + i * COL;
            visited[i] = visited[0] + i * COL;
        }

        for (int l = 0; l < LIN; l++) {
            for (int c = 0; c < COL; c++) {
                int aux;
                fscanf(file, "%d", &aux);
                matriz[l][c] = aux;
                visited[l][c] = 0;
            }
        }

        if (estrategia == 1) {
            resultados[t] = buscaEmProfundidade(matriz, visited, LIN, COL, 0, 0, 1, 0, 9999);
        }
        if (estrategia == 2) {
             resultados[t] = programacaoDinamica(matriz, LIN, COL);
        }

        free(matriz[0]);
        free(matriz);
        free(visited[0]);
        free(visited);
    }

    outputFile(Testes, resultados);
    free(resultados);
    fclose(file);
}