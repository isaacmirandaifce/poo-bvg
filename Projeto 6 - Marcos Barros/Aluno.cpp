#include "Aluno.h"
#include <iostream>

// Implementação da Classe Interna
Aluno::HistoricoDisciplinar::HistoricoDisciplinar(std::string nome, int ano, float nota)
    : nomeDisciplina(nome), anoCursado(ano), nota(nota) {}

void Aluno::HistoricoDisciplinar::exibir() const {
    std::cout << "    - Disciplina: " << nomeDisciplina 
              << ", Ano: " << anoCursado 
              << ", Nota: " << nota << std::endl;
}

// Implementação da Classe Aluno
Aluno::Aluno(int id, std::string nome, std::string senha, std::string curso)
    : UsuarioAutenticavel(id, nome, TipoUsuario::ALUNO, senha), curso(curso) {}

void Aluno::adicionarDisciplina(const std::string& nome, int ano, float nota) {
    historico.emplace_back(nome, ano, nota); // Cria um objeto HistoricoDisciplinar diretamente no vetor
}

bool Aluno::autenticar(const std::string& senha) const {
    std::cout << "Autenticando aluno '" << this->nome << "'... ";
    return verificarSenha(senha); // Reutiliza a lógica da classe base
}

void Aluno::gerarRelatorio() const {
    std::cout << "\n--- Relatorio do Aluno ---" << std::endl;
    std::cout << "ID: " << this->id << std::endl;
    std::cout << "Nome: " << this->nome << std::endl;
    std::cout << "Tipo: " << this->getTipoAsString() << std::endl;
    std::cout << "Curso: " << this->curso << std::endl;
    std::cout << "Historico de Disciplinas:" << std::endl;
    if (historico.empty()) {
        std::cout << "  Nenhuma disciplina cursada." << std::endl;
    } else {
        for (const auto& disciplina : historico) {
            disciplina.exibir();
        }
    }
    std::cout << "--------------------------" << std::endl;
}