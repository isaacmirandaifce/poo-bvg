#include "SignalHandler.h"
#include "../exceptions/StorageException.h"
#include <fstream>
#include <cstdlib>

LedgerPersistence* SignalHandler::persistenciaAtiva = nullptr;
std::vector<std::string>* SignalHandler::bufferAtivo = nullptr;

void SignalHandler::inicializar() {
    std::signal(SIGINT, SignalHandler::tratador);
    std::signal(SIGTERM, SignalHandler::tratador);
}

void SignalHandler::registrarContexto(LedgerPersistence* persistencia, std::vector<std::string>* bufferPendente) {
    persistenciaAtiva = persistencia;
    bufferAtivo = bufferPendente;
}

void SignalHandler::tratador(int sinal) {
    std::cout << std::endl;
    std::cout << "[SIGNAL HANDLER] Sinal critico interceptado! ID: " << sinal
               << " (" << (sinal == SIGINT ? "SIGINT" : sinal == SIGTERM ? "SIGTERM" : "DESCONHECIDO") << ")"
               << std::endl;
    std::cout << "[SIGNAL HANDLER] Encerrando engine com seguranca antes de finalizar o processo..." << std::endl;

    try {
        // Log emergencial de encerramento.
        std::ofstream logEmergencial("shutdown_emergency.log", std::ios::out | std::ios::app);
        if (logEmergencial.is_open()) {
            logEmergencial << "Encerramento capturado. Sinal ID: " << sinal << std::endl;
            logEmergencial.flush();
            logEmergencial.close();
        }

        // Persiste qualquer transacao pendente no buffer antes de sair.
        if (persistenciaAtiva != nullptr && bufferAtivo != nullptr && !bufferAtivo->empty()) {
            persistenciaAtiva->salvarDados(*bufferAtivo);
            std::cout << "[SIGNAL HANDLER] Buffer pendente (" << bufferAtivo->size()
                       << " transacoes) persistido com sucesso." << std::endl;
            bufferAtivo->clear();
        }
    } catch (const StorageException& e) {
        std::cerr << "[SIGNAL HANDLER] Falha ao persistir dados durante o encerramento: " << e.what() << std::endl;
    }

    std::cout << "[SIGNAL HANDLER] Arquivos fechados. Encerrando processo com exit(" << sinal << ")." << std::endl;
    std::exit(sinal);
}
