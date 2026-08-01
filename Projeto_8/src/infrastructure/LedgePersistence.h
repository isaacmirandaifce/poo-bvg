#ifndef LEDGER_PERSISTENCE_H
#define LEDGER_PERSISTENCE_H

#include <vector>
#include <string>

class LedgerPersistence {
private:
    std::string caminhoArquivo;

public:
    explicit LedgerPersistence(std::string caminho = "ledger.csv");
    
    void salvarDados(const std::vector<std::string>& transacoes);
    std::vector<std::string> carregarDados();
};

#endif 