#ifndef LEDGERPERSISTENCE_H
#define LEDGERPERSISTENCE_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "exceptions/storageException.h"

class LedgerPersistence{

    private:
    std::vector<std::string> dados;

    public: 

    LedgerPersistence();

    ~LedgerPersistence();

    void salvarDados(const std::vector<std::string>& transacoes);

    std::vector<std::string> carregarDados();
};

#endif