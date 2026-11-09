#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // Para uso do português



typedef struct livros {
    unsigned int identificador; // Identificador único
    char titulo[100]; 
    unsigned int quantidade_emprestimos; // Quantidade de empréstimos feitos no nome do livro [CRITÉRIO RELEVANTE]
    unsigned int ano_publicacao;
    unsigned int volume;
    int disponivel; 
    char autor[100];
    struct livros *proximo; // Usado APENAS quando o livro estiver na lista da Hash
  
} Livros;

typedef struct head {
    Livros *primeiro;
    int quantidade_livros;
} Head;

typedef struct hashlivrosidentificador {
    Head resto0;
    Head resto1;
    Head resto2;
    Head resto3;
    int N; // Número de registros ativos para calcular a carga
} HashLivrosIdentificador;

// --- PROTÓTIPOS DAS FUNÇÕES ---

void menu();
void inicializar_hash(HashLivrosIdentificador *hli);

// Funções de Gerenciamento e Cadastro
int cadastrar_livro(HashLivrosIdentificador *hli, Livros livro);
int editar_livro(HashLivrosIdentificador *hli, unsigned int identificador);



// --- FUNÇÃO PRINCIPAL ---

int main(){
    setlocale(LC_ALL, "Portuguese"); // Define linguagem em PT

    HashLivrosIdentificador minha_hash;
    inicializar_hash(&minha_hash);

    int sair = 0;
    int opcao = 0;
    unsigned int id_busca = 0;

    // Estrutura para dados sem Hash
    Livros *livros = malloc(sizeof(Livros)*50);
    int livro_scapacidade = 50;
    int livro_quantidade = 0;
    //

    // Estrutura de dados com Hash
    HashLivrosIdentificador *hli = malloc(sizeof(HashLivrosIdentificador));
    hli->resto0.quantidade_livros = 0;
    hli->resto0.primeiro = NULL;

    hli->resto0.quantidade_livros = 0;
    hli->resto0.primeiro = NULL;

    hli->resto1.quantidade_livros = 0;
    hli->resto1.primeiro = NULL;

    hli->resto2.quantidade_livros = 0;
    hli->resto2.primeiro = NULL;

    hli->resto3.quantidade_livros = 0;
    hli->resto3.primeiro = NULL;
    // 
     
    while(sair == 0){
        menu();
        printf("Opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        switch (opcao) {
            case 1: {
                Livros novoLivro;
                printf("Digite o nome do livro:");
                fgets(nome, sizeof(nome), stdin); // Captura a entrada completa
nome[strcspn(nome, '
')] = 0; // Remove a nova linha fina
                cadastrar_livro(&minha_hash, novo_livro);
                break;
            }
            case 2:
                printf("Digite o ID para Busca Sequencial: ");
                scanf("%u", &id_busca);
                busca_sequencial(&minha_hash, id_busca);
                break;
            case 3:
                printf("Digite o ID para Divisão Binária: ");
                scanf("%u", &id_busca);
                busca_binaria(&minha_hash, id_busca);
                break;
            case 4:
                printf("Digite o ID para Busca Sequencial Indexada: ");
                scanf("%u", &id_busca);
                busca_sequencial_indexada(&minha_hash, id_busca);
                break;
            case 5:
                printf("Digite o ID do livro para Editar: ");
                scanf("%u", &id_busca);
                editar_livro(&minha_hash, id_busca);
                break;
            case 6:
                gerar_relatorio_ordenado(&minha_hash, 6); // 6 = Insertion
                break;
            case 7:
                gerar_relatorio_ordenado(&minha_hash, 7); // 7 = Merge
                break;
            case 8:
                gerar_relatorio_ordenado(&minha_hash, 8); // 8 = Heap
                break;
            case 9:
                exportar_base_dados(&minha_hash, "base_dados.txt");
                break;
            case 10:
                importar_base_dados(&minha_hash, "base_dados.txt");
                break;
            case 0:
                sair = 1;
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    }
    return 0;
}


int cadastrar_livro(HashLivrosIdentificador *hli, Livros livro){
    // Insert no cadastro com Hash
    

    
}


// --- IMPLEMENTAÇÃO DO MENU ---

void menu(){
     printf("\n========= SISTEMA BIBLIOTECÁRIO ========\n");
     printf("Escolha uma opção:\n");  
     printf("1 - Cadastrar Novo Livro\n");          
     printf("== Pesquisar Por Livro: == \n 2 - Método Sequencial\n");  
     printf("3 - Método Divisão Binária\n");
     printf("4 - Método Sequencial Indexado \n");
     printf("5 - Editar Livro\n");
     printf("== Gerar Relatório Ordenado por Livros Mais Emprestados == \n"); 
     printf("6 - Método Insertion Sort\n");
     printf("7 - Método Merge Sort\n");
     printf("8 - Método Heapsort\n");
     printf("9 - Exportar Base De Dados\n");   
     printf("10 - Importar Base de Dados\n"); 
     printf("0 - Sair do Sistema\n");
     printf("Obs.: Métricas dos experimentos é salva em metricas_experimentos.csv durante execução do sistema.\n"); 
}
