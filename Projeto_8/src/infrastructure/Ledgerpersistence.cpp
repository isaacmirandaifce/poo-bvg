#include "LedgerPersistence.h"
#include "../exceptions/StorageException.h"

#include <fstream>
#include <iostream>
#include <sstream>

const std::string LedgerPersistence::ARQUIVO_LEDGER = "ledger.csv";

// salvarDados
// Abre o arquivo em modo append, grava cada transação e força
// o flush do buffer. Lança DiskWriteException em qualquer falha.
void LedgerPersistence::salvarDados(const std::vector<std::string>& transacoes) {
    std::ofstream arquivo(ARQUIVO_LEDGER, std::ios::app);

    if (!arquivo.is_open()) {
        throw DiskWriteException(
            "Não foi possível abrir '" + ARQUIVO_LEDGER +
            "' para escrita. Verifique permissões ou espaço em disco."
        );
    }

    for (const auto& linha : transacoes) {
        arquivo << linha << "\n";

        // flush imediato: garante que os dados chegam ao SO antes de qualquer queda
        arquivo << std::flush;

        if (arquivo.fail()) {
            arquivo.close();
            throw DiskWriteException(
                "Falha ao gravar transação no ledger. "
                "Possível disco cheio ou permissão negada."
            );
        }
    }

    arquivo.close();
    std::cout << "[LedgerPersistence] " << transacoes.size()
              << " transação(ões) persistida(s) em '" << ARQUIVO_LEDGER << "'.\n";
}

// carregarDados
// Lê o arquivo linha a linha. Dispara FileCorruptedException
// se encontrar linhas vazias inesperadas ou falha de leitura.
std::vector<std::string> LedgerPersistence::carregarDados() {
    std::ifstream arquivo(ARQUIVO_LEDGER);
    std::vector<std::string> transacoes;

    // Arquivo inexistente não é erro — ledger ainda não foi criado
    if (!arquivo.is_open()) {
        std::cout << "[LedgerPersistence] Arquivo '" << ARQUIVO_LEDGER
                  << "' não encontrado. Iniciando ledger vazio.\n";
        return transacoes;
    }

    std::string linha;
    int numeroLinha = 0;

    while (std::getline(arquivo, linha)) {
        ++numeroLinha;

        // Linha completamente vazia no meio do ledger = dado corrompido
        if (linha.empty()) {
            arquivo.close();
            throw FileCorruptedException(
                "Linha vazia inesperada detectada na linha " +
                std::to_string(numeroLinha) + " de '" + ARQUIVO_LEDGER +
                "'. Arquivo pode estar corrompido."
            );
        }

        transacoes.push_back(linha);
    }

    // Verifica se a leitura encerrou por erro e não por EOF natural
    if (arquivo.bad()) {
        arquivo.close();
        throw FileCorruptedException(
            "Falha de leitura (badbit) detectada em '" + ARQUIVO_LEDGER +
            "'. O arquivo pode estar parcialmente corrompido."
        );
    }

    arquivo.close();
    std::cout << "[LedgerPersistence] " << transacoes.size()
              << " transação(ões) carregada(s) de '" << ARQUIVO_LEDGER << "'.\n";
    return transacoes;
}