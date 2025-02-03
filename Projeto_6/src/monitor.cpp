#include "../include/Monitor.h"
#include <iostream>

// Construtor
Monitor::Monitor(const std::string& nome, const std::string& email, TipoUsuario tipo, std::string senha, const std::string& curso)
    : Aluno(nome, email, tipo, senha, curso) {}


// Adiciona uma disciplina monitorada
void Monitor::adicionarDisciplinaMonitorada(const std::shared_ptr<Disciplina>& disciplina) {
    disciplinasMonitoradas.push_back(disciplina);
}

// Sobrescrita do método para gerar o relatório do monitor
void Monitor::gerarRelatorio() const {
    std::cout << "Relatorio do Monitor\n"
              << "Nome: " << nome << "\n"
              << "Email: " << email << "\n"
              << "Curso: " << curso << "\nDisciplinas Cursadas:\n";

    for (const auto& disciplina : disciplinas) {
        disciplina->exibirInformacoes();
        std::cout << "---------------------\n";
    }

    std::cout << "Disciplinas Monitoradas:\n";
    for (const auto& disciplina : disciplinasMonitoradas) {
        disciplina->exibirInformacoes();
        std::cout << "---------------------\n";
    }
}

bool Monitor::autenticar(const std::string& senha) const {
    return senha == getSenha(); // Usa o getter para acessar a senha armazenada
}