#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
	int conteudo;
	struct elemento *prox;
} Elem;

typedef struct fila {
	struct elemento *inicio;
	struct elemento *fim;
	int quantidade;
	int maximo;
} Fila;

Fila *cria_Fila(int limite) {
	Fila *fila = (Fila *)malloc(sizeof(Fila));
	if(fila != NULL) {
		fila->inicio = NULL;
		fila->fim = NULL;
		fila->quantidade = 0;
		fila->maximo = limite;
	}
	return fila;
}

int enqueue(Fila *fila, int num) {
	if (fila == NULL || fila->quantidade > fila->maximo) { return 0;}

	Elem *no = (Elem *)malloc(sizeof(Elem));
	if(no == NULL) return 0;
	no->conteudo = num;
	no->prox = NULL;

    if(fila->fim != NULL) fila->fim->prox = no;
	
	fila->fim = no;
	fila->quantidade++;
	if(fila->inicio == NULL) {
		fila->inicio = no;
	}
	return 1;
}

int dequeue(Fila *fila) {
	if (fila == NULL || fila->inicio == NULL) return 0;

	Elem *aux = fila->inicio;
	fila->inicio = fila->inicio->prox;
	int num = aux->conteudo;
	free(aux);
	return num;
}

void imprimir_fila(Fila *fila) {
	if(fila != NULL) {
		for(Elem *aux = fila->inicio; aux != NULL; aux = aux->prox) {
			printf("%d -", aux->conteudo);
		}
		printf("\n");
	}
}


int main()
{
	// FIFO
	Fila *fila = cria_Fila(10);
	enqueue(fila, 18);
	enqueue(fila, 16);
	enqueue(fila, 4);
	imprimir_fila(fila);
	dequeue(fila);
	imprimir_fila(fila);
	return 0;
}
