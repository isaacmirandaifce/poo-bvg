#include "SinalHandler.h"
#include "Persistencia.h"
#include <cstdlib>

void SinalHandler::inicializar() {
    std::signal(SIGINT, tratador);
    std::signal(SIGTERM, tratador);
    std::signal(SIGSEGV, tratador);
}

void SinalHandler::tratador(int sinal) {
    std::cerr << "\nSinal capturado: ";
    switch (sinal) {
        case SIGINT: std::cerr << "Interrupcao (Ctrl+C)."; break;
        case SIGTERM: std::cerr << "Finalizacao solicitada."; break;
        case SIGSEGV: std::cerr << "Violacao de segmento (acesso invalido)."; break;
    }
    std::cerr << "\nSalvando dados antes de encerrar...\n";
   
    exit(1);
}
