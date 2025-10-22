#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
	struct cel* proximo;
	int conteudo;
} cel;

typedef struct fila {
	cel* inicio;
	cel* fim;
	int quantidade;
	int limite;
} Fila;

Fila *criarFila(int limite);
int enqueue(Fila *fila, int valor);
int dequeue(Fila *fila);
int isEmpty(Fila *fila);
int isFull(Fila *fila);
void imprimirFila(Fila *fila);
void liberarFila(Fila *fila);

int main()
{
	return 0;
}

Fila *criarFila(int limite) {
    Fila *fila = malloc(sizeof(Fila));
    if(fila != NULL) {
        fila->inicio = NULL;
        fila->fim = NULL;
        fila->quantidade = 0;
        fila->limite = limite;
    }
    return fila;
}

int enqueue(Fila *fila, int valor){ //nsere no final
    if(fila == NULL) return 0;
    if(isEmpty(fila)) return 0;
}
int dequeue(Fila *fila); // retira no inicio
int isEmpty(Fila *fila);
int isFull(Fila *fila);
void imprimirFila(Fila *fila);
void liberarFila(Fila *fila);
