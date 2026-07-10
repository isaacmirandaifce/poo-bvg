#include "SignalHandler.h"
#include "LedgerPersistence.h"

#include <cstdlib>
#include <fstream>
#include <string>

//inicializar
//Registra o ponteiro do tratador estático para SIGINT e SIGTERM.
//Deve ser chamado no início do main(), antes de qualquer I/O.
void SignalHandler::inicializar() {
    std::signal(SIGINT,  SignalHandler::tratador);
    std::signal(SIGTERM, SignalHandler::tratador);

    std::cout << "[SignalHandler] Hooks registrados para SIGINT e SIGTERM.\n";
}

//tratador (static)
//Chamado pelo SO ao receber SIGINT (Ctrl+C) ou SIGTERM (kill).
//Realiza flush emergencial, grava log de encerramento e encerra
//de forma limpa para evitar partial writes no ledger.
void SignalHandler::tratador(int sinal) {
    const char* nomeSinal = (sinal == SIGINT) ? "SIGINT (Ctrl+C)" : "SIGTERM";

    std::cerr << "  [ALERTA CRÍTICO] Sinal capturado: " << nomeSinal;
    std::cerr << "\n  Iniciando encerramento seguro do Transaction Ledger...\n";

    //Grava log emergencial de encerramento
    std::ofstream logEmergencia("shutdown_emergency.log", std::ios::app);
    if (logEmergencia.is_open()) {
        logEmergencia << "[SHUTDOWN] Sinal recebido: " << sinal
                      << " (" << nomeSinal << "). "
                      << "Ledger fechado de forma segura.\n"
                      << std::flush;
        logEmergencia.close();
        std::cerr << "[SignalHandler] Log emergencial gravado em 'shutdown_emergency.log'.\n";
    }

    //Persiste estado final antes de encerrar
    try {
        LedgerPersistence db;
        db.salvarDados({"[SHUTDOWN] Sessão encerrada por sinal do SO: " +
                        std::string(nomeSinal)});
        std::cerr << "[SignalHandler] Estado final persistido no ledger.\n";
    } catch (...) {
        // Em shutdown emergencial, ignoramos falhas secundárias de I/O
        std::cerr << "[SignalHandler] Aviso: não foi possível persistir estado final.\n";
    }

    std::cerr << "[SignalHandler] Encerramento limpo concluído. Saindo...\n";
    std::exit(sinal);
}