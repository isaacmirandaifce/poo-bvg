#include <iostream>
#include "infrastructure/LedgerPersistence.h"
#include "infrastructure/SignalHandler.h"
#include "exceptions/StorageException.h"

int main() {
    SignalHandler::inicializar(); // Registra os hooks de sinal do SO

    try {
        LedgerPersistence db;
        // 1. Simular carregamento inicial (pode disparar FileCorruptedException)
        auto historico = db.carregarDados();
        
        // 2. Loop de processamento de transações (simulação)
        std::cout << "[ENGINE] Sistema operacional esta aguardando interceptacoes..." << std::endl;
        
        // CÓDIGO DO ALUNO: Adicione lógica de simulação e persistência aqui...

    } catch (const StorageException& e) {
        std::cerr << "[CRITICAL ERROR] Falha na camada de armazenamento: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "[UNKNOWN ERROR] Erro generico de runtime: " << e.what() << std::endl;
    }

    return 0;
}