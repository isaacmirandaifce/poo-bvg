#include <iostream>
#include <vector>
#include <string>

#include "infrastructure/LedgerPersistence.h"
#include "infrastructure/SignalHandler.h"
#include "exceptions/StorageException.h"

int main()
{
    SignalHandler::inicializar();

    try
    {
        LedgerPersistence db;

        std::vector<std::string> historico =
            db.carregarDados();

        std::cout << "[ENGINE] Sistema iniciado."
                  << std::endl;

        std::cout << "[ENGINE] Historico carregado: "
                  << historico.size()
                  << " transacoes."
                  << std::endl;

        historico.push_back("PIX,100.00");
        historico.push_back("TED,250.00");
        historico.push_back("DEPOSITO,500.00");

        db.salvarDados(historico);

        std::cout << "[ENGINE] Dados persistidos com sucesso."
                  << std::endl;

        std::cout << "[ENGINE] Pressione Ctrl+C para testar SIGINT."
                  << std::endl;

        while (true)
        {
        }
    }
    catch (const StorageException& e)
    {
        std::cerr
            << "[CRITICAL ERROR] "
            << e.what()
            << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr
            << "[UNKNOWN ERROR] "
            << e.what()
            << std::endl;
    }

    return 0;
}