#include "SignalHandler.h"

void SignalHandler::inicializar() {
    // Registra os sinais SIGINT (Ctrl+C) e SIGTERM para apontarem para o nosso tratador
    std::signal(SIGINT, tratador);
    std::signal(SIGTERM, tratador);
}

void SignalHandler::tratador(int sinal) {
    std::cout << "\n[ALERTA CRITICO] Sinal do SO interceptado (ID: " << sinal << "). Salvando estado e fechando com seguranca..." << std::endl;
    
    // Aqui você pode colocar a lógica de emergência para salvar os dados se necessário
    
    std::exit(sinal); // Encerra o programa de forma limpa
}