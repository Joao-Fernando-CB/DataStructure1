#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

// Função para criar um novo nó
No* criarNo(int valor) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    novo->dado = valor;
    novo->prox = NULL;
    return novo;
}

// Inserir no início da lista
void inserirInicio(No **inicio, int valor) {
    No *novo = criarNo(valor);
    novo->prox = *inicio;
    *inicio = novo;
}

// Inserir no fim da lista
void inserirFim(No **inicio, int valor) {
    No *novo = criarNo(valor);
    if (*inicio == NULL) {
        *inicio = novo;
        return;
    }
    No *atual = *inicio;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = novo;
}

// Imprimir todos os elementos da lista
void imprimirLista(No *inicio) {
    No *atual = inicio;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// Liberar a memória alocada pela lista
void liberarLista(No **inicio) {
    No *atual = *inicio;
    No *prox;
    while (atual != NULL) {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
    *inicio = NULL;
}

int main() {
    No *lista = NULL; // Lista inicialmente vazia

    // Inserindo elementos
    inserirInicio(&lista, 10);
    inserirInicio(&lista, 5);
    inserirFim(&lista, 20);
    inserirFim(&lista, 30);

    // Exibindo a lista: 5 -> 10 -> 20 -> 30 -> NULL
    imprimirLista(lista);

    // Liberando a memória alocada
    liberarLista(&lista);

    return 0;
}