#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void imprimirVetor(int *arr, int t);
int mergeSort(int *arr, int i, int f);
void merge(int *arr, int inicio, int meio, int fim);



int main()
{

	int vetor[] = {23, 4, 67, -8, 90, 54, 21, 2, 34, 7};
	int tamanho = sizeof(vetor)/ sizeof(vetor[0]);
	printf("Antes da Ordenacao:\n");
	imprimirVetor(vetor, tamanho);
	mergeSort(vetor, 0, tamanho -1);
	printf("Depois da Ordenacao:\n");
	imprimirVetor(vetor, tamanho);

	return 0;
}

int mergeSort(int* arr, int i, int f) {
	int meio;
	if(i < f) {
		meio = floor((i + f) /2);
		mergeSort(arr, i, meio);
		mergeSort(arr, meio+1, f);
		merge(arr, i, meio, f);
	}
}

void merge(int *arr, int inicio, int meio, int fim) {
	int *temp, i, j, k, tamanho, p1, p2, fim1 = 0, fim2 = 0;
	tamanho = fim - inicio +1;
	p1 = inicio;
	p2 = meio +1;
	temp = (int *) malloc(tamanho*(sizeof(int)));
	if(temp != NULL) {
		for(i = 0; i < tamanho; i++) {
			if(!fim1 && !fim2) {
				if(arr[p1] < arr[p2]) temp[i] = arr[p1++];
				else temp[i] = arr[p2++];
				if(p1 > meio) fim1 =1;
				if(p2 > fim) fim2 =1;
			} else {
				if(!fim1) temp[i] = arr[p1++];
				else temp[i] = arr[p2++];
			}
		}
		for(j = 0, k = inicio; j < tamanho; j++, k++) {
			arr[k] = temp[j];
		}
		free(temp);
	}
}

void imprimirVetor(int* arr, int t) {
	for(int i = 0; i < t; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


