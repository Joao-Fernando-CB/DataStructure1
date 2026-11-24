#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *anterior;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    No *fim;
} ListaDupla;

void inicializarLista(ListaDupla *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
}

No *criarNo(int valor) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        return NULL;
    }

    novo->dado = valor;
    novo->anterior = NULL;
    novo->proximo = NULL;
    return novo;
}

int inserirInicio(ListaDupla *lista, int valor) {
    No *novo = criarNo(valor);
    if (novo == NULL) {
        return 0;
    }

    novo->proximo = lista->inicio;
    if (lista->inicio == NULL) {
        lista->fim = novo;
    } else {
        lista->inicio->anterior = novo;
    }
    lista->inicio = novo;
    return 1;
}

int inserirFim(ListaDupla *lista, int valor) {
    No *novo = criarNo(valor);
    if (novo == NULL) {
        return 0;
    }

    novo->anterior = lista->fim;
    if (lista->fim == NULL) {
        lista->inicio = novo;
    } else {
        lista->fim->proximo = novo;
    }
    lista->fim = novo;
    return 1;
}

void imprimirInicioFim(const ListaDupla *lista) {
    const No *atual = lista->inicio;
    printf("Inicio -> ");
    while (atual != NULL) {
        printf("%d", atual->dado);
        if (atual->proximo != NULL) {
            printf(" <-> ");
        }
        atual = atual->proximo;
    }
    printf(" <- Fim\n");
}

void imprimirFimInicio(const ListaDupla *lista) {
    const No *atual = lista->fim;
    printf("Fim -> ");
    while (atual != NULL) {
        printf("%d", atual->dado);
        if (atual->anterior != NULL) {
            printf(" <-> ");
        }
        atual = atual->anterior;
    }
    printf(" <- Inicio\n");
}

void liberarLista(ListaDupla *lista) {
    No *atual = lista->inicio;
    while (atual != NULL) {
        No *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    inicializarLista(lista);
}

int main(void) {
    ListaDupla lista;
    inicializarLista(&lista);

    if (!inserirInicio(&lista, 20) ||
        !inserirInicio(&lista, 10) ||
        !inserirFim(&lista, 30) ||
        !inserirFim(&lista, 40)) {
        fprintf(stderr, "Erro ao alocar memoria para a lista.\n");
        liberarLista(&lista);
        return 1;
    }

    imprimirInicioFim(&lista);
    imprimirFimInicio(&lista);
    liberarLista(&lista);
    return 0;
}