#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PRODUTOS 500

typedef struct {
    int codigo;
    char nome[60];
    char categoria[30];
    float preco;
    int estoque;
} Produto;

// Inicialização do array global com os 15 produtos de teste
Produto produtos[MAX_PRODUTOS] = {
    {1042, "Teclado Mecânico", "Periféricos", 249.90, 12},
    {1007, "Mouse Sem Fio", "Periféricos", 119.50, 31},
    {1078, "Monitor 24", "Monitores", 899.00, 8},
    {1015, "Cabo HDMI", "Cabos", 39.90, 55},
    {1091, "SSD 1TB", "Armazenamento", 449.00, 14},
    {1033, "Webcam Full HD", "Vídeo", 189.90, 9},
    {1064, "Headset USB", "Áudio", 159.90, 23},
    {1021, "Hub USB", "Acessórios", 89.90, 17},
    {1085, "Memória 16GB", "Memória", 279.00, 26},
    {1056, "Suporte Notebook", "Acessórios", 79.90, 35},
    {1103, "Fonte 650W", "Energia", 389.00, 7},
    {1011, "Adaptador Bluetooth", "Acessórios", 54.90, 42},
    {1071, "HD Externo 2TB", "Armazenamento", 529.90, 11},
    {1048, "Microfone USB", "Áudio", 299.00, 6},
    {1097, "Notebook Stand Pro", "Acessórios", 139.90, 19}
};

int quantidade = 15;

// Protótipos das funções
void listarProdutos();
int cadastrarProduto();
int buscaSequencialCodigo(int codigo);
int buscaSequencialNome(const char* nome);
int buscaBinariaCodigo(int codigo);
int selectionSort();
int insertionSort();
int bubbleSort();
int merge(Produto arr[], int left, int mid, int right);
int mergeSort(Produto arr[], int left, int right);  
int ordenarPorPreco();
int exibirEstoqueBaixo(int limite);

// Funções auxiliares para ligação com o menu
void buscarProdutoPorCodigo();
void buscarProdutoPorNome();
void buscarProdutoBinario();
void ordenarProdutosSelectionSort();
void ordenarProdutosInsertionSort();
void ordenarProdutosBubbleSort();
void ordenarProdutosMergeSort();
void ordenarProdutosPorPreco();
void exibirProdutosEstoqueBaixo();
int compararAlgoritmosOrdenacao();
int compararMetodosBusca();

// --- Implementação das Funções Principais ---

int cadastrarProduto() {
    if (quantidade >= MAX_PRODUTOS) {
        printf("\nLimite de produtos atingido.\n");
        return -1;
    }

    int codigo;
    while (1) {
        printf("\nDigite o código do produto: ");
        scanf("%d", &codigo);
        getchar(); // Limpar o buffer do teclado

        if (buscaSequencialCodigo(codigo) != -1) {
            printf("Produto com código %d já existe. Tente outro código.\n", codigo);
        } else {
            break;
        }
    }

    Produto novoProduto;
    novoProduto.codigo = codigo;

    printf("Digite o nome do produto: ");
    fgets(novoProduto.nome, sizeof(novoProduto.nome), stdin);
    novoProduto.nome[strcspn(novoProduto.nome, "\n")] = 0;

    printf("Digite a categoria do produto: ");
    fgets(novoProduto.categoria, sizeof(novoProduto.categoria), stdin);
    novoProduto.categoria[strcspn(novoProduto.categoria, "\n")] = 0;

    printf("Digite o preço do produto: ");
    scanf("%f", &novoProduto.preco);

    printf("Digite a quantidade em estoque: ");
    scanf("%d", &novoProduto.estoque);

    produtos[quantidade] = novoProduto;
    quantidade++;

    printf("\nProduto cadastrado com sucesso!\n");
    return 0;
}

