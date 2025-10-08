#include <stdio.h>
#include <stdlib.h>

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
    printf("Lista nula\n");
  } else {
    cel* aux = *lista;
  
  	while(aux != NULL) {
  		printf("\t%d", aux->conteudo);
  		aux = aux->seg;
  	}
  	printf("\n");
  }
}

int buscaLinear(Lista* lista, int x) {
  
  if(lista == NULL) return 0;
  cel* aux = *lista;

	while(aux != NULL) {
		if(aux->conteudo == x) {
		  return 1;
		}
		aux = aux->seg;
	}
	return 0;
	
}

//busca com for
int buscaFor(Lista* lista, int x) {
  if(lista == NULL) return 0;
	for(cel* aux = *lista; aux != NULL; aux = aux->seg) {
	  if(aux->conteudo == x) return 1;
	}
	return 0;
}
//busca recursiva

int buscaRecursiva(cel* elemento, int x) {
  if(elemento == NULL) return 0;
  if(elemento->conteudo == x) return 1;
  return buscaRecursiva(elemento->seg, x);
	
}

int main()
{
	Lista *lst;
	cel* aux;
	lst = cria_Lista();


	for(int i = 0; i < 10; i++) {
		insere_lista_fim(lst, i+1);
	}

	
	imprimir_lista(lst);
	
	printf("\nResultado da busca: %d\n", buscaLinear(lst, 10));
	printf("\nResultado da busca Recursiva: %d\n", buscaRecursiva(*lst, 12));
	printf("\nResultado da busca For: %d\n", buscaFor(lst, 5));
	
  aux = *lst;
  cel *temp;
  while(aux != NULL) {
      temp = aux;
      aux = aux->seg;
      free(temp);
  }
  free(lst);
  

	return 0;
}
