#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
	int info;
	struct NO *esq;
	struct NO *dir;
} NO;

typedef struct NO* ArvBin;

ArvBin* cria_ArvBin() {
	ArvBin *raiz = (ArvBin *) malloc(sizeof(ArvBin));
	if(raiz != NULL) {
		*raiz = NULL;
	}
	return raiz;
}

void preOrdem(ArvBin *raiz) {
	if (raiz != NULL && *raiz != NULL) {
		printf("%d ", (*raiz)->info);
		preOrdem(&((*raiz)->esq));
		preOrdem(&((*raiz)->dir));
	}

}

void emOrdem(ArvBin *raiz) {
	if (raiz != NULL && *raiz != NULL) {
		emOrdem(&((*raiz)->esq));
		printf("%d ", (*raiz)->info);
		emOrdem(&((*raiz)->dir));
	}
}

void posOrdem(ArvBin *raiz) {
	if (raiz != NULL && *raiz != NULL) {
		posOrdem(&((*raiz)->esq));
		posOrdem(&((*raiz)->dir));
		printf("%d ", (*raiz)->info);
	}
}

int totalNosArvBin(ArvBin *raiz) {

	if (raiz != NULL && *raiz != NULL) {
		return totalNosArvBin(&((*raiz)->esq)) + totalNosArvBin(&((*raiz)->dir)) + 1;
	}
	return 0;
}

int alturaArvBin(ArvBin *raiz) {
	if (raiz == NULL || *raiz == NULL) return -1;
	int esq = alturaArvBin(&((*raiz)->esq));
	int dir = alturaArvBin(&((*raiz)->dir));
	if (esq > dir) return esq + 1;
	return dir + 1;
}

int inserirElemento(ArvBin *raiz, int valor) {
	if (raiz == NULL) return 0;
	
	NO* no = (NO*) malloc(sizeof(NO));
	if (no == NULL) return 0;
	no->info = valor;
	no->dir = NULL;
	no->esq = NULL;
	
	if(*raiz == NULL) *raiz = no;
	else {
	    NO* atual = *raiz;
	    NO* anterior = NULL;
	    while(atual != NULL) {
	        anterior = atual;
	        if(valor == atual->info) {
	            free(no);
	            return 0;
	        }
	        if (valor > atual->info) {
	            atual = atual->dir;
	        } else {
	            atual = atual->esq;
	        }
	    }
	    if (valor > anterior->info) anterior->dir = no;
	    else anterior->esq = no;
	}
    return 1;
}

int inserirElementoRecursivo(ArvBin *raiz, int valor) {
    if (raiz == NULL) return 0;

    if (*raiz == NULL) {
        NO* no = (NO*) malloc(sizeof(NO));
        if (no == NULL) return 0;
        no->info = valor;
        no->esq = no->dir = NULL;
        *raiz = no;
        return 1;
    } 
    else {
        if (valor < (*raiz)->info)
            return inserirElementoRecursivo(&((*raiz)->esq), valor);
        else if (valor > (*raiz)->info)
            return inserirElementoRecursivo(&((*raiz)->dir), valor);
        else
            return 0;
    }
}


void liberarNo(NO *no) {
    if (no != NULL) {
        liberarNo(no->esq);
        liberarNo(no->dir);
        free(no);
        no = NULL;
    }
}
void liberarArvBin(ArvBin *raiz) {
    if (raiz != NULL) {
        liberarNo(*raiz);
        free(raiz);
        raiz = NULL;
    }
}

int buscarElemento(ArvBin *raiz, int valor) {
	if(raiz == NULL || *raiz == NULL) return 0;
	if (((*raiz)->info) == valor) return 1;

	if (((*raiz)->info) > valor)
		return buscarElemento(&((*raiz)->esq), valor);
	else
		return buscarElemento(&((*raiz)->dir), valor);

}

NO *removerAtual(NO* atual) {
    NO *no1, *no2;
    if(atual->esq == NULL) {
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    // buscando o nó mais a direita da subárvore da esquerda
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL) {
        no1 = no2;
        no2 = no2->dir;
    }
    
    if(no1 != atual) {
        no1->dir = no2->esq;
        no2->esq = atual->dir;
    }
    
    no2->dir = atual->dir;
    free(atual);
    return no2;
}

int removeArvBin(ArvBin *raiz, int valor) {
    if (raiz == NULL || *raiz == NULL) return 0;
    NO *anterior = NULL;
    NO *atual = *raiz;
    while(atual != NULL) {
        if (valor == atual->info) {
            if(atual == *raiz) *raiz = removerAtual(atual);
            else if (anterior->dir == atual) anterior->dir = removerAtual(atual);
            else anterior->esq = removerAtual(atual);
            return 1;
        }
        
        anterior = atual;
        if (valor > atual->info) atual = atual->dir;
        else atual = atual->esq;
    }
    return 0;
}

int main()
{
	printf("Inicio\n");
	ArvBin *raiz = cria_ArvBin();

    inserirElemento(raiz, 10);
    inserirElemento(raiz, 20);
    inserirElemento(raiz, 30);
    inserirElemento(raiz, 40);
    inserirElemento(raiz, 35);
    inserirElemento(raiz, 25);
    inserirElemento(raiz, 37);
    inserirElemento(raiz, 32);
    inserirElemento(raiz, 31);
    inserirElemento(raiz, 36);
    inserirElemento(raiz, 39);


	printf("\n preOrdem: ");
	preOrdem(raiz);
	printf("\n emOrdem:  ");
	emOrdem(raiz);
	printf("\n posOrdem: ");
	posOrdem(raiz);
	printf("\n Quantidade de nos: %d", totalNosArvBin(raiz));
	printf("\n Altura da arvore: %d", alturaArvBin(raiz));
	
	removeArvBin(raiz, 31);
	printf("\n emOrdem:  ");
	emOrdem(raiz);
}
