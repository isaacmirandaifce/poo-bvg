#include "LedgerPersistence.h"
#include "../exceptions/StorageException.h"
#include <fstream>

void LedgerPersistence::salvarDados(const std::vector<std::string>& transacoes) {
    std::ofstream arquivo("ledger.csv", std::ios::app);

    if(!arquivo.is_open() || arquivo.fail()) {
        throw DiskWriteException("Falha ao abrir ou criar o arquivo ledger.csv por falta de permissão ou espaço");
    };

    for (const auto& tx : transacoes) {
        arquivo << tx << "\n";
    };

    arquivo.flush(); // Esvazia o buffer

    if(arquivo.fail()) {
        throw DiskWriteException("Erro detectado durante a operação de flush no disco");
    };
    
    arquivo.close();
}


std::vector<std::string> LedgerPersistence::carregarDados() {
    std::vector<std::string> dados;
    std::ifstream arquivo("ledger.csv");

    if(!arquivo.is_open()) {
        return dados;
    }

    std::string linha;
    while(std::getline(arquivo, linha)) {
        if (linha.empty()) {
            throw FileCorruptedException("Linha em branco inesperada encontrada no arquivo ledger.csv");
        }
        dados.push_back(linha);
    }

    if(arquivo.bad()) {
        throw FileCorruptedException("Falha critica de I/O na leitura do arquivo ledger.csv");
    }

    arquivo.close();
    return dados;
}