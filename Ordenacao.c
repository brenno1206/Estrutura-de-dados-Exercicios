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
    printf("--------------------------------\n");
    bubbleSort(v, size);
    printf("--------------------------------\n");
    printf("Depois da Ordenação:\n");
    imprimir(v, size);
    return 0;
}

void bubbleSort(int *arr, int t) { // troca os elementos par a par e acaba quando nao houverem mais trocas
  int trocas;
  int limite = t-1;
  do {
    trocas = 0;
    for(int i = 0; i < limite; i++) {
      if(arr[i + 1] < arr[i]) {
        trocar(&arr[i], &arr[i+1]);
        trocas++;
      }
    }
    imprimir(arr, t);
  } while(trocas);
}

void selectionSort(int *arr, int t) { // procura o menor/maior por todo array a cada iteração
  for(int i = 0; i < t; i++) {
    int menorIdx = arr[i];
    for(int j = i + 1; j < t; j++) {
      if(arr[j] < arr[menorIdx])
        menorIdx = j;
    }
    if (menorIdx != i)
      trocar(&arr[i], &arr[menorIdx]);
    imprimir(arr, t);
  }
}

void insertionSort(int *arr, int t) { // troca pelo numero anterior até onde puder
  for(int i = 1; i < t; i++) {
    int j = i;
    while(j > 0 && arr[j] < arr[j-1]) {
      trocar(&arr[j-1], &arr[j]);
      j--;
    }
    imprimir(arr,t);
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
