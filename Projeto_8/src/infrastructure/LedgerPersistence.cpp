#include "LedgerPersistence.h"
#include "../exceptions/StorageException.h"
#include <fstream>

LedgerPersistence::LedgerPersistence()
    : caminhoArquivo("ledger.csv") {}

LedgerPersistence::LedgerPersistence(const std::string& caminhoArquivo)
    : caminhoArquivo(caminhoArquivo) {}

void LedgerPersistence::salvarDados(const std::vector<std::string>& transacoes) {
    std::ofstream arquivo(caminhoArquivo, std::ios::out | std::ios::app);

    if (!arquivo.is_open()) {
        throw DiskWriteException("Nao foi possivel abrir '" + caminhoArquivo + "' para escrita (permissao ou disco cheio).");
    }

    for (const std::string& transacao : transacoes) {
        arquivo << transacao << "\n";

        if (arquivo.fail()) {
            throw DiskWriteException("Falha ao gravar dados em '" + caminhoArquivo + "'. Operacao de disco interrompida.");
        }
    }

    arquivo.flush();

    if (arquivo.fail()) {
        throw DiskWriteException("Falha ao esvaziar o buffer (flush) de '" + caminhoArquivo + "'.");
    }

    arquivo.close();
}

std::vector<std::string> LedgerPersistence::carregarDados() {
    std::ifstream arquivo(caminhoArquivo);
    std::vector<std::string> transacoes;

    if (!arquivo.is_open()) {
        // Sem historico previo: nao ha o que carregar, nao e uma corrupcao.
        return transacoes;
    }

    std::string linha;
    while (std::getline(arquivo, linha)) {
        if (linha.empty()) {
            throw FileCorruptedException("Linha vazia inesperada encontrada em '" + caminhoArquivo + "'.");
        }
        transacoes.push_back(linha);
    }

    if (arquivo.bad()) {
        throw FileCorruptedException("Falha de leitura ao processar '" + caminhoArquivo + "'.");
    }

    return transacoes;
}

std::string LedgerPersistence::getCaminhoArquivo() const {
    return caminhoArquivo;
}
