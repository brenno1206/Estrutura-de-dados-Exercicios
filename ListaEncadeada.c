#include <stdio.h>
#include <stdlib.h>

// fazer com cabeça, duplamente encadeada e circular

typedef struct cel {
	int conteudo;
	struct cel *seg;
} cel;

typedef struct cel* Lista;

Lista* cria_Lista() {
	Lista *li = (Lista*) malloc(sizeof(Lista));
	if(li != NULL) {
		*li = NULL;
	}
	return li;
}

int insere_lista_fim(Lista* lista, int x) {
	if (lista == NULL) return 0;

	cel *aux = (cel*) malloc(sizeof(cel));
	if(aux == NULL) return 0;

	aux->conteudo = x;
	aux->seg = NULL;

	if(*lista == NULL) {
		*lista = aux;
	} else {
		cel *temp = *lista;
		while(temp->seg != NULL) {
			temp = temp->seg;
		}
		temp->seg = aux;
	}
	return 1;
}

void imprimir_lista(Lista* lista) {
	if(lista == NULL) {
		printf("Lista nula.\n");
	} else if (*lista == NULL) {
	  printf("Lista Vazia.\n");
	} else {
		cel* aux = *lista;

		while(aux != NULL) {
			printf("%d ", aux->conteudo);
			aux = aux->seg;
		}
		printf("\n");
	}
}

int buscaFor(Lista* lista, int x) {
	if(lista == NULL) return 0;
	for(cel* aux = *lista; aux != NULL; aux = aux->seg) {
		if(aux->conteudo == x) return 1;
	}
	return 0;
}

void liberar_lista(Lista* lista) {
  if (lista != NULL) {
    cel *aux;
    while(*lista != NULL) {
      aux = *lista;
      *lista = aux->seg;
      free(aux);
    }
    free(lista);
  }
}

int remover_lista(Lista* lista, int x) {
  if (lista == NULL) return 0;
  if (*lista == NULL) return 0;
  
  cel* aux = *lista;
  cel* ant = NULL;
  while(aux != NULL && aux->conteudo != x) {
    ant = aux;
    aux = aux->seg;
  }
  if (aux == NULL) return 0;
  if (aux == *lista) {
    *lista = aux->seg;
  } else {
    ant->seg = aux->seg;
  }
  free(aux);
  return 1;
  
}

int main()
{
	Lista *lst = NULL;
	cel* aux = NULL;
	lst = cria_Lista();
	
	for(int i = 0; i < 10; i++) {
		insere_lista_fim(lst, i+1);
	}

	
	imprimir_lista(lst);
  
	liberar_lista(lst);
	
	return 0;
}
