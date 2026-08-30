#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include "infrastructure/LedgerPersistence.h"
#include "infrastructure/SignalHandler.h"
#include "exceptions/StorageException.h"

int main() {
    // 1. Inicializa o interceptador de sinais (Ctrl+C / Kill)
    SignalHandler::inicializar();

    try {
        LedgerPersistence db;
        
        std::cout << "[ENGINE] Inicializando Storage Engine e carregando ledger.csv..." << std::endl;
        auto historico = db.carregarDados();
        std::cout << "[ENGINE] " << historico.size() << " transacoes antigas restauradas com sucesso." << std::endl;
        
        std::cout << "[ENGINE] Sistema operacional e aguardando interceptacoes (Pressione Ctrl+C para testar o hook)..." << std::endl;
        
        // 2. Loop simulando fluxo contínuo de transações bancárias
        int tx_id = historico.size() + 1;
        while (true) {
            std::vector<std::string> buffer_transacoes = {
                "TXN-" + std::to_string(tx_id) + ",STATUS:APPROVED,AMOUNT:150.00"
            };
            
            db.salvarDados(buffer_transacoes);
            std::cout << "[INFO] Transacao " << tx_id << " persistida e isolada no disco." << std::endl;
            
            tx_id++;
            std::this_thread::sleep_for(std::chrono::seconds(2)); // Sleep para dar tempo ao usuário aplicar Ctrl+C
        }

    } catch (const StorageException& e) {
        std::cerr << "\n[CRITICAL ERROR] Falha na camada de armazenamento: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "\n[UNKNOWN ERROR] Erro generico de runtime: " << e.what() << std::endl;
        return 2;
    }

    return 0;
}