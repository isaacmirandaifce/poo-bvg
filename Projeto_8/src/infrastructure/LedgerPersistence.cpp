#include "LedgerPersistence.h"
#include "../exceptions/StorageException.h"
#include <fstream>
#include <iostream>

void LedgerPersistence::salvarDados(const std::vector<std::string>& transacoes) {
    // Tenta abrir o arquivo em modo append
    std::ofstream arquivo("ledger.csv", std::ios::app);
    
    if (!arquivo.is_open()) {
        throw DiskWriteException("Sem permissao ou espaco em disco para abrir ledger.csv.");
    }

    for (const auto& transacao : transacoes) {
        arquivo << transacao << "\n";
    }

    // Força o esvaziamento do buffer de escrita para o disco
    arquivo.flush();

    if (arquivo.fail()) {
        throw DiskWriteException("Erro durante o flush ou manipulacao do fluxo de saida.");
    }

    arquivo.close();
}

std::vector<std::string> LedgerPersistence::carregarDados() {
    std::vector<std::string> transacoes;
    std::ifstream arquivo("ledger.csv");

    if (!arquivo.is_open()) {
        // Arquivo ainda não existe, retorna lista vazia de forma segura
        return transacoes;
    }

    std::string linha;
    while (std::getline(arquivo, linha)) {
        // Simulação de corrupção: arquivos CSV vazios ou com marcador inválido
        if (linha.empty() || linha.find("CORRUPT") != std::string::npos) {
            arquivo.close();
            throw FileCorruptedException("Linha nula/invalida detectada no registro.");
        }
        transacoes.push_back(linha);
    }

    arquivo.close();
    return transacoes;
}