#include "./headers/programacaoDinamica.h"

#define MAX_SIZE 99999

void Print_Matriz(int **matriz, int LIN, int COL){
    int i, j;
    for(i = 0; i < LIN; i++){
        for(j = 0; j < COL; j++){
            printf("%i ",matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int melhorCaminho(int vizinho1, int vizinho2){
    return vizinho1 > vizinho2 ? vizinho1: vizinho2;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}




int programacaoDinamica(int **matriz, int LIN, int COL) {
    int min, soma;

    int **matrizDP = (int **)calloc((LIN), sizeof(int *));
    int **matrizDPAux = (int **)calloc((LIN), sizeof(int *));
    int **matrizDPSoma = (int **)calloc((LIN), sizeof(int *));
    for (int i = 0; i < LIN; i++) {
        matrizDP[i] = (int *)calloc((COL), sizeof(int));
        matrizDPAux[i] = (int *)calloc((COL), sizeof(int));
        matrizDPSoma[i] = (int *)calloc((COL), sizeof(int));
    }

    // Passo 2: preencher a matriz com os custos base
    matrizDP[0][0] = matriz[0][0];
    matrizDPSoma[0][0] = 0;
    matrizDPAux[0][0] = 1;
    soma = 0;
    min = 1;
    for (int i = 1; i < LIN; i++) {
        soma += matriz[i][0];
        if (soma < 0) {
            min += (soma * -1); // Ajusta o número mínimo na primeira posição
            soma = 0;
        }
        matrizDP[i][0] = matriz[i][0] + matrizDP[i-1][0];
        matrizDPAux[i][0] = min;
        matrizDPSoma[i][0] = soma;
    }
    soma = 0;
    min = 1;
    for (int j = 1; j < COL; j++) {
        soma += matriz[0][j];
        if (soma < 0) {
            min += (soma * -1); // Ajusta o número mínimo na primeira posição
            soma = 0;
        }
        matrizDP[0][j] = matriz[0][j] + matrizDP[0][j - 1];
        matrizDPAux[0][j] = min;
        matrizDPSoma[0][j] = soma;
    }

    int resultado;
    // Passo 3: preencher o restante da matriz
    for(int i = 1; i < LIN; i++){
        soma = 0;
        min = 0;
        for(int j = 1; j < COL; j++){
            resultado =  ((matrizDP[i][j-1] > matrizDP[i-1][j]) ? matrizDP[i][j-1] : matrizDP[i-1][j]);
            if(resultado == matrizDP[i][j-1]){
                if(min == 0){
                    soma = matrizDPSoma[i][j-1] + matriz[i][j];
                    min = matrizDPAux[i][j-1];
                }else{
                    soma += matrizDPSoma[i][j-1];
                }
            }else{
                if(min == 0){
                    soma = matrizDPSoma[i-1][j] + matriz[i][j];
                    min = matrizDPAux[i-1][j];
                }else{
                    soma += matrizDPSoma[i-1][j];
                }
            }
            if (soma < 0){
                min += (soma * -1); // Ajusta o número mínimo na primeira posição
                soma = 0;
            }
            matrizDP[i][j] = matriz[i][j] + resultado;
            matrizDPAux[i][j] = min;
            matrizDPSoma[i][j] = soma;
        }
    }
    int resultadoFinal = matrizDPAux[LIN-1][COL-1];


    // Passo 5: Liberar memória alocada
    for (int i = 0; i < LIN; i++) {
        free(matrizDP[i]);
        free(matrizDPAux[i]);
        free(matrizDPSoma[i]);
    }
    free(matrizDP);
    free(matrizDPAux);
    free(matrizDPSoma);
    return resultadoFinal;
}