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
	if (lista != NULL && lista->inicio != NULL)
	{
		int i = 0;
		for (cel *aux = lista->inicio; aux != NULL; aux = aux->proximo, i++)
		{
			if (aux->conteudo == valor)
				return i;
		}
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

Lista *concatenarListas(Lista *lista1, Lista *lista2)
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
	if (lista != NULL && lista->inicio != NULL)
	{
		int elementosRemovidos = 0;
		while (lista->inicio != NULL && elementosRemovidos < quantidade)
		{
			cel *aux = lista->inicio;
			lista->inicio = lista->inicio->proximo;

			free(aux);
			lista->quantidade--;
			elementosRemovidos++;
		}
		if (lista->inicio == NULL)
			lista->fim = NULL;
		else
		{
			lista->inicio->anterior = NULL;
		}
	}
}

int buscarMaiorElemento(Lista *lista)
{
	if (lista == NULL || lista->inicio == NULL)
		return -1;
	int maiorElemento = lista->inicio->conteudo, idxMaiorElemento = 0, contador = 1;
	for (cel *aux = lista->inicio->proximo; aux != NULL; aux = aux->proximo)
	{
		if (aux->conteudo > maiorElemento)
		{
			maiorElemento = aux->conteudo;
			idxMaiorElemento = contador;
		}
		contador++;
	}
	return idxMaiorElemento;
}

int quantidadeDePares(Lista *lista)
{
	if (lista == NULL)
		return -1;

	int qtdPares = 0;
	for (cel *aux = lista->inicio; aux != NULL; aux = aux->proximo)
	{
		if (!(aux->conteudo % 2))
			qtdPares++;
	}
	return qtdPares;
}

double media(Lista *lista)
{
	if (lista == NULL || lista->inicio == NULL)
		return 0;
	int soma = 0;
	for (cel *aux = lista->inicio; aux != NULL; aux = aux->proximo)
	{
		soma += aux->conteudo;
	}

	double media = ((double)soma) / lista->quantidade;
	return media;
}

Lista *copiarSemRepeticao(Lista *lista)
{
	if (lista == NULL || lista->inicio == NULL)
		return NULL;
	Lista *listaResultado = criarLista();
	cel *aux = lista->inicio;

	while (aux != NULL)
	{
		if (buscaLinear(listaResultado, aux->conteudo) == -1)
		{
			inserirFim(listaResultado, aux->conteudo);
		}
		aux = aux->proximo;
	}
	return listaResultado;
}

void inverter(Lista *lista)
{
	if (!(lista == NULL || lista->inicio == NULL || lista->inicio == lista->fim))
	{
		cel *aux = lista->inicio;
		cel *temp = NULL;

		while (aux != NULL)
		{
			temp = aux->anterior;

			aux->anterior = aux->proximo;
			aux->proximo = temp;
			aux = aux->anterior;
		}

		temp = lista->inicio;
		lista->inicio = lista->fim;
		lista->fim = temp;
	}
}

int *paraVetor(Lista *lista)
{
	if (lista == NULL)
		return NULL;
	int *vet = malloc(lista->quantidade * sizeof(int));
	if (vet == NULL)
		return NULL;

	cel *aux = lista->inicio;
	for (int i = 0; i < lista->quantidade; i++)
	{
		vet[i] = aux->conteudo;
		aux = aux->proximo;
	}
	return vet;
}

int saoIguais(Lista *lista1, Lista *lista2)
{
	if (lista1 == NULL || lista2 == NULL || lista1->quantidade != lista2->quantidade)
		return 0;
	for (cel *aux1 = lista1->inicio, *aux2 = lista2->inicio; aux1 != NULL && aux2 != NULL; aux1 = aux1->proximo, aux2 = aux2->proximo)
	{
		if (aux1->conteudo != aux2->conteudo)
			return 0;
	}
	return 1;
}

