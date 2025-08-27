#include <stdio.h>


int buscaBinariaRecursiva(int *arr, int inicio, int fim, int numero);
int buscaLinearRecursiva(int *arr, int i, int tamanho, int numero);
int maiorElementoRecursivo(int *arr, int pos, int tamanho, int maior);
void imprimirDeTrasPraFenteRecursivo(int *arr, int pos, int tamanho);

int main()
{
    int vet[] = {1,2,3,4,5,6,8};
    imprimirDeTrasPraFenteRecursivo(vet, 0, 7);
    return 0;
}



void imprimirDeTrasPraFenteRecursivo(int *arr, int pos, int tamanho) {
    if (!(pos >= tamanho)) {
        printf("%d ", arr[pos]);
        imprimirDeTrasPraFenteRecursivo(arr, pos + 1, tamanho);
    }
}

int maiorElementoRecursivo(int *arr, int pos, int tamanho, int maior) {
    if(pos >= tamanho) return maior;
    else if(arr[pos] > maior) return maiorElementoRecursivo(arr, pos + 1, tamanho, arr[pos]);
    else return maiorElementoRecursivo(arr, pos + 1, tamanho, maior);
}

int buscaLinearRecursiva(int *arr, int i, int tamanho, int numero) {
    
    if(i >= tamanho) return 0;
    else if(arr[i] == numero) return 1;
    else if(arr[i] > numero) return 0;
    else return buscaLinearRecursiva(arr, i + 1, tamanho, numero);
}

int buscaBinariaRecursiva(int *arr, int inicio, int fim, int numero) {
    int meio = (inicio + fim) / 2;
    if(inicio > fim) return 0;
    else if (numero == arr[meio]) return 1;
    else if (numero > arr[meio]) return buscaBinariaRecursiva(arr, meio + 1, fim, numero);
    else return buscaBinariaRecursiva(arr, inicio, meio -1 , numero);
}

