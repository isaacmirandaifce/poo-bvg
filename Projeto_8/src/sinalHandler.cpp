#include "SinalHandler.h"

std::vector<std::shared_ptr<Aluno>>* SinalHandler::alunosRef = nullptr;
std::vector<std::shared_ptr<Professor>>* SinalHandler::professoresRef = nullptr;

void SinalHandler::registrarDados(std::vector<std::shared_ptr<Aluno>>* alunos,
                                  std::vector<std::shared_ptr<Professor>>* professores) {
    alunosRef = alunos;
    professoresRef = professores;
}

void SinalHandler::inicializar() {
    std::signal(SIGINT, tratador);   // Ctrl + C
    std::signal(SIGTERM, tratador);  // Encerramento pelo SO
#ifdef SIGSEGV
    std::signal(SIGSEGV, tratador);  // Violação de memória
#endif
}

void SinalHandler::tratador(int sinal) {
    std::cout << "\n[AVISO] Sinal capturado: " << sinal << std::endl;

    if (alunosRef && professoresRef) {
        try {
            Persistencia::salvarAlunos(*alunosRef, "dados/alunos.csv");
            Persistencia::salvarProfessores(*professoresRef, "dados/professores.csv");
            std::cout << "[INFO] Dados salvos com sucesso antes de encerrar.\n";
        } catch (const std::exception& e) {
            std::cerr << "[ERRO] Falha ao salvar dados: " << e.what() << std::endl;
        }
    }

    switch (sinal) {
        case SIGINT:
            std::cout << "[INFO] Encerramento via Ctrl+C.\n";
            break;
        case SIGTERM:
            std::cout << "[INFO] Encerramento solicitado pelo sistema.\n";
            break;
#ifdef SIGSEGV
        case SIGSEGV:
            std::cout << "[ALERTA] Violação de acesso à memória.\n";
            break;
#endif
        default:
            std::cout << "[INFO] Sinal desconhecido.\n";
            break;
    }

    std::exit(1);
}