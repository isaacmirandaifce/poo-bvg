#include "SinalHandler.h"
#include "Persistencia.h"
#include <iostream>
#include <unistd.h> // _exit

Persistencia* SinalHandler::persistenciaPtr = nullptr;

void SinalHandler::registrarPersistencia(Persistencia* p) {
    persistenciaPtr = p;
}

void SinalHandler::inicializar() {
    std::signal(SIGINT, SinalHandler::tratador);
    std::signal(SIGTERM, SinalHandler::tratador);
    std::signal(SIGSEGV, SinalHandler::tratador);
}

void SinalHandler::tratador(int sinal) {
    // Mensagem simples — atenção: funções de E/S não são garantia de segurança em sinal.
    const char* motivo;
    switch (sinal) {
        case SIGINT: motivo = "SIGINT (Interrupção - Ctrl+C)"; break;
        case SIGTERM: motivo = "SIGTERM (Finalização solicitada)"; break;
        case SIGSEGV: motivo = "SIGSEGV (Falha de segmentação)"; break;
        default: motivo = "Sinal desconhecido"; break;
    }

    // tentar escrever mensagem em stderr
    std::cerr << "\n[SinalHandler] Recebido: " << motivo << ". Tentando salvar dados...\n";

    if (persistenciaPtr) {
        persistenciaPtr->salvarEmSituacaoDeSinal();
    } else {
        std::cerr << "[SinalHandler] Nenhuma persistência registrada. Saindo sem salvar.\n";
    }

    // Em caso de SIGSEGV, sair imediatamente com código diferente
    if (sinal == SIGSEGV) {
        _exit(128 + SIGSEGV);
    } else {
        _exit(128 + sinal);
    }
}
