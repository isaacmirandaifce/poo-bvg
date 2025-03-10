#ifndef SINAL_HANDLER_H
#define SINAL_HANDLER_H

#include <csignal>
#include <vector>
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"
#include "Persistencia.h"

class SinalHandler {
public:
    static void configurarHandler(std::vector<Aluno>&, std::vector<Professor>&, std::vector<Disciplina>&);
private:
    static void handler(int);
    static std::vector<Aluno>* alunos;
    static std::vector<Professor>* professores;
    static std::vector<Disciplina>* disciplinas;
};

#endif // SINAL_HANDLER_H

// SinalHandler.cpp
#include "SinalHandler.h"
#include <iostream>

std::vector<Aluno>* SinalHandler::alunos = nullptr;
std::vector<Professor>* SinalHandler::professores = nullptr;
std::vector<Disciplina>* SinalHandler::disciplinas = nullptr;

void SinalHandler::configurarHandler(std::vector<Aluno>& a, std::vector<Professor>& p, std::vector<Disciplina>& d) {
    alunos = &a;
    professores = &p;
    disciplinas = &d;
    signal(SIGINT, handler);
    signal(SIGTERM, handler);
}

void SinalHandler::handler(int signum) {
    std::cout << "\nSinal " << signum << " recebido! Salvando dados antes de encerrar...\n";
    Persistencia::salvarDados(*alunos, *professores, *disciplinas);
    exit(signum);
}
