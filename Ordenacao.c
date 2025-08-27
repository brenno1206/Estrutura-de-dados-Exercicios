#include <stdio.h>

void insertionSort(int *arr, int t);
void selectionSort(int *arr, int t);
void bubbleSort(int *arr, int t);

void trocar(int *a, int *b);
void imprimir(int *arr, int t);

int main() {
    int v[] = {5,3,4,3,2,1,2,0};
    int size = sizeof(v) / sizeof(v[0]);
    printf("Antes da Ordenação:\n");
    imprimir(v, size);

    bubbleSort(v, size);

    printf("Depois da Ordenação:\n");
    imprimir(v, size);
    return 0;
}

void bubbleSort(int *arr, int t) { // troca os elementos par a par e acaba quando nao houverem mais trocas
    int troca;
    do {
        troca = 0;
        for(int i = 0; i < t; i++) {
            if(arr[i] > arr[i + 1] && i < t - 1) {
                trocar(&arr[i], &arr[i + 1]);
                troca++;
            }
        }

    } while(troca > 0);
}

void selectionSort(int *arr, int t) { // procura o menor/maior por todo array a cada iteração
    for (int i = 0; i < t; i++) {
        int menorIndex = i;
        int j;
        for(j = i; j < t; j++) {
            if(arr[j] < arr[menorIndex]) {
                menorIndex = j;
            }
        }
        trocar(&arr[i], &arr[menorIndex]);
    }
}

void insertionSort(int *arr, int t) { // troca pelo numero anterior até onde puder
    for(int i = 0; i < t; i++) {
        int j = i;
        while(arr[j] < arr[j - 1] && j > 0) {
            trocar(&arr[j], &arr[j - 1]);
            j--;
        }
    }
}

void trocar(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void imprimir(int *arr, int t) {
    int i = 0;
    while(i < t) {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
}