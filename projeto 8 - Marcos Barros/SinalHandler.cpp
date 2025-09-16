#include "SinalHandler.h"

// Inicializa a variável estática
std::function<void()> SinalHandler::funcaoSalvarDados = nullptr;

void SinalHandler::registrarFuncaoSalvar(std::function<void()> func) {
    funcaoSalvarDados = func;
}

void SinalHandler::inicializar() {
    signal(SIGINT, tratador);  // Captura Ctrl+C
    signal(SIGTERM, tratador); // Captura o comando 'kill'
    signal(SIGSEGV, tratador); // Captura falha de segmentação (acesso inválido à memória)
}

void SinalHandler::tratador(int sinal) {
    std::cout << "\n\nSinal " << sinal << " recebido. ";

    switch(sinal) {
        case SIGINT:
        case SIGTERM:
            std::cout << "Tentando salvar dados antes de encerrar..." << std::endl;
            // É seguro tentar salvar aqui
            if (funcaoSalvarDados) {
                try {
                    funcaoSalvarDados();
                    std::cout << "Dados salvos com sucesso." << std::endl;
                } catch (const std::exception& e) {
                    std::cerr << "Erro ao salvar dados: " << e.what() << std::endl;
                }
            } else {
                std::cout << "Nenhuma função de salvamento registrada." << std::endl;
            }
            exit(128 + sinal); // Sai com um código de erro que indica o sinal
            break;

        case SIGSEGV:
            std::cerr << "Falha de segmentação! O programa está em um estado instável." << std::endl;
            std::cerr << "Não é seguro tentar salvar os dados. Encerrando imediatamente." << std::endl;
            // NUNCA tente fazer operações complexas (como I/O de arquivo) aqui.
            // Apenas saia da forma mais limpa possível.
            exit(128 + sinal);
            break;
    }
}