#include "SinalHandler.h"

std::vector<Aluno*>* SinalHandler::alunos_ptr = nullptr;
std::vector<Professor*>* SinalHandler::professores_ptr = nullptr;

void SinalHandler::inicializar(std::vector<Aluno*>& alunos, std::vector<Professor*>& professores) {
    alunos_ptr = &alunos;
    professores_ptr = &professores;

    signal(SIGINT, tratador);
    signal(SIGTERM, tratador);
    signal(SIGSEGV, tratador);
}

void SinalHandler::tratador(int sinal) {
    std::cout << "\n\nSinal (" << sinal << ") recebido. Iniciando encerramento seguro..." << std::endl;

    switch (sinal) {
        case SIGINT:
        case SIGTERM:
            std::cout << "Tentando salvar dados antes de sair..." << std::endl;
            if (alunos_ptr != nullptr && professores_ptr != nullptr) {
                try {
                    Persistencia::salvarAlunos("alunos_autosave.csv", *alunos_ptr);
                    Persistencia::salvarProfessores("professores_autosave.csv", *professores_ptr);
                    std::cout << "Dados salvos com sucesso." << std::endl;
                } catch (const std::exception& e) {
                    std::cerr << "Erro ao salvar dados durante o encerramento: " << e.what() << std::endl;
                }
            }
            exit(0);
            break;
        case SIGSEGV:
            std::cerr << "ERRO CRITICO: Falha de segmentacao. O programa sera encerrado." << std::endl;
            exit(1);
            break;
    }
}
