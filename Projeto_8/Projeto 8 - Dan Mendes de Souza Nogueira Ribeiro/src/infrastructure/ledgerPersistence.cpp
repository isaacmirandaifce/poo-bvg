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
        // Força a escrita imediata em disco utilizando flush.
        arquivo << transacao << '\n' << std::flush;
    }

    arquivo.close();

    // Atualiza o cache interno com os novos dados recém salvos.
    this->dados = transacoes;
};

std::vector<std::string> LedgerPersistence::carregarDados(){

    // Retorna o cache caso os dados já tenham sido carregados anteriormente.
    if (!this->dados.empty())
    {
        return this->dados;
    }

    std::ifstream arquivo("ledger.csv");

    // Retorna um cache vazio caso o arquivo ainda não exista.
    if (!arquivo.is_open())
    {
        return this->dados;
    }

    std::string linha;

    while (std::getline(arquivo, linha))
    {
        // Se uma linha vazia for identificada no CSV, consideramos como corrupção.
        if (linha.empty())
        {
            arquivo.close();
            this->dados.clear();            
            throw FileCorruptedException(); 
        }

        this->dados.push_back(linha);
    }

    // Valida se houve algum erro subjacente durante a leitura (ex: erro de hardware)
    if (arquivo.bad())
    {
        arquivo.close();
        this->dados.clear();
        throw FileCorruptedException();
    }

    arquivo.close();
    return this->dados;
};