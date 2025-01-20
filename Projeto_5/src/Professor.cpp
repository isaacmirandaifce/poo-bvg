#include "Professor.h"

Professor::Professor() : Usuario(), areaDeAtuacao("") {}

Professor::Professor(const std::string& nome, const std::string& email, const std::string& areaDeAtuacao)
    : Usuario(nome, email, "Professor"), areaDeAtuacao(areaDeAtuacao) {}

void Professor::adicionarDisciplina(const std::string& disciplina) {
    disciplinasMinistradas.push_back(disciplina);
}

void Professor::gerarRelatorio() const {
    std::cout << "Relatório do Professor:" << std::endl;
    std::cout << "Nome: " << nome << ", Área de Atuação: " << areaDeAtuacao << std::endl;
    std::cout << "Disciplinas Ministradas: ";
    for (const auto& disc : disciplinasMinistradas) {
        std::cout << disc << " ";
    }
    std::cout << std::endl;
}
