#include "LedgerPersistence.h"
#include <fstream>
#include <iostream>

void LedgerPersistence::salvarDados(const std::vector<std::string>& transacoes) {
    std::ofstream arquivo("ledger.csv");
    if (!arquivo.is_open()) throw DiskWriteException();
    
    for (const auto& linha : transacoes) {
        arquivo << linha << "\n";
        // Verifica se houve falha durante a escrita linha a linha
        if (arquivo.fail()) throw DiskWriteException();
    }
    
    // O comando flush é obrigatório para garantir a resiliência
    arquivo.flush(); 
    arquivo.close();
}

std::vector<std::string> LedgerPersistence::carregarDados() {
    std::ifstream arquivo("ledger.csv");
    if (!arquivo.is_open()) return {};
    
    std::vector<std::string> dados;
    std::string linha;
    while (std::getline(arquivo, linha)) {
        if (linha.empty()) throw FileCorruptedException();
        dados.push_back(linha);
    }
    return dados;
}
