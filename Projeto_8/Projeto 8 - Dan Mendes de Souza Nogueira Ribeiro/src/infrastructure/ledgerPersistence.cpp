#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "exceptions/storageException.h"
#include "ledgerPersistence.h"

LedgerPersistence::LedgerPersistence(){};

LedgerPersistence::~LedgerPersistence(){};

void LedgerPersistence::salvarDados(const std::vector<std::string> &transacoes){

    std::ofstream arquivo("ledger.csv");

    if (!arquivo.is_open())
    {
        throw DiskWriteException();
    }

    for (const auto &transacao : transacoes)
    {
        arquivo << transacao << '\n' << std::flush;
    }

    arquivo.close();

    this->dados = transacoes;
};

std::vector<std::string> LedgerPersistence::carregarDados(){

    if (!this->dados.empty())
    {
        return this->dados;
    }

    std::ifstream arquivo("ledger.csv");

    if (!arquivo.is_open())
    {
        return this->dados;
    }

    std::string linha;

    while (std::getline(arquivo, linha))
    {

        if (linha.empty())
        {
            arquivo.close();
            this->dados.clear();            
            throw FileCorruptedException(); 
        }

        this->dados.push_back(linha);
    }

    if (arquivo.bad())
    {
        arquivo.close();
        this->dados.clear();
        throw FileCorruptedException();
    }

    arquivo.close();
    return this->dados;
};