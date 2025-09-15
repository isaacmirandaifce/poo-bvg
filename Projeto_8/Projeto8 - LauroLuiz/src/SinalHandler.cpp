#include "SinalHandler.h"
#include "Persistencia.h"
#include <cstdlib>

// Inicialização dos ponteiros estáticos
std::vector<Aluno>* SinalHandler::alunosPtr = nullptr;
std::vector<Professor>* SinalHandler::professoresPtr = nullptr;
std::vector<Disciplina>* SinalHandler::disciplinasPtr = nullptr;

void SinalHandler::inicializar() {
    std::signal(SIGINT, tratador);   // Ctrl+C
    std::signal(SIGSEGV, tratador);  // Violação de segmentação
    std::signal(SIGTERM, tratador);  // Finalização pelo SO

    std::cout << "Sistema de tratamento de sinais inicializado." << std::endl;
}

void SinalHandler::definirDados(std::vector<Aluno>* alunos,
                                std::vector<Professor>* professores,
                                std::vector<Disciplina>* disciplinas) {
    alunosPtr = alunos;
    professoresPtr = professores;
    disciplinasPtr = disciplinas;
}

void SinalHandler::tratador(int sinal) {
    std::cout << "\n========== SINAL CAPTURADO ==========" << std::endl;

    switch (sinal) {
        case SIGINT:
            std::cout << "Sinal SIGINT recebido (Ctrl+C)" << std::endl;
            std::cout << "Tentando salvar dados antes do encerramento..." << std::endl;
            break;
        case SIGSEGV:
            std::cout << "Sinal SIGSEGV recebido (Violação de segmentação)" << std::endl;
            std::cout << "Erro crítico detectado! Tentando salvar dados..." << std::endl;
            break;
        case SIGTERM:
            std::cout << "Sinal SIGTERM recebido (Finalização pelo SO)" << std::endl;
            std::cout << "Sistema sendo encerrado pelo SO. Salvando dados..." << std::endl;
            break;
        default:
            std::cout << "Sinal desconhecido recebido: " << sinal << std::endl;
            break;
    }

    // Tentar salvar dados se for seguro
    if (sinal != SIGSEGV) {
        try {
            salvarDadosEmergencia();
            std::cout << "Dados salvos com sucesso!" << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Erro ao salvar dados: " << e.what() << std::endl;
        }
    }

    std::cout << "Sistema encerrado devido ao sinal " << sinal << std::endl;
    std::cout << "====================================" << std::endl;

    exit(sinal);
}

void SinalHandler::salvarDadosEmergencia() {
    if (alunosPtr) {
        Persistencia::salvarAlunos(*alunosPtr, "alunos_backup.csv");
    }

    if (professoresPtr) {
        Persistencia::salvarProfessores(*professoresPtr, "professores_backup.csv");
    }

    if (disciplinasPtr) {
        Persistencia::salvarDisciplinas(*disciplinasPtr, "disciplinas_backup.csv");
    }
}
