#include "Professor.h"
#include <iostream>
#include <sstream>

Professor::Professor(const std::string& nome, const std::string& email,
                     const std::string& matricula, const std::string& senha,
                     const std::string& departamento)
    : UsuarioAutenticavel(nome, email, matricula, TipoUsuario::PROFESSOR, senha),
      departamento(departamento) {}

void Professor::adicionarDisciplina(const std::string& disciplina) {
    disciplinasMinistradas.push_back(disciplina);
}

void Professor::gerarRelatorio() const {
    std::cout << "=== RELATÓRIO DO PROFESSOR ===" << std::endl;
    std::cout << "Nome: " << getNome() << std::endl;
    std::cout << "Matrícula: " << getMatricula() << std::endl;
    std::cout << "Departamento: " << departamento << std::endl;
    std::cout << "Disciplinas Ministradas:" << std::endl;
    
    for (const auto& disciplina : disciplinasMinistradas) {
        std::cout << "- " << disciplina << std::endl;
    }
    std::cout << "=============================" << std::endl;
}

std::string Professor::getDepartamento() const { return departamento; }
void Professor::setDepartamento(const std::string& departamento) { 
    this->departamento = departamento; 
}

// Adições para o Projeto 7
std::ostream& operator<<(std::ostream& os, const Professor& professor) {
    os << "Professor: " << professor.getNome()
       << " | Matrícula: " << professor.getMatricula()
       << " | Departamento: " << professor.getDepartamento();
    return os;
}