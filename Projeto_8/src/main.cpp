#include <iostream>
#include "infrastructure/LedgerPersistence.h"
#include "infrastructure/SignalHandler.h"

int main() {
    // 1. Inicializa os hooks de sinal
    SignalHandler::inicializar();

    try {
        LedgerPersistence db;
        
        // 2. Simulação de carregamento (pode disparar FileCorruptedException)
        auto historico = db.carregarDados();
        std::cout << "[ENGINE] Histórico carregado. Aguardando processamento..." << std::endl;

        // 3. Loop de persistência
        std::vector<std::string> novasTx = {"TX_003, 200.00", "TX_004, 15.75"};
        db.salvarDados(novasTx);

        std::cout << "[ENGINE] Sistema operacional operando. Pressione Ctrl+C para testar o SignalHandler." << std::endl;
        while(true) { /* Mantém o processo vivo */ }

    } catch (const StorageException& e) {
        std::cerr << "[CRITICAL ERROR] Falha na camada de armazenamento: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "[UNKNOWN ERROR] " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
