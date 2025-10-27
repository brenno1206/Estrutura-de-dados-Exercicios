#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
	int conteudo;
	struct elemento *prox;
} Elem;

typedef struct elemento * Pilha;

Pilha *cria_Pilha() {
	Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
	if(pilha != NULL) {
		*pilha = NULL;
	}
	return pilha;
}

int push(Pilha *pilha, int num) {
	if (pilha == NULL) return 0;

	Elem *no = (Elem *)malloc(sizeof(Elem));
	if(no == NULL) return 0;
	no->conteudo = num;
	no->prox = (*pilha);
	*pilha = no;
	return 1;

}

int consulta_Topo(Pilha *pilha) {
	if(pilha == NULL || *pilha == NULL) return 0;
	return (*pilha)->conteudo;
}

void libera_pilha(Pilha *pilha) {
	if (pilha != NULL) {
		while(*pilha != NULL) {
			Elem *aux = *pilha;
			printf("%d - ", aux->conteudo);
			*pilha = (*pilha)->prox;
			free(aux);
		}
		free(pilha);
	}
}

int pop(Pilha *pilha) {
	if (pilha == NULL || *pilha == NULL) return 0;

	Elem *aux = *pilha;
	*pilha = (*pilha)->prox;
	int num = aux->conteudo;
	free(aux);
	return num;
}

int main()
{
	Pilha *pilha = cria_Pilha();

	push(pilha, 5);
	push(pilha, 2);
	push(pilha, 9);
    

	printf("Topo: %d\n", consulta_Topo(pilha));
    printf("Removendo: %d\n", pop(pilha));
    
	libera_pilha(pilha);
	return 0;
}
