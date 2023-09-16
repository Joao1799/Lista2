#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int trocas = 0;
int comparacoes = 0;
	void muda(char* arr[], int a, int b) {
	    char* temp = arr[a];
	    arr[a] = arr[b];
	    arr[b] = temp;
	    trocas++;
	}
	int particao(char* arr[], int esq, int dir) {
	    char* pivo = arr[dir];
	    int i = (esq - 1);
	
	    for (int j = esq; j <= dir - 1; j++) {
	        comparacoes++;
	        if (strcmp(arr[j], pivo) < 0) {
	            i++;
	            muda(arr, i, j);
	        }
	    }
	    muda(arr, i + 1, dir);
	    return (i + 1);
	}
		void quick(char* arr[], int esq, int dir) {
		    if (esq < dir) {
		        int pi = particao(arr, esq, dir);
		        quick(arr, esq, pi - 1);
		        quick(arr, pi + 1, dir);
		    }
		}

int main() { 
    char* arr[20] = {
        "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limao", "manga", "abacate", "kiwi",
        "cereja", "morango", "pessego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"
    };
    
    int n = sizeof(arr) / sizeof(arr[0]);

	printf("***************************************************************\n");
    printf("******************Versão Original:***************************\n");
    
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
       printf("\n\n");

    quick(arr, 0, n - 1);

	printf("\n**************************************************************\n");
    printf("******************Versão Ordenada pelo QuickSort :*************\n");
    
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
	printf("\n\n\n**************************************************************\n");
    printf("Foram feitas %d comparacoes e %d trocas\n", comparacoes,trocas);
	printf("***************************************************************\n");
	

    char* doMeio;   // Aqui é calculado a mediana
    if (n % 2 == 1) {
        doMeio = arr[n / 2];
    } else {
        doMeio = arr[n / 2 - 1];
    }
    
    printf("\n\n***************************************************************\n");
    printf("mediana: %s\n", doMeio);
    printf("***************************************************************\n");

    
    FILE* quick_sort = fopen("Saída QuickSort.txt", "w"); //arquivo de saída
    if (quick_sort == NULL) {
        printf("\nErro no arquivo, n achou\n");
        return 1;
    }
	
		fprintf(quick_sort, "Número de trocas: %d\n", trocas); //arquivo de saída, Número de trocas
    	fprintf(quick_sort, "Número de comparações: %d\n", comparacoes);  //arquivo de saída, Número de comparações
    	fprintf(quick_sort, "\n");
    	
        fprintf(quick_sort, "Vetor ordenado:\n"); //arquivo de saída, vetor ordenado 
    	for (int i = 0; i < n; i++) {
        fprintf(quick_sort, "(%d)\t%s\n", i + 1, arr[i]);
    }
	
    
    fclose(quick_sort);

    return 0;
}

