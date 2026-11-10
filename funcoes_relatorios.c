
#include "livro_hash.h"

   // Funções Auxiliares para Relatórios e Arquivos
    void gerar_relatorio_ordenado(HashLivrosIdentificador *hli, int metodo);
    int exportar_base_dados(HashLivrosIdentificador *hli, const char *nome_arquivo);
    int importar_base_dados(HashLivrosIdentificador *hli, const char *nome_arquivo);