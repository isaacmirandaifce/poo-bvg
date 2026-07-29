#include "LedgerPersistence.h"
#include "../exceptions/StorageException.h"
#include <iostream>

void LedgerPersistence::salvarDados(const std::vector<std::string>& transacoes) {
    std::ofstream arquivo("ledger.csv");
    if (!arquivo.is_open()) {
        throw DiskWriteException("Nao foi possivel abrir o arquivo ledger.csv para escrita.");
    }

    for (const auto& t : transacoes) {
        arquivo << t << "\n";
    }
    
    arquivo << std::flush; // Força o esvaziamento do buffer conforme o requisito
    if (arquivo.bad()) {
        throw DiskWriteException("Erro crítico ao persistir dados no disco.");
    }
    arquivo.close();
}

std::vector<std::string> LedgerPersistence::carregarDados() {
    std::vector<std::string> transacoes;
    std::ifstream arquivo("ledger.csv");
    
    // Se o arquivo não existir na primeira execução, podemos apenas retornar um vetor vazio
    if (!arquivo.is_open()) {
        return transacoes; 
    }

    std::string linha;
    while (std::getline(arquivo, linha)) {
        if (linha.empty()) {
            throw FileCorruptedException("Linha vazia inesperada encontrada no arquivo ledger.csv.");
        }
        transacoes.push_back(linha);
    }

    return transacoes;
}