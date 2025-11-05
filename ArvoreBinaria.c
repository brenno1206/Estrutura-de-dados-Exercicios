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

// FAZER ALTURA FUNÇÃO DE ALTURA (MAIOR CAMINHO)

int main()
{
	printf("Inicio\n");
	ArvBin *raiz = cria_ArvBin();


	NO a,b, c, d, e, f, g, h, i;
	NO *converte = &a;

	a.info = 15;
	a.esq = &b;
	a.dir = &c;
	b.info = 20;
	b.esq = &d;
	b.dir = &e;
	c.info = 7;
	c.esq = &f;
	c.dir = &g;
	d.info = 2;
	d.esq = NULL;
	d.dir = NULL;
	e.info = 32;
	e.esq = &h;
	e.dir = NULL;
	h.info = 5;
	h.esq = NULL;
	h.dir = NULL;
	f.info = 3;
	f.esq = NULL;
	f.dir = NULL;
	g.info = 10;
	g.esq = &i;
	g.dir = NULL;
	i.info = 1;
	i.esq = NULL;
	i.dir = NULL;

	raiz = &converte;

	printf("preOrdem: ");
	preOrdem(raiz);
	printf("\nemOrdem:  ");
	emOrdem(raiz);
	printf("\nposOrdem: ");
	posOrdem(raiz);
	printf("\nQuantidade de nos: %d", totalNosArvBin(raiz));
}
