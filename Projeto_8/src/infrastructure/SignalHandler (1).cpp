#include "SignalHandler.h"
#include "LedgerPersistence.h"

#include <cstdlib>

LedgerPersistence* SignalHandler::persistenciaAtiva = nullptr;

void SignalHandler::inicializar() {
    std::signal(SIGINT, SignalHandler::tratador);
    std::signal(SIGTERM, SignalHandler::tratador);
}

void SignalHandler::registrarPersistencia(LedgerPersistence* persistencia) {
    persistenciaAtiva = persistencia;
}

void SignalHandler::tratador(int sinal) {
    const char* nomeSinal =
        (sinal == SIGINT)  ? "SIGINT (Ctrl+C)" :
        (sinal == SIGTERM) ? "SIGTERM (encerramento solicitado pelo SO)" :
                              "sinal desconhecido";

    std::cerr << "\n[SIGNAL HANDLER] Interceptado " << nomeSinal
              << " (codigo " << sinal << ").\n";
    std::cerr << "[SIGNAL HANDLER] Iniciando encerramento seguro do Ledger...\n";

    if (persistenciaAtiva != nullptr) {
        persistenciaAtiva->fecharComSeguranca();
    }

    std::cerr << "[SIGNAL HANDLER] Arquivos fechados sem partial writes. "
                 "Encerrando processo.\n";

    std::exit(sinal);
}
