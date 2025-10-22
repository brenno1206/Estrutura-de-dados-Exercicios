#include <stdio.h>
#include <stdlib.h>

typedef struct cel
{
    struct cel *proximo;
    int conteudo;
} cel;

typedef struct fila
{
    cel *inicio;
    cel *fim;
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
    int limite = 5;
    printf("Criando fila com limite: %d\n", limite);
    Fila *minhaFila = criarFila(limite);

    if (minhaFila == NULL)
    {
        printf("Erro ao criar fila.\n");
        return 1;
    }

    printf("Fila esta vazia (isEmpty)? %d\n", isEmpty(minhaFila));
    printf("Fila esta cheia (isFull)? %d\n", isFull(minhaFila));

    printf("\nEnfileirando 5 elementos...\n");
    printf("enqueue(10): %d\n", enqueue(minhaFila, 10));
    printf("enqueue(20): %d\n", enqueue(minhaFila, 20));
    printf("enqueue(30): %d\n", enqueue(minhaFila, 30));
    printf("enqueue(40): %d\n", enqueue(minhaFila, 40));
    printf("enqueue(50): %d\n", enqueue(minhaFila, 50));

    printf("\nFila atual: ");
    imprimirFila(minhaFila);

    printf("Fila esta vazia (isEmpty)? %d\n", isEmpty(minhaFila));
    printf("Fila esta cheia (isFull)? %d\n", isFull(minhaFila));

    printf("Tentando enfileirar mais um (enqueue(60)): %d\n", enqueue(minhaFila, 60));
    printf("Fila atual: ");
    imprimirFila(minhaFila);

    printf("\nDesenfileirando 3 elementos...\n");
    printf("dequeue(): %d\n", dequeue(minhaFila));
    printf("dequeue(): %d\n", dequeue(minhaFila));
    printf("dequeue(): %d\n", dequeue(minhaFila));

    printf("\nFila atual: ");
    imprimirFila(minhaFila);

    printf("Fila esta cheia (isFull)? %d\n", isFull(minhaFila));
    printf("Fila esta vazia (isEmpty)? %d\n", isEmpty(minhaFila));

    printf("\nEnfileirando mais 2 elementos...\n");
    printf("enqueue(70): %d\n", enqueue(minhaFila, 70));
    printf("enqueue(80): %d\n", enqueue(minhaFila, 80));

    printf("\nFila atual: ");
    imprimirFila(minhaFila);

    printf("\nDesenfileirando todos elementos restantes...\n");
    printf("dequeue(): %d\n", dequeue(minhaFila));
    printf("dequeue(): %d\n", dequeue(minhaFila));
    printf("dequeue(): %d\n", dequeue(minhaFila));
    printf("dequeue(): %d\n", dequeue(minhaFila));

    printf("\nFila atual: ");
    imprimirFila(minhaFila);

    printf("Fila esta vazia (isEmpty)? %d\n", isEmpty(minhaFila));

    printf("Tentando desenfileirar de fila vazia (dequeue()): %d\n", dequeue(minhaFila));

    printf("\nLiberando fila...\n");
    liberarFila(minhaFila);
    printf("Fila liberada.\n");

    return 0;
}

Fila *criarFila(int limite)
{
    Fila *fila = malloc(sizeof(Fila));
    if (fila != NULL)
    {
        fila->inicio = NULL;
        fila->fim = NULL;
        fila->quantidade = 0;
        fila->limite = limite;
    }
    return fila;
}

int enqueue(Fila *fila, int valor)
{ // insere no final
    if (fila == NULL || fila->quantidade == fila->limite)
        return 0;

    cel *aux = malloc(sizeof(cel));
    if (aux == NULL)
        return 0;
    aux->conteudo = valor;
    aux->proximo = NULL;

    if (isEmpty(fila))
        fila->inicio = aux;
    else
        fila->fim->proximo = aux;
    fila->fim = aux;
    fila->quantidade++;

    return 1;
}

int dequeue(Fila *fila)
{ // retira no inicio
    if (fila == NULL || isEmpty(fila))
        return 0;
    cel *aux = fila->inicio;
    fila->inicio = fila->inicio->proximo;
    if (fila->inicio == NULL)
        fila->fim == NULL;
    free(aux);
    fila->quantidade--;
    return 1;
}

int isEmpty(Fila *fila)
{
    if (fila == NULL)
        return -1;
    return fila->inicio == NULL;
}

int isFull(Fila *fila)
{
    if (fila == NULL)
        return -1;
    return fila->quantidade == fila->limite;
}

void imprimirFila(Fila *fila)
{
    for (cel *aux = fila->inicio; aux != NULL; aux = aux->proximo)
    {
        printf("%d ", aux->conteudo);
    }
    printf("\n");
}

void liberarFila(Fila *fila)
{

    cel *aux = fila->inicio;
    while (aux != NULL)
    {
        cel *temp = aux;
        aux = aux->proximo;
        free(temp);
    }
    free(fila);
}
