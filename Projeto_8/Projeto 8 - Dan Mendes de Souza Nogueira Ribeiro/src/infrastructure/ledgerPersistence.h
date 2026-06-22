#ifndef LEDGERPERSISTENCE_H
#define LEDGERPERSISTENCE_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "exceptions/storageException.h"

/**
 * @class LedgerPersistence
 * @brief Gerencia a persistência do livro-razão (Ledger) do sistema.
 * * Responsável por salvar e carregar dados transacionais em um arquivo CSV, 
 * mantendo um cache em memória das transações carregadas.
 */
class LedgerPersistence{

    private:
    std::vector<std::string> dados; /*!< Cache em memória contendo o histórico de transações. */

    public: 

    /**
     * @brief Construtor padrão da classe LedgerPersistence.
     */
    LedgerPersistence();

    /**
     * @brief Destrutor padrão.
     */
    ~LedgerPersistence();

    /**
     * @brief Salva uma lista de transações no arquivo físico do ledger.
     * * Sobrescreve o arquivo "ledger.csv" com os dados atuais e atualiza
     * o cache em memória.
     * * @param transacoes Vetor contendo as transações formatadas como string.
     * @throws DiskWriteException Caso não seja possível abrir ou gravar no arquivo.
     */
    void salvarDados(const std::vector<std::string>& transacoes);

    /**
     * @brief Carrega os dados do arquivo do ledger para a memória.
     * * Caso o arquivo já tenha sido lido (cache preenchido), retorna o cache.
     * Caso contrário, lê o "ledger.csv". Linhas vazias ou erros no arquivo disparam uma exceção.
     * * @return std::vector<std::string> O vetor de transações lidas com sucesso ou contidas no cache.
     * @throws FileCorruptedException Caso encontre linhas em branco inesperadas ou erros na stream de leitura.
     */
    std::vector<std::string> carregarDados();
};

#endif