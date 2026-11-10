#ifndef LIVRO_HASH_H
#define LIVRO_HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro_hash.h"

typedef struct livros {
    unsigned int identificador;
    char titulo[100]; 
    unsigned int quantidade_emprestimos;
    unsigned int ano_publicacao;
    unsigned int volume;
    int disponivel; 
    char autor[100];
    struct livros *proximo;
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
    int N; // Número total de registros ativos
} HashLivrosIdentificador;

// --- PROTÓTIPOS DAS FUNÇÕES ---

void inicializar_hash(HashLivrosIdentificador *hli);
void menu();

// Gerenciamento e Cadastro
int cadastrar_livro(HashLivrosIdentificador *hli, Livros livro);
int editar_livro(HashLivrosIdentificador *hli, unsigned int identificador);
int emprestar_livro(HashLivrosIdentificador *hli, unsigned int identificador);

// Métodos de Busca
Livros* busca_sequencial(HashLivrosIdentificador *hli, unsigned int identificador);
Livros* busca_binaria(HashLivrosIdentificador *hli, unsigned int identificador);
Livros* busca_sequencial_indexada(HashLivrosIdentificador *hli, unsigned int identificador);

// Relatórios e Arquivos
void gerar_relatorio_ordenado(HashLivrosIdentificador *hli, int metodo);
int exportar_base_dados(HashLivrosIdentificador *hli, const char *nome_arquivo);
int importar_base_dados(HashLivrosIdentificador *hli, const char *nome_arquivo);
void salvar_metrica(const char *metodo, double tempo_execucao, int comparacoes);

// Métodos de Ordenação (atuam sobre vetores auxiliares)
void insertion_sort(Livros *vetor, int tamanho, int *comparacoes);
void merge_sort(Livros *vetor, int inicio, int fim, int *comparacoes);
void heap_sort(Livros *vetor, int tamanho, int *comparacoes);

// Utilitários Internos
Head* obter_lista_hash(HashLivrosIdentificador *hli, unsigned int id);
Livros* converter_hash_para_vetor(HashLivrosIdentificador *hli, int *tamanho);
void liberar_hash(HashLivrosIdentificador *hli);

#endif