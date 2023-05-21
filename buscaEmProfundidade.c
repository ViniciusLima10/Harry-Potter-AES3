#include "./headers/buscaEmProfundidade.h"

// Define a função de busca em profundidade

// void Print_Matriz(int **visited, int LIN, int COL){
//     int i, j;
//     for(i = 0; i < LIN; i++){
//         for(j = 0; j < COL; j++){
//             printf("%i ",visited[i][j]);
//         }
//         printf("\n");
//     }
//     printf("\n");
// }

int buscaEmProfundidade(int **matriz, int **visited, int LIN, int COL, int i, int j, int minNum, int sum, int minNumAbsoluto) {
    sum += matriz[i][j];
    if (sum < 0) {
        minNum += (sum * -1); // Ajusta o número mínimo na primeira posição
        sum = 0;
    }
    if (i == LIN-1 && j == COL-1) {
        if(minNum < minNumAbsoluto){
            minNumAbsoluto = minNum;
        }
        return minNumAbsoluto;
    }
    
    visited[i][j] = 1;
    
    if (i < LIN-1 && visited[i+1][j] == 0) { // Abaixo
        minNumAbsoluto = buscaEmProfundidade(matriz, visited, LIN, COL, i+1, j, minNum, sum, minNumAbsoluto);
    }
    if (j < COL-1 && visited[i][j+1] == 0) { // À direita
        minNumAbsoluto = buscaEmProfundidade(matriz, visited, LIN, COL, i, j+1, minNum, sum, minNumAbsoluto);
    }

    visited[i][j] = 0;
    return minNumAbsoluto;
}
