#include "LedgePersistence.h"
#include "Projeto_8/src/exceptions/StorageExeption.h"
#include <fstream>
#include <sstream>
#include <iostream>

LedgerPersistence::LedgerPersistence(std::string caminho) 
    : caminhoArquivo(std::move(caminho)) {}

void LedgerPersistence::salvarDados(const std::vector<std::string>& transacoes) {
    // Abre em modo append para simular o ledger
    std::ofstream arquivo(caminhoArquivo, std::ios::out | std::ios::app);

    if (!arquivo.is_open() || arquivo.fail()) {
        throw DiskWriteException("Nao foi possivel abrir/criar o arquivo " + caminhoArquivo + " para escrita.");
    }

    for (const auto& tx : transacoes) {
        arquivo << tx << "\n";
        
        
        if (arquivo.fail()) {
            throw DiskWriteException("Falha ao gravar transacao no fluxo do arquivo.");
        }
    }

    
    arquivo.flush();

    if (arquivo.bad()) {
        throw DiskWriteException("Erro fatal de I/O ao realizar o flush no disco.");
    }

    arquivo.close();
}

std::vector<std::string> LedgerPersistence::carregarDados() {
    std::ifstream arquivo(caminhoArquivo);
    
  
    if (!arquivo.is_open()) {
        return {}; 
    }

    std::vector<std::string> transacoes;
    std::string linha;
    size_t numeroLinha = 0;

    while (std::getline(arquivo, linha)) {
        numeroLinha++;

       
        if (linha.empty()) {
            throw FileCorruptedException("Linha em branco invalida detectada na linha " + std::to_string(numeroLinha));
        }

      
        if (linha.find(',') == std::string::npos) {
            throw FileCorruptedException("Formato CSV invalido na linha " + std::to_string(numeroLinha) + ": sem delimitador ','");
        }

        transacoes.push_back(linha);
    }

    if (arquivo.bad()) {
        throw FileCorruptedException("Falha de I/O durante a leitura do arquivo.");
    }

    return transacoes;
}