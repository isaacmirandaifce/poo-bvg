#ifndef LEDGERPERSISTENCE_H
#define LEDGERPERSISTENCE_H

#include <vector>
#include <string>
#include "../exceptions/StorageException.h"

class LedgerPersistence {
public:
    void salvarDados(const std::vector<std::string>& transacoes);
    std::vector<std::string> carregarDados();
};

#endif