int buscaSequencialCodigo(int codigo) {
    for (int i = 0; i < quantidade; i++) {
        if (produtos[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

int buscaSequencialNome(const char* nome) {
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(produtos[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1;
}

int buscaBinariaCodigo(int codigo) {
    int esquerda = 0;
    int direita = quantidade - 1;

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        if (produtos[meio].codigo == codigo) {
            return meio;
        } else if (produtos[meio].codigo < codigo) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return -1;
}

int selectionSort() {
    for (int i = 0; i < quantidade - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < quantidade; j++) {
            if (produtos[j].codigo < produtos[minIndex].codigo) {
                minIndex = j;
            }
        }
        Produto temp = produtos[i];
        produtos[i] = produtos[minIndex];
        produtos[minIndex] = temp;
    }
    return 0;
}

int insertionSort() {
    for (int i = 1; i < quantidade; i++) {
        Produto key = produtos[i];
        int j = i - 1;

        while (j >= 0 && produtos[j].codigo > key.codigo) {
            produtos[j + 1] = produtos[j];
            j--;
        }
        produtos[j + 1] = key;
    }
    return 0;
}

int bubbleSort() {
    for (int i = 0; i < quantidade - 1; i++) {
        for (int j = 0; j < quantidade - i - 1; j++) {
            if (produtos[j].codigo > produtos[j + 1].codigo) {
                Produto temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }
    return 0;
}

int merge(Produto arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Produto* L = (Produto*)malloc(n1 * sizeof(Produto));
    Produto* R = (Produto*)malloc(n2 * sizeof(Produto));

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].codigo <= R[j].codigo) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
    return 0;
}

int mergeSort(Produto arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
    return 0;
}

int ordenarPorPreco() {
    for (int i = 0; i < quantidade - 1; i++) {
        for (int j = 0; j < quantidade - i - 1; j++) {
            if (produtos[j].preco > produtos[j + 1].preco) {
                Produto temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }
    return 0;
}

int exibirEstoqueBaixo(int limite) {
    printf("\nProdutos com estoque abaixo de %d:\n", limite);
    printf("------------------------------------------------------------------\n");
    printf("%-7s | %-20s | %-15s | %-8s | %-7s\n", "Código", "Produto", "Categoria", "Preço", "Estoque");
    printf("------------------------------------------------------------------\n");
    
    int encontrado = 0;
    for (int i = 0; i < quantidade; i++) {
        if (produtos[i].estoque < limite) {
            printf("%-7d | %-20s | %-15s | %8.2f | %-7d\n", 
                   produtos[i].codigo, 
                   produtos[i].nome, 
                   produtos[i].categoria, 
                   produtos[i].preco, 
                   produtos[i].estoque);
            encontrado = 1;
        }
    }
    
    if (!encontrado) {
        printf("Nenhum produto encontrado com estoque abaixo de %d.\n", limite);
    }
    
    printf("------------------------------------------------------------------\n");
    return 0;
}

void listarProdutos() {
    printf("\nLista de Produtos:\n");
    printf("------------------------------------------------------------------\n");
    printf("%-7s | %-20s | %-15s | %-8s | %-7s\n", "Código", "Produto", "Categoria", "Preço", "Estoque");
    printf("------------------------------------------------------------------\n");
    
    for (int i = 0; i < quantidade; i++) {
        printf("%-7d | %-20s | %-15s | %8.2f | %-7d\n", 
               produtos[i].codigo, 
               produtos[i].nome, 
               produtos[i].categoria, 
               produtos[i].preco, 
               produtos[i].estoque);
    }
    printf("------------------------------------------------------------------\n");
}

// --- Funções Auxiliares da Interface do Menu ---

void buscarProdutoPorCodigo() {
    int codigo;
    printf("\nDigite o código do produto: ");
    scanf("%d", &codigo);
    
    int pos = buscaSequencialCodigo(codigo);
    if (pos != -1) {
        printf("\nProduto Encontrado:\n");
        printf("Código: %d | Nome: %s | Categoria: %s | Preço: R$ %.2f | Estoque: %d\n",
               produtos[pos].codigo, produtos[pos].nome, produtos[pos].categoria, produtos[pos].preco, produtos[pos].estoque);
    } else {
        printf("\nProduto com código %d não encontrado.\n", codigo);
    }
}

void buscarProdutoPorNome() {
    char nome[60];
    printf("\nDigite o nome exato do produto: ");
    getchar(); // Limpar buffer
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    int pos = buscaSequencialNome(nome);
    if (pos != -1) {
        printf("\nProduto Encontrado:\n");
        printf("Código: %d | Nome: %s | Categoria: %s | Preço: R$ %.2f | Estoque: %d\n",
               produtos[pos].codigo, produtos[pos].nome, produtos[pos].categoria, produtos[pos].preco, produtos[pos].estoque);
    } else {
        printf("\nProduto '%s' não encontrado.\n", nome);
    }
}

void buscarProdutoBinario() {
    int codigo;
    printf("\n[Nota: Ordenando por código para permitir a busca binária...]\n");
    selectionSort();

    printf("Digite o código do produto para busca binária: ");
    scanf("%d", &codigo);

    int pos = buscaBinariaCodigo(codigo);
    if (pos != -1) {
        printf("\nProduto Encontrado:\n");
        printf("Código: %d | Nome: %s | Categoria: %s | Preço: R$ %.2f | Estoque: %d\n",
               produtos[pos].codigo, produtos[pos].nome, produtos[pos].categoria, produtos[pos].preco, produtos[pos].estoque);
    } else {
        printf("\nProduto com código %d não encontrado.\n", codigo);
    }
}

void ordenarProdutosSelectionSort() {
    selectionSort();
    printf("\nProdutos ordenados por código (Selection Sort) com sucesso!\n");
    listarProdutos();
}

void ordenarProdutosInsertionSort() {
    insertionSort();
    printf("\nProdutos ordenados por código (Insertion Sort) com sucesso!\n");
    listarProdutos();
}

void ordenarProdutosBubbleSort() {
    bubbleSort();
    printf("\nProdutos ordenados por código (Bubble Sort) com sucesso!\n");
    listarProdutos();
}

void ordenarProdutosMergeSort() {
    mergeSort(produtos, 0, quantidade - 1);
    printf("\nProdutos ordenados por código (Merge Sort) com sucesso!\n");
    listarProdutos();
}

void ordenarProdutosPorPreco() {
    ordenarPorPreco();
    printf("\nProdutos ordenados por preço com sucesso!\n");
    listarProdutos();
}

void exibirProdutosEstoqueBaixo() {
    int limite;
    printf("\nDigite o valor limite de estoque: ");
    scanf("%d", &limite);
    exibirEstoqueBaixo(limite);
}

int compararAlgoritmosOrdenacao() {
    printf("\n=== Comparativo de Algoritmos de Ordenação ===\n");
    printf("Testando ordenação no conjunto atual (%d produtos):\n\n", quantidade);

    Produto copia[MAX_PRODUTOS];
    clock_t inicio, fim;
    double tempo;

    // Selection Sort
    memcpy(copia, produtos, sizeof(Produto) * quantidade);
    inicio = clock();
    for(int k = 0; k < 10000; k++) { // Repetições para medição precisa em conjuntos pequenos
        memcpy(copia, produtos, sizeof(Produto) * quantidade);
        selectionSort();
    }
    fim = clock();
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("- Selection Sort: tempo médio de execução concluído (%.6f segundos / 10 mil iterações)\n", tempo);

    // Insertion Sort
    memcpy(copia, produtos, sizeof(Produto) * quantidade);
    inicio = clock();
    for(int k = 0; k < 10000; k++) {
        memcpy(copia, produtos, sizeof(Produto) * quantidade);
        insertionSort();
    }
    fim = clock();
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("- Insertion Sort: tempo médio de execução concluído (%.6f segundos / 10 mil iterações)\n", tempo);

    // Bubble Sort
    memcpy(copia, produtos, sizeof(Produto) * quantidade);
    inicio = clock();
    for(int k = 0; k < 10000; k++) {
        memcpy(copia, produtos, sizeof(Produto) * quantidade);
        bubbleSort();
    }
    fim = clock();
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("- Bubble Sort   : tempo médio de execução concluído (%.6f segundos / 10 mil iterações)\n", tempo);

    // Merge Sort
    memcpy(copia, produtos, sizeof(Produto) * quantidade);
    inicio = clock();
    for(int k = 0; k < 10000; k++) {
        memcpy(copia, produtos, sizeof(Produto) * quantidade);
        mergeSort(copia, 0, quantidade - 1);
    }
    fim = clock();
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("- Merge Sort    : tempo médio de execução concluído (%.6f segundos / 10 mil iterações)\n", tempo);

    return 0;
}

int compararMetodosBusca() {
    printf("\n=== Comparativo de Métodos de Busca ===\n");
    printf("1. Busca Sequencial: Complexidade O(n) - Percorre elemento a elemento. Funciona em listas desordenadas.\n");
    printf("2. Busca Binária   : Complexidade O(log n) - Divide o vetor ao meio. Requer vetor previamente ordenado por código.\n\n");
    
    int codigoProcurado = produtos[quantidade - 1].codigo; // Pior caso na busca sequencial
    
    printf("Testando busca para o código %d:\n", codigoProcurado);
    int posSeq = buscaSequencialCodigo(codigoProcurado);
    selectionSort();
    int posBin = buscaBinariaCodigo(codigoProcurado);

    printf("- Busca Sequencial encontrou no índice: %d\n", posSeq);
    printf("- Busca Binária encontrou no índice: %d\n", posBin);

    return 0;
}

// --- Função Principal ---

int main() {
    int opcao;

    do {
        printf("\n=================================================\n");
        printf("          SISTEMA DE CATALOGO DE PRODUTOS\n");
        printf("=================================================\n\n");
        printf("1 - Listar produtos\n");
        printf("2 - Cadastrar produto\n\n");
        printf("3 - Busca sequencial por codigo\n");
        printf("4 - Busca sequencial por nome\n");
        printf("5 - Busca binaria por codigo\n\n");
        printf("6 - Ordenar por codigo - Selection Sort\n");
        printf("7 - Ordenar por codigo - Insertion Sort\n");
        printf("8 - Ordenar por codigo - Bubble Sort\n");
        printf("9 - Ordenar por codigo - Merge Sort\n\n");
        printf("10 - Ordenar produtos por preco\n");
        printf("11 - Exibir produtos com estoque baixo\n\n");
        printf("12 - Comparar algoritmos de ordenacao\n");
        printf("13 - Comparar metodos de busca\n\n");
        printf("0 - Sair\n\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                listarProdutos();
                break;
            case 2:
                cadastrarProduto();
                break;
            case 3:
                buscarProdutoPorCodigo();
                break;
            case 4:
                buscarProdutoPorNome();
                break;
            case 5:
                buscarProdutoBinario();
                break;
            case 6:
                ordenarProdutosSelectionSort();
                break;
            case 7:
                ordenarProdutosInsertionSort();
                break;
            case 8:
                ordenarProdutosBubbleSort();
                break;
            case 9:
                ordenarProdutosMergeSort();
                break;
            case 10:
                ordenarProdutosPorPreco();
                break;
            case 11:
                exibirProdutosEstoqueBaixo();
                break;
            case 12:
                compararAlgoritmosOrdenacao();
                break;
            case 13:
                compararMetodosBusca();
                break;
            case 0:
                printf("\nSaindo do sistema...\n");
                break;
            default:
                printf("\nOpção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}