#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
	struct cel* proximo;
	int conteudo;
} cel;

typedef struct pilha {
	cel* inicio;
	cel* fim;
	int quantidade;
	int limite;
} Pilha;

Pilha *criarPilha();
int push(Pilha *pilha, int valor);
int pop(Pilha *pilha);
int mostrarTopo(Pilha *pilha);
int isEmpty(Pilha *pilha);
int isFull(Pilha *pilha);
void liberarPilha(Pilha *pilha);
void imprimirPilha(Pilha *pilha);

int main()
{
	Pilha *pilha = criarPilha(20);
	printf("Esta vazia: %d\n", isEmpty(pilha));
	printf("Esta cheia: %d\n", isFull(pilha));

	printf("\n\n");
	for(int i = 0; i < 25; i++) {
		printf("inserC'C#o do elemento %d: %d\n", i, push(pilha, i));
	}
	printf("\n\n");
	imprimirPilha(pilha);
	printf("Esta vazia: %d\n", isEmpty(pilha));
	printf("Esta cheia: %d\n", isFull(pilha));

	printf("Topo da pilha: %d\n", mostrarTopo(pilha));

	imprimirPilha(pilha);
	printf("Removendo -- %d\n", pop(pilha));
	printf("Removendo -- %d\n", pop(pilha));
	printf("Removendo -- %d\n", pop(pilha));
	printf("Removendo -- %d\n", pop(pilha));
	printf("Removendo -- %d\n", pop(pilha));
	imprimirPilha(pilha);

	printf("Esta vazia: %d\n", isEmpty(pilha));
	printf("Esta cheia: %d\n", isFull(pilha));



	liberarPilha(pilha);
	return 0;
}


Pilha *criarPilha(int limite) {
	Pilha *pilha = malloc(sizeof(pilha));
	if(pilha != NULL) {
		pilha->inicio = NULL;
		pilha->fim = NULL;
		pilha->quantidade = 0;
		pilha->limite = limite;
	}
	return pilha;
}

int push(Pilha *pilha, int valor) { //insere no inicio
	if(pilha == NULL) return -1;
	if(isFull(pilha)) return 0;

	cel* aux = malloc(sizeof(cel));
	if(aux == NULL) return -1;

	aux->proximo = NULL;
	aux->conteudo = valor;
	if(isEmpty(pilha)) {
		pilha->fim = aux;
	} else {
		aux->proximo = pilha->inicio;
	}
	pilha->inicio = aux;
	pilha->quantidade++;
	return 1;
}

int pop(Pilha *pilha) { //retira do inicio
	if(pilha == NULL) return -1;
	if(isEmpty(pilha)) return 0;
	cel *aux = pilha->inicio;
	pilha->inicio = pilha->inicio->proximo;
	if(pilha->inicio == NULL) {
		pilha->fim == NULL;
	}
	free(aux);
	pilha->quantidade--;
	return 1;
}

int mostrarTopo(Pilha *pilha) {
	if(pilha == NULL || isEmpty(pilha)) return -1;
	return pilha->inicio->conteudo;

}

int isEmpty(Pilha *pilha) {
	if (pilha == NULL) return -1;
	if(pilha->inicio == NULL) return 1;
	return 0;
}

int isFull(Pilha *pilha) {
	if(pilha == NULL) return -1;
	if(pilha->quantidade == pilha->limite) return 1;
	return 0;
}

void imprimirPilha(Pilha *pilha) {
	if(pilha != NULL) {
		cel *aux = pilha->inicio;
		while(aux != NULL) {
			printf("%d ", aux->conteudo);
			aux = aux->proximo;
		}
		printf("\n");
	}
}

void liberarPilha(Pilha *pilha) {
	if(pilha != NULL) {
		cel *aux = pilha->inicio;
		while(aux != NULL) {
			cel *temp = aux;
			aux = aux->proximo;
			free(temp);
		}
		free(pilha);
	}
}

