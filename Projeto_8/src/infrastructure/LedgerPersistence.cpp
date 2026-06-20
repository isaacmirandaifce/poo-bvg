#include "LedgerPersistence.h"
#include "../exceptions/StorageException.h"

#include <fstream>
#include <iostream>

void LedgerPersistence::salvarDados(const std::vector<std::string>& transacoes)
{
    std::ofstream arquivo("ledger.csv");

    if (!arquivo.is_open())
    {
        throw DiskWriteException();
    }

    for (const auto& transacao : transacoes)
    {
        arquivo << transacao << std::endl;

        if (arquivo.fail())
        {
            throw DiskWriteException();
        }
    }

    arquivo << std::flush;
    arquivo.close();
}

std::vector<std::string> LedgerPersistence::carregarDados()
{
    std::ifstream arquivo("ledger.csv");
    std::vector<std::string> transacoes;
    std::string linha;

    if (!arquivo.is_open())
    {
        return transacoes;
    }

    while (std::getline(arquivo, linha))
    {
        if (linha.empty())
        {
            throw FileCorruptedException();
        }

        transacoes.push_back(linha);
    }

    if (arquivo.bad())
    {
        throw FileCorruptedException();
    }

    arquivo.close();

    return transacoes;
}