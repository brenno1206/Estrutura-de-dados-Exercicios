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

void inserirElemento(ArvBin *raiz, int valor) {
	if (raiz == NULL) return;
	NO* no = (NO*) malloc(sizeof(NO));
	no->info = valor;
	no->dir = NULL;
	no->esq = NULL;
	if(*raiz == NULL) *raiz = no;
	else {
		if((*raiz)->info == valor) return;
		if(valor < (*raiz)->info) return inserirElemento(&((*raiz)->esq), valor);
		else return inserirElemento(&((*raiz)->dir), valor);
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

int main()
{
	printf("Inicio\n");
	ArvBin *raiz = cria_ArvBin();


	NO a,b, c, d, e, f, g, h, i;
	NO *converte = &a;

	a.info = 80;
	a.esq = &b;
	a.dir = &c;
	b.info = 60;
	b.esq = &d;
	b.dir = &e;
	c.info = 90;
	c.esq = &f;
	c.dir = &g;
	d.info = 50;
	d.esq = NULL;
	d.dir = NULL;
	e.info = 70;
	e.esq = &h;
	e.dir = NULL;
	h.info = 65;
	h.esq = NULL;
	h.dir = NULL;
	f.info = 85;
	f.esq = NULL;
	f.dir = NULL;
	g.info = 110;
	g.esq = &i;
	g.dir = NULL;
	i.info = 100;
	i.esq = NULL;
	i.dir = NULL;

	raiz = &converte;

	inserirElemento(raiz, 19);


	printf("\n 110: %d", buscarElemento(raiz, 110));
	printf("\n 50: %d", buscarElemento(raiz, 50));
	printf("\n 2: %d", buscarElemento(raiz, 2));
	printf("\n 4: %d", buscarElemento(raiz, 4));

	printf("\n preOrdem: ");
	preOrdem(raiz);
	printf("\n emOrdem:  ");
	emOrdem(raiz);
	printf("\n posOrdem: ");
	posOrdem(raiz);
	printf("\n Quantidade de nos: %d", totalNosArvBin(raiz));
	printf("\n Altura da arvore: %d", alturaArvBin(raiz));
}
