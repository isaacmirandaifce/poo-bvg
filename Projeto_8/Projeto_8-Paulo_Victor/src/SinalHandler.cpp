#include "SinalHandler.h"
#include <csignal>
#include <iostream>

std::vector<Aluno> SinalHandler::alunos;
std::vector<Professor> SinalHandler::professores;

void SinalHandler::inicializar() {
    std::signal(SIGINT, tratador);
    std::signal(SIGSEGV, tratador);
    std::signal(SIGTERM, tratador);
}

void SinalHandler::setDados(const std::vector<Aluno>& alunos, const std::vector<Professor>& professores) {
    SinalHandler::alunos = alunos;
    SinalHandler::professores = professores;
}

void SinalHandler::tratador(int sinal) {
    std::cout << "\nSinal recebido: " << sinal << ". Salvando dados...\n";
    try {
        Persistencia::salvarAlunos(alunos, "alunos.txt");
        Persistencia::salvarProfessores(professores, "professores.txt");
    } catch (const std::exception& e) {
        std::cerr << "Erro ao salvar dados: " << e.what() << "\n";
    }
    std::exit(sinal);
}