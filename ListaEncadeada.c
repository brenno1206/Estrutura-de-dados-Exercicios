#include <stdio.h>
#include <stdlib.h>

typedef struct cel
{
	struct cel *anterior;
	int conteudo;
	struct cel *proximo;
} cel;

typedef struct Lista
{
	struct cel *inicio;
	struct cel *fim;
	int quantidade;
} Lista;

Lista *criarLista()
{
	Lista *lista = (Lista *)malloc(sizeof(Lista));
	lista->inicio = NULL;
	lista->fim = NULL;
	lista->quantidade = 0;
	return lista;
}

void liberarLista(Lista *lista)
{
	if (lista != NULL)
	{
		while (lista->inicio != NULL)
		{
			cel *aux = lista->inicio;
			lista->inicio = lista->inicio->proximo;
			free(aux);
		}
		free(lista);
	}
}

void inserirFim(Lista *lista, int valor)
{
	if (lista != NULL)
	{
		cel *val = (cel *)malloc(sizeof(cel));
		val->conteudo = valor;
		val->proximo = NULL;
		if (lista->inicio == NULL)
		{
			lista->inicio = val;
			val->anterior = NULL;
			lista->fim = val;
		}
		else
		{
			val->anterior = lista->fim;
			lista->fim->proximo = val;
			lista->fim = val;
		}
		lista->quantidade++;
	}
}

void imprimirLista(Lista *lista)
{
	for (cel *aux = lista->inicio; aux != NULL; aux = aux->proximo)
	{
		printf("%d ", aux->conteudo);
	}
	printf("\n");
}

void inserirInicio(Lista *lista, int valor)
{
	if (lista != NULL)
	{
		cel *no = (cel *)malloc(sizeof(cel));
		no->conteudo = valor;
		no->anterior = NULL;

		if (lista->inicio == NULL)
		{
			no->proximo = NULL;
			lista->inicio = no;
			lista->fim = no;
		}
		else
		{
			no->proximo = lista->inicio;
			lista->inicio->anterior = no;
			lista->inicio = no;
		}
		lista->quantidade++;
	}
}

int buscaLinear(Lista *lista, int valor)
{
	int i = 0;
	for (cel *aux = lista->inicio; aux != NULL; aux = aux->proximo, i++)
	{
		if (aux->conteudo == valor)
			return i;
	}
	return -1;
}

int removerElemento(Lista *lista, int valor)
{
	if (lista == NULL || lista->inicio == NULL)
		return 0;

	cel *aux = lista->inicio;

	while (aux != NULL && aux->conteudo != valor)
	{
		aux = aux->proximo;
	}
	if (aux == NULL)
		return 0;
	if (aux == lista->inicio)
	{
		lista->inicio = lista->inicio->proximo;
		if (lista->inicio != NULL)
			lista->inicio->anterior = NULL;
		else
			lista->fim = NULL;
	}
	else if (aux->proximo == NULL)
	{
		aux->anterior->proximo = NULL;
		lista->fim = aux->anterior;
	}
	else
	{
		aux->anterior->proximo = aux->proximo;
		aux->proximo->anterior = aux->anterior;
	}
	free(aux);
	lista->quantidade--;
	return 1;
}

Lista *concatenarLista(Lista *lista1, Lista *lista2)
{
	if (lista1 == NULL || lista2 == NULL)
		return NULL;
	Lista *listaResultado = criarLista();
	cel *aux1 = lista1->inicio;
	cel *aux2 = lista2->inicio;

	while (aux1 != NULL || aux2 != NULL)
	{
		if (aux1 != NULL)
		{
			inserirFim(listaResultado, aux1->conteudo);
			aux1 = aux1->proximo;
		}
		else if (aux2 != NULL)
		{
			inserirFim(listaResultado, aux2->conteudo);
			aux2 = aux2->proximo;
		}
	}
	return listaResultado;
}

void concatenarLista(Lista *lista1, Lista *lista2)
{
	if (lista1 != NULL && lista2 != NULL && lista2->inicio != NULL)
	{
		if (lista1->inicio == NULL)
		{
			lista1->inicio = lista2->inicio;
			lista1->fim = lista2->fim;
			lista1->quantidade = lista2->quantidade;
		}
		else
		{
			lista1->fim->proximo = lista2->inicio;
			lista2->inicio->anterior = lista1->fim;
			lista1->fim = lista2->fim;
			lista1->quantidade += lista2->quantidade;
		}
		lista2->inicio = NULL;
		lista2->fim = NULL;
		lista2->quantidade = 0;
	}
}

void removerElementos(Lista *lista, int quantidade)
{
	if (lista != NULL || lista->inicio == NULL)
	{
		cel *aux;
		int elementosRemovidos = 0;
		while (lista->inicio != NULL && elementosRemovidos < quantidade)
		{
			aux = lista->inicio;
			lista->inicio = lista->inicio->proximo;

			free(aux);
			lista->quantidade--;
			elementosRemovidos++;
		}
		if (aux == NULL)
			lista->fim = NULL;
		else
			lista->inicio->anterior = NULL;
		if (lista->inicio->proximo == NULL)
		{
			lista->fim = lista->inicio;
		}
	}
}

int buscarMaiorElemento(Lista *lista);

int quantidadeDePares(Lista *lista);

int media(Lista *lista);

Lista *copiarSemRepeticao(Lista *lista);

void inverter(Lista *lista);

int *paraVetor(Lista *lista);

int saoIguais(Lista *lista1, Lista *lista2);

int estaContida(Lista *lista1, Lista *lista2);

int main()
{
	Lista *lista1 = criarLista();
	Lista *lista2 = criarLista();
	Lista *listaConcatenada;

	for (int i = 10; i < 20; i++)
	{
		inserirFim(lista2, i);
	}

	for (int i = 9; i >= 0; i--)
	{
		inserirInicio(lista1, i);
	}

	listaConcatenada = concatenarLista(lista1, lista2);

	imprimirLista(lista1);
	removerElementos(lista1, 7);
	imprimirLista(lista1);
	/*
		imprimirLista(lista1);
		imprimirLista(lista2);
		imprimirLista(listaConcatenada);
	*/
	liberarLista(lista1);
	liberarLista(lista2);
	liberarLista(listaConcatenada);

	return 0;
}