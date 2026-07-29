#ifndef LEDGER_PERSISTENCE_H
#define LEDGER_PERSISTENCE_H

#include <vector>
#include <string>
#include <fstream>

class LedgerPersistence {
public:
    void salvarDados(const std::vector<std::string>& transacoes);
    std::vector<std::string> carregarDados();
};

#endif // LEDGER_PERSISTENCE_H