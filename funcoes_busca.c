// Busca Sequencial, Binária, Sequencial indexada
#include "livro_hash.h"

// Métodos de Busca (Retornam o ponteiro do livro encontrado ou NULL)
Livros* busca_sequencial(HashLivrosIdentificador *hli, unsigned int identificador);
Livros* busca_binaria(HashLivrosIdentificador *hli, unsigned int identificador); // Exige cópia ordenada em vetor
Livros* busca_sequencial_indexada(HashLivrosIdentificador *hli, unsigned int identificador);

