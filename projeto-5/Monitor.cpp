#include "Monitor.h"
#include <iostream>

Monitor::Monitor(std::string nome, std::string email, std::string matricula, std::string curso, std::string areaDeAtuacao)
    : Usuario(nome, email, "Monitor"),
      Aluno(nome, email, matricula, curso),
      Professor(nome, email, areaDeAtuacao)
{
}

void Monitor::adicionarDisciplinaMonitorada(const std::string& disciplina) {
    disciplinasMonitoradas.push_back(disciplina);
}

void Monitor::listarDisciplinasMonitoradas()
{
    std::cout << "Disciplinas Monitoradas por " << this->nome << ":" << std::endl;
    if (disciplinasMonitoradas.empty())
    {
        std::cout << "  Nenhuma disciplina." << std::endl;
    } else
    {
        for (const std::string& disciplina : disciplinasMonitoradas)
        {
            std::cout << "  - " << disciplina << std::endl;
        }
    }
}

void Monitor::gerarRelatorio() {
    std::cout << "--- Relatório do Monitor ---" << std::endl;
    std::cout << "Nome: " << this->nome << std::endl;
    std::cout << "Matrícula: " << this->matricula << std::endl; // Acessa o membro herdado de Aluno
    std::cout << "Curso: " << this->curso << std::endl;         // Acessa o membro herdado de Aluno
    std::cout << "Área de Atuação como Professor: " << this->areaDeAtuacao << std::endl; // Acessa o membro herdado de Professor
    listarDisciplinasMonitoradas(); // Reutiliza o método da própria classe
}
