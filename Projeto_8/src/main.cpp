#include <iostream>
#include <thread>
#include <chrono>
#include "Projeto_8/src/infrastructure/LedgePersistence.h"
#include "Projeto_8/src/infrastructure/SignalHandler.h"
#include "Projeto_8/src/exceptions/StorageExeption.h"

int main() {
    
    SignalHandler::inicializar();

    std::cout << "=========================================" << std::endl;
    std::cout << "  SecureBank Pro - Engine de Persistencia  " << std::endl;
    std::cout << "=========================================\n" << std::endl;

    try {
        LedgerPersistence db("ledger.csv");

        
        std::cout << "[ENGINE] Carregando historico de transacoes..." << std::endl;
        auto historico = db.carregarDados();
        std::cout << "[ENGINE] Transacoes carregadas: " << historico.size() << std::endl;

        std::cout << "[ENGINE] Sistema operacional e aguardando interceptacoes (Pressione Ctrl+C para testar o SignalHandler)..." << std::endl;

        size_t contador = historico.size() + 1;
        
        while (true) {
           
            std::string novaTransacao = "TX" + std::to_string(1000 + contador) + ",150.50,PROCESSADO";

            std::cout << "[TX-LOOP] Processando e persistindo: " << novaTransacao << std::endl;
            
            
            db.salvarDados({novaTransacao});

            contador++;
            
            
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }

    } catch (const FileCorruptedException& e) {
        std::cerr << "\n[CRITICAL ERROR] Arquivo corrompido ou invalido: " 
                  << e.what() << std::endl;
        return 1;
    } catch (const DiskWriteException& e) {
        std::cerr << "\n[CRITICAL ERROR] Falha de persistencia em disco: " 
                  << e.what() << std::endl;
        return 2;
    } catch (const StorageException& e) {
        std::cerr << "\n[CRITICAL ERROR] Falha generica no subsistema de armazenamento: " 
                  << e.what() << std::endl;
        return 3;
    } catch (const std::exception& e) {
        std::cerr << "\n[UNKNOWN ERROR] Erro nao tratado de runtime: " 
                  << e.what() << std::endl;
        return 99;
    }

    return 0;
}