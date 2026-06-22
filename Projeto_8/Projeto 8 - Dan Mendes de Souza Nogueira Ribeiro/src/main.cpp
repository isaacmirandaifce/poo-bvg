#include <iostream>
#include <thread>
#include <chrono>
#include "infrastructure/ledgerPersistence.h"
#include "infrastructure/signalHandler.h"
#include "exceptions/storageException.h"

int main()
{
    SignalHandler::inicializar();

    /* 
    std::ofstream arquivoTeste("ledger.csv");
    arquivoTeste << "PIX,100.00\n";
    arquivoTeste << "\n";
    arquivoTeste << "TED,50.00\n";
    arquivoTeste.close();
    */

    LedgerPersistence db;
    std::vector<std::string> historico;

    
    try
    {
        historico = db.carregarDados();
        std::cout << "Sistema operacional e aguardando interceptações..." << std::endl;
    }
    catch (const StorageException &e)
    {
        std::cerr << "erro critico Falha no carregamento inicial: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro genérico na inicialização: " << e.what() << std::endl;
        return 2;
    }

    historico.push_back("PIX,200.00");
    historico.push_back("DEPOSITO,50.00");
    historico.push_back("TED,3150.00");

    int contador = historico.size();

    while (true)
    {
        contador++;

        std::string novaTransacao = std::to_string(contador) + ", Status: Aprovado, o valor é: " + std::to_string(contador * 150);

        std::cout << "Processando... " << novaTransacao << " ... ";

        historico.push_back(novaTransacao);

        try
        {
            db.salvarDados(historico);
            std::cout << "Salvo com sucesso.\n";
        }
        catch (const StorageException &e)
        {
            std::cerr << std::endl  << e.what() << ". O sistema retentará no próximo ciclo...\n";
        }
        catch (const std::exception &e)
        {
            std::cerr << std::endl << "Erro genérico de runtime: " << e.what() << std::endl;
        }

        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    return 0;
}