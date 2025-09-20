#include "Professor.h"
#include <iostream>

Professor::Professor(std::string nome, std::string email, std::string areaDeAtuacao)
    : Usuario(nome, email, "Professor"), areaDeAtuacao(areaDeAtuacao)
{

}

void Professor::adicionarDisciplina(const std::string& disciplina)
{
    disciplinasMinistradas.push_back(disciplina);
}

void Professor::gerarRelatorio()
{
    std::cout << "--- Relatório do Professor ---" << std::endl;
    std::cout << "Nome: " << this->nome << std::endl;
    std::cout << "Área de Atuação: " << this->areaDeAtuacao << std::endl;
    std::cout << "Disciplinas Ministradas:" << std::endl;
    if (disciplinasMinistradas.empty()) {
        std::cout << "  Nenhuma disciplina ministrada." << std::endl;
    } else {
        for (const std::string& disciplina : disciplinasMinistradas) {
            std::cout << "  - " << disciplina << std::endl;
        }
    }
}
