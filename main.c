#include <stdio.h>
#include <sys/resource.h>
#include <sys/time.h>


#include "./headers/manipulaArquivos.h"


void main(int argc, char *argv[]){

    struct rusage usage;
    struct timeval start, end;
    double diff;
    getrusage(RUSAGE_SELF, &usage);

    if(strcmp(argv[1], "1") == 0){
        gettimeofday(&start, NULL);
        inputFile(argv[2], 1);
        gettimeofday(&end, NULL);
    }
    if(strcmp(argv[1], "2") == 0){
        gettimeofday(&start, NULL);
        inputFile(argv[2], 2);
        gettimeofday(&end, NULL);
    }

    printf("Tempo de CPU usado: %ld.%06ld segundos\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
    printf("Tempo de CPU do sistema usado: %ld.%06ld segundos\n", usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
    printf("Máximo uso de memória residente: %ld kilobytes\n", usage.ru_maxrss);
    printf("Tempo de execucao do algoritmo de encontrar a maior sequencia: %f segundos\n", diff);

}