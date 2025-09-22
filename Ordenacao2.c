#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void imprimirVetor(int *arr, int t);
void trocar(int *a, int *b);
void mergeSort(int *arr, int beg, int end);
void merge(int *arr, int beg, int mid, int end);

int main() {

  int vetor[] = {23, 4, 67, -8, 90, 54, 21, 2, 34, 7};
  int tamanho = sizeof(vetor) / sizeof(vetor[0]);
  printf("Antes da Ordenacao:\n");
  imprimirVetor(vetor, tamanho);
  mergeSort(vetor, 0, tamanho - 1);
  printf("Depois da Ordenacao:\n");
  imprimirVetor(vetor, tamanho);

  return 0;
}

void mergeSort(int *arr, int beg, int end) {
  int mid;
  if (beg < end) {
    mid = floor((beg + end) / 2);
    mergeSort(arr, beg, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, beg, mid, end);
  }
}

void merge(int *arr, int beg, int mid, int end) {
  int pos1 = beg, pos2 = mid + 1;
  int end1 = 0, end2 = 0;
  int size = end - beg + 1;
  int *temp = (int *)malloc(size * (sizeof(int)));
  if (temp != NULL) {
    for (int i = 0; i < size; i++) {
      if (!end1 && !end2) {
        if (arr[pos1] < arr[pos2])
          temp[i] = arr[pos1++];
        else
          temp[i] = arr[pos2++];
        if (pos1 > mid)
          end1 = 1;
        if (pos2 > end)
          end2 = 1;
      } else {
        if (!end1)
          temp[i] = arr[pos1++];
        else
          temp[i] = arr[pos2++];
      }
    }
    for (int j = 0, k = beg; j < size; j++, k++) {
      arr[k] = temp[j];
    }
    free(temp);
  }
}

void imprimirVetor(int *arr, int t) {
  for (int i = 0; i < t; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

void trocar(int *a, int *b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}