int estaContida(Lista *lista1, Lista *lista2)
{
	if (lista1 == NULL || lista2 == NULL || lista1->quantidade < lista2->quantidade)
		return 0;
	for (cel *aux2 = lista2->inicio; aux2 != NULL; aux2 = aux2->proximo)
	{
		if (buscaLinear(lista1, aux2->conteudo) == -1)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	printf("--- Testando criarLista, inserirInicio, inserirFim, imprimirLista ---\n");
	Lista *l1 = criarLista();
	imprimirLista(l1);

	inserirInicio(l1, 10);
	imprimirLista(l1);

	inserirInicio(l1, 5);
	imprimirLista(l1);

	inserirFim(l1, 20);
	imprimirLista(l1);

	inserirFim(l1, 30);
	imprimirLista(l1); // l1 = 5 10 20 30

	Lista *l_vazia = criarLista();
	printf("\nLista vazia criada:\n");
	imprimirLista(l_vazia);

	printf("\n--- Testando buscaLinear ---\n");
	printf("Buscando 5 em l1 (inicio): %d\n", buscaLinear(l1, 5));
	printf("Buscando 20 em l1 (meio): %d\n", buscaLinear(l1, 20));
	printf("Buscando 30 em l1 (fim): %d\n", buscaLinear(l1, 30));
	printf("Buscando 99 em l1 (nao existe): %d\n", buscaLinear(l1, 99));
	printf("Buscando 10 em l_vazia: %d\n", buscaLinear(l_vazia, 10));

	printf("\n--- Testando removerElemento ---\n");
	Lista *l_remove = criarLista();
	inserirFim(l_remove, 1);
	inserirFim(l_remove, 2);
	inserirFim(l_remove, 3);
	inserirFim(l_remove, 4);
	inserirFim(l_remove, 5); // l_remove = 1 2 3 4 5
	imprimirLista(l_remove);

	printf("Removendo 99 (nao existe): %d\n", removerElemento(l_remove, 99));
	imprimirLista(l_remove);
	printf("Removendo 3 (meio): %d\n", removerElemento(l_remove, 3));
	imprimirLista(l_remove);
	printf("Removendo 1 (inicio): %d\n", removerElemento(l_remove, 1));
	imprimirLista(l_remove);
	printf("Removendo 5 (fim): %d\n", removerElemento(l_remove, 5));
	imprimirLista(l_remove);
	printf("Removendo 2: %d\n", removerElemento(l_remove, 2));
	imprimirLista(l_remove);
	printf("Removendo 4: %d\n", removerElemento(l_remove, 4));
	imprimirLista(l_remove);
	printf("Removendo de lista vazia: %d\n", removerElemento(l_remove, 1));
	imprimirLista(l_remove);
	liberarLista(l_remove);

	printf("\n--- Testando concatenarListas (cria nova) ---\n");
	Lista *l_cat1 = criarLista();
	inserirFim(l_cat1, 1);
	inserirFim(l_cat1, 2);
	Lista *l_cat2 = criarLista();
	inserirFim(l_cat2, 3);
	inserirFim(l_cat2, 4);
	printf("l_cat1: ");
	imprimirLista(l_cat1);
	printf("l_cat2: ");
	imprimirLista(l_cat2);

	Lista *l_cat_res1 = concatenarListas(l_cat1, l_cat2);
	printf("Resultado (l_cat1 + l_cat2): ");
	imprimirLista(l_cat_res1);
	printf("l_cat1 (original deve ser mantido): ");
	imprimirLista(l_cat1);
	printf("l_cat2 (original deve ser mantido): ");
	imprimirLista(l_cat2);
	liberarLista(l_cat_res1);

	Lista *l_cat_res2 = concatenarListas(l_cat1, l_vazia);
	printf("Resultado (l_cat1 + l_vazia): ");
	imprimirLista(l_cat_res2);
	liberarLista(l_cat_res2);

	Lista *l_cat_res3 = concatenarListas(l_vazia, l_cat2);
	printf("Resultado (l_vazia + l_cat2): ");
	imprimirLista(l_cat_res3);
	liberarLista(l_cat_res3);
	liberarLista(l_cat1);
	liberarLista(l_cat2);

	printf("\n--- Testando concatenarLista (modifica l1) ---\n");
	Lista *l_mod1 = criarLista();
	inserirFim(l_mod1, 1);
	inserirFim(l_mod1, 2);
	Lista *l_mod2 = criarLista();
	inserirFim(l_mod2, 3);
	inserirFim(l_mod2, 4);
	printf("l_mod1 (antes): ");
	imprimirLista(l_mod1);
	printf("l_mod2 (antes): ");
	imprimirLista(l_mod2);
	concatenarLista(l_mod1, l_mod2);
	printf("l_mod1 (depois): ");
	imprimirLista(l_mod1);
	printf("l_mod2 (depois - deve estar vazia): ");
	imprimirLista(l_mod2);
	liberarLista(l_mod2); // l_mod2 agora esta vazia, mas precisa liberar a struct

	Lista *l_mod3 = criarLista(); // Teste com l1 vazia
	Lista *l_mod4 = criarLista();
	inserirFim(l_mod4, 5);
	inserirFim(l_mod4, 6);
	printf("l_mod3 (antes): ");
	imprimirLista(l_mod3);
	printf("l_mod4 (antes): ");
	imprimirLista(l_mod4);
	concatenarLista(l_mod3, l_mod4);
	printf("l_mod3 (depois): ");
	imprimirLista(l_mod3);
	printf("l_mod4 (depois): ");
	imprimirLista(l_mod4);
	liberarLista(l_mod1);
	liberarLista(l_mod3);
	liberarLista(l_mod4);

	printf("\n--- Testando removerElementos (do inicio) ---\n");
	Lista *l_rem_n = criarLista();
	for (int i = 1; i <= 5; i++)
		inserirFim(l_rem_n, i); // l_rem_n = 1 2 3 4 5
	imprimirLista(l_rem_n);
	printf("Removendo 2 elementos:\n");
	removerElementos(l_rem_n, 2);
	imprimirLista(l_rem_n); // Deve ser 3 4 5
	printf("Removendo 0 elementos:\n");
	removerElementos(l_rem_n, 0);
	imprimirLista(l_rem_n); // Deve ser 3 4 5
	printf("Removendo 5 elementos (mais que o total):\n");
	removerElementos(l_rem_n, 5);
	imprimirLista(l_rem_n); // Deve ser vazia
	printf("Removendo de lista vazia:\n");
	removerElementos(l_rem_n, 2);
	imprimirLista(l_rem_n);
	liberarLista(l_rem_n);

	printf("\n--- Testando buscarMaiorElemento (indice) ---\n");
	Lista *l_maior = criarLista();
	inserirFim(l_maior, 10);
	inserirFim(l_maior, 50);
	inserirFim(l_maior, 20);
	inserirFim(l_maior, 70);
	inserirFim(l_maior, 70);
	inserirFim(l_maior, 30); // l_maior = 10 50 20 70 70 30
	imprimirLista(l_maior);
	printf("Indice do maior: %d\n", buscarMaiorElemento(l_maior));
	liberarLista(l_maior);
	printf("Indice do maior (lista vazia): %d\n", buscarMaiorElemento(l_vazia));

	printf("\n--- Testando quantidadeDePares ---\n");
	Lista *l_pares = criarLista();
	inserirFim(l_pares, 1);
	inserirFim(l_pares, 2);
	inserirFim(l_pares, 3);
	inserirFim(l_pares, 4);
	inserirFim(l_pares, 5);
	inserirFim(l_pares, 6); // l_pares = 1 2 3 4 5 6
	imprimirLista(l_pares);
	printf("Qtd pares: %d\n", quantidadeDePares(l_pares));
	Lista *l_impares = criarLista();
	inserirFim(l_impares, 1);
	inserirFim(l_impares, 3);
	imprimirLista(l_impares);
	printf("Qtd pares (so impares): %d\n", quantidadeDePares(l_impares));
	printf("Qtd pares (lista vazia): %d\n", quantidadeDePares(l_vazia));
	liberarLista(l_pares);
	liberarLista(l_impares);

	printf("\n--- Testando media ---\n");
	Lista *l_media = criarLista();
	inserirFim(l_media, 10);
	inserirFim(l_media, 20);
	inserirFim(l_media, 30); // l_media = 10 20 30
	imprimirLista(l_media);
	printf("Media: %.2f\n", media(l_media));
	Lista *l_media2 = criarLista();
	inserirFim(l_media2, 1);
	inserirFim(l_media2, 2); // l_media2 = 1 2
	imprimirLista(l_media2);
	printf("Media: %.2f\n", media(l_media2));
	printf("Media (lista vazia): %.2f\n", media(l_vazia));
	liberarLista(l_media);
	liberarLista(l_media2);

	printf("\n--- Testando copiarSemRepeticao ---\n");
	Lista *l_rep = criarLista();
	inserirFim(l_rep, 1);
	inserirFim(l_rep, 2);
	inserirFim(l_rep, 2);
	inserirFim(l_rep, 3);
	inserirFim(l_rep, 1);
	inserirFim(l_rep, 4);
	inserirFim(l_rep, 5);
	inserirFim(l_rep, 4);
	imprimirLista(l_rep);
	Lista *l_sem_rep = copiarSemRepeticao(l_rep);
	printf("Copia sem repeticao: ");
	imprimirLista(l_sem_rep);
	liberarLista(l_rep);
	liberarLista(l_sem_rep);
	Lista *l_sem_rep2 = copiarSemRepeticao(l_vazia);
	printf("Copia sem repeticao (lista vazia): ");
	imprimirLista(l_sem_rep2); // Deve ser NULL
	liberarLista(l_sem_rep2);

	printf("\n--- Testando inverter ---\n");
	Lista *l_inv = criarLista();
	for (int i = 1; i <= 5; i++)
		inserirFim(l_inv, i); // l_inv = 1 2 3 4 5
	printf("Antes de inverter: ");
	imprimirLista(l_inv);
	inverter(l_inv);
	printf("Depois de inverter: ");
	imprimirLista(l_inv); // l_inv = 5 4 3 2 1
	inverter(l_inv);
	printf("Depois de inverter de novo: ");
	imprimirLista(l_inv); // l_inv = 1 2 3 4 5
	liberarLista(l_inv);

	Lista *l_inv2 = criarLista();
	inserirFim(l_inv2, 1);
	printf("\nAntes de inverter (1 elem): ");
	imprimirLista(l_inv2);
	inverter(l_inv2);
	printf("Depois de inverter (1 elem): ");
	imprimirLista(l_inv2);
	liberarLista(l_inv2);

	printf("\nInvertendo lista vazia:\n");
	imprimirLista(l_vazia);
	inverter(l_vazia);
	imprimirLista(l_vazia);

	printf("\n--- Testando paraVetor ---\n");
	// l1 = 5 10 20 30
	printf("Lista l1: ");
	imprimirLista(l1);
	int *vet = paraVetor(l1);
	if (vet != NULL)
	{
		printf("Vetor: ");
		for (int i = 0; i < l1->quantidade; i++)
		{
			printf("%d ", vet[i]);
		}
		printf("\n");
		free(vet);
	}
	printf("Vetor de lista vazia:\n");
	int *vet_vazio = paraVetor(l_vazia);
	if (vet_vazio == NULL || l_vazia->quantidade == 0)
	{
		printf("(Vetor vazio ou NULL como esperado)\n");
	}
	free(vet_vazio); // free(NULL) é seguro

	printf("\n--- Testando saoIguais ---\n");
	Lista *l_i1 = criarLista();
	inserirFim(l_i1, 1);
	inserirFim(l_i1, 2);
	Lista *l_i2 = criarLista();
	inserirFim(l_i2, 1);
	inserirFim(l_i2, 2);
	Lista *l_i3 = criarLista();
	inserirFim(l_i3, 1);
	inserirFim(l_i3, 3);
	Lista *l_i4 = criarLista();
	inserirFim(l_i4, 1);
	imprimirLista(l_i1);
	imprimirLista(l_i2);
	imprimirLista(l_i3);
	imprimirLista(l_i4);
	printf("l_i1 e l_i2 sao iguais? %d\n", saoIguais(l_i1, l_i2));
	printf("l_i1 e l_i3 sao iguais? %d\n", saoIguais(l_i1, l_i3));
	printf("l_i1 e l_i4 (tam dif) sao iguais? %d\n", saoIguais(l_i1, l_i4));
	printf("l_vazia e l_vazia sao iguais? %d\n", saoIguais(l_vazia, l_vazia));
	printf("l_i1 e l_vazia sao iguais? %d\n", saoIguais(l_i1, l_vazia));
	liberarLista(l_i1);
	liberarLista(l_i2);
	liberarLista(l_i3);
	liberarLista(l_i4);

	printf("\n--- Testando estaContida ---\n");
	Lista *l_contem = criarLista();
	for (int i = 1; i <= 5; i++)
		inserirFim(l_contem, i); // 1 2 3 4 5
	Lista *l_contida = criarLista();
	inserirFim(l_contida, 3);
	inserirFim(l_contida, 1); // 3 1
	Lista *l_nao_contida = criarLista();
	inserirFim(l_nao_contida, 3);
	inserirFim(l_nao_contida, 6); // 3 6
	Lista *l_maior_contida = criarLista();
	for (int i = 1; i <= 6; i++)
		inserirFim(l_maior_contida, i); // 1 2 3 4 5 6

	imprimirLista(l_contem);
	imprimirLista(l_contida);
	imprimirLista(l_nao_contida);
	imprimirLista(l_maior_contida);
	printf("l_contem contem l_contida? %d\n", estaContida(l_contem, l_contida));
	printf("l_contem contem l_nao_contida? %d\n", estaContida(l_contem, l_nao_contida));
	printf("l_contem contem l_maior_contida? %d\n", estaContida(l_contem, l_maior_contida));
	printf("l_contem contem l_vazia? %d\n", estaContida(l_contem, l_vazia));
	printf("l_vazia contem l_contida? %d\n", estaContida(l_vazia, l_contida));
	liberarLista(l_contem);
	liberarLista(l_contida);
	liberarLista(l_nao_contida);
	liberarLista(l_maior_contida);

	printf("\n--- Testando liberarLista ---\n");
	liberarLista(l1);
	liberarLista(l_vazia);
	printf("Listas l1 e l_vazia liberadas.\n");
	printf("Testando liberar lista NULL:\n");
	liberarLista(NULL);
	printf("Teste de liberar NULL concluido (se nao houve crash).\n");

	printf("\n--- FIM DOS TESTES ---\n");

	return 0;
}