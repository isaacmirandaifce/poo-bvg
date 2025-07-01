#include "SinalHandler.h"
#include "SistemaAcademico.h"
#include "Persistencia.h"
#include <iostream>
#include <cstdlib>

// Inicializa o ponteiro estático
SistemaAcademico* SinalHandler::sistema_ptr = nullptr;

void SinalHandler::inicializar(SistemaAcademico* sistema) {
    sistema_ptr = sistema;
    signal(SIGINT, tratador);
    signal(SIGTERM, tratador);
    signal(SIGSEGV, tratador);
}

void SinalHandler::tratador(int sinal) {
    std::cout << "\n\n[SINAL HANDLER] Sinal (" << sinal << ") recebido." << std::endl;

    switch (sinal) {
        case SIGINT:
        case SIGTERM: 
            std::cout << "[SINAL HANDLER] Solicitacao de encerramento recebida. Salvando dados..." << std::endl;
            if (sistema_ptr) {
                Persistencia::salvarDados(*sistema_ptr);
            }
            exit(EXIT_SUCCESS);
            break;

        case SIGSEGV: 
            std::cerr << "[SINAL HANDLER] ERRO CRITICO: Falha de segmentacao (SIGSEGV)." << std::endl;
            std::cerr << "[SINAL HANDLER] Tentativa de salvar dados pode nao ser segura, mas sera executada." << std::endl;
            if (sistema_ptr) {
                 
                try {
                    Persistencia::salvarDados(*sistema_ptr);
                } catch (...) {
                    std::cerr << "[SINAL HANDLER] Nao foi possivel salvar os dados durante o tratamento de SIGSEGV." << std::endl;
                }
            }
            
            _Exit(EXIT_FAILURE); 
            break;
    }
}