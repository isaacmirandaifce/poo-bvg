#ifndef LEDGERPERSISTENCE_H
#define LEDGERPERSISTENCE_H

#include <string>
#include <vector>

class LedgerPersistence {
private:
    static const std::string ARQUIVO_LEDGER; // "ledger.csv"

public:
    // Grava transações no arquivo; dispara DiskWriteException em falha
    void salvarDados(const std::vector<std::string>& transacoes);

    // Carrega transações do arquivo; dispara FileCorruptedException em inconsistência
    std::vector<std::string> carregarDados();
};

#endif 