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
	}
	else if (aux->proximo == NULL)
	{
		aux->anterior->proximo = NULL;
	}
	else
	{
		aux->anterior->proximo = aux->proximo;
		aux->proximo->anterior = aux->anterior;
	}
	free(aux);
	return 1;
}

int main()
{
	Lista *lista;
	lista = criarLista();
	if (lista == NULL)
		return 1;

	for (int i = 10; i < 20; i++)
	{
		inserirFim(lista, i);
	}
	for (int i = 9; i >= 0; i--)
	{
		inserirInicio(lista, i);
	}

	imprimirLista(lista);
	liberarLista(lista);

	return 0;
}